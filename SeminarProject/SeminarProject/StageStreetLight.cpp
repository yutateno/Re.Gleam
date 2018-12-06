#include "StageStreetLight.hpp"


StageStreetLight::StageStreetLight(const int draw, const int collStageHandle, const VECTOR area
	, const int tex0, const int tex1) : BasicObject(collStageHandle)
{
	this->area = area;


	shadowHeight = 10.0f;
	shadowSize = 5.0f;


	// モデルデータを読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// テクスチャ適応
	textureHandle0 = -1;
	textureHandle1 = -1;

	textureHandle0 = tex0;
	textureHandle1 = tex1;
	/*switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

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
	}*/

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);


	// 座標にモデルを配置
	MV1SetPosition(this->modelHandle, area);
}

StageStreetLight::~StageStreetLight()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	MODEL_RELEASE(modelHandle);
}

void StageStreetLight::Draw()
{
	BasicObject::ShadowFoot();


	BasicObject::Draw();
}

void StageStreetLight::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

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
