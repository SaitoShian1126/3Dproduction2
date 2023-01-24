//============================================
//
//	gasolene_gimmick.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "gasolene_gimmick.h"
#include "player.h"
#include "bullet.h"
#include "explosion.h"
#include "game.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================

//============================================
// �M�~�b�N�̃R���X�g���N�^
//============================================
CGasolene_Gimmick::CGasolene_Gimmick()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//============================================
// �M�~�b�N�̃f�X�g���N�^
//============================================
CGasolene_Gimmick::~CGasolene_Gimmick()
{
	//���������Ȃ�
}

//============================================
// �M�~�b�N�̏���������
//============================================
HRESULT CGasolene_Gimmick::Init(void)
{
	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_size = D3DXVECTOR3(30.0f, 30.0f, 30.0f);
	m_nLife = 10;

	//�I�u�W�F�N�g��b�̏���������
	CObjectX::Init();
	CObjectX::SetModel("data/XMODEL/gasolene.x");

	return S_OK;
}

//============================================
// �M�~�b�N�̏I������
//============================================
void CGasolene_Gimmick::Uninit(void)
{
	//�I�u�W�F�N�g��b�̏I������
	CObjectX::Uninit();
}

//============================================
// �M�~�b�N�̍X�V����
//============================================
void CGasolene_Gimmick::Update(void)
{
	if (m_nLife <= 0)
	{
		CExplosion::Create(D3DXVECTOR3(m_pos.x,m_pos.y + 20.0f,m_pos.z), D3DXVECTOR3(50.0f, 50.0f, 0.0f));
		CPlayer::GetBullet()->SetGimmickUninitFlag(true);
		Uninit();
		return;
	}

	//�I�u�W�F�N�g��b�̍X�V����
	CObjectX::Update();

	//�ʒu�̐ݒ�
	SetPosition(m_pos);
}

//============================================
// �M�~�b�N�̕`�揈��
//============================================
void CGasolene_Gimmick::Draw(void)
{
	//�I�u�W�F�N�g��b�̕`�揈��
	CObjectX::Draw();
}

//============================================
// �����������̓����蔻��
//============================================
void CGasolene_Gimmick::HitDamage()
{
	
}

//============================================
// ����
//============================================
CGasolene_Gimmick * CGasolene_Gimmick::Create(D3DXVECTOR3 pos)
{
	CGasolene_Gimmick *pGasolene = nullptr;

	//3D�I�u�W�F�N�g�N���X�̐���
	pGasolene = new CGasolene_Gimmick;				//3D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pGasolene != nullptr)
	{
		//����������
		pGasolene->Init();
		pGasolene->SetPosition(pos);
	}
	else
	{
		assert(false);
	}
	return pGasolene;
}
