//============================================
//
//	enemy.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "object.h"

//============================================
// マクロ定義
//============================================
#define ENEMY_MOVE			(1.0f)		//敵の移動
#define MAX_ENEMY_WORD		(512)		//ワード数
#define MODEL_ENEMY_PARTS	(15)		//モデルのパーツ数
#define MOTION_ENEMY_NUMBER	(2)			//モーション数

//============================================
// 前方宣言
//============================================
class CShadow;
class CModelParts;
class CMotionSet;
class CKeySet;
class CKey;

//============================================
// 敵クラス
//============================================
class CEnemy : public CObject
{
public:
	//============================================
	// モーションの種類
	//============================================
	enum MOTIONTYPE
	{
		MOTIONTYPE_NEUTRALMOTION = 0,					//ニュートラルモーション
		MOTIONTYPE_MOVE,								//移動モーション
		MOTIONTYPE_MAX
	};

	CEnemy();											//コンストラクタ
	~CEnemy()override;									//デストラクタ

	HRESULT Init(void)override;							//敵の初期化処理
	void Uninit(void)override;							//敵の終了処理
	void Update(void)override;							//敵の更新処理
	void Draw(void)override;							//敵の描画処理

	void LoadEnemy();									//敵の読み込み
	void Vtx(void);										//最大最小
	void CollisionEnemy(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size);	//敵の当たり判定
	void EnemyMove();									//敵の移動処理

	//setter
	void SetPosition(D3DXVECTOR3 pos);					//敵の位置処理
	void SetRot(D3DXVECTOR3 rot);						//敵の回転処理
	void SetMove(D3DXVECTOR3 move);						//敵の移動処理
	void SetLength(float length);						//長さの設定処理
	void SetLife(int life);								//体力の設定処理
	void SetMotionType(MOTIONTYPE type);				//モーションの種類の設定処理
	void SeteEnemyNum(int num);							//敵の番号の設定

	//getter
	D3DXVECTOR3 GetEnemyPos(void) { return m_pos; }		//敵の位置取得
	D3DXVECTOR3 GetEnemySize(void) { return m_size; }	//敵のサイズ取得
	D3DXVECTOR3 GetEnemyRot(void) { return m_rot; }		//敵の向きの取得
	D3DXVECTOR3 GetPos(void);							//位置の取得処理
	D3DXVECTOR3 GetMove(void);							//移動量の取得
	D3DXVECTOR3 GetSize(void);							//サイズの取得処理
	D3DXVECTOR3 GetRot(void);							//回転の取得
	float GetLength(void);								//拡大縮小のスケールの取得
	int GetLife(void);									//体力の取得処理
	int GetEnemyNum(void);								//敵の番号の取得処理

	static CEnemy *Create(const D3DXVECTOR3 pos,int enemynum);				//生成

private:
	//============================================
	// プライベート関数
	//============================================
	void MotionEnemyAnimation(void);				//モーション関数

	D3DXVECTOR3 m_pos;								//位置
	D3DXVECTOR3 m_rot;								//向き
	D3DXVECTOR3 m_size;								//サイズ
	D3DXVECTOR3 m_VtxMinModel;						//最小
	D3DXVECTOR3 m_VtxMaxModel;						//最大
	CModelParts *m_apModel[MODEL_ENEMY_PARTS];		//モデルパーツ
	CMotionSet *m_MotionSet[MOTION_ENEMY_NUMBER];	//モーションセット
	CKeySet *m_KeySet;								//キーセット
	CKey *m_Key;									//キー
	D3DXVECTOR3 m_posOld;							//目的の位置
	D3DXVECTOR3 m_rotDest;							//目的の向き
	D3DXVECTOR3 m_FrameSpeed[MODEL_ENEMY_PARTS];	//フレームの速さ
	D3DXVECTOR3 m_RotSpeed[MODEL_ENEMY_PARTS];		//回転の速さ
	D3DXVECTOR3 m_move;								//移動
	D3DXMATRIX m_mtxWorld;							//ワールドマトリックス
	D3DXMATRIX *m_pmtxParent;						//親のマトリックス
	CShadow *m_pShadow;								//影

	MOTIONTYPE m_MotionType;						//モーションの種類

	int m_Frame;									//フレーム
	int m_PresentKeySet;							//現在のキーセット
	int m_nLife;									//体力
	int m_nCountModel;								//モデル数のカウント
	int m_EnemyNumber;								//敵の番号

	float m_PlayerHeightPos;						//敵の高さの位置
	float m_Length;									//長さ
	float m_Angle;									//角度
};

#endif
