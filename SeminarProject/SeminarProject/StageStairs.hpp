#pragma once
#include "BasicObject.hpp"


/*
階段のクラス
*/
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


	// テクスチャの切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();


	// Y軸の回転
	const float GetYAngle() const { return angle; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

