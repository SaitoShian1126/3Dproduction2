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
	CBullet();									//コンストラクタ
	~CBullet()override;							//デストラクタ

	HRESULT Init(void)override;						//弾の初期化処理
	void Uninit(void)override;						//弾の終了処理
	void Update(void)override;						//弾の更新処理
	void Draw(void)override;						//弾の描画処理

	void SetLife(int life) { m_nLife = life; }		//弾のライフの設定処理
	void SetBulletPos(D3DXVECTOR3 pos) { m_BulletPos = pos; }
	void SetGimmickUninitFlag(bool flag) { m_GimmickUninitFlag = flag; }

	D3DXVECTOR3 GetBulletPos(void) { return m_BulletPos;}
	int GetBulletLife(void) { return m_nLife; }

	void HitEnemy(D3DXVECTOR3 pos);		//弾と敵の当たり判定
	void HitGimmick(D3DXVECTOR3 pos);	//弾とギミックの当たり判定

	static CBullet *Create(D3DXVECTOR3 pos,D3DXVECTOR3 move, int nLife);		//生成

private:
	D3DXVECTOR3 m_BulletPos;						//位置
	D3DXVECTOR3 m_BulletRot;						//向き
	D3DXVECTOR3	m_BulletMove;						//移動
	CEnemy *m_pEnemy;								//敵のインスタンス
	CFade *m_pFade;									//フェードのインスタンス

	int m_nLife;									//体力
	bool m_EnemyDeathFlag;							//敵が死んだのかフラグ
	bool m_GimmickUninitFlag;						//ギミックが消えたのかフラグ
	bool m_BulletMoveFlag;							//弾がレティクルの方向へ向かっていくフラグ
};

#endif

