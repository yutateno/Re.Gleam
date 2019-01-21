#include "StagePaneru.hpp"



/// --------------------------------------------------------------------------------
StagePaneru::StagePaneru(const int draw, const VECTOR area) : BasicObject()
{
	// 座標を設定
	this->area = area;

	
	// モデル読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);

	
	// サイズ変更
	MV1SetScale(this->modelHandle, VGet(50.0f, 50.0f, 50.0f));
	// 座標を更新
	MV1SetPosition(this->modelHandle, area);
}



/// --------------------------------------------------------------------------------
StagePaneru::~StagePaneru()
{
	// モデル開放
	MODEL_RELEASE(modelHandle);
}
