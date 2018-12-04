#include "Manager.hpp"

//int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
//double Fps = 0.0;
//
//void FpsTimeFanction() {
//	if (FpsTime_i == 0)
//		FpsTime[0] = GetNowCount();               //1周目の時間取得
//	if (FpsTime_i == 49) {
//		FpsTime[1] = GetNowCount();               //50周目の時間取得
//		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) * 0.02f);//測定した値からfpsを計算
//		FpsTime_i = 0;//カウントを初期化
//	}
//	else
//		FpsTime_i++;//現在何周目かカウント
//	if (Fps != 0)
//		DrawFormatString(1700, 0, GetColor(0, 0, 0), "FPS %.1f", Fps); //fpsを表示
//	return;
//}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウサイズ
	int winWidth = 1920;
	int winHeight = 1080;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif

	SetWindowText("Re.Gleam");	// メインウインドウのウインドウタイトルを変更する

	//SetBackgroundColor(255, 255, 255);

	SetUseDirect3DVersion(DX_DIRECT3D_11);			// Direct3D11を使用する

	ChangeWindowMode(TRUE);			// ウィンドウズモードにさせるかどうか

	SetEnableXAudioFlag(TRUE);			// XAudioを使用するようにする

	SetUseLarge3DPositionSupport(TRUE);		// 巨大な座標値をサポート

	SetGraphMode(winWidth, winHeight, 32);					// 1920x1080x32bit

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// SetAlwaysRunFlag(TRUE);

	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画

	// コントローラーとキーボードの初期化
	DLLXinput::Init();
	DLLXinput::FirstUpdate();

	// new
	Manager* manager = new Manager();

	// 最初にコントローラーを設定するための確認コマンド
	bool firstControll = false;						// コントローラーが押されてないのでゲームを起動しないよう
	DLLXinput::SetPlayerPadNum(5);
	int controllCount = 0;							// コマンドに関する時間
	bool noTouch = true;							// コマンドを押されない時間経過次第で再起動を促すよう処理
	const int COUNT = 600;							// コマンド時間の数値
	SoundProcess::Init();

	// 接続数が一つの場合は確認しない
	if (DLLXinput::GetPadNum() == 1)
	{
		DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
		firstControll = true;
	}

	// ゲームの核
	while (/*ScreenFlip() == 0 && */ProcessMessage() == 0/* && ClearDrawScreen() == 0 */&& CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// コントローラーが２つ以上の時
		if (!firstControll)
		{
			ClearDrawScreen();
			if (DLLXinput::GetPadNum() == 0)
			{
				DrawFormatString(winWidth / 2, winHeight / 2, GetColor(0, 0, 180), "コントローラーが繋がっていません。終了します。");
				controllCount++;
				if (controllCount >= 50)
				{
					break;
				}
			}
			else
			{
				DLLXinput::FirstUpdate();

				// 範囲外に投げといたまま
				if (DLLXinput::GetPlayerPadNumber() == 5)
				{
					controllCount++;
					DrawFormatString(winWidth / 2, winHeight / 2, GetColor(0, 0, 180), "コントローラーのAボタンを押してください。\nそれをコントローラーとして認証します。\n");
					if (controllCount >= 10)
					{
						if (DLLXinput::GetPadButtonData(0, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// １Pが入力された
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(1, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// ２Pが入力された
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM02);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(2, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// ３Pが入力された
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM03);
							controllCount = 0;
						}
						if (DLLXinput::GetPadButtonData(3, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		// ４Pが入力された
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM04);
							controllCount = 0;
						}
					}

					// 入力されない時間経過で動きを与える
					if (controllCount >= COUNT && controllCount < COUNT + 400)
					{
						DrawFormatString(winWidth / 2, (winHeight / 2) + 100, GetColor(0, 0, 180), "入力を一定時間確認できません。再起動してみてください。\n");
					}
					else if (controllCount >= COUNT + 400 && controllCount < COUNT + 550)		// 何かしら問題があると判断して終了させる
					{
						DrawFormatString(winWidth / 2, (winHeight / 2) + 100, GetColor(0, 0, 180), "問題が発生してると判断し、ゲームを終了します。\n");
					}
					else if (controllCount >= COUNT + 550)
					{
						break;
					}
				}
				else
				{
					controllCount++;
					DrawFormatString(winWidth / 2, winHeight / 2, GetColor(0, 0, 0), "コントローラーナンバー：%d を確認しました。ゲームを開始します。\n", (DLLXinput::GetPlayerPadNumber() + 1));
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

	// 削除
	POINTER_RELEASE(manager);

	DxLib::DxLib_End();		// DXライブラリの後始末

	return 0;
}