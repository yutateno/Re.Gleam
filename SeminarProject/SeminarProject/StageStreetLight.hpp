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
	StageStreetLight(const int draw, const VECTOR area, const int tex0, const int tex1);

	// デストラクタ
	~StageStreetLight();


	// 描画
	void Draw();

	// テクスチャ切り替え
	void TextureReload();
};

