//============================================
//
//	player.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
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
// �ÓI�����o�ϐ��錾
//============================================
D3DXVECTOR3 CPlayer::m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

//============================================
// �I�u�W�F�N�g�̃R���X�g���N�^
//============================================
CPlayer::CPlayer()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
}

//============================================
// �I�u�W�F�N�g�̃f�X�g���N�^
//============================================
CPlayer::~CPlayer()
{
	//���������Ȃ�
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̏���������
//============================================
HRESULT CPlayer::Init(void)
{
	//============================================
	// �����o�ϐ��̏�����
	//============================================
	m_pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_posOld = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_size = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_rot = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_rotDest = D3DXVECTOR3(0.0f,0.0f,0.0f);

	CObjectX::Init();

	m_pShadow = CShadow::Create(D3DXVECTOR3(0.0f,0.0f,0.0f));		//�e�̐ݒ菈���̏�����

	//���f���̎g�p��false�ɂ���
	m_PlayerModel = false;
	SetModel("data/XMODEL/�o�M�[.x");

	return S_OK;
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̏I������
//============================================
void CPlayer::Uninit(void)
{
	CObjectX::Uninit();
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̍X�V����
//============================================
void CPlayer::Update(void)
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	CMeshField *pMeshField = CGame::GetMeshField();
	D3DXVECTOR3 CameraRot = CCamera::GetCameraRot();
	D3DXVECTOR3 PlayerPos = GetPos();
	D3DXVECTOR3 ShadowPos = m_pShadow->GetPos();
	D3DXVECTOR3 PlayerRot = GetRot();

	ShadowPos.y = 0.8f;

	//�����
	if (pInput->GetKeyboardPress(DIK_UP) == true)
	{//W�L�[�������ꂽ
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{
			PlayerPos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//�ړ���
			PlayerPos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//�ړ���
			m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					//�����p�x

			ShadowPos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//�ړ���
			ShadowPos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//�ړ���
		}
		else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{
			PlayerPos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//�ړ���
			PlayerPos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//�ړ���
			m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					//�����p�x

			ShadowPos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//�ړ���
			ShadowPos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//�ړ���
		}
		else
		{
			PlayerPos.x += sinf(CameraRot.y) * PLAYER_MOVE;						//�ړ���
			PlayerPos.z += cosf(CameraRot.y) * PLAYER_MOVE;						//�ړ���
			m_rotDest.y = (CameraRot.y + D3DX_PI);							//�����p�x

			ShadowPos.x += sinf(CameraRot.y) * PLAYER_MOVE / 2;
			ShadowPos.z += cosf(CameraRot.y) * PLAYER_MOVE / 2;
		}
	}
	//������
	else if (pInput->GetKeyboardPress(DIK_DOWN) == true)
	{//S�L�[�������ꂽ
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{
			PlayerPos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//�ړ���
			PlayerPos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	//�ړ���
			m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);						//�����p�x

			ShadowPos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//�ړ���
			ShadowPos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE / 2;	//�ړ���
		}
		else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{
			PlayerPos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//�ړ���
			PlayerPos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	//�ړ���
			m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);						//�����p�x

			ShadowPos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//�ړ���
			ShadowPos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE / 2;	//�ړ���
		}
		else
		{
			PlayerPos.x -= sinf(CameraRot.y) * PLAYER_MOVE;						//�ړ���
			PlayerPos.z -= cosf(CameraRot.y) * PLAYER_MOVE;						//�ړ���
			m_rotDest.y = CameraRot.y;											//�����p�x

			ShadowPos.x -= sinf(CameraRot.y) * PLAYER_MOVE / 2;						//�ړ���
			ShadowPos.z -= cosf(CameraRot.y) * PLAYER_MOVE / 2;						//�ړ���
		}
	}
	//������
	else if (pInput->GetKeyboardPress(DIK_LEFT) == true)
	{//A�L�[�������ꂽ
		PlayerPos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//�ړ���
		PlayerPos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//�ړ���
		m_rotDest.y = (CameraRot.y + D3DX_PI / 2);								//�����p�x

		ShadowPos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//�ړ���
		ShadowPos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//�ړ���
	}
	//�E����
	else if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
	{//D�L�[�������ꂽ
		PlayerPos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//�ړ���
		PlayerPos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			//�ړ���
		m_rotDest.y = (CameraRot.y - D3DX_PI / 2);								//�����p�x

		ShadowPos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//�ړ���
		ShadowPos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE / 2;			//�ړ���
	}

	//============================================
	// �ړI�̊p�x�̐��K��
	//============================================
	if (m_rotDest.y - PlayerRot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - PlayerRot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	//�p�x����
	PlayerRot.y += (m_rotDest.y - PlayerRot.y) * 0.1f;

	//============================================*
	// �p�x�̐��K��
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

	CDebugProc::Print("�v���C���[�̌����Ă�p�x:%f\n�v���C���[�̍���:%.2f", PlayerRot.y, PlayerPos.y);
	
	CObjectX::Update();
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̕`�揈��
//============================================
void CPlayer::Draw(void)
{
	CObjectX::Draw();
}

//============================================
// ����
//============================================
CPlayer * CPlayer::Create(const D3DXVECTOR3 &pos)
{
	CPlayer *pPlayer = nullptr;

	//3D�I�u�W�F�N�g�N���X�̐���
	pPlayer = new CPlayer;				//3D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pPlayer != nullptr)
	{
		//����������
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
// �v���C���[���f���̐ݒ�
//============================================
CPlayer * CPlayer::SetPlayerModel(char * pFile)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//X�t�@�C���̓ǂݍ���
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
