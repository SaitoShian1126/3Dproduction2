//============================================
//
//	billboard.cpp
//	Author: saito shian
//
//============================================

//============================================
// �C���N���[�h
//============================================
#include <assert.h>
#include "billboard.h"
#include "application.h"
#include "renderer.h"

//============================================
// �r���{�[�h�̃R���X�g���N�^
//============================================
CBillboard::CBillboard()
{
	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_pVtxBuffBillboard = nullptr;									//�o�b�t�@�̏�����
	m_BillboardPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�ʒu�̏�����
	m_BillboardSize = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�T�C�Y
}

//============================================
// �r���{�[�h�̃f�X�g���N�^
//============================================
CBillboard::~CBillboard()
{
}
//============================================
// �r���{�[�h�̏���������
//============================================
HRESULT CBillboard::Init(void)
{
	//============================================
	//�����o�ϐ��̏�����
	//============================================
	m_pVtxBuffBillboard = nullptr;									//�o�b�t�@�̏�����
	m_BillboardPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//�ʒu�̏�����
	m_BillboardSize = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�T�C�Y

	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̎g�p��false�ɂ���
	m_pTextureBillboard = false;
	//�e�N�X�`���̐ݒ�
	SetTexture("data/TEXTURE/�]���r.png");

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffBillboard,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_3D * pVtx = NULL;

	//���_�o�b�t�@�����b�N
	m_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�(���[���h���W�ł͂Ȃ����[�J�����W��ݒ�)
	pVtx[0].pos = D3DXVECTOR3(m_BillboardPos.x - 10.0f, m_BillboardPos.y + 10.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_BillboardPos.x + 10.0f, m_BillboardPos.y + 10.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_BillboardPos.x - 10.0f, m_BillboardPos.y - 10.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_BillboardPos.x + 10.0f, m_BillboardPos.y - 10.0f, 0.0f);

	//�e���_�̖@���̐ݒ�(���x�N�g���̑傫����1�ɂ���K�v������)
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuffBillboard->Unlock();

	return S_OK;
}

//============================================
// �r���{�[�h�̏I������
//============================================
void CBillboard::Uninit(void)
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuffBillboard != NULL)
	{
		m_pVtxBuffBillboard->Release();
		m_pVtxBuffBillboard = NULL;
	}

	//�j������
	Release();
}

//============================================
// �r���{�[�h�̍X�V����
//============================================
void CBillboard::Update(void)
{

}

//============================================
// �r���{�[�h�̕`�揈��
//============================================
void CBillboard::Draw(void)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_BillboardmtxWorld);//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

	//�r���[�}�g���b�N�X���擾
	D3DXMATRIX mtxView;
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	//�J�����̋t�s���ݒ�	(2�t����������΃r���{�[�h����Ɍ����Ȃ�)
	m_BillboardmtxWorld._11 = mtxView._11;
	m_BillboardmtxWorld._12 = mtxView._21;
	m_BillboardmtxWorld._13 = mtxView._31;
	m_BillboardmtxWorld._21 = mtxView._12;
	m_BillboardmtxWorld._22 = mtxView._22;
	m_BillboardmtxWorld._23 = mtxView._32;
	m_BillboardmtxWorld._31 = mtxView._13;
	m_BillboardmtxWorld._32 = mtxView._23;
	m_BillboardmtxWorld._33 = mtxView._33;

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_BillboardRot.y, m_BillboardRot.x, m_BillboardRot.z);	//�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
	D3DXMatrixMultiply(&m_BillboardmtxWorld, &m_BillboardmtxWorld, &mtxRot);						//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_BillboardPos.x, m_BillboardPos.y, m_BillboardPos.z);		//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
	D3DXMatrixMultiply(&m_BillboardmtxWorld, &m_BillboardmtxWorld, &mtxTrans);

	//���C�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//z�o�b�t�@
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, D3DCMP_ALWAYS);

	//�A���t�@�e�X�g��L��
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_BillboardmtxWorld);	//���[���h���W�s��̐ݒ�

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTextureBillboard);

	//�r���{�[�h�̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	//���C�g��L���ɖ߂�
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//�ݒ�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//Z�o�b�t�@�̐ݒ�����ɖ߂�
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//�A���t�@�e�X�g�𖳌�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	//�e�N�X�`���̉���
	pDevice->SetTexture(0, NULL);
}
//============================================
// �r���{�[�h�̃e�N�X�`���̐ݒ�
//============================================
CBillboard * CBillboard::SetTexture(char * pFile)
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		pFile,
		&m_pTextureBillboard);

	m_BillboardTexture = true;

	return S_OK;
}

//============================================
// �r���{�[�h�̐���
//============================================
CBillboard * CBillboard::Create(const D3DXVECTOR3 & pos)
{
	CBillboard *pBillboard = nullptr;

	//3D�I�u�W�F�N�g�N���X�̐���
	pBillboard = new CBillboard;				//3D�I�u�W�F�N�g�̃C���X�^���X����

	//null�`�F�b�N
	if (pBillboard != nullptr)
	{
		//����������
		pBillboard->Init();
		//�ݒ菈��
		pBillboard->SetPosition(pos);
	}
	else
	{
		assert(false);
	}
	return pBillboard;
}

//============================================
// �r���{�[�h�̐ݒ菈��
//============================================
void CBillboard::SetPosition(D3DXVECTOR3 pos)
{
	m_BillboardPos = pos;
}