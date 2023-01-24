//============================================
//
//	gimmick.h
//	Author: saito shian
//
//============================================
#ifndef _GIMMICK_H_
#define _GIMMICK_H_

//============================================
// �C���N���[�h�t�@�C��
//============================================
#include "objectX.h"

//============================================
// �O����`
//============================================

//============================================
// �N���X�̒�`
//============================================
class CGimmick : public CObjectX
{
public:
	//============================================
	// �M�~�b�N�̃^�C�v
	//============================================
	enum GIMMICKTYPE
	{
		GIMMICKTYPE_NONE = 0,
		GIMMICKTYPE_GASOLENE,				//�K�\�����M�~�b�N
		GIMMICKTYPE_MAX
	};

	CGimmick();
	~CGimmick() override;

	HRESULT Init() override;			//����������
	void Uninit() override;				//�I������
	void Update() override;				//�X�V����
	void Draw() override;				//�`�揈��

	void SetGimmickType(GIMMICKTYPE type);								//�M�~�b�N�̎�ނ̐ݒ�
	GIMMICKTYPE GetGimmickType(void) { return m_GimmickType; }			//�M�~�b�N�̎�ނ̎擾

private:
	D3DXVECTOR3 m_Pos;				//�M�~�b�N�̈ʒu
	GIMMICKTYPE m_GimmickType;		//�M�~�b�N�̎��
};
#endif
