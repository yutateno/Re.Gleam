#include "Manager.hpp"

void Manager::SceneChange()
{
	switch (BASICPARAM::e_nowScene)
	{
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::FIRSTMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		for (int i = 0; i != optionDrawNum; ++i)
		{
			int temp = i + 14;
			optionDrawMedia[i] = p_loadThread->GetFile()[temp];
		}
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::SECONDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
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
	///-----------------------------------------------------------------------------------------------------------
	// 常時
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		// BGMバーの動きでサウンドのBGM音量を変更する
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
		// 61カウントのたびにSEを鳴らす
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
		}


		// SEバーの動きでサウンドのSE音量を変更する
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() < 1.00f ? SoundProcess::GetSEVolumeEntire() + 0.01f : SoundProcess::GetSEVolumeEntire());
		}
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() > 0.00f ? SoundProcess::GetSEVolumeEntire() - 0.01f : SoundProcess::GetSEVolumeEntire());
		}
	}
	///-----------------------------------------------------------------------------------------------------------


	///-----------------------------------------------------------------------------------------------------------
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
			// 白黒画像ではなかったら通常色に変える
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// テクスチャ切り替え
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// 白黒画像ではなかったらP型補正色に変える
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// テクスチャ切り替え
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// 白黒画像ではなかったらD型補正色に変える
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// テクスチャ切り替え
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect
			&& BASICPARAM::e_nowScene >= ESceneNumber::THIRDMOVE)
		{
			optionSelectButtonNum = EOptionSelectButton::ColorNormal;
			optionSelectMin = 5;
			optionSelectMax = 7;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			SoundProcess::SetOptionMenuNow(false);				// サウンドの音量をオプション用からやめる
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
		else if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			optionSelectButtonNum = EOptionSelectButton::CameraPerspective;
			optionSelectMin = 10;
			optionSelectMax = 13;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			BASICPARAM::nowCameraOrtho = false;
			p_baseMove->CameraProcess();		// カメラ切り替え
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			BASICPARAM::nowCameraOrtho = true;
			p_baseMove->CameraProcess();		// カメラ切り替え
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			BASICPARAM::cameraHorizonReturn = !BASICPARAM::cameraHorizonReturn;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			BASICPARAM::cameraVerticalReturn = !BASICPARAM::cameraVerticalReturn;
		}
	}
	///-----------------------------------------------------------------------------------------------------------


	///-----------------------------------------------------------------------------------------------------------
	// 戻るボタンを押したときの動作
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			SoundProcess::SetOptionMenuNow(true);					// サウンドの音量をオプション用からに戻す
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			SoundProcess::SetOptionMenuNow(true);					// サウンドの音量をオプション用からに戻す
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
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
	}
	///-----------------------------------------------------------------------------------------------------------


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
	// 背景
	DrawGraph(0, 0, gaussianScreen, false);

	///　モデル表示-------------------------------------------------------------
	p_baseMove->OptionActorModel();

	/// サウンド関係オプション-----------------------------------------------
	// UI:Sound
	DrawGraph(95, 95, optionDrawMedia[static_cast<int>(EOptionDraw::Sound)], false);
	if (optionSelectButtonNum == EOptionSelectButton::Sound)
	{
		DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(255, 0, 0), false);
	}

	// UI:BGM
	DrawGraph(381, 114, optionDrawMedia[static_cast<int>(EOptionDraw::BGM)], false);
	if (optionSelectButtonNum == EOptionSelectButton::BGM)
	{
		DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(255, 0, 0), false);
	}

	// UI:BGMバー
	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(200, 200, 200), true);
	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(255, 0, 0), false);
	}
	DrawBox(546 - 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 547)
		, 100 - 10, 546 + 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 548)
		, 100 + 81 + 10, GetColor(0, 125, 125), true);

	// UI:SE
	DrawGraph(385, 266, optionDrawMedia[static_cast<int>(EOptionDraw::SE)], false);
	if (optionSelectButtonNum == EOptionSelectButton::SE)
	{
		DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(255, 0, 0), false);
	}

	// UI:SEバー
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 0, 0), false);
	}
	DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
		, 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
		, 255 + 78 + 10, GetColor(0, 125, 125), true);


	/// 色覚に関するオプション----------------------------------------------
	// UI:色覚調整
	if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
	{
		DrawBox(96, 413, 96 + 112, 413 + 76, GetColor(255, 0, 0), false);
	}

	// UI:通常色
	DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
	{
		DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 0, 0), false);
	}

	// UI:P型
	DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorP)
	{
		DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 0, 0), false);
	}

	// UI:D型
	DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorD)
	{
		DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 0, 0), false);
	}
	if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


	/// カメラの関するオプション------------------------------------------------
	// カメラ
	DrawGraph(95, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
	if (optionSelectButtonNum == EOptionSelectButton::Camera)
	{
		DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(255, 0, 0), false);
	}

	// 遠近法
	if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(385, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
	{
		DrawBox(385, 843, 385 + 83, 843 + 58, GetColor(255, 0, 0), false);
	}
	if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// 正射影
	if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(385, 970, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
	{
		DrawBox(385, 970, 385 + 83, 970 + 58, GetColor(255, 0, 0), false);
	}
	if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// 横反転
	if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(568, 843, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
	{
		DrawBox(568, 843, 568 + 83, 843 + 58, GetColor(255, 0, 0), false);
	}
	if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// 縦反転
	if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(568, 970, optionDrawMedia[static_cast<int>(EOptionDraw::VerticalReturn)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
	{
		DrawBox(568, 970, 568 + 83, 970 + 58, GetColor(255, 0, 0), false);
	}
	if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


Manager::Manager()
{
	// 初期化
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;
	BASICPARAM::cameraHorizonReturn = true;
	BASICPARAM::cameraVerticalReturn = true;


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

	// コントローラー説明
	move1str[12] = "media\\こっち\\media\\move1\\hida.pyn";
	move1str[13] = "media\\こっち\\media\\move1\\mighi.pyn";

	// オプション用画像
	move1str[14] = "media\\こっち\\media\\option\\BGM.pyn";
	move1str[15] = "media\\こっち\\media\\option\\camera.pyn";
	move1str[16] = "media\\こっち\\media\\option\\D型.pyn";
	move1str[17] = "media\\こっち\\media\\option\\P型.pyn";
	move1str[18] = "media\\こっち\\media\\option\\SE.pyn";
	move1str[19] = "media\\こっち\\media\\option\\Sound.pyn";
	move1str[20] = "media\\こっち\\media\\option\\遠近法.pyn";
	move1str[21] = "media\\こっち\\media\\option\\色覚調整.pyn";
	move1str[22] = "media\\こっち\\media\\option\\正射影.pyn";
	move1str[23] = "media\\こっち\\media\\option\\通常色.pyn";
	move1str[24] = "media\\こっち\\media\\option\\横反転.pyn";
	move1str[25] = "media\\こっち\\media\\option\\縦反転.pyn";

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

	// コントローラー説明
	load1[12] = ELOADFILE::graph;
	load1[13] = ELOADFILE::graph;

	// オプション用画像
	load1[14] = ELOADFILE::graph;
	load1[15] = ELOADFILE::graph;
	load1[16] = ELOADFILE::graph;
	load1[17] = ELOADFILE::graph;
	load1[18] = ELOADFILE::graph;
	load1[19] = ELOADFILE::graph;
	load1[20] = ELOADFILE::graph;
	load1[21] = ELOADFILE::graph;
	load1[22] = ELOADFILE::graph;
	load1[23] = ELOADFILE::graph;
	load1[24] = ELOADFILE::graph;
	load1[25] = ELOADFILE::graph;
	/// ---------------------------------------------------------------------------------------------------


	/// シーン２の素材ファイル-----------------------------------------------------------------------------
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

	// 精算機械データ
	move2str[20] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

	// 精算機械テクスチャ
	move2str[21] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move2str[22] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

	// 精密機械の補助説明
	move2str[23] = "media\\こっち\\media\\Terminal\\push.pyn";

	// 階段とそのあとの床データ
	move2str[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

	// 階段とそのあとの床のテクスチャデータ
	move2str[25] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
	move2str[26] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

	// 階段と床のあたり判定データ
	move2str[27] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

	// 2D関連
	move2str[28] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\block_2D.pyn";
	move2str[29] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\CLPH_up.pyn";
	move2str[30] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\gaiyou_2D.pyn";
	move2str[31] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\kaidan_2d.pyn";
	move2str[32] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\Terminal_2D.pyn";
	move2str[33] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\yuka_2D.pyn";

	// キャラクター周りの3DSE
	move2str[34] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
	move2str[35] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
	move2str[36] = "media\\こっち\\media\\sound\\足音.wyn";
	move2str[37] = "media\\こっち\\media\\sound\\着地.wyn";
	move2str[38] = "media\\こっち\\media\\sound\\着地２.wyn";

	// キャラクターの攻撃の音
	move2str[39] = "media\\こっち\\media\\sound\\piano攻撃音1.wyn";
	move2str[40] = "media\\こっち\\media\\sound\\piano攻撃音2.wyn";
	move2str[41] = "media\\こっち\\media\\sound\\piano攻撃音3.wyn";


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

	load2[20] = ELOADFILE::mv1model;

	load2[21] = ELOADFILE::graph;
	load2[22] = ELOADFILE::graph;
	load2[23] = ELOADFILE::graph;

	load2[24] = ELOADFILE::mv1model;

	load2[25] = ELOADFILE::graph;
	load2[26] = ELOADFILE::graph;

	load2[27] = ELOADFILE::mv1model;

	load2[28] = ELOADFILE::graph;
	load2[29] = ELOADFILE::graph;
	load2[30] = ELOADFILE::graph;
	load2[31] = ELOADFILE::graph;
	load2[32] = ELOADFILE::graph;
	load2[33] = ELOADFILE::graph;

	load2[34] = ELOADFILE::sound3DSource;
	load2[35] = ELOADFILE::sound3DSource;
	load2[36] = ELOADFILE::sound3DSource;
	load2[37] = ELOADFILE::sound3DSource;
	load2[38] = ELOADFILE::sound3DSource;

	load2[39] = ELOADFILE::sound3DSource;
	load2[40] = ELOADFILE::sound3DSource;
	load2[41] = ELOADFILE::sound3DSource;
	/// ---------------------------------------------------------------------------------------------------


	// メモリの初期化
	p_baseMove = NULL;
	p_loadThread = NULL;


	// 最初のロードを生成
	p_loadThread = new LoadThread();

	// シーン開始なので
	preLoadScene = false;


	// 画面に関する
	gaussianScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight);


	// オプションに関する
	optionMenuNow = false;
	optionControllStick[0] = 0;
	optionControllStick[1] = 0;
	optionSelectMin = 0;
	optionSelectMax = 2;
	seDoWaitTimer = 0;
	for (int i = 0; i != optionDrawNum; ++i)
	{
		optionDrawMedia[i] = -1;
	}


	// フェード処理に関する
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// アンチエイリアシングに関する
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4のアンチエイリアシングモードにする
	antiAliasScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight, false);	// アンチエイリアシング用の画面を作成
	SetCreateDrawValidGraphMultiSample(0, 0);			// 元に戻す
}


Manager::~Manager()
{
	for (int i = 0; i != optionDrawNum; ++i)
	{
		GRAPHIC_RELEASE(optionDrawMedia[i]);
	}
	GRAPHIC_RELEASE(gaussianScreen);
	GRAPHIC_RELEASE(antiAliasScreen);
	POINTER_RELEASE(p_baseMove);
	POINTER_RELEASE(p_loadThread);
}

void Manager::Update()
{
	// 今のシーンと直前のシーンが同じ
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		
	{
		// 最初のムーブのロードだったら
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		
		{
			p_loadThread->Process(max1, move1str, load1);		// ロードをする

			// ロードが終了したら
			if (p_loadThread->GetNum() >= max1)		
			{
				BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
				preLoadScene = true;								// 直前がロードだったとする
				BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;	// 次のシーンを指定する
			}
		}
		// 二番目のムーブのロードだったら
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ロードをする

			// ロードが終了したら
			if (p_loadThread->GetNum() >= max2)		
			{
				BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
				preLoadScene = true;								// 直前がロードだったら
				BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;	// 次のシーンを指定する
			}
		}
		// ロードではなくゲームだったら
		else
		{
			preLoadScene = false;		// 直前がロードではないとする

			// オプションメニューでないとき
			if (!optionMenuNow)
			{
				// 開始フェードが終了していたら
				if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
				{
					// アンチエイリアス画面に対して描画処理を行う
					SetDrawScreen(antiAliasScreen);
					ClearDrawScreen();

					// ゲームに関する
					p_baseMove->CameraProcess();
					p_baseMove->Draw();
					BASICPARAM::e_nowScene = p_baseMove->GetScene();

					// アンチエイリアス画面に描画したものを裏画面に書き込む
					SetDrawScreen(DX_SCREEN_BACK);
					DrawGraph(0, 0, antiAliasScreen, false);

					// ゲームに関する
					p_baseMove->CameraProcess();				// SetDrawScreenを行うとカメラの設定がなくなるので再設定を行う
					p_baseMove->Process();


					// オプション画面に移行するコマンドを押されたら、またはウィンドウズが非アクティブになったら
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1
						|| !GetWindowActiveFlag())
					{
						// 現在の画面をキャプチャする
						GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);	

						// 現在の画面にガウスフィルタかけてぼかす
						GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);				
						

						// オプションメニューに移行するフラッグを立てる
						optionMenuNow = true;

						// オプションメニューのボタン位置を初期化
						optionSelectButtonNum = EOptionSelectButton::Sound;


						// サウンド音量をオプションメニュー用に下げるよう命令
						SoundProcess::SetOptionMenuNow(true);
					}

#ifdef _DEBUG
					MyDebug::DebugProcess();
#endif // _DEBUG


					ScreenFlip();
				}
				// 開始フェードが立っていたら
				else
				{
					// フェードカウントを下げる
					feedCount -= 5;				

					// 画面に関する一連
					ClearDrawScreen();
					SetDrawScreen(DX_SCREEN_BACK);

					// ゲームに関する一連
					p_baseMove->CameraProcess();
					p_baseMove->Draw();

					// フェードイン処理
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
					DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

					// フェードカウントが下がりまくったら開始フェードフラッグを下す
					if (feedCount <= 0)
					{
						feedCount = 0;
						BASICPARAM::startFeedNow = false;
					}

					ScreenFlip();
				}
			}
			// オプションメニューのとき
			else
			{
				// 画面に関する一連
				ClearDrawScreen();

				// オプションに関する
				OptionProcess();
				OptionDraw();

				// オプション画面から戻る
				if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
				{
					SoundProcess::SetOptionMenuNow(false);		// サウンド音量をオプション用から戻す
					optionMenuNow = false;
				}

				ScreenFlip();
			}
		}
	}
	// シーンを移行するように指定されたら
	else
	{
		// 現在のシーンの終了フェードが終わったら
		if (!BASICPARAM::endFeedNow)
		{
			// シーンを変える
			SceneChange();

			// 直前のシーンと今のシーンを同じにする
			BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
		}
		// 現在のシーンの終了フェードのとき
		else
		{
			// 終了シーンがロードではないとき
			if (!preLoadScene)
			{
				// サウンドを解放する
				SoundProcess::Release();

				
				// フェードを加算する
				feedCount += 5;


				// 画面に関する一連
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();

				// ゲームの描画に関するのだけを残してゲームに関するもの
				p_baseMove->CameraProcess();
				p_baseMove->Draw();

				// フェードアウト処理
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

				ScreenFlip();

				// フェードカウントが一定に達したらフラッグを下す
				if (feedCount >= 255)
				{
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			}
			// 終了シーンがロードのとき
			else
			{
				// サウンドを解放する
				SoundProcess::Release();


				// フェードを加算する
				feedCount += 15;


				// 画面に関する一連
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();

				// ゲームの描画に関するのだけを残してゲームに関するもの
				p_loadThread->Draw();

				// フェードアウト処理
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

				ScreenFlip();

				// フェードカウントが一定に達したらフラッグを下す
				if (feedCount >= 255)
				{
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			}
		}
	}
}