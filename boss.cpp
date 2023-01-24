//============================================
// 
// 	boss.cpp
// 	Author: saito shian
// 
//============================================

//============================================
// インクルード
//============================================
#include <stdio.h>
#include <assert.h>
#include "boss.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "shadow.h"
#include "debug.h"
#include "meshfield.h"
#include "game.h"
#include "modelparts.h"
#include "keyset.h"
#include "key.h"
#include "motionset.h"
#include "score.h"
#include "player.h"

//============================================
// 静的メンバ変数宣言
//============================================
D3DXVECTOR3 CBoss::m_pos = {};
D3DXVECTOR3 CBoss::m_rot = {};
D3DXVECTOR3 CBoss::m_size = {};

//============================================
// オブジェクトのコンストラクタ
//============================================
CBoss::CBoss()
{
	//============================================
	// メンバ変数のクリア
	//============================================
	m_nCountModel = 0;
	m_nLife = 0;
}

//============================================
// オブジェクトのデストラクタ
//============================================
CBoss::~CBoss()
{
	// 何も書かない
}

//============================================
// オブジェクト(ポリゴン)の初期化処理
//============================================
HRESULT CBoss::Init(void)
{
	// ============================================
	// メンバ変数の初期化
	// ============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_size = D3DXVECTOR3(10.0f, 50.0f, 10.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_nCountModel = 0;
	m_PresentKeySet = 0;
	m_Frame = 0;
	m_nLife = 100;
	for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
	{
		m_apModel[nCnt] = nullptr;								//モデル数の初期化
		m_FrameSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//フレームスピードの初期化
		m_RotSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//回転スピードの初期化
	}

	//プレイヤーのファイル読み込み
	LoadBoss();

	m_pShadow = CShadow::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// 影の設定処理の初期化

	return S_OK;
}

//============================================
// オブジェクト(ポリゴン)の終了処理
//============================================
void CBoss::Uninit(void)
{
	//モデルパーツの終了処理
	for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			m_apModel[nCnt]->Uninit();
			delete m_apModel[nCnt];
			m_apModel[nCnt] = nullptr;
		}
	}
}

//============================================
// オブジェクト(ポリゴン)の更新処理
//============================================
void CBoss::Update(void)
{
	CMeshField *pMeshField = CGame::GetMeshField();

	//メッシュフィールドと敵の当たり判定
	pMeshField->GetMeshFieldCollision(&m_pos);

	//移動の設定
	SetMove(m_move);
	//位置の設定
	SetPosition(m_pos);
}

//============================================
// オブジェクト(ポリゴン)の描画処理
//============================================
void CBoss::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス

										//ローカルマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);											//行列初期化関数(第一引数の行列を単位行列に初期化)

																				//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);			//行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);						//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

																				//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);				//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//モデルパーツのfor文
	for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			m_apModel[nCnt]->DrawFile();
		}
	}
}

//============================================
// 生成
//============================================
CBoss * CBoss::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 move)
{
	CBoss *pPlayer = nullptr;

	// 3Dオブジェクトクラスの生成
	pPlayer = new CBoss;				// 3Dオブジェクトのインスタンス生成

										// nullptrチェック
	if (pPlayer != nullptr)
	{
		// 初期化処理
		pPlayer->Init();
		pPlayer->SetPosition(pos);
		pPlayer->m_move = move;
	}
	else
	{
		assert(false);
	}
	return pPlayer;
}

//============================================
// 外部ファイル読み込み
//============================================
void CBoss::LoadBoss()
{
	int nNumParts;
	int nCntMotionSet = 0;
	int Loop = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	char aText[2000];							//文字列を格納する配列
	char FileName[MODEL_BOSS_PARTS][2000];		//2次元配列

	FILE *pFile; //ファイルポインタを宣言

	pFile = fopen("data/XMODEL/bossMotion.txt", "r");

	aText[0] = '\0';	//文字列なし

	if (pFile != nullptr)
	{//ファイルが開けた場合
	 //ファイルに入力したデータを書き出す処理
		while (strncmp(&aText[0], "SCRIPT", strlen("SCRIPT")) != 0)
		{//テキストの最初の行を読み込むまで繰り返す
			fgets(aText, MAX_BOSS_WORD, pFile);        //一行ごと読み込む
		}

		while (strncmp(&aText[0], "END_SCRIPT", strlen("END_SCRIPT")) != 0)
		{//テキストの最後の行を読み込むまで繰り返す
			fscanf(pFile, "%s", &aText[0]);    //ファイルから文字列を読み込む(読み込み開始)

			if (strncmp(&aText[0], "#", strlen("#")) == 0)
			{
				fgets(aText, MAX_BOSS_WORD, pFile);        //一行ごと読み込む
				continue;
			}

			//ファイルネームを複数個入力する
			if (strcmp(&aText[0], "MODEL_FILENAME") == 0)
			{
				fscanf(pFile, "%s", &aText[0]);        // = を読み込む
				fscanf(pFile, "%s", &FileName[m_nCountModel][0]);	//0番目から読み込まれる

																	//モデルパーツの生成
				m_apModel[m_nCountModel]->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

				m_nCountModel++;
			}

			if (strcmp(&aText[0], "CHARACTERSET") == 0)
			{
				while (strcmp(&aText[0], "END_CHARACTERSET") != 0)
				{
					fscanf(pFile, "%s", &aText[0]);

					if (strncmp(&aText[0], "#", strlen("#")) == 0)
					{
						fgets(aText, MAX_BOSS_WORD, pFile);        //一行ごと読み込む
						continue;
					}

					if (strcmp(&aText[0], "NUM_PARTS") == 0)
					{
						fscanf(pFile, "%s", &aText[0]);        // = を読み込む
						fscanf(pFile, "%d", &nNumParts);
					}

					if (strcmp(&aText[0], "PARTSSET") == 0)
					{
						D3DXVECTOR3 pos, rot;
						int IndexParent = 0;	//親の番号
						int Ind = 0;

						while (strcmp(&aText[0], "END_PARTSSET") != 0)
						{
							fscanf(pFile, "%s", &aText[0]);

							if (strncmp(&aText[0], "#", strlen("#")) == 0)
							{
								fgets(aText, MAX_BOSS_WORD, pFile);        //一行ごと読み込む
								continue;
							}

							if (strcmp(&aText[0], "INDEX") == 0)
							{
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%d", &Ind);
							}

							else if (strcmp(&aText[0], "PARENT") == 0)
							{

								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%d", &IndexParent);
							}

							else if (strcmp(&aText[0], "POS") == 0)
							{
								float x = 0.0f;
								float y = 0.0f;
								float z = 0.0f;
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%f", &x);
								fscanf(pFile, "%f", &y);
								fscanf(pFile, "%f", &z);
								pos = D3DXVECTOR3(x, y, z);
							}

							else if (strcmp(&aText[0], "ROT") == 0)
							{
								float x = 0.0f;
								float y = 0.0f;
								float z = 0.0f;
								fscanf(pFile, "%s", &aText[0]);
								fscanf(pFile, "%f", &x);
								fscanf(pFile, "%f", &y);
								fscanf(pFile, "%f", &z);
								rot = D3DXVECTOR3(x, y, z);
							}
						}

						//モデルパーツの生成
						m_apModel[Ind] = CModelParts::Create(pos, rot);

						//モデルパーツの読み込み
						m_apModel[Ind]->SetModel(&FileName[Ind][0]);

						//モデルパーツに情報が入っていたら
						if (m_apModel[Ind])
						{
							//モデルパーツの向きの設定
							m_apModel[Ind]->SetRot(rot);
						}

						//親の番号が0より下だったら
						if (IndexParent < 0)
						{
							//モデルパーツのマトリックスの設定
							m_apModel[Ind]->SetMatrix(&m_mtxWorld);
						}
						//親の番号がモデルパーツより小さかったら
						else if (IndexParent < MODEL_BOSS_PARTS)
						{
							//モデルパーツのマトリックスの設定
							m_apModel[Ind]->SetMatrix(m_apModel[IndexParent]->GetMatrix());
						}
					}
				}
			}
			if (strcmp(&aText[0], "MOTIONSET") == 0)
			{//テキストの最初の行を読み込むまで繰り返す

				m_MotionSet[nCntMotionSet] = CMotionSet::Create();

				m_MotionSet[nCntMotionSet]->SetNumParts(nNumParts);

				while (strcmp(&aText[0], "END_MOTIONSET") != 0)
				{//テキストの最後の行を読み込むまで繰り返す
					fscanf(pFile, "%s", &aText[0]);    //ファイルから文字列を読み込む(読み込み開始)

					if (strcmp(&aText[0], "NUM_KEY") == 0)
					{
						int numKey = 0;
						fscanf(pFile, "%s %d", &aText[0], &numKey);
						m_MotionSet[nCntMotionSet]->SetNumKey(numKey);
					}

					if (strcmp(&aText[0], "LOOP") == 0)
					{
						fscanf(pFile, "%s %d", &aText[0], &Loop);

						if (Loop == 1)
						{

							m_MotionSet[nCntMotionSet]->GetLoop();
							m_MotionSet[nCntMotionSet]->SetLoop(1);
						}

						else
						{
							m_MotionSet[nCntMotionSet]->GetLoop();
							m_MotionSet[nCntMotionSet]->SetLoop(0);
						}
					}

					if (strcmp(&aText[0], "KEYSET") == 0)
					{
						while (1)
						{
							fscanf(pFile, "%s", &aText[0]);

							if (strcmp(&aText[0], "#") == 0)
							{
								fgets(aText, MAX_BOSS_WORD, pFile);        //一行ごと読み込む
								continue;
							}

							if (strcmp(&aText[0], "END_KEYSET") == 0)
							{
								nCntKeySet++;
								nCntKey = 0;
								break;
							}

							if (strcmp(&aText[0], "FRAME") == 0)
							{
								int nFrame = 0;
								fscanf(pFile, "%s %d", &aText[0], &nFrame);

								m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->SetFrame(nFrame);
							}

							else if (strcmp(&aText[0], "KEY") == 0)
							{
								while (1)
								{
									fscanf(pFile, "%s", &aText[0]);

									if (strcmp(&aText[0], "END_KEY") == 0)
									{
										nCntKey++;

										if (nCntKey >= m_MotionSet[nCntMotionSet]->GetNumParts())
										{
											nCntKey = 0;
										}
										break;
									}
									else if (strcmp(&aText[0], "POS") == 0)
									{
										float px = 0.0f;
										float py = 0.0f;
										float pz = 0.0f;
										fscanf(pFile, "%s", &aText[0]);
										fscanf(pFile, "%f", &px);
										fscanf(pFile, "%f", &py);
										fscanf(pFile, "%f", &pz);
										m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->GetKey(nCntKey)->SetPos(D3DXVECTOR3(px, py, pz));
									}

									else if (strcmp(&aText[0], "ROT") == 0)
									{
										float rx = 0.0f;
										float ry = 0.0f;
										float rz = 0.0f;
										fscanf(pFile, "%s", &aText[0]);
										fscanf(pFile, "%f", &rx);
										fscanf(pFile, "%f", &ry);
										fscanf(pFile, "%f", &rz);
										m_MotionSet[nCntMotionSet]->GetKeySet(nCntKeySet)->GetKey(nCntKey)->SetRot(D3DXVECTOR3(rx, ry, rz));
									}
								}
							}
						}
					}
				}

				nCntMotionSet++;
				nCntKeySet = 0;
				nCntKey = 0;
			}
		}
	}
	for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
	{
		if (m_apModel[nCnt] != nullptr)
		{
			D3DXVECTOR3 pos, rot;
			pos = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetPos();
			rot = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetRot();
			m_apModel[nCnt]->SetPos(pos);
			m_apModel[nCnt]->SetRot(rot);
		}
	}
}

//============================================
// モーション関数
//============================================
void CBoss::MotionBossAnimation(void)
{
	m_Frame++;		//フレームのインクリメント

	for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
	{
		D3DXVECTOR3 pos = m_apModel[nCnt]->GetPos();		//モデルパーツの位置取得
		D3DXVECTOR3 rot = m_apModel[nCnt]->GetRot();		//モデルパーツの向き取得
		pos += m_FrameSpeed[nCnt];							//モデルパーツの位置にフレームの速さを代入
		rot += m_RotSpeed[nCnt];							//モデルパーツの向きに向きの速さを代入
		m_apModel[nCnt]->SetPos(pos);						//位置の設定
		m_apModel[nCnt]->SetRot(rot);						//向きの設定
	}

	if (m_Frame >= m_MotionSet[m_MotionType]->GetKeySet(m_PresentKeySet)->GetFrame())
	{	//現在のアニメーションのフレーム数以上だったら

		int NextKeySet = 0;					//次のキーセット変数
		NextKeySet = m_PresentKeySet + 1;	//次のキーセットを代入

		if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 1)
		{	//再生中のキー数カウントがキー数の最大値を超えたとき、そのモーションがループを使用している

			NextKeySet = 0;					//再生中のキー数カウントを初期化

		}
		else if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 0)
		{	//再生中のキー数カウントがキー数の最大値を超えたとき

			m_MotionSet[m_MotionType]->SetLoop(false);		//ループをfalseに設定する	
			NextKeySet = 0;											//次のキーセットの初期化
		}

		for (int nCnt = 0; nCnt < MODEL_BOSS_PARTS; nCnt++)
		{
			//速度の計算
			m_FrameSpeed[nCnt] = (m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetKey(nCnt)->GetPos() - m_apModel[nCnt]->GetPos());
			m_FrameSpeed[nCnt].x /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_FrameSpeed[nCnt].y /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_FrameSpeed[nCnt].z /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			//回転の計算
			m_RotSpeed[nCnt] = (m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetKey(nCnt)->GetRot() - m_apModel[nCnt]->GetRot());
			m_RotSpeed[nCnt].x /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_RotSpeed[nCnt].y /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
			m_RotSpeed[nCnt].z /= (float)m_MotionSet[m_MotionType]->GetKeySet(NextKeySet)->GetFrame();
		}

		m_Frame = 0;						//フレームの初期化
		m_PresentKeySet = NextKeySet;
	}
}

//============================================
// モーションの種類の設定
//============================================
void CBoss::SetMotionType(MOTIONTYPE type)
{
	m_MotionType = type;
}

//============================================
// 位置の設定
//============================================
void CBoss::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//============================================
// 移動の設定
//============================================
void CBoss::SetMove(D3DXVECTOR3 move)
{
	move;
}

//============================================
// 長さの設定
//============================================
void CBoss::SetLength(float length)
{
	length;
}

//============================================
// 体力の設定
//============================================
void CBoss::SetLife(int life)
{
	m_nLife = life;
}

//============================================
// 位置の取得
//============================================
D3DXVECTOR3 CBoss::GetPos(void)
{
	return m_pos;
}

//============================================
// 移動の取得
//============================================
D3DXVECTOR3 CBoss::GetMove(void)
{
	return D3DXVECTOR3();
}

//============================================
// サイズの取得
//============================================
D3DXVECTOR3 CBoss::GetSize(void)
{
	return m_size;
}

//============================================
// 向きの取得
//============================================
D3DXVECTOR3 CBoss::GetRot(void)
{
	return m_rot;
}

//============================================
// 長さの取得
//============================================
float CBoss::GetLength(void)
{
	return 0.0f;
}

//============================================
// 体力の取得
//============================================
int CBoss::GetLife(void)
{
	return m_nLife;
}


