//============================================
//
//	game.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "object3d.h"
#include "objectX.h"
#include "game.h"
#include "player.h"
#include "billboard.h"
#include "meshfield.h"
#include "sphere.h"
#include "input.h"
#include "fade.h"
#include "result.h"
#include "number.h"
#include "score.h"
#include "objectbase.h"
#include "enemy.h"
#include "model.h"
#include "particle.h"
#include "boss.h"
#include "gasolene_gimmick.h"
#include "bullet.h"
#include "explosion.h"
#include "spawn.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================
CMeshField *CGame::m_pMeshField = nullptr;
CScore *CGame::m_pScore = nullptr;
CGasolene_Gimmick *CGame::m_pGasoleneGimmick[MAX_GASOLENE] = {};
CModel *CGame::m_Model = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
CSpawn *CGame::m_pSpawn = nullptr;

//============================================
// �Q�[���̃R���X�g���N�^
//============================================
CGame::CGame()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
}

//============================================
// �Q�[���̃f�X�g���N�^
//============================================
CGame::~CGame()
{
	//���������Ȃ�
}

//============================================
// �Q�[���̏���������
//============================================
HRESULT CGame::Init(void)
{
	//============================================
	// �����o�ϐ��̏�����
	//============================================

	//============================================
	//	�e�N�X�`���ǂݍ���
	//============================================
	CNumber::Load();	//�i���o�[�e�N�X�`���̓ǂݍ���

	//============================================
	//	�I�u�W�F�N�g�̐���
	//============================================
	m_pMeshField = CMeshField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Model = CModel::Create();
	m_pScore = CScore::Create();
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(-75.0f, 0.0f, 60.0f));
	CBoss::Create(D3DXVECTOR3(-90.0f, 0.0f, 115.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pSpawn = CSpawn::Create();
	/*for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		m_pEnemy[nCnt] = CEnemy::Create(D3DXVECTOR3(100.0f * nCnt + 50.0f, 0.0f, 0.0f), D3DXVECTOR3());
	}*/
	//m_pGasoleneGimmick[0] = CGasolene_Gimmick::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_pGasoleneGimmick[0] = CGasolene_Gimmick::Create(D3DXVECTOR3(250.0f, 0.0f, -640.0f));
	//CParticle::Create();

	return S_OK;
}

//============================================
// �Q�[���̏I������
//============================================
void CGame::Uninit(void)
{
	//============================================
	//	�e�N�X�`���j��
	//============================================
	CNumber::Unload();		//�i���o�[�e�N�X�`���̔j��

	CObject::Release();
}

//============================================
// �Q�[���̍X�V����
//============================================
void CGame::Update()
{

}

//============================================
// �Q�[���̕`�揈��
//============================================
void CGame::Draw()
{

}

//============================================
// �Q�[���̐���
//============================================
CGame *CGame::Create()
{
	CGame *pgame = nullptr;

	//�N���X�̐���
	pgame = new CGame;				//�Q�[���̃C���X�^���X����

	//null�`�F�b�N
	if (pgame != nullptr)
	{
		//����������
		pgame->Init();
	}
	else
	{
		assert(false);
	}

	return pgame;
}