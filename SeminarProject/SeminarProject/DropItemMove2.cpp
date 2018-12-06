#include "DropItemMove2.hpp"


DropItemMove2::DropItemMove2(const int draw, VECTOR area, const int tex0) : BasicObject()
{
	// 初期位置を設定
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-20, 20);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-20, 20);        // Z座標用乱数
	this->area = VAdd(area, VGet(static_cast<float>(randInX(mt)), 0.0f, static_cast<float>(randInZ(mt))));

	// モデルデータの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);


	// テクスチャ適応
	textureHandle = -1;

	textureHandle = tex0;

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, true);


	// モデルのサイズを変更
	MV1SetScale(this->modelHandle, VGet(0.2f, 0.2f, 0.2f));

	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, this->area);
}


DropItemMove2::~DropItemMove2()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void DropItemMove2::Draw()
{
	BasicObject::Draw();
}

void DropItemMove2::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\ブロック\\whiteblack\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\ブロック\\normal\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\ブロック\\D\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\ブロック\\P\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\ブロック\\normal\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
