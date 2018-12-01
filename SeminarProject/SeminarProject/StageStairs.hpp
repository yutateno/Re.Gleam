#pragma once
#include "BasicObject.hpp"


class StageStairs : public BasicObject
{
public:
	// コンストラクタ
	StageStairs(const int draw, const int collStageHandle, const VECTOR area);

	// デストラクタ
	~StageStairs();


	// 描画
	void Draw();
};

