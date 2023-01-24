//============================================
//
//	bullet.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "bullet.h"
#include "application.h"
#include "renderer.h"
#include "player.h"
#include "object2D.h"
#include "score.h"
#include "game.h"
#include "enemy.h"
#include "fade.h"
#include "result.h"
#include "billboard.h"
#include "gasolene_gimmick.h"
#include "spawn.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================

//============================================
// �e�̃R���X�g���N�^
//============================================
CBullet::CBullet()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_EnemyDeathFlag = false;
	m_GimmickUninitFlag = false;
}

//============================================
// �e�̃f�X�g���N�^
//============================================
CBullet::~CBullet()
{
	//���������Ȃ�
}

//============================================
// �e�̏���������
//============================================
HRESULT CBullet::Init(void)
{
	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_BulletPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_BulletMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_EnemyDeathFlag = false;
	m_GimmickUninitFlag = false;
	m_BulletMoveFlag = false;

	//�I�u�W�F�N�g��b�̏���������
	CObjectBase::Init();

	SetTexture("data/TEXTURE/bullet000.png");

	return S_OK;
}

//============================================
// �e�̏I������
//============================================
void CBullet::Uninit(void)
{
	//�I�u�W�F�N�g��b�̏I������
	CObjectBase::Uninit();
}

//============================================
// �e�̍X�V����
//============================================
void CBullet::Update(void)
{
	//�v���C���[�̏��擾
	D3DXVECTOR3 BulletPos = GetPos();
	D3DXVECTOR3 BulletMove = GetMove();

	m_BulletPos = BulletPos;

	//�e�̈ʒu�X�V
	m_BulletPos += BulletMove;

	//���������炷����
	m_nLife--;

	//�e�̃��C�t��0�ɂȂ�����
	if (m_nLife <= 0)
	{
		//�e�̍폜
		Uninit();
		return;
	}

	//�e�ƓG�̓����蔻�菈��
	if (m_EnemyDeathFlag == false)
	{
		HitEnemy(m_BulletPos);
	}
	//�e�ƃM�~�b�N�̓����蔻��
	if (m_GimmickUninitFlag == false)
	{
		HitGimmick(m_BulletPos);
	}

	//�ʒu�̐ݒ�
	SetPosition(m_BulletPos);
	//�ړ��̐ݒ�
	SetMove(BulletMove);
	//�����̐ݒ�
	SetRot(m_BulletRot);
}

//============================================
// �e�̕`�揈��
//============================================
void CBullet::Draw(void)
{
	//�I�u�W�F�N�g��b�̕`�揈��
	CObjectBase::Draw();
}

//============================================
// �e�̐���
//============================================
CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife)
{
	CBullet *pBullet = nullptr;

	//�e�̃C���X�^���X�̐���
	pBullet = new CBullet;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pBullet != nullptr)
	{
		//����������
		pBullet->Init();
		//�ݒ菈��
		pBullet->SetPosition(pos);
		pBullet->SetMove(move);
		pBullet->SetLife(nLife);
		pBullet->SetSize(D3DXVECTOR3(1.5f, 1.5f, 0.0f));
	}
	else
	{
		assert(false);
	}

	return pBullet;
}

//============================================
// �e�ƓG�̓����蔻��
//============================================
void CBullet::HitEnemy(D3DXVECTOR3 pos)
{
	//�G�̑���
	int TotalEnemy = CGame::GetSpawn()->GetEnemyCount();

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		if (CSpawn::GetEnemy()[nCnt] != nullptr)
		{
			//�G�̈ʒu
			D3DXVECTOR3 EnemyPos = CSpawn::GetEnemy()[nCnt]->GetEnemyPos();
			//�G�̃T�C�Y
			D3DXVECTOR3 EnemySize = CSpawn::GetEnemy()[nCnt]->GetEnemySize();
			//�G�̗̑�
			int EnemyLife = CSpawn::GetEnemy()[nCnt]->GetLife();
			//�e�ƓG�̓����蔻��
			if (pos.x + 5.0f >= EnemyPos.x - EnemySize.x
				&&pos.x - 5.0f <= EnemyPos.x + EnemySize.x
				&&pos.y + 5.0f >= EnemyPos.y - EnemySize.y
				&&pos.y - 5.0f <= EnemyPos.y + EnemySize.y
				&&pos.z + 5.0f >= EnemyPos.z - EnemySize.z
				&&pos.z - 5.0f <= EnemyPos.z + EnemySize.z)
			{
				//�e�̍폜
				m_nLife = 0;
				SetLife(m_nLife);

				EnemyLife--;

				if (EnemyLife <= 0)
				{
					CGame::GetScore()->AddScore(200);
					CSpawn::GetEnemy()[nCnt]->Uninit();
					CSpawn::GetEnemy()[nCnt] = nullptr;
				}
				else
				{
					CSpawn::GetEnemy()[nCnt]->SetLife(EnemyLife);
				}

				TotalEnemy--;
				CGame::GetSpawn()->SetEnemyCount(TotalEnemy);
			}
		}
	}
}

//============================================
// �e�ƃM�~�b�N�̓����蔻��
//============================================
void CBullet::HitGimmick(D3DXVECTOR3 pos)
{
	for (int nCnt = 0; nCnt < MAX_GASOLENE; nCnt++)
	{
		//�M�~�b�N�̈ʒu
		D3DXVECTOR3 GasolenePos = CGame::GetGasoleneGimmick(nCnt)->GetGasolenePos();
		//�M�~�b�N�̃T�C�Y
		D3DXVECTOR3 GasoleneSize = CGame::GetGasoleneGimmick(nCnt)->GetGasoleneSize();
		//�M�~�b�N�̗̑�
		int GasoleneLife = CGame::GetGasoleneGimmick(nCnt)->GetGasoleneLife();

		//�e�ƃM�~�b�N�̓����蔻��
		if (pos.x + 5.0f >= GasolenePos.x - GasoleneSize.x
			&&pos.x - 5.0f <= GasolenePos.x + GasoleneSize.x
			&&pos.y + 5.0f >= GasolenePos.y - GasoleneSize.y
			&&pos.y - 5.0f <= GasolenePos.y + GasoleneSize.y
			&&pos.z + 5.0f >= GasolenePos.z - GasoleneSize.z
			&&pos.z - 5.0f <= GasolenePos.z + GasoleneSize.z)
		{
			//�e�̍폜
			m_nLife = 0;
			SetLife(m_nLife);

			GasoleneLife--;
			CGame::GetGasoleneGimmick(nCnt)->SetGasoleneLife(GasoleneLife);
		}
	}
}