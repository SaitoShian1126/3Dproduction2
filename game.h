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
// �}�N����`
//============================================
#define MAX_ENEMY		(2)	//�G�̍ő吔
#define MAX_GASOLENE	(1)	//�K�\�����̍ő吔

//============================================
// �O���錾
//============================================
class CMeshField;
class CEnemy;
class CFade;
class CScore;
class CGasolene_Gimmick;
class CModel;
class CHitBox;
class CPlayer;
class CSpawn;

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

	static CMeshField *GetMeshField(void) { return m_pMeshField; }								//���b�V���t�B�[���h�̏��̎擾����
	static CScore *GetScore(void) { return m_pScore; }											//�G�̏��̎擾����
	static CGasolene_Gimmick *GetGasoleneGimmick(int cnt) { return m_pGasoleneGimmick[cnt]; }	//�K�\�����M�~�b�N�̏��̎擾����
	static CModel *GetModel(void) { return m_Model; }											//���f���̎擾����
	static CPlayer *GetPlayer(void) { return m_pPlayer; }										//�v���C���[�擾����
	static CSpawn *GetSpawn(void) { return m_pSpawn; }											//�X�|�[���̎擾����

	static CGame *Create();												//����

private:
	static CMeshField *m_pMeshField;							//���b�V���t�B�[���h�̃C���X�^���X
	static CScore *m_pScore;									//�X�R�A�̃C���X�^���X
	static CGasolene_Gimmick *m_pGasoleneGimmick[MAX_GASOLENE];	//�K�\�����M�~�b�N�̃C���X�^���X
	static CModel *m_Model;										//���f���̃C���X�^���X
	static CPlayer *m_pPlayer;									//�v���C���[�̃C���X�^���X
	static CSpawn *m_pSpawn;									//�X�|�[���̃C���X�^���X
	CFade *m_pFade;												//�t�F�[�h�̃C���X�^���X
};
#endif



