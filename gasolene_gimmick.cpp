//============================================
//
//	gasolene_gimmick.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "gasolene_gimmick.h"
#include "player.h"
#include "bullet.h"
#include "explosion.h"
#include "game.h"

//============================================
// 静的メンバ変数宣言
//============================================

//============================================
// ギミックのコンストラクタ
//============================================
CGasolene_Gimmick::CGasolene_Gimmick()
{
	//============================================
	//メンバ変数のクリア
	//============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//============================================
// ギミックのデストラクタ
//============================================
CGasolene_Gimmick::~CGasolene_Gimmick()
{
	//何も書かない
}

//============================================
// ギミックの初期化処理
//============================================
HRESULT CGasolene_Gimmick::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_size = D3DXVECTOR3(30.0f, 30.0f, 30.0f);
	m_nLife = 10;

	//オブジェクト基礎の初期化処理
	CObjectX::Init();
	CObjectX::SetModel("data/XMODEL/gasolene.x");

	return S_OK;
}

//============================================
// ギミックの終了処理
//============================================
void CGasolene_Gimmick::Uninit(void)
{
	//オブジェクト基礎の終了処理
	CObjectX::Uninit();
}

//============================================
// ギミックの更新処理
//============================================
void CGasolene_Gimmick::Update(void)
{
	if (m_nLife <= 0)
	{
		CExplosion::Create(D3DXVECTOR3(m_pos.x,m_pos.y + 20.0f,m_pos.z), D3DXVECTOR3(50.0f, 50.0f, 0.0f));
		CPlayer::GetBullet()->SetGimmickUninitFlag(true);
		Uninit();
		return;
	}

	//オブジェクト基礎の更新処理
	CObjectX::Update();

	//位置の設定
	SetPosition(m_pos);
}

//============================================
// ギミックの描画処理
//============================================
void CGasolene_Gimmick::Draw(void)
{
	//オブジェクト基礎の描画処理
	CObjectX::Draw();
}

//============================================
// 爆発した時の当たり判定
//============================================
void CGasolene_Gimmick::HitDamage()
{
	
}

//============================================
// 生成
//============================================
CGasolene_Gimmick * CGasolene_Gimmick::Create(D3DXVECTOR3 pos)
{
	CGasolene_Gimmick *pGasolene = nullptr;

	//3Dオブジェクトクラスの生成
	pGasolene = new CGasolene_Gimmick;				//3Dオブジェクトのインスタンス生成

	//nullチェック
	if (pGasolene != nullptr)
	{
		//初期化処理
		pGasolene->Init();
		pGasolene->SetPosition(pos);
	}
	else
	{
		assert(false);
	}
	return pGasolene;
}
