#pragma once
#include "BasicObject.hpp"


class AdjustmentMachine : public BasicObject
{
private:
	// テクスチャ
	int textureHandle0;
	int textureHandle1;
	int textureHandleDisplayBlack;


public:
	AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1);
	~AdjustmentMachine();

	// 描画
	void Draw();

	// テクスチャの切り替え
	void TextureReload();

	// 触れられ次第でテクスチャを切り替える
	void ChangeDisplayTexture(bool touchNow);
};

