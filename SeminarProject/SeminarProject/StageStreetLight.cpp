#include "StageStreetLight.hpp"


StageStreetLight::StageStreetLight(const int draw, const VECTOR area, const int tex0, const int tex1, const float angle) : BasicObject()
{
	this->area = area;
	this->angle = angle;


	// ƒ‚ƒfƒ‹ƒf[ƒ^‚ð“Ç‚Ýž‚Ý
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// ƒeƒNƒXƒ`ƒƒ“K‰ž
	textureHandle0 = -1;
	textureHandle1 = -1;

	textureHandle0 = tex0;
	textureHandle1 = tex1;

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);


	// À•W‚Éƒ‚ƒfƒ‹‚ð”z’u
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, this->angle, 0.0f));
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
	BasicObject::Draw();
}

void StageStreetLight::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\whiteblack\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\whiteblack\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\D\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\D\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\P\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\P\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\‚±‚Á‚¿\\media\\ŠX“”\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}
