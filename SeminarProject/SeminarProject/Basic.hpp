#pragma once

/// �C���N���[�h�t�@�C��-------------
#include "DLLXinput.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "SoundProcess.hpp"
#include <vector>


/// �F��ȏ��Ŏg�������Ȃ���------------------------------

// �V�[���̓���
enum class ESceneNumber
{
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE
};

// �e�N�X�`���̐F
enum class ETextureColor
{
	NORMAL, D_CORRECTION, P_CORRECTION, WHITEBLACK
};

namespace BASICPARAM
{
	// ���O�̃V�[��
	extern ESceneNumber e_preScene;

	// ���̃V�[��
	extern ESceneNumber e_nowScene;

	// ���O�̃e�N�X�`���̐F
	extern ETextureColor e_preTextureColor;

	// ���̃e�N�X�`���̐F
	extern ETextureColor e_TextureColor;

	// ���̃J�����̌`�������ˉe���ǂ���
	extern bool nowCameraOrtho;

	// �E�B���h�E�T�C�Y
	extern int winWidth;
	extern int winHeight;
	extern int bitColor;

	// �O�V�[���̏I���t�F�[�h���I�������ǂ���
	extern bool endFeedNow;

	// ���V�[���̊J�n�t�F�[�h���I�������ǂ���
	extern bool startFeedNow;

	// �p�l����\�����邩�ǂ���
	extern bool paneruDrawFlag;

	// �K�i�̐�
	extern int stairsNum;

	// �K�i�̍��W
	extern std::vector<VECTOR> v_stairsArea;

	// �X���̐�
	extern int streetLightNum;

	// �X���̍��W
	extern std::vector<VECTOR> v_streetLightArea;
}


/// �}�N��-------------------------------------------------------------------------------------

// directx�֌W�ł悭�������}�N��
#define SAFE_RELEASE(p) { if(p!=NULL) { (p)->Release(); (p)=NULL; } }

// �|�C���^�p����}�N��
#define POINTER_RELEASE(p) { if(p!=NULL) {delete p; (p)=NULL; } }

// 2D�֘A�摜����}�N��
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); (p)=-1; } }

// 3D�֘A�摜����}�N��
#define MODEL_RELEASE(p) { if(p!=-1) { MV1DeleteModel(p); (p)=-1; } }

// ������}�N��
#define SOUND_RELEASE(p) { if(p!=-1) { StopSoundMem(p); DeleteSoundMem(p); (p)=-1; } }

// �����n���h������}�N��
#define LIGHT_RELEASE(p) { if(p!=-1) { DeleteLightHandle(p); (p)=-1; } }

// �V���h�E�}�b�v����}�N��
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
