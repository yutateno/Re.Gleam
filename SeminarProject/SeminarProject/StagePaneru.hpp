#pragma once
#include "BasicObject.hpp"


class StagePaneru : public BasicObject
{
public:
	// コンストラクタ
	StagePaneru(const int draw, const VECTOR area);

	// デストラクタ
	~StagePaneru();


	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}

};

