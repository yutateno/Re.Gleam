#include "LoadThread.hpp"

using namespace std;
mutex mtx;


// デッドロック抑制しながら非同期読み込み
void LoadThread::MyNextLoad(const std::string path, int& file, const ELOADFILE type)
{
	lock_guard<mutex> lock(mtx);

	LoadFile::MyLoad(path, file, type);
}


// コンストラクタ
LoadThread::LoadThread()
{
	num = 0;
	p_loadScreen = nullptr;
	p_loadScreen = new LoadScreen();
}


// デストラクタ
LoadThread::~LoadThread()
{
	POINTER_RELEASE(p_loadScreen);
	fileName.clear();
	fileName.shrink_to_fit();
}


// プロセス
void LoadThread::Process(const int max, const std::vector<std::string> path, const std::vector<ELOADFILE> type)
{
	if (num < max)
	{
		fileName.push_back(-1);
		ths = thread(&LoadThread::MyNextLoad, this, path[num], ref(fileName[num]), type[num]);
		ths.join();
		num++;
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);	// 背景描画
		p_loadScreen->Process(num, max);			// ロード画面
		ScreenFlip();
		Process(max, path, type);		// 読み込み終わるまで再帰
	}
}


// 描画
void LoadThread::Draw()
{
	p_loadScreen->Process(num, num);			// ロード画面
}
