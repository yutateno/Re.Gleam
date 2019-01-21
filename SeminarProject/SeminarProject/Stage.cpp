#include "Stage.hpp"



/// ------------------------------------------------------------------------
Stage::Stage(const int drawStageHandle)
{
	// モデルハンドル受け渡し
	this->drawStageHandle = MV1DuplicateModel(drawStageHandle);
	// サイズを設定
	MV1SetScale(this->drawStageHandle, VGet(0.75f, 0.75f, 0.75f));
	// 座標を指定
	MV1SetPosition(this->drawStageHandle, VGet(0, 0, 0));
}



/// ------------------------------------------------------------------------
Stage::~Stage()
{
	// モデル開放
	MODEL_RELEASE(drawStageHandle);
}



/// ------------------------------------------------------------------------
void Stage::Draw()
{
	MV1DrawModel(drawStageHandle);


#ifdef _DEBUG
	if (MyDebug::stageDrawFlag)
	{
		int i;
		VECTOR Pos1;
		VECTOR Pos2;
		float LINE_AREA_SIZE = 100000.0f;
		int LINE_NUM = 50;

		SetUseZBufferFlag(TRUE);

		Pos1 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
		Pos2 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, LINE_AREA_SIZE / 2.0f);
		for (i = 0; i <= LINE_NUM; i++)
		{
			DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
			Pos1.x += LINE_AREA_SIZE / LINE_NUM;
			Pos2.x += LINE_AREA_SIZE / LINE_NUM;
		}

		Pos1 = VGet(-LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
		Pos2 = VGet(LINE_AREA_SIZE / 2.0f, 0.0f, -LINE_AREA_SIZE / 2.0f);
		for (i = 0; i < LINE_NUM; i++)
		{
			DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
			Pos1.z += LINE_AREA_SIZE / LINE_NUM;
			Pos2.z += LINE_AREA_SIZE / LINE_NUM;
		}

		SetUseZBufferFlag(FALSE);
	}
#endif // _DEBUG
} /// void Stage::Draw()
