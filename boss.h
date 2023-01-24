//============================================
//
//	boss.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _BOSS_H_
#define _BOSS_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "object.h"

//============================================
// �}�N����`
//============================================
#define BOSS_MOVE			(1.0f)		//�{�X�̈ړ�
#define MAX_BOSS_WORD		(512)		//���[�h��
#define MODEL_BOSS_PARTS	(15)		//���f���̃p�[�c��
#define MOTION_BOSS_NUMBER	(2)			//���[�V������

//============================================
// �O���錾
//============================================
class CShadow;
class CModelParts;
class CMotionSet;
class CKeySet;
class CKey;

//============================================
// �{�X�N���X
//============================================
class CBoss : public CObject
{
public:
	//============================================
	// ���[�V�����̎��
	//============================================
	enum MOTIONTYPE
	{
		MOTIONTYPE_NEUTRALMOTION = 0,				//�j���[�g�������[�V����
		MOTIONTYPE_MOVE,							//�ړ����[�V����
		MOTIONTYPE_MAX
	};

	CBoss();										//�R���X�g���N�^
	~CBoss()override;								//�f�X�g���N�^

	HRESULT Init(void)override;						//�{�X�̏���������
	void Uninit(void)override;						//�{�X�̏I������
	void Update(void)override;						//�{�X�̍X�V����
	void Draw(void)override;						//�{�X�̕`�揈��

	void LoadBoss();								//�{�X�̓ǂݍ���

	static D3DXVECTOR3 GetBossPos(void) { return m_pos; }		//�{�X�̈ʒu�擾
	static D3DXVECTOR3 GetBossSize(void) { return m_size; }		//�{�X�̃T�C�Y�擾
	static D3DXVECTOR3 GetBossRot(void) { return m_rot; }		//�{�X�̌����̎擾
	static CBoss *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move);				//����

	void SetPosition(D3DXVECTOR3 pos);		//�{�X�̈ʒu����
	void SetRot(D3DXVECTOR3 rot);			//�{�X�̉�]����
	void SetMove(D3DXVECTOR3 move);			//�{�X�̈ړ�����
	void SetLength(float length);			//�����̐ݒ菈��
	void SetLife(int life);					//�̗͂̐ݒ菈��
	void SetMotionType(MOTIONTYPE type);	//���[�V�����̎�ނ̐ݒ菈��

	D3DXVECTOR3 GetPos(void);				//�ʒu�̎擾����
	D3DXVECTOR3 GetMove(void);				//�ړ��ʂ̎擾
	D3DXVECTOR3 GetSize(void);				//�T�C�Y�̎擾����
	D3DXVECTOR3 GetRot(void);				//��]�̎擾
	float GetLength(void);					//�g��k���̃X�P�[���̎擾
	int GetLife(void);						//�̗͂̎擾����

private:
	//============================================
	// �v���C�x�[�g�֐�
	//============================================
	void MotionBossAnimation(void);					//���[�V�����֐�

	static D3DXVECTOR3 m_pos;						//�ʒu
	static D3DXVECTOR3 m_rot;						//����
	static D3DXVECTOR3 m_size;						//�T�C�Y
	CModelParts *m_apModel[MODEL_BOSS_PARTS];		//���f���p�[�c
	CMotionSet *m_MotionSet[MOTION_BOSS_NUMBER];	//���[�V�����Z�b�g
	CKeySet *m_KeySet;								//�L�[�Z�b�g
	CKey *m_Key;									//�L�[
	D3DXVECTOR3 m_posOld;							//�ړI�̈ʒu
	D3DXVECTOR3 m_rotDest;							//�ړI�̌���
	D3DXVECTOR3 m_FrameSpeed[MODEL_BOSS_PARTS];		//�t���[���̑���
	D3DXVECTOR3 m_RotSpeed[MODEL_BOSS_PARTS];		//��]�̑���
	D3DXVECTOR3 m_move;								//�ړ�
	D3DXMATRIX m_mtxWorld;							//���[���h�}�g���b�N�X
	D3DXMATRIX *m_pmtxParent;						//�e�̃}�g���b�N�X
	CShadow *m_pShadow;								//�e

	MOTIONTYPE m_MotionType;						//���[�V�����̎��

	int m_Frame;									//�t���[��
	int m_PresentKeySet;							//���݂̃L�[�Z�b�g
	int m_nLife;									//�̗�
	int m_nCountModel;								//���f�����̃J�E���g
	float m_PlayerHeightPos;						//�{�X�̍����̈ʒu
	float m_Length;									//����
	float m_Angle;									//�p�x
};

#endif
