#include "BaseMove.hpp"

bool BaseMove::endFlag;		// 終了フラッグ
ESceneNumber BaseMove::scene;	// 現在のシーン


// プレイヤーのシャドウマップへの準備
void BaseMove::ShadowCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapCharaHandle);
}


// プレイヤー以外のシャドウマップへの準備
void BaseMove::ShadowAnotherCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapAnotherCharaHandle);
}


// ステージのシャドウマップへの描画の準備
void BaseMove::ShadowNoMoveSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapNoMoveHandle);
}


// シャドウマップの終了
void BaseMove::ShadowSetUpAfter()
{
	ShadowMap_DrawEnd();
}


// プレイヤーの描画に使用するシャドウマップを設定
void BaseMove::ShadowCharaDrawBefore()
{
	SetUseShadowMap(0, shadowMapCharaHandle);
}


// プレイヤーの描画に使用するシャドウマップの設定を解除
void BaseMove::ShadowCharaDrawAfter()
{
	SetUseShadowMap(0, -1);
}


// プレイヤー以外の描画に使用するシャドウマップを設定
void BaseMove::ShadowAnotherCharaDrawBefore()
{
	SetUseShadowMap(1, shadowMapAnotherCharaHandle);
}


// プレイヤー以外の描画に使用するシャドウマップの設定を解除
void BaseMove::ShadowAnotherCharaDrawAfter()
{
	SetUseShadowMap(1, -1);
}


// ステージの描画に使用するシャドウマップを設定
void BaseMove::ShadowNoMoveDrawBefore()
{
	SetUseShadowMap(2, shadowMapNoMoveHandle);
}


// ステージの描画に使用するシャドウマップの設定を解除
void BaseMove::ShadowNoMoveDrawAfter()
{
	SetUseShadowMap(2, -1);
}


// シャドウマップの中心座標をプレイヤーに更新
void BaseMove::ShadowArea(const VECTOR charaArea)
{
	SetShadowMapDrawArea(shadowMapCharaHandle, VAdd(charaArea, shadowCharaLowArea), VAdd(charaArea, shadowCharaHighArea));
	SetShadowMapDrawArea(shadowMapAnotherCharaHandle, VAdd(charaArea, shadowAnotherCharaLowArea), VAdd(charaArea, shadowAnotherCharaHighArea));
}


// スカイボックスの描画
void BaseMove::SkyBoxDraw()
{
	// ライティングを無効にする
	SetUseLighting(FALSE);
	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);
	MV1DrawModel(skyBoxUp);
	MV1DrawModel(skyBoxUnder);
	// ライティングを有効にする
	SetUseLighting(TRUE);
	// Ｚバッファを無効にする
	SetUseZBuffer3D(FALSE);
}


// スカイボックスのプロセス
void BaseMove::SkyBoxProcess(const VECTOR characterArea)
{
	// ポジションをプレイヤー中心にする
	MV1SetPosition(skyBoxUp, characterArea);
	MV1SetPosition(skyBoxUnder, characterArea);
}


// スカイボックスの初期化
void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)
{
	/// スカイボックスの上に関する-----------------------------------------
	// モデル読み込み
	this->skyBoxUp = MV1DuplicateModel(skyBoxUp);
	

	// テクスチャ適応
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);


	// スケール変更
	MV1SetScale(this->skyBoxUp, VGet(170.0f, 170.0f, 170.0f));


	/// スカイボックスの下に関する-------------------------------------------
	// モデル読み込み
	this->skyBoxUnder = MV1DuplicateModel(this->skyBoxUp);


	// テクスチャ適応
	MV1SetTextureGraphHandle(this->skyBoxUnder, 0, textureHandle, false);


	// スケール変更
	MV1SetScale(this->skyBoxUnder, VGet(170.0f, 170.0f, 170.0f));


	// ロケーション変更
	MV1SetRotationXYZ(this->skyBoxUnder, VGet(DX_PI_F, 0.0f, 0.0f));
} /// void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)


// スカイボックスのテクスチャ差し替え
void BaseMove::SkyTextureReload()
{
	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\スカイボックス\\normal\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\スカイボックス\\D\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\スカイボックス\\P\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\スカイボックス\\normal\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);
}


// コンストラクタ
BaseMove::BaseMove()
{
	SetLightEnable(TRUE);	// 光源を有効にする


	// フォグに関する
	SetFogEnable(TRUE);					// フォグを有効にする
	SetFogColor(128, 128, 128);			// フォグの色にする
	SetFogStartEnd(3500.0f, 6000.0f);	// フォグの開始距離


	// シャドウマップハンドルの作成
	shadowMapCharaHandle = MakeShadowMap(2048, 2048);
	shadowMapAnotherCharaHandle = MakeShadowMap(512, 512);
	shadowMapNoMoveHandle = MakeShadowMap(256, 256);


	// シャドウマップに描画する範囲を設定
	shadowCharaLowArea = VGet(-500.0f, -1.0f, -500.0f);
	shadowCharaHighArea = VGet(500.0f, 10.0f, 500.0f);

	shadowAnotherCharaLowArea = VGet(-2000.0f, -1.0f, -2000.0f);
	shadowAnotherCharaHighArea = VGet(2000.0f, 100.0f, 2000.0f);

	shadowNoMoveLowArea = VGet(-2000.0f, -1.0f, -2000.0f);
	shadowNoMoveHighArea = VGet(2000.0f, 1000.0f, 2000.0f);

	SetShadowMapDrawArea(shadowMapCharaHandle, shadowCharaLowArea, shadowCharaHighArea);
	SetShadowMapDrawArea(shadowMapAnotherCharaHandle, shadowAnotherCharaLowArea, shadowAnotherCharaHighArea);
	SetShadowMapDrawArea(shadowMapNoMoveHandle, shadowNoMoveLowArea, shadowNoMoveHighArea);


	// ライトの方向を設定
	lightDire = VGet(-0.5f, -0.7f, 0.5f);
	SetLightDirection(lightDire);


	// シャドウマップが想定するライトの方向もセット
	SetShadowMapLightDirection(shadowMapCharaHandle, lightDire);
	SetShadowMapLightDirection(shadowMapAnotherCharaHandle, lightDire);
	SetShadowMapLightDirection(shadowMapNoMoveHandle, lightDire);


	// スカイボックスに関して
	skyBoxUnder = -1;
	skyBoxUp = -1;
	textureHandle = -1;
}


// デストラクタ
BaseMove::~BaseMove()
{
	// シャドウマップの削除
	SHADOW_MAP_RELEASE(shadowMapNoMoveHandle);
	SHADOW_MAP_RELEASE(shadowMapAnotherCharaHandle);
	SHADOW_MAP_RELEASE(shadowMapCharaHandle);

	// スカイボックスの削除
	MODEL_RELEASE(skyBoxUnder);
	MODEL_RELEASE(skyBoxUp);
	GRAPHIC_RELEASE(textureHandle);
}
