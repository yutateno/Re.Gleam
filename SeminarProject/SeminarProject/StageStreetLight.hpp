#pragma once
#include "BasicObject.hpp"


class StageStreetLight : public BasicObject
{
public:
	// コンストラクタ
	StageStreetLight(const int draw, const int collStageHandle, const VECTOR area);

	// デストラクタ
	~StageStreetLight();


	// 描画
	void Draw();
};

