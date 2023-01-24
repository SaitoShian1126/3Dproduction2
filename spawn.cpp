//============================================
//
//	spawn.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "spawn.h"
#include "enemy.h"
#include "objectX.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================
CEnemy *CSpawn::m_pEnemy[MAX_ENEMY] = {};

//============================================
// �R���X�g���N�^
//============================================
CSpawn::CSpawn()
{
	//============================================
	// �����o�ϐ��̃N���A
	//============================================
}

//============================================
// �f�X�g���N�^
//============================================
CSpawn::~CSpawn()
{
	//���������Ȃ�
}

//============================================
// �ʎY�̏���������
//============================================
HRESULT CSpawn::Init(void)
{
	//============================================
	// �����o�ϐ��̏�����
	//============================================
	m_EnemyCreateTime = ENEMY_CREATE_TIME;
	m_RandNumber = 0;
	m_EnemyCount = 0;
	m_RandPos = 0;
	m_RandFlag = false;
	m_MaxEnemyFlag = false;

	//objectx�̏���������
	CObjectX::Init();

	return S_OK;
}

//============================================
// �ʎY�̏I������
//============================================
void CSpawn::Uninit(void)
{
	//objectx�̏I������
	CObjectX::Uninit();
}

//============================================
// �ʎY�̍X�V����
//============================================
void CSpawn::Update(void)
{
	//objectx�̍X�V����
	CObjectX::Update();

	if (m_MaxEnemyFlag == false)
	{
		//�G�̗ʎY�����̊֐��Ăяo��
		EnemySpawn();
	}
}

//============================================
// �ʎY�̕`�揈��
//============================================
void CSpawn::Draw(void)
{
	//objectx�̕`�揈��
	CObjectX::Draw();
}

//============================================
// �ʎY�̐�������
//============================================
CSpawn *CSpawn::Create()
{
	CSpawn *pSpawn = nullptr;

	// �ʎY�N���X�̐���
	pSpawn = new CSpawn;				// �ʎY�C���X�^���X����

	// nullptr�`�F�b�N
	if (pSpawn != nullptr)
	{
		// ����������
		pSpawn->Init();
	}
	else
	{
		assert(false);
	}
	return pSpawn;
}

//============================================
// �G�̗ʎY����
//============================================
void CSpawn::EnemySpawn(void)
{
	//�G�����������܂ł̎��Ԃ����炵�Ă���1
	m_EnemyCreateTime--;
	m_EnemyCount = GetEnemyCount();

	if (m_EnemyCreateTime <= 0 && m_RandFlag == false)
	{
		m_RandNumber = rand() % 2 + 1;		//�����_���Ȑ��l�����߂�
		m_RandPos = rand() % 150 + 100;		//�����_���Ȉʒu�̐��l�����߂�
		m_RandFlag = true;					//�����_���Ȑ��l�����ߏI�����
	}
	if (m_EnemyCreateTime <= 0)
	{	
		m_EnemyCreateTime = ENEMY_CREATE_TIME;	//���Ԃ�������
	}

	if (m_RandNumber == 1 && m_RandFlag == true)
	{
		m_pEnemy[m_EnemyCount] = CEnemy::Create(D3DXVECTOR3(100.0f, 0.0f, 0.0f), 0);
		m_EnemyCount++;
		m_RandFlag = false;
	}
	if (m_RandNumber == 2 && m_RandFlag == true)
	{
		m_pEnemy[m_EnemyCount] = CEnemy::Create(D3DXVECTOR3(50.0f, 0.0f, 0.0f), 0);
		m_EnemyCount++;
		m_RandFlag = false;
	}

	//if (m_EnemyCount >= MAX_ENEMY)
	//{
	//	m_MaxEnemyFlag = true;	//�G�̑������ő�l�ɒB����
	//}
}
