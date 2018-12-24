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
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE, THIRDLOAD, THIRDMOVE
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

	// �K�i�Ə��̐�
	extern int stairsRoadNum;

	// �K�i�Ə��̍��W
	extern std::vector<VECTOR> v_stairsRoadArea;

	// �J�����̉����]���邩�ǂ���
	extern bool cameraHorizonReturn;

	// �J�����̏c���]���邩�ǂ���
	extern bool cameraVerticalReturn;
}


/// �}�N��-------------------------------------------------------------------------------------

// �|�C���^�p����}�N��
#define POINTER_RELEASE(p) { if(p!=nullptr) {delete p; (p)=nullptr; } }

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

	void Init();

	void DebugProcess();
}
#endif // _DEBUG
