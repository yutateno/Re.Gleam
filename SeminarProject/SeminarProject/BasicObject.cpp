#include "BasicObject.hpp"
#include <typeinfo.h>



/// --------------------------------------------------------------------------------
bool BasicObject::ShadowFoot(int shadowModel)
{
	// プレイヤーの直下に存在する地面のポリゴンを取得
	ShadowHitResDim = MV1CollCheck_Capsule(shadowModel, -1, area, VAdd(area, VGet(0.0f, -shadowHeight, 0.0f)), shadowSize);


	// 頂点データで変化が無い部分をセット
	ShadowVertex[0].dif = GetColorU8(255, 255, 255, 255);
	ShadowVertex[0].spc = GetColorU8(0, 0, 0, 0);
	ShadowVertex[0].su = 0.0f;
	ShadowVertex[0].sv = 0.0f;
	ShadowVertex[1] = ShadowVertex[0];
	ShadowVertex[2] = ShadowVertex[0];


	// 球の直下に存在するポリゴンの数だけ繰り返し
	ShadowHitRes = ShadowHitResDim.Dim;
	if (ShadowHitResDim.HitNum == 0) return false;


	SetUseLighting(FALSE);	// ライティングを無効にする
	SetUseZBuffer3D(TRUE);	// Ｚバッファを有効にする


	// テクスチャアドレスモードを CLAMP にする
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);
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
	} /// for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)


	// 検出した地面ポリゴン情報の後始末
	MV1CollResultPolyDimTerminate(ShadowHitResDim);


	SetUseLighting(TRUE);	// ライティングを有効にする
	SetUseZBuffer3D(FALSE);	// Ｚバッファを無効にする
	return true;
} /// bool BasicObject::ShadowFoot(int shadowModel)



/// --------------------------------------------------------------------------------
BasicObject::BasicObject()
{
	// 情報初期化
	shadowHandle = -1;
	notViewCount = 0;
	optionRotaCount = 0;
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
	move6_circle = 0;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::BasicObject(bool shadowDo)
{
	// 影の読み込み
	shadowHandle = -1;
	LoadFile::MyLoad("media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);


	// 情報初期化
	notViewCount = 0;
	optionRotaCount = 0;
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
	move6_circle = 0;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::~BasicObject()
{
	// 影ハンドル開放
	GRAPHIC_RELEASE(shadowHandle);
}



/// --------------------------------------------------------------------------------
void BasicObject::ModelDraw()
{
	// スクリーン座標内にいたら
	if (!CheckCameraViewClip(area) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight, 0.0f)))
		&& !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight / 2.0f, 0.0f))))
	{
		// モデルを描画
		MV1DrawModel(modelHandle);


		// 見えていないカウント数を0に
		if (notViewCount != 0) notViewCount = 0;
	}
	// スクリーン座標外にいたら
	else
	{
		// 見えていないカウントが6以下だったら
		if (++notViewCount <= 6)
		{
			// モデルを描画
			MV1DrawModel(modelHandle);
		}
	}
}



/// --------------------------------------------------------------------------------
void BasicObject::OptionActorDraw()
{
	// 回転して描画させる
	if (++optionRotaCount > 360) optionRotaCount = 0;
	if (optionModelDrawCount++ > 10) MV1DrawModel(modelHandle);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, optionRotaCount * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, VGet(150.0f, -110.0f, -370.0f));
}



/// --------------------------------------------------------------------------------
void BasicObject::OptionActorDrawBefore()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -650.0f), VGet(0.0f, 0.0f, 0.0f));
	optionModelDrawCount = 0;
}



/// --------------------------------------------------------------------------------
void BasicObject::Move6SetDownArea()
{
	// 自分からボスのとこまで伸ばしている線がまだ到達していなかったら
	if (move6_line <= 200.0f)
	{
		// 黒い丸い円の半径を大きくする
		if (move6_circle <= 100.0f) move6_circle++;
		DrawCone3D(VGet(area.x, 50.0, area.z), VGet(area.x, 0, area.z), move6_circle, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);


		// 自分からボスのとこまで線を引く
		DrawLine3D(VGet(area.x, 50.0, area.z), VGet(area.x + ((4000.0f - area.x) * (move6_line / 200.0f)), 50.0f, 0.0f), GetColor(0, 0, 0));
	}
	// ボスのとこまで線が到達していたら
	else if (move6_line <= 400.0f)
	{
		// 黒い丸い円の半径を小さくしていく
		if (move6_circle >= 0.0f) move6_circle--;
		DrawCone3D(VGet(area.x, 50.0, area.z), VGet(area.x, 0, area.z), move6_circle, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);


		// 自分からボスのとこまで線を引く
		DrawLine3D(VGet(area.x, 50.0, area.z), VGet(4000.0f, 50.0f, 0.0f), GetColor(0, 0, 0));
	}
	move6_line++;


	// 沈ませる
	area.y -= 2.0f;
	MV1SetPosition(modelHandle, this->area);
} /// void BasicObject::Move6SetDownArea()
