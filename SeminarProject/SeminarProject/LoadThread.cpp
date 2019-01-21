#include "LoadThread.hpp"

using namespace std;
mutex mtx;



/// ---------------------------------------------------------------------------------------
void LoadThread::MyNextLoad(const std::string path, int& file, const ELOADFILE type)
{
	lock_guard<mutex> lock(mtx);

	LoadFile::MyLoad(path, file, type);
}



/// ---------------------------------------------------------------------------------------
LoadThread::LoadThread()
{
	num = 0;
	p_loadScreen = nullptr;
	p_loadScreen = new LoadScreen();
}



/// ---------------------------------------------------------------------------------------
LoadThread::~LoadThread()
{
	POINTER_RELEASE(p_loadScreen);
	fileName.clear();
	fileName.shrink_to_fit();
}



/// ---------------------------------------------------------------------------------------
void LoadThread::Process(const int max, const std::vector<std::string> path
	, const std::vector<ELOADFILE> type)
{
	if (num < max)
	{
		fileName.push_back(-1);
		ths = thread(&LoadThread::MyNextLoad, this, path[num]
			, ref(fileName[num]), type[num]);
		ths.join();
		num++;
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);				// �w�i�`��
		p_loadScreen->Process(num, max);			// ���[�h���
		ScreenFlip();
		Process(max, path, type);					// �ǂݍ��ݏI���܂ōċA
	}
}



/// ---------------------------------------------------------------------------------------
void LoadThread::Draw()
{
	p_loadScreen->Process(num, num);			// ���[�h���
}
