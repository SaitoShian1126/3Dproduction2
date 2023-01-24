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
// マクロ定義
//============================================
#define MAX_ENEMY		(2)	//敵の最大数
#define MAX_GASOLENE	(1)	//ガソリンの最大数

//============================================
// 前方宣言
//============================================
class CMeshField;
class CEnemy;
class CFade;
class CScore;
class CGasolene_Gimmick;
class CModel;
class CHitBox;
class CPlayer;
class CSpawn;

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

	static CMeshField *GetMeshField(void) { return m_pMeshField; }								//メッシュフィールドの情報の取得処理
	static CScore *GetScore(void) { return m_pScore; }											//敵の情報の取得処理
	static CGasolene_Gimmick *GetGasoleneGimmick(int cnt) { return m_pGasoleneGimmick[cnt]; }	//ガソリンギミックの情報の取得処理
	static CModel *GetModel(void) { return m_Model; }											//モデルの取得処理
	static CPlayer *GetPlayer(void) { return m_pPlayer; }										//プレイヤー取得処理
	static CSpawn *GetSpawn(void) { return m_pSpawn; }											//スポーンの取得処理

	static CGame *Create();												//生成

private:
	static CMeshField *m_pMeshField;							//メッシュフィールドのインスタンス
	static CScore *m_pScore;									//スコアのインスタンス
	static CGasolene_Gimmick *m_pGasoleneGimmick[MAX_GASOLENE];	//ガソリンギミックのインスタンス
	static CModel *m_Model;										//モデルのインスタンス
	static CPlayer *m_pPlayer;									//プレイヤーのインスタンス
	static CSpawn *m_pSpawn;									//スポーンのインスタンス
	CFade *m_pFade;												//フェードのインスタンス
};
#endif



