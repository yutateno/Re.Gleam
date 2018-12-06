#include "Manager.hpp"

void Manager::SceneChange()
{
	switch (BASICPARAM::e_nowScene)
	{
	case ESceneNumber::FIRSTLOAD:
		SoundProcess::Release();
		p_loadThread = new LoadThread();
		break;


	case ESceneNumber::FIRSTMOVE:
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::SECONDLOAD:
		SoundProcess::Release();
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


void Manager::OptionProcess()
{
	// 常時
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() < 1.00f ? SoundProcess::GetBGMVolumeEntire() + 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() > 0.00f ? SoundProcess::GetBGMVolumeEntire() - 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
	}
	else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
		}

		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() < 1.00f ? SoundProcess::GetSEVolumeEntire() + 0.01f : SoundProcess::GetSEVolumeEntire());
		}
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() > 0.00f ? SoundProcess::GetSEVolumeEntire() - 0.01f : SoundProcess::GetSEVolumeEntire());
		}
	}

	// 決定ボタンを押したときの動作
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			optionSelectButtonNum = EOptionSelectButton::BGMSelect;
			optionSelectMin = 8;
			optionSelectMax = 8;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			optionSelectButtonNum = EOptionSelectButton::SESelect;
			optionSelectMin = 9;
			optionSelectMax = 9;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK)*/ BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK)*/ BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK)*/ BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::Back)
		{
			SoundProcess::SetOptionMenuNow(false);
			optionMenuNow = false;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
		{
			optionSelectButtonNum = EOptionSelectButton::ColorNormal;
			optionSelectMin = 5;
			optionSelectMax = 7;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			SoundProcess::SetOptionMenuNow(false);
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
	}


	// 戻るボタンを押したときの動作
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			SoundProcess::SetOptionMenuNow(true);
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			SoundProcess::SetOptionMenuNow(true);
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		/*else if (optionSelectButtonNum == EOptionSelectButton::Back)
		{
			SoundProcess::SetOptionMenuNow(false);
			optionMenuNow = false;
		}*/
		/*else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
		{
			
		}*/
		/*else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{

		}*/
	}


	// スティックの一回押し倒しで更新するよう調整。
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if(optionControllStick[0] < 2) optionControllStick[0]++;
	}
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllStick[1] < 2) optionControllStick[1]++;
	}
	else
	{
		optionControllStick[0] = 0;
		optionControllStick[1] = 0;
	}
	if (optionControllStick[0] == 1)
	{
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
	}
	if (optionControllStick[1] == 1)
	{
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
	}
}


void Manager::OptionDraw()
{
	DrawGraph(0, 0, gaussianScreen, false);


	// 選択されるボタン(SEや通常やP型補正まわり)の座標
	const int selectLeftXArea = 385;
	const int selectRightXArea = selectLeftXArea + 83;


	/// サウンド関係オプション-----------------------------------------------

	DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(255, 255, 255), true);
	DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::Sound)
	{
		DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(255, 0, 0), true);
	}
	DrawFormatString(95, 95, 255, "サウンド調整");

	DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(255, 255, 255), true);
	DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::BGM)
	{
		DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(255, 0, 0), true);
	}
	DrawFormatString(381, 114, 255, "BGM");

	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(255, 255, 255), true);
	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(255, 0, 0), true);
	}
	DrawBox(546 - 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 547), 100 - 10, 546 + 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 548), 100 + 81 + 10, GetColor(0, 125, 125), true);
	DrawFormatString(546, 100, 255, "BGMバー");

	DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::SE)
	{
		DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(255, 0, 0), true);
	}
	DrawFormatString(385, 266, 255, "SE");

	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 255, 255), true);
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 0, 0), true);
	}
	DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547), 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547), 255 + 78 + 10, GetColor(0, 125, 125), true);
	DrawFormatString(548, 255, 255, "SEのバー");


	/// 色覚に関するオプション----------------------------------------------

	DrawBox(96, 413, 96 + 154, 413 + 76, GetColor(255, 255, 255), true);
	DrawBox(96, 413, 96 + 154, 413 + 76, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
	{
		DrawBox(96, 413, 96 + 154, 413 + 76, GetColor(255, 0, 0), true);
	}
	DrawFormatString(96, 413, 255, "色覚設定");

	DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
	{
		DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 0, 0), true);
	}
	DrawFormatString(385, 427, 255, "通常色");

	DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 255, 255), true);
	DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorP)
	{
		DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 0, 0), true);
	}
	DrawFormatString(386, 550, 255, "P型補正");

	DrawBox(559, 550, 559 + 269, 550 + 65, GetColor(255, 255, 255), true);
	DrawBox(559, 550, 559 + 269, 550 + 65, GetColor(0, 0, 0), false);
	DrawFormatString(559, 550, 255, "P型補足説明");

	DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorD)
	{
		DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 0, 0), true);
	}
	DrawFormatString(385, 682, 255, "D型補正");

	DrawBox(557, 681, 557 + 273, 681 + 60, GetColor(255, 255, 255), true);
	DrawBox(557, 681, 557 + 273, 681 + 60, GetColor(0, 0, 0), false);
	DrawFormatString(557, 681, 255, "D型補足説明");


	///　モデル表示-------------------------------------------------------------

	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(255, 255, 255), true);
	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(0, 0, 0), false);
	DrawFormatString(1252, 94, 255, "モデル");


	// 戻る

	DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(255, 255, 255), true);
	DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::Back)
	{
		DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(255, 0, 0), true);
	}
	DrawFormatString(95, 843, 255, "戻る");


	// debug
	DrawFormatString(0, 0, 255, "%d", optionSelectButtonNum);
}


Manager::Manager()
{
	// 初期化
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;


	/// シーン１の素材ファイル-----------------------------------------------------------------------------
	
	// モデルデータ
	move1str[0] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";
	move1str[1] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
	move1str[2] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.myn";				// 4
	move1str[3] = "media\\こっち\\media\\剣\\sword.myn";								// 1

	// サウンドデータ
	move1str[4] = "media\\こっち\\media\\sound\\タイトル（オルゴール）.wyn";
	move1str[5] = "media\\こっち\\media\\sound\\玉がポーン（音が高いほう）.wyn";
	move1str[6] = "media\\こっち\\media\\sound\\玉がポーン.wyn";

	// キャラクターのテクスチャデータ
	move1str[7] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
	move1str[8] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
	move1str[9] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
	move1str[10] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

	// 剣のテクスチャデータ
	move1str[11] = "media\\こっち\\media\\剣\\whiteblack\\sword_Tex.pyn";

	// モデルデータ
	load1[0] = ELOADFILE::mv1model;
	load1[1] = ELOADFILE::mv1model;
	load1[2] = ELOADFILE::mv1model;
	load1[3] = ELOADFILE::mv1model;

	// サウンドデータ
	load1[4] = ELOADFILE::soundStream;
	load1[5] = ELOADFILE::soundmem;
	load1[6] = ELOADFILE::soundmem;

	// キャラクターのテクスチャデータ
	load1[7] = ELOADFILE::graph;
	load1[8] = ELOADFILE::graph;
	load1[9] = ELOADFILE::graph;
	load1[10] = ELOADFILE::graph;

	// 剣のテクスチャデータ
	load1[11] = ELOADFILE::graph;
	/// ---------------------------------------------------------------------------------------------------


	/// シーン２の素材ファイル
	// モデルデータ
	move2str[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
	move2str[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move2str[2] = "media\\こっち\\media\\paneru\\paneru.myn";
	move2str[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
	move2str[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
	move2str[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
	move2str[7] = "media\\こっち\\media\\ブロック\\cubeblock.myn";					// 1
	move2str[8] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

	// キャラのテクスチャデータ
	move2str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move2str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move2str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move2str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move2str[13] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// 階段のテクスチャデータ
	move2str[14] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// 街灯のテクスチャデータ
	move2str[15] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
	move2str[16] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

	// スカイボックスのテクスチャデータ
	move2str[17] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

	// ブロックのテクスチャ
	move2str[18] = "media\\こっち\\media\\ブロック\\whiteblack\\tex.pyn";

	// サウンドデータ
	move2str[19] = "media\\こっち\\media\\sound\\たま拾う音.wyn";

	load2[0] = ELOADFILE::mv1model;
	load2[1] = ELOADFILE::mv1model;
	load2[2] = ELOADFILE::mv1model;
	load2[3] = ELOADFILE::mv1model;
	load2[4] = ELOADFILE::mv1model;
	load2[5] = ELOADFILE::mv1model;
	load2[6] = ELOADFILE::mv1model;
	load2[7] = ELOADFILE::mv1model;
	load2[8] = ELOADFILE::mv1model;

	load2[9] = ELOADFILE::graph;
	load2[10] = ELOADFILE::graph;
	load2[11] = ELOADFILE::graph;
	load2[12] = ELOADFILE::graph;
	load2[13] = ELOADFILE::graph;
	load2[14] = ELOADFILE::graph;
	load2[15] = ELOADFILE::graph;
	load2[16] = ELOADFILE::graph;
	load2[17] = ELOADFILE::graph;
	load2[18] = ELOADFILE::graph;

	load2[19] = ELOADFILE::soundmem;


	p_baseMove = NULL;
	p_loadThread = NULL;

	p_loadThread = new LoadThread();


	gaussianScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight);
	optionMenuNow = false;
	optionControllStick[0] = 0;
	optionControllStick[1] = 0;
	optionSelectMin = 0;
	optionSelectMax = 2;
	seDoWaitTimer = 0;


	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4のアンチエイリアシングモードにする
	antiAliasScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight, false);	// アンチエイリアシング用の画面を作成
	SetCreateDrawValidGraphMultiSample(0, 0);			// 元に戻す
}


Manager::~Manager()
{
	GRAPHIC_RELEASE(gaussianScreen);
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
				//if (CheckHitKey(KEY_INPUT_Z) == 1)			// 終わったら一操作
				//{
					BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;
				//}
			}
		}
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ロードをする
			if (p_loadThread->GetNum() >= max2)		// ロードが終了したら
			{
				//if (CheckHitKey(KEY_INPUT_Z) == 1)			// 終わったら一操作
				//{
					BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;
				//}
			}
		}
		else
		{
			if (!optionMenuNow)
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
				
				// オプション画面に移行する
				if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
				{
					GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);						// 現在の画面をキャプチャする
					GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 16, 1400);				// 現在の画面にガウスフィルタかけてぼかす
					optionMenuNow = true;
					optionSelectButtonNum = EOptionSelectButton::Sound;
					SoundProcess::SetOptionMenuNow(true);
				}
			}
			else
			{
				ClearDrawScreen();
				OptionProcess();
				OptionDraw();

				// オプション画面から戻る
				if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
				{
					SoundProcess::SetOptionMenuNow(false);
					optionMenuNow = false;
				}

				ScreenFlip();
			}
		}
	}
	else
	{
		SceneChange();
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}
