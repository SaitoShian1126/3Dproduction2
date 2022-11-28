//============================================
//
//	player.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "objectx.h"

//============================================
// マクロ定義
//============================================
#define PLAYER_MOVE	(1.0f)	//プレイヤーの移動

//============================================
// 前方宣言
//============================================
class CShadow;

//============================================
// オブジェクトクラス
//============================================
class CPlayer : public CObjectX
{
public:
	CPlayer();									//コンストラクタ
	~CPlayer()override;									//デストラクタ

	HRESULT Init(void)override;						//ポリゴンの初期化処理
	void Uninit(void)override;						//ポリゴンの終了処理
	void Update(void)override;						//ポリゴンの更新処理
	void Draw(void)override;						//ポリゴンの描画処理

	static D3DXVECTOR3 GetPlayerPos(void) { return m_pos; }
	static CPlayer *Create(const D3DXVECTOR3 &pos);			//生成
	CPlayer *SetPlayerModel(char *pFile);

private:
	static D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_size;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_rotDest;
	LPD3DXBUFFER m_PlayerBuffMat;
	LPD3DXMESH m_PlayerMesh;
	DWORD m_nPlayerNumMat;
	CShadow *m_pShadow;

	bool m_PlayerModel;
	float m_PlayerHeightPos;
};

#endif
