//============================================
//
//	billboard.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "object.h"
#include "shadow.h"

//============================================
// �r���{�[�h�N���X
//============================================
class CBillboard : public CObject
{
public:
	CBillboard();									//�R���X�g���N�^
	~CBillboard()override;							//�f�X�g���N�^

	HRESULT Init(void)override;						//�|���S���̏���������
	void Uninit(void)override;						//�|���S���̏I������
	void Update(void)override;						//�|���S���̍X�V����
	void Draw(void)override;						//�|���S���̕`�揈��

	void SetPosition(D3DXVECTOR3 pos)override;							//�|���S���̈ʒu
	void SetMove(D3DXVECTOR3 move)override { move; }					//�|���S���̈ړ�
	void SetSize(D3DXVECTOR3 size);										//�|���S���̃T�C�Y
	void SetRot(D3DXVECTOR3 rot) { rot; }								//��]
	void SetLength(float length) { length; }							//�g��k���̃X�P�[��
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { pTexture; }			//�e�N�X�`�����f
	float GetLength(void) override { return m_fLength; }				//�g��k���̃X�P�[���̎擾

	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuffBillboard; }	//�o�b�t�@�[�̎擾
	D3DXVECTOR3 GetPos(void) override { return m_BillboardPos; }		//�ʒu�̎擾
	D3DXVECTOR3 GetMove(void) override { return m_BillboardMove; }		//�ړ��ʂ̎擾
	D3DXVECTOR3 GetSize(void) override { return m_BillboardSize; }		//�T�C�Y�̎擾
	D3DXVECTOR3 GetRot(void) override { return m_BillboardRot; }		//��]�̎擾

	CBillboard *SetTexture(char *pFile);
	static CBillboard *Create(const D3DXVECTOR3 &pos);					//����

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffBillboard;		//���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTextureBillboard;				//���_�o�b�t�@�ւ̃|�C���^
	D3DXVECTOR3 m_BillboardPos;							//�ʒu
	D3DXVECTOR3 m_BillboardRot;							//����
	D3DXVECTOR3	m_BillboardMove;						//�ړ�
	D3DXVECTOR3 m_BillboardSize;						//�T�C�Y
	D3DXMATRIX m_BillboardmtxWorld;						//���[���h�}�g���b�N�X
	CBillboard *m_pBillboard;							//�r���{�[�h�̏��
	CShadow *m_pShadow;

	float m_fLength;									//�g��k���̃X�P�[��
	bool m_BillboardTexture;							//�e�N�X�`�����g���Ă��邩�ǂ���
};

#endif

