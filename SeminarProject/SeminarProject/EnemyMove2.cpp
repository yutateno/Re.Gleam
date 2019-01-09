#include "EnemyMove2.hpp"


EnemyMove2::EnemyMove2(const VECTOR area, const int modelHandle, const int tex0) : BasicCreature()
{
	shadowStageHandle = -1;
	stageHandle = -1;
	// 座標を設定
	this->area = VAdd(area, VGet(0.0f, 10.0f, 0.0f));


	// サイズを設定
	modelHeight = 100.0f;
	modelWidth = 100.0f;


	// モデルデータの読み込み
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// テクスチャ適応
	MV1SetTextureGraphHandle(this->modelHandle, 0, tex0, false);

	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);

	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// 座標にモデルを配置
	MV1SetPosition(this->modelHandle, area);


	MV1SetupCollInfo(this->modelHandle, -1);
}

EnemyMove2::~EnemyMove2()
{
	MODEL_RELEASE(modelHandle);
}

void EnemyMove2::Draw()
{
#ifdef _DEBUG
	if (MyDebug::enemyTwoDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
	}
#endif // _DEBUG
}

void EnemyMove2::Process()
{
	if (eraseExistence) return;


	// ダメージ受けた時
	if (damageHit)
	{
		deathFlag = true;

		damageHit = false;
	}

	// 死んだとき
	if (deathFlag)
	{
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		else
		{
			eraseExistence = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	}

	MV1SetPosition(this->modelHandle, area);
}
