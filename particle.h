//============================================
//
//	particle.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "objectbase.h"

//============================================
// �O���錾
//============================================

//============================================
// �p�[�e�B�N���N���X
//============================================
class CParticle : public CObjectBase
{
public:
	CParticle();									//�R���X�g���N�^
	~CParticle() override;							//�f�X�g���N�^

	HRESULT Init(void)override;						//�p�[�e�B�N���̏���������
	void Uninit(void)override;						//�p�[�e�B�N���̏I������
	void Update(void)override;						//�p�[�e�B�N���̍X�V����
	void Draw(void)override;						//�p�[�e�B�N���̕`�揈��

	static void SetBillboardPos(D3DXVECTOR3 pos) { m_pos = pos; }	//�p�[�e�B�N���̈ʒu�ݒ�
	static D3DXVECTOR3 GetBillboardPos(void) { return m_pos; }		//�p�[�e�B�N���̈ʒu�擾
	static CParticle *Create();			//����

private:
	static D3DXVECTOR3 m_pos;		//�ʒu
	int m_Life;						//�̗�
	
};

#endif

