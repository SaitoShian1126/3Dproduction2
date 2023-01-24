//============================================
//
//	spawn.h
//	Author: saito shian
//
//============================================

//============================================
// 2�d�C���N���[�h�K�[�h
//============================================
#ifndef _SPAWN_H_
#define _SPAWN_H_

//============================================
// �C���N���[�h
//============================================
#include "main.h"
#include "objectX.h"

//============================================
// �}�N����`
//============================================
#define ENEMY_CREATE_TIME	(250)	//�G�����������܂ł̎���
#define MAX_ENEMY			(2)		//�G�̍ő吔

//============================================
// �O���錾
//============================================
class CEnemy;

//============================================
// �ʎY�N���X
//============================================
class CSpawn :public CObjectX
{
public:
	CSpawn();						//�R���X�g���N�^
	~CSpawn();						//�f�X�g���N�^

	HRESULT Init(void);				//�ʎY�̏���������
	void Uninit(void);				//�ʎY�̏I������
	void Update(void);				//�ʎY�̍X�V����
	void Draw(void);				//�ʎY�̕`�揈��

	void EnemySpawn(void);			//�G�̗ʎY����
	
	//getter
	int GetEnemyCount(void) { return m_EnemyCount; }	//�G�̑����̎擾����

	//setter
	void SetEnemyCount(int cnt) { m_EnemyCount = cnt; }	//�G�̑����̐ݒ菈��

	static CEnemy **GetEnemy() { return m_pEnemy; }		//�G�̏��̎擾����

	static CSpawn *Create();		//��������

private:
	static CEnemy *m_pEnemy[MAX_ENEMY];	//�G�̃C���X�^���X
	int m_EnemyCreateTime;				//�G�����������܂ł̎���
	int m_RandNumber;					//�����_���Ȓl������ϐ�
	int m_RandPos;						//�����_���Ȉʒu�ɓG�𐶐�
	int m_EnemyCount;					//�G�̑���

	bool m_RandFlag;					//�G�̃����_���t���O
	bool m_MaxEnemyFlag;				//�G���ő�l�ɒB�����̂��̃t���O

};
#endif