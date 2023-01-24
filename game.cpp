//============================================
//
//	game.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "object3d.h"
#include "objectX.h"
#include "game.h"
#include "player.h"
#include "billboard.h"
#include "meshfield.h"
#include "sphere.h"
#include "input.h"
#include "fade.h"
#include "result.h"
#include "number.h"
#include "score.h"
#include "objectbase.h"
#include "enemy.h"
#include "model.h"
#include "particle.h"
#include "boss.h"
#include "gasolene_gimmick.h"
#include "bullet.h"
#include "explosion.h"
#include "spawn.h"

//============================================
// 静的メンバ変数宣言
//============================================
CMeshField *CGame::m_pMeshField = nullptr;
CScore *CGame::m_pScore = nullptr;
CGasolene_Gimmick *CGame::m_pGasoleneGimmick[MAX_GASOLENE] = {};
CModel *CGame::m_Model = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
CSpawn *CGame::m_pSpawn = nullptr;

//============================================
// ゲームのコンストラクタ
//============================================
CGame::CGame()
{
	//============================================
	//メンバ変数のクリア
	//============================================
}

//============================================
// ゲームのデストラクタ
//============================================
CGame::~CGame()
{
	//何も書かない
}

//============================================
// ゲームの初期化処理
//============================================
HRESULT CGame::Init(void)
{
	//============================================
	// メンバ変数の初期化
	//============================================

	//============================================
	//	テクスチャ読み込み
	//============================================
	CNumber::Load();	//ナンバーテクスチャの読み込み

	//============================================
	//	オブジェクトの生成
	//============================================
	m_pMeshField = CMeshField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Model = CModel::Create();
	m_pScore = CScore::Create();
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(-75.0f, 0.0f, 60.0f));
	CBoss::Create(D3DXVECTOR3(-90.0f, 0.0f, 115.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pSpawn = CSpawn::Create();
	/*for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		m_pEnemy[nCnt] = CEnemy::Create(D3DXVECTOR3(100.0f * nCnt + 50.0f, 0.0f, 0.0f), D3DXVECTOR3());
	}*/
	//m_pGasoleneGimmick[0] = CGasolene_Gimmick::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pGasoleneGimmick[0] = CGasolene_Gimmick::Create(D3DXVECTOR3(250.0f, 0.0f, -640.0f));
	//CParticle::Create();

	return S_OK;
}

//============================================
// ゲームの終了処理
//============================================
void CGame::Uninit(void)
{
	//============================================
	//	テクスチャ破棄
	//============================================
	CNumber::Unload();		//ナンバーテクスチャの破棄

	CObject::Release();
}

//============================================
// ゲームの更新処理
//============================================
void CGame::Update()
{

}

//============================================
// ゲームの描画処理
//============================================
void CGame::Draw()
{

}

//============================================
// ゲームの生成
//============================================
CGame *CGame::Create()
{
	CGame *pgame = nullptr;

	//クラスの生成
	pgame = new CGame;				//ゲームのインスタンス生成

	//nullチェック
	if (pgame != nullptr)
	{
		//初期化処理
		pgame->Init();
	}
	else
	{
		assert(false);
	}

	return pgame;
}