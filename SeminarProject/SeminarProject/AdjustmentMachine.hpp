#pragma once
#include "BasicObject.hpp"


/*
ムーブ２以降に出て、次へのステージを出すオペレーターのクラス
*/
class AdjustmentMachine : public BasicObject
{
private:
	// テクスチャ
	int textureHandle0;
	int textureHandle1;
	int textureHandleDisplayBlack;


	/// ムーブ2用のブレンド-------------------------------

	int blendCount;
	int nextBlendCount;
	// ムーブ2にて何個ドロップアイテム得たかどうか
	int dropCount;

	
	// 触れるフラッグ
	bool canTouch;


public:
	AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1);
	~AdjustmentMachine();

	// 描画
	void Draw();


	// テクスチャの切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();

	// 触れられ次第でテクスチャを切り替える
	void ChangeDisplayTexture(bool touchNow);

	// 触れるフラッグ
	const bool GetCanTouch()const { return canTouch; }

	// いくつドロップアイテム得たかどうか
	void CatchDropItem() { dropCount++; }

	// もうドロップアイテムいらないかどうか
	const bool GetFullDropItem() const { return dropCount < 15 ? false : true; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

