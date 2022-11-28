//============================================
//
//	camera.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
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
// �ÓI�����o�ϐ��錾
//============================================
D3DXVECTOR3 CCamera::m_Rot = {};

//============================================
// �J�����̃R���X�g���N�^
//============================================
CCamera::CCamera()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
}

//============================================
// �J�����̃f�X�g���N�^
//============================================
CCamera::~CCamera()
{
	//���������Ȃ�
}

//============================================
// �J�����̏���������
//============================================
HRESULT CCamera::Init(void)
{
	m_PosV = D3DXVECTOR3(0.0f, 200.0f, -250.0f);
	m_PosR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_VecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	//<-�Œ�ŗǂ�

	//�J�����̌���
	m_Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�O�����̒藝(sqrtf�̓��[�g�̖���)
	m_fDistance = sqrtf(((m_PosR.x - m_PosV.x) * (m_PosR.x - m_PosV.x)) + ((m_PosR.z - m_PosV.z) * (m_PosR.z - m_PosV.z)));

	return S_OK;
}

//============================================
// �J�����̏I������
//============================================
void CCamera::Uninit(void)
{

}

//============================================
// �J�����̍X�V����
//============================================
void CCamera::Update()
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	//============================================
	// �����_�̐���
	//============================================
	if (pInput->GetKeyboardPress(DIK_Q) == true)
	{//Q�L�[�������ꂽ
		m_Rot.y -= 0.005f * D3DX_PI;		//�E�̉�]��
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//�����_�Ǝ��_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//�����_�Ǝ��_��z�̒���
	}
	if (pInput->GetKeyboardPress(DIK_E) == true)
	{//E�L�[�������ꂽ

		m_Rot.y += 0.005f * D3DX_PI;		//���̉�]��
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//�����_�Ǝ��_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//�����_�Ǝ��_��z�̒���
	}
	//============================================
	// ���_�̐���
	//============================================
	if (pInput->GetKeyboardPress(DIK_T) == true)
	{//T�L�[�������ꂽ
		m_Rot.y -= 0.005f * D3DX_PI;		//�E�̉�]��
		m_PosV.x = m_PosR.x - sinf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��x�̒���
		m_PosV.z = m_PosR.z - cosf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��z�̒���
	}
	if (pInput->GetKeyboardPress(DIK_U) == true)
	{//U�L�[�������ꂽ
		m_Rot.y += 0.005f * D3DX_PI;		//���̉�]��
		m_PosV.x = m_PosR.x - sinf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��x�̒���
		m_PosV.z = m_PosR.z - cosf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��z�̒���
	}
	//============================================
	// �J�����̈ړ�
	//============================================
	//�O�ړ�
	if (pInput->GetKeyboardPress(DIK_Y) == true)
	{//Y�L�[�������ꂽ
		m_PosV.x += sinf(m_Rot.y) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��z�̒���
	}
	//���ړ�
	if (pInput->GetKeyboardPress(DIK_H) == true)
	{//H�L�[�������ꂽ
		m_PosV.x -= sinf(m_Rot.y) * CAMERA_SPEED;
		m_PosV.z -= cosf(m_Rot.y) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		 //���_�ƒ����_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		 //���_�ƒ����_��z�̒���
	}
	//���ړ�
	if (pInput->GetKeyboardPress(DIK_G) == true)
	{//G�L�[�������ꂽ
		m_PosV.x -= sinf(m_Rot.y + D3DX_PI / 2) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y + D3DX_PI / 2) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��z�̒���
	}
	//�E�ړ�
	if (pInput->GetKeyboardPress(DIK_J) == true)
	{//J�L�[�������ꂽ
		m_PosV.x -= sinf(m_Rot.y - D3DX_PI / 2) * CAMERA_SPEED;
		m_PosV.z += cosf(m_Rot.y - D3DX_PI / 2) * CAMERA_SPEED;
		m_PosR.x = m_PosV.x + sinf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��x�̒���
		m_PosR.z = m_PosV.z + cosf(m_Rot.y) * m_fDistance;		//���_�ƒ����_��z�̒���
	}
	//============================================
	// �p�x�̐��K��
	//============================================
	if (m_Rot.y < -D3DX_PI)				//�p�x��-180�x��菬�����Ȃ�����
	{
		m_Rot.y = D3DX_PI;				//�p�x��180�x��������
	}
	else if (m_Rot.y > D3DX_PI)			//�p�x��180�x���傫���Ȃ�����
	{
		m_Rot.y = -D3DX_PI;				//�p�x��-180�x��������
	}

	//============================================
	// �J�����̒Ǐ]����
	//============================================
	//D3DXVECTOR3 PlayerPos = CPlayer::GetPlayerPos();
	//�ړI�̒����_�̐ݒ�
	//m_PosRDest.x = (float)PlayerPos.x + sinf(m_Rot.y) * 40.0f;
	//m_PosRDest.y = 0.0f;
	//m_PosRDest.z = (float)PlayerPos.z + cosf(m_Rot.y) * 0.0f;

	//�ړI�̎��_�̐ݒ�												
	//m_PosVDest.x = (float)PlayerPos.x - sinf(m_Rot.y) * 40.0f;
	//m_PosVDest.y = 0.0f;
	//m_PosVDest.z = (float)PlayerPos.z - cosf(m_Rot.y) * 80.0f;

	//���_�̌�������
	//m_PosR.x += (m_PosRDest.x - m_PosR.x) * 1.0f;
	//m_PosR.z += (m_PosRDest.z - m_PosR.z) * 1.0f;

	//m_PosV.x += (m_PosVDest.x - m_PosV.x) * 1.0f;
	//m_PosV.z += (m_PosVDest.z - m_PosV.z) * 1.0f;
}

//============================================
// �J�����̐ݒ�
//============================================
void CCamera::SetCamera()
{
	//�f�o�C�X�ւ̃|�C���^
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_PosV,
		&m_PosR,
		&m_VecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),										//����p
		(float)m_Viewport.Width / (float)m_Viewport.Height,			//�A�X�y�N�g��
		1.0f,														//�ǂ�����(�j�A)�ǂ��܂�(�t�@�[)���J������
		1000.0f);													//�\�����邩�ݒ�

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}