//============================================
//
//	camera.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "camera.h"
#include "application.h"
#include "renderer.h" 
#include "object3d.h"
#include "fade.h"
#include "input.h"
#include "application.h"
#include "player.h"

//============================================
// 静的メンバ変数宣言
//============================================
D3DXVECTOR3 CCamera::m_Rot = {};

//============================================
// カメラのコンストラクタ
//============================================
CCamera::CCamera()
{
	//============================================
	//メンバ変数のクリア
	//============================================
}

//============================================
// カメラのデストラクタ
//============================================
CCamera::~CCamera()
{
	//何も書かない
}

//============================================
// カメラの初期化処理
//============================================
HRESULT CCamera::Init(void)
{
	m_PosV = D3DXVECTOR3(0.0f, 200.0f, -250.0f);
	m_PosR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_VecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	//<-固定で良い

	//カメラの向き
	m_Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//三平方の定理(sqrtfはルートの役割)
	m_fDistance = sqrtf(((m_PosR.x - m_PosV.x) * (m_PosR.x - m_PosV.x)) + ((m_PosR.z - m_PosV.z) * (m_PosR.z - m_PosV.z)));

	return S_OK;
}

//============================================
// カメラの終了処理
//============================================
void CCamera::Uninit(void)
{

}

//============================================
// カメラの更新処理
//============================================
void CCamera::Update()
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	//============================================
	// 注視点の旋回
	//============================================
	if (pInput->GetKeyboardPress(DIK_Q) == true)
	{//Qキーが押された
		m_Rot.y -= 0.005f * D3DX_PI;		//右の回転量
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//注視点と視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//注視点と視点のzの長さ
	}
	if (pInput->GetKeyboardPress(DIK_E) == true)
	{//Eキーが押された

		m_Rot.y += 0.005f * D3DX_PI;		//左の回転量
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//注視点と視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//注視点と視点のzの長さ
	}
	//============================================
	// 視点の旋回
	//============================================
	if (pInput->GetKeyboardPress(DIK_T) == true)
	{//Tキーが押された
		m_Rot.y -= 0.005f * D3DX_PI;		//右の回転量
		m_PosV.x = m_PosR.x - sinf(m_Rot.y) * m_fDistance;		//視点と注視点のxの長さ
		m_PosV.z = m_PosR.z - cosf(m_Rot.y) * m_fDistance;		//視点と注視点のzの長さ
	}
	if (pInput->GetKeyboardPress(DIK_U) == true)
	{//Uキーが押された
		m_Rot.y += 0.005f * D3DX_PI;		//左の回転量
		m_PosV.x = m_PosR.x - sinf(m_Rot.y) * m_fDistance;		//視点と注視点のxの長さ
		m_PosV.z = m_PosR.z - cosf(m_Rot.y) * m_fDistance;		//視点と注視点のzの長さ
	}
	//============================================
	// カメラの移動
	//============================================
	//前移動
	if (pInput->GetKeyboardPress(DIK_Y) == true)
	{//Yキーが押された
		m_PosV.x += sinf(m_Rot.y) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//視点と注視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//視点と注視点のzの長さ
	}
	//後ろ移動
	if (pInput->GetKeyboardPress(DIK_H) == true)
	{//Hキーが押された
		m_PosV.x -= sinf(m_Rot.y) * CAMERA_SPEED;
		m_PosV.z -= cosf(m_Rot.y) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		 //視点と注視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		 //視点と注視点のzの長さ
	}
	//左移動
	if (pInput->GetKeyboardPress(DIK_G) == true)
	{//Gキーが押された
		m_PosV.x -= sinf(m_Rot.y + D3DX_PI / 2) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y + D3DX_PI / 2) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//視点と注視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//視点と注視点のzの長さ
	}
	//右移動
	if (pInput->GetKeyboardPress(DIK_J) == true)
	{//Jキーが押された
		m_PosV.x -= sinf(m_Rot.y - D3DX_PI / 2) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y - D3DX_PI / 2) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//視点と注視点のxの長さ
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//視点と注視点のzの長さ
	}
	//============================================
	// 角度の正規化
	//============================================
	if (m_Rot.y < -D3DX_PI)				//角度が-180度より小さくなったら
	{
		m_Rot.y = D3DX_PI;				//角度に180度を代入する
	}
	else if (m_Rot.y > D3DX_PI)			//角度が180度より大きくなったら
	{
		m_Rot.y = -D3DX_PI;				//角度に-180度を代入する
	}

	//============================================
	// カメラの追従処理
	//============================================
	//D3DXVECTOR3 PlayerPos = CPlayer::GetPlayerPos();
	//目的の注視点の設定
	//m_PosRDest.x = (float)PlayerPos.x + sinf(m_Rot.y) * 40.0f;
	//m_PosRDest.y = 0.0f;
	//m_PosRDest.z = (float)PlayerPos.z + cosf(m_Rot.y) * 0.0f;

	//目的の視点の設定												
	//m_PosVDest.x = (float)PlayerPos.x - sinf(m_Rot.y) * 40.0f;
	//m_PosVDest.y = 0.0f;
	//m_PosVDest.z = (float)PlayerPos.z - cosf(m_Rot.y) * 80.0f;

	//視点の減衰処理
	//m_PosR.x += (m_PosRDest.x - m_PosR.x) * 1.0f;
	//m_PosR.z += (m_PosRDest.z - m_PosR.z) * 1.0f;

	//m_PosV.x += (m_PosVDest.x - m_PosV.x) * 1.0f;
	//m_PosV.z += (m_PosVDest.z - m_PosV.z) * 1.0f;
}

//============================================
// カメラの設定
//============================================
void CCamera::SetCamera()
{
	//デバイスへのポインタ
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_PosV,
		&m_PosR,
		&m_VecU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);

	//プロジェクションマトリックスの作成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),										//視野角
		(float)m_Viewport.Width / (float)m_Viewport.Height,			//アスペクト比
		1.0f,														//どこから(ニア)どこまで(ファー)をカメラで
		1000.0f);													//表示するか設定

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}