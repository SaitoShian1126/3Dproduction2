//============================================
//
//	keyset.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include <stdio.h>
#include "keyset.h"
#include "application.h"
#include "renderer.h"
#include "key.h"

//============================================
// 静的メンバ変数宣言
//============================================

//============================================
// キーのコンストラクタ
//============================================
CKeySet::CKeySet()
{
	//============================================
	//メンバ変数のクリア
	//============================================
	m_Frame = 0;					//フレーム数
	m_apKey[MAX_MODEL] = {};		//キー構造体の配列
}

//============================================
// キーのデストラクタ
//============================================
CKeySet::~CKeySet()
{
	//何も書かない
}

//============================================
// キーの初期化処理
//============================================
HRESULT CKeySet::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_Frame = 0;					//フレーム数

	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		//キーの生成
		m_apKey[nCnt] = CKey::Create();
	}

	return S_OK;
}

//============================================
// キー設定の終了処理
//============================================
void CKeySet::Uninit()
{
	//キーの終了処理
	for (int nCnt = 0; nCnt < MAX_MODEL; nCnt++)
	{
		if (m_apKey[nCnt] != nullptr)
		{
			m_apKey[nCnt]->Uninit();
			delete m_apKey[nCnt];
			m_apKey[nCnt] = nullptr;
		}
	}
}

//============================================
// 生成
//============================================
CKeySet * CKeySet::Create()
{
	CKeySet *pKeySet = nullptr;

	// 3Dオブジェクトクラスの生成
	pKeySet = new CKeySet;				// 3Dオブジェクトのインスタンス生成

	// nullptrチェック
	if (pKeySet != nullptr)
	{
		// 初期化処理
		pKeySet->Init();
	}
	else
	{
		assert(false);
	}
	return pKeySet;
}