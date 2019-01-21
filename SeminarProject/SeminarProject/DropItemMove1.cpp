#include "DropItemMove1.hpp"



/// -------------------------------------------------------------------------------------------
DropItemMove1::DropItemMove1(const int draw, const int tex0) : BasicObject()
{
	// 初期位置を設定
	area = VGet(1000.0f, 0.0f, 1000.0f);


	// 影のサイズを設定
	BasicObject::shadowHeight = 10.0f;
	BasicObject::shadowSize = 5.0f;


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
	MV1SetPosition(this->modelHandle, area);
}



/// -------------------------------------------------------------------------------------------
DropItemMove1::~DropItemMove1()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}



/// -------------------------------------------------------------------------------------------
void DropItemMove1::Draw()
{
#ifdef _DEBUG
	if (MyDebug::dropItemOneDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, 1.0f, 0.0f)), 80.0f, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}
