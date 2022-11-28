//============================================
//
//	debug.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <stdio.h>
#include "debug.h"
#include "application.h"
#include "renderer.h"

//============================================
// �ÓI�����o�ϐ��錾
//============================================
LPD3DXFONT CDebugProc::m_pFont = nullptr;
char CDebugProc::m_aStr[1024] = {};

//============================================
// �f�o�b�O�\���̃R���X�g���N�^
//============================================
CDebugProc::CDebugProc()
{
	//============================================
	//�����o�ϐ��̃N���A
	//============================================
	m_pFont = nullptr;						//�t�H���g���N���A
}

//============================================
// �f�o�b�O�\���̃f�X�g���N�^
//============================================
CDebugProc::~CDebugProc()
{
	//���������Ȃ�
}

//============================================
// �f�o�b�O�\���̏���������
//============================================
HRESULT CDebugProc::Init(void)
{
	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_pFont = nullptr;						//�t�H���g��������

	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

#ifdef _DEBUG
	// �f�o�b�O���\���p�t�H���g�̐���
	D3DXCreateFont(pDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Terminal"), &m_pFont);
#endif

	return S_OK;
}

//============================================
// �f�o�b�O�\���̏I������
//============================================
void CDebugProc::Uninit(void)
{
#ifdef _DEBUG
	// �f�o�b�O���\���p�t�H���g�̔j��
	if (m_pFont != nullptr)
	{
		m_pFont->Release();
		m_pFont = nullptr;
	}
#endif // _DEBUG
}

//============================================
// �f�o�b�O�\��
//============================================
void CDebugProc::Print(const char * pFormat, ...)
{
	va_list args;					//�ψ������g�p���邽�߂̊֐� args(����)
	va_start(args, pFormat);		//������va_list�̐��l,������������
	vsprintf(m_aStr, pFormat, args);//���ʊi�[�p�A�h���X,�\�������镶����,���l
	va_end(args);					//�I�����邽�߂ɕK�v
}

//�f�o�b�O�\���̕`�揈��
void CDebugProc::Draw(void)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	// �e�L�X�g�`��
	m_pFont->DrawText(NULL, m_aStr, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));
}
