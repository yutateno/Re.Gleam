#include "Manager.hpp"

//int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
//double Fps = 0.0;
//
//void FpsTimeFanction() {
//	if (FpsTime_i == 0)
//		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
//	if (FpsTime_i == 49) {
//		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
//		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) * 0.02f);//���肵���l����fps���v�Z
//		FpsTime_i = 0;//�J�E���g��������
//	}
//	else
//		FpsTime_i++;//���݉����ڂ��J�E���g
//	if (Fps != 0)
//		DrawFormatString(1700, 0, GetColor(0, 0, 0), "FPS %.1f", Fps); //fps��\��
//	return;
//}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ���O�e�L�X�g�o�͂���
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ���O�e�L�X�g�o�͂��Ȃ�
#endif

	SetWindowText("Re.Gleam");	// ���C���E�C���h�E�̃E�C���h�E�^�C�g����ύX����

	SetBackgroundColor(255, 255, 255);

	SetUseDirect3DVersion(DX_DIRECT3D_11);			// Direct3D11���g�p����

	ChangeWindowMode(TRUE);			// �E�B���h�E�Y���[�h�ɂ����邩�ǂ���

	SetEnableXAudioFlag(TRUE);			// XAudio���g�p����悤�ɂ���

	SetUseLarge3DPositionSupport(TRUE);		// ����ȍ��W�l���T�|�[�g

	SetGraphMode(1920, 1080, BASICPARAM::bitColor);					// 1920x1080xdefaultbit

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// �E�B���h�E�f�t�H���g�l�𓾂�

	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);		// �E�B���h�E�T�C�Y�ɍ��킹�ăQ�[���T�C�Y��ύX

	// SetAlwaysRunFlag(TRUE);

	SetDrawScreen(DX_SCREEN_BACK);	// �w�i�`��

	// �R���g���[���[�ƃL�[�{�[�h�̏�����
	DLLXinput::Init();
	DLLXinput::FirstUpdate();

	// new
	Manager* manager = new Manager();

	// �ŏ��ɃR���g���[���[��ݒ肷�邽�߂̊m�F�R�}���h
	bool firstControll = false;						// �R���g���[���[��������ĂȂ��̂ŃQ�[�����N�����Ȃ��悤
	DLLXinput::SetPlayerPadNum(5);
	int controllCount = 0;							// �R�}���h�Ɋւ��鎞��
	bool noTouch = true;							// �R�}���h��������Ȃ����Ԍo�ߎ���ōċN���𑣂��悤����
	const int COUNT = 600;							// �R�}���h���Ԃ̐��l
	SoundProcess::Init();

	// �ڑ�������̏ꍇ�͊m�F���Ȃ�
	if (DLLXinput::GetPadNum() == 1)
	{
		DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
		firstControll = true;
	}

#ifdef _DEBUG
	MyDebug::Init();
#endif // _DEBUG


	// �Q�[���̊j
	while (/*ScreenFlip() == 0 && */ProcessMessage() == 0/* && ClearDrawScreen() == 0 */&& CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �R���g���[���[���Q�ȏ�̎�
		if (!firstControll)
		{
			ClearDrawScreen();
			if (DLLXinput::GetPadNum() == 0)
			{
				DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180), "�R���g���[���[���q�����Ă��܂���B�I�����܂��B");
				controllCount++;
				if (controllCount >= 50)
				{
					break;
				}
			}
			else
			{
				DLLXinput::FirstUpdate();

				// �͈͊O�ɓ����Ƃ����܂�
				if (DLLXinput::GetPlayerPadNumber() == 5)
				{
					controllCount++;
					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180), "�R���g���[���[��A�{�^���������Ă��������B\n������R���g���[���[�Ƃ��ĔF�؂��܂��B\n");
					if (controllCount >= 10)
					{
						if (DLLXinput::GetPadButtonData(0, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// �PP�����͂��ꂽ
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(1, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// �QP�����͂��ꂽ
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM02);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(2, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// �RP�����͂��ꂽ
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM03);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(3, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// �SP�����͂��ꂽ
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM04);
							controllCount = 0;
						}
					}

					// ���͂���Ȃ����Ԍo�߂œ�����^����
					if (controllCount >= COUNT && controllCount < COUNT + 400)
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180), "���͂���莞�Ԋm�F�ł��܂���B�ċN�����Ă݂Ă��������B\n");
					}
					else if (controllCount >= COUNT + 400 && controllCount < COUNT + 550)		// ���������肪����Ɣ��f���ďI��������
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180), "��肪�������Ă�Ɣ��f���A�Q�[�����I�����܂��B\n");
					}
					else if (controllCount >= COUNT + 550)
					{
						break;
					}
				}
				else
				{
					controllCount++;
					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 0), "�R���g���[���[�i���o�[�F%d ���m�F���܂����B�Q�[�����J�n���܂��B\n", (DLLXinput::GetPlayerPadNumber() + 1));
					if (controllCount >= 100)
					{
						firstControll = true;
					}
				}
			}
			ScreenFlip();
		}
		else
		{
			DLLXinput::EverUpdate();

			manager->Update();

			SoundProcess::Process();

			DLLXinput::VibrationSlowlyStop(DLLXinput::GetPlayerPadNumber());
		}
		//FpsTimeFanction();
	}

	SoundProcess::Release();

	// �폜
	POINTER_RELEASE(manager);

	DxLib_End();		// DX���C�u�����̌�n��

	return 0;
}