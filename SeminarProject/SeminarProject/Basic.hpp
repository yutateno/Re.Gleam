#pragma once

/*
��{
*/

/// �C���N���[�h�t�@�C��--------------------------------------------------------
#include "DLLXinput.h"
#include "EffekseerForDXLib.h"
#include "SoundProcess.hpp"
#include <vector>


/// �F��ȏ��Ŏg�������Ȃ���----------------------------------------------------

// �V�[���̓���
enum class ESceneNumber
{
	FIRSTLOAD, FIRSTMOVE, SECONDLOAD, SECONDMOVE, THIRDLOAD, THIRDMOVE
	, FOURTHLOAD, FOURTHMOVE, FIFTHLOAD, FIFTHMOVE, SIXLOAD, SIXMOVE
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

	// ���V�[���̊J�n�t�F�[�h���I���ĂȂ����ǂ���
	extern bool startFeedNow;


	// �p�l����\�����邩�ǂ���
	extern bool paneruDrawFlag;


	// �K�i�̐�
	extern int stairsNum;

	// �K�i�̍��W
	extern std::vector<VECTOR> v_stairsArea;

	// �K�i�̊p�x
	extern std::vector<float> v_stairsAngle;


	// �X���̐�
	extern int streetLightNum;

	// �X���̍��W
	extern std::vector<VECTOR> v_streetLightArea;

	// �X���̊p�x
	extern std::vector<float> v_streetLightAngle;


	// �K�i�Ə��̐�
	extern int stairsRoadNum;

	// �K�i�Ə��̍��W
	extern std::vector<VECTOR> v_stairsRoadArea;

	// �K�i�Ə��̍��W
	extern std::vector<float> v_stairsRoadAngle;


	// �J�����̉����]���邩�ǂ���
	extern bool cameraHorizonReturn;

	// �J�����̏c���]���邩�ǂ���
	extern bool cameraVerticalReturn;


	// �L�����N�^�[�̃e�N�X�`�����������ǂ���
	extern bool charaTextureWhiteBlack;

	// �G�̃e�N�X�`�����������ǂ���
	extern bool enemyTextureWhiteBlack;

	// �K�i�̃e�N�X�`�����������ǂ���
	extern bool stairsTextureWhiteBlack;

	// �K�i�Ə��̃e�N�X�`�����������ǂ���
	extern bool stairsRoadTextureWhiteBlack;

	// �X���̃e�N�X�`�����������ǂ���
	extern bool lightStreetTextureWhiteBlack;

	// ���̑��̃e�N�X�`�����������ǂ���
	extern bool anothreTextureWhiteBlack;


	// ��ʐl�̐l��
	extern int ordinaryPeopleNum;


	// ���[�u5�ɂăL������`�悷��悤�ɂ������ǂ���
	extern bool lastCharaView;

	// ���[�u5�ɂĊX����`�悷��悤�ɂ������ǂ���
	extern bool lastStreetLightView;

	// ���[�u5�ɂĊK�i��`�悷��悤�ɂ������ǂ���
	extern bool lastStairsView;

	// ���[�u5�ɂĊK�i�Ə���`�悷��悤�ɂ������ǂ���
	extern bool lastStairsRoadView;

	// ���[�u5�ɂăp�l����`�悷��悤�ɂ������ǂ���
	extern bool lastPaneruView;

	// ���[�u5�ɂĈ�ʐl��`�悷��悤�ɂ������ǂ���
	extern bool lastOrdinaryView;
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
	extern bool enemyThreeSlimeDrawFlag;
	extern bool enemyThreeCrayonHumanDrawFlag;
	extern bool enemyThreeSlimeSearchLineDrawFlag;
	extern bool enemyThreeCrayonHumanSearchLineDrawFlag;
	extern bool enemyFourEnemyDrawFlag;
	extern bool enemyFourEnemySearchLineDrawFlag;
	extern bool enemyFifthEnemyDrawFlag;
	extern bool enemyFifthEnemySearchLineDrawFlag;
	extern bool enemyLastBossDrawFlag;
	extern bool enemyLastBossAttackFlameDrawFlag;

	void Init();

	void DebugProcess();
}
#endif // _DEBUG
