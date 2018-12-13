#pragma once
#include "BasicObject.hpp"


class DropItemMove1 : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;


public:
	// コンストラクタ
	DropItemMove1(const int draw, const int collStageHandle, const int tex0);

	// デストラクタ
	~DropItemMove1();


	// 描画
	void Draw();
};

