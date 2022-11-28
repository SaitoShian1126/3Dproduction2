//============================================
//
//	camera.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"

//============================================
// �}�N����`
//============================================
#define CAMERA_SPEED	(0.5f)	//�J�����̑��x

//============================================
// �J�����N���X
//============================================
class CCamera
{
public:
	CCamera();				//�R���X�g���N�^
	~CCamera();				//�f�X�g���N�^

	HRESULT Init(void);		//�J�����̏���������
	void Uninit(void);		//�J�����̏I������
	void Update(void);		//�J�����̍X�V����

	void SetCamera();		//�J�����̐ݒ菈��

	static D3DXVECTOR3 GetCameraRot() { return m_Rot; }		//�J�����̉�]�̎擾����	

private:
	static D3DXVECTOR3 m_Rot;		//����
	D3DXVECTOR3 m_PosV;				//���_
	D3DXVECTOR3 m_PosVDest;			//�ړI�̎��_
	D3DXVECTOR3 m_PosR;				//�����_
	D3DXVECTOR3 m_PosRDest;			//�ړI�̒����_
	D3DXVECTOR3 m_VecU;				//������x�N�g��
	D3DVIEWPORT9 m_Viewport;		//�r���[�|�[�g
	D3DXMATRIX m_mtxProjection;		//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX m_mtxView;			//�r���[�}�g���b�N�X

	float m_fDistance;				//���_���璍���_�̋���			
};

#endif