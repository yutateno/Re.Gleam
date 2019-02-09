#pragma once
#include "BasicObject.hpp"


/*
階段と床のクラス
*/
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
	StageStairsRoad(const int draw, const VECTOR area, const int tex0
		, const int tex1, const float angle);

	// デストラクタ
	~StageStairsRoad();


	// テクスチャ切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();


	// Y軸の回転
	const float GetYAngle() const { return angle; }
};

