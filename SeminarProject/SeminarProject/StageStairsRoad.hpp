#pragma once
#include "BasicObject.hpp"


class StageStairsRoad : public BasicObject
{
private:
	// テクスチャ
	int textureHandle0;
	int textureHandle1;


	// Y軸に回転
	float angle;


public:
	// コンストラクタ
	StageStairsRoad(const int draw, const VECTOR area, const int tex0, const int tex1, const float angle);

	// デストラクタ
	~StageStairsRoad();


	// テクスチャ切り替え
	void TextureReload();


	// Y軸の回転
	const float GetYAngle() const { return angle; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

