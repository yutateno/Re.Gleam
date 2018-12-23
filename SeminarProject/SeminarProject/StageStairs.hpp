#pragma once
#include "BasicObject.hpp"


class StageStairs : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;

	
	// Y軸に回転
	float angle;


public:
	// コンストラクタ
	StageStairs(const int draw, const VECTOR area, const int tex0, const float angle);

	// デストラクタ
	~StageStairs();


	// 描画
	void Draw();

	// テクスチャの切り替え
	void TextureReload();

	// Y軸の回転
	const float GetYAngle() const { return angle; }
};

