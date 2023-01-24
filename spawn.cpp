//============================================
//
//	spawn.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "spawn.h"
#include "enemy.h"
#include "objectX.h"

//============================================
// 静的メンバ変数宣言
//============================================
CEnemy *CSpawn::m_pEnemy[MAX_ENEMY] = {};

//============================================
// コンストラクタ
//============================================
CSpawn::CSpawn()
{
	//============================================
	// メンバ変数のクリア
	//============================================
}

//============================================
// デストラクタ
//============================================
CSpawn::~CSpawn()
{
	//何も書かない
}

//============================================
// 量産の初期化処理
//============================================
HRESULT CSpawn::Init(void)
{
	//============================================
	// メンバ変数の初期化
	//============================================
	m_EnemyCreateTime = ENEMY_CREATE_TIME;
	m_RandNumber = 0;
	m_EnemyCount = 0;
	m_RandPos = 0;
	m_RandFlag = false;
	m_MaxEnemyFlag = false;

	//objectxの初期化処理
	CObjectX::Init();

	return S_OK;
}

//============================================
// 量産の終了処理
//============================================
void CSpawn::Uninit(void)
{
	//objectxの終了処理
	CObjectX::Uninit();
}

//============================================
// 量産の更新処理
//============================================
void CSpawn::Update(void)
{
	//objectxの更新処理
	CObjectX::Update();

	if (m_MaxEnemyFlag == false)
	{
		//敵の量産処理の関数呼び出し
		EnemySpawn();
	}
}

//============================================
// 量産の描画処理
//============================================
void CSpawn::Draw(void)
{
	//objectxの描画処理
	CObjectX::Draw();
}

//============================================
// 量産の生成処理
//============================================
CSpawn *CSpawn::Create()
{
	CSpawn *pSpawn = nullptr;

	// 量産クラスの生成
	pSpawn = new CSpawn;				// 量産インスタンス生成

	// nullptrチェック
	if (pSpawn != nullptr)
	{
		// 初期化処理
		pSpawn->Init();
	}
	else
	{
		assert(false);
	}
	return pSpawn;
}

//============================================
// 敵の量産処理
//============================================
void CSpawn::EnemySpawn(void)
{
	//敵が生成されるまでの時間を減らしていく1
	m_EnemyCreateTime--;
	m_EnemyCount = GetEnemyCount();

	if (m_EnemyCreateTime <= 0 && m_RandFlag == false)
	{
		m_RandNumber = rand() % 2 + 1;		//ランダムな数値を決める
		m_RandPos = rand() % 150 + 100;		//ランダムな位置の数値を決める
		m_RandFlag = true;					//ランダムな数値を決め終わった
	}
	if (m_EnemyCreateTime <= 0)
	{	
		m_EnemyCreateTime = ENEMY_CREATE_TIME;	//時間を初期化
	}

	if (m_RandNumber == 1 && m_RandFlag == true)
	{
		m_pEnemy[m_EnemyCount] = CEnemy::Create(D3DXVECTOR3(100.0f, 0.0f, 0.0f), 0);
		m_EnemyCount++;
		m_RandFlag = false;
	}
	if (m_RandNumber == 2 && m_RandFlag == true)
	{
		m_pEnemy[m_EnemyCount] = CEnemy::Create(D3DXVECTOR3(50.0f, 0.0f, 0.0f), 0);
		m_EnemyCount++;
		m_RandFlag = false;
	}

	//if (m_EnemyCount >= MAX_ENEMY)
	//{
	//	m_MaxEnemyFlag = true;	//敵の総数が最大値に達した
	//}
}
