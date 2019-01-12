#include "AdjustmentMachine.hpp"


// コンストラクタ
AdjustmentMachine::AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1): BasicObject()
{
	// 座標初期化
	this->area = area;


	// モデルデータを読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);

	
	// 情報初期化
	modelHeight = 100.0f;
	modelWidth = 70.0f;


	// ムーブ2用の変数
	if (BASICPARAM::e_nowScene <= ESceneNumber::SECONDMOVE)
	{
		canTouch = false;
		blendCount = 0;
		dropCount = 0;
		nextBlendCount = 0;
	}
	else
	{
		canTouch = true;
	}


	// テクスチャ適応
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandleDisplayBlack = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	LoadFile::MyLoad("media\\こっち\\media\\Terminal\\T_displayblack.pyn", textureHandleDisplayBlack, ELOADFILE::graph);
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandleDisplayBlack, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);


	// 座標にモデルを配置
	MV1SetPosition(this->modelHandle, area);
} /// AdjustmentMachine::AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1): BasicObject()


// デストラクタ
AdjustmentMachine::~AdjustmentMachine()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandleDisplayBlack);


	// モデル開放
	MODEL_RELEASE(modelHandle);
}


// 描画
void AdjustmentMachine::Draw()
{
	// ムーブ2以下で透過がまだされていたら
	if (BASICPARAM::e_nowScene <= ESceneNumber::SECONDMOVE
		&& blendCount < 255)
	{
		if (nextBlendCount > blendCount) blendCount += 3;
		nextBlendCount = dropCount * 17;

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
	}
	else
	{
		if(!canTouch) canTouch = true;
	}

#ifdef _DEBUG
	if (MyDebug::adjustmentMachineDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
	}
#endif // _DEBUG
}


// テクスチャ差し替え
void AdjustmentMachine::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\normal\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\normal\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\D\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\D\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\P\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\P\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\normal\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\Terminal\\normal\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}


// ディスプレイのテクスチャを切り替える
void AdjustmentMachine::ChangeDisplayTexture(bool touchNow)
{
	if (touchNow)
	{
		MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	}
	else
	{
		MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandleDisplayBlack, false);
	}
}
