#include "StageStairs.hpp"


StageStairs::StageStairs(const int draw, const int collStageHandle, const VECTOR area, const int tex0) : BasicObject(collStageHandle)
{
	// 座標設定
	this->area = area;


	// 影の設定
	shadowHeight = 10.0f;
	shadowSize = 5.0f;


	// モデルデータの読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// テクスチャ適応
	textureHandle = -1;

	textureHandle = tex0;
	/*switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}*/

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);


	// 座標にモデルを配置
	MV1SetPosition(modelHandle, area);
}

StageStairs::~StageStairs()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void StageStairs::Draw()
{
	BasicObject::ShadowFoot();


	BasicObject::Draw();
}

void StageStairs::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
