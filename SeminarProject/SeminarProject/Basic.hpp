#pragma once

/// インクルードファイル-------------
#include "DLLXinput.h"
#include "DxLib.h"
#include "EffekseerForDXLib.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "SoundProcess.hpp"
#include <vector>


/// 色んな所で使いそうなもの------------------------------

// シーンの動き
enum class ESceneNumber
{
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE, THIRDLOAD, THIRDMOVE
	, FORTHLOAD, FORTHMOVE
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

	// 前シーンの終了フェードを終えたかどうか
	extern bool endFeedNow;

	// 次シーンの開始フェードを終えたかどうか
	extern bool startFeedNow;

	// パネルを表示するかどうか
	extern bool paneruDrawFlag;

	// 階段の数
	extern int stairsNum;

	// 階段の座標
	extern std::vector<VECTOR> v_stairsArea;

	// 階段の角度
	extern std::vector<float> v_stairsAngle;

	// 街灯の数
	extern int streetLightNum;

	// 街灯の座標
	extern std::vector<VECTOR> v_streetLightArea;

	// 街灯の角度
	extern std::vector<float> v_streetLightAngle;

	// 階段と床の数
	extern int stairsRoadNum;

	// 階段と床の座標
	extern std::vector<VECTOR> v_stairsRoadArea;

	// 階段と床の座標
	extern std::vector<float> v_stairsRoadAngle;

	// カメラの横反転するかどうか
	extern bool cameraHorizonReturn;

	// カメラの縦反転するかどうか
	extern bool cameraVerticalReturn;
}


/// マクロ-------------------------------------------------------------------------------------

// ポインタ用解放マクロ
#define POINTER_RELEASE(p) { if(p!=nullptr) {delete p; (p)=nullptr; } }

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



// debug
#ifdef _DEBUG
namespace MyDebug
{
	static bool checkFlag;
	extern bool characterDrawFlag;
	extern bool characterSwordDrawFlag;
	extern bool ordinaryDrawFlag;
	extern bool enemyOneDrawFlag;
	extern bool enemyTwoDrawFlag;
	extern bool adjustmentMachineDrawFlag;
	extern bool dropItemOneDrawFlag;
	extern bool stageDrawFlag;
	extern bool moveOneDrawFlag;
	extern bool enemyThreeSlimeDrawFlag;
	extern bool enemyThreeCrayonHumanDrawFlag;
	extern bool enemyThreeSlimeSearchLineDrawFlag;
	extern bool enemyThreeCrayonHumanSearchLineDrawFlag;

	void Init();

	void DebugProcess();
}
#endif // _DEBUG
