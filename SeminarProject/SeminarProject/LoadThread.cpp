#include "LoadThread.hpp"

using namespace std;

std::mutex mtx;

void LoadThread::MyNextLoad(const std::string path, int& file, const ELOADFILE type)
{
	std::lock_guard<std::mutex> lock(mtx);

	LoadFile::MyLoad(path, file, type);
}

LoadThread::LoadThread()
{
	num = 0;
	p_loadScreen = nullptr;
	p_loadScreen = new LoadScreen();
}

LoadThread::~LoadThread()
{
	POINTER_RELEASE(p_loadScreen);
	fileName.clear();
	fileName.shrink_to_fit();
}

void LoadThread::Process(const int max, const std::string* path, const ELOADFILE* type)
{
	if (num < max)
	{
		fileName.push_back(0);
		ths = std::thread(&LoadThread::MyNextLoad, this, path[num], ref(fileName[num]), type[num]);
		ths.join();
		num++;
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);	// 背景描画
		p_loadScreen->Process(num, max);			// ロード画面
		ScreenFlip();
		Process(max, path, type);
	}
}

void LoadThread::Draw()
{
	p_loadScreen->Process(num, num);			// ロード画面
}
