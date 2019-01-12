#include "StageStreetLight.hpp"


// コンストラクタ
StageStreetLight::StageStreetLight(const int draw, const VECTOR area
	, const int tex0, const int tex1, const float angle) : BasicObject()
{
	// 座標と角度の初期化
	this->area = area;
	this->angle = angle;


	// モデルデータを読み込み
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
	MV1SetPosition(this->modelHandle, this->area);
}


// デストラクタ
StageStreetLight::~StageStreetLight()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);


	// モデル開放
	MODEL_RELEASE(modelHandle);
}


// テクスチャ差し替え
void StageStreetLight::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\D\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\D\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\P\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\P\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}
