#include "EnemyMove1.hpp"


// 動きのプロセス
void EnemyMove1::MoveProcess()
{
	// 上昇中のとき
	if (upNow)
	{
		// 上昇中
		if (60.0f > area.y)
		{
			area.y += flyMove;
			shadowSize -= flyMove;
		}
		// 上昇しきったら
		else
		{
			upNow = false;
			flyMove = -0.1f;
			shadowSize = 60.0f;
		}
	}
	// 下降中ののとき
	else
	{
		// 下降中
		if (area.y > 30.0f)
		{
			area.y -= flyMove;
			shadowSize += flyMove;;
		}
		// 下降しきったら
		else
		{
			upNow = true;
			flyMove = -0.1f;
			shadowSize = 90.0f;
		}
	}


	// 始発をゆっくりさせる
	if (flyMove < 0.5f)
	{
		flyMove += 0.05f;
	}
} /// void EnemyMove1::MoveProcess()


// コンストラクタ
EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ, const float color) : BasicCreature(true)
{
	// あたり判定のステージのコリジョン情報の更新
	stageHandle = -1;


	// 足影判定用のステージのコリジョン情報の更新
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(shadowStageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(shadowStageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）


	// モデルの向きと位置
	this->area = VGet(areaX, 40.0f, areaZ);


	// マテリアル
	material.Diffuse = GetColorF(0.0f, 0.0f, 1.0f, 0.0f);
	material.Specular = GetColorF(0.0f, 0.0f, 0.0f, 0.0f);
	material.Ambient = GetColorF(1.0f, 1.0f, 1.0f, 0.0f);
	material.Emissive = GetColorF(color, color, 1.0f, 0.0f);
	material.Power = 10.0f;


	// モデルの基本情報
	modelHeight = 10.0f;
	modelWidth = 10.0f;

	
	// 足元の影に関する
	shadowHeight = 70.0f;
	shadowSize = 90.0f;


	// 動きに関する
	upNow = true;
	flyMove = 0.0f;
} /// EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ, const float color) : BasicCreature(true)


// デストラクタ
EnemyMove1::~EnemyMove1()
{
	MODEL_RELEASE(shadowStageHandle);
}


// 描画
void EnemyMove1::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);
	SetMaterialParam(material);
	DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth, 16, GetColor(68, 178, 227), GetColor(255, 255, 255), TRUE);
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(FALSE);
	// Ｚバッファを有効にする
	SetUseZBuffer3D(FALSE);


#ifdef _DEBUG
	if (MyDebug::enemyOneDrawFlag)
	{
		VECTOR viewArea = VAdd(area, VGet(0.0f, 60.0f, 0.0f));		// モデルの初期Y座標が浮いているので調整

		DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth + 3, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}


// メインプロセス
void EnemyMove1::Process()
{
	// 動きのプロセス
	MoveProcess();
}


// プレイヤーが近づいたら
void EnemyMove1::NearChara(const VECTOR characterArea)
{
	// プレイヤーにちこうよれ
	if (characterArea.x < area.x - 4.0f)
	{
		area.x -= 2.0f;
	}
	else if( characterArea.x > area.x + 4.0f)
	{
		area.x += 2.0f;
	}
	if (characterArea.z < area.z - 4.0f)
	{
		area.z -= 2.0f;
	}
	else if(characterArea.z > area.z + 4.0f)
	{
		area.z += 2.0f;
	}
}
