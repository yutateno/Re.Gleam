#include "Manager.hpp"



/// --------------------------------------------------------------------------------------------------
void Manager::SceneChange()
{
	// 今のシーン
	switch (BASICPARAM::e_nowScene)
	{
	// ムーブ1のロード
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ムーブ1
	case ESceneNumber::FIRSTMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;


	// ムーブ2のロード
	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ムーブ2
	case ESceneNumber::SECONDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove2(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;


	// ムーブ3のロード
	case ESceneNumber::THIRDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ムーブ3
	case ESceneNumber::THIRDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove3(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;


	// ムーブ4のロード
	case ESceneNumber::FOURTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ムーブ4
	case ESceneNumber::FOURTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove4(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;


	// ムーブ5のロード
	case ESceneNumber::FIFTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ムーブ5
	case ESceneNumber::FIFTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove5(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;



		// ムーブ6のロード
	case ESceneNumber::SIXLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


		// ムーブ6
	case ESceneNumber::SIXMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove6(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		moveStr.clear();
		moveStr.shrink_to_fit();
		loadType.clear();
		loadType.shrink_to_fit();
		LoadFile::MyLoad("media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;


	default:
		break;
	} /// switch (BASICPARAM::e_nowScene)
} /// void Manager::SceneChange()



/// --------------------------------------------------------------------------------------------------
void Manager::TitleProcess()
{
	// 決定を押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// ゲームを開始するの時
		if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::firstGame))
		{
			BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
			BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
			optionSelectMin = 0;
			optionSelectMax = 4;
			gameFirstStarting = false;
		} /// if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::firstGame))
		// ロードするとき
		else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::load))
		{
			// ムーブが3以降だったらテクスチャの色を通常色にしておく
			if (BASICPARAM::e_nowScene >= ESceneNumber::THIRDLOAD)
			{
				BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			}


			optionSelectMin = 0;
			optionSelectMax = 4;
			gameFirstStarting = false;
		} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::load))
		// ゲームを終了するとき
		else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
		{
			gameEnd = true;
		} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
		// おまけのとき
		else
		{
			// ムーブ２を選択していたら
			if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove2))
			{
				BASICPARAM::e_nowScene = ESceneNumber::SECONDLOAD;
				BASICPARAM::e_preScene = ESceneNumber::SECONDLOAD;
			}
			// ムーブ３を選択していたら
			else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove3))
			{
				BASICPARAM::stairsNum = 0;
				BASICPARAM::streetLightNum = 0;
				BASICPARAM::stairsRoadNum = 0;
				BASICPARAM::v_stairsArea.clear();
				BASICPARAM::v_stairsAngle.clear();
				BASICPARAM::v_streetLightArea.clear();
				BASICPARAM::v_streetLightAngle.clear();
				BASICPARAM::v_stairsRoadArea.clear();
				BASICPARAM::v_stairsRoadAngle.clear();

				BASICPARAM::e_TextureColor = ETextureColor::NORMAL;

				BASICPARAM::e_nowScene = ESceneNumber::THIRDLOAD;
				BASICPARAM::e_preScene = ESceneNumber::THIRDLOAD;
			}
			// ムーブ４を選択していたら
			else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove4))
			{
				BASICPARAM::stairsNum = 0;
				BASICPARAM::streetLightNum = 0;
				BASICPARAM::stairsRoadNum = 0;
				BASICPARAM::v_stairsArea.clear();
				BASICPARAM::v_stairsAngle.clear();
				BASICPARAM::v_streetLightArea.clear();
				BASICPARAM::v_streetLightAngle.clear();
				BASICPARAM::v_stairsRoadArea.clear();
				BASICPARAM::v_stairsRoadAngle.clear();

				BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
				BASICPARAM::charaTextureWhiteBlack = true;
				BASICPARAM::anothreTextureWhiteBlack = true;
				BASICPARAM::enemyTextureWhiteBlack = true;
				BASICPARAM::lightStreetTextureWhiteBlack = true;
				BASICPARAM::stairsRoadTextureWhiteBlack = true;
				BASICPARAM::stairsTextureWhiteBlack = true;

				BASICPARAM::e_nowScene = ESceneNumber::FOURTHLOAD;
				BASICPARAM::e_preScene = ESceneNumber::FOURTHLOAD;
			}
			// ムーブ５を選択していたら
			else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove5))
			{
				BASICPARAM::stairsNum = 0;
				BASICPARAM::streetLightNum = 0;
				BASICPARAM::stairsRoadNum = 0;
				BASICPARAM::v_stairsArea.clear();
				BASICPARAM::v_stairsAngle.clear();
				BASICPARAM::v_streetLightArea.clear();
				BASICPARAM::v_streetLightAngle.clear();
				BASICPARAM::v_stairsRoadArea.clear();
				BASICPARAM::v_stairsRoadAngle.clear();

				BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
				BASICPARAM::charaTextureWhiteBlack = true;
				BASICPARAM::anothreTextureWhiteBlack = true;
				BASICPARAM::enemyTextureWhiteBlack = true;
				BASICPARAM::lightStreetTextureWhiteBlack = true;
				BASICPARAM::stairsRoadTextureWhiteBlack = true;
				BASICPARAM::stairsTextureWhiteBlack = true;

				BASICPARAM::ordinaryPeopleNum = 0;

				BASICPARAM::e_nowScene = ESceneNumber::FIFTHLOAD;
				BASICPARAM::e_preScene = ESceneNumber::FIFTHLOAD;
			}
			// ムーブ６を選択していたら
			else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove6))
			{
				BASICPARAM::stairsNum = 0;
				BASICPARAM::streetLightNum = 0;
				BASICPARAM::stairsRoadNum = 0;
				BASICPARAM::v_stairsArea.clear();
				BASICPARAM::v_stairsAngle.clear();
				BASICPARAM::v_streetLightArea.clear();
				BASICPARAM::v_streetLightAngle.clear();
				BASICPARAM::v_stairsRoadArea.clear();
				BASICPARAM::v_stairsRoadAngle.clear();

				BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
				BASICPARAM::charaTextureWhiteBlack = true;
				BASICPARAM::anothreTextureWhiteBlack = true;
				BASICPARAM::enemyTextureWhiteBlack = true;
				BASICPARAM::lightStreetTextureWhiteBlack = true;
				BASICPARAM::stairsRoadTextureWhiteBlack = true;
				BASICPARAM::stairsTextureWhiteBlack = true;

				BASICPARAM::ordinaryPeopleNum = 0;

				BASICPARAM::lastCharaView = false;
				BASICPARAM::lastOrdinaryView = false;
				BASICPARAM::lastPaneruView = false;
				BASICPARAM::lastStairsRoadView = false;
				BASICPARAM::lastStairsView = false;
				BASICPARAM::lastStreetLightView = false;
				BASICPARAM::e_nowScene = ESceneNumber::SIXLOAD;
				BASICPARAM::e_preScene = ESceneNumber::SIXLOAD;
			} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove6))


			optionSelectMin = 0;
			optionSelectMax = 4;
			gameFirstStarting = false;
		} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonus))
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// LBとRBとBACKとXボタンを同時に押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		// おまけコマンドを出す
		playBonus = true;
		optionSelectMax = 8;
	}


	/// スティックの一回押し倒しで更新するよう調整-----------------------------------------------------------------
	// 左スティックを上に倒したら
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if (optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	// 左スティックを下に倒したら
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	// 左スティックを特に弄ってなかったら
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}


	// 上にスティックを倒したとき
	if (optionControllLeftStickY[0] == 1)
	{
		// カーソルを上に移動する
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
	}
	// 下にスティックを倒したとき
	if (optionControllLeftStickY[1] == 1)
	{
		// カーソルを下に移動する
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
	}
	/// スティックの一回押し倒しで更新するよう調整-----------------------------------------------------------------
} /// void Manager::TitleProcess()



/// --------------------------------------------------------------------------------------------------
void Manager::TitleDraw()
{
	// ゲーム開始
	DrawGraph(760, 340, titleUIDraw[static_cast<int>(ETitleDraw::firstGame)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::firstGame))
	{
		DrawBox(760 + 5, 340 + 5, 760 + 400 - 5, 340 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 340 + 4, 760 + 400 - 4, 340 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 340 + 3, 760 + 400 - 3, 340 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// ロード
	DrawGraph(760, 471, titleUIDraw[static_cast<int>(ETitleDraw::load)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::load))
	{
		DrawBox(760 + 5, 471 + 5, 760 + 400 - 5, 471 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 471 + 4, 760 + 400 - 4, 471 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 471 + 3, 760 + 400 - 3, 471 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// ゲーム終了
	DrawGraph(760, 600, titleUIDraw[static_cast<int>(ETitleDraw::gameEnd)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
	{
		DrawBox(760 + 5, 600 + 5, 760 + 400 - 5, 600 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 600 + 4, 760 + 400 - 4, 600 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 600 + 3, 760 + 400 - 3, 600 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// おまけコマンドを打っていたら
	if (playBonus)
	{
		// おまけ
		DrawGraph(760, 730, titleUIDraw[static_cast<int>(optionSelectButtonNum)], false);
		if (optionSelectButtonNum >= static_cast<EOptionSelectButton>(ETitleDraw::bonus))
		{
			DrawBox(760 + 5, 730 + 5, 760 + 400 - 5, 730 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(760 + 4, 730 + 4, 760 + 400 - 4, 730 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(760 + 3, 730 + 3, 760 + 400 - 3, 730 + 69 - 3, GetColor(50, 50, 200), false);
		}
	}
} /// void Manager::TitleDraw()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove1Load()
{
	moveStr.resize(max1 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_graphic.myn";
		moveStr[1] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[2] = "media\\CLPH\\motion\\CLPH_motionALL.myn";
		moveStr[3] = "media\\剣\\sword.myn";

		// サウンドデータ
		moveStr[4] = "media\\sound\\タイトル（オルゴール）.wyn";
		moveStr[5] = "media\\sound\\玉がポーン（音が高いほう）.wyn";
		moveStr[6] = "media\\sound\\玉がポーン.wyn";

		// キャラクターのテクスチャデータ
		moveStr[7] = "media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[8] = "media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
		moveStr[9] = "media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[10] = "media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

		// 剣のテクスチャデータ
		moveStr[11] = "media\\剣\\whiteblack\\sword_Tex.pyn";

		// コントローラー説明
		moveStr[12] = "media\\move1\\hida.pyn";
		moveStr[13] = "media\\move1\\mighi.pyn";

		// ムーブ説明画像
		moveStr[14] = "media\\ムーブ説明\\move1.pyn";
	}


	loadType.resize(max1 + 1);
	{
		// モデルデータ
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;

		// サウンドデータ
		loadType[4] = ELOADFILE::soundStream;
		loadType[5] = ELOADFILE::soundmem;
		loadType[6] = ELOADFILE::soundmem;

		// キャラクターのテクスチャデータ
		loadType[7] = ELOADFILE::graph;
		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;

		// 剣のテクスチャデータ
		loadType[11] = ELOADFILE::graph;

		// コントローラー説明
		loadType[12] = ELOADFILE::graph;
		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
	}
} /// void Manager::InitMove1Load()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove2Load()
{
	moveStr.resize(max2 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\swordCLPH\\clph_sword_all.myn";
		moveStr[2] = "media\\paneru\\paneru.myn";
		moveStr[3] = "media\\kaidan\\kaidan.myn";		
		moveStr[4] = "media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\街灯\\Gaitou.myn";	
		moveStr[6] = "media\\スカイボックス\\SkyDome.myn";	
		moveStr[7] = "media\\ブロック\\cubeblock.myn";
		moveStr[8] = "media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[13] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[14] = "media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[15] = "media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[16] = "media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[17] = "media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// ブロックのテクスチャ
		moveStr[18] = "media\\ブロック\\whiteblack\\tex.pyn";

		// サウンドデータ
		moveStr[19] = "media\\sound\\たま拾う音.wyn";

		// 精算機械データ
		moveStr[20] = "media\\Terminal\\terminal.myn";

		// 精算機械テクスチャ
		moveStr[21] = "media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[22] = "media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[23] = "media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[24] = "media\\階段と床合体\\kaidan_yuka1.myn";

		// 階段とそのあとの床のテクスチャデータ
		moveStr[25] = "media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[26] = "media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[27] = "media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// 2D関連
		moveStr[28] = "media\\2D素材\\change\\whiteblack\\block_2D.pyn";
		moveStr[29] = "media\\2D素材\\change\\whiteblack\\CLPH_up.pyn";
		moveStr[30] = "media\\2D素材\\change\\whiteblack\\gaiyou_2D.pyn";
		moveStr[31] = "media\\2D素材\\change\\whiteblack\\kaidan_2d.pyn";
		moveStr[32] = "media\\2D素材\\change\\whiteblack\\Terminal_2D.pyn";
		moveStr[33] = "media\\2D素材\\change\\whiteblack\\kaidan_yuka2D.pyn";

		// キャラクター周りの3DSE
		moveStr[34] = "media\\sound\\ジャンプ.wyn";
		moveStr[35] = "media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[36] = "media\\sound\\足音.wyn";
		moveStr[37] = "media\\sound\\着地.wyn";
		moveStr[38] = "media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[39] = "media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[40] = "media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[41] = "media\\sound\\ピアノコンボ三発目.wyn";

		// ドロップアイテムのSEの二種類目
		moveStr[42] = "media\\sound\\たま拾う音2.wyn";

		// 次のステージでのBGMを流す
		moveStr[43] = "media\\sound\\通常bgm.wyn";

		// 操作の説明
		moveStr[44] = "media\\move2\\attackTrans.pyn";
		moveStr[45] = "media\\move2\\jumpTrans.pyn";
		moveStr[46] = "media\\move2\\fastSpeedTrans.pyn";
		moveStr[47] = "media\\move2\\optionTrans.pyn";

		// ムーブの説明
		moveStr[48] = "media\\ムーブ説明\\move2.pyn";
	}


	loadType.resize(max2 + 1);
	{
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;
		loadType[4] = ELOADFILE::mv1model;
		loadType[5] = ELOADFILE::mv1model;
		loadType[6] = ELOADFILE::mv1model;
		loadType[7] = ELOADFILE::mv1model;
		loadType[8] = ELOADFILE::mv1model;

		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;
		loadType[11] = ELOADFILE::graph;
		loadType[12] = ELOADFILE::graph;
		loadType[13] = ELOADFILE::graph;
		loadType[14] = ELOADFILE::graph;
		loadType[15] = ELOADFILE::graph;
		loadType[16] = ELOADFILE::graph;
		loadType[17] = ELOADFILE::graph;
		loadType[18] = ELOADFILE::graph;

		loadType[19] = ELOADFILE::sound3DSource;

		loadType[20] = ELOADFILE::mv1model;

		loadType[21] = ELOADFILE::graph;
		loadType[22] = ELOADFILE::graph;
		loadType[23] = ELOADFILE::graph;

		loadType[24] = ELOADFILE::mv1model;

		loadType[25] = ELOADFILE::graph;
		loadType[26] = ELOADFILE::graph;

		loadType[27] = ELOADFILE::mv1model;

		loadType[28] = ELOADFILE::graph;
		loadType[29] = ELOADFILE::graph;
		loadType[30] = ELOADFILE::graph;
		loadType[31] = ELOADFILE::graph;
		loadType[32] = ELOADFILE::graph;
		loadType[33] = ELOADFILE::graph;

		loadType[34] = ELOADFILE::sound3DSource;
		loadType[35] = ELOADFILE::sound3DSource;
		loadType[36] = ELOADFILE::sound3DSource;
		loadType[37] = ELOADFILE::sound3DSource;
		loadType[38] = ELOADFILE::sound3DSource;

		loadType[39] = ELOADFILE::sound3DSource;
		loadType[40] = ELOADFILE::sound3DSource;
		loadType[41] = ELOADFILE::sound3DSource;

		loadType[42] = ELOADFILE::sound3DSource;

		loadType[43] = ELOADFILE::soundStream;

		loadType[44] = ELOADFILE::graph;
		loadType[45] = ELOADFILE::graph;
		loadType[46] = ELOADFILE::graph;
		loadType[47] = ELOADFILE::graph;

		loadType[48] = ELOADFILE::graph;
	}
} /// void Manager::InitMove2Load()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove3Load()
{
	moveStr.resize(max3 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\swordCLPH\\clph_sword_all.myn";
		moveStr[2] = "media\\paneru\\paneru.myn";
		moveStr[3] = "media\\kaidan\\kaidan.myn";
		moveStr[4] = "media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\街灯\\Gaitou.myn";
		moveStr[6] = "media\\スカイボックス\\SkyDome.myn";
		moveStr[7] = "media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// サウンドデータ
		moveStr[17] = "media\\sound\\たま拾う音.wyn";

		// 精算機械データ
		moveStr[18] = "media\\Terminal\\terminal.myn";

		// 精算機械テクスチャ
		moveStr[19] = "media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[20] = "media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[21] = "media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[22] = "media\\階段と床合体\\kaidan_yuka1.myn";

		// 階段とそのあとの床のテクスチャデータ
		moveStr[23] = "media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[24] = "media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[25] = "media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[26] = "media\\sound\\ジャンプ.wyn";
		moveStr[27] = "media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[28] = "media\\sound\\足音.wyn";
		moveStr[29] = "media\\sound\\着地.wyn";
		moveStr[30] = "media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[31] = "media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[32] = "media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[33] = "media\\sound\\ピアノコンボ三発目.wyn";

		// ドロップアイテムのSEの二種類目
		moveStr[34] = "media\\sound\\たま拾う音2.wyn";

		// BGM
		moveStr[35] = "media\\sound\\通常bgm.wyn";

		// 敵のスライムのデータ
		moveStr[36] = "media\\move3\\インクスライム\\ink_slime_motionALL.myn";
		moveStr[37] = "media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn";

		// 敵のクレヨンヒューマンのデータ
		moveStr[38] = "media\\move3\\人型クレヨン\\kureyon_,motionALL.myn";
		moveStr[39] = "media\\move3\\人型クレヨン\\kureyon_,motionALL.fbm\\normal\\kre.pyn";

		// ドロップアイテムのデータ
		moveStr[40] = "media\\move3\\インク的な\\ink.myn";
		moveStr[41] = "media\\move3\\インク的な\\correction\\normal\\ink.pyn";

		// ダメージ演出画像
		moveStr[42] = "media\\damage\\damage1\\whiteblack.pyn";
		moveStr[43] = "media\\damage\\damage2\\whiteblack.pyn";
		moveStr[44] = "media\\damage\\damage3\\whiteblack.pyn";
		moveStr[45] = "media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[46] = "media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[47] = "media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[48] = "media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[49] = "media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[50] = "media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[51] = "media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[52] = "media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[53] = "media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[54] = "media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// 敵の攻撃音
		moveStr[55] = "media\\sound\\殴る音（爆発）.wyn";

		// クレヨンの死ぬ音
		moveStr[56] = "media\\sound\\クレヨンの死(2).wyn";

		// 攻撃BGM
		moveStr[57] = "media\\sound\\戦闘BGM.wyn";

		// ムーブ説明画像
		moveStr[58] = "media\\ムーブ説明\\move3.pyn";

		// 精密機械での説明画像
		moveStr[59] = "media\\move3\\UI\\another.pyn";
		moveStr[60] = "media\\move3\\UI\\charaSelect.pyn";
		moveStr[61] = "media\\move3\\UI\\enemy.pyn";
		moveStr[62] = "media\\move3\\UI\\stairs.pyn";
		moveStr[63] = "media\\move3\\UI\\stairsRoad.pyn";
		moveStr[64] = "media\\move3\\UI\\streetLight.pyn";
	}


	loadType.resize(max3 + 1);
	{
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;
		loadType[4] = ELOADFILE::mv1model;
		loadType[5] = ELOADFILE::mv1model;
		loadType[6] = ELOADFILE::mv1model;
		loadType[7] = ELOADFILE::mv1model;

		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;
		loadType[11] = ELOADFILE::graph;
		loadType[12] = ELOADFILE::graph;

		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
		loadType[15] = ELOADFILE::graph;

		loadType[16] = ELOADFILE::graph;

		loadType[17] = ELOADFILE::sound3DSource;

		loadType[18] = ELOADFILE::mv1model;

		loadType[19] = ELOADFILE::graph;
		loadType[20] = ELOADFILE::graph;

		loadType[21] = ELOADFILE::graph;

		loadType[22] = ELOADFILE::mv1model;

		loadType[23] = ELOADFILE::graph;
		loadType[24] = ELOADFILE::graph;

		loadType[25] = ELOADFILE::mv1model;

		loadType[26] = ELOADFILE::sound3DSource;
		loadType[27] = ELOADFILE::sound3DSource;
		loadType[28] = ELOADFILE::sound3DSource;
		loadType[29] = ELOADFILE::sound3DSource;
		loadType[30] = ELOADFILE::sound3DSource;

		loadType[31] = ELOADFILE::sound3DSource;
		loadType[32] = ELOADFILE::sound3DSource;
		loadType[33] = ELOADFILE::sound3DSource;

		loadType[34] = ELOADFILE::sound3DSource;

		loadType[35] = ELOADFILE::soundStream;

		loadType[36] = ELOADFILE::mv1model;
		loadType[37] = ELOADFILE::graph;

		loadType[38] = ELOADFILE::mv1model;
		loadType[39] = ELOADFILE::graph;

		loadType[40] = ELOADFILE::mv1model;
		loadType[41] = ELOADFILE::graph;

		loadType[42] = ELOADFILE::graph;
		loadType[43] = ELOADFILE::graph;
		loadType[44] = ELOADFILE::graph;
		loadType[45] = ELOADFILE::graph;
		loadType[46] = ELOADFILE::graph;
		loadType[47] = ELOADFILE::graph;
		loadType[48] = ELOADFILE::graph;
		loadType[49] = ELOADFILE::graph;
		loadType[50] = ELOADFILE::graph;
		loadType[51] = ELOADFILE::graph;
		loadType[52] = ELOADFILE::graph;
		loadType[53] = ELOADFILE::graph;
		loadType[54] = ELOADFILE::graph;

		loadType[55] = ELOADFILE::sound3DSource;
		loadType[56] = ELOADFILE::sound3DSource;

		loadType[57] = ELOADFILE::soundStream;

		loadType[58] = ELOADFILE::graph;

		loadType[59] = ELOADFILE::graph;
		loadType[60] = ELOADFILE::graph;
		loadType[61] = ELOADFILE::graph;
		loadType[62] = ELOADFILE::graph;
		loadType[63] = ELOADFILE::graph;
		loadType[64] = ELOADFILE::graph;
	}
} /// void Manager::InitMove3Load()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove4Load()
{
	moveStr.resize(max4 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\swordCLPH\\clph_sword_all.myn";
		moveStr[2] = "media\\paneru\\paneru.myn";
		moveStr[3] = "media\\kaidan\\kaidan.myn";
		moveStr[4] = "media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\街灯\\Gaitou.myn";	
		moveStr[6] = "media\\スカイボックス\\SkyDome.myn";
		moveStr[7] = "media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// 精算機械データ
		moveStr[17] = "media\\Terminal\\terminal.myn";	

		// 精算機械テクスチャ
		moveStr[18] = "media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[20] = "media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[21] = "media\\階段と床合体\\kaidan_yuka1.myn";

		// 階段とそのあとの床のテクスチャデータ
		moveStr[22] = "media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[24] = "media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[25] = "media\\sound\\ジャンプ.wyn";
		moveStr[26] = "media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[27] = "media\\sound\\足音.wyn";
		moveStr[28] = "media\\sound\\着地.wyn";
		moveStr[29] = "media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[30] = "media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[31] = "media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[32] = "media\\sound\\ピアノコンボ三発目.wyn";

		// BGM
		moveStr[33] = "media\\sound\\通常bgm.wyn";

		// 人のデータ
		moveStr[34] = "media\\move4\\一般人＿その１\\human1_motionALL.myn";
		moveStr[35] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// 敵のデータ
		moveStr[36] = "media\\move4\\人（敵）\\ene_human_motionALL.myn";
		moveStr[37] = "media\\move4\\人（敵）\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";

		// 攻撃BGM
		moveStr[38] = "media\\sound\\戦闘BGM.wyn";

		// ムーブの説明画像
		moveStr[39] = "media\\ムーブ説明\\move4.pyn";

		// ダメージ演出画像
		moveStr[40] = "media\\damage\\damage1\\whiteblack.pyn";
		moveStr[41] = "media\\damage\\damage2\\whiteblack.pyn";
		moveStr[42] = "media\\damage\\damage3\\whiteblack.pyn";
		moveStr[43] = "media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[44] = "media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[45] = "media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[46] = "media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[47] = "media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[48] = "media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[49] = "media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[50] = "media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[51] = "media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[52] = "media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// 敵の攻撃音
		moveStr[53] = "media\\sound\\殴る音（爆発）.wyn";
	}


	loadType.resize(max4 + 1);
	{
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;
		loadType[4] = ELOADFILE::mv1model;
		loadType[5] = ELOADFILE::mv1model;
		loadType[6] = ELOADFILE::mv1model;
		loadType[7] = ELOADFILE::mv1model;

		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;
		loadType[11] = ELOADFILE::graph;
		loadType[12] = ELOADFILE::graph;

		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
		loadType[15] = ELOADFILE::graph;

		loadType[16] = ELOADFILE::graph;

		loadType[17] = ELOADFILE::mv1model;

		loadType[18] = ELOADFILE::graph;
		loadType[19] = ELOADFILE::graph;

		loadType[20] = ELOADFILE::graph;

		loadType[21] = ELOADFILE::mv1model;

		loadType[22] = ELOADFILE::graph;
		loadType[23] = ELOADFILE::graph;

		loadType[24] = ELOADFILE::mv1model;

		loadType[25] = ELOADFILE::sound3DSource;
		loadType[26] = ELOADFILE::sound3DSource;
		loadType[27] = ELOADFILE::sound3DSource;
		loadType[28] = ELOADFILE::sound3DSource;
		loadType[29] = ELOADFILE::sound3DSource;

		loadType[30] = ELOADFILE::sound3DSource;
		loadType[31] = ELOADFILE::sound3DSource;
		loadType[32] = ELOADFILE::sound3DSource;

		loadType[33] = ELOADFILE::soundStream;

		loadType[34] = ELOADFILE::mv1model;
		loadType[35] = ELOADFILE::graph;

		loadType[36] = ELOADFILE::mv1model;
		loadType[37] = ELOADFILE::graph;

		loadType[38] = ELOADFILE::soundStream;

		loadType[39] = ELOADFILE::graph;

		loadType[40] = ELOADFILE::graph;
		loadType[41] = ELOADFILE::graph;
		loadType[42] = ELOADFILE::graph;
		loadType[43] = ELOADFILE::graph;
		loadType[44] = ELOADFILE::graph;
		loadType[45] = ELOADFILE::graph;
		loadType[46] = ELOADFILE::graph;
		loadType[47] = ELOADFILE::graph;
		loadType[48] = ELOADFILE::graph;
		loadType[49] = ELOADFILE::graph;
		loadType[50] = ELOADFILE::graph;
		loadType[51] = ELOADFILE::graph;
		loadType[52] = ELOADFILE::graph;
		loadType[53] = ELOADFILE::graph;

		loadType[54] = ELOADFILE::sound3DSource;
	}
} /// void Manager::InitMove4Load()



/// --------------------------------------------------------------------------------------------------
void Manager::Move4TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\normal\\body_col.pyn";
			moveStr[15] = "media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\normal\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\normal\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\move4\\人（敵）\\ene_human_motionALL.fbm\\P\\P.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\P\\body_col.pyn";
			moveStr[15] = "media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\P\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\P\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\move4\\人（敵）\\ene_human_motionALL.fbm\\D\\D.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\D\\body_col.pyn";
			moveStr[15] = "media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\D\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\D\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move4TextureReload()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove5Load()
{
	moveStr.resize(max5 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\swordCLPH\\clph_sword_all.myn";
		moveStr[2] = "media\\paneru\\paneru.myn";
		moveStr[3] = "media\\kaidan\\kaidan.myn";	
		moveStr[4] = "media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\街灯\\Gaitou.myn";		
		moveStr[6] = "media\\スカイボックス\\SkyDome.myn";
		moveStr[7] = "media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// 精算機械データ
		moveStr[17] = "media\\Terminal\\terminal.myn";	

		// 精算機械テクスチャ
		moveStr[18] = "media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[20] = "media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[21] = "media\\階段と床合体\\kaidan_yuka1.myn";

		// 階段とそのあとの床のテクスチャデータ
		moveStr[22] = "media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[24] = "media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[25] = "media\\sound\\ジャンプ.wyn";
		moveStr[26] = "media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[27] = "media\\sound\\足音.wyn";
		moveStr[28] = "media\\sound\\着地.wyn";
		moveStr[29] = "media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[30] = "media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[31] = "media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[32] = "media\\sound\\ピアノコンボ三発目.wyn";

		// BGM
		moveStr[33] = "media\\sound\\通常bgm.wyn";

		// 敵のデータ
		moveStr[34] = "media\\childCLPH\\sd_,motionALL.myn";
		moveStr[35] = "media\\childCLPH\\sd_,motionALL.fbm\\whiteblack\\SDchar.pyn";

		// 一般人のデータ
		moveStr[36] = "media\\move4\\一般人＿その１\\human1_motionALL.myn";
		moveStr[37] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// ムーブの説明画像
		moveStr[38] = "media\\ムーブ説明\\move5.pyn";

		// 一定数捕まえたら流すSE
		moveStr[39] = "media\\sound\\savemisson.wyn";

		// 一定数捕まえた時に描画するUI
		moveStr[40] = "media\\move5\\adjustment.pyn";
		moveStr[41] = "media\\move5\\character.pyn";
		moveStr[42] = "media\\move5\\ordinary.pyn";
		moveStr[43] = "media\\move5\\paneru.pyn";
		moveStr[44] = "media\\move5\\stairs.pyn";
		moveStr[45] = "media\\move5\\stairsRoad.pyn";
		moveStr[46] = "media\\move5\\streetLight.pyn";
	}


	loadType.resize(max5 + 1);
	{
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;
		loadType[4] = ELOADFILE::mv1model;
		loadType[5] = ELOADFILE::mv1model;
		loadType[6] = ELOADFILE::mv1model;
		loadType[7] = ELOADFILE::mv1model;

		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;
		loadType[11] = ELOADFILE::graph;
		loadType[12] = ELOADFILE::graph;

		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
		loadType[15] = ELOADFILE::graph;

		loadType[16] = ELOADFILE::graph;

		loadType[17] = ELOADFILE::mv1model;

		loadType[18] = ELOADFILE::graph;
		loadType[19] = ELOADFILE::graph;

		loadType[20] = ELOADFILE::graph;

		loadType[21] = ELOADFILE::mv1model;

		loadType[22] = ELOADFILE::graph;
		loadType[23] = ELOADFILE::graph;

		loadType[24] = ELOADFILE::mv1model;

		loadType[25] = ELOADFILE::sound3DSource;
		loadType[26] = ELOADFILE::sound3DSource;
		loadType[27] = ELOADFILE::sound3DSource;
		loadType[28] = ELOADFILE::sound3DSource;
		loadType[29] = ELOADFILE::sound3DSource;

		loadType[30] = ELOADFILE::sound3DSource;
		loadType[31] = ELOADFILE::sound3DSource;
		loadType[32] = ELOADFILE::sound3DSource;

		loadType[33] = ELOADFILE::soundStream;

		loadType[34] = ELOADFILE::mv1model;
		loadType[35] = ELOADFILE::graph;

		loadType[36] = ELOADFILE::mv1model;
		loadType[37] = ELOADFILE::graph;

		loadType[38] = ELOADFILE::graph;

		loadType[39] = ELOADFILE::soundmem;

		loadType[40] = ELOADFILE::graph;
		loadType[41] = ELOADFILE::graph;
		loadType[42] = ELOADFILE::graph;
		loadType[43] = ELOADFILE::graph;
		loadType[44] = ELOADFILE::graph;
		loadType[45] = ELOADFILE::graph;
		loadType[46] = ELOADFILE::graph;
	}
} /// void Manager::InitMove5Load()



/// --------------------------------------------------------------------------------------------------
void Manager::Move5TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\childCLPH\\sd_,motionALL.fbm\\normal\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\normal\\body_col.pyn";
			moveStr[15] = "media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\normal\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\normal\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\childCLPH\\sd_,motionALL.fbm\\P\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\P\\body_col.pyn";
			moveStr[15] = "media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\P\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\P\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\childCLPH\\sd_,motionALL.fbm\\D\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\D\\body_col.pyn";
			moveStr[15] = "media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\階段と床合体\\D\\kaidan.pyn";
			moveStr[23] = "media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\D\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move5TextureReload()



/// --------------------------------------------------------------------------------------------------
void Manager::InitMove6Load()
{
	moveStr.resize(max6 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\swordCLPH\\clph_sword_all.myn";
		moveStr[2] = "media\\paneru\\paneru.myn";
		moveStr[3] = "media\\kaidan\\kaidan.myn";	
		moveStr[4] = "media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\街灯\\Gaitou.myn";		
		moveStr[6] = "media\\スカイボックス\\SkyDome.myn";	
		moveStr[7] = "media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// 階段とそのあとの床データ
		moveStr[17] = "media\\階段と床合体\\kaidan_yuka1.myn";

		// 階段とそのあとの床のテクスチャデータ
		moveStr[18] = "media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[19] = "media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[20] = "media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[21] = "media\\sound\\ジャンプ.wyn";
		moveStr[22] = "media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[23] = "media\\sound\\足音.wyn";
		moveStr[24] = "media\\sound\\着地.wyn";
		moveStr[25] = "media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[26] = "media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[27] = "media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[28] = "media\\sound\\ピアノコンボ三発目.wyn";

		// BGM
		moveStr[29] = "media\\sound\\boss.wyn";

		// 一般人のデータ
		moveStr[30] = "media\\move4\\一般人＿その１\\human1_motionALL.myn";
		moveStr[31] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// 敵に近づいたときに出るUI
		moveStr[32] = "media\\move6\\near.pyn";
		moveStr[33] = "media\\move6\\yes.pyn";
		moveStr[34] = "media\\move6\\no.pyn";

		// 前敵のデータ
		moveStr[35] = "media\\ラスボス＿光\\モーション\\motion_Boss1.myn";
		moveStr[36] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\whiteblack.pyn";
		moveStr[37] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\whiteblack.pyn";
		moveStr[38] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\whiteblack.pyn";

		// エンドロール用画像
		moveStr[39] = "media\\end\\title.pyn";
		moveStr[40] = "media\\end\\dxlib.pyn";
		moveStr[41] = "media\\end\\effekseer.pyn";
		moveStr[42] = "media\\end\\graphic.pyn";
		moveStr[43] = "media\\end\\program.pyn";
		moveStr[44] = "media\\end\\sound.pyn";
		moveStr[45] = "media\\end\\special.pyn";
		moveStr[46] = "media\\end\\test.pyn";
		moveStr[47] = "media\\end\\thanksLib.pyn";
		moveStr[48] = "media\\end\\youser.pyn";

		// エンドロール用BGM
		moveStr[49] = "media\\sound\\ED.wyn";

		// 戦闘敵のデータ
		moveStr[50] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\whiteblack.pyn";
		moveStr[51] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\whiteblack.pyn";
		moveStr[52] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\whiteblack.pyn";

		// ムービーをスキップの仕方の画像
		moveStr[53] = "media\\move6\\skip.pyn";

		// プレイヤーの体力を表示する
		moveStr[54] = "media\\UI\\clph_icon\\whiteblack.pyn";
		moveStr[55] = "media\\UI\\no_name\\whiteblack.pyn";
		moveStr[56] = "media\\UI\\ゲージ\\whiteblack.pyn";
		moveStr[57] = "media\\UI\\ゲージの中身1\\whiteblack.pyn";

		// 敵の体力を表示する
		moveStr[58] = "media\\UI\\enemy\\whiteblack.pyn";
	}


	loadType.resize(max6 + 1);
	{
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;
		loadType[4] = ELOADFILE::mv1model;
		loadType[5] = ELOADFILE::mv1model;
		loadType[6] = ELOADFILE::mv1model;
		loadType[7] = ELOADFILE::mv1model;

		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;
		loadType[11] = ELOADFILE::graph;
		loadType[12] = ELOADFILE::graph;

		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
		loadType[15] = ELOADFILE::graph;

		loadType[16] = ELOADFILE::graph;

		loadType[17] = ELOADFILE::mv1model;

		loadType[18] = ELOADFILE::graph;
		loadType[19] = ELOADFILE::graph;

		loadType[20] = ELOADFILE::mv1model;

		loadType[21] = ELOADFILE::sound3DSource;
		loadType[22] = ELOADFILE::sound3DSource;
		loadType[23] = ELOADFILE::sound3DSource;
		loadType[24] = ELOADFILE::sound3DSource;
		loadType[25] = ELOADFILE::sound3DSource;

		loadType[26] = ELOADFILE::sound3DSource;
		loadType[27] = ELOADFILE::sound3DSource;
		loadType[28] = ELOADFILE::sound3DSource;

		loadType[29] = ELOADFILE::soundStream;

		loadType[30] = ELOADFILE::mv1model;
		loadType[31] = ELOADFILE::graph;

		loadType[32] = ELOADFILE::graph;
		loadType[33] = ELOADFILE::graph;
		loadType[34] = ELOADFILE::graph;

		loadType[35] = ELOADFILE::mv1model;
		loadType[36] = ELOADFILE::graph;
		loadType[37] = ELOADFILE::graph;
		loadType[38] = ELOADFILE::graph;

		loadType[39] = ELOADFILE::graph;
		loadType[40] = ELOADFILE::graph;
		loadType[41] = ELOADFILE::graph;
		loadType[42] = ELOADFILE::graph;
		loadType[43] = ELOADFILE::graph;
		loadType[44] = ELOADFILE::graph;
		loadType[45] = ELOADFILE::graph;
		loadType[46] = ELOADFILE::graph;
		loadType[47] = ELOADFILE::graph;
		loadType[48] = ELOADFILE::graph;

		loadType[49] = ELOADFILE::soundStream;

		loadType[50] = ELOADFILE::graph;
		loadType[51] = ELOADFILE::graph;
		loadType[52] = ELOADFILE::graph;

		loadType[53] = ELOADFILE::graph;

		loadType[54] = ELOADFILE::graph;
		loadType[55] = ELOADFILE::graph;
		loadType[56] = ELOADFILE::graph;
		loadType[57] = ELOADFILE::graph;

		loadType[58] = ELOADFILE::graph;
	}
} /// void Manager::InitMove6Load()



/// --------------------------------------------------------------------------------------------------
void Manager::Move6TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";

			// プレイヤーの体力を表示する
			moveStr[54] = "media\\UI\\clph_icon\\normal.pyn";
			moveStr[55] = "media\\UI\\no_name\\normal.pyn";
			moveStr[56] = "media\\UI\\ゲージ\\normal.pyn";
			moveStr[57] = "media\\UI\\ゲージの中身1\\normal.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack || !BASICPARAM::lightStreetTextureWhiteBlack
			|| !BASICPARAM::stairsRoadTextureWhiteBlack || !BASICPARAM::stairsTextureWhiteBlack
			|| !BASICPARAM::anothreTextureWhiteBlack)
		{
			// 戦闘敵のデータ
			moveStr[50] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\normal.pyn";
			moveStr[51] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\normal.pyn";
			moveStr[52] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\normal.pyn";

			// 敵の体力を表示する
			moveStr[58] = "media\\UI\\enemy\\normal.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\normal\\body_col.pyn";
			moveStr[15] = "media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[18] = "media\\階段と床合体\\normal\\kaidan.pyn";
			moveStr[19] = "media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[31] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\normal\\BlueSky.byn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";

			// プレイヤーの体力を表示する
			moveStr[54] = "media\\UI\\clph_icon\\P.pyn";
			moveStr[55] = "media\\UI\\no_name\\P.pyn";
			moveStr[56] = "media\\UI\\ゲージ\\P.pyn";
			moveStr[57] = "media\\UI\\ゲージの中身1\\P.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack || !BASICPARAM::lightStreetTextureWhiteBlack
			|| !BASICPARAM::stairsRoadTextureWhiteBlack || !BASICPARAM::stairsTextureWhiteBlack
			|| !BASICPARAM::anothreTextureWhiteBlack)
		{
			// 戦闘敵のデータ
			moveStr[50] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\P.pyn";
			moveStr[51] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\P.pyn";
			moveStr[52] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\P.pyn";

			// 敵の体力を表示する
			moveStr[58] = "media\\UI\\enemy\\P.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\P\\body_col.pyn";
			moveStr[15] = "media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[18] = "media\\階段と床合体\\P\\kaidan.pyn";
			moveStr[19] = "media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[31] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\P\\BlueSky.byn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";

			// プレイヤーの体力を表示する
			moveStr[54] = "media\\UI\\clph_icon\\D.pyn";
			moveStr[55] = "media\\UI\\no_name\\D.pyn";
			moveStr[56] = "media\\UI\\ゲージ\\D.pyn";
			moveStr[57] = "media\\UI\\ゲージの中身1\\D.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack || !BASICPARAM::lightStreetTextureWhiteBlack
			|| !BASICPARAM::stairsRoadTextureWhiteBlack || !BASICPARAM::stairsTextureWhiteBlack
			|| !BASICPARAM::anothreTextureWhiteBlack)
		{
			// 戦闘敵のデータ
			moveStr[50] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\D.pyn";
			moveStr[51] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\D.pyn";
			moveStr[52] = "media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\D.pyn";

			// 敵の体力を表示する
			moveStr[58] = "media\\UI\\enemy\\D.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\街灯\\D\\body_col.pyn";
			moveStr[15] = "media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[18] = "media\\階段と床合体\\D\\kaidan.pyn";
			moveStr[19] = "media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[31] = "media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\スカイボックス\\D\\BlueSky.byn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move6TextureReload()



/// --------------------------------------------------------------------------------------------------
void Manager::OptionProcess()
{
	///常時-------------------------------------------------------------------------------------------------------
	// BGM音量調整コマンドを選択していたら
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		// 右にスティックを倒していたら
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// BGMの設定音量を上げる
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() < 1.00f ? SoundProcess::GetBGMVolumeEntire() + 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
		// 左にスティックを倒していたら
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// BGMの設定音量を下げる
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() > 0.00f ? SoundProcess::GetBGMVolumeEntire() - 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
	}
	// SE音量調整コマンドを選択していたら
	else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		// 61カウントのたびにSEを鳴らす
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			

			// SEを流す
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveOn);
			//PlaySoundMem(se_save, DX_PLAYTYPE_BACK);
		}


		// 右にスティックを倒していたら
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// SEの設定音量を上げる
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() < 1.00f ? SoundProcess::GetSEVolumeEntire() + 0.01f : SoundProcess::GetSEVolumeEntire());
		}
		// 左にスティックを倒していたら
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// SEの設定音量を下げる
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() > 0.00f ? SoundProcess::GetSEVolumeEntire() - 0.01f : SoundProcess::GetSEVolumeEntire());
		}
	}
	///常時-------------------------------------------------------------------------------------------------------


	///決定-------------------------------------------------------------------------------------------------------
	// 決定ボタンを押したときの動作
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// BGMにカーソルがあったとき
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			// BGM設定音量に移る
			optionSelectButtonNum = EOptionSelectButton::BGMSelect;
			optionSelectMin = 10;
			optionSelectMax = 10;
		}
		// SEにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// SE設定音量に移る
			optionSelectButtonNum = EOptionSelectButton::SESelect;
			optionSelectMin = 11;
			optionSelectMax = 11;
		}
		// テクスチャ色の通常にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			// 通常色に変える
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// テクスチャ切り替え
			}
		}
		// テクスチャ色のP型にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// P型補正色に変える
			BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// テクスチャ切り替え
			}
		}
		// テクスチャ色のD型にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// D型補正色に変える
			BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// テクスチャ切り替え
			}
		}
		// 色覚選択にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect
			&& BASICPARAM::e_nowScene >= ESceneNumber::THIRDMOVE)
		{
			// 通常色にカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::ColorNormal;
			optionSelectMin = 7;
			optionSelectMax = 9;
		}
		// サウンドにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			// BGMにカーソルを移す
			SoundProcess::SetOptionMenuNow(false);				// サウンドの音量をオプション用からやめる
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// BGM選択にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGMの設定音量に移る
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// SE選択にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SEの設定音量に移る
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// カメラにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			// 遠近法カメラに移る
			optionSelectButtonNum = EOptionSelectButton::CameraPerspective;
			optionSelectMin = 12;
			optionSelectMax = 15;
		}
		// 遠近法カメラにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			// カメラを遠近法カメラに設定する
			BASICPARAM::nowCameraOrtho = false;
		}
		// 正射影カメラにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			// カメラを正射影カメラに設定する
			BASICPARAM::nowCameraOrtho = true;
		}
		// 横回転カメラにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			// 横回転のスティック方向を逆にする
			BASICPARAM::cameraHorizonReturn = !BASICPARAM::cameraHorizonReturn;
		}
		// 縦回転カメラにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// 縦回転のスティック方向を逆にする
			BASICPARAM::cameraVerticalReturn = !BASICPARAM::cameraVerticalReturn;
		}
		// セーブにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::DataSave)
		{
			// セーブにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::SaveYes;
			optionSelectMin = 16;
			optionSelectMax = 17;
		}
		// ゲーム終了にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			// セーブにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::GameEndYes;
			optionSelectMin = 18;
			optionSelectMax = 19;
		}
		// セーブするにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SaveYes)
		{
			// SEを流す
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveOn);


			// セーブする
			FileSaveLoad::Save();


			// セーブにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::DataSave;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// セーブしないにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SaveNo)
		{
			// セーブにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::DataSave;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// ゲーム終了にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::GameEndYes)
		{
			// ゲームを終了する
			gameEnd = true;
		}
		// ゲーム終了しないにカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::GameEndNo)
		{
			// ゲームを終了にカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::GameEnd;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	///決定------------------------------------------------------------------------------------------------------


	///戻る-------------------------------------------------------------------------------------------------------
	// 戻るボタンを押したときの動作
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// BGMにカーソルがあったとき
		if (optionSelectButtonNum == EOptionSelectButton::BGM
			|| optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// サウンドにカーソルを移す
			SoundProcess::SetOptionMenuNow(true);					// サウンドの音量をオプション用からに戻す
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// 通常色にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal
			|| optionSelectButtonNum == EOptionSelectButton::ColorP
			|| optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// 色覚選択にカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// BGM音量調整にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGMにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// SE音量調整にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SEにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// カメラ関連にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective
			|| optionSelectButtonNum == EOptionSelectButton::CameraOrtho
			|| optionSelectButtonNum == EOptionSelectButton::CameraHReturn
			|| optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// カメラにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// セーブ関連にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::SaveYes
			|| optionSelectButtonNum == EOptionSelectButton::SaveNo)
		{
			// セーブにカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::DataSave;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// ゲーム終了関連にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::GameEndYes
			|| optionSelectButtonNum == EOptionSelectButton::GameEndNo)
		{
			// ゲームを終了にカーソルを移す
			optionSelectButtonNum = EOptionSelectButton::GameEnd;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	///戻る------------------------------------------------------------------------------------------------------


	/// スティックの一回押し倒しで更新するよう調整-----------------------------------------------------------------
	// 左スティックを上に倒したら
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if(optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	// 左スティックを下に倒したら
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	// 左スティックを特に弄ってなかったら
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}


	// 上にスティックを倒したとき
	if (optionControllLeftStickY[0] == 1)
	{
		// カーソルを上に移動する
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect) optionPageNowNumber = 0;
	}
	// 下にスティックを倒したとき
	if (optionControllLeftStickY[1] == 1)
	{
		// カーソルを下に移動する
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::Camera) optionPageNowNumber = 1;
	}
	/// スティックの一回押し倒しで更新するよう調整-----------------------------------------------------------------
} /// void Manager::OptionProcess()



/// --------------------------------------------------------------------------------------------------
void Manager::OptionDraw()
{
	// 背景
	DrawGraph(0, 0, gaussianScreen, false);


	//　モデル表示
	p_baseMove->OptionActorModel();


	// オプションから戻る説明画像
	DrawGraph(1600, 800, optionDrawMedia[static_cast<int>(EOptionDraw::optionEnd)], true);


	// 一列目のオプションのとき
	if (optionPageNowNumber == 0)
	{
		/// サウンド関係オプション---------------------------------------------------------------
		// UI:Sound
		DrawGraph(95, 95, optionDrawMedia[static_cast<int>(EOptionDraw::Sound)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			DrawBox(95 + 5, 95 + 5, 95 + 211 - 5, 95 + 86 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 95 + 4, 95 + 211 - 4, 95 + 86 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 95 + 3, 95 + 211 - 3, 95 + 86 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGM
		DrawGraph(381, 114, optionDrawMedia[static_cast<int>(EOptionDraw::BGM)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			DrawBox(381 + 5, 114 + 5, 381 + 87 - 5, 114 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(381 + 4, 114 + 4, 381 + 87 - 4, 114 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(381 + 3, 114 + 3, 381 + 87 - 3, 114 + 58 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGMバー
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(200, 200, 200), true);
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			DrawBox(546 + 5, 100 + 5, 546 + 548 - 5, 100 + 81 - 5, GetColor(50, 50, 200), false);
			DrawBox(546 + 4, 100 + 4, 546 + 548 - 4, 100 + 81 - 4, GetColor(50, 50, 200), false);
			DrawBox(546 + 3, 100 + 3, 546 + 548 - 3, 100 + 81 - 3, GetColor(50, 50, 200), false);
		}
		DrawBox(546 - 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 547)
			, 100 - 10, 546 + 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 548)
			, 100 + 81 + 10, GetColor(255, 255, 255), true);


		// UI:SE
		DrawGraph(385, 266, optionDrawMedia[static_cast<int>(EOptionDraw::SE)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			DrawBox(385 + 5, 266 + 5, 385 + 86 - 5, 266 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 266 + 4, 385 + 86 - 4, 266 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 266 + 3, 385 + 86 - 3, 266 + 58 - 3, GetColor(50, 50, 200), false);
		}

		// UI:SEバー
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			DrawBox(548 + 5, 255 + 5, 548 + 547 - 5, 255 + 78 - 5, GetColor(50, 50, 200), false);
			DrawBox(548 + 4, 255 + 4, 548 + 547 - 4, 255 + 78 - 4, GetColor(50, 50, 200), false);
			DrawBox(548 + 3, 255 + 3, 548 + 547 - 3, 255 + 78 - 3, GetColor(50, 50, 200), false);
		}
		DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 + 78 + 10, GetColor(255, 255, 255), true);
		/// サウンド関係オプション---------------------------------------------------------------


		/// 色覚に関するオプション-----------------------------------------------------------------------
		// 色覚補正できるムーブじゃなかったら
		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);


		// UI:色覚調整
		DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);


		// UI:通常色
		DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			DrawBox(385 + 5, 427 + 5, 385 + 83 - 5, 427 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 427 + 4, 385 + 83 - 4, 427 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 427 + 3, 385 + 83 - 3, 427 + 58 - 3, GetColor(50, 50, 200), false);
		}


		// UI:P型
		DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			DrawBox(386 + 5, 550 + 5, 386 + 83 - 5, 550 + 59 - 5, GetColor(50, 50, 200), false);
			DrawBox(386 + 4, 550 + 4, 386 + 83 - 4, 550 + 59 - 4, GetColor(50, 50, 200), false);
			DrawBox(386 + 3, 550 + 3, 386 + 83 - 3, 550 + 59 - 3, GetColor(50, 50, 200), false);
		}


		// UI:D型
		DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
		// カーソルが当たっていたら
		if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			DrawBox(385 + 5, 682 + 5, 385 + 83 - 5, 682 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 682 + 4, 385 + 83 - 4, 682 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 682 + 3, 385 + 83 - 3, 682 + 58 - 3, GetColor(50, 50, 200), false);
		}


		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// 色覚補正にカーソルが当たっていたら(ブレンドから逃がすため
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
		{
			DrawBox(96 + 5, 413 + 5, 96 + 112 - 5, 413 + 76 - 5, GetColor(50, 50, 200), false);
			DrawBox(96 + 4, 413 + 4, 96 + 112 - 4, 413 + 76 - 4, GetColor(50, 50, 200), false);
			DrawBox(96 + 3, 413 + 3, 96 + 112 - 3, 413 + 76 - 3, GetColor(50, 50, 200), false);
		}
		/// 色覚に関するオプション-----------------------------------------------------------------------


		// 次のページ
		DrawGraph(96, 815, optionDrawMedia[static_cast<int>(EOptionDraw::nextPage)], false);
	} /// if (optionPageNowNumber == 0)
	// 二ページ目の時
	else if (optionPageNowNumber == 1)
	{
		// 前のページへ
		DrawGraph(96, 95, optionDrawMedia[static_cast<int>(EOptionDraw::prevPage)], false);


		/// カメラの関するオプション------------------------------------------------
		// カメラ
		DrawGraph(95, 247, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
		if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			DrawBox(95 + 5, 247 + 5, 95 + 109 - 5, 247 + 68 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 247 + 4, 95 + 109 - 4, 247 + 68 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 247 + 3, 95 + 109 - 3, 247 + 68 - 3, GetColor(50, 50, 200), false);
		}


		// 遠近法
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 267, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			DrawBox(385 + 5, 267 + 5, 385 + 83 - 5, 267 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 267 + 4, 385 + 83 - 4, 267 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 267 + 3, 385 + 83 - 3, 267 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// 正射影
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 400, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			DrawBox(385 + 5, 400 + 5, 385 + 83 - 5, 400 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 400 + 4, 385 + 83 - 4, 400 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 400 + 3, 385 + 83 - 3, 400 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// 横反転
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 513, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			DrawBox(385 + 5, 513 + 5, 385 + 83 - 5, 513 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 513 + 4, 385 + 83 - 4, 513 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 513 + 3, 385 + 83 - 3, 513 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// 縦反転
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 646, optionDrawMedia[static_cast<int>(EOptionDraw::VerticalReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			DrawBox(385 + 5, 646 + 5, 385 + 83 - 5, 646 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 646 + 4, 385 + 83 - 4, 646 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 646 + 3, 385 + 83 - 3, 646 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// セーブ
		DrawGraph(95, 760, optionDrawMedia[static_cast<int>(EOptionDraw::dataSave)], false);
		if (optionSelectButtonNum == EOptionSelectButton::DataSave)
		{
			DrawBox(95 + 5, 760 + 5, 95 + 450 - 5, 760 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 760 + 4, 95 + 450 - 4, 760 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 760 + 3, 95 + 450 - 3, 760 + 69 - 3, GetColor(50, 50, 200), false);
		}


		// ゲーム終了
		DrawGraph(95, 880, optionDrawMedia[static_cast<int>(EOptionDraw::gameEnd)], false);
		if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			DrawBox(95 + 5, 880 + 5, 95 + 450 - 5, 880 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 880 + 4, 95 + 450 - 4, 880 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 880 + 3, 95 + 450 - 3, 880 + 69 - 3, GetColor(50, 50, 200), false);
		}


		// セーブする
		if (optionSelectButtonNum == EOptionSelectButton::SaveYes
			|| optionSelectButtonNum == EOptionSelectButton::SaveNo)
		{
			DrawGraph(600, 660, optionDrawMedia[static_cast<int>(EOptionDraw::yes)], false);
			if (optionSelectButtonNum == EOptionSelectButton::SaveYes)
			{
				DrawBox(600 + 5, 660 + 5, 600 + 275 - 5, 660 + 69 - 5, GetColor(50, 50, 200), false);
				DrawBox(600 + 4, 660 + 4, 600 + 275 - 4, 660 + 69 - 4, GetColor(50, 50, 200), false);
				DrawBox(600 + 3, 660 + 3, 600 + 275 - 3, 660 + 69 - 3, GetColor(50, 50, 200), false);
			}
		}

		
		// セーブしない
		if (optionSelectButtonNum == EOptionSelectButton::SaveYes
			|| optionSelectButtonNum == EOptionSelectButton::SaveNo)
		{
			DrawGraph(600, 840, optionDrawMedia[static_cast<int>(EOptionDraw::no)], false);
			if (optionSelectButtonNum == EOptionSelectButton::SaveNo)
			{
				DrawBox(600 + 5, 840 + 5, 600 + 275 - 5, 840 + 69 - 5, GetColor(50, 50, 200), false);
				DrawBox(600 + 4, 840 + 4, 600 + 275 - 4, 840 + 69 - 4, GetColor(50, 50, 200), false);
				DrawBox(600 + 3, 840 + 3, 600 + 275 - 3, 840 + 69 - 3, GetColor(50, 50, 200), false);
			}
		}


		// ゲーム終了する
		if (optionSelectButtonNum == EOptionSelectButton::GameEndNo
			|| optionSelectButtonNum == EOptionSelectButton::GameEndYes)
		{
			DrawGraph(600, 760, optionDrawMedia[static_cast<int>(EOptionDraw::yes)], false);
			if (optionSelectButtonNum == EOptionSelectButton::GameEndYes)
			{
				DrawBox(600 + 5, 760 + 5, 600 + 275 - 5, 760 + 69 - 5, GetColor(50, 50, 200), false);
				DrawBox(600 + 4, 760 + 4, 600 + 275 - 4, 760 + 69 - 4, GetColor(50, 50, 200), false);
				DrawBox(600 + 3, 760 + 3, 600 + 275 - 3, 760 + 69 - 3, GetColor(50, 50, 200), false);
			}
		}


		// ゲーム終了しない
		if (optionSelectButtonNum == EOptionSelectButton::GameEndNo
			|| optionSelectButtonNum == EOptionSelectButton::GameEndYes)
		{
			DrawGraph(600, 940, optionDrawMedia[static_cast<int>(EOptionDraw::no)], false);
			if (optionSelectButtonNum == EOptionSelectButton::GameEndNo)
			{
				DrawBox(600 + 5, 940 + 5, 600 + 275 - 5, 940 + 69 - 5, GetColor(50, 50, 200), false);
				DrawBox(600 + 4, 940 + 4, 600 + 275 - 4, 940 + 69 - 4, GetColor(50, 50, 200), false);
				DrawBox(600 + 3, 940 + 3, 600 + 275 - 3, 940 + 69 - 3, GetColor(50, 50, 200), false);
			}
		}
	} /// else if (optionPageNowNumber == 1)
} /// void Manager::OptionDraw()



/// --------------------------------------------------------------------------------------------------
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
	

	// メモリの初期化
	p_baseMove = nullptr;
	p_loadThread = nullptr;
	moveStr.clear();
	loadType.clear();
	for (int i = 0; i != titleUINum; ++i)
	{
		titleUIDraw[i] = -1;
	}


	// 最初のロードを生成
	p_loadThread = new LoadThread();
	preLoadScene = false;

	
	/// ゲームのタイトルに関する-------------------------------------------------------------------------------------
	gameFirstStarting = FileSaveLoad::Load();		// ロードさせる、ファイルがあるかどうかでそのあとを判断
	gameEnd = false;
	

	// ロードファイルがあった場合
	if (gameFirstStarting)
	{
		optionSelectMin = 0;
		optionSelectMax = 2;
	}
	// ロードファイルがなかった場合
	else
	{
		optionSelectMin = 0;
		optionSelectMax = 4;
	}
	playBonus = false;


	LoadFile::MyLoad("media\\First\\gameStart.pyn", titleUIDraw[0], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\dataLoad.pyn", titleUIDraw[1], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\gameEnd.pyn", titleUIDraw[2], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake.pyn", titleUIDraw[3], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake2.pyn", titleUIDraw[4], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake3.pyn", titleUIDraw[5], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake4.pyn", titleUIDraw[6], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake5.pyn", titleUIDraw[7], ELOADFILE::graph);
	LoadFile::MyLoad("media\\First\\omake6.pyn", titleUIDraw[8], ELOADFILE::graph);
	/// ゲームのタイトルに関する-------------------------------------------------------------------------------------


	// 画面に関する
	gaussianScreen = MakeScreen(1920, 1080);


	// オプションに関する
	optionMenuNow = false;
	optionControllLeftStickY[0] = 0;
	optionControllLeftStickY[1] = 0;
	optionPageNowNumber = 0;
	seDoWaitTimer = 0;
	for (int i = 0; i != optionDrawNum; ++i)
	{
		optionDrawMedia[i] = -1;
	}
	se_save = -1;
	LoadFile::MyLoad("media\\option\\BGM.pyn", optionDrawMedia[0], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\camera.pyn", optionDrawMedia[1], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\D型.pyn", optionDrawMedia[2], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\P型.pyn", optionDrawMedia[3], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\SE.pyn", optionDrawMedia[4], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\Sound.pyn", optionDrawMedia[5], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\遠近法.pyn", optionDrawMedia[6], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\色覚調整.pyn", optionDrawMedia[7], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\正射影.pyn", optionDrawMedia[8], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\通常色.pyn", optionDrawMedia[9], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\横反転.pyn", optionDrawMedia[10], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\縦反転.pyn", optionDrawMedia[11], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\nextPage.pyn", optionDrawMedia[12], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\prevPage.pyn", optionDrawMedia[13], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\optionEnd.pyn", optionDrawMedia[14], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\gameEnd.pyn", optionDrawMedia[15], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\save.pyn", optionDrawMedia[16], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\yes.pyn", optionDrawMedia[17], ELOADFILE::graph);
	LoadFile::MyLoad("media\\option\\no.pyn", optionDrawMedia[18], ELOADFILE::graph);


	// フェード処理に関する
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// アンチエイリアシングに関する
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4のアンチエイリアシングモードにする
	antiAliasScreen = MakeScreen(1920, 1080, false);	// アンチエイリアシング用の画面を作成
	SetCreateDrawValidGraphMultiSample(0, 0);			// 元に戻す
} /// Manager::Manager()



/// --------------------------------------------------------------------------------------------------
Manager::~Manager()
{
	for (int i = 0; i != titleUINum; ++i)
	{
		GRAPHIC_RELEASE(titleUIDraw[i]);
	}
	for (int i = 0; i != optionDrawNum; ++i)
	{
		GRAPHIC_RELEASE(optionDrawMedia[i]);
	}
	GRAPHIC_RELEASE(gaussianScreen);
	GRAPHIC_RELEASE(antiAliasScreen);


	POINTER_RELEASE(p_baseMove);
	POINTER_RELEASE(p_loadThread);
}



/// --------------------------------------------------------------------------------------------------
void Manager::Update()
{
	// 最初の起動のとき
	if (gameFirstStarting)
	{
		TitleProcess();

		ClearDrawScreen();

		TitleDraw();

		ScreenFlip();
	} /// if (gameFirstStarting)
	// 最初の起動でないとき(つまり通常時
	else
	{
		// 今のシーンと直前のシーンが同じ
		if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
		{
			// 最初のムーブのロードだったら
			if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)
			{
				// シーン１の素材ファイル
				InitMove1Load();


				p_loadThread->Process(max1, moveStr, loadType);		// ロードをする


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
				// シーン２の素材ファイル
				InitMove2Load();


				p_loadThread->Process(max2, moveStr, loadType);		// ロードをする


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
				// ムーブ3のロード素材
				InitMove3Load();


				p_loadThread->Process(max3, moveStr, loadType);		// ロードをする


				// ロードが終了したら
				if (p_loadThread->GetNum() >= max3)
				{
					BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
					preLoadScene = true;								// 直前がロードだったら
					BASICPARAM::e_nowScene = ESceneNumber::THIRDMOVE;	// 次のシーンを指定する
				}
			}
			// 四番目のムーブのロードだったら
			else if (BASICPARAM::e_preScene == ESceneNumber::FOURTHLOAD)
			{
				// ムーブ4のロード素材
				InitMove4Load();


				Move4TextureReload();


				p_loadThread->Process(max4, moveStr, loadType);		// ロードをする


				// ロードが終了したら
				if (p_loadThread->GetNum() >= max4)
				{
					BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
					preLoadScene = true;								// 直前がロードだったら
					BASICPARAM::e_nowScene = ESceneNumber::FOURTHMOVE;	// 次のシーンを指定する
				}
			}
			// 五番目のムーブのロードだったら
			else if (BASICPARAM::e_preScene == ESceneNumber::FIFTHLOAD)
			{
				// ムーブ5のロード素材
				InitMove5Load();


				Move5TextureReload();


				p_loadThread->Process(max5, moveStr, loadType);		// ロードをする


				// ロードが終了したら
				if (p_loadThread->GetNum() >= max5)
				{
					BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
					preLoadScene = true;								// 直前がロードだったら
					BASICPARAM::e_nowScene = ESceneNumber::FIFTHMOVE;	// 次のシーンを指定する
				}
			}
			// 六番目のムーブのロードだったら
			else if (BASICPARAM::e_preScene == ESceneNumber::SIXLOAD)
			{
				// ムーブ6のロード素材
				InitMove6Load();


				Move6TextureReload();


				p_loadThread->Process(max6, moveStr, loadType);		// ロードをする


				// ロードが終了したら
				if (p_loadThread->GetNum() >= max6)
				{
					BASICPARAM::endFeedNow = true;						// 終了フェードのフラッグを立てる
					preLoadScene = true;								// 直前がロードだったら
					BASICPARAM::e_nowScene = ESceneNumber::SIXMOVE;		// 次のシーンを指定する				
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
					if (!BASICPARAM::startFeedNow)
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


							GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);	// 現在の画面にガウスフィルタかけてぼかす	


							p_baseMove->OptionActorModelBefore();							// オプション用のモデル表示の準備



							optionMenuNow = true;											// オプションメニューに移行するフラッグを立てる


							optionSelectButtonNum = EOptionSelectButton::Sound;				// オプションメニューのボタン位置を初期化


							optionPageNowNumber = 0;										// オプションのページを1ページ目にする


							SoundProcess::SetOptionMenuNow(true);							// サウンド音量をオプションメニュー用に下げるよう命令

						}
#ifdef _DEBUG
						MyDebug::DebugProcess();
#endif // _DEBUG
						ScreenFlip();
					} /// if (!BASICPARAM::startFeedNow)
					// 開始フェードが立っていたら
					else
					{
						feedCount -= 5;						// フェードカウントを下げる			


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
					} /// else(!if (!BASICPARAM::startFeedNow))
				} /// if (!optionMenuNow)
				// オプションメニューのとき
				else
				{
					// 画面に関する一連
					ClearDrawScreen();


					// オプションに関する
					OptionDraw();
					OptionProcess();


					// オプション画面から戻る
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
					{
						p_baseMove->OptionActorModelAfter();
						p_baseMove->CameraProcess();				// カメラ切り替え
						SoundProcess::SetOptionMenuNow(false);		// サウンド音量をオプション用から戻す
						optionMenuNow = false;
					}


					ScreenFlip();
				} /// else(!if (!optionMenuNow))
			} /// else
		} /// if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)	
		// シーンを移行するように指定されたら
		else
		{
			// 現在のシーンの終了フェードが終わったら
			if (!BASICPARAM::endFeedNow)
			{
				// ムーブ6だったら終了させる
				if (BASICPARAM::e_preScene == ESceneNumber::SIXMOVE)
				{
					// セーブデータがあるか調べる
					int temp = FileSaveLoad::Load();

					
					// セーブデータがなかった場合セーブする
					if (!temp)
					{
						BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;
						FileSaveLoad::Save();
					}


					// タイトルに遷移させる
					gameFirstStarting = true;
				}


				// シーンを変える
				SceneChange();


				// 直前のシーンと今のシーンを同じにする
				BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
			} /// if (!BASICPARAM::endFeedNow)
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
				} /// if (!preLoadScene)
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
				} /// else(!if (!preLoadScene))
			} /// else(!if (!BASICPARAM::endFeedNow))
		} /// else(!if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene))
	} /// else(!if (gameFirstStarting))
} /// void Manager::Update()