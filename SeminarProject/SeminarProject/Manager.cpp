#include "Manager.hpp"


// �V�[���ύX
void Manager::SceneChange()
{
	// ���̃V�[��
	switch (BASICPARAM::e_nowScene)
	{
	// ���[�u1�̃��[�h
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u1
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


	// ���[�u2�̃��[�h
	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u2
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


	// ���[�u3�̃��[�h
	case ESceneNumber::THIRDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u3
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


	// ���[�u4�̃��[�h
	case ESceneNumber::FOURTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u4
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


	// ���[�u5�̃��[�h
	case ESceneNumber::FIFTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u5
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


// �^�C�g���v���Z�X
void Manager::TitleProcess()
{
	// �������������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// �Q�[�����J�n����̎�
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
		// ���[�h����Ƃ�
		else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::load))
		{
			// ���[�u��3�ȍ~��������e�N�X�`���̐F��ʏ�F�ɂ��Ă���
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
		// �Q�[�����I������Ƃ�
		else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
		{
			gameEnd = true;
		} /// else if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
		// ���܂��̂Ƃ�
		else
		{
			// ���[�u�Q��I�����Ă�����
			if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::bonusMove2))
			{
				BASICPARAM::e_nowScene = ESceneNumber::SECONDLOAD;
				BASICPARAM::e_preScene = ESceneNumber::SECONDLOAD;
			}
			// ���[�u�R��I�����Ă�����
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
			// ���[�u�S��I�����Ă�����
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
			// ���[�u�T��I�����Ă�����
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
			// ���[�u�U��I�����Ă�����
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


	// LB��RB��BACK��X�{�^���𓯎��ɉ�������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) >= 1
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		playBonus = true;
		optionSelectMax = 8;
	}


	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
	// ���X�e�B�b�N����ɓ|������
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if (optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	// ���X�e�B�b�N�����ɓ|������
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	// ���X�e�B�b�N����ɘM���ĂȂ�������
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}


	// ��ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[0] == 1)
	{
		// �J�[�\������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
	}
	// ���ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[1] == 1)
	{
		// �J�[�\�������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
	}
	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
} /// void Manager::TitleProcess()


// �^�C�g���`��
void Manager::TitleDraw()
{
	// �Q�[���J�n
	DrawGraph(760, 340, titleUIDraw[static_cast<int>(ETitleDraw::firstGame)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::firstGame))
	{
		DrawBox(760 + 5, 340 + 5, 760 + 400 - 5, 340 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 340 + 4, 760 + 400 - 4, 340 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 340 + 3, 760 + 400 - 3, 340 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// ���[�h
	DrawGraph(760, 471, titleUIDraw[static_cast<int>(ETitleDraw::load)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::load))
	{
		DrawBox(760 + 5, 471 + 5, 760 + 400 - 5, 471 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 471 + 4, 760 + 400 - 4, 471 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 471 + 3, 760 + 400 - 3, 471 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// �Q�[���I��
	DrawGraph(760, 600, titleUIDraw[static_cast<int>(ETitleDraw::gameEnd)], false);
	if (optionSelectButtonNum == static_cast<EOptionSelectButton>(ETitleDraw::gameEnd))
	{
		DrawBox(760 + 5, 600 + 5, 760 + 400 - 5, 600 + 69 - 5, GetColor(50, 50, 200), false);
		DrawBox(760 + 4, 600 + 4, 760 + 400 - 4, 600 + 69 - 4, GetColor(50, 50, 200), false);
		DrawBox(760 + 3, 600 + 3, 760 + 400 - 3, 600 + 69 - 3, GetColor(50, 50, 200), false);
	}


	// ���܂��R�}���h��ł��Ă�����
	if (playBonus)
	{
		// ���܂�
		DrawGraph(760, 730, titleUIDraw[static_cast<int>(optionSelectButtonNum)], false);
		if (optionSelectButtonNum >= static_cast<EOptionSelectButton>(ETitleDraw::bonus))
		{
			DrawBox(760 + 5, 730 + 5, 760 + 400 - 5, 730 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(760 + 4, 730 + 4, 760 + 400 - 4, 730 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(760 + 3, 730 + 3, 760 + 400 - 3, 730 + 69 - 3, GetColor(50, 50, 200), false);
		}
	}
} /// void Manager::TitleDraw()


// ���[�u1�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove1Load()
{
	moveStr.resize(max1 + 1);
	{
		// ���f���f�[�^
		moveStr[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
		moveStr[1] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
		moveStr[2] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.myn";				// 4
		moveStr[3] = "media\\������\\media\\��\\sword.myn";								// 1

		// �T�E���h�f�[�^
		moveStr[4] = "media\\������\\media\\sound\\�^�C�g���i�I���S�[���j.wyn";
		moveStr[5] = "media\\������\\media\\sound\\�ʂ��|�[���i���������ق��j.wyn";
		moveStr[6] = "media\\������\\media\\sound\\�ʂ��|�[��.wyn";

		// �L�����N�^�[�̃e�N�X�`���f�[�^
		moveStr[7] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[8] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
		moveStr[9] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[10] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

		// ���̃e�N�X�`���f�[�^
		moveStr[11] = "media\\������\\media\\��\\whiteblack\\sword_Tex.pyn";

		// �R���g���[���[����
		moveStr[12] = "media\\������\\media\\move1\\hida.pyn";
		moveStr[13] = "media\\������\\media\\move1\\mighi.pyn";

		// ���[�u�����摜
		moveStr[14] = "media\\������\\media\\���[�u����\\move1.pyn";
	}


	loadType.resize(max1 + 1);
	{
		// ���f���f�[�^
		loadType[0] = ELOADFILE::mv1model;
		loadType[1] = ELOADFILE::mv1model;
		loadType[2] = ELOADFILE::mv1model;
		loadType[3] = ELOADFILE::mv1model;

		// �T�E���h�f�[�^
		loadType[4] = ELOADFILE::soundStream;
		loadType[5] = ELOADFILE::soundmem;
		loadType[6] = ELOADFILE::soundmem;

		// �L�����N�^�[�̃e�N�X�`���f�[�^
		loadType[7] = ELOADFILE::graph;
		loadType[8] = ELOADFILE::graph;
		loadType[9] = ELOADFILE::graph;
		loadType[10] = ELOADFILE::graph;

		// ���̃e�N�X�`���f�[�^
		loadType[11] = ELOADFILE::graph;

		// �R���g���[���[����
		loadType[12] = ELOADFILE::graph;
		loadType[13] = ELOADFILE::graph;

		loadType[14] = ELOADFILE::graph;
	}
} /// void Manager::InitMove1Load()


// ���[�u2�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove2Load()
{
	moveStr.resize(max2 + 1);
	{
		// ���f���f�[�^
		moveStr[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
		moveStr[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\������\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
		moveStr[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
		moveStr[7] = "media\\������\\media\\�u���b�N\\cubeblock.myn";					// 1
		moveStr[8] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

		// �L�����̃e�N�X�`���f�[�^
		moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[13] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// �K�i�̃e�N�X�`���f�[�^
		moveStr[14] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// �X���̃e�N�X�`���f�[�^
		moveStr[15] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
		moveStr[16] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

		// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
		moveStr[17] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

		// �u���b�N�̃e�N�X�`��
		moveStr[18] = "media\\������\\media\\�u���b�N\\whiteblack\\tex.pyn";

		// �T�E���h�f�[�^
		moveStr[19] = "media\\������\\media\\sound\\���܏E����.wyn";

		// ���Z�@�B�f�[�^
		moveStr[20] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

		// ���Z�@�B�e�N�X�`��
		moveStr[21] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[22] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

		// �����@�B�̕⏕����
		moveStr[23] = "media\\������\\media\\Terminal\\push.pyn";

		// �K�i�Ƃ��̂��Ƃ̏��f�[�^
		moveStr[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

		// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
		moveStr[25] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
		moveStr[26] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

		// �K�i�Ə��̂����蔻��f�[�^
		moveStr[27] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

		// 2D�֘A
		moveStr[28] = "media\\������\\media\\2D�f��\\change\\whiteblack\\block_2D.pyn";
		moveStr[29] = "media\\������\\media\\2D�f��\\change\\whiteblack\\CLPH_up.pyn";
		moveStr[30] = "media\\������\\media\\2D�f��\\change\\whiteblack\\gaiyou_2D.pyn";
		moveStr[31] = "media\\������\\media\\2D�f��\\change\\whiteblack\\kaidan_2d.pyn";
		moveStr[32] = "media\\������\\media\\2D�f��\\change\\whiteblack\\Terminal_2D.pyn";
		moveStr[33] = "media\\������\\media\\2D�f��\\change\\whiteblack\\kaidan_yuka2D.pyn";

		// �L�����N�^�[�����3DSE
		moveStr[34] = "media\\������\\media\\sound\\�W�����v.wyn";
		moveStr[35] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
		moveStr[36] = "media\\������\\media\\sound\\����.wyn";
		moveStr[37] = "media\\������\\media\\sound\\���n.wyn";
		moveStr[38] = "media\\������\\media\\sound\\���n�Q.wyn";

		// �L�����N�^�[�̍U���̉�
		moveStr[39] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
		moveStr[40] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
		moveStr[41] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

		// �h���b�v�A�C�e����SE�̓��ޖ�
		moveStr[42] = "media\\������\\media\\sound\\���܏E����2.wyn";

		// ���̃X�e�[�W�ł�BGM�𗬂�
		moveStr[43] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

		// ����̐���
		moveStr[44] = "media\\������\\media\\move2\\attackTrans.pyn";
		moveStr[45] = "media\\������\\media\\move2\\jumpTrans.pyn";
		moveStr[46] = "media\\������\\media\\move2\\fastSpeedTrans.pyn";
		moveStr[47] = "media\\������\\media\\move2\\optionTrans.pyn";

		// ���[�u�̐���
		moveStr[48] = "media\\������\\media\\���[�u����\\move2.pyn";
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


// ���[�u3�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove3Load()
{
	moveStr.resize(max3 + 1);
	{
		// ���f���f�[�^
		moveStr[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
		moveStr[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\������\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
		moveStr[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
		moveStr[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

		// �L�����̃e�N�X�`���f�[�^
		moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// �K�i�̃e�N�X�`���f�[�^
		moveStr[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// �X���̃e�N�X�`���f�[�^
		moveStr[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

		// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
		moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

		// �T�E���h�f�[�^
		moveStr[17] = "media\\������\\media\\sound\\���܏E����.wyn";

		// ���Z�@�B�f�[�^
		moveStr[18] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

		// ���Z�@�B�e�N�X�`��
		moveStr[19] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[20] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

		// �����@�B�̕⏕����
		moveStr[21] = "media\\������\\media\\Terminal\\push.pyn";

		// �K�i�Ƃ��̂��Ƃ̏��f�[�^
		moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

		// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
		moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
		moveStr[24] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

		// �K�i�Ə��̂����蔻��f�[�^
		moveStr[25] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

		// �L�����N�^�[�����3DSE
		moveStr[26] = "media\\������\\media\\sound\\�W�����v.wyn";
		moveStr[27] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
		moveStr[28] = "media\\������\\media\\sound\\����.wyn";
		moveStr[29] = "media\\������\\media\\sound\\���n.wyn";
		moveStr[30] = "media\\������\\media\\sound\\���n�Q.wyn";

		// �L�����N�^�[�̍U���̉�
		moveStr[31] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
		moveStr[32] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
		moveStr[33] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

		// �h���b�v�A�C�e����SE�̓��ޖ�
		moveStr[34] = "media\\������\\media\\sound\\���܏E����2.wyn";

		// BGM
		moveStr[35] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

		// �G�̃X���C���̃f�[�^
		moveStr[36] = "media\\������\\media\\move3\\�C���N�X���C��\\ink_slime_motionALL.myn";
		moveStr[37] = "media\\������\\media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn";

		// �G�̃N�������q���[�}���̃f�[�^
		moveStr[38] = "media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.myn";
		moveStr[39] = "media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\normal\\kre.pyn";

		// �h���b�v�A�C�e���̃f�[�^
		moveStr[40] = "media\\������\\media\\move3\\�C���N�I��\\ink.myn";
		moveStr[41] = "media\\������\\media\\move3\\�C���N�I��\\correction\\normal\\ink.pyn";

		// �_���[�W���o�摜
		moveStr[42] = "media\\������\\media\\damage\\damage1\\whiteblack.pyn";
		moveStr[43] = "media\\������\\media\\damage\\damage2\\whiteblack.pyn";
		moveStr[44] = "media\\������\\media\\damage\\damage3\\whiteblack.pyn";
		moveStr[45] = "media\\������\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[46] = "media\\������\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[47] = "media\\������\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[48] = "media\\������\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[49] = "media\\������\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[50] = "media\\������\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[51] = "media\\������\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[52] = "media\\������\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[53] = "media\\������\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[54] = "media\\������\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// �G�̍U����
		moveStr[55] = "media\\������\\media\\sound\\���鉹�i�����j.wyn";

		// �N�������̎��ʉ�
		moveStr[56] = "media\\������\\media\\sound\\�N�������̎�(2).wyn";

		// �U��BGM
		moveStr[57] = "media\\������\\media\\sound\\�퓬BGM.wyn";

		// ���[�u�����摜
		moveStr[58] = "media\\������\\media\\���[�u����\\move3.pyn";

		// �����@�B�ł̐����摜
		moveStr[59] = "media\\������\\media\\move3\\UI\\another.pyn";
		moveStr[60] = "media\\������\\media\\move3\\UI\\charaSelect.pyn";
		moveStr[61] = "media\\������\\media\\move3\\UI\\enemy.pyn";
		moveStr[62] = "media\\������\\media\\move3\\UI\\stairs.pyn";
		moveStr[63] = "media\\������\\media\\move3\\UI\\stairsRoad.pyn";
		moveStr[64] = "media\\������\\media\\move3\\UI\\streetLight.pyn";
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


// ���[�u4�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove4Load()
{
	moveStr.resize(max4 + 1);
	{
		// ���f���f�[�^
		moveStr[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
		moveStr[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\������\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
		moveStr[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
		moveStr[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

		// �L�����̃e�N�X�`���f�[�^
		moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// �K�i�̃e�N�X�`���f�[�^
		moveStr[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// �X���̃e�N�X�`���f�[�^
		moveStr[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

		// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
		moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

		// ���Z�@�B�f�[�^
		moveStr[17] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

		// ���Z�@�B�e�N�X�`��
		moveStr[18] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

		// �����@�B�̕⏕����
		moveStr[20] = "media\\������\\media\\Terminal\\push.pyn";

		// �K�i�Ƃ��̂��Ƃ̏��f�[�^
		moveStr[21] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

		// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
		moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

		// �K�i�Ə��̂����蔻��f�[�^
		moveStr[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

		// �L�����N�^�[�����3DSE
		moveStr[25] = "media\\������\\media\\sound\\�W�����v.wyn";
		moveStr[26] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
		moveStr[27] = "media\\������\\media\\sound\\����.wyn";
		moveStr[28] = "media\\������\\media\\sound\\���n.wyn";
		moveStr[29] = "media\\������\\media\\sound\\���n�Q.wyn";

		// �L�����N�^�[�̍U���̉�
		moveStr[30] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
		moveStr[31] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
		moveStr[32] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

		// BGM
		moveStr[33] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

		// �l�̃f�[�^
		moveStr[34] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.myn";
		moveStr[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// �G�̃f�[�^
		moveStr[36] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.myn";
		moveStr[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";

		// �U��BGM
		moveStr[38] = "media\\������\\media\\sound\\�퓬BGM.wyn";

		// ���[�u�̐����摜
		moveStr[39] = "media\\������\\media\\���[�u����\\move4.pyn";

		// �_���[�W���o�摜
		moveStr[40] = "media\\������\\media\\damage\\damage1\\whiteblack.pyn";
		moveStr[41] = "media\\������\\media\\damage\\damage2\\whiteblack.pyn";
		moveStr[42] = "media\\������\\media\\damage\\damage3\\whiteblack.pyn";
		moveStr[43] = "media\\������\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
		moveStr[44] = "media\\������\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
		moveStr[45] = "media\\������\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
		moveStr[46] = "media\\������\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
		moveStr[47] = "media\\������\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
		moveStr[48] = "media\\������\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
		moveStr[49] = "media\\������\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
		moveStr[50] = "media\\������\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
		moveStr[51] = "media\\������\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
		moveStr[52] = "media\\������\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

		// �G�̍U����
		moveStr[53] = "media\\������\\media\\sound\\���鉹�i�����j.wyn";
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


// ���[�u3�̍s������Ń��[�u4�̓ǂݍ��ޑf�ނ��X�V
void Manager::Move4TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\normal\\normal.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\normal\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\normal\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\normal\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\P\\P.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\P\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\P\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\P\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\P\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\D\\D.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\D\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\D\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\D\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\D\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move4TextureReload()


// ���[�u5�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove5Load()
{
	moveStr.resize(max5 + 1);
	{
		// ���f���f�[�^
		moveStr[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
		moveStr[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
		moveStr[2] = "media\\������\\media\\paneru\\paneru.myn";
		moveStr[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
		moveStr[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
		moveStr[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
		moveStr[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
		moveStr[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

		// �L�����̃e�N�X�`���f�[�^
		moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
		moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
		moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
		moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
		moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

		// �K�i�̃e�N�X�`���f�[�^
		moveStr[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

		// �X���̃e�N�X�`���f�[�^
		moveStr[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
		moveStr[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

		// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
		moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

		// ���Z�@�B�f�[�^
		moveStr[17] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

		// ���Z�@�B�e�N�X�`��
		moveStr[18] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
		moveStr[19] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

		// �����@�B�̕⏕����
		moveStr[20] = "media\\������\\media\\Terminal\\push.pyn";

		// �K�i�Ƃ��̂��Ƃ̏��f�[�^
		moveStr[21] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

		// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
		moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
		moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

		// �K�i�Ə��̂����蔻��f�[�^
		moveStr[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

		// �L�����N�^�[�����3DSE
		moveStr[25] = "media\\������\\media\\sound\\�W�����v.wyn";
		moveStr[26] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
		moveStr[27] = "media\\������\\media\\sound\\����.wyn";
		moveStr[28] = "media\\������\\media\\sound\\���n.wyn";
		moveStr[29] = "media\\������\\media\\sound\\���n�Q.wyn";

		// �L�����N�^�[�̍U���̉�
		moveStr[30] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
		moveStr[31] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
		moveStr[32] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

		// BGM
		moveStr[33] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

		// �G�̃f�[�^
		moveStr[34] = "media\\������\\media\\childCLPH\\sd_,motionALL.myn";
		moveStr[35] = "media\\������\\media\\childCLPH\\sd_,motionALL.fbm\\whiteblack\\SDchar.pyn";

		// ��ʐl�̃f�[�^
		moveStr[36] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.myn";
		moveStr[37] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

		// ���[�u�̐����摜
		moveStr[38] = "media\\������\\media\\���[�u����\\move5.pyn";
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


// ���[�u4�̍s������Ń��[�u5�̓ǂݍ��ޑf�ނ��X�V
void Manager::Move5TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\������\\media\\childCLPH\\sd_,motionALL.fbm\\normal\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\normal\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\normal\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[37] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\normal\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\normal\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;


	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\������\\media\\childCLPH\\sd_,motionALL.fbm\\P\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\P\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\P\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[37] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\P\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\P\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\P\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			moveStr[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			moveStr[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			moveStr[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			moveStr[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			moveStr[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			moveStr[35] = "media\\������\\media\\childCLPH\\sd_,motionALL.fbm\\D\\SDchar.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			moveStr[14] = "media\\������\\media\\�X��\\D\\body_col.pyn";
			moveStr[15] = "media\\������\\media\\�X��\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			moveStr[22] = "media\\������\\media\\�K�i�Ə�����\\D\\kaidan.pyn";
			moveStr[23] = "media\\������\\media\\�K�i�Ə�����\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			moveStr[13] = "media\\������\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			moveStr[37] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\D\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			moveStr[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\D\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			moveStr[18] = "media\\������\\media\\Terminal\\D\\Terminal.pyn";
			moveStr[19] = "media\\������\\media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move5TextureReload()


void Manager::OptionProcess()
{
	///�펞-------------------------------------------------------------------------------------------------------
	// BGM���ʒ����R�}���h��I�����Ă�����
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		// �E�ɃX�e�B�b�N��|���Ă�����
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// BGM�̐ݒ艹�ʂ��グ��
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() < 1.00f ? SoundProcess::GetBGMVolumeEntire() + 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
		// ���ɃX�e�B�b�N��|���Ă�����
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// BGM�̐ݒ艹�ʂ�������
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() > 0.00f ? SoundProcess::GetBGMVolumeEntire() - 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
	}
	// SE���ʒ����R�}���h��I�����Ă�����
	else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		// 61�J�E���g�̂��т�SE��炷
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			

			// SE�𗬂�
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveOn);
			//PlaySoundMem(se_save, DX_PLAYTYPE_BACK);
		}


		// �E�ɃX�e�B�b�N��|���Ă�����
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// SE�̐ݒ艹�ʂ��グ��
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() < 1.00f ? SoundProcess::GetSEVolumeEntire() + 0.01f : SoundProcess::GetSEVolumeEntire());
		}
		// ���ɃX�e�B�b�N��|���Ă�����
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// SE�̐ݒ艹�ʂ�������
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() > 0.00f ? SoundProcess::GetSEVolumeEntire() - 0.01f : SoundProcess::GetSEVolumeEntire());
		}
	}
	///�펞-------------------------------------------------------------------------------------------------------


	///����-------------------------------------------------------------------------------------------------------
	// ����{�^�����������Ƃ��̓���
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// BGM�ɃJ�[�\�����������Ƃ�
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			// BGM�ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::BGMSelect;
			optionSelectMin = 10;
			optionSelectMax = 10;
		}
		// SE�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// SE�ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::SESelect;
			optionSelectMin = 11;
			optionSelectMax = 11;
		}
		// �e�N�X�`���F�̒ʏ�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			// �ʏ�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �e�N�X�`���F��P�^�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// P�^�␳�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �e�N�X�`���F��D�^�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// D�^�␳�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �F�o�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect
			&& BASICPARAM::e_nowScene >= ESceneNumber::THIRDMOVE)
		{
			// �ʏ�F�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::ColorNormal;
			optionSelectMin = 7;
			optionSelectMax = 8;
		}
		// �T�E���h�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			// BGM�ɃJ�[�\�����ڂ�
			SoundProcess::SetOptionMenuNow(false);				// �T�E���h�̉��ʂ��I�v�V�����p�����߂�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// BGM�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGM�̐ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// SE�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SE�̐ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// �J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			// ���ߖ@�J�����Ɉڂ�
			optionSelectButtonNum = EOptionSelectButton::CameraPerspective;
			optionSelectMin = 12;
			optionSelectMax = 15;
		}
		// ���ߖ@�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			// �J���������ߖ@�J�����ɐݒ肷��
			BASICPARAM::nowCameraOrtho = false;
		}
		// ���ˉe�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			// �J�����𐳎ˉe�J�����ɐݒ肷��
			BASICPARAM::nowCameraOrtho = true;
		}
		// ����]�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			// ����]�̃X�e�B�b�N�������t�ɂ���
			BASICPARAM::cameraHorizonReturn = !BASICPARAM::cameraHorizonReturn;
		}
		// �c��]�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// �c��]�̃X�e�B�b�N�������t�ɂ���
			BASICPARAM::cameraVerticalReturn = !BASICPARAM::cameraVerticalReturn;
		}
		// �Z�[�u�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::DataSave)
		{
			// SE�𗬂�
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveOn);


			// �Z�[�u����
			FileSaveLoad::Save();
		}
		// �Q�[���I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			// �Q�[�����I������
			gameEnd = true;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	///����------------------------------------------------------------------------------------------------------


	///�߂�-------------------------------------------------------------------------------------------------------
	// �߂�{�^�����������Ƃ��̓���
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// BGM�ɃJ�[�\�����������Ƃ�
		if (optionSelectButtonNum == EOptionSelectButton::BGM
			|| optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// �T�E���h�ɃJ�[�\�����ڂ�
			SoundProcess::SetOptionMenuNow(true);					// �T�E���h�̉��ʂ��I�v�V�����p����ɖ߂�
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// �ʏ�F�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal
			|| optionSelectButtonNum == EOptionSelectButton::ColorP
			|| optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// �F�o�I���ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
		// BGM���ʒ����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGM�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// SE���ʒ����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SE�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 5;
			optionSelectMax = 6;
		}
		// ���ߖ@�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective
			|| optionSelectButtonNum == EOptionSelectButton::CameraOrtho
			|| optionSelectButtonNum == EOptionSelectButton::CameraHReturn
			|| optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// �J�����ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 4;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	///�߂�------------------------------------------------------------------------------------------------------


	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
	// ���X�e�B�b�N����ɓ|������
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if(optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	// ���X�e�B�b�N�����ɓ|������
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	// ���X�e�B�b�N����ɘM���ĂȂ�������
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}


	// ��ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[0] == 1)
	{
		// �J�[�\������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect) optionPageNowNumber = 0;
	}
	// ���ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[1] == 1)
	{
		// �J�[�\�������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::Camera) optionPageNowNumber = 1;
	}
	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
} /// void Manager::OptionProcess()


// �I�v�V������ʂ̕`��
void Manager::OptionDraw()
{
	// �w�i
	DrawGraph(0, 0, gaussianScreen, false);


	//�@���f���\��
	p_baseMove->OptionActorModel();


	// �I�v�V��������߂�����摜
	DrawGraph(1600, 800, optionDrawMedia[static_cast<int>(EOptionDraw::optionEnd)], true);


	// ���ڂ̃I�v�V�����̂Ƃ�
	if (optionPageNowNumber == 0)
	{
		/// �T�E���h�֌W�I�v�V����---------------------------------------------------------------
		// UI:Sound
		DrawGraph(95, 95, optionDrawMedia[static_cast<int>(EOptionDraw::Sound)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			DrawBox(95 + 5, 95 + 5, 95 + 211 - 5, 95 + 86 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 95 + 4, 95 + 211 - 4, 95 + 86 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 95 + 3, 95 + 211 - 3, 95 + 86 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGM
		DrawGraph(381, 114, optionDrawMedia[static_cast<int>(EOptionDraw::BGM)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			DrawBox(381 + 5, 114 + 5, 381 + 87 - 5, 114 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(381 + 4, 114 + 4, 381 + 87 - 4, 114 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(381 + 3, 114 + 3, 381 + 87 - 3, 114 + 58 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGM�o�[
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(200, 200, 200), true);
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
		// �J�[�\�����������Ă�����
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
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			DrawBox(385 + 5, 266 + 5, 385 + 86 - 5, 266 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 266 + 4, 385 + 86 - 4, 266 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 266 + 3, 385 + 86 - 3, 266 + 58 - 3, GetColor(50, 50, 200), false);
		}

		// UI:SE�o�[
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			DrawBox(548 + 5, 255 + 5, 548 + 547 - 5, 255 + 78 - 5, GetColor(50, 50, 200), false);
			DrawBox(548 + 4, 255 + 4, 548 + 547 - 4, 255 + 78 - 4, GetColor(50, 50, 200), false);
			DrawBox(548 + 3, 255 + 3, 548 + 547 - 3, 255 + 78 - 3, GetColor(50, 50, 200), false);
		}
		DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 + 78 + 10, GetColor(255, 255, 255), true);
		/// �T�E���h�֌W�I�v�V����---------------------------------------------------------------


		/// �F�o�Ɋւ���I�v�V����-----------------------------------------------------------------------
		// �F�o�␳�ł��郀�[�u����Ȃ�������
		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);


		// UI:�F�o����
		DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);


		// UI:�ʏ�F
		DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			DrawBox(385 + 5, 427 + 5, 385 + 83 - 5, 427 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 427 + 4, 385 + 83 - 4, 427 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 427 + 3, 385 + 83 - 3, 427 + 58 - 3, GetColor(50, 50, 200), false);
		}


		// UI:P�^
		DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			DrawBox(386 + 5, 550 + 5, 386 + 83 - 5, 550 + 59 - 5, GetColor(50, 50, 200), false);
			DrawBox(386 + 4, 550 + 4, 386 + 83 - 4, 550 + 59 - 4, GetColor(50, 50, 200), false);
			DrawBox(386 + 3, 550 + 3, 386 + 83 - 3, 550 + 59 - 3, GetColor(50, 50, 200), false);
		}


		// UI:D�^
		DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			DrawBox(385 + 5, 682 + 5, 385 + 83 - 5, 682 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 682 + 4, 385 + 83 - 4, 682 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 682 + 3, 385 + 83 - 3, 682 + 58 - 3, GetColor(50, 50, 200), false);
		}


		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// �F�o�␳�ɃJ�[�\�����������Ă�����(�u�����h���瓦��������
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
		{
			DrawBox(96 + 5, 413 + 5, 96 + 112 - 5, 413 + 76 - 5, GetColor(50, 50, 200), false);
			DrawBox(96 + 4, 413 + 4, 96 + 112 - 4, 413 + 76 - 4, GetColor(50, 50, 200), false);
			DrawBox(96 + 3, 413 + 3, 96 + 112 - 3, 413 + 76 - 3, GetColor(50, 50, 200), false);
		}
		/// �F�o�Ɋւ���I�v�V����-----------------------------------------------------------------------


		// ���̃y�[�W
		DrawGraph(96, 815, optionDrawMedia[static_cast<int>(EOptionDraw::nextPage)], false);
	} /// if (optionPageNowNumber == 0)
	// ��y�[�W�ڂ̎�
	else if (optionPageNowNumber == 1)
	{
		// �O�̃y�[�W��
		DrawGraph(96, 95, optionDrawMedia[static_cast<int>(EOptionDraw::prevPage)], false);


		/// �J�����̊ւ���I�v�V����------------------------------------------------
		// �J����
		DrawGraph(95, 247, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
		if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			DrawBox(95 + 5, 247 + 5, 95 + 109 - 5, 247 + 68 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 247 + 4, 95 + 109 - 4, 247 + 68 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 247 + 3, 95 + 109 - 3, 247 + 68 - 3, GetColor(50, 50, 200), false);
		}


		// ���ߖ@
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 267, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			DrawBox(385 + 5, 267 + 5, 385 + 83 - 5, 267 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 267 + 4, 385 + 83 - 4, 267 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 267 + 3, 385 + 83 - 3, 267 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// ���ˉe
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 400, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			DrawBox(385 + 5, 400 + 5, 385 + 83 - 5, 400 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 400 + 4, 385 + 83 - 4, 400 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 400 + 3, 385 + 83 - 3, 400 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// �����]
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 513, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			DrawBox(385 + 5, 513 + 5, 385 + 83 - 5, 513 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 513 + 4, 385 + 83 - 4, 513 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 513 + 3, 385 + 83 - 3, 513 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// �c���]
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 646, optionDrawMedia[static_cast<int>(EOptionDraw::VerticalReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			DrawBox(385 + 5, 646 + 5, 385 + 83 - 5, 646 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 646 + 4, 385 + 83 - 4, 646 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 646 + 3, 385 + 83 - 3, 646 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// �Z�[�u����
		DrawGraph(95, 760, optionDrawMedia[static_cast<int>(EOptionDraw::dataSave)], false);
		if (optionSelectButtonNum == EOptionSelectButton::DataSave)
		{
			DrawBox(95 + 5, 760 + 5, 95 + 450 - 5, 760 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 760 + 4, 95 + 450 - 4, 760 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 760 + 3, 95 + 450 - 3, 760 + 69 - 3, GetColor(50, 50, 200), false);
		}


		// �Q�[�����I������
		DrawGraph(95, 880, optionDrawMedia[static_cast<int>(EOptionDraw::gameEnd)], false);
		if (optionSelectButtonNum == EOptionSelectButton::GameEnd)
		{
			DrawBox(95 + 5, 880 + 5, 95 + 450 - 5, 880 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 880 + 4, 95 + 450 - 4, 880 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 880 + 3, 95 + 450 - 3, 880 + 69 - 3, GetColor(50, 50, 200), false);
		}
	} /// else if (optionPageNowNumber == 1)
} /// void Manager::OptionDraw()


// �R���X�g���N�^
Manager::Manager()
{
	// ������
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
	

	// �������̏�����
	p_baseMove = nullptr;
	p_loadThread = nullptr;
	moveStr.clear();
	loadType.clear();
	for (int i = 0; i != titleUINum; ++i)
	{
		titleUIDraw[i] = -1;
	}


	// �ŏ��̃��[�h�𐶐�
	p_loadThread = new LoadThread();
	preLoadScene = false;

	
	/// �Q�[���̃^�C�g���Ɋւ���-------------------------------------------------------------------------------------
	gameFirstStarting = FileSaveLoad::Load();		// ���[�h������A�t�@�C�������邩�ǂ����ł��̂��Ƃ𔻒f
	gameEnd = false;
	

	// ���[�h�t�@�C�����������ꍇ
	if (gameFirstStarting)
	{
		LoadFile::MyLoad("media\\������\\media\\First\\gameStart.pyn", titleUIDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\dataLoad.pyn", titleUIDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\gameEnd.pyn", titleUIDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake.pyn", titleUIDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake2.pyn", titleUIDraw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake3.pyn", titleUIDraw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake4.pyn", titleUIDraw[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake5.pyn", titleUIDraw[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\First\\omake6.pyn", titleUIDraw[8], ELOADFILE::graph);
		optionSelectMin = 0;
		optionSelectMax = 2;
	}
	// ���[�h�t�@�C�����Ȃ������ꍇ
	else
	{
		optionSelectMin = 0;
		optionSelectMax = 4;
	}
	playBonus = false;
	/// �Q�[���̃^�C�g���Ɋւ���-------------------------------------------------------------------------------------


	// ��ʂɊւ���
	gaussianScreen = MakeScreen(1920, 1080);


	// �I�v�V�����Ɋւ���
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
	LoadFile::MyLoad("media\\������\\media\\sound\\saveon.wyn", se_save, ELOADFILE::soundmem);
	LoadFile::MyLoad("media\\������\\media\\option\\BGM.pyn", optionDrawMedia[0], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\camera.pyn", optionDrawMedia[1], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\D�^.pyn", optionDrawMedia[2], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\P�^.pyn", optionDrawMedia[3], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\SE.pyn", optionDrawMedia[4], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\Sound.pyn", optionDrawMedia[5], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\���ߖ@.pyn", optionDrawMedia[6], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�F�o����.pyn", optionDrawMedia[7], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\���ˉe.pyn", optionDrawMedia[8], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�ʏ�F.pyn", optionDrawMedia[9], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�����].pyn", optionDrawMedia[10], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�c���].pyn", optionDrawMedia[11], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\nextPage.pyn", optionDrawMedia[12], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\prevPage.pyn", optionDrawMedia[13], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\optionEnd.pyn", optionDrawMedia[14], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\gameEnd.pyn", optionDrawMedia[15], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\save.pyn", optionDrawMedia[16], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\yes.pyn", optionDrawMedia[17], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\no.pyn", optionDrawMedia[18], ELOADFILE::graph);


	// �t�F�[�h�����Ɋւ���
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// �A���`�G�C���A�V���O�Ɋւ���
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(1920, 1080, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
} /// Manager::Manager()


// �f�X�g���N�^
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


// �X�V
void Manager::Update()
{
	// �ŏ��̋N���̂Ƃ�
	if (gameFirstStarting)
	{
		TitleProcess();

		ClearDrawScreen();

		TitleDraw();

		ScreenFlip();
	} /// if (gameFirstStarting)
	// �ŏ��̋N���łȂ��Ƃ�(�܂�ʏ펞
	else
	{
		// ���̃V�[���ƒ��O�̃V�[��������
		if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
		{
			// �ŏ��̃��[�u�̃��[�h��������
			if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)
			{
				// �V�[���P�̑f�ރt�@�C��
				InitMove1Load();


				p_loadThread->Process(max1, moveStr, loadType);		// ���[�h������


				// ���[�h���I��������
				if (p_loadThread->GetNum() >= max1)
				{
					BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
					preLoadScene = true;								// ���O�����[�h�������Ƃ���
					BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;	// ���̃V�[�����w�肷��
				}
			}
			// ��Ԗڂ̃��[�u�̃��[�h��������
			else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
			{
				// �V�[���Q�̑f�ރt�@�C��
				InitMove2Load();


				p_loadThread->Process(max2, moveStr, loadType);		// ���[�h������


				// ���[�h���I��������
				if (p_loadThread->GetNum() >= max2)
				{
					BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
					preLoadScene = true;								// ���O�����[�h��������
					BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;	// ���̃V�[�����w�肷��
				}
			}
			// �O�Ԗڂ̃��[�u�̃��[�h��������
			else if (BASICPARAM::e_preScene == ESceneNumber::THIRDLOAD)
			{
				// ���[�u3�̃��[�h�f��
				InitMove3Load();


				p_loadThread->Process(max3, moveStr, loadType);		// ���[�h������


				// ���[�h���I��������
				if (p_loadThread->GetNum() >= max3)
				{
					BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
					preLoadScene = true;								// ���O�����[�h��������
					BASICPARAM::e_nowScene = ESceneNumber::THIRDMOVE;	// ���̃V�[�����w�肷��
				}
			}
			// �l�Ԗڂ̃��[�u�̃��[�h��������
			else if (BASICPARAM::e_preScene == ESceneNumber::FOURTHLOAD)
			{
				// ���[�u4�̃��[�h�f��
				InitMove4Load();


				Move4TextureReload();


				p_loadThread->Process(max4, moveStr, loadType);		// ���[�h������


				// ���[�h���I��������
				if (p_loadThread->GetNum() >= max4)
				{
					BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
					preLoadScene = true;								// ���O�����[�h��������
					BASICPARAM::e_nowScene = ESceneNumber::FOURTHMOVE;	// ���̃V�[�����w�肷��
				}
			}
			// �ܔԖڂ̃��[�u�̃��[�h��������
			else if (BASICPARAM::e_preScene == ESceneNumber::FIFTHLOAD)
			{
				// ���[�u5�̃��[�h�f��
				InitMove5Load();


				Move5TextureReload();


				p_loadThread->Process(max5, moveStr, loadType);		// ���[�h������


				// ���[�h���I��������
				if (p_loadThread->GetNum() >= max5)
				{
					BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
					preLoadScene = true;								// ���O�����[�h��������
					BASICPARAM::e_nowScene = ESceneNumber::FIFTHMOVE;	// ���̃V�[�����w�肷��
				}
			}
			// ���[�h�ł͂Ȃ��Q�[����������
			else
			{
				preLoadScene = false;		// ���O�����[�h�ł͂Ȃ��Ƃ���


				// �I�v�V�������j���[�łȂ��Ƃ�
				if (!optionMenuNow)
				{
					// �J�n�t�F�[�h���I�����Ă�����
					if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
					{
						// �A���`�G�C���A�X��ʂɑ΂��ĕ`�揈�����s��
						SetDrawScreen(antiAliasScreen);
						ClearDrawScreen();


						// �Q�[���Ɋւ���
						p_baseMove->CameraProcess();
						p_baseMove->Draw();


						// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
						DrawEffekseer3D();
						// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
						DrawEffekseer2D();


						BASICPARAM::e_nowScene = p_baseMove->GetScene();


						// �A���`�G�C���A�X��ʂɕ`�悵�����̂𗠉�ʂɏ�������
						SetDrawScreen(DX_SCREEN_BACK);
						DrawGraph(0, 0, antiAliasScreen, false);


						// �Q�[���Ɋւ���
						p_baseMove->CameraProcess();				// SetDrawScreen���s���ƃJ�����̐ݒ肪�Ȃ��Ȃ�̂ōĐݒ���s��
						p_baseMove->Process();


						// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
						UpdateEffekseer3D();
						// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
						UpdateEffekseer2D();


						// �I�v�V������ʂɈڍs����R�}���h�������ꂽ��A�܂��̓E�B���h�E�Y����A�N�e�B�u�ɂȂ�����
						if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1
							|| !GetWindowActiveFlag())
						{
							// ���݂̉�ʂ��L���v�`������
							GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);


							GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);	// ���݂̉�ʂɃK�E�X�t�B���^�����Ăڂ���	


							p_baseMove->OptionActorModelBefore();							// �I�v�V�����p�̃��f���\���̏���



							optionMenuNow = true;											// �I�v�V�������j���[�Ɉڍs����t���b�O�𗧂Ă�


							optionSelectButtonNum = EOptionSelectButton::Sound;				// �I�v�V�������j���[�̃{�^���ʒu��������


							optionPageNowNumber = 0;										// �I�v�V�����̃y�[�W��1�y�[�W�ڂɂ���


							SoundProcess::SetOptionMenuNow(true);							// �T�E���h���ʂ��I�v�V�������j���[�p�ɉ�����悤����

						}
#ifdef _DEBUG
						MyDebug::DebugProcess();
#endif // _DEBUG
						ScreenFlip();
					} /// if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
					// �J�n�t�F�[�h�������Ă�����
					else
					{
						feedCount -= 5;						// �t�F�[�h�J�E���g��������			


						// ��ʂɊւ����A
						ClearDrawScreen();
						SetDrawScreen(DX_SCREEN_BACK);


						// �Q�[���Ɋւ����A
						p_baseMove->CameraProcess();
						p_baseMove->Draw();


						// �t�F�[�h�C������
						SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
						DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
						SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


						// �t�F�[�h�J�E���g��������܂�������J�n�t�F�[�h�t���b�O������
						if (feedCount <= 0)
						{
							feedCount = 0;
							BASICPARAM::startFeedNow = false;
						}


						ScreenFlip();
					} /// else(!if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/))
				} /// if (!optionMenuNow)
				// �I�v�V�������j���[�̂Ƃ�
				else
				{
					// ��ʂɊւ����A
					ClearDrawScreen();


					// �I�v�V�����Ɋւ���
					OptionDraw();
					OptionProcess();


					// �I�v�V������ʂ���߂�
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
					{
						p_baseMove->OptionActorModelAfter();
						p_baseMove->CameraProcess();			// �J�����؂�ւ�
						SoundProcess::SetOptionMenuNow(false);		// �T�E���h���ʂ��I�v�V�����p����߂�
						optionMenuNow = false;
					}


					ScreenFlip();
				} /// else(!if (!optionMenuNow))
			} /// else
		} /// if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)	
		// �V�[�����ڍs����悤�Ɏw�肳�ꂽ��
		else
		{
			// ���݂̃V�[���̏I���t�F�[�h���I�������
			if (!BASICPARAM::endFeedNow)
			{
				// �V�[����ς���
				SceneChange();


				// ���O�̃V�[���ƍ��̃V�[���𓯂��ɂ���
				BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
			} /// if (!BASICPARAM::endFeedNow)
			// ���݂̃V�[���̏I���t�F�[�h�̂Ƃ�
			else
			{
				// �I���V�[�������[�h�ł͂Ȃ��Ƃ�
				if (!preLoadScene)
				{
					// �t�F�[�h�����Z����
					feedCount += 5;


					// ��ʂɊւ����A
					SetDrawScreen(DX_SCREEN_BACK);
					ClearDrawScreen();


					// �Q�[���̕`��Ɋւ���̂������c���ăQ�[���Ɋւ������
					p_baseMove->CameraProcess();
					p_baseMove->Draw();


					// �t�F�[�h�A�E�g����
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
					DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


					ScreenFlip();


					// �t�F�[�h�J�E���g�����ɒB������t���b�O������
					if (feedCount >= 255)
					{
						// �G�t�F�N�g���I������
						DrawEffekseer2D_End();
						DrawEffekseer3D_End();


						// �T�E���h���������
						SoundProcess::Release();


						feedCount = 0;
						BASICPARAM::endFeedNow = false;
					}
				} /// if (!preLoadScene)
				// �I���V�[�������[�h�̂Ƃ�
				else
				{
					// �T�E���h���������
					SoundProcess::Release();


					// �t�F�[�h�����Z����
					feedCount += 15;


					// ��ʂɊւ����A
					SetDrawScreen(DX_SCREEN_BACK);
					ClearDrawScreen();


					// �Q�[���̕`��Ɋւ���̂������c���ăQ�[���Ɋւ������
					p_loadThread->Draw();


					// �t�F�[�h�A�E�g����
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
					DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


					ScreenFlip();


					// �t�F�[�h�J�E���g�����ɒB������t���b�O������
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