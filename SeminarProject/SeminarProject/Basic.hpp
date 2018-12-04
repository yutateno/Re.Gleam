#pragma once

/// �C���N���[�h�t�@�C��-------------
#include "DLLXinput.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "SoundProcess.hpp"


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
