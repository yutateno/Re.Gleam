#include "Manager.hpp"

void Manager::SceneChange()
{
	switch (BASICPARAM::e_nowScene)
	{
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		break;


	case ESceneNumber::FIRSTMOVE:
		SoundProcess::Release();
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	case ESceneNumber::SECONDMOVE:
		SoundProcess::Release();
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
	if (optionMenuNow)
	{
		SoundProcess::SetOptionMenuNow(true);
	}
}


void Manager::OptionDraw()
{
	DrawGraph(0, 0, gaussianScreen, false);


	// �I�������{�^��(SE��ʏ��P�^�␳�܂��)�̍��W
	const int selectLeftXArea = 385;
	const int selectRightXArea = selectLeftXArea + 83;


	/// �T�E���h�֌W�I�v�V����-----------------------------------------------

	DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(255, 255, 255), true);
	DrawBox(95, 95, 95 + 211, 95 + 86, GetColor(0, 0, 0), false);
	DrawFormatString(95, 95, 255, "�T�E���h����");

	DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(255, 255, 255), true);
	DrawBox(381, 114, 381 + 87, 114 + 58, GetColor(0, 0, 0), false);
	DrawFormatString(381, 114, 255, "BGM");

	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(255, 255, 255), true);
	DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
	DrawFormatString(546, 100, 255, "BGM�o�[");

	DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 266, 385 + 86, 266 + 58, GetColor(0, 0, 0), false);
	DrawFormatString(385, 266, 255, "SE");

	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(255, 255, 255), true);
	DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
	DrawFormatString(548, 255, 255, "SE�̃o�[");


	/// �F�o�Ɋւ���I�v�V����----------------------------------------------

	DrawBox(96, 413, 96 + 154, 413 + 76, GetColor(255, 255, 255), true);
	DrawBox(96, 413, 96 + 154, 413 + 76, GetColor(0, 0, 0), false);
	DrawFormatString(96, 413, 255, "�F�o�ݒ�");

	DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 427, 385 + 83, 427 + 58, GetColor(0, 0, 0), false);
	DrawFormatString(385, 427, 255, "�ʏ�F");

	DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(255, 255, 255), true);
	DrawBox(386, 550, 386 + 83, 550 + 59, GetColor(0, 0, 0), false);
	DrawFormatString(386, 550, 255, "P�^�␳");

	DrawBox(559, 550, 559 + 269, 550 + 65, GetColor(255, 255, 255), true);
	DrawBox(559, 550, 559 + 269, 550 + 65, GetColor(0, 0, 0), false);
	DrawFormatString(559, 550, 255, "P�^�⑫����");

	DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(255, 255, 255), true);
	DrawBox(385, 682, 385 + 83, 682 + 58, GetColor(0, 0, 0), false);
	DrawFormatString(385, 682, 255, "D�^�␳");

	DrawBox(557, 681, 557 + 273, 681 + 60, GetColor(255, 255, 255), true);
	DrawBox(557, 681, 557 + 273, 681 + 60, GetColor(0, 0, 0), false);
	DrawFormatString(557, 681, 255, "D�^�⑫����");


	///�@���f���\��-------------------------------------------------------------

	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(255, 255, 255), true);
	DrawBox(1252, 94, 1252 + 589, 94 + 897, GetColor(0, 0, 0), false);
	DrawFormatString(1252, 94, 255, "���f��");


	// �߂�

	DrawBox(375, 843, 375 + 109, 843 + 68, GetColor(255, 255, 255), true);
	DrawBox(375, 843, 375 + 109, 843 + 68, GetColor(0, 0, 0), false);
	DrawFormatString(375, 843, 255, "�߂�");
}


Manager::Manager()
{
	// ������
	BASICPARAM::e_preScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::FIRSTLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;


	// �V�[���P�̑f�ރt�@�C��
	move1str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
	move1str[1] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move1str[2] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.myn";
	move1str[3] = "media\\������\\media\\��\\sword.myn";
	move1str[4] = "media\\������\\media\\sound\\�^�C�g���i�I���S�[���j.wyn";
	move1str[5] = "media\\������\\media\\sound\\�ʂ��|�[���i���������ق��j.wyn";
	move1str[6] = "media\\������\\media\\sound\\�ʂ��|�[��.wyn";
	load1[0] = ELOADFILE::mv1model;
	load1[1] = ELOADFILE::mv1model;
	load1[2] = ELOADFILE::mv1model;
	load1[3] = ELOADFILE::mv1model;
	load1[4] = ELOADFILE::soundStream;
	load1[5] = ELOADFILE::soundmem;
	load1[6] = ELOADFILE::soundmem;


	// �V�[���Q�̑f�ރt�@�C��
	move2str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move2str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";
	move2str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move2str[3] = "media\\������\\media\\kaidan\\kaidan.myn";
	move2str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\������\\media\\�X��\\Gaitou.myn";
	move2str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";
	move2str[7] = "media\\������\\media\\�u���b�N\\cubeblock.myn";
	move2str[8] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
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


	gaussianScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight);
	optionMenuNow = false;


	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(BASICPARAM::winWidth, BASICPARAM::winHeight, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
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
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		// ���̃V�[���ƒ��O�̃V�[��������
	{
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		// ���[�h���ɕς�����u�ԂȂ�
		{
			p_loadThread->Process(max1, move1str, load1);		// ���[�h������
			if (p_loadThread->GetNum() >= max1)		// ���[�h���I��������
			{
				//if (CheckHitKey(KEY_INPUT_Z) == 1)			// �I�������ꑀ��
				//{
					BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;
				//}
			}
		}
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ���[�h������
			if (p_loadThread->GetNum() >= max2)		// ���[�h���I��������
			{
				//if (CheckHitKey(KEY_INPUT_Z) == 1)			// �I�������ꑀ��
				//{
					BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;
				//}
			}
		}
		else
		{
			if (!optionMenuNow)
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
		SceneChange();
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}
