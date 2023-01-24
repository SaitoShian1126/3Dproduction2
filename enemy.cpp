//============================================
// 
// 	enemy.cpp
// 	Author: saito shian
// 
//============================================

//============================================
// �C���N���[�h
//============================================
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "enemy.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "shadow.h"
#include "debug.h"
#include "meshfield.h"
#include "game.h"
#include "modelparts.h"
#include "keyset.h"
#include "key.h"
#include "motionset.h"
#include "score.h"
#include "player.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================

//============================================
// �I�u�W�F�N�g�̃R���X�g���N�^
//============================================
CEnemy::CEnemy()
{
	//============================================
	// �����o�ϐ��̃N���A
	//============================================
	m_nCountModel = 0;
	m_nLife = 0;
}

//============================================
// �I�u�W�F�N�g�̃f�X�g���N�^
//============================================
CEnemy::~CEnemy()
{
	// ���������Ȃ�
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̏���������
//============================================
HRESULT CEnemy::Init(void)
{
	//============================================
	// ����
	//============================================
	srand((unsigned int)time(nullptr));							//�N�����Ɉ�񂾂��s�����ߏ������ɏ���	

	//============================================
	// �����o�ϐ��̏�����
	//============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(10.0f, 50.0f, 10.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nCountModel = 0;
	m_PresentKeySet = 0;
	m_Frame = 0;
	m_nLife = 1;
	m_EnemyNumber = 0;
	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
	{
		m_apModel[nCnt] = nullptr;								//���f�����̏�����
		m_FrameSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�t���[���X�s�[�h�̏�����
		m_RotSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//��]�X�s�[�h�̏�����
	}

	//�v���C���[�̃t�@�C���ǂݍ���
	LoadEnemy();

	//�ő�ŏ�
	//Vtx();

	m_pShadow = CShadow::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// �e�̐ݒ菈���̏�����

	return S_OK;
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̏I������
//============================================
void CEnemy::Uninit(void)
{
	//���f���p�[�c�̏I������
	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			m_apModel[nCnt]->Uninit();
			delete m_apModel[nCnt];
			m_apModel[nCnt] = nullptr;
		}
	}

	//�j������
	Release();
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̍X�V����
//============================================
void CEnemy::Update(void)
{
	CMeshField *pMeshField = CGame::GetMeshField();
	D3DXVECTOR3 CameraRot = CCamera::GetCameraRot();

	//�G�̈ړ�����
	EnemyMove();

	//���b�V���t�B�[���h�ƓG�̓����蔻��
	pMeshField->GetMeshFieldCollision(&m_pos);
	////�v���C���[�Ƃ̓����蔻��
	//CPlayer *pPlayer = CGame::GetPlayer();
	//pPlayer->CollisionPlayer(&m_pos, &m_posOld, m_size);
	//�����̐ݒ�
	SetRot(m_rot);
	//�ړ��̐ݒ�
	SetMove(m_move);
	//�ʒu�̐ݒ�
	SetPosition(m_pos);
}

//============================================
// �I�u�W�F�N�g(�|���S��)�̕`�揈��
//============================================
void CEnemy::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�}�g���b�N�X

	//���[�J���}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);											//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);			//�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);						//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);				//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���f���p�[�c��for��
	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
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
CEnemy * CEnemy::Create(const D3DXVECTOR3 pos,int enemynum)
{
	CEnemy *pEnemy = nullptr;

	// 3D�I�u�W�F�N�g�N���X�̐���
	pEnemy = new CEnemy;				// 3D�I�u�W�F�N�g�̃C���X�^���X����

	// nullptr�`�F�b�N
	if (pEnemy != nullptr)
	{
		// ����������
		pEnemy->Init();
		pEnemy->SetPosition(pos);
		pEnemy->SeteEnemyNum(enemynum);
	}
	else
	{
		assert(false);
	}
	return pEnemy;
}

//============================================
// �O���t�@�C���ǂݍ���
//============================================
void CEnemy::LoadEnemy()
{
	int nNumParts;
	int nCntMotionSet = 0;
	int Loop = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	char aText[2000];							//��������i�[����z��
	char FileName[MODEL_ENEMY_PARTS][2000];		//2�����z��

	FILE *pFile; //�t�@�C���|�C���^��錾

	pFile = fopen("data/XMODEL/EnemyMotion.txt", "r");

	aText[0] = '\0';	//������Ȃ�

	if (pFile != nullptr)
	{//�t�@�C�����J�����ꍇ
	 //�t�@�C���ɓ��͂����f�[�^�������o������
		while (strncmp(&aText[0], "SCRIPT", strlen("SCRIPT")) != 0)
		{//�e�L�X�g�̍ŏ��̍s��ǂݍ��ނ܂ŌJ��Ԃ�
			fgets(aText, MAX_ENEMY_WORD, pFile);        //��s���Ɠǂݍ���
		}

		while (strncmp(&aText[0], "END_SCRIPT", strlen("END_SCRIPT")) != 0)
		{//�e�L�X�g�̍Ō�̍s��ǂݍ��ނ܂ŌJ��Ԃ�
			fscanf(pFile, "%s", &aText[0]);    //�t�@�C�����當�����ǂݍ���(�ǂݍ��݊J�n)

			if (strncmp(&aText[0], "#", strlen("#")) == 0)
			{
				fgets(aText, MAX_ENEMY_WORD, pFile);        //��s���Ɠǂݍ���
				continue;
			}

			//�t�@�C���l�[���𕡐����͂���
			if (strcmp(&aText[0], "MODEL_FILENAME") == 0)
			{
				fscanf(pFile, "%s", &aText[0]);        // = ��ǂݍ���
				fscanf(pFile, "%s", &FileName[m_nCountModel][0]);	//0�Ԗڂ���ǂݍ��܂��

				//���f���p�[�c�̐���
				m_apModel[m_nCountModel]->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

				m_nCountModel++;
			}

			if (strcmp(&aText[0], "CHARACTERSET") == 0)
			{
				while (strcmp(&aText[0], "END_CHARACTERSET") != 0)
				{
					fscanf(pFile, "%s", &aText[0]);

					if (strncmp(&aText[0], "#", strlen("#")) == 0)
					{
						fgets(aText, MAX_ENEMY_WORD, pFile);        //��s���Ɠǂݍ���
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
								fgets(aText, MAX_ENEMY_WORD, pFile);        //��s���Ɠǂݍ���
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

						//���f���p�[�c�̐���
						m_apModel[Ind] = CModelParts::Create(pos,rot);

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
						else if (IndexParent < MODEL_ENEMY_PARTS)
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
								fgets(aText, MAX_ENEMY_WORD, pFile);        //��s���Ɠǂݍ���
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

				nCntMotionSet++;
				nCntKeySet = 0;
				nCntKey = 0;
			}
		}
	}
	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			D3DXVECTOR3 pos, rot;
			pos = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetPos();
			rot = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetRot();
			m_apModel[nCnt]->SetPos(pos);
			m_apModel[nCnt]->SetRot(rot);
		}
	}
}

//============================================
// ���[�V�����֐�
//============================================
void CEnemy::MotionEnemyAnimation(void)
{
	m_Frame++;		//�t���[���̃C���N�������g

	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
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

		}
		else if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 0)
		{	//�Đ����̃L�[���J�E���g���L�[���̍ő�l�𒴂����Ƃ�

			m_MotionSet[m_MotionType]->SetLoop(false);		//���[�v��false�ɐݒ肷��	
			NextKeySet = 0;											//���̃L�[�Z�b�g�̏�����
		}

		for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
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
		m_PresentKeySet = NextKeySet;
	}
}


//============================================
// ���_�̍ő�ŏ�
//============================================
void CEnemy::Vtx(void)
{
	for (int nCnt = 0; nCnt < MODEL_ENEMY_PARTS; nCnt++)
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
// �v���C���[�̓����蔻��
//============================================
void CEnemy::CollisionEnemy(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size)
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
// �G�̈ړ�����
//============================================
void CEnemy::EnemyMove()
{
	D3DXVECTOR3 ShadowPos = m_pShadow->GetPos();
	D3DXVECTOR3 PlayerRot = GetRot();

	//�e��y���W
	ShadowPos.y = 0.8f;

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

	// �p�x����
	PlayerRot.y += (m_rotDest.y - PlayerRot.y) * 0.1f;

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

	//���[�V�����֐�
	MotionEnemyAnimation();

	//============================================
	//  �v���C���[��Ǐ]���鏈��
	//============================================
	D3DXVECTOR3 PlayerPos = CPlayer::GetPlayerPos();
	m_move = m_pos - PlayerPos;				//�v���C���[�̈ʒu�ƓG�̈ʒu���v�Z���Ĉړ��ɑ��
	D3DXVec3Normalize(&m_move, &m_move);	//�ړ��̐��K��
	D3DXVec3Normalize(&m_rot, &m_rot);		//�ړ��̐��K��
	m_move *= 3.0f;							//�ړ��X�s�[�h

											//����
	m_Angle = atan2f(PlayerPos.x, PlayerPos.z) + D3DX_PI;
	m_rot = D3DXVECTOR3(0.0f, m_Angle, 0.0f);

	//����
	m_rot.y += (m_rotDest.y - m_rot.y) * 0.1f;

	//======================
	//�ړI�̕����̐��K��
	//======================
	if (m_rotDest.y - m_rot.y > D3DX_PI)
	{
		m_rotDest.y -= D3DX_PI * 2;
	}

	else if (m_rotDest.y - m_rot.y < -D3DX_PI)
	{
		m_rotDest.y += D3DX_PI * 2;
	}

	//======================
	//���K��
	//======================
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}

	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}

	//�ړ����[�V�����ɐݒ�
	SetMotionType(CEnemy::MOTIONTYPE_MOVE);

	if (PlayerPos.x + 25.0f >= m_pos.x && PlayerPos.x - 25.0f <= m_pos.x
		&&PlayerPos.z + 25.0f >= m_pos.z && PlayerPos.z - 25.0f <= m_pos.z)
	{	//�G���v���C���[���U������͈�

		m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		SetMove(m_move);
		//�j���[�g�������[�V�����ɐݒ�
		SetMotionType(CEnemy::MOTIONTYPE_NEUTRALMOTION);
	}

	//�ړ��ʌ���
	m_pos.x += (0.0f - m_move.x) * 0.1f;
	m_pos.y += (0.0f - m_move.y) * 0.1f;
	m_pos.z += (0.0f - m_move.z) * 0.1f;

	//�e�̐ݒ�
	m_pShadow->SetPosition(ShadowPos);
}

//============================================
// ���[�V�����̎�ނ̐ݒ�
//============================================
void CEnemy::SetMotionType(MOTIONTYPE type)
{
	m_MotionType = type;
}

//============================================
// �G�̔ԍ��̐ݒ菈��
//============================================
void CEnemy::SeteEnemyNum(int num)
{
	m_EnemyNumber = num;
}

//============================================
// �ʒu�̐ݒ�
//============================================
void CEnemy::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//============================================
// �����̐ݒ�
//============================================
void CEnemy::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//============================================
// �ړ��̐ݒ�
//============================================
void CEnemy::SetMove(D3DXVECTOR3 move)
{
	move;
}

//============================================
// �����̐ݒ�
//============================================
void CEnemy::SetLength(float length)
{
	length;
}

//============================================
// �̗͂̐ݒ�
//============================================
void CEnemy::SetLife(int life)
{
	m_nLife = life;
}

//============================================
// �ʒu�̎擾
//============================================
D3DXVECTOR3 CEnemy::GetPos(void)
{
	return m_pos;
}

//============================================
// �ړ��̎擾
//============================================
D3DXVECTOR3 CEnemy::GetMove(void)
{
	return D3DXVECTOR3();
}

//============================================
// �T�C�Y�̎擾
//============================================
D3DXVECTOR3 CEnemy::GetSize(void)
{
	return m_size;
}

//============================================
// �����̎擾
//============================================
D3DXVECTOR3 CEnemy::GetRot(void)
{
	return m_rot;
}

//============================================
// �����̎擾
//============================================
float CEnemy::GetLength(void)
{
	return 0.0f;
}

//============================================
// �̗͂̎擾
//============================================
int CEnemy::GetLife(void)
{
	return m_nLife;
}

//============================================
// �G�̔ԍ��̎擾����
//============================================
int CEnemy::GetEnemyNum(void)
{
	return m_EnemyNumber;
}


