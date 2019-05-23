#include "LoadScreen.hpp"



/// ---------------------------------------------------------------------------------------
LoadScreen::LoadScreen()
{
	// 情報初期化
	for (int i = 0; i != 7; ++i)
	{
		draw[i] = -1;
	}
	endDraw = 0;
	walkCount = 0;


	// 状態に応じて読み込む2Dモデルを変更
	switch (BASICPARAM::e_TextureColor)
	{
	// 通常色のとき
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\load\\walk\\normal\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\6.pyn", draw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\icon\\normal.pyn", draw[6], ELOADFILE::graph);

		LoadFile::MyLoad("media\\load\\ex\\normal.pyn", endDraw, ELOADFILE::graph);
		break;


	// D型補正のとき
	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\load\\walk\\D\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\D\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\D\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\D\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\D\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\D\\6.pyn", draw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\icon\\D.pyn", draw[6], ELOADFILE::graph);

		LoadFile::MyLoad("media\\load\\ex\\D.pyn", endDraw, ELOADFILE::graph);
		break;


	// P型補正のとき
	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\load\\walk\\P\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\P\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\P\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\P\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\P\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\P\\6.pyn", draw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\icon\\P.pyn", draw[6], ELOADFILE::graph);

		LoadFile::MyLoad("media\\load\\ex\\P.pyn", endDraw, ELOADFILE::graph);
		break;


	// 白黒のとき
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\whiteblack\\6.pyn", draw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\icon\\whiteblack.pyn", draw[6], ELOADFILE::graph);

		LoadFile::MyLoad("media\\load\\ex\\whiteblack.pyn", endDraw, ELOADFILE::graph);
		break;


	default:
		LoadFile::MyLoad("media\\load\\walk\\normal\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\walk\\normal\\6.pyn", draw[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\load\\icon\\normal.pyn", draw[6], ELOADFILE::graph);

		LoadFile::MyLoad("media\\load\\ex\\normal.pyn", endDraw, ELOADFILE::graph);
		break;
	}
} /// LoadScreen::LoadScreen()



/// ---------------------------------------------------------------------------------------
LoadScreen::~LoadScreen()
{
	for (int i = 0; i != 7; ++i)
	{
		GRAPHIC_RELEASE(draw[i]);
	}
	GRAPHIC_RELEASE(endDraw);
}



/// ---------------------------------------------------------------------------------------
void LoadScreen::Process(const int num, const int max)
{
	if (++walkCount > 5) walkCount = 0;


	// ロード中のロゴを出す
	DrawGraph(50, 50, draw[6], true);


	// 読み込み個数に応じて右から左に走らせる
	if (num < max)
	{
		DrawGraph(BASICPARAM::winWidth - (num * static_cast<int>(BASICPARAM::winWidth / max))
			, BASICPARAM::winHeight - 260, draw[walkCount], true);
	}
	else
	{
		DrawGraph(0, BASICPARAM::winHeight - 260, endDraw, true);
	}
}
