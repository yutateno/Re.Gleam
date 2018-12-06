#pragma once
#include "BasicObject.hpp"

#include <random>

class DropItemMove2 : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;

public:
	DropItemMove2(const int draw, VECTOR area, const int tex0);
	~DropItemMove2();


	// 描画
	void Draw();

	// テクスチャ切り替え
	void TextureReload();
};

