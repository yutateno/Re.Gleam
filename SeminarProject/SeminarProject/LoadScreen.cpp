#include "LoadScreen.hpp"

LoadScreen::LoadScreen()
{
	for (int i = 0; i != 6; ++i)
	{
		draw[i] = -1;
	}
	endDraw = 0;


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\6.pyn", draw[5], ELOADFILE::graph);

		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\ex\\normal\\jamp2.pyn", endDraw, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\D\\6.pyn", draw[5], ELOADFILE::graph);

		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\ex\\D\\jamp2.pyn", endDraw, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\P\\6.pyn", draw[5], ELOADFILE::graph);

		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\ex\\P\\jamp2.pyn", endDraw, ELOADFILE::graph);
		break;

	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\whiteblack\\6.pyn", draw[5], ELOADFILE::graph);

		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\ex\\whiteblack\\jamp2.pyn", endDraw, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\1.pyn", draw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\2.pyn", draw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\3.pyn", draw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\4.pyn", draw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\5.pyn", draw[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\walk\\normal\\6.pyn", draw[5], ELOADFILE::graph);

		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\clph_2d\\scrollaction\\ex\\normal\\jamp2.pyn", endDraw, ELOADFILE::graph);
		break;
	}

	walkCount = 0;
}

LoadScreen::~LoadScreen()
{
	for (int i = 0; i != 6; ++i)
	{
		GRAPHIC_RELEASE(draw[i]);
	}
	GRAPHIC_RELEASE(endDraw);
}

void LoadScreen::Process(const int num, const int max)
{
	if (++walkCount > 5) walkCount = 0;
	if (num < max)
	{
		DrawGraph(BASICPARAM::winWidth - (num * static_cast<int>(BASICPARAM::winWidth / max)), BASICPARAM::winHeight - 260, draw[walkCount], true);
	}
	else
	{
		DrawGraph(0, BASICPARAM::winHeight - 260, endDraw, true);
	}
}
