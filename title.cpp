//============================================
//
//	title.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "title.h"
#include "application.h"
#include "renderer.h" 
#include "object2d.h"
#include "fade.h"
#include "input.h"

//============================================
// タイトルのコンストラクタ
//============================================
CTitle::CTitle()
{
	//============================================
	//メンバ変数のクリア
	//============================================
}

//============================================
// タイトルのデストラクタ
//============================================
CTitle::~CTitle()
{
	//何も書かない
}

//============================================
// タイトルの初期化処理
//============================================
HRESULT CTitle::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title.png",
		&m_pTextureTitle);

	//============================================
	//メンバ変数の初期化
	//============================================

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureTitle);

	return S_OK;
}

//============================================
// タイトルの終了処理
//============================================
void CTitle::Uninit(void)
{
	CObject::Release();
}

//============================================
// タイトルの更新処理
//============================================
void CTitle::Update()
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	//CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();
	
	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE)
	{
		CFade::SetFade(CApplication::MODE_GAME);
	}
}

//============================================
// タイトルの描画処理
//============================================
void CTitle::Draw()
{

}

//============================================
// タイトルの生成
//============================================
CTitle *CTitle::Create()
{
	CTitle *pTitle = nullptr;

	//クラスの生成
	pTitle = new CTitle;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pTitle != nullptr)
	{
		//初期化処理
		pTitle->Init();
	}
	else
	{
		assert(false);
	}

	return pTitle;
}

//============================================
// 色の設定
//============================================
void CTitle::SetColor(float Red, float Green, float Blue, float α)
{
	VERTEX_2D*pVtx;				//頂点情報へのポインタ

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, α);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, α);

	//頂点バッファをアンロックする
	Buffer->Unlock();
}