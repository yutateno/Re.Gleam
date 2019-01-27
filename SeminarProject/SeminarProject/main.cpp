#include "Manager.hpp"


/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�T�C�Y�����߂�
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ���O�e�L�X�g�o�͂���
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ���O�e�L�X�g�o�͂��Ȃ�
#endif


	SetWindowText("Re.Gleam");					// ���C���E�C���h�E�̃E�C���h�E�^�C�g����ύX����
	SetBackgroundColor(255, 255, 255);			// �w�i�F�𔒂ɕύX
	SetUseDirect3DVersion(DX_DIRECT3D_11);		// Direct3D11���g�p����
	ChangeWindowMode(TRUE);						// �E�B���h�E�Y���[�h�ɂ�����
	SetEnableXAudioFlag(TRUE);					// XAudio���g�p����悤�ɂ���
	SetUseLarge3DPositionSupport(TRUE);			// ����ȍ��W�l���T�|�[�g
	SetWindowIconID(333);


	SetGraphMode(BASICPARAM::winWidth, BASICPARAM::winHeight, BASICPARAM::bitColor);			// ��ʃT�C�Y�ݒ�
	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// �f�t�H���g�E�B���h�E�l�𓾂�
	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);									// �f�t�H���g�E�B���h�E�T�C�Y�ɍ��킹�ăQ�[���T�C�Y��ύX

	
	// ��ʃT�C�Y�ɖ߂�
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}


	// Effekseer������������B�����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}


	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);


	Effekseer_Set2DSetting(1920, 1080);	// 2D�G�t�F�N�g�̍ő�͈͂�ݒ�


	SetAlwaysRunFlag(TRUE);			// ���ł��A�N�e�B�u�ɂ���
	SetDrawScreen(DX_SCREEN_BACK);	// �w�i�`��
	SetMouseDispFlag(FALSE);		// �}�E�X�J�[�\�����\���ɂ���


	// �R���g���[���[�̏�����
	DLLXinput::Init();
	DLLXinput::FirstUpdate();


	// ���C��������new����
	Manager* manager = new Manager();


	// �ŏ��ɃR���g���[���[��ݒ肷�邽�߂̊m�F�R�}���h
	bool firstControll = false;						// �R���g���[���[��������ĂȂ��̂ŃQ�[�����N�����Ȃ��悤
	DLLXinput::SetPlayerPadNum(5);
	int controllCount = 0;							// �R�}���h�Ɋւ��鎞��
	bool noTouch = true;							// �R�}���h��������Ȃ����Ԍo�ߎ���ōċN���𑣂��悤����
	const int COUNT = 600;							// �R�}���h���Ԃ̐��l

												
	// �ڑ�������̏ꍇ�͊m�F���Ȃ�
	if (DLLXinput::GetPadNum() == 1)
	{
		DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
		firstControll = true;
	}


	SoundProcess::Init();			// �T�E���h�v���Z�X�̏�����

#ifdef _DEBUG
	MyDebug::Init();
#endif // _DEBUG


	// �Q�[���̊j
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !manager->GetEnd())
	{
		// �R���g���[���[����łȂ��Ƃ�
		if (!firstControll)
		{
			ClearDrawScreen();


			// �R���g���[���[���q�����Ă��Ȃ��Ƃ�
			if (DLLXinput::GetPadNum() == 0)
			{
				DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
					, "�R���g���[���[���q�����Ă��܂���B�I�����܂��B");


				controllCount++;				// �Q�[���I���܂ł̃J�E���g���Z


				// �Q�[���I������
				if (controllCount >= 50) break;
			}
			// �R���g���[���[���q�����Ă���Ƃ�
			else
			{
				DLLXinput::FirstUpdate();		// �R���g���[���[�̍X�V


				// �R���g���[���[�����܂��Ă��Ȃ�������
				if (DLLXinput::GetPlayerPadNumber() == 5)
				{
					controllCount++;			// �R���g���[���[�̓��͑ҋ@�J�E���g���Z


					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
						, "�R���g���[���[��A�{�^���������Ă��������B\n������R���g���[���[�Ƃ��ĔF�؂��܂��B\n");


					// �����ҋ@���Ă�����͂𓾂���悤�ɂ���
					if (controllCount >= 10)
					{
						// �PP�����͂��ꂽ
						if (DLLXinput::GetPadButtonData(0, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 1P�𑀍�R���g���[���[�Ƃ���
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
							controllCount = 0;
						}
						// �QP�����͂��ꂽ
						if (DLLXinput::GetPadButtonData(1, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 2P�𑀍�R���g���[���[�Ƃ���
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM02);
							controllCount = 0;
						}
						// �RP�����͂��ꂽ
						if (DLLXinput::GetPadButtonData(2, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
						{
							// 3P�𑀍�R���g���[���[�Ƃ���
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM03);
							controllCount = 0;
						}
						// �SP�����͂��ꂽ
						if (DLLXinput::GetPadButtonData(3, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 4P�𑀍�R���g���[���[�Ƃ���
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM04);
							controllCount = 0;
						}
					} /// if (controllCount >= 10)


					// ���͂���Ȃ����Ԃ������Ĉȏゾ������
					if (controllCount >= COUNT && controllCount < COUNT + 400)
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180)
							, "���͂���莞�Ԋm�F�ł��܂���B�ċN�����Ă݂Ă��������B\n");
					}
					// ���������肪����Ɣ��f���ďI��������
					else if (controllCount >= COUNT + 400 && controllCount < COUNT + 550)		
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180)
							, "��肪�������Ă�Ɣ��f���A�Q�[�����I�����܂��B\n");
					}
					// �I��������
					else if (controllCount >= COUNT + 550) break;


				} /// if (DLLXinput::GetPlayerPadNumber() == 5)
				// �R���g���[���[�����肳�ꂽ��
				else
				{
					controllCount++;		// �Q�[�����J�n����J�E���g�����Z


					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 0)
						, "�R���g���[���[�i���o�[�F%d ���m�F���܂����B�Q�[�����J�n���܂��B\n", (DLLXinput::GetPlayerPadNumber() + 1));


					// �R���g���[���[�����܂����Ƃ���
					if (controllCount >= 100) firstControll = true;
				}
			} /// else(!if (DLLXinput::GetPadNum() == 0))
			ScreenFlip();
		} /// if (!firstControll)
		// �Q�[�����J�n��������Ƃ��ẴR���g���[���[�����肳�ꂽ��
		else
		{
			DLLXinput::EverUpdate();

			manager->Update();

			SoundProcess::Process();

			DLLXinput::VibrationSlowlyStop(DLLXinput::GetPlayerPadNumber());
		}
	} /// while


	// �폜
	POINTER_RELEASE(manager);


	SoundProcess::Release();		// �T�E���h�J��
	InitSoundMem();					// �T�E���h�J��
	InitGraph();					// �摜���
	MV1InitModel();					// ���f���J��


	Effkseer_End();		// Effekseer���I������B


	DxLib_End();		// DX���C�u�����̌�n��


	return 0;
}