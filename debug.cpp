//============================================
//
//	debug.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <stdio.h>
#include "debug.h"
#include "application.h"
#include "renderer.h"

//============================================
// 静的メンバ変数宣言
//============================================
LPD3DXFONT CDebugProc::m_pFont = nullptr;
char CDebugProc::m_aStr[1024] = {};

//============================================
// デバッグ表示のコンストラクタ
//============================================
CDebugProc::CDebugProc()
{
	//============================================
	//メンバ変数のクリア
	//============================================
	m_pFont = nullptr;						//フォントをクリア
}

//============================================
// デバッグ表示のデストラクタ
//============================================
CDebugProc::~CDebugProc()
{
	//何も書かない
}

//============================================
// デバッグ表示の初期化処理
//============================================
HRESULT CDebugProc::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_pFont = nullptr;						//フォントを初期化

	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

#ifdef _DEBUG
	// デバッグ情報表示用フォントの生成
	D3DXCreateFont(pDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Terminal"), &m_pFont);
#endif

	return S_OK;
}

//============================================
// デバッグ表示の終了処理
//============================================
void CDebugProc::Uninit(void)
{
#ifdef _DEBUG
	// デバッグ情報表示用フォントの破棄
	if (m_pFont != nullptr)
	{
		m_pFont->Release();
		m_pFont = nullptr;
	}
#endif // _DEBUG
}

//============================================
// デバッグ表示
//============================================
void CDebugProc::Print(const char * pFormat, ...)
{
	va_list args;					//可変引数を使用するための関数 args(引数)
	va_start(args, pFormat);		//第一引数va_listの数値,第二引数文字列
	vsprintf(m_aStr, pFormat, args);//結果格納用アドレス,表示させる文字列,数値
	va_end(args);					//終了するために必要
}

//デバッグ表示の描画処理
void CDebugProc::Draw(void)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	// テキスト描画
	m_pFont->DrawText(NULL, m_aStr, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));
}
