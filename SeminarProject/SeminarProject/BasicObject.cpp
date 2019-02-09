#include "BasicObject.hpp"
#include <typeinfo.h>



/// --------------------------------------------------------------------------------
bool BasicObject::ShadowFoot(int shadowModel)
{
	// プレイヤーの直下に存在する地面のポリゴンを取得
	shadowHitResDim = MV1CollCheck_Capsule(shadowModel, -1, area, VAdd(area, VGet(0.0f, -shadowHeight, 0.0f)), shadowSize);


	// 頂点データで変化が無い部分をセット
	shadowVertex[0].dif = GetColorU8(255, 255, 255, 255);
	shadowVertex[0].spc = GetColorU8(0, 0, 0, 0);
	shadowVertex[0].su = 0.0f;
	shadowVertex[0].sv = 0.0f;
	shadowVertex[1] = shadowVertex[0];
	shadowVertex[2] = shadowVertex[0];


	// 球の直下に存在するポリゴンの数だけ繰り返し
	shadowHitRes = shadowHitResDim.Dim;
	if (shadowHitResDim.HitNum == 0) return false;


	SetUseLighting(FALSE);	// ライティングを無効にする
	SetUseZBuffer3D(TRUE);	// Ｚバッファを有効にする


	// テクスチャアドレスモードを CLAMP にする
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);
	for (int i = 0; i != shadowHitResDim.HitNum; ++i, ++shadowHitRes)
	{
		// ポリゴンの座標は地面ポリゴンの座標
		shadowVertex[0].pos = shadowHitRes->Position[0];
		shadowVertex[1].pos = shadowHitRes->Position[1];
		shadowVertex[2].pos = shadowHitRes->Position[2];


		// ちょっと持ち上げて重ならないようにする
		shadowSlideVec = VScale(shadowHitRes->Normal, 0.5f);
		shadowVertex[0].pos = VAdd(shadowVertex[0].pos, shadowSlideVec);
		shadowVertex[1].pos = VAdd(shadowVertex[1].pos, shadowSlideVec);
		shadowVertex[2].pos = VAdd(shadowVertex[2].pos, shadowSlideVec);


		// ポリゴンの不透明度を設定する
		shadowVertex[0].dif.a = 0;
		shadowVertex[1].dif.a = 0;
		shadowVertex[2].dif.a = 0;
		if (shadowHitRes->Position[0].y > area.y - shadowHeight)
		{
			shadowVertex[0].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[0].y - area.y) / shadowHeight));
		}

		if (shadowHitRes->Position[1].y > area.y - shadowHeight)
		{
			shadowVertex[1].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[1].y - area.y) / shadowHeight));
		}

		if (shadowHitRes->Position[2].y > area.y - shadowHeight)
		{
			shadowVertex[2].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[2].y - area.y) / shadowHeight));
		}


		// ＵＶ値は地面ポリゴンとプレイヤーの相対座標から割り出す
		shadowVertex[0].u = (shadowHitRes->Position[0].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[0].v = (shadowHitRes->Position[0].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[1].u = (shadowHitRes->Position[1].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[1].v = (shadowHitRes->Position[1].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[2].u = (shadowHitRes->Position[2].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[2].v = (shadowHitRes->Position[2].z - area.z) / (shadowSize * 2.0f) + 0.5f;


		// 影ポリゴンを描画
		DrawPolygon3D(shadowVertex, 1, shadowHandle, TRUE);
	} /// for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)


	// 検出した地面ポリゴン情報の後始末
	MV1CollResultPolyDimTerminate(shadowHitResDim);


	SetUseLighting(TRUE);	// ライティングを有効にする
	SetUseZBuffer3D(FALSE);	// Ｚバッファを無効にする
	return true;
} /// bool BasicObject::ShadowFoot(int shadowModel)



/// --------------------------------------------------------------------------------
BasicObject::BasicObject()
{
	// 情報初期化
	modelHandle = -1;
	modelHeight = 0.0f;
	modelWidth = 0.0f;
	notViewCount = 0;
	shadowHeight = 0.0f;
	shadowSize = 0.0f;
	area = VGet(0.0f, 0.0f, 0.0f);
	shadowHitRes = nullptr;
	ZeroMemory(shadowVertex, sizeof(shadowVertex));
	shadowSlideVec = VGet(0.0f, 0.0f, 0.0f);
	shadowHandle = -1;
	move6_circle = 0.0f;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::BasicObject(bool shadowDo)
{
	// 影の読み込み
	shadowHandle = -1;
	if (shadowDo)
	{
		LoadFile::MyLoad("media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);
	}


	// 情報初期化
	modelHandle = -1;
	modelHeight = 0.0f;
	modelWidth = 0.0f;
	notViewCount = 0;
	shadowHeight = 0.0f;
	shadowSize = 0.0f;
	area = VGet(0, 0, 0);
	shadowHitRes = nullptr;
	ZeroMemory(shadowVertex, sizeof(shadowVertex));
	shadowSlideVec = VGet(0.0f, 0.0f, 0.0f);
	move6_circle = 0.0f;
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
