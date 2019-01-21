#include "StageStairsRoad.hpp"



/// --------------------------------------------------------------------------------
StageStairsRoad::StageStairsRoad(const int draw, const VECTOR area
	, const int tex0, const int tex1, const float angle) : BasicObject()
{
	// 座標設定
	this->area = area;
	this->angle = angle;


	// モデルデータの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);


	// テクスチャ適応
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);


	// 座標にモデルを配置
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, this->angle, 0.0f));
	MV1SetPosition(modelHandle, this->area);
}



/// --------------------------------------------------------------------------------
StageStairsRoad::~StageStairsRoad()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle0);


	// モデル開放
	MODEL_RELEASE(modelHandle);
}



/// --------------------------------------------------------------------------------
void StageStairsRoad::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\階段と床合体\\normal\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\階段と床合体\\normal\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\階段と床合体\\D\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\階段と床合体\\D\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\階段と床合体\\P\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\階段と床合体\\P\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\階段と床合体\\normal\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\階段と床合体\\normal\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}
