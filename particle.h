//============================================
//
//	particle.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "objectbase.h"

//============================================
// 前方宣言
//============================================

//============================================
// パーティクルクラス
//============================================
class CParticle : public CObjectBase
{
public:
	CParticle();									//コンストラクタ
	~CParticle() override;							//デストラクタ

	HRESULT Init(void)override;						//パーティクルの初期化処理
	void Uninit(void)override;						//パーティクルの終了処理
	void Update(void)override;						//パーティクルの更新処理
	void Draw(void)override;						//パーティクルの描画処理

	static void SetBillboardPos(D3DXVECTOR3 pos) { m_pos = pos; }	//パーティクルの位置設定
	static D3DXVECTOR3 GetBillboardPos(void) { return m_pos; }		//パーティクルの位置取得
	static CParticle *Create();			//生成

private:
	static D3DXVECTOR3 m_pos;		//位置
	int m_Life;						//体力
	
};

#endif

