#include "StageStairs.hpp"



/// --------------------------------------------------------------------------------
StageStairs::StageStairs(const int draw, const VECTOR area
	, const int tex0, const float angle) : BasicObject()
{
	// 座標設定
	this->area = area;
	this->angle = angle;
	

	// モデルデータの読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// テクスチャ適応
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);


	// 座標にモデルを配置
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, this->angle, 0.0f));
	MV1SetPosition(modelHandle, this->area);
}



/// --------------------------------------------------------------------------------
StageStairs::~StageStairs()
{
	// テクスチャ解放
	GRAPHIC_RELEASE(textureHandle);

	
	// モデル開放
	MODEL_RELEASE(modelHandle);
}



/// --------------------------------------------------------------------------------
void StageStairs::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
