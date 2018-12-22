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
	// �펞
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		// BGM�o�[�̓����ŃT�E���h��BGM���ʂ�ύX����
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
		// 61�J�E���g�̂��т�SE��炷
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
		}


		// SE�o�[�̓����ŃT�E���h��SE���ʂ�ύX����
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
			// �����摜�ł͂Ȃ�������ʏ�F�ɕς���
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// �����摜�ł͂Ȃ�������P�^�␳�F�ɕς���
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// �����摜�ł͂Ȃ�������D�^�␳�F�ɕς���
			if (BASICPARAM::e_TextureColor != ETextureColor::WHITEBLACK) BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->TextureReload();		// �e�N�X�`���؂�ւ�
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
			SoundProcess::SetOptionMenuNow(false);				// �T�E���h�̉��ʂ��I�v�V�����p�����߂�
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
			p_baseMove->CameraProcess();		// �J�����؂�ւ�
		}
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			BASICPARAM::nowCameraOrtho = true;
			p_baseMove->CameraProcess();		// �J�����؂�ւ�
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
	// �߂�{�^�����������Ƃ��̓���
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			SoundProcess::SetOptionMenuNow(true);					// �T�E���h�̉��ʂ��I�v�V�����p����ɖ߂�
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			SoundProcess::SetOptionMenuNow(true);					// �T�E���h�̉��ʂ��I�v�V�����p����ɖ߂�
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
}


void Manager::OptionDraw()
{
	// �w�i
	DrawGraph(0, 0, gaussianScreen, false);

	///�@���f���\��-------------------------------------------------------------
	p_baseMove->OptionActorModel();

	/// �T�E���h�֌W�I�v�V����-----------------------------------------------
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

	// UI:BGM�o�[
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

	// UI:SE�o�[
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
	if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 0, 0), false);
	}
	DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
		, 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
		, 255 + 78 + 10, GetColor(0, 125, 125), true);


	/// �F�o�Ɋւ���I�v�V����----------------------------------------------
	// UI:�F�o����
	if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
	{
		DrawBox(96, 413, 96 + 112, 413 + 76, GetColor(255, 0, 0), false);
	}

	// UI:�ʏ�F
	DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
	{
		DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 0, 0), false);
	}

	// UI:P�^
	DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorP)
	{
		DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 0, 0), false);
	}

	// UI:D�^
	DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
	if (optionSelectButtonNum == EOptionSelectButton::ColorD)
	{
		DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 0, 0), false);
	}
	if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


	/// �J�����̊ւ���I�v�V����------------------------------------------------
	// �J����
	DrawGraph(95, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
	if (optionSelectButtonNum == EOptionSelectButton::Camera)
	{
		DrawBox(95, 843, 95 + 109, 843 + 68, GetColor(255, 0, 0), false);
	}

	// ���ߖ@
	if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(385, 843, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
	{
		DrawBox(385, 843, 385 + 83, 843 + 58, GetColor(255, 0, 0), false);
	}
	if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// ���ˉe
	if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(385, 970, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
	{
		DrawBox(385, 970, 385 + 83, 970 + 58, GetColor(255, 0, 0), false);
	}
	if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// �����]
	if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
	DrawGraph(568, 843, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
	if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
	{
		DrawBox(568, 843, 568 + 83, 843 + 58, GetColor(255, 0, 0), false);
	}
	if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	// �c���]
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
	// ������
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;
	BASICPARAM::cameraHorizonReturn = true;
	BASICPARAM::cameraVerticalReturn = true;


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
	move1str[24] = "media\\������\\media\\option\\�����].pyn";
	move1str[25] = "media\\������\\media\\option\\�c���].pyn";

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
	load1[24] = ELOADFILE::graph;
	load1[25] = ELOADFILE::graph;
	/// ---------------------------------------------------------------------------------------------------


	/// �V�[���Q�̑f�ރt�@�C��-----------------------------------------------------------------------------
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

	// �����@�B�̕⏕����
	move2str[23] = "media\\������\\media\\Terminal\\push.pyn";

	// �K�i�Ƃ��̂��Ƃ̏��f�[�^
	move2str[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

	// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
	move2str[25] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
	move2str[26] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

	// �K�i�Ə��̂����蔻��f�[�^
	move2str[27] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

	// 2D�֘A
	move2str[28] = "media\\������\\media\\2D�f��\\change\\whiteblack\\block_2D.pyn";
	move2str[29] = "media\\������\\media\\2D�f��\\change\\whiteblack\\CLPH_up.pyn";
	move2str[30] = "media\\������\\media\\2D�f��\\change\\whiteblack\\gaiyou_2D.pyn";
	move2str[31] = "media\\������\\media\\2D�f��\\change\\whiteblack\\kaidan_2d.pyn";
	move2str[32] = "media\\������\\media\\2D�f��\\change\\whiteblack\\Terminal_2D.pyn";
	move2str[33] = "media\\������\\media\\2D�f��\\change\\whiteblack\\yuka_2D.pyn";

	// �L�����N�^�[�����3DSE
	move2str[34] = "media\\������\\media\\sound\\�W�����v.wyn";
	move2str[35] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
	move2str[36] = "media\\������\\media\\sound\\����.wyn";
	move2str[37] = "media\\������\\media\\sound\\���n.wyn";
	move2str[38] = "media\\������\\media\\sound\\���n�Q.wyn";

	// �L�����N�^�[�̍U���̉�
	move2str[39] = "media\\������\\media\\sound\\piano�U����1.wyn";
	move2str[40] = "media\\������\\media\\sound\\piano�U����2.wyn";
	move2str[41] = "media\\������\\media\\sound\\piano�U����3.wyn";


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


	// �������̏�����
	p_baseMove = NULL;
	p_loadThread = NULL;


	// �ŏ��̃��[�h�𐶐�
	p_loadThread = new LoadThread();

	// �V�[���J�n�Ȃ̂�
	preLoadScene = false;


	// ��ʂɊւ���
	gaussianScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight);


	// �I�v�V�����Ɋւ���
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


	// �t�F�[�h�����Ɋւ���
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// �A���`�G�C���A�V���O�Ɋւ���
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
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
	// ���̃V�[���ƒ��O�̃V�[��������
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		
	{
		// �ŏ��̃��[�u�̃��[�h��������
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		
		{
			p_loadThread->Process(max1, move1str, load1);		// ���[�h������

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
			p_loadThread->Process(max2, move2str, load2);		// ���[�h������

			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max2)		
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h��������
				BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;	// ���̃V�[�����w�肷��
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
					BASICPARAM::e_nowScene = p_baseMove->GetScene();

					// �A���`�G�C���A�X��ʂɕ`�悵�����̂𗠉�ʂɏ�������
					SetDrawScreen(DX_SCREEN_BACK);
					DrawGraph(0, 0, antiAliasScreen, false);

					// �Q�[���Ɋւ���
					p_baseMove->CameraProcess();				// SetDrawScreen���s���ƃJ�����̐ݒ肪�Ȃ��Ȃ�̂ōĐݒ���s��
					p_baseMove->Process();


					// �I�v�V������ʂɈڍs����R�}���h�������ꂽ��A�܂��̓E�B���h�E�Y����A�N�e�B�u�ɂȂ�����
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1
						|| !GetWindowActiveFlag())
					{
						// ���݂̉�ʂ��L���v�`������
						GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);	

						// ���݂̉�ʂɃK�E�X�t�B���^�����Ăڂ���
						GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);				
						

						// �I�v�V�������j���[�Ɉڍs����t���b�O�𗧂Ă�
						optionMenuNow = true;

						// �I�v�V�������j���[�̃{�^���ʒu��������
						optionSelectButtonNum = EOptionSelectButton::Sound;


						// �T�E���h���ʂ��I�v�V�������j���[�p�ɉ�����悤����
						SoundProcess::SetOptionMenuNow(true);
					}

#ifdef _DEBUG
					MyDebug::DebugProcess();
#endif // _DEBUG


					ScreenFlip();
				}
				// �J�n�t�F�[�h�������Ă�����
				else
				{
					// �t�F�[�h�J�E���g��������
					feedCount -= 5;				

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
				}
			}
			// �I�v�V�������j���[�̂Ƃ�
			else
			{
				// ��ʂɊւ����A
				ClearDrawScreen();

				// �I�v�V�����Ɋւ���
				OptionProcess();
				OptionDraw();

				// �I�v�V������ʂ���߂�
				if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
				{
					SoundProcess::SetOptionMenuNow(false);		// �T�E���h���ʂ��I�v�V�����p����߂�
					optionMenuNow = false;
				}

				ScreenFlip();
			}
		}
	}
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
		}
		// ���݂̃V�[���̏I���t�F�[�h�̂Ƃ�
		else
		{
			// �I���V�[�������[�h�ł͂Ȃ��Ƃ�
			if (!preLoadScene)
			{
				// �T�E���h���������
				SoundProcess::Release();

				
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
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			}
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
			}
		}
	}
}