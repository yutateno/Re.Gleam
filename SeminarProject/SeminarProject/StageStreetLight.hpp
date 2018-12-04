#pragma once
#include "BasicObject.hpp"


class StageStreetLight : public BasicObject
{
private:
	// テクスチャ
	int textureHandle0;
	int textureHandle1;


public:
	// コンストラクタ
	StageStreetLight(const int draw, const int collStageHandle, const VECTOR area);

	// デストラクタ
	~StageStreetLight();


	// 描画
	void Draw();
};

