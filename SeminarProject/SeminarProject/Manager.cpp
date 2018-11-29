#include "Manager.hpp"

void Manager::SceneChange()
{
	switch (BASICPARAM::e_nowScene)
	{
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		break;


	case ESceneNumber::FIRSTMOVE:
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::SECONDMOVE:
		p_baseMove = new MainMove2(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;

	default:
		break;
	}
}

Manager::Manager()
{
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;

	move1str[0] = "media\\ステージモデル\\move1_graphic.myn";
	move1str[1] = "media\\ステージモデル\\move1_hantei.myn";
	move1str[2] = "media\\CLPH\\motion\\CLPH_motionALL.myn";
	move1str[3] = "media\\剣\\sword.myn";
	move1str[4] = "media\\sound\\ノイズ(1).wyn";
	move1str[5] = "media\\sound\\玉がポーン（音が高いほう）.wyn";
	move1str[6] = "media\\sound\\玉がポーン.wyn";
	load1[0] = ELOADFILE::mv1model;
	load1[1] = ELOADFILE::mv1model;
	load1[2] = ELOADFILE::mv1model;
	load1[3] = ELOADFILE::mv1model;
	load1[4] = ELOADFILE::soundStream;
	load1[5] = ELOADFILE::soundmem;
	load1[6] = ELOADFILE::soundmem;

	move2str[0] = "media\\ステージモデル\\move1_hantei.myn";
	move2str[1] = "media\\swordCLPH\\clph_sword_all.myn";
	move2str[2] = "media\\paneru\\paneru.myn";
	move2str[3] = "media\\kaidan\\kaidan.myn";
	move2str[4] = "media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\街灯\\Gaitou.myn";
	move2str[6] = "media\\スカイボックス\\SkyDome.myn";
	move2str[7] = "media\\ブロック\\cubeblock.myn";
	move2str[8] = "media\\ステージモデル\\move1_graphic.myn";
	load2[0] = ELOADFILE::mv1model;
	load2[1] = ELOADFILE::mv1model;
	load2[2] = ELOADFILE::mv1model;
	load2[3] = ELOADFILE::mv1model;
	load2[4] = ELOADFILE::mv1model;
	load2[5] = ELOADFILE::mv1model;
	load2[6] = ELOADFILE::mv1model;
	load2[7] = ELOADFILE::mv1model;
	load2[8] = ELOADFILE::mv1model;


	p_baseMove = NULL;
	p_loadThread = NULL;

	p_loadThread = new LoadThread();


	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4のアンチエイリアシングモードにする
	antiAliasScreen = MakeScreen(1920, 1080, false);	// アンチエイリアシング用の画面を作成
	SetCreateDrawValidGraphMultiSample(0, 0);			// 元に戻す
}


Manager::~Manager()
{
	GRAPHIC_RELEASE(antiAliasScreen);
	POINTER_RELEASE(p_baseMove);
	POINTER_RELEASE(p_loadThread);
}

void Manager::Update()
{
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		// 今のシーンと直前のシーンが同じ
	{
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		// ロード中に変わった瞬間なら
		{
			p_loadThread->Process(max1, move1str, load1);		// ロードをする
			if (p_loadThread->GetNum() >= max1)		// ロードが終了したら
			{
				if (CheckHitKey(KEY_INPUT_Z) == 1)			// 終わったら一操作
				{
					BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;
				}
			}
		}
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ロードをする
			if (p_loadThread->GetNum() >= max2)		// ロードが終了したら
			{
				if (CheckHitKey(KEY_INPUT_Z) == 1)			// 終わったら一操作
				{
					BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;
				}
			}
		}
		else
		{
			// アンチエイリアス画面に対して描画処理を行う
			SetDrawScreen(antiAliasScreen);
			ClearDrawScreen();
			p_baseMove->CameraProcess();
			p_baseMove->Draw();
			p_baseMove->Process();
			BASICPARAM::e_nowScene = p_baseMove->GetScene();


			// アンチエイリアス画面に描画したものを裏画面に書き込む
			SetDrawScreen(DX_SCREEN_BACK);
			DrawGraph(0, 0, antiAliasScreen, false);
			p_baseMove->CameraProcess();				// SetDrawScreenを行うとカメラの設定がなくなるので再設定を行う
			ScreenFlip();
		}
	}
	else
	{
		SceneChange();
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}
