//============================================
//
//	bullet.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _BULLET_H_
#define _BULLET_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "objectBase.h"

//============================================
// �O���錾
//============================================
class CEnemy;
class CFade;

//============================================
// �e�N���X
//============================================
class CBullet : public CObjectBase
{
public:
	CBullet();									//�R���X�g���N�^
	~CBullet()override;							//�f�X�g���N�^

	HRESULT Init(void)override;						//�e�̏���������
	void Uninit(void)override;						//�e�̏I������
	void Update(void)override;						//�e�̍X�V����
	void Draw(void)override;						//�e�̕`�揈��

	void SetLife(int life) { m_nLife = life; }		//�e�̃��C�t�̐ݒ菈��
	void SetBulletPos(D3DXVECTOR3 pos) { m_BulletPos = pos; }
	void SetGimmickUninitFlag(bool flag) { m_GimmickUninitFlag = flag; }

	D3DXVECTOR3 GetBulletPos(void) { return m_BulletPos;}
	int GetBulletLife(void) { return m_nLife; }

	void HitEnemy(D3DXVECTOR3 pos);		//�e�ƓG�̓����蔻��
	void HitGimmick(D3DXVECTOR3 pos);	//�e�ƃM�~�b�N�̓����蔻��

	static CBullet *Create(D3DXVECTOR3 pos,D3DXVECTOR3 move, int nLife);		//����

private:
	D3DXVECTOR3 m_BulletPos;						//�ʒu
	D3DXVECTOR3 m_BulletRot;						//����
	D3DXVECTOR3	m_BulletMove;						//�ړ�
	CEnemy *m_pEnemy;								//�G�̃C���X�^���X
	CFade *m_pFade;									//�t�F�[�h�̃C���X�^���X

	int m_nLife;									//�̗�
	bool m_EnemyDeathFlag;							//�G�����񂾂̂��t���O
	bool m_GimmickUninitFlag;						//�M�~�b�N���������̂��t���O
	bool m_BulletMoveFlag;							//�e�����e�B�N���̕����֌������Ă����t���O
};

#endif

