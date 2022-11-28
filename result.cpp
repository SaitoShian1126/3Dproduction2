//============================================
//
//	result.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "result.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "fade.h"
#include "object2d.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================
LPDIRECT3DTEXTURE9 CResult::m_pTextureResult = {};
CResult::TYPE CResult::m_type = TYPE_NONE;

//============================================
// ���U���g�̃R���X�g���N�^
//============================================
CResult::CResult()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
}

//============================================
// ���U���g�̃f�X�g���N�^
//============================================
CResult::~CResult()
{
	//���������Ȃ�
}

//============================================
// ���U���g�̏���������
//============================================
HRESULT CResult::Init(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/result.png",
		&m_pTextureResult);

	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureResult);
	return S_OK;
}

//============================================
// ���U���g�̏I������
//============================================
void CResult::Uninit(void)
{
	CObject::Release();
}

//============================================
// ���U���g�̍X�V����
//============================================
void CResult::Update()
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	//CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE)
	{
		CFade::SetFade(CApplication::MODE_RANKING);
	}
}

//============================================
// ���U���g�̕`�揈��
//============================================
void CResult::Draw()
{

}

//============================================
// ���U���g�̐ݒ菈��
//============================================
void CResult::SetType(TYPE type)
{
	m_type = type;
}

//============================================
// ���U���g�̐���
//============================================
CResult *CResult::Create()
{
	CResult *pResult = nullptr;

	//�N���X�̐���
	pResult = new CResult;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pResult != nullptr)
	{
		//����������
		pResult->Init();
	}
	else
	{
		assert(false);
	}

	return pResult;
}
