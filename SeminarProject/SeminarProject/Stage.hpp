#pragma once
#include "Basic.hpp"


class Stage
{
private:
	// ステージ
	int drawStageHandle;		


public:
	// コンストラクタ
	Stage(const int drawStageHandle);		

	// デストラクタ
	~Stage();						


	// 描画
	void Draw();
};
