//============================================
//
//	billboard.h
//	Author: saito shian
//
//============================================

//============================================
// 2重インクルードガード
//============================================
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

//============================================
// インクルード
//============================================
#include "main.h"
#include "object.h"
#include "shadow.h"

//============================================
// ビルボードクラス
//============================================
class CBillboard : public CObject
{
public:
	CBillboard();									//コンストラクタ
	~CBillboard()override;							//デストラクタ

	HRESULT Init(void)override;						//ポリゴンの初期化処理
	void Uninit(void)override;						//ポリゴンの終了処理
	void Update(void)override;						//ポリゴンの更新処理
	void Draw(void)override;						//ポリゴンの描画処理

	void SetPosition(D3DXVECTOR3 pos)override;							//ポリゴンの位置
	void SetMove(D3DXVECTOR3 move)override { move; }					//ポリゴンの移動
	void SetSize(D3DXVECTOR3 size);										//ポリゴンのサイズ
	void SetRot(D3DXVECTOR3 rot) { rot; }								//回転
	void SetLength(float length) { length; }							//拡大縮小のスケール
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture) { pTexture; }			//テクスチャ反映
	float GetLength(void) override { return m_fLength; }				//拡大縮小のスケールの取得

	LPDIRECT3DVERTEXBUFFER9 GetBuffer() { return m_pVtxBuffBillboard; }	//バッファーの取得
	D3DXVECTOR3 GetPos(void) override { return m_BillboardPos; }		//位置の取得
	D3DXVECTOR3 GetMove(void) override { return m_BillboardMove; }		//移動量の取得
	D3DXVECTOR3 GetSize(void) override { return m_BillboardSize; }		//サイズの取得
	D3DXVECTOR3 GetRot(void) override { return m_BillboardRot; }		//回転の取得

	CBillboard *SetTexture(char *pFile);
	static CBillboard *Create(const D3DXVECTOR3 &pos);					//生成

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffBillboard;		//頂点バッファへのポインタ
	LPDIRECT3DTEXTURE9 m_pTextureBillboard;				//頂点バッファへのポインタ
	D3DXVECTOR3 m_BillboardPos;							//位置
	D3DXVECTOR3 m_BillboardRot;							//向き
	D3DXVECTOR3	m_BillboardMove;						//移動
	D3DXVECTOR3 m_BillboardSize;						//サイズ
	D3DXMATRIX m_BillboardmtxWorld;						//ワールドマトリックス
	CBillboard *m_pBillboard;							//ビルボードの情報
	CShadow *m_pShadow;

	float m_fLength;									//拡大縮小のスケール
	bool m_BillboardTexture;							//テクスチャが使われているかどうか
};

#endif

