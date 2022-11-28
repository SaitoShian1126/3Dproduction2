//============================================
//
//	title.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "title.h"
#include "application.h"
#include "renderer.h" 
#include "object2d.h"
#include "fade.h"
#include "input.h"

//============================================
// �^�C�g���̃R���X�g���N�^
//============================================
CTitle::CTitle()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
}

//============================================
// �^�C�g���̃f�X�g���N�^
//============================================
CTitle::~CTitle()
{
	//���������Ȃ�
}

//============================================
// �^�C�g���̏���������
//============================================
HRESULT CTitle::Init(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/title.png",
		&m_pTextureTitle);

	//============================================
	//�����o�ϐ��̏�����
	//============================================

	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureTitle);

	return S_OK;
}

//============================================
// �^�C�g���̏I������
//============================================
void CTitle::Uninit(void)
{
	CObject::Release();
}

//============================================
// �^�C�g���̍X�V����
//============================================
void CTitle::Update()
{
	//�C���v�b�g�̃C���X�^���X����
	CInput *pInput = CApplication::GetInput();
	//CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();
	
	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE)
	{
		CFade::SetFade(CApplication::MODE_GAME);
	}
}

//============================================
// �^�C�g���̕`�揈��
//============================================
void CTitle::Draw()
{

}

//============================================
// �^�C�g���̐���
//============================================
CTitle *CTitle::Create()
{
	CTitle *pTitle = nullptr;

	//�N���X�̐���
	pTitle = new CTitle;				//2D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pTitle != nullptr)
	{
		//����������
		pTitle->Init();
	}
	else
	{
		assert(false);
	}

	return pTitle;
}

//============================================
// �F�̐ݒ�
//============================================
void CTitle::SetColor(float Red, float Green, float Blue, float ��)
{
	VERTEX_2D*pVtx;				//���_���ւ̃|�C���^

	LPDIRECT3DVERTEXBUFFER9 Buffer = GetBuffer();

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	Buffer->Lock(0, 0, (void**)&pVtx, 0);

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[1].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[2].col = D3DXCOLOR(Red, Green, Blue, ��);
	pVtx[3].col = D3DXCOLOR(Red, Green, Blue, ��);

	//���_�o�b�t�@���A�����b�N����
	Buffer->Unlock();
}