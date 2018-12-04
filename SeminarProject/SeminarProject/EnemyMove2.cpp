#include "EnemyMove2.hpp"


EnemyMove2::EnemyMove2(const int collStageHandle, const VECTOR area, const int modelHandle) : BasicCreature(collStageHandle)
{
	// 座標を設定
	this->area = VAdd(area, VGet(0.0f, 10.0f, 0.0f));


	// サイズを設定
	modelHeight = 100.0f;
	modelWigth = 50.0f;

	shadowHeight = 10.0f;
	shadowSize = 15.0f;


	// モデルデータの読み込み
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// テクスチャ適応
	textureHandle = -1;
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

	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);

	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// 座標にモデルを配置
	MV1SetPosition(this->modelHandle, area);
}

EnemyMove2::~EnemyMove2()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void EnemyMove2::Draw()
{
	if (!deathFlag)
	{
		BasicObject::ShadowFoot();
	}

	BasicObject::Draw();



#ifdef _ENEMY2_DEBUG
	DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWigth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
#endif // _ENEMY2_DEBUG
}

void EnemyMove2::Process()
{
	// ステージのあたり判定
	StageHit();


	// ダメージ受けた時
	if (damageHit)
	{
		deathFlag = true;
	}

	// 死んだとき
	if (deathFlag)
	{
		if (blendCount >= 0)
		{
			blendCount--;
		}
		else
		{
			viewDrawFlag = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	}

	MV1SetPosition(this->modelHandle, area);
}

void EnemyMove2::SetArea(const VECTOR area)
{
	this->area = area;
}
