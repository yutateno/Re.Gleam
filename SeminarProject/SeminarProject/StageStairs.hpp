#pragma once
#include "BasicObject.hpp"


class StageStairs : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;


public:
	// コンストラクタ
	StageStairs(const int draw, const VECTOR area, const int tex0);

	// デストラクタ
	~StageStairs();


	// 描画
	void Draw();

	// テクスチャの切り替え
	void TextureReload();
};

