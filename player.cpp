//============================================
// 
// 	player.cpp
// 	Author: saito shian
// 
//============================================

//============================================
// インクルード
//============================================
#include <stdio.h>
#include <assert.h>
#include "player.h"
#include "renderer.h"
#include "object.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "debug.h"
#include "meshfield.h"
#include "game.h"
#include "modelparts.h"
#include "keyset.h"
#include "key.h"
#include "motionset.h"
#include "bullet.h"
#include "objectX.h"
#include "billboard.h"
#include "model.h"
#include "line.h"
#include "enemy.h"

//============================================
// 静的メンバ変数宣言
//============================================
D3DXVECTOR3 CPlayer::m_pos = {};
D3DXVECTOR3 CPlayer::m_rot = {};
bool CPlayer::m_PlayerAttackFlag = false;
CBullet *CPlayer::m_pBullet = nullptr;

//============================================
// オブジェクトのコンストラクタ
//============================================
CPlayer::CPlayer()
{
	//============================================
	// メンバ変数のクリア
	//============================================
	m_nCountModel = 0;
	m_Frame = 0;
}

//============================================
// オブジェクトのデストラクタ
//============================================
CPlayer::~CPlayer()
{
	//何も書かない
}

//============================================
// オブジェクト(ポリゴン)の初期化処理
//============================================
HRESULT CPlayer::Init(void)
{
	// ============================================
	// メンバ変数の初期化
	// ============================================
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//位置の初期化
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//向きの初期化
	m_size = D3DXVECTOR3(0.0f, 0.0f, 0.0f);						//サイズの初期化
	m_rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//目的の向きの初期化
	m_VtxMinModel = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//最小の初期化
	m_VtxMaxModel = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//最大の初期化
	m_nCountModel = 0;											//モデルカウントの初期化
	m_Frame = 0;												//フレーム数の初期化
	m_PresentKeySet = 0;										//前回のキーセットの初期化
	m_MotionType = MOTIONTYPE_NEUTRALMOTION;					//モーションの種類をニュートラルモーションに初期化
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)				
	{
		m_apModel[nCnt] = nullptr;								//モデル数の初期化
		m_FrameSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//フレームスピードの初期化
		m_RotSpeed[nCnt] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//回転スピードの初期化
	}

	//プレイヤーのファイル読み込み
	LoadPlayer();

	//最大最小
	Vtx();

	return S_OK;
}

//============================================
// オブジェクト(ポリゴン)の終了処理
//============================================
void CPlayer::Uninit(void)
{
	//モデルパーツの終了処理
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
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
void CPlayer::Update(void)
{
	//メッシュフィールドの情報
	CMeshField *pMeshField = CGame::GetMeshField();

	//プレイヤーの移動処理関数
	PlayerMove();

	//プレイヤーの攻撃処理関数
	PlayerAttack();

	//モーションの関数呼び出し
	MotionAnimation();

	//メッシュフィールドとプレイヤーの当たり判定
	pMeshField->GetMeshFieldCollision(&m_pos);

	for (int nCnt = 0; nCnt < NUMBER_OF_MODELS; nCnt++)
	{
		//モデルとの当たり判定
		CModelParts *pModelParts = CGame::GetModel()->GetModelParts()[nCnt];
		pModelParts->ModelCollision(&m_pos, &m_posOld, m_size);
	}

	//for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	//{
	//	//敵との当たり判定
	//	CEnemy *pEnemy = CGame::GetEnemy(nCnt);
	//	pEnemy->CollisionEnemy(&m_pos, &m_posOld, m_size);
	//}
}

//============================================
// オブジェクト(ポリゴン)の描画処理
//============================================
void CPlayer::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;		//計算用マトリックス

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);											//行列初期化関数(第一引数の行列を単位行列に初期化)

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);			//行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);						//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);				//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//モデルパーツのfor文
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
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
CPlayer * CPlayer::Create(const D3DXVECTOR3 &pos)
{
	CPlayer *pPlayer = nullptr;

	//プレイヤークラスの生成
	pPlayer = new CPlayer;				// 3Dオブジェクトのインスタンス生成

	// nullptrチェック
	if (pPlayer != nullptr)
	{
		// 初期化処理
		pPlayer->Init();
		pPlayer->SetPosition(pos);
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
void CPlayer::LoadPlayer()
{
	int nNumParts;							//モデルのパーツの変数
	int nCntMotionSet = 0;					//モーションセットのカウント
	int Loop = 0;							//ループをするのかの変数
	int nCntKeySet = 0;						//モーションセット数のカウント
	int nCntKey = 0;						//キーのカウント
	char aText[2000];						//文字列を格納する配列
	char FileName[MODEL_NUMBER][2000];		//2次元配列

	FILE *pFile; //ファイルポインタを宣言

	pFile = fopen("data/XMODEL/PlayerMotion.txt", "r");

	aText[0] = '\0';	//文字列なし

	if (pFile != nullptr)
	{//ファイルが開けた場合
	 //ファイルに入力したデータを書き出す処理
		while (strncmp(&aText[0], "SCRIPT", strlen("SCRIPT")) != 0)
		{//テキストの最初の行を読み込むまで繰り返す
			fgets(aText, MAX_WORD, pFile);        //一行ごと読み込む
		}

		while (strncmp(&aText[0], "END_SCRIPT", strlen("END_SCRIPT")) != 0)
		{//テキストの最後の行を読み込むまで繰り返す
			fscanf(pFile, "%s", &aText[0]);    //ファイルから文字列を読み込む(読み込み開始)

			if (strncmp(&aText[0], "#", strlen("#")) == 0)
			{
				fgets(aText, MAX_WORD, pFile);        //一行ごと読み込む
				continue;
			}

			//ファイルネームを複数個入力する
			if (strcmp(&aText[0], "MODEL_FILENAME") == 0)
			{
				fscanf(pFile, "%s", &aText[0]);        // = を読み込む
				fscanf(pFile, "%s", &FileName[m_nCountModel][0]);	//0番目から読み込まれる

				//モデルパーツの生成
				m_apModel[m_nCountModel] = CModelParts::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

				m_nCountModel++;
			}

			if (strcmp(&aText[0], "CHARACTERSET") == 0)
			{
				while (strcmp(&aText[0], "END_CHARACTERSET") != 0)
				{
					fscanf(pFile, "%s", &aText[0]);

					if (strncmp(&aText[0], "#", strlen("#")) == 0)
					{
						fgets(aText, MAX_WORD, pFile);        //一行ごと読み込む
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
								fgets(aText, MAX_WORD, pFile);        //一行ごと読み込む
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
						else if (IndexParent < MODEL_NUMBER)
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
								fgets(aText, MAX_WORD, pFile);        //一行ごと読み込む
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

				//モーションセットをインクリメント
				nCntMotionSet++;
				//モーションセット数の初期化
				nCntKeySet = 0;
				//キーカウントの初期化
				nCntKey = 0;
			}
		}
	}

	//ファイルを閉じる
	fclose(pFile);

	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		//nullチェック
		if (m_apModel[nCnt] != nullptr)
		{
			//posとrotの変数宣言
			D3DXVECTOR3 pos, rot;

			//現在使われているモーションの位置情報をposに代入
			pos = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetPos();

			//現在使われているモーションの向き情報をrotに代入
			rot = m_MotionSet[m_MotionType]->GetKeySet(1)->GetKey(nCnt)->GetRot();

			//モデルの位置と向きの設定
			m_apModel[nCnt]->SetPos(pos);
			m_apModel[nCnt]->SetRot(rot);
		}
	}
}

//============================================
// 頂点の最大最小
//============================================
void CPlayer::Vtx(void)
{
	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
	{
		int nNumVtx;	//頂点数
		DWORD sizeFVF;	//頂点フォーマットのサイズ
		BYTE *pVtxBuff;	//頂点バッファへのポインタ

		//頂点数の取得
		nNumVtx = m_apModel[nCnt]->GetMesh()->GetNumVertices();

		//頂点フォーマットのサイズを取得
		sizeFVF = D3DXGetFVFVertexSize(m_apModel[nCnt]->GetMesh()->GetFVF());

		//頂点バッファのロック
		m_apModel[nCnt]->GetMesh()->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

		D3DXVECTOR3 min = D3DXVECTOR3(100000.0f, 100000.0f, 100000.0f);
		D3DXVECTOR3 max = D3DXVECTOR3(-100000.0f, -100000.0f, -100000.0f);

		for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
		{
			//頂点座標の代入
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

			//頂点座標を比較してモデルの最小値、最大値を取得
			//xの比較
			if (vtx.x < min.x)
			{
				min.x = vtx.x;
			}
			if (vtx.x > max.x)
			{
				max.x = vtx.x;
			}

			//yの比較(最小値)
			if (vtx.y < min.y)
			{
				min.y = vtx.y;
			}
			if (vtx.y > max.y)
			{
				max.y = vtx.y;
			}

			//zの比較(最小値)
			if (vtx.z < min.z)
			{
				min.z = vtx.z;
			}
			if (vtx.z > max.z)
			{
				max.z = vtx.z;
			}
			//頂点フォーマットのサイズ分ポインタを進める
			pVtxBuff += sizeFVF;
		}

		//頂点バッファのアンロック
		m_apModel[nCnt]->GetMesh()->UnlockVertexBuffer();

		m_apModel[nCnt]->SetVtxMin(min);
		m_apModel[nCnt]->SetVtxMax(max);

		//プレイヤーサイズ
		m_size = D3DXVECTOR3(max.x - min.x, 0.0f, max.z - min.z);
	}
}

//============================================
// モーション関数
//============================================
void CPlayer::MotionAnimation(void)
{
	m_Frame++;		//フレームのインクリメント

	for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
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
			m_PresentKeySet = NextKeySet;	//次のアニメーションの最初のモーションセットを設定する
		}
		else if (NextKeySet >= m_MotionSet[m_MotionType]->GetNumKey() && m_MotionSet[m_MotionType]->GetLoop() == 0)
		{	//再生中のキー数カウントがキー数の最大値を超えたとき

			m_MotionSet[m_MotionType]->SetLoop(false);		//ループをfalseに設定する	
			m_MotionType = MOTIONTYPE_NEUTRALMOTION;		//モーションをニュートラルモーションにする
			NextKeySet = 0;									//次のキーセットの初期化
		}

		for (int nCnt = 0; nCnt < MODEL_NUMBER; nCnt++)
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
		m_PresentKeySet = NextKeySet;		//現在のモーションに次のモーションを代入
	}
}

//============================================
// プレイヤーの移動処理
//============================================
void CPlayer::PlayerMove(void)
{
	// インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	D3DXVECTOR3 CameraRot = CCamera::GetCameraRot();
	D3DXVECTOR3 PlayerRot = GetRot();

	//前回の位置を保存
	m_posOld = m_pos;

	if (m_PlayerAttackFlag == false)
	{
		// 上方向
		if (pInput->GetKeyboardPress(DIK_W) == true)
		{// Wキーが押された
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// 移動量
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					// 向く角度
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// 移動量
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					// 向く角度
			}
			else
			{
				m_pos.x += sinf(CameraRot.y) * PLAYER_MOVE;						// 移動量
				m_pos.z += cosf(CameraRot.y) * PLAYER_MOVE;						// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI);							// 向く角度
			}

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 下方向
		else if (pInput->GetKeyboardPress(DIK_S) == true)
		{// Sキーが押された
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// 移動量
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);					// 向く角度
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// 移動量
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);					// 向く角度
			}
			else
			{
				m_pos.x -= sinf(CameraRot.y) * PLAYER_MOVE;						// 移動量
				m_pos.z -= cosf(CameraRot.y) * PLAYER_MOVE;						// 移動量
				m_rotDest.y = CameraRot.y;										// 向く角度
			}

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 左方向
		else if (pInput->GetKeyboardPress(DIK_A) == true)
		{// Aキーが押された
			m_pos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// 移動量
			m_pos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// 移動量
			m_rotDest.y = (CameraRot.y + D3DX_PI / 2);							// 向く角度

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 右方向
		else if (pInput->GetKeyboardPress(DIK_D) == true)
		{// Dキーが押された
			m_pos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// 移動量
			m_pos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER_MOVE;			// 移動量
			m_rotDest.y = (CameraRot.y - D3DX_PI / 2);							// 向く角度

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
	}
	else if (m_PlayerAttackFlag == true)
	{
		// 上方向
		if (pInput->GetKeyboardPress(DIK_W) == true)
		{// Wキーが押された
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// 移動量
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.75f);					// 向く角度
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// 移動量
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.75f);					// 向く角度
			}
			else
			{
				m_pos.x += sinf(CameraRot.y) * PLAYER__ADS_MOVE;						// 移動量
				m_pos.z += cosf(CameraRot.y) * PLAYER__ADS_MOVE;						// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI);							// 向く角度
			}

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 下方向
		else if (pInput->GetKeyboardPress(DIK_S) == true)
		{// Sキーが押された
			if (pInput->GetKeyboardPress(DIK_A) == true)
			{
				m_pos.x -= sinf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// 移動量
				m_pos.z -= cosf(CameraRot.y + D3DX_PI * 0.25f) * PLAYER__ADS_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y + D3DX_PI * 0.25f);					// 向く角度
			}
			else if (pInput->GetKeyboardPress(DIK_D) == true)
			{
				m_pos.x += sinf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// 移動量
				m_pos.z += cosf(CameraRot.y + D3DX_PI * 0.75f) * PLAYER__ADS_MOVE;	// 移動量
				m_rotDest.y = (CameraRot.y - D3DX_PI * 0.25f);					// 向く角度
			}
			else
			{
				m_pos.x -= sinf(CameraRot.y) * PLAYER__ADS_MOVE;						// 移動量
				m_pos.z -= cosf(CameraRot.y) * PLAYER__ADS_MOVE;						// 移動量
				m_rotDest.y = CameraRot.y;										// 向く角度
			}

			//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 左方向
		else if (pInput->GetKeyboardPress(DIK_A) == true)
		{// Aキーが押された
			m_pos.x -= sinf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// 移動量
			m_pos.z -= cosf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// 移動量
			m_rotDest.y = (CameraRot.y + D3DX_PI / 2);							// 向く角度

																				//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
		// 右方向
		else if (pInput->GetKeyboardPress(DIK_D) == true)
		{// Dキーが押された
			m_pos.x += sinf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// 移動量
			m_pos.z += cosf(CameraRot.y + D3DX_PI / 2) * PLAYER__ADS_MOVE;			// 移動量
			m_rotDest.y = (CameraRot.y - D3DX_PI / 2);							// 向く角度

																				//移動モーションの設定
			SetMotionType(CPlayer::MOTIONTYPE_MOVE);
		}
	}

	//============================================
	//	モーションの設定
	//============================================
	if (pInput->GetKeyboardPress(DIK_W) == false && pInput->GetKeyboardPress(DIK_A) == false
		&& pInput->GetKeyboardPress(DIK_S) == false && pInput->GetKeyboardPress(DIK_D) == false
		&& pInput->GetKeyboardPress(DIK_LSHIFT) == false)
	{
		//ニュートラルモーションの設定
		SetMotionType(CPlayer::MOTIONTYPE_NEUTRALMOTION);
	}

	//============================================
	//  目的の角度の正規化
	//============================================
	if (m_rotDest.y - PlayerRot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - PlayerRot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	if (pInput->GetKeyboardPress(DIK_LSHIFT) == false)
	{
		// 角度慣性
		PlayerRot += (m_rotDest - PlayerRot) * 0.1f;
	}

	//============================================
	//  角度の正規化
	//============================================
	if (PlayerRot.y > D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y - D3DX_PI * 2;
	}
	else if (PlayerRot.y < -D3DX_PI)
	{
		PlayerRot.y = PlayerRot.y + D3DX_PI * 2;
	}
	//向きの設定
	m_rot = PlayerRot;
	//デバック表示
	CDebugProc::Print("プレイヤーの向いてる角度:%f\nプレイヤーの高さ:%.2f\nプレイヤーのX位置:%f\nプレイヤーのZ位置:%f\n", PlayerRot.y, m_pos.y, m_pos.x, m_pos.z);
}

//============================================
// プレイヤーの攻撃処理
//============================================
void CPlayer::PlayerAttack(void)
{
	//インプットのインスタンス生成
	CInput *pInput = CApplication::GetInput();
	//プレイヤーの位置取得
	D3DXVECTOR3 PlayerPos = GetPos();
	//カメラの向きの取得
	D3DXVECTOR3 CameraRot = CApplication::GetCamera()->GetCameraRot();

	//============================================
	//	プレイヤーの攻撃処理
	//============================================
	//spaceキーが押された
	if (pInput->GetKeyboardPress(DIK_LSHIFT) == true)
	{
		//プレイヤーが攻撃態勢に入った
		m_PlayerAttackFlag = true;

		//エイムした時のカメラの位置の設定
		CApplication::GetCamera()->SetOffset(D3DXVECTOR3(-20.0f, 45.0f, 40.0f), D3DXVECTOR3(0.0f, 0.0f, -100.0f));

		//============================================
		//	攻撃処理
		//============================================
		if (pInput->GetKeyboardTrigger(DIK_RETURN) == true)
		{	//LSHIFT押し続けているとき && ENTERを押したとき

			//攻撃モーションに設定
			SetMotionType(MOTIONTYPE_ATTACK);

			//弾の生成
			m_pBullet = CBullet::Create(D3DXVECTOR3(m_pos.x, 32.0f, m_pos.z), D3DXVECTOR3(-sinf(m_rot.y) * 15.0f, sinf(m_rot.x) * 15.0f, -cosf(m_rot.y) * 15.0f), 20);
		}

		//============================================
		//	エイムの向きを変える処理
		//============================================
		if (pInput->GetKeyboardPress(DIK_UP) == true)
		{	//UPキーを押しているとき

			m_rot.x += 0.01f;			//プレイヤーの上方向の加算
			CameraRot.x += 0.01f;		//カメラの上方向の加算

			if (CameraRot.x >= 0.3f)
			{	//カメラが向ける範囲

				CameraRot.x = 0.3f;		//カメラの固定
			}
		}
		if (pInput->GetKeyboardPress(DIK_DOWN) == true)
		{	//DOWNキーを押しているとき

			m_rot.x -= 0.01f;			//プレイヤーの下方向の加算
			CameraRot.x -= 0.01f;		//カメラの下方向の加算

			if (CameraRot.x <= -0.3f)
			{	//カメラが向ける範囲

				CameraRot.x = -0.3f;	//カメラの固定
			}
		}
		if (pInput->GetKeyboardPress(DIK_LEFT) == true)
		{	//LEFTキーを押しているとき

			m_rot.y -= 0.01f;			//プレイヤーの左方向の加算
			CameraRot.y -= 0.01f;		//カメラの左方向の加算
		}	
		if (pInput->GetKeyboardPress(DIK_RIGHT) == true)
		{	//RIGHTキーを押しているとき

			m_rot.y += 0.01f;			//プレイヤーの右方向の加算
			CameraRot.y += 0.01f;		//カメラの右方向の加算
		}

		//============================================
		//  角度の正規化
		//============================================
		if (CameraRot.y > D3DX_PI)
		{
			CameraRot.y = CameraRot.y - D3DX_PI * 2;
		}
		else if (CameraRot.y < -D3DX_PI)
		{
			CameraRot.y = CameraRot.y + D3DX_PI * 2;
		}

		//プレイヤーの向きの保存
		SetRot(m_rot);

		//攻撃待機モーションに設定
		SetMotionType(MOTIONTYPE_STANDBYATTACK);
	}
	//LSHIFT押していないとき && プレイヤーが攻撃態勢になっているとき
	else if (pInput->GetKeyboardPress(DIK_LSHIFT) == false && m_PlayerAttackFlag == true)
	{
		//プレイヤーが攻撃体制をやめた
		m_PlayerAttackFlag = false;
		//プレイヤーの向きの取得
		m_rot = GetRot();
		//プレイヤーの向きの設定
		SetRot(m_rot);
		//カメラの向きの設定
		CApplication::GetCamera()->SetOffset(D3DXVECTOR3(0.0f, 75.0f, 150.0f),D3DXVECTOR3(0.0f, 0.0f, -100.0f));
	}

	//カメラの向きの設定
	CApplication::GetCamera()->SetRot(CameraRot);
}

//============================================
// プレイヤーの当たり判定
//============================================
void CPlayer::CollisionPlayer(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 size)
{
	//左の当たり判定
	if (pPos->z - size.z / 2.0f < m_pos.z + m_VtxMaxModel.z
		&& pPos->z + size.z / 2.0f > m_pos.z + m_VtxMinModel.z
		&&pPosOld->x <= m_pos.x + m_VtxMinModel.x - size.x / 2.0f
		&&pPos->x > m_pos.x + m_VtxMinModel.x - size.x / 2.0f)
	{
		pPos->x = m_pos.x + m_VtxMinModel.x - size.x / 2.0f;
	}

	//右の当たり判定
	if (pPos->z - size.z / 2.0f < m_pos.z + m_VtxMaxModel.z
		&& pPos->z + size.z / 2.0f > m_pos.z + m_VtxMinModel.z
		&&pPosOld->x >= m_pos.x + m_VtxMaxModel.x + size.x / 2.0f
		&&pPos->x < m_pos.x + m_VtxMaxModel.x + size.x / 2.0f)
	{
		pPos->x = m_pos.x + m_VtxMaxModel.x + size.x / 2.0f;
	}

	//手前の当たり判定
	if (pPos->x - size.x / 2.0f < m_pos.x + m_VtxMaxModel.x
		&& pPos->x + size.x / 2.0f > m_pos.x + m_VtxMinModel.x
		&&pPosOld->z <= m_pos.z + m_VtxMinModel.z - size.z / 2.0f
		&&pPos->z > m_pos.z + m_VtxMinModel.z - size.z / 2.0f)
	{
		pPos->z = m_pos.z + m_VtxMinModel.z - size.z / 2.0f;
	}

	//奥の当たり判定
	if (pPos->x - size.x / 2.0f < m_pos.x + m_VtxMaxModel.x
		&& pPos->x + size.x / 2.0f > m_pos.x + m_VtxMinModel.x
		&&pPosOld->z >= m_pos.z + m_VtxMaxModel.z + size.z / 2.0f
		&&pPos->z < m_pos.z + m_VtxMaxModel.z + size.z / 2.0f)
	{
		pPos->z = m_pos.z + m_VtxMinModel.z + size.z / 2.0f;
	}
}

//============================================
// モーションの種類の設定
//============================================
void CPlayer::SetMotionType(MOTIONTYPE type)
{
	m_MotionType = type;
}

//============================================
// 位置の設定
//============================================
void CPlayer::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

//============================================
// 向きの設定
//============================================
void CPlayer::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;
}

//============================================
// 移動の設定
//============================================
void CPlayer::SetMove(D3DXVECTOR3 move)
{
	move;
}

//============================================
// 長さの設定
//============================================
void CPlayer::SetLength(float length)
{
	length;
}

//============================================
// 位置の取得
//============================================
D3DXVECTOR3 CPlayer::GetPos(void)
{
	return m_pos;
}

//============================================
// 移動の取得
//============================================
D3DXVECTOR3 CPlayer::GetMove(void)
{
	return D3DXVECTOR3();
}

//============================================
// サイズの取得
//============================================
D3DXVECTOR3 CPlayer::GetSize(void)
{
	return D3DXVECTOR3();
}

//============================================
// 向きの取得
//============================================
D3DXVECTOR3 CPlayer::GetRot(void)
{
	return m_rot;
}

//============================================
// 長さの取得
//============================================
float CPlayer::GetLength(void)
{
	return 0.0f;
}