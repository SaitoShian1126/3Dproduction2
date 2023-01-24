//============================================
// 
// 	player.cpp
// 	Author: saito shian
// 
//============================================

//============================================
// �C���N���[�h
//============================================
#include <stdio.h>
#include <assert.h>
#include "player.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "debug.h"
#include "meshfield.h"
#include "game.h"
#include "modelparts.h"
#include "keyset.h"
#include "key.h"
#include "motionset.h"
#include "bullet.h"
#include "objectX.h"
#include "billboard.h"
#include "model.h"
#include "line.h"
#include "enemy.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================
D3DXVECTOR3 CPlayer::m_pos = {};
D3DXVECTOR3 CPlayer::m_rot = {};
bool CPlayer::m_PlayerAttackFlag = false;
CBullet *CPlayer::m_pBullet = nullptr;

//============================================
// �I�u�W�F�N�g�̃R���X�g���N�^
//============================================
CPlayer::CPlayer()
{
	//============================================
	// �����o�ϐ��̃N���A
	//============================================
	m_nCountModel = 0;
	m_Frame = 0;
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
	// ============================================
	// �����o�ϐ��̏�����
	// ============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//�ʒu�̏�����
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//�����̏�����
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//�T�C�Y�̏�����
	m_rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�ړI�̌����̏�����
	m_VtxMinModel = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�ŏ��̏�����
	m_VtxMaxModel = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�ő�̏�����
	m_nCountModel = 0;											//���f���J�E���g�̏�����
	m_Frame = 0;												//�t���[�����̏�����
	m_PresentKeySet = 0;										//�O��̃L�[�Z�b�g�̏�����
	m_MotionType = MOTIONTYPE_NEUTRALMOTION;					//���[�V�����̎�ނ��j���[�g�������[�V�����ɏ�����
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)				
	{
		m_apModel[nCnt] = nullptr;								//���f�����̏�����
		m_FrameSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�t���[���X�s�[�h�̏�����
		m_RotSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//��]�X�s�[�h�̏�����
	}

	//�v���C���[�̃t�@�C���ǂݍ���
	LoadPlayer();

	//�ő�ŏ�
	Vtx();

	return S_OK;
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̏I������
//============================================
void CPlayer::Uninit(void)
{
	//���f���p�[�c�̏I������
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			m_apModel[nCnt]->Uninit();
			delete m_apModel[nCnt];
			m_apModel[nCnt] = nullptr;
		}
	}
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̍X�V����
//============================================
void CPlayer::Update(void)
{
	//���b�V���t�B�[���h�̏��
	CMeshField *pMeshField = CGame::GetMeshField();

	//�v���C���[�̈ړ������֐�
	PlayerMove();

	//�v���C���[�̍U�������֐�
	PlayerAttack();

	//���[�V�����̊֐��Ăяo��
	MotionAnimation();

	//���b�V���t�B�[���h�ƃv���C���[�̓����蔻��
	pMeshField->GetMeshFieldCollision(&m_pos);

	for (int nCnt = 0; nCnt < NUMBER_OF_MODELS; nCnt++)
	{
		//���f���Ƃ̓����蔻��
		CModelParts *pModelParts = CGame::GetModel()->GetModelParts()[nCnt];
		pModelParts->ModelCollision(&m_pos, &m_posOld, m_size);
	}

	//for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	//{
	//	//�G�Ƃ̓����蔻��
	//	CEnemy *pEnemy = CGame::GetEnemy(nCnt);
	//	pEnemy->CollisionEnemy(&m_pos, &m_posOld, m_size);
	//}
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̕`�揈��
//============================================
void CPlayer::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);											//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);			//�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);						//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);				//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���f���p�[�c��for��
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			m_apModel[nCnt]->DrawFile();
		}
	}
}

//============================================
// ����
//============================================
CPlayer * CPlayer::Create(const D3DXVECTOR3 &pos)
{
	CPlayer *pPlayer = nullptr;

	//�v���C���[�N���X�̐���
	pPlayer = new CPlayer;				// 3D�I�u�W�F�N�g�̃C���X�^���X����

	// nullptr�`�F�b�N
	if (pPlayer != nullptr)
	{
		// ����������
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
// �O���t�@�C���ǂݍ���
//============================================
void CPlayer::LoadPlayer()
{
	int nNumParts;							//���f���̃p�[�c�̕ϐ�
	int nCntMotionSet = 0;					//���[�V�����Z�b�g�̃J�E���g
	int Loop = 0;							//���[�v������̂��̕ϐ�
	int nCntKeySet = 0;						//���[�V�����Z�b�g���̃J�E���g
	int nCntKey = 0;						//�L�[�̃J�E���g
	char aText[2000];						//��������i�[����z��
	char FileName[MODEL_NUMBER][2000];		//2�����z��

	FILE *pFile; //�t�@�C���|�C���^��錾

	pFile = fopen("data/XMODEL/PlayerMotion.txt", "r");

	aText[0] = '\0';	//������Ȃ�

	if (pFile != nullptr)
	{//�t�@�C�����J�����ꍇ
	 //�t�@�C���ɓ��͂����f�[�^�������o������
		while (strncmp(&aText[0], "SCRIPT", strlen("SCRIPT")) != 0)
		{//�e�L�X�g�̍ŏ��̍s��ǂݍ��ނ܂ŌJ��Ԃ�
			fgets(aText, MAX_WORD, pFile);        //��s���Ɠǂݍ���
		}

		while (strncmp(&aText[0], "END_SCRIPT", strlen("END_SCRIPT")) != 0)
		{//�e�L�X�g�̍Ō�̍s��ǂݍ��ނ܂ŌJ��Ԃ�
			fscanf(pFile, "%s", &aText[0]);    //�t�@�C�����當�����ǂݍ���(�ǂݍ��݊J�n)

			if (strncmp(&aText[0], "#", strlen("#")) == 0)
			{
				fgets(aText, MAX_WORD, pFile);        //��s���Ɠǂݍ���
				continue;
			}

			//�t�@�C���l�[���𕡐����͂���
			if (strcmp(&aText[0], "MODEL_FILENAME") == 0)
			{
				fscanf(pFile, "%s", &aText[0]);        // = ��ǂݍ���
				fscanf(pFile, "%s", &FileName[m_nCountModel][0]);	//0�Ԗڂ���ǂݍ��܂��

				//���f���p�[�c�̐���
				m_apModel[m_nCountModel] = CModelParts::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

				m_nCountModel++;
			}

			if (strcmp(&aText[0], "CHARACTERSET") == 0)
			{
				while (strcmp(&aText[0], "END_CHARACTERSET") != 0)
				{
					fscanf(pFile, "%s", &aText[0]);

					if (strncmp(&aText[0], "#", strlen("#")) == 0)
					{
						fgets(aText, MAX_WORD, pFile);        //��s���Ɠǂݍ���
						continue;
					}

					if (strcmp(&aText[0], "NUM_PARTS") == 0)
					{
						fscanf(pFile, "%s", &aText[0]);        // = ��ǂݍ���
						fscanf(pFile, "%d", &nNumParts);
					}

					if (strcmp(&aText[0], "PARTSSET") == 0)
					{
						D3DXVECTOR3 pos, rot;
						int IndexParent = 0;	//�e�̔ԍ�
						int Ind = 0;

						while (strcmp(&aText[0], "END_PARTSSET") != 0)
						{
							fscanf(pFile, "%s", &aText[0]);

							if (strncmp(&aText[0], "#", strlen("#")) == 0)
							{
								fgets(aText, MAX_WORD, pFile);        //��s���Ɠǂݍ���
								continue;
							}

							if (strcmp(&aText[0], "INDEX") == 0)
							{
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%d", &Ind);
							}

							else if (strcmp(&aText[0], "PARENT") == 0)
							{

								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%d", &IndexParent);
							}

							else if (strcmp(&aText[0], "POS") == 0)
							{
								float x = 0.0f;
								float y = 0.0f;
								float z = 0.0f;
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%f", &x);
								fscanf(pFile, "%f", &y);
								fscanf(pFile, "%f", &z);
								pos = D3DXVECTOR3(x, y, z);
							}

							else if (strcmp(&aText[0], "ROT") == 0)
							{
								float x = 0.0f;
								float y = 0.0f;
								float z = 0.0f;
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%f", &x);
								fscanf(pFile, "%f", &y);
								fscanf(pFile, "%f", &z);
								rot = D3DXVECTOR3(x, y, z);
							}
						}

						//���f���p�[�c�̓ǂݍ���
						m_apModel[Ind]->SetModel(&FileName[Ind][0]);

						//���f���p�[�c�ɏ�񂪓����Ă�����
						if (m_apModel[Ind])
						{
							//���f���p�[�c�̌����̐ݒ�
							m_apModel[Ind]->SetRot(rot);
						}

						//�e�̔ԍ���0��艺��������
						if (IndexParent < 0)
						{
							//���f���p�[�c�̃}�g���b�N�X�̐ݒ�
							m_apModel[Ind]->SetMatrix(&m_mtxWorld);
						}
						//�e�̔ԍ������f���p�[�c��菬����������
						else if (IndexParent < MODEL_NUMBER)
						{
							//���f���p�[�c�̃}�g���b�N�X�̐ݒ�
							m_apModel[Ind]->SetMatrix(m_apModel[IndexParent]->GetMatrix());
						}
					}
				}
			}
			if (strcmp(&aText[0], "MOTIONSET") == 0)
			{//�e�L�X�g�̍ŏ��̍s��ǂݍ��ނ܂ŌJ��Ԃ�

				m_MotionSet[nCntMotionSet] = CMotionSet::Create();

				m_MotionSet[nCntMotionSet]->SetNumParts(nNumParts);

				while (strcmp(&aText[0], "END_MOTIONSET") != 0)
				{//�e�L�X�g�̍Ō�̍s��ǂݍ��ނ܂ŌJ��Ԃ�
					fscanf(pFile, "%s", &aText[0]);    //�t�@�C�����當�����ǂݍ���(�ǂݍ��݊J�n)

					if (strcmp(&aText[0], "NUM_KEY") == 0)
					{
						int numKey = 0;
						fscanf(pFile, "%s %d", &aText[0], &numKey);
						m_MotionSet[nCntMotionSet]->SetNumKey(numKey);
					}

					if (strcmp(&aText[0], "LOOP") == 0)
					{
						fscanf(pFile, "%s %d", &aText[0], &Loop);

						if (Loop == 1)
						{

							m_MotionSet[nCntMotionSet]->GetLoop();
							m_MotionSet[nCntMotionSet]->SetLoop(1);
						}

						else
						{
							m_MotionSet[nCntMotionSet]->GetLoop();
							m_MotionSet[nCntMotionSet]->SetLoop(0);
						}
					}

					if (strcmp(&aText[0], "KEYSET") == 0)
					{
						while (1)
						{
							fscanf(pFile, "%s", &aText[0]);

							if (strcmp(&aText[0], "#") == 0)
							{
								fgets(aText, MAX_WORD, pFile);        //��s���Ɠǂݍ���
								continue;
							}

							if (strcmp(&aText[0], "END_KEYSET") == 0)
							{
								nCntKeySet++;
								nCntKey = 0;
								break;
							}

							if (strcmp(&aText[0], "FRAME") == 0)
							{
								int nFrame = 0;
								fscanf(pFile, "%s %d", &aText[0], &nFrame);

								m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->SetFrame(nFrame);
							}

							else if (strcmp(&aText[0], "KEY") == 0)
							{
								while (1)
								{
									fscanf(pFile, "%s", &aText[0]);

									if (strcmp(&aText[0], "END_KEY") == 0)
									{
										nCntKey++;

										if (nCntKey >= m_MotionSet[nCntMotionSet]->GetNumParts())
										{
											nCntKey = 0;
										}
										break;
									}
									else if (strcmp(&aText[0], "POS") == 0)
									{
										float px = 0.0f;
										float py = 0.0f;
										float pz = 0.0f;
										fscanf(pFile, "%s", &aText[0]);
										fscanf(pFile, "%f", &px);
										fscanf(pFile, "%f", &py);
										fscanf(pFile, "%f", &pz);
										m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->GetKey(nCntKey)->SetPos(D3DXVECTOR3(px, py, pz));
									}

									else if (strcmp(&aText[0], "ROT") == 0)
									{
										float rx = 0.0f;
										float ry = 0.0f;
										float rz = 0.0f;
										fscanf(pFile, "%s", &aText[0]);
										fscanf(pFile, "%f", &rx);
										fscanf(pFile, "%f", &ry);
										fscanf(pFile, "%f", &rz);
										m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->GetKey(nCntKey)->SetRot(D3DXVECTOR3(rx, ry, rz));
									}
								}
							}
						}
					}
				}

				//���[�V�����Z�b�g���C���N�������g
				nCntMotionSet++;
				//���[�V�����Z�b�g���̏�����
				nCntKeySet = 0;
				//�L�[�J�E���g�̏�����
				nCntKey = 0;
			}
		}
	}

	//�t�@�C�������
	fclose(pFile);

	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		//null�`�F�b�N
		if (m_apModel[nCnt] != nullptr)
		{
			//pos��rot�̕ϐ��錾
			D3DXVECTOR3 pos, rot;

			//���ݎg���Ă��郂�[�V�����̈ʒu����pos�ɑ��
			pos = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetPos();

			//���ݎg���Ă��郂�[�V�����̌�������rot�ɑ��
			rot = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetRot();

			//���f���̈ʒu�ƌ����̐ݒ�
			m_apModel[nCnt]->SetPos(pos);
			m_apModel[nCnt]->SetRot(rot);
		}
	}
}

//============================================
// ���_�̍ő�ŏ�
//============================================
void CPlayer::Vtx(void)
{
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		int nNumVtx;	//���_��
		DWORD sizeFVF;	//���_�t�H�[�}�b�g�̃T�C�Y
		BYTE *pVtxBuff;	//���_�o�b�t�@�ւ̃|�C���^

		//���_���̎擾
		nNumVtx = m_apModel[nCnt]->GetMesh()->GetNumVertices();

		//���_�t�H�[�}�b�g�̃T�C�Y���擾
		sizeFVF = D3DXGetFVFVertexSize(m_apModel[nCnt]->GetMesh()->GetFVF());

		//���_�o�b�t�@�̃��b�N
		m_apModel[nCnt]->GetMesh()->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

		D3DXVECTOR3 min = D3DXVECTOR3(100000.0f, 100000.0f, 100000.0f);
		D3DXVECTOR3 max = D3DXVECTOR3(-100000.0f, -100000.0f, -100000.0f);

		for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
		{
			//���_���W�̑��
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

			//���_���W���r���ă��f���̍ŏ��l�A�ő�l���擾
			//x�̔�r
			if (vtx.x < min.x)
			{
				min.x = vtx.x;
			}
			if (vtx.x > max.x)
			{
				max.x = vtx.x;
			}

			//y�̔�r(�ŏ��l)
			if (vtx.y < min.y)
			{
				min.y = vtx.y;
			}
			if (vtx.y > max.y)
			{
				max.y = vtx.y;
			}

			//z�̔�r(�ŏ��l)
			if (vtx.z < min.z)
			{
				min.z = vtx.z;
			}
			if (vtx.z > max.z)
			{
				max.z = vtx.z;
			}
			//���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
			pVtxBuff += sizeFVF;
		}

		//���_�o�b�t�@�̃A�����b�N
		m_apModel[nCnt]->GetMesh()->UnlockVertexBuffer();

		m_apModel[nCnt]->SetVtxMin(min);
		m_apModel[nCnt]->SetVtxMax(max);

		//�v���C���[�T�C�Y
		m_size = D3DXVECTOR3(max.x - min.x, 0.0f, max.z - min.z);
	}
}

//============================================
// ���[�V�����֐�
//============================================
void CPlayer::MotionAnimation(void)
{
	m_Frame++;		//�t���[���̃C���N�������g

	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		D3DXVECTOR3 pos = m_apModel[nCnt]->GetPos();		//���f���p�[�c�̈ʒu�擾
		D3DXVECTOR3 rot = m_apModel[nCnt]->GetRot();		//���f���p�[�c�̌����擾
		pos += m_FrameSpeed[nCnt];							//���f���p�[�c�̈ʒu�Ƀt���[���̑�������
		rot += m_RotSpeed[nCnt];							//���f���p�[�c�̌����Ɍ����̑�������
		m_apModel[nCnt]->SetPos(pos);						//�ʒu�̐ݒ�
		m_apModel[nCnt]->SetRot(rot);						//�����̐ݒ�
	}

	if (m_Frame >= m_MotionSet[m_MotionType]->GetKeySet(m_PresentKeySet)->GetFrame())
	{	//���݂̃A�j���[�V�����̃t���[�����ȏゾ������

		int NextKeySet = 0;					//���̃L�[�Z�b�g�ϐ�
		NextKeySet = m_PresentKeySet + 1;	//���̃L�[�Z�b�g����

		if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 1)
		{	//�Đ����̃L�[���J�E���g���L�[���̍ő�l�𒴂����Ƃ��A���̃��[�V���������[�v���g�p���Ă���
			
			NextKeySet = 0;					//�Đ����̃L�[���J�E���g��������
			m_PresentKeySet = NextKeySet;	//���̃A�j���[�V�����̍ŏ��̃��[�V�����Z�b�g��ݒ肷��
		}
		else if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 0)
		{	//�Đ����̃L�[���J�E���g���L�[���̍ő�l�𒴂����Ƃ�

			m_MotionSet[m_MotionType]->SetLoop(false);		//���[�v��false�ɐݒ肷��	
			m_MotionType = MOTIONTYPE_NEUTRALMOTION;		//���[�V�������j���[�g�������[�V�����ɂ���
			NextKeySet = 0;									//���̃L�[�Z�b�g�̏�����
		}

		for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
		{
			//���x�̌v�Z
			m_FrameSpeed[nCnt] = (m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetKey(nCnt)->GetPos() - m_apModel[nCnt]->GetPos());
			m_FrameSpeed[nCnt].x /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_FrameSpeed[nCnt].y /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_FrameSpeed[nCnt].z /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			//��]�̌v�Z
			m_RotSpeed[nCnt] = (m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetKey(nCnt)->GetRot() - m_apModel[nCnt]->GetRot());
			m_RotSpeed[nCnt].x /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_RotSpeed[nCnt].y /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_RotSpeed[nCnt].z /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
		}

		m_Frame = 0;						//�t���[���̏�����
		m_PresentKeySet = NextKeySet;		//���݂̃��[�V�����Ɏ��̃��[�V��������
	}
}

//============================================
// �v���C���[�̈ړ�����
//============================================
void CPlayer::PlayerMove(void)
{
	// �C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	D3DXVECTOR3 CameraRot = CCamera::GetCameraRot();
	D3DXVECTOR3 PlayerRot = GetRot();

	//�O��̈ʒu��ۑ�
	m_posOld = m_pos;

	if (m_PlayerAttackFlag == false)
	{
		// �����
		if (pInput->GetKeyboardPress(DIK_W) == true)
		{// W�L�[�������ꂽ
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// �ړ���
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					// �����p�x
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// �ړ���
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					// �����p�x
			}
			else
			{
				m_pos.x += sinf(CameraRot.y) * PLAYER_MOVE;						// �ړ���
				m_pos.z += cosf(CameraRot.y) * PLAYER_MOVE;						// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI);							// �����p�x
			}

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// ������
		else if (pInput->GetKeyboardPress(DIK_S) == true)
		{// S�L�[�������ꂽ
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// �ړ���
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);					// �����p�x
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// �ړ���
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);					// �����p�x
			}
			else
			{
				m_pos.x -= sinf(CameraRot.y) * PLAYER_MOVE;						// �ړ���
				m_pos.z -= cosf(CameraRot.y) * PLAYER_MOVE;						// �ړ���
				m_rotDest.y = CameraRot.y;										// �����p�x
			}

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// ������
		else if (pInput->GetKeyboardPress(DIK_A) == true)
		{// A�L�[�������ꂽ
			m_pos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// �ړ���
			m_pos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// �ړ���
			m_rotDest.y = (CameraRot.y + D3DX_PI / 2);							// �����p�x

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// �E����
		else if (pInput->GetKeyboardPress(DIK_D) == true)
		{// D�L�[�������ꂽ
			m_pos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// �ړ���
			m_pos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// �ړ���
			m_rotDest.y = (CameraRot.y - D3DX_PI / 2);							// �����p�x

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
	}
	else if (m_PlayerAttackFlag == true)
	{
		// �����
		if (pInput->GetKeyboardPress(DIK_W) == true)
		{// W�L�[�������ꂽ
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// �ړ���
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					// �����p�x
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// �ړ���
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					// �����p�x
			}
			else
			{
				m_pos.x += sinf(CameraRot.y) * PLAYER__ADS_MOVE;						// �ړ���
				m_pos.z += cosf(CameraRot.y) * PLAYER__ADS_MOVE;						// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI);							// �����p�x
			}

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// ������
		else if (pInput->GetKeyboardPress(DIK_S) == true)
		{// S�L�[�������ꂽ
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// �ړ���
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);					// �����p�x
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// �ړ���
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// �ړ���
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);					// �����p�x
			}
			else
			{
				m_pos.x -= sinf(CameraRot.y) * PLAYER__ADS_MOVE;						// �ړ���
				m_pos.z -= cosf(CameraRot.y) * PLAYER__ADS_MOVE;						// �ړ���
				m_rotDest.y = CameraRot.y;										// �����p�x
			}

			//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// ������
		else if (pInput->GetKeyboardPress(DIK_A) == true)
		{// A�L�[�������ꂽ
			m_pos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// �ړ���
			m_pos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// �ړ���
			m_rotDest.y = (CameraRot.y + D3DX_PI / 2);							// �����p�x

																				//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// �E����
		else if (pInput->GetKeyboardPress(DIK_D) == true)
		{// D�L�[�������ꂽ
			m_pos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// �ړ���
			m_pos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// �ړ���
			m_rotDest.y = (CameraRot.y - D3DX_PI / 2);							// �����p�x

																				//�ړ����[�V�����̐ݒ�
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
	}

	//============================================
	//	���[�V�����̐ݒ�
	//============================================
	if (pInput->GetKeyboardPress(DIK_W) == false && pInput->GetKeyboardPress(DIK_A) == false
		&& pInput->GetKeyboardPress(DIK_S) == false && pInput->GetKeyboardPress(DIK_D) == false
		&& pInput->GetKeyboardPress(DIK_LSHIFT) == false)
	{
		//�j���[�g�������[�V�����̐ݒ�
		SetMotionType(CPlayer::MOTIONTYPE_NEUTRALMOTION);
	}

	//============================================
	//  �ړI�̊p�x�̐��K��
	//============================================
	if (m_rotDest.y - PlayerRot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - PlayerRot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	if (pInput->GetKeyboardPress(DIK_LSHIFT) == false)
	{
		// �p�x����
		PlayerRot += (m_rotDest - PlayerRot) * 0.1f;
	}

	//============================================
	//  �p�x�̐��K��
	//============================================
	if (PlayerRot.y > D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y - D3DX_PI * 2;
	}
	else if (PlayerRot.y < -D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y + D3DX_PI * 2;
	}
	//�����̐ݒ�
	m_rot = PlayerRot;
	//�f�o�b�N�\��
	CDebugProc::Print("�v���C���[�̌����Ă�p�x:%f\n�v���C���[�̍���:%.2f\n�v���C���[��X�ʒu:%f\n�v���C���[��Z�ʒu:%f\n", PlayerRot.y, m_pos.y, m_pos.x, m_pos.z);
}

//============================================
// �v���C���[�̍U������
//============================================
void CPlayer::PlayerAttack(void)
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	//�v���C���[�̈ʒu�擾
	D3DXVECTOR3 PlayerPos = GetPos();
	//�J�����̌����̎擾
	D3DXVECTOR3 CameraRot = CApplication::GetCamera()->GetCameraRot();

	//============================================
	//	�v���C���[�̍U������
	//============================================
	//space�L�[�������ꂽ
	if (pInput->GetKeyboardPress(DIK_LSHIFT) == true)
	{
		//�v���C���[���U���Ԑ��ɓ�����
		m_PlayerAttackFlag = true;

		//�G�C���������̃J�����̈ʒu�̐ݒ�
		CApplication::GetCamera()->SetOffset(D3DXVECTOR3(-20.0f, 45.0f, 40.0f), D3DXVECTOR3(0.0f, 0.0f, -100.0f));

		//============================================
		//	�U������
		//============================================
		if (pInput->GetKeyboardTrigger(DIK_RETURN) == true)
		{	//LSHIFT���������Ă���Ƃ� && ENTER���������Ƃ�

			//�U�����[�V�����ɐݒ�
			SetMotionType(MOTIONTYPE_ATTACK);

			//�e�̐���
			m_pBullet = CBullet::Create(D3DXVECTOR3(m_pos.x, 32.0f, m_pos.z), D3DXVECTOR3(-sinf(m_rot.y) * 15.0f, sinf(m_rot.x) * 15.0f, -cosf(m_rot.y) * 15.0f), 20);
		}

		//============================================
		//	�G�C���̌�����ς��鏈��
		//============================================
		if (pInput->GetKeyboardPress(DIK_UP) == true)
		{	//UP�L�[�������Ă���Ƃ�

			m_rot.x += 0.01f;			//�v���C���[�̏�����̉��Z
			CameraRot.x += 0.01f;		//�J�����̏�����̉��Z

			if (CameraRot.x >= 0.3f)
			{	//�J������������͈�

				CameraRot.x = 0.3f;		//�J�����̌Œ�
			}
		}
		if (pInput->GetKeyboardPress(DIK_DOWN) == true)
		{	//DOWN�L�[�������Ă���Ƃ�

			m_rot.x -= 0.01f;			//�v���C���[�̉������̉��Z
			CameraRot.x -= 0.01f;		//�J�����̉������̉��Z

			if (CameraRot.x <= -0.3f)
			{	//�J������������͈�

				CameraRot.x = -0.3f;	//�J�����̌Œ�
			}
		}
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{	//LEFT�L�[�������Ă���Ƃ�

			m_rot.y -= 0.01f;			//�v���C���[�̍������̉��Z
			CameraRot.y -= 0.01f;		//�J�����̍������̉��Z
		}	
		if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{	//RIGHT�L�[�������Ă���Ƃ�

			m_rot.y += 0.01f;			//�v���C���[�̉E�����̉��Z
			CameraRot.y += 0.01f;		//�J�����̉E�����̉��Z
		}

		//============================================
		//  �p�x�̐��K��
		//============================================
		if (CameraRot.y > D3DX_PI)
		{
			CameraRot.y = CameraRot.y - D3DX_PI * 2;
		}
		else if (CameraRot.y < -D3DX_PI)
		{
			CameraRot.y = CameraRot.y + D3DX_PI * 2;
		}

		//�v���C���[�̌����̕ۑ�
		SetRot(m_rot);

		//�U���ҋ@���[�V�����ɐݒ�
		SetMotionType(MOTIONTYPE_STANDBYATTACK);
	}
	//LSHIFT�����Ă��Ȃ��Ƃ� && �v���C���[���U���Ԑ��ɂȂ��Ă���Ƃ�
	else if (pInput->GetKeyboardPress(DIK_LSHIFT) == false && m_PlayerAttackFlag == true)
	{
		//�v���C���[���U���̐�����߂�
		m_PlayerAttackFlag = false;
		//�v���C���[�̌����̎擾
		m_rot = GetRot();
		//�v���C���[�̌����̐ݒ�
		SetRot(m_rot);
		//�J�����̌����̐ݒ�
		CApplication::GetCamera()->SetOffset(D3DXVECTOR3(0.0f, 75.0f, 150.0f),D3DXVECTOR3(0.0f, 0.0f, -100.0f));
	}

	//�J�����̌����̐ݒ�
	CApplication::GetCamera()->SetRot(CameraRot);
}

//============================================
// �v���C���[�̓����蔻��
//============================================
void CPlayer::CollisionPlayer(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size)
{
	//���̓����蔻��
	if (pPos->z - size.z / 2.0f < m_pos.z + m_VtxMaxModel.z
		&& pPos->z + size.z / 2.0f > m_pos.z + m_VtxMinModel.z
		&&pPosOld->x <= m_pos.x + m_VtxMinModel.x - size.x / 2.0f
		&&pPos->x > m_pos.x + m_VtxMinModel.x - size.x / 2.0f)
	{
		pPos->x = m_pos.x + m_VtxMinModel.x - size.x / 2.0f;
	}

	//�E�̓����蔻��
	if (pPos->z - size.z / 2.0f < m_pos.z + m_VtxMaxModel.z
		&& pPos->z + size.z / 2.0f > m_pos.z + m_VtxMinModel.z
		&&pPosOld->x >= m_pos.x + m_VtxMaxModel.x + size.x / 2.0f
		&&pPos->x < m_pos.x + m_VtxMaxModel.x + size.x / 2.0f)
	{
		pPos->x = m_pos.x + m_VtxMaxModel.x + size.x / 2.0f;
	}

	//��O�̓����蔻��
	if (pPos->x - size.x / 2.0f < m_pos.x + m_VtxMaxModel.x
		&& pPos->x + size.x / 2.0f > m_pos.x + m_VtxMinModel.x
		&&pPosOld->z <= m_pos.z + m_VtxMinModel.z - size.z / 2.0f
		&&pPos->z > m_pos.z + m_VtxMinModel.z - size.z / 2.0f)
	{
		pPos->z = m_pos.z + m_VtxMinModel.z - size.z / 2.0f;
	}

	//���̓����蔻��
	if (pPos->x - size.x / 2.0f < m_pos.x + m_VtxMaxModel.x
		&& pPos->x + size.x / 2.0f > m_pos.x + m_VtxMinModel.x
		&&pPosOld->z >= m_pos.z + m_VtxMaxModel.z + size.z / 2.0f
		&&pPos->z < m_pos.z + m_VtxMaxModel.z + size.z / 2.0f)
	{
		pPos->z = m_pos.z + m_VtxMinModel.z + size.z / 2.0f;
	}
}

//============================================
// ���[�V�����̎�ނ̐ݒ�
//============================================
void CPlayer::SetMotionType(MOTIONTYPE type)
{
	m_MotionType = type;
}

//============================================
// �ʒu�̐ݒ�
//============================================
void CPlayer::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//============================================
// �����̐ݒ�
//============================================
void CPlayer::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//============================================
// �ړ��̐ݒ�
//============================================
void CPlayer::SetMove(D3DXVECTOR3 move)
{
	move;
}

//============================================
// �����̐ݒ�
//============================================
void CPlayer::SetLength(float length)
{
	length;
}

//============================================
// �ʒu�̎擾
//============================================
D3DXVECTOR3 CPlayer::GetPos(void)
{
	return m_pos;
}

//============================================
// �ړ��̎擾
//============================================
D3DXVECTOR3 CPlayer::GetMove(void)
{
	return D3DXVECTOR3();
}

//============================================
// �T�C�Y�̎擾
//============================================
D3DXVECTOR3 CPlayer::GetSize(void)
{
	return D3DXVECTOR3();
}

//============================================
// �����̎擾
//============================================
D3DXVECTOR3 CPlayer::GetRot(void)
{
	return m_rot;
}

//============================================
// �����̎擾
//============================================
float CPlayer::GetLength(void)
{
	return 0.0f;
}