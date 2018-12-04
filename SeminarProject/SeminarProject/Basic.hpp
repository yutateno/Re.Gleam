#pragma once

/// インクルードファイル-------------
#include "DLLXinput.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "SoundProcess.hpp"


/// 色んな所で使いそうなもの------------------------------

// シーンの動き
enum class ESceneNumber
{
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE
};

// テクスチャの色
enum class ETextureColor
{
	NORMAL, D_CORRECTION, P_CORRECTION, WHITEBLACK
};

namespace BASICPARAM
{
	// 直前のシーン
	extern ESceneNumber e_preScene;

	// 今のシーン
	extern ESceneNumber e_nowScene;

	// 直前のテクスチャの色
	extern ETextureColor e_preTextureColor;

	// 今のテクスチャの色
	extern ETextureColor e_TextureColor;

	// 今のカメラの形式が正射影かどうか
	extern bool nowCameraOrtho;

	// ウィンドウサイズ
	extern int winWidth;
	extern int winHeight;
	extern int bitColor;
}


/// マクロ-------------------------------------------------------------------------------------

// directx関係でよくある解放マクロ
#define SAFE_RELEASE(p) { if(p!=NULL) { (p)->Release(); (p)=NULL; } }

// ポインタ用解放マクロ
#define POINTER_RELEASE(p) { if(p!=NULL) {delete p; (p)=NULL; } }

// 2D関連画像解放マクロ
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); (p)=-1; } }

// 3D関連画像解放マクロ
#define MODEL_RELEASE(p) { if(p!=-1) { MV1DeleteModel(p); (p)=-1; } }

// 音解放マクロ
#define SOUND_RELEASE(p) { if(p!=-1) { StopSoundMem(p); DeleteSoundMem(p); (p)=-1; } }

// 光源ハンドル解放マクロ
#define LIGHT_RELEASE(p) { if(p!=-1) { DeleteLightHandle(p); (p)=-1; } }

// シャドウマップ解放マクロ
#define SHADOW_MAP_RELEASE(p) { if(p!=-1) { DeleteShadowMap(p); (p)=-1; } }
