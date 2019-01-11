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


	case ESceneNumber::THIRDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::THIRDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove3(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::FORTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::FORTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove4(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::FIFTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::FIFTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove5(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	default:
		break;
	}
}


void Manager::Move4TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			move4str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			move4str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			move4str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			move4str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			move4str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			move4str[14] = "media\\こっち\\media\\街灯\\normal\\body_col.pyn";
			move4str[15] = "media\\こっち\\media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			move4str[22] = "media\\こっち\\media\\階段と床合体\\normal\\kaidan.pyn";
			move4str[23] = "media\\こっち\\media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			move4str[13] = "media\\こっち\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			move4str[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			move4str[16] = "media\\こっち\\media\\スカイボックス\\normal\\BlueSky.byn";

			// 精算機械テクスチャ
			move4str[18] = "media\\こっち\\media\\Terminal\\normal\\Terminal.pyn";
			move4str[19] = "media\\こっち\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;
		
	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			move4str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			move4str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			move4str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			move4str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			move4str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			move4str[14] = "media\\こっち\\media\\街灯\\P\\body_col.pyn";
			move4str[15] = "media\\こっち\\media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			move4str[22] = "media\\こっち\\media\\階段と床合体\\P\\kaidan.pyn";
			move4str[23] = "media\\こっち\\media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			move4str[13] = "media\\こっち\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			move4str[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			move4str[16] = "media\\こっち\\media\\スカイボックス\\P\\BlueSky.byn";

			// 精算機械テクスチャ
			move4str[18] = "media\\こっち\\media\\Terminal\\P\\Terminal.pyn";
			move4str[19] = "media\\こっち\\media\\Terminal\\P\\T_display.pyn";
		}
		break;

	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			move4str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			move4str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			move4str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			move4str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			move4str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			move4str[14] = "media\\こっち\\media\\街灯\\D\\body_col.pyn";
			move4str[15] = "media\\こっち\\media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			move4str[22] = "media\\こっち\\media\\階段と床合体\\D\\kaidan.pyn";
			move4str[23] = "media\\こっち\\media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			move4str[13] = "media\\こっち\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			move4str[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			move4str[16] = "media\\こっち\\media\\スカイボックス\\D\\BlueSky.byn";

			// 精算機械テクスチャ
			move4str[18] = "media\\こっち\\media\\Terminal\\D\\Terminal.pyn";
			move4str[19] = "media\\こっち\\media\\Terminal\\D\\T_display.pyn";
		}
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
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) */BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// テクスチャ切り替え
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// 白黒画像ではなかったらP型補正色に変える
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) */BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// テクスチャ切り替え
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// 白黒画像ではなかったらD型補正色に変える
			/*if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) */BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
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
			//p_baseMove->CameraProcess();		// カメラ切り替え
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			BASICPARAM::nowCameraOrtho = true;
			//p_baseMove->CameraProcess();		// カメラ切り替え
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
		if(optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}
	if (optionControllLeftStickY[0] == 1)
	{
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect) optionPageNowNumber = 0;
	}
	if (optionControllLeftStickY[1] == 1)
	{
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::Camera) optionPageNowNumber = 1;
	}
}


void Manager::OptionDraw()
{
	// 背景
	DrawGraph(0, 0, gaussianScreen, false);

	///　モデル表示-------------------------------------------------------------
	p_baseMove->OptionActorModel();

	DrawGraph(1600, 800, optionDrawMedia[static_cast<int>(EOptionDraw::optionEnd)], true);

	if (optionPageNowNumber == 0)
	{
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

		// 次のページ
		DrawGraph(96, 815, optionDrawMedia[static_cast<int>(EOptionDraw::nextPage)], false);
	}
	else if (optionPageNowNumber == 1)
	{
		// 前のページへ
		DrawGraph(96, 95, optionDrawMedia[static_cast<int>(EOptionDraw::prevPage)], false);

		/// カメラの関するオプション------------------------------------------------
		// カメラ
		DrawGraph(95, 247, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
		if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			DrawBox(95, 247, 95 + 109, 247 + 68, GetColor(255, 0, 0), false);
		}

		// 遠近法
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 267, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			DrawBox(385, 267, 385 + 83, 267 + 58, GetColor(255, 0, 0), false);
		}
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// 正射影
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 400, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			DrawBox(385, 400, 385 + 83, 400 + 58, GetColor(255, 0, 0), false);
		}
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// 横反転
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 513, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			DrawBox(385, 513, 385 + 83, 513 + 58, GetColor(255, 0, 0), false);
		}
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// 縦反転
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 646, optionDrawMedia[static_cast<int>(EOptionDraw::VerticalReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			DrawBox(385, 646, 385 + 83, 646 + 58, GetColor(255, 0, 0), false);
		}
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}


Manager::Manager()
{
	// 初期化
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;
	BASICPARAM::cameraHorizonReturn = false;
	BASICPARAM::cameraVerticalReturn = false;
	BASICPARAM::charaTextureWhiteBlack = true;
	BASICPARAM::enemyTextureWhiteBlack = true;
	BASICPARAM::lightStreetTextureWhiteBlack = true;
	BASICPARAM::stairsRoadTextureWhiteBlack = true;
	BASICPARAM::stairsTextureWhiteBlack = true;
	BASICPARAM::anothreTextureWhiteBlack = true;


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
	move2str[33] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\kaidan_yuka2D.pyn";

	// キャラクター周りの3DSE
	move2str[34] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
	move2str[35] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
	move2str[36] = "media\\こっち\\media\\sound\\足音.wyn";
	move2str[37] = "media\\こっち\\media\\sound\\着地.wyn";
	move2str[38] = "media\\こっち\\media\\sound\\着地２.wyn";

	// キャラクターの攻撃の音
	move2str[39] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
	move2str[40] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
	move2str[41] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

	// ドロップアイテムのSEの二種類目
	move2str[42] = "media\\こっち\\media\\sound\\たま拾う音2.wyn";

	// 次のステージでのBGMを流す
	move2str[43] = "media\\こっち\\media\\sound\\通常bgm.wyn";

	// 操作の説明
	move2str[44] = "media\\こっち\\media\\move2\\attackTrans.pyn";
	move2str[45] = "media\\こっち\\media\\move2\\jumpTrans.pyn";
	move2str[46] = "media\\こっち\\media\\move2\\fastSpeedTrans.pyn";
	move2str[47] = "media\\こっち\\media\\move2\\optionTrans.pyn";


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

	load2[19] = ELOADFILE::sound3DSource;

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

	load2[42] = ELOADFILE::sound3DSource;

	load2[43] = ELOADFILE::soundStream;

	load2[44] = ELOADFILE::graph;
	load2[45] = ELOADFILE::graph;
	load2[46] = ELOADFILE::graph;
	load2[47] = ELOADFILE::graph;
	/// ---------------------------------------------------------------------------------------------------


	/// ムーブ3のロード素材-------------------------------------------------
	// モデルデータ
	move3str[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
	move3str[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move3str[2] = "media\\こっち\\media\\paneru\\paneru.myn";
	move3str[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
	move3str[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
	move3str[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
	move3str[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
	move3str[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

	// キャラのテクスチャデータ
	move3str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move3str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move3str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move3str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move3str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// 階段のテクスチャデータ
	move3str[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// 街灯のテクスチャデータ
	move3str[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
	move3str[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

	// スカイボックスのテクスチャデータ
	move3str[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

	// サウンドデータ
	move3str[17] = "media\\こっち\\media\\sound\\たま拾う音.wyn";

	// 精算機械データ
	move3str[18] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

	// 精算機械テクスチャ
	move3str[19] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move3str[20] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

	// 精密機械の補助説明
	move3str[21] = "media\\こっち\\media\\Terminal\\push.pyn";

	// 階段とそのあとの床データ
	move3str[22] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

	// 階段とそのあとの床のテクスチャデータ
	move3str[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
	move3str[24] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

	// 階段と床のあたり判定データ
	move3str[25] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

	// キャラクター周りの3DSE
	move3str[26] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
	move3str[27] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
	move3str[28] = "media\\こっち\\media\\sound\\足音.wyn";
	move3str[29] = "media\\こっち\\media\\sound\\着地.wyn";
	move3str[30] = "media\\こっち\\media\\sound\\着地２.wyn";

	// キャラクターの攻撃の音
	move3str[31] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
	move3str[32] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
	move3str[33] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

	// ドロップアイテムのSEの二種類目
	move3str[34] = "media\\こっち\\media\\sound\\たま拾う音2.wyn";

	// BGM
	move3str[35] = "media\\こっち\\media\\sound\\通常bgm.wyn";

	// 敵のスライムのデータ
	move3str[36] = "media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.myn";
	move3str[37] = "media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn";

	// 敵のクレヨンヒューマンのデータ
	move3str[38] = "media\\こっち\\media\\move3\\人型クレヨン\\kureyon_,motionALL.myn";
	move3str[39] = "media\\こっち\\media\\move3\\人型クレヨン\\kureyon_,motionALL.fbm\\normal\\kre.pyn";

	// ドロップアイテムのデータ
	move3str[40] = "media\\こっち\\media\\move3\\インク的な\\ink.myn";
	move3str[41] = "media\\こっち\\media\\move3\\インク的な\\correction\\normal\\ink.pyn";

	// ダメージ演出画像
	move3str[42] = "media\\こっち\\media\\damage\\damage1\\whiteblack.pyn";
	move3str[43] = "media\\こっち\\media\\damage\\damage2\\whiteblack.pyn";
	move3str[44] = "media\\こっち\\media\\damage\\damage3\\whiteblack.pyn";
	move3str[45] = "media\\こっち\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
	move3str[46] = "media\\こっち\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
	move3str[47] = "media\\こっち\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
	move3str[48] = "media\\こっち\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
	move3str[49] = "media\\こっち\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
	move3str[50] = "media\\こっち\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
	move3str[51] = "media\\こっち\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
	move3str[52] = "media\\こっち\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
	move3str[53] = "media\\こっち\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
	move3str[54] = "media\\こっち\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

	// 敵の攻撃音
	move3str[55] = "media\\こっち\\media\\sound\\殴る音（爆発）.wyn";

	// クレヨンの死ぬ音
	move3str[56] = "media\\こっち\\media\\sound\\クレヨンの死(2).wyn";

	// 攻撃BGM
	move3str[57] = "media\\こっち\\media\\sound\\戦闘BGM.wyn";

	load3[0] = ELOADFILE::mv1model;
	load3[1] = ELOADFILE::mv1model;
	load3[2] = ELOADFILE::mv1model;
	load3[3] = ELOADFILE::mv1model;
	load3[4] = ELOADFILE::mv1model;
	load3[5] = ELOADFILE::mv1model;
	load3[6] = ELOADFILE::mv1model;
	load3[7] = ELOADFILE::mv1model;

	load3[8] = ELOADFILE::graph;
	load3[9] = ELOADFILE::graph;
	load3[10] = ELOADFILE::graph;
	load3[11] = ELOADFILE::graph;
	load3[12] = ELOADFILE::graph;

	load3[13] = ELOADFILE::graph;

	load3[14] = ELOADFILE::graph;
	load3[15] = ELOADFILE::graph;

	load3[16] = ELOADFILE::graph;

	load3[17] = ELOADFILE::sound3DSource;

	load3[18] = ELOADFILE::mv1model;

	load3[19] = ELOADFILE::graph;
	load3[20] = ELOADFILE::graph;

	load3[21] = ELOADFILE::graph;

	load3[22] = ELOADFILE::mv1model;

	load3[23] = ELOADFILE::graph;
	load3[24] = ELOADFILE::graph;

	load3[25] = ELOADFILE::mv1model;

	load3[26] = ELOADFILE::sound3DSource;
	load3[27] = ELOADFILE::sound3DSource;
	load3[28] = ELOADFILE::sound3DSource;
	load3[29] = ELOADFILE::sound3DSource;
	load3[30] = ELOADFILE::sound3DSource;

	load3[31] = ELOADFILE::sound3DSource;
	load3[32] = ELOADFILE::sound3DSource;
	load3[33] = ELOADFILE::sound3DSource;

	load3[34] = ELOADFILE::sound3DSource;

	load3[35] = ELOADFILE::soundStream;

	load3[36] = ELOADFILE::mv1model;
	load3[37] = ELOADFILE::graph;

	load3[38] = ELOADFILE::mv1model;
	load3[39] = ELOADFILE::graph;

	load3[40] = ELOADFILE::mv1model;
	load3[41] = ELOADFILE::graph;

	load3[42] = ELOADFILE::graph;
	load3[43] = ELOADFILE::graph;
	load3[44] = ELOADFILE::graph;
	load3[45] = ELOADFILE::graph;
	load3[46] = ELOADFILE::graph;
	load3[47] = ELOADFILE::graph;
	load3[48] = ELOADFILE::graph;
	load3[49] = ELOADFILE::graph;
	load3[50] = ELOADFILE::graph;
	load3[51] = ELOADFILE::graph;
	load3[52] = ELOADFILE::graph;
	load3[53] = ELOADFILE::graph;
	load3[54] = ELOADFILE::graph;

	load3[55] = ELOADFILE::sound3DSource;
	load3[56] = ELOADFILE::sound3DSource;

	load3[57] = ELOADFILE::soundStream;
	/// --------------------------------------------------------------------


	/// ムーブ4のロード素材-------------------------------------------------
	// モデルデータ
	move4str[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
	move4str[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move4str[2] = "media\\こっち\\media\\paneru\\paneru.myn";
	move4str[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
	move4str[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
	move4str[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
	move4str[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
	move4str[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

	// キャラのテクスチャデータ
	move4str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move4str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move4str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move4str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move4str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// 階段のテクスチャデータ
	move4str[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// 街灯のテクスチャデータ
	move4str[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
	move4str[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

	// スカイボックスのテクスチャデータ
	move4str[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

	// 精算機械データ
	move4str[17] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

	// 精算機械テクスチャ
	move4str[18] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move4str[19] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

	// 精密機械の補助説明
	move4str[20] = "media\\こっち\\media\\Terminal\\push.pyn";

	// 階段とそのあとの床データ
	move4str[21] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

	// 階段とそのあとの床のテクスチャデータ
	move4str[22] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
	move4str[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

	// 階段と床のあたり判定データ
	move4str[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

	// キャラクター周りの3DSE
	move4str[25] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
	move4str[26] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
	move4str[27] = "media\\こっち\\media\\sound\\足音.wyn";
	move4str[28] = "media\\こっち\\media\\sound\\着地.wyn";
	move4str[29] = "media\\こっち\\media\\sound\\着地２.wyn";

	// キャラクターの攻撃の音
	move4str[30] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
	move4str[31] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
	move4str[32] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

	// BGM
	move4str[33] = "media\\こっち\\media\\sound\\通常bgm.wyn";

	// 人のデータ
	move4str[34] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.myn";
	move4str[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

	load4[0] = ELOADFILE::mv1model;
	load4[1] = ELOADFILE::mv1model;
	load4[2] = ELOADFILE::mv1model;
	load4[3] = ELOADFILE::mv1model;
	load4[4] = ELOADFILE::mv1model;
	load4[5] = ELOADFILE::mv1model;
	load4[6] = ELOADFILE::mv1model;
	load4[7] = ELOADFILE::mv1model;

	load4[8] = ELOADFILE::graph;
	load4[9] = ELOADFILE::graph;
	load4[10] = ELOADFILE::graph;
	load4[11] = ELOADFILE::graph;
	load4[12] = ELOADFILE::graph;

	load4[13] = ELOADFILE::graph;

	load4[14] = ELOADFILE::graph;
	load4[15] = ELOADFILE::graph;

	load4[16] = ELOADFILE::graph;

	load4[17] = ELOADFILE::mv1model;

	load4[18] = ELOADFILE::graph;
	load4[19] = ELOADFILE::graph;

	load4[20] = ELOADFILE::graph;

	load4[21] = ELOADFILE::mv1model;

	load4[22] = ELOADFILE::graph;
	load4[23] = ELOADFILE::graph;

	load4[24] = ELOADFILE::mv1model;

	load4[25] = ELOADFILE::sound3DSource;
	load4[26] = ELOADFILE::sound3DSource;
	load4[27] = ELOADFILE::sound3DSource;
	load4[28] = ELOADFILE::sound3DSource;
	load4[29] = ELOADFILE::sound3DSource;

	load4[30] = ELOADFILE::sound3DSource;
	load4[31] = ELOADFILE::sound3DSource;
	load4[32] = ELOADFILE::sound3DSource;

	load4[33] = ELOADFILE::soundStream;

	load4[34] = ELOADFILE::mv1model;
	load4[35] = ELOADFILE::graph;
	/// --------------------------------------------------------------------


	/// ムーブ5のロード素材-------------------------------------------------
	// モデルデータ
	move5str[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
	move5str[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move5str[2] = "media\\こっち\\media\\paneru\\paneru.myn";
	move5str[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
	move5str[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
	move5str[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
	move5str[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
	move5str[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

	// キャラのテクスチャデータ
	move5str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move5str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move5str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move5str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move5str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// 階段のテクスチャデータ
	move5str[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// 街灯のテクスチャデータ
	move5str[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
	move5str[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

	// スカイボックスのテクスチャデータ
	move5str[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

	// 精算機械データ
	move5str[17] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

	// 精算機械テクスチャ
	move5str[18] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move5str[19] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

	// 精密機械の補助説明
	move5str[20] = "media\\こっち\\media\\Terminal\\push.pyn";

	// 階段とそのあとの床データ
	move5str[21] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

	// 階段とそのあとの床のテクスチャデータ
	move5str[22] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
	move5str[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

	// 階段と床のあたり判定データ
	move5str[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

	// キャラクター周りの3DSE
	move5str[25] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
	move5str[26] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
	move5str[27] = "media\\こっち\\media\\sound\\足音.wyn";
	move5str[28] = "media\\こっち\\media\\sound\\着地.wyn";
	move5str[29] = "media\\こっち\\media\\sound\\着地２.wyn";

	// キャラクターの攻撃の音
	move5str[30] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
	move5str[31] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
	move5str[32] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

	// BGM
	move5str[33] = "media\\こっち\\media\\sound\\通常bgm.wyn";

	load5[0] = ELOADFILE::mv1model;
	load5[1] = ELOADFILE::mv1model;
	load5[2] = ELOADFILE::mv1model;
	load5[3] = ELOADFILE::mv1model;
	load5[4] = ELOADFILE::mv1model;
	load5[5] = ELOADFILE::mv1model;
	load5[6] = ELOADFILE::mv1model;
	load5[7] = ELOADFILE::mv1model;

	load5[8] = ELOADFILE::graph;
	load5[9] = ELOADFILE::graph;
	load5[10] = ELOADFILE::graph;
	load5[11] = ELOADFILE::graph;
	load5[12] = ELOADFILE::graph;

	load5[13] = ELOADFILE::graph;

	load5[14] = ELOADFILE::graph;
	load5[15] = ELOADFILE::graph;

	load5[16] = ELOADFILE::graph;

	load5[17] = ELOADFILE::mv1model;

	load5[18] = ELOADFILE::graph;
	load5[19] = ELOADFILE::graph;

	load5[20] = ELOADFILE::graph;

	load5[21] = ELOADFILE::mv1model;

	load5[22] = ELOADFILE::graph;
	load5[23] = ELOADFILE::graph;

	load5[24] = ELOADFILE::mv1model;

	load5[25] = ELOADFILE::sound3DSource;
	load5[26] = ELOADFILE::sound3DSource;
	load5[27] = ELOADFILE::sound3DSource;
	load5[28] = ELOADFILE::sound3DSource;
	load5[29] = ELOADFILE::sound3DSource;

	load5[30] = ELOADFILE::sound3DSource;
	load5[31] = ELOADFILE::sound3DSource;
	load5[32] = ELOADFILE::sound3DSource;

	load5[33] = ELOADFILE::soundStream;
	/// --------------------------------------------------------------------


	// メモリの初期化
	p_baseMove = nullptr;
	p_loadThread = nullptr;


	// 最初のロードを生成
	p_loadThread = new LoadThread();

	// シーン開始なので
	preLoadScene = false;


	// 画面に関する
	gaussianScreen = MakeScreen(1920, 1080);


	// オプションに関する
	optionMenuNow = false;
	optionControllLeftStickY[0] = 0;
	optionControllLeftStickY[1] = 0;
	optionPageNowNumber = 0;
	optionSelectMin = 0;
	optionSelectMax = 2;
	seDoWaitTimer = 0;
	for (int i = 0; i != optionDrawNum; ++i)
	{
		optionDrawMedia[i] = -1;
	}
	LoadFile::MyLoad("media\\こっち\\media\\option\\BGM.pyn", optionDrawMedia[0], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\camera.pyn", optionDrawMedia[1], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\D型.pyn", optionDrawMedia[2], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\P型.pyn", optionDrawMedia[3], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\SE.pyn", optionDrawMedia[4], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\Sound.pyn", optionDrawMedia[5], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\遠近法.pyn", optionDrawMedia[6], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\色覚調整.pyn", optionDrawMedia[7], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\正射影.pyn", optionDrawMedia[8], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\通常色.pyn", optionDrawMedia[9], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\横反転.pyn", optionDrawMedia[10], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\縦反転.pyn", optionDrawMedia[11], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\nextPage.pyn", optionDrawMedia[12], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\prevPage.pyn", optionDrawMedia[13], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\optionEnd.pyn", optionDrawMedia[14], ELOADFILE::graph);

	// フェード処理に関する
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// アンチエイリアシングに関する
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4のアンチエイリアシングモードにする
	antiAliasScreen = MakeScreen(1920, 1080, false);	// アンチエイリアシング用の画面を作成
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
		// 三番目のムーブのロードだったら
		else if (BASICPARAM::e_preScene == ESceneNumber::THIRDLOAD)
		{
			p_loadThread->Process(max3, move3str, load3);		// ロードをする

			// ロードが終了したら
			if (p_loadThread->GetNum() >= max3)
			{
				BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
				preLoadScene = true;								// 直前がロードだったら
				BASICPARAM::e_nowScene = ESceneNumber::THIRDMOVE;	// 次のシーンを指定する
			}
		}
		// 四番目のムーブのロードだったら
		else if (BASICPARAM::e_preScene == ESceneNumber::FORTHLOAD)
		{
			p_loadThread->Process(max4, move4str, load4);		// ロードをする

			// ロードが終了したら
			if (p_loadThread->GetNum() >= max4)
			{
				BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
				preLoadScene = true;								// 直前がロードだったら
				BASICPARAM::e_nowScene = ESceneNumber::FORTHMOVE;	// 次のシーンを指定する
			}
		}
		// 五番目のムーブのロードだったら
		else if (BASICPARAM::e_preScene == ESceneNumber::FIFTHLOAD)
		{
			p_loadThread->Process(max5, move5str, load5);		// ロードをする

			// ロードが終了したら
			if (p_loadThread->GetNum() >= max5)
			{
				BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
				preLoadScene = true;								// 直前がロードだったら
				BASICPARAM::e_nowScene = ESceneNumber::FIFTHMOVE;	// 次のシーンを指定する
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

					// Effekseerにより再生中のエフェクトを描画する。
					DrawEffekseer3D();
					// Effekseerにより再生中のエフェクトを描画する。
					DrawEffekseer2D();

					BASICPARAM::e_nowScene = p_baseMove->GetScene();

					// アンチエイリアス画面に描画したものを裏画面に書き込む
					SetDrawScreen(DX_SCREEN_BACK);
					DrawGraph(0, 0, antiAliasScreen, false);

					// ゲームに関する
					p_baseMove->CameraProcess();				// SetDrawScreenを行うとカメラの設定がなくなるので再設定を行う
					p_baseMove->Process();

					// Effekseerにより再生中のエフェクトを更新する。
					UpdateEffekseer3D();
					// Effekseerにより再生中のエフェクトを更新する。
					UpdateEffekseer2D();

					// オプション画面に移行するコマンドを押されたら、またはウィンドウズが非アクティブになったら
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1
						|| !GetWindowActiveFlag())
					{
						// 現在の画面をキャプチャする
						GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);	

						// 現在の画面にガウスフィルタかけてぼかす
						GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);	


						// オプション用のモデル表示の準備
						p_baseMove->OptionActorModelBefore();
						

						// オプションメニューに移行するフラッグを立てる
						optionMenuNow = true;

						// オプションメニューのボタン位置を初期化
						optionSelectButtonNum = EOptionSelectButton::Sound;

						optionPageNowNumber = 0;


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
					p_baseMove->OptionActorModelAfter();
					p_baseMove->CameraProcess();			// カメラ切り替え
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
			if (BASICPARAM::e_preScene == ESceneNumber::THIRDMOVE)
			{
				Move4TextureReload();
			}

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
					// エフェクトを終了する
					DrawEffekseer2D_End();
					DrawEffekseer3D_End();


					// サウンドを解放する
					SoundProcess::Release();


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