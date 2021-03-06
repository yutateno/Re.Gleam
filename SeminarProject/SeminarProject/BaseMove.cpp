#include "BaseMove.hpp"


bool BaseMove::endFlag;			// 終了フラッグ
ESceneNumber BaseMove::scene;	// 現在のシーン


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapCharaHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowAnotherCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapAnotherCharaHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowNoMoveSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapNoMoveHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowSetUpAfter()
{
	ShadowMap_DrawEnd();
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowCharaDrawBefore()
{
	SetUseShadowMap(0, shadowMapCharaHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowCharaDrawAfter()
{
	SetUseShadowMap(0, -1);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowAnotherCharaDrawBefore()
{
	SetUseShadowMap(1, shadowMapAnotherCharaHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowAnotherCharaDrawAfter()
{
	SetUseShadowMap(1, -1);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowNoMoveDrawBefore()
{
	SetUseShadowMap(2, shadowMapNoMoveHandle);
}


/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowNoMoveDrawAfter()
{
	SetUseShadowMap(2, -1);
}



/// ---------------------------------------------------------------------------------------------
void BaseMove::ShadowArea(const VECTOR charaArea)
{
	SetShadowMapDrawArea(shadowMapCharaHandle, VAdd(charaArea, shadowCharaLowArea), VAdd(charaArea, shadowCharaHighArea));
	SetShadowMapDrawArea(shadowMapAnotherCharaHandle, VAdd(charaArea, shadowAnotherCharaLowArea), VAdd(charaArea, shadowAnotherCharaHighArea));
}



/// ---------------------------------------------------------------------------------------------
void BaseMove::SkyBoxDraw()
{
	SetUseLighting(FALSE);
	SetUseZBuffer3D(TRUE);
	MV1DrawModel(skyBoxUp);
	MV1DrawModel(skyBoxUnder);
	SetUseLighting(TRUE);
	SetUseZBuffer3D(FALSE);
}



/// ---------------------------------------------------------------------------------------------
void BaseMove::SkyBoxProcess(const VECTOR characterArea)
{
	// ポジションをプレイヤー中心にする
	MV1SetPosition(skyBoxUp, characterArea);
	MV1SetPosition(skyBoxUnder, characterArea);
}



/// ---------------------------------------------------------------------------------------------
void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)
{
	/// スカイボックスの上に関する-----------------------------------------
	// モデル読み込み
	this->skyBoxUp = MV1DuplicateModel(skyBoxUp);
	

	// テクスチャ適応
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);


	MV1SetScale(this->skyBoxUp, VGet(170.0f, 170.0f, 170.0f));


	/// スカイボックスの下に関する-------------------------------------------
	// モデル読み込み
	this->skyBoxUnder = MV1DuplicateModel(this->skyBoxUp);


	// テクスチャ適応
	MV1SetTextureGraphHandle(this->skyBoxUnder, 0, textureHandle, false);


	MV1SetScale(this->skyBoxUnder, VGet(170.0f, 170.0f, 170.0f));
	MV1SetRotationXYZ(this->skyBoxUnder, VGet(DX_PI_F, 0.0f, 0.0f));
} /// void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)



/// ---------------------------------------------------------------------------------------------
void BaseMove::SkyTextureReload()
{
	GRAPHIC_RELEASE(textureHandle);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\skyBox\\whiteblack.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\skyBox\\normal.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\skyBox\\D.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\skyBox\\P.byn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\skyBox\\normal.byn", textureHandle, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);
}



/// ---------------------------------------------------------------------------------------------
BaseMove::BaseMove()
{
	SetLightEnable(TRUE);	// 光源を有効にする


	// フォグに関する
	SetFogEnable(TRUE);					// フォグを有効にする
	SetFogColor(128, 128, 128);			// フォグの色にする
	SetFogStartEnd(3000.0f, 4000.0f);	// フォグの開始距離


	// シャドウマップハンドルの作成
	shadowMapCharaHandle = MakeShadowMap(512, 512);
	shadowMapAnotherCharaHandle = MakeShadowMap(512, 512);
	shadowMapNoMoveHandle = MakeShadowMap(1, 1);


	// シャドウマップに描画する範囲を設定
	shadowCharaLowArea = VGet(-400.0f, -0.5f, -400.0f);
	shadowCharaHighArea = VGet(400.0f, 0.5f, 400.0f);

	shadowAnotherCharaLowArea = VGet(-2000.0f, -0.5f, -2000.0f);
	shadowAnotherCharaHighArea = VGet(2000.0f, 0.5f, 2000.0f);

	shadowNoMoveLowArea = VGet(-0.5f, -0.5f, -0.5f);
	shadowNoMoveHighArea = VGet(0.5f, 0.5f, 0.5f);

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


	// 説明画像
	moveDescriptionDraw = -1;
}



/// ---------------------------------------------------------------------------------------------
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
