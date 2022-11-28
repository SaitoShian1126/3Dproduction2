//============================================
//
//	billboard.cpp
//	Author: saito shian
//
//============================================

//============================================
// インクルード
//============================================
#include <assert.h>
#include "billboard.h"
#include "application.h"
#include "renderer.h"

//============================================
// ビルボードのコンストラクタ
//============================================
CBillboard::CBillboard()
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_pVtxBuffBillboard = nullptr;									//バッファの初期化
	m_BillboardPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//位置の初期化
	m_BillboardSize = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//サイズ
}

//============================================
// ビルボードのデストラクタ
//============================================
CBillboard::~CBillboard()
{
}
//============================================
// ビルボードの初期化処理
//============================================
HRESULT CBillboard::Init(void)
{
	//============================================
	//メンバ変数の初期化
	//============================================
	m_pVtxBuffBillboard = nullptr;									//バッファの初期化
	m_BillboardPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//位置の初期化
	m_BillboardSize = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//サイズ

	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの使用をfalseにする
	m_pTextureBillboard = false;
	//テクスチャの設定
	SetTexture("data/TEXTURE/ゾンビ.png");

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffBillboard,
		NULL);

	//頂点情報へのポインタ
	VERTEX_3D * pVtx = NULL;

	//頂点バッファをロック
	m_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定(ワールド座標ではなくローカル座標を設定)
	pVtx[0].pos = D3DXVECTOR3(m_BillboardPos.x - 10.0f, m_BillboardPos.y + 10.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_BillboardPos.x + 10.0f, m_BillboardPos.y + 10.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_BillboardPos.x - 10.0f, m_BillboardPos.y - 10.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_BillboardPos.x + 10.0f, m_BillboardPos.y - 10.0f, 0.0f);

	//各頂点の法線の設定(※ベクトルの大きさは1にする必要がある)
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	m_pVtxBuffBillboard->Unlock();

	return S_OK;
}

//============================================
// ビルボードの終了処理
//============================================
void CBillboard::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuffBillboard != NULL)
	{
		m_pVtxBuffBillboard->Release();
		m_pVtxBuffBillboard = NULL;
	}

	//破棄処理
	Release();
}

//============================================
// ビルボードの更新処理
//============================================
void CBillboard::Update(void)
{

}

//============================================
// ビルボードの描画処理
//============================================
void CBillboard::Draw(void)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_BillboardmtxWorld);//行列初期化関数(第一引数の行列を単位行列に初期化)

	//ビューマトリックスを取得
	D3DXMATRIX mtxView;
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	//カメラの逆行列を設定	(2付くやつを消せばビルボードが上に向かない)
	m_BillboardmtxWorld._11 = mtxView._11;
	m_BillboardmtxWorld._12 = mtxView._21;
	m_BillboardmtxWorld._13 = mtxView._31;
	m_BillboardmtxWorld._21 = mtxView._12;
	m_BillboardmtxWorld._22 = mtxView._22;
	m_BillboardmtxWorld._23 = mtxView._32;
	m_BillboardmtxWorld._31 = mtxView._13;
	m_BillboardmtxWorld._32 = mtxView._23;
	m_BillboardmtxWorld._33 = mtxView._33;

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_BillboardRot.y, m_BillboardRot.x, m_BillboardRot.z);	//行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
	D3DXMatrixMultiply(&m_BillboardmtxWorld, &m_BillboardmtxWorld, &mtxRot);						//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_BillboardPos.x, m_BillboardPos.y, m_BillboardPos.z);		//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
	D3DXMatrixMultiply(&m_BillboardmtxWorld, &m_BillboardmtxWorld, &mtxTrans);

	//ライトを無効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//zバッファ
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, D3DCMP_ALWAYS);

	//アルファテストを有効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_BillboardmtxWorld);	//ワールド座標行列の設定

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTextureBillboard);

	//ビルボードの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	//ライトを有効に戻す
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	//設定を元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//Zバッファの設定を元に戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//アルファテストを無効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	//テクスチャの解除
	pDevice->SetTexture(0, NULL);
}
//============================================
// ビルボードのテクスチャの設定
//============================================
CBillboard * CBillboard::SetTexture(char * pFile)
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		pFile,
		&m_pTextureBillboard);

	m_BillboardTexture = true;

	return S_OK;
}

//============================================
// ビルボードの生成
//============================================
CBillboard * CBillboard::Create(const D3DXVECTOR3 & pos)
{
	CBillboard *pBillboard = nullptr;

	//3Dオブジェクトクラスの生成
	pBillboard = new CBillboard;				//3Dオブジェクトのインスタンス生成

	//nullチェック
	if (pBillboard != nullptr)
	{
		//初期化処理
		pBillboard->Init();
		//設定処理
		pBillboard->SetPosition(pos);
	}
	else
	{
		assert(false);
	}
	return pBillboard;
}

//============================================
// ビルボードの設定処理
//============================================
void CBillboard::SetPosition(D3DXVECTOR3 pos)
{
	m_BillboardPos = pos;
}