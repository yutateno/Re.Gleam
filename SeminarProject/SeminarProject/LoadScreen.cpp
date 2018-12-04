#include "LoadScreen.hpp"

LoadScreen::LoadScreen()
{
	draw = 0;
	LoadFile::MyLoad("media\\こっち\\media\\load.pyn", draw, ELOADFILE::graph);
	endDraw = 0;
	LoadFile::MyLoad("media\\こっち\\media\\ロード終了.pyn", endDraw, ELOADFILE::graph);
}

LoadScreen::~LoadScreen()
{
	GRAPHIC_RELEASE(draw);
	GRAPHIC_RELEASE(endDraw);
}

void LoadScreen::Process(const int num, const int max)
{
	if (num < max)
	{
		DrawGraph(0, 0, draw, false);
	}
	else
	{
		DrawGraph(0, 0, endDraw, false);
	}
}
