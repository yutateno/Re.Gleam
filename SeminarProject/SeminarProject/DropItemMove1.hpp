#pragma once
#include "BasicObject.hpp"


class DropItemMove1 : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;


public:
	// コンストラクタ
	DropItemMove1(const int draw, const int tex0);

	// デストラクタ
	~DropItemMove1();


	// 描画
	void Draw();

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

