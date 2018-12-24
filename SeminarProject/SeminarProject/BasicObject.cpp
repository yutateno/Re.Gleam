#include "BasicObject.hpp"


// 足の影
void BasicObject::ShadowFoot()
{
	// ライティングを無効にする
	SetUseLighting(FALSE);

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// テクスチャアドレスモードを CLAMP にする( テクスチャの端より先は端のドットが延々続く )
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);

	// プレイヤーの直下に存在する地面のポリゴンを取得
	ShadowHitResDim = MV1CollCheck_Capsule(stageHandle, -1, area, VAdd(area, VGet(0.0f, shadowHeight, 0.0f)), shadowSize);

	// 頂点データで変化が無い部分をセット
	ShadowVertex[0].dif = GetColorU8(255, 255, 255, 255);
	ShadowVertex[0].spc = GetColorU8(0, 0, 0, 0);
	ShadowVertex[0].su = 0.0f;
	ShadowVertex[0].sv = 0.0f;
	ShadowVertex[1] = ShadowVertex[0];
	ShadowVertex[2] = ShadowVertex[0];

	// 球の直下に存在するポリゴンの数だけ繰り返し
	ShadowHitRes = ShadowHitResDim.Dim;
	for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)
	{
		// ポリゴンの座標は地面ポリゴンの座標
		ShadowVertex[0].pos = ShadowHitRes->Position[0];
		ShadowVertex[1].pos = ShadowHitRes->Position[1];
		ShadowVertex[2].pos = ShadowHitRes->Position[2];

		// ちょっと持ち上げて重ならないようにする
		ShadowSlideVec = VScale(ShadowHitRes->Normal, 0.5f);
		ShadowVertex[0].pos = VAdd(ShadowVertex[0].pos, ShadowSlideVec);
		ShadowVertex[1].pos = VAdd(ShadowVertex[1].pos, ShadowSlideVec);
		ShadowVertex[2].pos = VAdd(ShadowVertex[2].pos, ShadowSlideVec);

		// ポリゴンの不透明度を設定する
		ShadowVertex[0].dif.a = 0;
		ShadowVertex[1].dif.a = 0;
		ShadowVertex[2].dif.a = 0;
		if (ShadowHitRes->Position[0].y > area.y - shadowHeight)
		{
			ShadowVertex[0].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[0].y - area.y) / shadowHeight));
		}

		if (ShadowHitRes->Position[1].y > area.y - shadowHeight)
		{
			ShadowVertex[1].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[1].y - area.y) / shadowHeight));
		}

		if (ShadowHitRes->Position[2].y > area.y - shadowHeight)
		{
			ShadowVertex[2].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[2].y - area.y) / shadowHeight));
		}

		// ＵＶ値は地面ポリゴンとプレイヤーの相対座標から割り出す
		ShadowVertex[0].u = (ShadowHitRes->Position[0].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[0].v = (ShadowHitRes->Position[0].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[1].u = (ShadowHitRes->Position[1].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[1].v = (ShadowHitRes->Position[1].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[2].u = (ShadowHitRes->Position[2].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[2].v = (ShadowHitRes->Position[2].z - area.z) / (shadowSize * 2.0f) + 0.5f;

		// 影ポリゴンを描画
		DrawPolygon3D(ShadowVertex, 1, shadowHandle, TRUE);
	}

	// 検出した地面ポリゴン情報の後始末
	MV1CollResultPolyDimTerminate(ShadowHitResDim);

	// ライティングを有効にする
	SetUseLighting(TRUE);

	// Ｚバッファを無効にする
	SetUseZBuffer3D(FALSE);
}



BasicObject::BasicObject()
{
	notViewCount = 0;


	// 初期化
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
}

BasicObject::BasicObject(const int collStageHandle)
{
	shadowHandle = 0;
	stageHandle = 0;

	// 影の読み込み
	LoadFile::MyLoad("media\\こっち\\media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);


	// ステージのコリジョン情報の更新
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetupCollInfo(stageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetFrameVisible(stageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(stageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）

	notViewCount = 0;

	optionRotaCount = 0;


	// 初期化
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
}


BasicObject::~BasicObject()
{
	GRAPHIC_RELEASE(shadowHandle);
	MODEL_RELEASE(stageHandle);
}

// 描画
void BasicObject::Draw()
{
	/*if (modelHeight >= 40.0f)
	{
		if (!CheckCameraViewClip(VAdd(area, VGet(0.0f, 30.0f, 0.0f))))
		{
			MV1DrawModel(modelHandle);
		}
	}
	else
	{
		if (!CheckCameraViewClip(VAdd(area, VGet(0.0f, 10.0f, 0.0f))))
		{
			MV1DrawModel(modelHandle);
		}
	}*/
	if (!CheckCameraViewClip(area) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight, 0.0f))) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight / 2.0f, 0.0f))))
	{
		MV1DrawModel(modelHandle);
		if (notViewCount != 0)
		{
			notViewCount = 0;
		}
	}
	else
	{
		notViewCount++;
		if (notViewCount <= 50)
		{
			MV1DrawModel(modelHandle);
		}
	}
}

void BasicObject::OptionActorDraw()
{
	if (++optionRotaCount > 360) optionRotaCount = 0;
	if (optionModelDrawCount++ > 10) MV1DrawModel(modelHandle);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, optionRotaCount * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, VGet(150.0f, -110.0f, -370.0f));
}

void BasicObject::OptionActorDrawBefore()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -650.0f), VGet(0.0f, 0.0f, 0.0f));
	optionModelDrawCount = 0;
}
