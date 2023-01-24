//============================================
//
//	spawn.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _SPAWN_H_
#define _SPAWN_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "objectX.h"

//============================================
// マクロ定義
//============================================
#define ENEMY_CREATE_TIME	(250)	//敵が生成されるまでの時間
#define MAX_ENEMY			(2)		//敵の最大数

//============================================
// 前方宣言
//============================================
class CEnemy;

//============================================
// 量産クラス
//============================================
class CSpawn :public CObjectX
{
public:
	CSpawn();						//コンストラクタ
	~CSpawn();						//デストラクタ

	HRESULT Init(void);				//量産の初期化処理
	void Uninit(void);				//量産の終了処理
	void Update(void);				//量産の更新処理
	void Draw(void);				//量産の描画処理

	void EnemySpawn(void);			//敵の量産処理
	
	//getter
	int GetEnemyCount(void) { return m_EnemyCount; }	//敵の総数の取得処理

	//setter
	void SetEnemyCount(int cnt) { m_EnemyCount = cnt; }	//敵の総数の設定処理

	static CEnemy **GetEnemy() { return m_pEnemy; }		//敵の情報の取得処理

	static CSpawn *Create();		//生成処理

private:
	static CEnemy *m_pEnemy[MAX_ENEMY];	//敵のインスタンス
	int m_EnemyCreateTime;				//敵が生成されるまでの時間
	int m_RandNumber;					//ランダムな値が入る変数
	int m_RandPos;						//ランダムな位置に敵を生成
	int m_EnemyCount;					//敵の総数

	bool m_RandFlag;					//敵のランダムフラグ
	bool m_MaxEnemyFlag;				//敵が最大値に達したのかのフラグ

};
#endif