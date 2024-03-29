//============================================
//
//	bullet.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _BULLET_H_
#define _BULLET_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "objectBase.h"

//============================================
// マクロ定義
//============================================
#define BOMB_SIZE			(9.0f)				//爆弾のサイズ
#define BOMB_HIT_SIZE		(75.0f)				//ボスの弾の当たり判定サイズ

//============================================
// 前方宣言
//============================================
class CEnemy;
class CFade;

//============================================
// 弾クラス
//============================================
class CBullet : public CObjectBase
{
public:
	enum BULLETTYPE
	{
		BULLETTYPE_PLAYER = 0,					//プレイヤーの弾
		BULLETTYPE_BOMB,						//爆弾
		BULLETTYPE_BOSS,						//ボスの弾
		BULLETTYPE_MAX
	};

	CBullet();									//コンストラクタ
	~CBullet()override;							//デストラクタ

	HRESULT Init(void)override;					//弾の初期化処理
	void Uninit(void)override;					//弾の終了処理
	void Update(void)override;					//弾の更新処理
	void Draw(void)override;					//弾の描画処理

	void HitEnemy(D3DXVECTOR3 pos);														//弾と敵の当たり判定
	void HitGimmick(D3DXVECTOR3 pos);													//弾とギミックの当たり判定
	void HitModel(D3DXVECTOR3 pos);														//弾とモデルの当たり判定
	void HitBoss(D3DXVECTOR3 pos);														//弾とボスの当たり判定
	void BulletBehavior();																//弾の挙動
	void BombHitBoss(D3DXVECTOR3 pos, D3DXVECTOR3 size);								//弾(爆弾)とボスの当たり判定
	void BossBullet(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 move);				//ボスの弾の攻撃処理
	void BulletLife();																	//弾の体力

	//getter
	D3DXVECTOR3 GetBulletPos(void) { return m_BulletPos;}								//弾の位置の取得処理
	BULLETTYPE GetBulletType(void) { return m_type; }									//弾の種類の取得処理
	int GetBulletLife(void) { return m_nLife; }											//弾の体力の取得処理
	int GetTotalEnemy(void) { return m_TotalEnemy; }									//敵の総数の取得処理
	bool GetBossDeathFlag(void) { return m_BossDeathFlag; }								//ボスが死んだのかフラグの取得処理

	//setter
	void SetLife(int life);																//弾のライフの設定処理
	void SetBulletPos(D3DXVECTOR3 pos) { m_BulletPos = pos; }							//弾の位置の設定
	void SetGimmickUninitFlag(bool flag) { m_GimmickUninitFlag = flag; }				//ギミックが消えたのかフラグの設定処理
	void SetBossDeathFlag(bool flag) { m_BossDeathFlag = flag; }						//ボスが死んだのかフラグの設定処理
	void SetBulletType(BULLETTYPE type);	//弾の使用者の設定処理

	static CBullet *Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR3 size, int nLife, BULLETTYPE type);		//生成

private:
	D3DXVECTOR3 m_BulletSize;						//サイズ
	D3DXVECTOR3 m_BulletPos;						//位置
	D3DXVECTOR3 m_BulletPosOld;						//前回の位置
	D3DXVECTOR3 m_BulletRot;						//向き
	D3DXVECTOR3	m_BulletMove;						//移動

	BULLETTYPE m_type;								//弾の種類

	CEnemy *m_pEnemy;								//敵のインスタンス
	CFade *m_pFade;									//フェードのインスタンス

	int m_nLife;									//体力
	int m_TotalEnemy;								//敵の総数
	int m_ExplosionTime;							//爆発するまでの時間

	bool m_RandFlag;								//ランダムフラグ
	bool m_ExplosionFlag;							//爆発したのかのフラグ
	bool m_EnemyDeathFlag;							//敵が死んだのかフラグ
	bool m_GimmickUninitFlag;						//ギミックが消えたのかフラグ
	bool m_BossDeathFlag;							//ボスが死んだのかのフラグ
};

#endif

