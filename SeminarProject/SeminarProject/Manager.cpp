#include "Manager.hpp"


// シーン変更
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
		SoundProcess::Load(se_save, SoundProcess::ESOUNDNAME_SE::saveOn);
		break;

	default:
		break;
	} /// switch (BASICPARAM::e_nowScene)
} /// void Manager::SceneChange()


// タイトルプロセス
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
			for (int i = 0; i != titleUINum; ++i)
			{
				GRAPHIC_RELEASE(titleUIDraw[i]);
			}
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
			for (int i = 0; i != titleUINum; ++i)
			{
				GRAPHIC_RELEASE(titleUIDraw[i]);
			}
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
				BASICPARAM::e_nowScene = ESceneNumber::SECONDLOAD;
				BASICPARAM::e_preScene = ESceneNumber::SECONDLOAD;
			} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove6))


			optionSelectMin = 0;
			optionSelectMax = 4;
			gameFirstStarting = false;
			for (int i = 0; i != titleUINum; ++i)
			{
				GRAPHIC_RELEASE(titleUIDraw[i]);
			}
		} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonus))
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// LBとRBとBACKとXボタンを同時に押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
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


// タイトル描画
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


// ムーブ1の読み込み素材の初期化
void Manager::InitMove1Load()
{
	moveStr.resize(max1 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";
		moveStr[1] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
		moveStr[2] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.myn";				// 4
		moveStr[3] = "media\\こっち\\media\\剣\\sword.myn";								// 1

		// サウンドデータ
		moveStr[4] = "media\\こっち\\media\\sound\\タイトル（オルゴール）.wyn";
		moveStr[5] = "media\\こっち\\media\\sound\\玉がポーン（音が高いほう）.wyn";
		moveStr[6] = "media\\こっち\\media\\sound\\玉がポーン.wyn";

		// キャラクターのテクスチャデータ
		moveStr[7] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[8] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
		moveStr[9] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[10] = "media\\こっち\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

		// 剣のテクスチャデータ
		moveStr[11] = "media\\こっち\\media\\剣\\whiteblack\\sword_Tex.pyn";

		// コントローラー説明
		moveStr[12] = "media\\こっち\\media\\move1\\hida.pyn";
		moveStr[13] = "media\\こっち\\media\\move1\\mighi.pyn";

		// ムーブ説明画像
		moveStr[14] = "media\\こっち\\media\\ムーブ説明\\move1.pyn";
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


// ムーブ2の読み込み素材の初期化
void Manager::InitMove2Load()
{
	moveStr.resize(max2 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\こっち\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
		moveStr[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
		moveStr[7] = "media\\こっち\\media\\ブロック\\cubeblock.myn";					// 1
		moveStr[8] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[13] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[14] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[15] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[16] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[17] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// ブロックのテクスチャ
		moveStr[18] = "media\\こっち\\media\\ブロック\\whiteblack\\tex.pyn";

		// サウンドデータ
		moveStr[19] = "media\\こっち\\media\\sound\\たま拾う音.wyn";

		// 精算機械データ
		moveStr[20] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

		// 精算機械テクスチャ
		moveStr[21] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[22] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[23] = "media\\こっち\\media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

		// 階段とそのあとの床のテクスチャデータ
		moveStr[25] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[26] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[27] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// 2D関連
		moveStr[28] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\block_2D.pyn";
		moveStr[29] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\CLPH_up.pyn";
		moveStr[30] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\gaiyou_2D.pyn";
		moveStr[31] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\kaidan_2d.pyn";
		moveStr[32] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\Terminal_2D.pyn";
		moveStr[33] = "media\\こっち\\media\\2D素材\\change\\whiteblack\\kaidan_yuka2D.pyn";

		// キャラクター周りの3DSE
		moveStr[34] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
		moveStr[35] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[36] = "media\\こっち\\media\\sound\\足音.wyn";
		moveStr[37] = "media\\こっち\\media\\sound\\着地.wyn";
		moveStr[38] = "media\\こっち\\media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[39] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[40] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[41] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

		// ドロップアイテムのSEの二種類目
		moveStr[42] = "media\\こっち\\media\\sound\\たま拾う音2.wyn";

		// 次のステージでのBGMを流す
		moveStr[43] = "media\\こっち\\media\\sound\\通常bgm.wyn";

		// 操作の説明
		moveStr[44] = "media\\こっち\\media\\move2\\attackTrans.pyn";
		moveStr[45] = "media\\こっち\\media\\move2\\jumpTrans.pyn";
		moveStr[46] = "media\\こっち\\media\\move2\\fastSpeedTrans.pyn";
		moveStr[47] = "media\\こっち\\media\\move2\\optionTrans.pyn";

		// ムーブの説明
		moveStr[48] = "media\\こっち\\media\\ムーブ説明\\move2.pyn";
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


// ムーブ3の読み込み素材の初期化
void Manager::InitMove3Load()
{
	moveStr.resize(max3 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\こっち\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
		moveStr[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
		moveStr[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// サウンドデータ
		moveStr[17] = "media\\こっち\\media\\sound\\たま拾う音.wyn";

		// 精算機械データ
		moveStr[18] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

		// 精算機械テクスチャ
		moveStr[19] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[20] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[21] = "media\\こっち\\media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[22] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

		// 階段とそのあとの床のテクスチャデータ
		moveStr[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[24] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[25] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[26] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
		moveStr[27] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[28] = "media\\こっち\\media\\sound\\足音.wyn";
		moveStr[29] = "media\\こっち\\media\\sound\\着地.wyn";
		moveStr[30] = "media\\こっち\\media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[31] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[32] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[33] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

		// ドロップアイテムのSEの二種類目
		moveStr[34] = "media\\こっち\\media\\sound\\たま拾う音2.wyn";

		// BGM
		moveStr[35] = "media\\こっち\\media\\sound\\通常bgm.wyn";

		// 敵のスライムのデータ
		moveStr[36] = "media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.myn";
		moveStr[37] = "media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn";

		// 敵のクレヨンヒューマンのデータ
		moveStr[38] = "media\\こっち\\media\\move3\\人型クレヨン\\kureyon_,motionALL.myn";
		moveStr[39] = "media\\こっち\\media\\move3\\人型クレヨン\\kureyon_,motionALL.fbm\\normal\\kre.pyn";

		// ドロップアイテムのデータ
		moveStr[40] = "media\\こっち\\media\\move3\\インク的な\\ink.myn";
		moveStr[41] = "media\\こっち\\media\\move3\\インク的な\\correction\\normal\\ink.pyn";

		// ダメージ演出画像
		moveStr[42] = "media\\こっち\\media\\damage\\damage1\\whiteblack.pyn";
		moveStr[43] = "media\\こっち\\media\\damage\\damage2\\whiteblack.pyn";
		moveStr[44] = "media\\こっち\\media\\damage\\damage3\\whiteblack.pyn";
		moveStr[45] = "media\\こっち\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[46] = "media\\こっち\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[47] = "media\\こっち\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[48] = "media\\こっち\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[49] = "media\\こっち\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[50] = "media\\こっち\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[51] = "media\\こっち\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[52] = "media\\こっち\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[53] = "media\\こっち\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[54] = "media\\こっち\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// 敵の攻撃音
		moveStr[55] = "media\\こっち\\media\\sound\\殴る音（爆発）.wyn";

		// クレヨンの死ぬ音
		moveStr[56] = "media\\こっち\\media\\sound\\クレヨンの死(2).wyn";

		// 攻撃BGM
		moveStr[57] = "media\\こっち\\media\\sound\\戦闘BGM.wyn";

		// ムーブ説明画像
		moveStr[58] = "media\\こっち\\media\\ムーブ説明\\move3.pyn";

		// 精密機械での説明画像
		moveStr[59] = "media\\こっち\\media\\move3\\UI\\another.pyn";
		moveStr[60] = "media\\こっち\\media\\move3\\UI\\charaSelect.pyn";
		moveStr[61] = "media\\こっち\\media\\move3\\UI\\enemy.pyn";
		moveStr[62] = "media\\こっち\\media\\move3\\UI\\stairs.pyn";
		moveStr[63] = "media\\こっち\\media\\move3\\UI\\stairsRoad.pyn";
		moveStr[64] = "media\\こっち\\media\\move3\\UI\\streetLight.pyn";
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


// ムーブ4の読み込み素材の初期化
void Manager::InitMove4Load()
{
	moveStr.resize(max4 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\こっち\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
		moveStr[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
		moveStr[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// 精算機械データ
		moveStr[17] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

		// 精算機械テクスチャ
		moveStr[18] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[20] = "media\\こっち\\media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[21] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

		// 階段とそのあとの床のテクスチャデータ
		moveStr[22] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[25] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
		moveStr[26] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[27] = "media\\こっち\\media\\sound\\足音.wyn";
		moveStr[28] = "media\\こっち\\media\\sound\\着地.wyn";
		moveStr[29] = "media\\こっち\\media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[30] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[31] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[32] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

		// BGM
		moveStr[33] = "media\\こっち\\media\\sound\\通常bgm.wyn";

		// 人のデータ
		moveStr[34] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.myn";
		moveStr[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// 敵のデータ
		moveStr[36] = "media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.myn";
		moveStr[37] = "media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";

		// 攻撃BGM
		moveStr[38] = "media\\こっち\\media\\sound\\戦闘BGM.wyn";

		// ムーブの説明画像
		moveStr[39] = "media\\こっち\\media\\ムーブ説明\\move4.pyn";

		// ダメージ演出画像
		moveStr[40] = "media\\こっち\\media\\damage\\damage1\\whiteblack.pyn";
		moveStr[41] = "media\\こっち\\media\\damage\\damage2\\whiteblack.pyn";
		moveStr[42] = "media\\こっち\\media\\damage\\damage3\\whiteblack.pyn";
		moveStr[43] = "media\\こっち\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[44] = "media\\こっち\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[45] = "media\\こっち\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[46] = "media\\こっち\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[47] = "media\\こっち\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[48] = "media\\こっち\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[49] = "media\\こっち\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[50] = "media\\こっち\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[51] = "media\\こっち\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[52] = "media\\こっち\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// 敵の攻撃音
		moveStr[53] = "media\\こっち\\media\\sound\\殴る音（爆発）.wyn";
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


// ムーブ3の行動次第でムーブ4の読み込む素材を更新
void Manager::Move4TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\normal\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\normal\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\normal\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\P\\P.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\P\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\P\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\P\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\D\\D.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\D\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\D\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[35] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\D\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move4TextureReload()


// ムーブ5の読み込み素材の初期化
void Manager::InitMove5Load()
{
	moveStr.resize(max5 + 1);
	{
		// モデルデータ
		moveStr[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
		moveStr[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\こっち\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
		moveStr[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
		moveStr[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";

		// キャラのテクスチャデータ
		moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// 階段のテクスチャデータ
		moveStr[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// 街灯のテクスチャデータ
		moveStr[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";

		// スカイボックスのテクスチャデータ
		moveStr[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";

		// 精算機械データ
		moveStr[17] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2

		// 精算機械テクスチャ
		moveStr[18] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";

		// 精密機械の補助説明
		moveStr[20] = "media\\こっち\\media\\Terminal\\push.pyn";

		// 階段とそのあとの床データ
		moveStr[21] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2

		// 階段とそのあとの床のテクスチャデータ
		moveStr[22] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";

		// 階段と床のあたり判定データ
		moveStr[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";

		// キャラクター周りの3DSE
		moveStr[25] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
		moveStr[26] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
		moveStr[27] = "media\\こっち\\media\\sound\\足音.wyn";
		moveStr[28] = "media\\こっち\\media\\sound\\着地.wyn";
		moveStr[29] = "media\\こっち\\media\\sound\\着地２.wyn";

		// キャラクターの攻撃の音
		moveStr[30] = "media\\こっち\\media\\sound\\ピアノコンボ一発目.wyn";
		moveStr[31] = "media\\こっち\\media\\sound\\ピアノコンボ二発目.wyn";
		moveStr[32] = "media\\こっち\\media\\sound\\ピアノコンボ三発目.wyn";

		// BGM
		moveStr[33] = "media\\こっち\\media\\sound\\通常bgm.wyn";

		// 敵のデータ
		moveStr[34] = "media\\こっち\\media\\childCLPH\\sd_,motionALL.myn";
		moveStr[35] = "media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\whiteblack\\SDchar.pyn";

		// 一般人のデータ
		moveStr[36] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.myn";
		moveStr[37] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// ムーブの説明画像
		moveStr[38] = "media\\こっち\\media\\ムーブ説明\\move5.pyn";
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
	}
} /// void Manager::InitMove5Load()


// ムーブ4の行動次第でムーブ5の読み込む素材を更新
void Manager::Move5TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\normal\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\normal\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\normal\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\normal\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\P\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\P\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\P\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\P\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラのテクスチャデータ
			moveStr[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\D\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// 街灯のテクスチャデータ
			moveStr[14] = "media\\こっち\\media\\街灯\\D\\body_col.pyn";
			moveStr[15] = "media\\こっち\\media\\街灯\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// 階段とそのあとの床のテクスチャデータ
			moveStr[22] = "media\\こっち\\media\\階段と床合体\\D\\kaidan.pyn";
			moveStr[23] = "media\\こっち\\media\\階段と床合体\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// 階段のテクスチャデータ
			moveStr[13] = "media\\こっち\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 人のデータ
			moveStr[37] = "media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn";

			// スカイボックスのテクスチャデータ
			moveStr[16] = "media\\こっち\\media\\スカイボックス\\D\\BlueSky.byn";

			// 精算機械テクスチャ
			moveStr[18] = "media\\こっち\\media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\こっち\\media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move5TextureReload()


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
			optionSelectMax = 8;
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
			// SEを流す
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveOn);


			// セーブする
			FileSaveLoad::Save();
		}
		// ゲーム終了にカーソルがあったとき
		else if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			// ゲームを終了する
			gameEnd = true;
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
		// 遠近法カメラにカーソルがあったとき
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


// オプション画面の描画
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


		// セーブする
		DrawGraph(95, 760, optionDrawMedia[static_cast<int>(EOptionDraw::dataSave)], false);
		if (optionSelectButtonNum == EOptionSelectButton::DataSave)
		{
			DrawBox(95 + 5, 760 + 5, 95 + 450 - 5, 760 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 760 + 4, 95 + 450 - 4, 760 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 760 + 3, 95 + 450 - 3, 760 + 69 - 3, GetColor(50, 50, 200), false);
		}


		// ゲームを終了する
		DrawGraph(95, 880, optionDrawMedia[static_cast<int>(EOptionDraw::gameEnd)], false);
		if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			DrawBox(95 + 5, 880 + 5, 95 + 450 - 5, 880 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 880 + 4, 95 + 450 - 4, 880 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 880 + 3, 95 + 450 - 3, 880 + 69 - 3, GetColor(50, 50, 200), false);
		}
	} /// else if (optionPageNowNumber == 1)
} /// void Manager::OptionDraw()


// コンストラクタ
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
		LoadFile::MyLoad("media\\こっち\\media\\First\\gameStart.pyn", titleUIDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\dataLoad.pyn", titleUIDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\gameEnd.pyn", titleUIDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake.pyn", titleUIDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake2.pyn", titleUIDraw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake3.pyn", titleUIDraw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake4.pyn", titleUIDraw[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake5.pyn", titleUIDraw[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\First\\omake6.pyn", titleUIDraw[8], ELOADFILE::graph);
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
	LoadFile::MyLoad("media\\こっち\\media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
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
	LoadFile::MyLoad("media\\こっち\\media\\option\\gameEnd.pyn", optionDrawMedia[15], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\save.pyn", optionDrawMedia[16], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\yes.pyn", optionDrawMedia[17], ELOADFILE::graph);
	LoadFile::MyLoad("media\\こっち\\media\\option\\no.pyn", optionDrawMedia[18], ELOADFILE::graph);


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


// デストラクタ
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


// 更新
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
					} /// if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
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
					} /// else(!if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/))
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
						p_baseMove->CameraProcess();			// カメラ切り替え
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