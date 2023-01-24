//============================================
//
//	bullet.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "bullet.h"
#include "application.h"
#include "renderer.h"
#include "player.h"
#include "object2D.h"
#include "score.h"
#include "game.h"
#include "enemy.h"
#include "fade.h"
#include "result.h"
#include "billboard.h"
#include "gasolene_gimmick.h"
#include "spawn.h"

//============================================
// 静的メンバ変数宣言
//============================================

//============================================
// 弾のコンストラクタ
//============================================
CBullet::CBullet()
{
	//============================================
	//メンバ変数のクリア
	//============================================
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_EnemyDeathFlag = false;
	m_GimmickUninitFlag = false;
}

//============================================
// 弾のデストラクタ
//============================================
CBullet::~CBullet()
{
	//何も書かない
}

//============================================
// 弾の初期化処理
//============================================
HRESULT CBullet::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_EnemyDeathFlag = false;
	m_GimmickUninitFlag = false;
	m_BulletMoveFlag = false;

	//オブジェクト基礎の初期化処理
	CObjectBase::Init();

	SetTexture("data/TEXTURE/bullet000.png");

	return S_OK;
}

//============================================
// 弾の終了処理
//============================================
void CBullet::Uninit(void)
{
	//オブジェクト基礎の終了処理
	CObjectBase::Uninit();
}

//============================================
// 弾の更新処理
//============================================
void CBullet::Update(void)
{
	//プレイヤーの情報取得
	D3DXVECTOR3 BulletPos = GetPos();
	D3DXVECTOR3 BulletMove = GetMove();

	m_BulletPos = BulletPos;

	//弾の位置更新
	m_BulletPos += BulletMove;

	//寿命を減らす処理
	m_nLife--;

	//弾のライフが0になったら
	if (m_nLife <= 0)
	{
		//弾の削除
		Uninit();
		return;
	}

	//弾と敵の当たり判定処理
	if (m_EnemyDeathFlag == false)
	{
		HitEnemy(m_BulletPos);
	}
	//弾とギミックの当たり判定
	if (m_GimmickUninitFlag == false)
	{
		HitGimmick(m_BulletPos);
	}

	//位置の設定
	SetPosition(m_BulletPos);
	//移動の設定
	SetMove(BulletMove);
	//向きの設定
	SetRot(m_BulletRot);
}

//============================================
// 弾の描画処理
//============================================
void CBullet::Draw(void)
{
	//オブジェクト基礎の描画処理
	CObjectBase::Draw();
}

//============================================
// 弾の生成
//============================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife)
{
	CBullet *pBullet = nullptr;

	//弾のインスタンスの生成
	pBullet = new CBullet;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pBullet != nullptr)
	{
		//初期化処理
		pBullet->Init();
		//設定処理
		pBullet->SetPosition(pos);
		pBullet->SetMove(move);
		pBullet->SetLife(nLife);
		pBullet->SetSize(D3DXVECTOR3(1.5f, 1.5f, 0.0f));
	}
	else
	{
		assert(false);
	}

	return pBullet;
}

//============================================
// 弾と敵の当たり判定
//============================================
void CBullet::HitEnemy(D3DXVECTOR3 pos)
{
	//敵の総数
	int TotalEnemy = CGame::GetSpawn()->GetEnemyCount();

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		if (CSpawn::GetEnemy()[nCnt] != nullptr)
		{
			//敵の位置
			D3DXVECTOR3 EnemyPos = CSpawn::GetEnemy()[nCnt]->GetEnemyPos();
			//敵のサイズ
			D3DXVECTOR3 EnemySize = CSpawn::GetEnemy()[nCnt]->GetEnemySize();
			//敵の体力
			int EnemyLife = CSpawn::GetEnemy()[nCnt]->GetLife();
			//弾と敵の当たり判定
			if (pos.x + 5.0f >= EnemyPos.x - EnemySize.x
				&&pos.x - 5.0f <= EnemyPos.x + EnemySize.x
				&&pos.y + 5.0f >= EnemyPos.y - EnemySize.y
				&&pos.y - 5.0f <= EnemyPos.y + EnemySize.y
				&&pos.z + 5.0f >= EnemyPos.z - EnemySize.z
				&&pos.z - 5.0f <= EnemyPos.z + EnemySize.z)
			{
				//弾の削除
				m_nLife = 0;
				SetLife(m_nLife);

				EnemyLife--;

				if (EnemyLife <= 0)
				{
					CGame::GetScore()->AddScore(200);
					CSpawn::GetEnemy()[nCnt]->Uninit();
					CSpawn::GetEnemy()[nCnt] = nullptr;
				}
				else
				{
					CSpawn::GetEnemy()[nCnt]->SetLife(EnemyLife);
				}

				TotalEnemy--;
				CGame::GetSpawn()->SetEnemyCount(TotalEnemy);
			}
		}
	}
}

//============================================
// 弾とギミックの当たり判定
//============================================
void CBullet::HitGimmick(D3DXVECTOR3 pos)
{
	for (int nCnt = 0; nCnt < MAX_GASOLENE; nCnt++)
	{
		//ギミックの位置
		D3DXVECTOR3 GasolenePos = CGame::GetGasoleneGimmick(nCnt)->GetGasolenePos();
		//ギミックのサイズ
		D3DXVECTOR3 GasoleneSize = CGame::GetGasoleneGimmick(nCnt)->GetGasoleneSize();
		//ギミックの体力
		int GasoleneLife = CGame::GetGasoleneGimmick(nCnt)->GetGasoleneLife();

		//弾とギミックの当たり判定
		if (pos.x + 5.0f >= GasolenePos.x - GasoleneSize.x
			&&pos.x - 5.0f <= GasolenePos.x + GasoleneSize.x
			&&pos.y + 5.0f >= GasolenePos.y - GasoleneSize.y
			&&pos.y - 5.0f <= GasolenePos.y + GasoleneSize.y
			&&pos.z + 5.0f >= GasolenePos.z - GasoleneSize.z
			&&pos.z - 5.0f <= GasolenePos.z + GasoleneSize.z)
		{
			//弾の削除
			m_nLife = 0;
			SetLife(m_nLife);

			GasoleneLife--;
			CGame::GetGasoleneGimmick(nCnt)->SetGasoleneLife(GasoleneLife);
		}
	}
}