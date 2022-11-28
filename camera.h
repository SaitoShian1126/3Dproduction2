//============================================
//
//	camera.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

//============================================
// インクルード
//============================================
#include "main.h"

//============================================
// マクロ定義
//============================================
#define CAMERA_SPEED	(0.5f)	//カメラの速度

//============================================
// カメラクラス
//============================================
class CCamera
{
public:
	CCamera();				//コンストラクタ
	~CCamera();				//デストラクタ

	HRESULT Init(void);		//カメラの初期化処理
	void Uninit(void);		//カメラの終了処理
	void Update(void);		//カメラの更新処理

	void SetCamera();		//カメラの設定処理

	static D3DXVECTOR3 GetCameraRot() { return m_Rot; }		//カメラの回転の取得処理	

private:
	static D3DXVECTOR3 m_Rot;		//向き
	D3DXVECTOR3 m_PosV;				//視点
	D3DXVECTOR3 m_PosVDest;			//目的の視点
	D3DXVECTOR3 m_PosR;				//注視点
	D3DXVECTOR3 m_PosRDest;			//目的の注視点
	D3DXVECTOR3 m_VecU;				//上方向ベクトル
	D3DVIEWPORT9 m_Viewport;		//ビューポート
	D3DXMATRIX m_mtxProjection;		//プロジェクションマトリックス
	D3DXMATRIX m_mtxView;			//ビューマトリックス

	float m_fDistance;				//視点から注視点の距離			
};

#endif