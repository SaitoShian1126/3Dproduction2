//============================================
//
//	player.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "objectx.h"

//============================================
// �}�N����`
//============================================
#define PLAYER_MOVE	(1.0f)	//�v���C���[�̈ړ�

//============================================
// �O���錾
//============================================
class CShadow;

//============================================
// �I�u�W�F�N�g�N���X
//============================================
class CPlayer : public CObjectX
{
public:
	CPlayer();									//�R���X�g���N�^
	~CPlayer()override;									//�f�X�g���N�^

	HRESULT Init(void)override;						//�|���S���̏���������
	void Uninit(void)override;						//�|���S���̏I������
	void Update(void)override;						//�|���S���̍X�V����
	void Draw(void)override;						//�|���S���̕`�揈��

	static D3DXVECTOR3 GetPlayerPos(void) { return m_pos; }
	static CPlayer *Create(const D3DXVECTOR3 &pos);			//����
	CPlayer *SetPlayerModel(char *pFile);

private:
	static D3DXVECTOR3 m_pos;
	D3DXVECTOR3 m_posOld;
	D3DXVECTOR3 m_size;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_rotDest;
	LPD3DXBUFFER m_PlayerBuffMat;
	LPD3DXMESH m_PlayerMesh;
	DWORD m_nPlayerNumMat;
	CShadow *m_pShadow;

	bool m_PlayerModel;
	float m_PlayerHeightPos;
};

#endif
