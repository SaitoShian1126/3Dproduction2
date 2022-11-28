//============================================
//
//	result.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "result.h"
#include "application.h"
#include "renderer.h" 
#include "input.h"
#include "fade.h"
#include "object2d.h"

//============================================
// 静的メンバ変数宣言
//============================================
LPDIRECT3DTEXTURE9 CResult::m_pTextureResult = {};
CResult::TYPE CResult::m_type = TYPE_NONE;

//============================================
// リザルトのコンストラクタ
//============================================
CResult::CResult()
{
	//============================================
	//メンバ変数のクリア
	//============================================
}

//============================================
// リザルトのデストラクタ
//============================================
CResult::~CResult()
{
	//何も書かない
}

//============================================
// リザルトの初期化処理
//============================================
HRESULT CResult::Init(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/result.png",
		&m_pTextureResult);

	//============================================
	//メンバ変数の初期化
	//============================================
	m_pObject = CObject2D::Create(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->SetSize(D3DXVECTOR3(640.0f, 360.0f, 0.0f));
	m_pObject->BindTexture(m_pTextureResult);
	return S_OK;
}

//============================================
// リザルトの終了処理
//============================================
void CResult::Uninit(void)
{
	CObject::Release();
}

//============================================
// リザルトの更新処理
//============================================
void CResult::Update()
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	//CJoyPad *pInputJoyKey = CApplication::GetInputJoyKey();

	if (pInput->GetKeyboardTrigger(DIK_RETURN) == true && m_pFade->GetFade() == CFade::FADETYPE_NONE)
	{
		CFade::SetFade(CApplication::MODE_RANKING);
	}
}

//============================================
// リザルトの描画処理
//============================================
void CResult::Draw()
{

}

//============================================
// リザルトの設定処理
//============================================
void CResult::SetType(TYPE type)
{
	m_type = type;
}

//============================================
// リザルトの生成
//============================================
CResult *CResult::Create()
{
	CResult *pResult = nullptr;

	//クラスの生成
	pResult = new CResult;				//2Dオブジェクトのインスタンス生成

	//nullチェック
	if (pResult != nullptr)
	{
		//初期化処理
		pResult->Init();
	}
	else
	{
		assert(false);
	}

	return pResult;
}
