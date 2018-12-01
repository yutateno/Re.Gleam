#pragma once
#include "BasicObject.hpp"


class StagePaneru : public BasicObject
{
public:
	// コンストラクタ
	StagePaneru(const int draw, const int collStageHandle, const VECTOR area);

	// デストラクタ
	~StagePaneru();


	// 描画
	void Draw();
};

