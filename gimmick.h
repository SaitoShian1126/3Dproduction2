//============================================
//
//	gimmick.h
//	Author: saito shian
//
//============================================
#ifndef _GIMMICK_H_
#define _GIMMICK_H_

//============================================
// インクルードファイル
//============================================
#include "objectX.h"

//============================================
// 前方定義
//============================================

//============================================
// クラスの定義
//============================================
class CGimmick : public CObjectX
{
public:
	//============================================
	// ギミックのタイプ
	//============================================
	enum GIMMICKTYPE
	{
		GIMMICKTYPE_NONE = 0,
		GIMMICKTYPE_GASOLENE,				//ガソリンギミック
		GIMMICKTYPE_MAX
	};

	CGimmick();
	~CGimmick() override;

	HRESULT Init() override;			//初期化処理
	void Uninit() override;				//終了処理
	void Update() override;				//更新処理
	void Draw() override;				//描画処理

	void SetGimmickType(GIMMICKTYPE type);								//ギミックの種類の設定
	GIMMICKTYPE GetGimmickType(void) { return m_GimmickType; }			//ギミックの種類の取得

private:
	D3DXVECTOR3 m_Pos;				//ギミックの位置
	GIMMICKTYPE m_GimmickType;		//ギミックの種類
};
#endif
