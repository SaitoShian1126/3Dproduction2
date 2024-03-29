//============================================
//
//	key.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include <stdio.h>
#include "key.h"
#include "application.h"
#include "renderer.h"

//============================================
// 静的メンバ変数宣言
//============================================

//============================================
// キーのコンストラクタ
//============================================
CKey::CKey()
{
	//============================================
	//メンバ変数のクリア
	//============================================
	m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//============================================
// キーのデストラクタ
//============================================
CKey::~CKey()
{
	//何も書かない
}

//============================================
// キーの初期化処理
//============================================
HRESULT CKey::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	return S_OK;
}

//============================================
// キーの終了処理
//============================================
void CKey::Uninit()
{

}

//============================================
// 生成
//============================================
CKey * CKey::Create()
{
	CKey *pKey = nullptr;

	// 3Dオブジェクトクラスの生成
	pKey = new CKey;				// 3Dオブジェクトのインスタンス生成

	// nullptrチェック
	if (pKey != nullptr)
	{
		// 初期化処理
		pKey->Init();
	}
	else
	{
		assert(false);
	}
	return pKey;
}