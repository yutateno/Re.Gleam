#include "Manager.hpp"


/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウサイズを決める
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif


	SetWindowText("Re.Gleam");					// メインウインドウのウインドウタイトルを変更する
	SetBackgroundColor(255, 255, 255);			// 背景色を白に変更
	SetUseDirect3DVersion(DX_DIRECT3D_11);		// Direct3D11を使用する
	ChangeWindowMode(TRUE);						// ウィンドウズモードにさせる
	SetEnableXAudioFlag(TRUE);					// XAudioを使用するようにする
	SetUseLarge3DPositionSupport(TRUE);			// 巨大な座標値をサポート
	SetWindowIconID(333);


	SetGraphMode(BASICPARAM::winWidth, BASICPARAM::winHeight, BASICPARAM::bitColor);			// 画面サイズ設定
	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// デフォルトウィンドウ値を得る
	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);									// デフォルトウィンドウサイズに合わせてゲームサイズを変更

	
	// 画面サイズに戻す
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}


	// Effekseerを初期化する。引数には画面に表示する最大パーティクル数を設定する。
	if (Effkseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}


	// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);


	Effekseer_Set2DSetting(1920, 1080);	// 2Dエフェクトの最大範囲を設定


	SetAlwaysRunFlag(TRUE);			// 裏でもアクティブにする
	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画
	SetMouseDispFlag(FALSE);		// マウスカーソルを非表示にする


	// コントローラーの初期化
	DLLXinput::Init();
	DLLXinput::FirstUpdate();


	// メイン処理をnewする
	Manager* manager = new Manager();


	// 最初にコントローラーを設定するための確認コマンド
	bool firstControll = false;						// コントローラーが押されてないのでゲームを起動しないよう
	DLLXinput::SetPlayerPadNum(5);
	int controllCount = 0;							// コマンドに関する時間
	bool noTouch = true;							// コマンドを押されない時間経過次第で再起動を促すよう処理
	const int COUNT = 600;							// コマンド時間の数値

												
	// 接続数が一つの場合は確認しない
	if (DLLXinput::GetPadNum() == 1)
	{
		DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
		firstControll = true;
	}


	SoundProcess::Init();			// サウンドプロセスの初期化

#ifdef _DEBUG
	MyDebug::Init();
#endif // _DEBUG


	// ゲームの核
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !manager->GetEnd())
	{
		// コントローラーが一つでないとき
		if (!firstControll)
		{
			ClearDrawScreen();


			// コントローラーが繋がっていないとき
			if (DLLXinput::GetPadNum() == 0)
			{
				DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
					, "コントローラーが繋がっていません。終了します。");


				controllCount++;				// ゲーム終了までのカウント加算


				// ゲーム終了する
				if (controllCount >= 50) break;
			}
			// コントローラーが繋がっているとき
			else
			{
				DLLXinput::FirstUpdate();		// コントローラーの更新


				// コントローラーが決まっていなかったら
				if (DLLXinput::GetPlayerPadNumber() == 5)
				{
					controllCount++;			// コントローラーの入力待機カウント加算


					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 180)
						, "コントローラーのAボタンを押してください。\nそれをコントローラーとして認証します。\n");


					// 少し待機してから入力を得られるようにする
					if (controllCount >= 10)
					{
						// １Pが入力された
						if (DLLXinput::GetPadButtonData(0, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 1Pを操作コントローラーとする
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM01);
							controllCount = 0;
						}
						// ２Pが入力された
						if (DLLXinput::GetPadButtonData(1, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 2Pを操作コントローラーとする
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM02);
							controllCount = 0;
						}
						// ３Pが入力された
						if (DLLXinput::GetPadButtonData(2, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
						{
							// 3Pを操作コントローラーとする
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM03);
							controllCount = 0;
						}
						// ４Pが入力された
						if (DLLXinput::GetPadButtonData(3, DLLXinput::XINPUT_PAD::BUTTON_A) == 1)		
						{
							// 4Pを操作コントローラーとする
							DLLXinput::SetPlayerPadNum(DLLXinput::XINPUT_PAD::NUM04);
							controllCount = 0;
						}
					} /// if (controllCount >= 10)


					// 入力されない時間が逝って以上だったら
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
					// 終了させる
					else if (controllCount >= COUNT + 550) break;


				} /// if (DLLXinput::GetPlayerPadNumber() == 5)
				// コントローラーが決定されたら
				else
				{
					controllCount++;		// ゲームを開始するカウントを加算


					DrawFormatString(BASICPARAM::winWidth / 2, BASICPARAM::winHeight / 2, GetColor(0, 0, 0)
						, "コントローラーナンバー：%d を確認しました。ゲームを開始します。\n", (DLLXinput::GetPlayerPadNumber() + 1));


					// コントローラーが決まったとする
					if (controllCount >= 100) firstControll = true;
				}
			} /// else(!if (DLLXinput::GetPadNum() == 0))
			ScreenFlip();
		} /// if (!firstControll)
		// ゲームを開始する条件としてのコントローラーが決定されたら
		else
		{
			DLLXinput::EverUpdate();

			manager->Update();

			SoundProcess::Process();

			DLLXinput::VibrationSlowlyStop(DLLXinput::GetPlayerPadNumber());
		}
	} /// while


	// 削除
	POINTER_RELEASE(manager);


	SoundProcess::Release();		// サウンド開放
	InitSoundMem();					// サウンド開放
	InitGraph();					// 画像解放
	MV1InitModel();					// モデル開放


	Effkseer_End();		// Effekseerを終了する。


	DxLib_End();		// DXライブラリの後始末


	return 0;
}