#pragma once

// �C���N���[�h�t�@�C��
#include "DLLXinput.h"
#include "DxLib.h"
#include <math.h>


// �F��ȏ��Ŏg�������Ȃ���
// �V�[���̓���
enum class ESceneNumber
{
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE
};

namespace BASICPARAM
{
	extern ESceneNumber e_preScene;		// ���O�̃V�[��
	extern ESceneNumber e_nowScene;		// ���̃V�[��
}


// �}�N��
// directx�֌W�ł悭�������}�N��
#define SAFE_RELEASE(p) { if(p!=NULL) { (p)->Release(); (p)=NULL; } }

// �|�C���^�p����}�N��
#define POINTER_RELEASE(p) { if(p!=NULL) {delete (p); (p)=NULL; } }

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
