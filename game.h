//============================================
//
//	game.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _GAME_H_
#define _GAME_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "mode.h"
#include "object2D.h"

//============================================
// �O���錾
//============================================
class CMeshField;
class CFade;

//============================================
// �Q�[���N���X
//============================================
class CGame : public CMode
{
public:
	CGame();					//�R���X�g���N�^
	~CGame();					//�f�X�g���N�^

	HRESULT Init(void);			//�Q�[���̏���������
	void Uninit(void);			//�Q�[���̏I������
	void Update(void);			//�Q�[���̍X�V����
	void Draw(void);			//�Q�[���̕`�揈��

	static CMeshField *GetMeshField(void) { return m_pMeshField; }		//���b�V���t�B�[���h�̏��̎擾����
	static CGame *Create();												//����

private:
	static CMeshField *m_pMeshField;	
	CFade *m_pFade;						//�t�F�[�h
};

#endif






