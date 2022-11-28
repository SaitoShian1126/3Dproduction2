//============================================
//
//	player.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "player.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "shadow.h"
#include "debug.h"
#include "meshfield.h"
#include "game.h"

//============================================
// 静的メンバ変数宣言
//============================================
D3DXVECTOR3 CPlayer::m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

//============================================
// オブジェクトのコンストラクタ
//============================================
CPlayer::CPlayer()
{
	//============================================
	//メンバ変数のクリア
	//============================================
}

//============================================
// オブジェクトのデストラクタ
//============================================
CPlayer::~CPlayer()
{
	//何も書かない
}

//============================================
// オブジェクト(ポリゴン)の初期化処理
//============================================
HRESULT CPlayer::Init(void)
{
	//============================================
	// メンバ変数の初期化
	//============================================
	m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_posOld = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_size = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_rot = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_rotDest = D3DXVECTOR3(0.0f,0.0f,0.0f);

	CObjectX::Init();

	m_pShadow = CShadow::Create(D3DXVECTOR3(0.0f,0.0f,0.0f));		//影の設定処理の初期化

	//モデルの使用をfalseにする
	m_PlayerModel = false;
	SetModel("data/XMODEL/バギー.x");

	return S_OK;
}

//============================================
// オブジェクト(ポリゴン)の終了処理
//============================================
void CPlayer::Uninit(void)
{
	CObjectX::Uninit();
}

//============================================
// オブジェクト(ポリゴン)の更新処理
//============================================
void CPlayer::Update(void)
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	CMeshField *pMeshField = CGame::GetMeshField();
	D3DXVECTOR3 CameraRot = CCamera::GetCameraRot();
	D3DXVECTOR3 PlayerPos = GetPos();
	D3DXVECTOR3 ShadowPos = m_pShadow->GetPos();
	D3DXVECTOR3 PlayerRot = GetRot();

	ShadowPos.y = 0.8f;

	//上方向
	if (pInput->GetKeyboardPress(DIK_UP) == true)
	{//Wキーが押された
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{
			PlayerPos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//移動量
			PlayerPos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//移動量
			m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					//向く角度

			ShadowPos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//移動量
			ShadowPos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//移動量
		}
		else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{
			PlayerPos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//移動量
			PlayerPos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//移動量
			m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					//向く角度

			ShadowPos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//移動量
			ShadowPos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//移動量
		}
		else
		{
			PlayerPos.x += sinf(CameraRot.y) * PLAYER_MOVE;						//移動量
			PlayerPos.z += cosf(CameraRot.y) * PLAYER_MOVE;						//移動量
			m_rotDest.y = (CameraRot.y + D3DX_PI);							//向く角度

			ShadowPos.x += sinf(CameraRot.y) * PLAYER_MOVE / 2;
			ShadowPos.z += cosf(CameraRot.y) * PLAYER_MOVE / 2;
		}
	}
	//下方向
	else if (pInput->GetKeyboardPress(DIK_DOWN) == true)
	{//Sキーが押された
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{
			PlayerPos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//移動量
			PlayerPos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//移動量
			m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);						//向く角度

			ShadowPos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//移動量
			ShadowPos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//移動量
		}
		else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{
			PlayerPos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//移動量
			PlayerPos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//移動量
			m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);						//向く角度

			ShadowPos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//移動量
			ShadowPos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//移動量
		}
		else
		{
			PlayerPos.x -= sinf(CameraRot.y) * PLAYER_MOVE;						//移動量
			PlayerPos.z -= cosf(CameraRot.y) * PLAYER_MOVE;						//移動量
			m_rotDest.y = CameraRot.y;											//向く角度

			ShadowPos.x -= sinf(CameraRot.y) * PLAYER_MOVE / 2;						//移動量
			ShadowPos.z -= cosf(CameraRot.y) * PLAYER_MOVE / 2;						//移動量
		}
	}
	//左方向
	else if (pInput->GetKeyboardPress(DIK_LEFT) == true)
	{//Aキーが押された
		PlayerPos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//移動量
		PlayerPos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//移動量
		m_rotDest.y = (CameraRot.y + D3DX_PI / 2);								//向く角度

		ShadowPos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//移動量
		ShadowPos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//移動量
	}
	//右方向
	else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
	{//Dキーが押された
		PlayerPos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//移動量
		PlayerPos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//移動量
		m_rotDest.y = (CameraRot.y - D3DX_PI / 2);								//向く角度

		ShadowPos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//移動量
		ShadowPos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//移動量
	}

	//============================================
	// 目的の角度の正規化
	//============================================
	if (m_rotDest.y - PlayerRot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - PlayerRot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	//角度慣性
	PlayerRot.y += (m_rotDest.y - PlayerRot.y) * 0.1f;

	//============================================*
	// 角度の正規化
	//============================================*
	if (PlayerRot.y > D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y - D3DX_PI * 2;
	}
	else if (PlayerRot.y < -D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y + D3DX_PI * 2;
	}

	pMeshField->GetMeshFieldCollision(&PlayerPos);
	SetPosition(PlayerPos);

	//m_pShadow->SetPosition(ShadowPos);
	SetRot(PlayerRot);

	CDebugProc::Print("プレイヤーの向いてる角度:%f\nプレイヤーの高さ:%.2f", PlayerRot.y, PlayerPos.y);
	
	CObjectX::Update();
}

//============================================
// オブジェクト(ポリゴン)の描画処理
//============================================
void CPlayer::Draw(void)
{
	CObjectX::Draw();
}

//============================================
// 生成
//============================================
CPlayer * CPlayer::Create(const D3DXVECTOR3 &pos)
{
	CPlayer *pPlayer = nullptr;

	//3Dオブジェクトクラスの生成
	pPlayer = new CPlayer;				//3Dオブジェクトのインスタンス生成

	//nullチェック
	if (pPlayer != nullptr)
	{
		//初期化処理
		pPlayer->Init();
		pPlayer->SetPosition(pos);
	}
	else
	{
		assert(false);
	}
	return pPlayer;
}

//============================================
// プレイヤーモデルの設定
//============================================
CPlayer * CPlayer::SetPlayerModel(char * pFile)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//Xファイルの読み込み
	D3DXLoadMeshFromX(pFile,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_PlayerBuffMat,
		NULL,
		&m_nPlayerNumMat,
		&m_PlayerMesh);

	m_PlayerModel = true;

	return S_OK;
}
