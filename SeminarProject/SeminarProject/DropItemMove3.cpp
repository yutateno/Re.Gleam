#include "DropItemMove3.hpp"


DropItemMove3::DropItemMove3(const int draw, VECTOR area, const int tex0) : BasicObject()
{
	// 初期位置を設定
	this->area = area;


	// 目的位置を設定
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-250, 250);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-250, 250);        // Z座標用乱数
	nextAreaX = static_cast<float>(randInX(mt));
	nextAreaZ = static_cast<float>(randInZ(mt));
	moveAreaY = 0;


	// モデルデータの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);

	rotationY = 0;

	flyAroundFrame = 0;

	deathNow = false;

	aliveNow = false;


	// テクスチャ適応
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, true);


	// モデルのサイズを変更
	MV1SetScale(this->modelHandle, VGet(0.1f, 0.1f, 0.1f));

	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, this->area);
}

DropItemMove3::~DropItemMove3()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void DropItemMove3::Process()
{
	if (deathNow || !aliveNow) return;

	if (++rotationY >= 180) rotationY = 0;

	if (flyAroundFrame++ < 60)
	{
		area.x += nextAreaX / 60.0f;
		area.z += nextAreaZ / 60.0f;

		moveAreaY = (sin(-DX_PI_F / 2 + DX_PI_F / 30 * flyAroundFrame) + 1) / 2 * 120;
	}

	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotationY * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(this->modelHandle, VGet(area.x, area.y + moveAreaY, area.z));
}

void DropItemMove3::StolenChara(const VECTOR characterArea)
{
	if (deathNow || !aliveNow) return;

	// プレイヤーにちこうよれ
	if (characterArea.x < area.x - 20.0f)
	{
		area.x -= 10.0f;
	}
	else if (characterArea.x > area.x + 20.0f)
	{
		area.x += 10.0f;
	}
	if (characterArea.z < area.z - 20.0f)
	{
		area.z -= 10.0f;
	}
	else if (characterArea.z > area.z + 20.0f)
	{
		area.z += 10.0f;
	}
	if ((characterArea.y + 80.0f) < area.y - 4.0f)
	{
		area.y -= 2.0f;
	}
	else if ((characterArea.y + 80.0f) > area.y + 4.0f)
	{
		area.y += 2.0f;
	}
}

void DropItemMove3::TextureReload()
{
	if (deathNow) return;

	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インク的な\\correction\\normal\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インク的な\\correction\\D\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インク的な\\correction\\P\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インク的な\\correction\\normal\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
