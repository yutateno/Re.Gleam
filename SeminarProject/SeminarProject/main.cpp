#include "Manager.hpp"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif

	SetWindowText("Re.Gleam");	// メインウインドウのウインドウタイトルを変更する

	SetBackgroundColor(255, 255, 255);

	SetUseDirect3DVersion(DX_DIRECT3D_11);			// Direct3D11を使用する

	ChangeWindowMode(TRUE);			// ウィンドウズモードにさせるかどうか

	SetEnableXAudioFlag(TRUE);			// XAudioを使用するようにする

	SetUseLarge3DPositionSupport(TRUE);		// 巨大な座標値をサポート

	SetGraphMode(1920, 1080, BASICPARAM::bitColor);					// 1920x1080xdefaultbit


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// ウィンドウデフォルト値を得る

	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);		// ウィンドウサイズに合わせてゲームサイズを変更

	SetAlwaysRunFlag(TRUE);		// 裏でもアクティブにする

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

#ifdef _DEBUG
	MyDebug::Init();
#endif // _DEBUG


	// ゲームの核
	while (/*ScreenFlip() == 0 && */ProcessMessage() == 0/* && ClearDrawScreen() == 0 */&& CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// コントローラーが２つ以上の時
		if (!firstControll)
		{
			ClearDrawScreen();
			if (DLLXinput::GetPadNum() == 0)
			{
				DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
					, "コントローラーが繋がっていません。終了します。");

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
					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
						, "コントローラーのAボタンを押してください。\nそれをコントローラーとして認証します。\n");


					// 少し待機してから入力を得られるようにする
					if (controllCount >= 10)
					{
						// １Pが入力された
						if (DLLXinput::GetPadButtonData(0, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
							controllCount = 0;
						}
						// ２Pが入力された
						if (DLLXinput::GetPadButtonData(1, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM02);
							controllCount = 0;
						}
						// ３Pが入力された
						if (DLLXinput::GetPadButtonData(2, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM03);
							controllCount = 0;
						}
						// ４Pが入力された
						if (DLLXinput::GetPadButtonData(3, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM04);
							controllCount = 0;
						}
					}


					// 入力されない時間で動きを与える
					if (controllCount >= COUNT && controllCount < COUNT + 400)
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180)
							, "入力を一定時間確認できません。再起動してみてください。\n");
					}
					// 何かしら問題があると判断して終了させる
					else if (controllCount >= COUNT + 400 && controllCount < COUNT + 550)		
					{
						DrawFormatString(BASICPARAM::winWidth / 2, (BASICPARAM::winHeight / 2) + 100, GetColor(0, 0, 180)
							, "問題が発生してると判断し、ゲームを終了します。\n");
					}
					else if (controllCount >= COUNT + 550)
					{
						break;
					}
				}
				// コントローラーが決定されたら
				else
				{
					controllCount++;
					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 0)
						, "コントローラーナンバー：%d を確認しました。ゲームを開始します。\n", (DLLXinput::GetPlayerPadNumber() + 1));
					if (controllCount >= 100)
					{
						firstControll = true;
					}
				}
			}
			ScreenFlip();
		}
		// ゲームを開始する条件としてのコントローラーが決定されたら
		else
		{
			DLLXinput::EverUpdate();

			manager->Update();

			SoundProcess::Process();

			DLLXinput::VibrationSlowlyStop(DLLXinput::GetPlayerPadNumber());
		}
	}

	SoundProcess::Release();

	// 削除
	POINTER_RELEASE(manager);

	DxLib_End();		// DXライブラリの後始末

	return 0;
}