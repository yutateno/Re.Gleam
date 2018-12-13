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
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		for (int i = 0; i != 10; ++i)
		{
			optionDrawMedia[i] = p_loadThread->GetFile()[i + 14];
		}
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
	// �펞
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

	// ����{�^�����������Ƃ��̓���
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
		else if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			optionSelectButtonNum = EOptionSelectButton::CameraPerspective;
			optionSelectMin = 10;
			optionSelectMax = 11;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			BASICPARAM::nowCameraOrtho = false;
			p_baseMove->CameraProcess();
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			BASICPARAM::nowCameraOrtho = true;
			p_baseMove->CameraProcess();
		}
	}


	// �߂�{�^�����������Ƃ��̓���
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


	// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤�����B
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

	// debug
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) == 1)
	{
		BASICPARAM::nowCameraOrtho = false;
		p_baseMove->CameraProcess();
	}
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1)
	{
		BASICPARAM::nowCameraOrtho = true;
		p_baseMove->CameraProcess();
	}
}


void Manager::OptionDraw()
{
	DrawGraph(0, 0, gaussianScreen, false);
	

	/// �T�E���h�֌W�I�v�V����-----------------------------------------------

	DrawGraph(95, 95, optionDrawMedia[static_cast<int>(EOptionDraw::Sound)], false);
	if (optionSelectButtonNum == EOptionSelectButton::Sound)
	{
		DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(255, 0, 0), false);
	}

	DrawGraph(381, 114, optionDrawMedia[static_cast<int>(EOptionDraw::BGM)], false);
	if (optionSelectButtonNum == EOptionSelectButton::BGM)
	{
		DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(255, 0, 0), false);
	}

	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(200, 200, 200), true);
	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(255, 0, 0), false);
	}
	DrawBox(546 - 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 547), 100 - 10, 546 + 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 548), 100 + 81 + 10, GetColor(0, 125, 125), true);
	DrawFormatString(546, 100, 255, "BGM�o�[");

	DrawGraph(385, 266, optionDrawMedia[static_cast<int>(EOptionDraw::SE)], false);
	if (optionSelectButtonNum == EOptionSelectButton::SE)
	{
		DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(255, 0, 0), false);
	}

	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 0, 0), false);
	}
	DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547), 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547), 255 + 78 + 10, GetColor(0, 125, 125), true);
	DrawFormatString(548, 255, 255, "SE�̃o�[");


	/// �F�o�Ɋւ���I�v�V����----------------------------------------------

	DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
	{
		DrawBox(96, 413, 96 + 112, 413 + 76, GetColor(255, 0, 0), false);
	}

	DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
	{
		DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 0, 0), false);
	}

	DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorP)
	{
		DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 0, 0), false);
	}

	DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorD)
	{
		DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 0, 0), false);
	}


	///�@���f���\��-------------------------------------------------------------

	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(255, 255, 255), true);
	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(0, 0, 0), false);
	DrawFormatString(1252, 94, 255, "���f��");


	/// �J�����̊ւ���I�v�V����------------------------------------------------

	DrawGraph(95, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
	if (optionSelectButtonNum == EOptionSelectButton::Camera)
	{
		DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(255, 0, 0), false);
	}

	DrawGraph(385, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
	{
		DrawBox(385, 843, 385 + 83, 843 + 58, GetColor(255, 0, 0), false);
	}

	DrawGraph(385, 970, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
	{
		DrawBox(385, 970, 385 + 83, 970 + 58, GetColor(255, 0, 0), false);
	}
}


Manager::Manager()
{
	// ������
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;


	/// �V�[���P�̑f�ރt�@�C��-----------------------------------------------------------------------------
	
	// ���f���f�[�^
	move1str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
	move1str[1] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move1str[2] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.myn";				// 4
	move1str[3] = "media\\������\\media\\��\\sword.myn";								// 1

	// �T�E���h�f�[�^
	move1str[4] = "media\\������\\media\\sound\\�^�C�g���i�I���S�[���j.wyn";
	move1str[5] = "media\\������\\media\\sound\\�ʂ��|�[���i���������ق��j.wyn";
	move1str[6] = "media\\������\\media\\sound\\�ʂ��|�[��.wyn";

	// �L�����N�^�[�̃e�N�X�`���f�[�^
	move1str[7] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
	move1str[8] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
	move1str[9] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
	move1str[10] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

	// ���̃e�N�X�`���f�[�^
	move1str[11] = "media\\������\\media\\��\\whiteblack\\sword_Tex.pyn";

	// �R���g���[���[����
	move1str[12] = "media\\������\\media\\move1\\hida.pyn";
	move1str[13] = "media\\������\\media\\move1\\mighi.pyn";

	// �I�v�V�����p�摜
	move1str[14] = "media\\������\\media\\option\\BGM.pyn";
	move1str[15] = "media\\������\\media\\option\\camera.pyn";
	move1str[16] = "media\\������\\media\\option\\D�^.pyn";
	move1str[17] = "media\\������\\media\\option\\P�^.pyn";
	move1str[18] = "media\\������\\media\\option\\SE.pyn";
	move1str[19] = "media\\������\\media\\option\\Sound.pyn";
	move1str[20] = "media\\������\\media\\option\\���ߖ@.pyn";
	move1str[21] = "media\\������\\media\\option\\�F�o����.pyn";
	move1str[22] = "media\\������\\media\\option\\���ˉe.pyn";
	move1str[23] = "media\\������\\media\\option\\�ʏ�F.pyn";

	// ���f���f�[�^
	load1[0] = ELOADFILE::mv1model;
	load1[1] = ELOADFILE::mv1model;
	load1[2] = ELOADFILE::mv1model;
	load1[3] = ELOADFILE::mv1model;

	// �T�E���h�f�[�^
	load1[4] = ELOADFILE::soundStream;
	load1[5] = ELOADFILE::soundmem;
	load1[6] = ELOADFILE::soundmem;

	// �L�����N�^�[�̃e�N�X�`���f�[�^
	load1[7] = ELOADFILE::graph;
	load1[8] = ELOADFILE::graph;
	load1[9] = ELOADFILE::graph;
	load1[10] = ELOADFILE::graph;

	// ���̃e�N�X�`���f�[�^
	load1[11] = ELOADFILE::graph;

	// �R���g���[���[����
	load1[12] = ELOADFILE::graph;
	load1[13] = ELOADFILE::graph;

	// �I�v�V�����p�摜
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
	/// ---------------------------------------------------------------------------------------------------


	/// �V�[���Q�̑f�ރt�@�C��
	// ���f���f�[�^
	move2str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move2str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move2str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move2str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
	move2str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
	move2str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
	move2str[7] = "media\\������\\media\\�u���b�N\\cubeblock.myn";					// 1
	move2str[8] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

	// �L�����̃e�N�X�`���f�[�^
	move2str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move2str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move2str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move2str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move2str[13] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// �K�i�̃e�N�X�`���f�[�^
	move2str[14] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// �X���̃e�N�X�`���f�[�^
	move2str[15] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
	move2str[16] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

	// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
	move2str[17] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

	// �u���b�N�̃e�N�X�`��
	move2str[18] = "media\\������\\media\\�u���b�N\\whiteblack\\tex.pyn";

	// �T�E���h�f�[�^
	move2str[19] = "media\\������\\media\\sound\\���܏E����.wyn";

	// ���Z�@�B�f�[�^
	move2str[20] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

	// ���Z�@�B�e�N�X�`��
	move2str[21] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move2str[22] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

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

	for (int i = 0; i != 10; ++i)
	{
		optionDrawMedia[i] = -1;
	}

	preLoadScene = false;

	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	LoadFile::MyLoad("media\\������\\media\\black.pyn", feedDraw, ELOADFILE::graph);

	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
}


Manager::~Manager()
{
	for (int i = 0; i != 10; ++i)
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
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		// ���̃V�[���ƒ��O�̃V�[��������
	{
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		// ���[�h���ɕς�����u�ԂȂ�
		{
			p_loadThread->Process(max1, move1str, load1);		// ���[�h������
			if (p_loadThread->GetNum() >= max1)		// ���[�h���I��������
			{
				//feedCount++;
				////p_loadThread->Process(max1, move1str, load1);		// ���[�h������
				//SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				//DrawGraph(0, 0, feedDraw, false);
				//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

				//if (feedCount >= 255)
				//{
				BASICPARAM::endFeedNow = true;
				preLoadScene = true;
				BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;
				//}
			}
		}
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ���[�h������
			if (p_loadThread->GetNum() >= max2)		// ���[�h���I��������
			{
				BASICPARAM::endFeedNow = true;
				preLoadScene = true;
				BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;
			}
		}
		else
		{
			preLoadScene = false;
			if (!optionMenuNow)
			{
				if (!BASICPARAM::startFeedNow && !BASICPARAM::endFeedNow)
				{
					// �A���`�G�C���A�X��ʂɑ΂��ĕ`�揈�����s��
					SetDrawScreen(antiAliasScreen);
					ClearDrawScreen();
					p_baseMove->CameraProcess();
					p_baseMove->Draw();
					p_baseMove->Process();
					BASICPARAM::e_nowScene = p_baseMove->GetScene();

					// �A���`�G�C���A�X��ʂɕ`�悵�����̂𗠉�ʂɏ�������
					SetDrawScreen(DX_SCREEN_BACK);
					DrawGraph(0, 0, antiAliasScreen, false);
					p_baseMove->CameraProcess();				// SetDrawScreen���s���ƃJ�����̐ݒ肪�Ȃ��Ȃ�̂ōĐݒ���s��
					ScreenFlip();

					// �I�v�V������ʂɈڍs����
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
					{
						GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);						// ���݂̉�ʂ��L���v�`������
						GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 16, 1400);				// ���݂̉�ʂɃK�E�X�t�B���^�����Ăڂ���
						optionMenuNow = true;
						optionSelectButtonNum = EOptionSelectButton::Sound;
						SoundProcess::SetOptionMenuNow(true);
					}
				}
				else if(BASICPARAM::startFeedNow)
				{
					feedCount -= 5;
					ClearDrawScreen();
					SetDrawScreen(DX_SCREEN_BACK);
					p_baseMove->CameraProcess();
					p_baseMove->Draw();
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
					DrawGraph(0, 0, feedDraw, false);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
					ScreenFlip();

					if (feedCount <= 0)
					{
						feedCount = 0;
						BASICPARAM::startFeedNow = false;
					}
				}
			}
			else
			{
				ClearDrawScreen();
				OptionProcess();
				OptionDraw();

				// �I�v�V������ʂ���߂�
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
		if (!BASICPARAM::endFeedNow)
		{
			SceneChange();
			BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
		}
		else
		{
			if (!preLoadScene)
			{
				feedCount += 5;
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();
				p_baseMove->CameraProcess();
				p_baseMove->Draw();
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawGraph(0, 0, feedDraw, false);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
				ScreenFlip();

				if (feedCount >= 255)
				{
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			}
			else
			{
				feedCount += 15;
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();
				p_loadThread->Draw();
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawGraph(0, 0, feedDraw, false);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
				ScreenFlip();

				if (feedCount >= 255)
				{
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			}
		}
	}
}