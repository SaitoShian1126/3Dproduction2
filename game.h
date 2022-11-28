//============================================
//
//	game.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _GAME_H_
#define _GAME_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "mode.h"
#include "object2D.h"

//============================================
// 前方宣言
//============================================
class CMeshField;
class CFade;

//============================================
// ゲームクラス
//============================================
class CGame : public CMode
{
public:
	CGame();					//コンストラクタ
	~CGame();					//デストラクタ

	HRESULT Init(void);			//ゲームの初期化処理
	void Uninit(void);			//ゲームの終了処理
	void Update(void);			//ゲームの更新処理
	void Draw(void);			//ゲームの描画処理

	static CMeshField *GetMeshField(void) { return m_pMeshField; }		//メッシュフィールドの情報の取得処理
	static CGame *Create();												//生成

private:
	static CMeshField *m_pMeshField;	
	CFade *m_pFade;						//フェード
};

#endif






