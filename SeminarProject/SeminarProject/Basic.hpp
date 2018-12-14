#pragma once

/// インクルードファイル-------------
#include "DLLXinput.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "SoundProcess.hpp"
#include <vector>


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

	// 街灯の数
	extern int streetLightNum;

	// 街灯の座標
	extern std::vector<VECTOR> v_streetLightArea;
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



// debug
#ifdef _DEBUG
namespace MyDebug
{
	bool checkFlag;
	extern bool characterDrawFlag;
	extern bool characterSwordDrawFlag;
	extern bool ordinaryDrawFlag;
	extern bool enemyOneDrawFlag;
	extern bool enemyTwoDrawFlag;
	extern bool adjustmentMachineDrawFlag;
	extern bool dropItemOneDrawFlag;
	extern bool stageDrawFlag;
	extern bool moveOneDrawFlag;

	void Init()
	{
		characterDrawFlag = false;
		characterSwordDrawFlag = false;
		ordinaryDrawFlag = false;
		enemyOneDrawFlag = false;
		enemyTwoDrawFlag = false;
		adjustmentMachineDrawFlag = false;
		dropItemOneDrawFlag = false;
		stageDrawFlag = false;
		moveOneDrawFlag = false;
	}

	void DebugProcess()
	{
		if (CheckHitKey(KEY_INPUT_Q) == 2)
		{
			checkFlag = !checkFlag;
		}

		if (checkFlag)
		{
			DrawBox(960, 0, 1920, 540, GetColor(255, 255, 255), true);

			DrawFormatString(970, 10, GetColor(0, 0, 0), "characterDrawFlag: A: %s", characterDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_A) == 2)
			{
				characterDrawFlag = !characterDrawFlag;
			}

			DrawFormatString(970, 30, GetColor(0, 0, 0), "characterSwordDrawFlag: S: %s", characterSwordDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_S) == 2)
			{
				characterSwordDrawFlag = !characterSwordDrawFlag;
			}

			DrawFormatString(970, 50, GetColor(0, 0, 0), "ordinaryDrawFlag: D: %s", ordinaryDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_D) == 2)
			{
				ordinaryDrawFlag = !ordinaryDrawFlag;
			}

			DrawFormatString(970, 70, GetColor(0, 0, 0), "enemyOneDrawFlag: F: %s", enemyOneDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_F) == 2)
			{
				enemyOneDrawFlag = !enemyOneDrawFlag;
			}

			DrawFormatString(970, 90, GetColor(0, 0, 0), "enemyTwoDrawFlag: G: %s", enemyTwoDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_G) == 2)
			{
				enemyTwoDrawFlag = !enemyTwoDrawFlag;
			}

			DrawFormatString(970, 110, GetColor(0, 0, 0), "adjustmentMachineDrawFlag: H: %s", adjustmentMachineDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_H) == 2)
			{
				adjustmentMachineDrawFlag = !adjustmentMachineDrawFlag;
			}

			DrawFormatString(970, 130, GetColor(0, 0, 0), "dropItemOneDrawFlag: J: %s", dropItemOneDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_J) == 2)
			{
				dropItemOneDrawFlag = !dropItemOneDrawFlag;
			}

			DrawFormatString(970, 150, GetColor(0, 0, 0), "stageDrawFlag: K: %s", stageDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_K) == 2)
			{
				stageDrawFlag = !stageDrawFlag;
			}

			DrawFormatString(970, 170, GetColor(0, 0, 0), "moveOneDrawFlag: L: %s", moveOneDrawFlag ? "true" : "false");
			if (CheckHitKey(KEY_INPUT_L) == 2)
			{
				moveOneDrawFlag = !moveOneDrawFlag;
			}
		}
	}
}
#endif // _DEBUG
