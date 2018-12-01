#pragma once
#include "LoadFile.hpp"


class LoadScreen
{
private:
	// ロード画面
	int draw;

	// ロード終了
	int endDraw;


public:
	// コンストラクタ
	LoadScreen();

	// デストラクタ
	~LoadScreen();


	// 非同期で行うメソッド
	void Process(const int num, const int max);
};

