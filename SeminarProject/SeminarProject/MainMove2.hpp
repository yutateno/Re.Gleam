#pragma once
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "EnemyMove2.hpp"
#include "DropItemMove2.hpp"
#include "AdjustmentMachine.hpp"
#include "StageStairsRoad.hpp"

#include <random>

/*
�I�u�W�F�N�g���W�߂�V�[��
�����󂵂ăh���b�v�A�C�e���𓾂�A������t�B�[���h�̓���̒n�_�Ŏg�p���ăI�u�W�F�N�g�𐶐�����B
*/
class MainMove2 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE {
		stage, characterAttack, paneru, stairs, stairsColl, streetLight, skyBox, block, drawStage
		, charaTex0, charaTex1, charaTex2, charaTex3, charaTex4, stairTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, blockTex0, se_ballPickUp, terminal, terminalTex0, terminalTex1, terminalDescription
		, stairsRoad, stairsRoadTex0, stairsRoadTex1, stairsRoadColl
		, block2D, character2D, streetLight2D, stairs2D, terminal2D, stairsRoad2D
		, jump3DSE, footCorridor3DSE, foot3DSE, landing3DSE, landingSecond3DSE
		, charaAttackOne3DSE, charaAttackTwo3DSE, charaAttackThree3DSE
		, se_ballPickUp2, nextStageBGM, attackUI, jumpUI, fastSpeedUI, optionUI
	};


	/// �X�e�[�W-------------------------------------
	
	// �X�e�[�W�̃|�C���^
	Stage* p_stage;

	// �K�i�̃n���h��
	int stairsHandle;
	
	// �K�i�̃e�N�X�`��
	int stairsTexture0;

	// �K�i�̃|�C���^
	std::vector<StageStairs*> vp_stageStairs;

	// �X���̃n���h��
	int streetLightHandle;

	// �X���̃e�N�X�`��
	int streetLightTexture0;
	int streetLightTexture1;

	// �X���̃|�C���^
	std::vector<StageStreetLight*> vp_stageStreetLight;

	// �p�l���̃|�C���^
	StagePaneru* p_stagePaneru[10];

	// �K�i�Ə��̃n���h��
	int stairsRoadHandle;

	// �K�i�Ə��̃e�N�X�`��
	int stairsRoadTexture0;
	int stairsRoadTexture1;

	// �K�i�Ə��̃|�C���^
	std::vector<StageStairsRoad*> vp_stageStairsRoad;
	

	/// �L�����N�^�[----------------------

	// �L�����N�^�[�̃|�C���^
	CharacterSword* p_character;

	// ����̐����摜
	enum class EOPERATION_UI { attack, jump, fastSpeed, option };
	int operationUIDraw[4];
	int operationUIFeed[4];
	int nextOperationUIFeed[4];
	bool opeFastOptionEnd;


	/// �G---------------------

	// �G�̐�
	const int enemyNum = 50;

	// �G�̃|�C���^
	EnemyMove2* p_enemy[50];

	// �h���b�v�A�C�e���i�P�̂ɑ΂��ĂT��
	DropItemMove2* p_dropItem[250];

	int dropItemSE;

	// ���̃h���b�v�A�C�e������Ɏ�������
	int catchDropItemNum;

	// ��ԃL�����N�^�[�ɋ߂��G
	int mostNearEnemyDistance;
	VECTOR mostNearEnemyScreenArea;
	int lockONNowEnemyID;


	/// ���Z�@�B-----------------------------------------------------------------------

	// ���Z�@�B�̃|�C���^
	AdjustmentMachine* p_adjustmentMachine;

	// �����@�B�̃V�[���Ɉڍs
	bool changeAdjustmentScene;

	// �����@�B�̕⏕�����摜
	int adjustmentDescriptionDraw;

	// �����@�B�̃v���Z�X
	void AdjustmentProcess();

	// �����@�B�̕`��
	void AdjustmentDraw();

	// �����@�B����I�u�W�F�N�g��������ID
	enum class AdjustmentObject { Stairs, StairsRoad, StreetLight};

	// �����@�B����I�u�W�F�N�g����
	void AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction);

	// �����@�B�̃V�[���ւ̃t�F�[�h
	int adjustmentSceneFeed;

	// �����@�B�̃t�F�[�h���I���������ǂ���
	bool adjustmentFeedNow;

	// �����@�B�̕��Ɉڂ�t�F�[�h���ǂ���
	bool adjustmentStartFeed;

	// �����@�B�Ɉڂ�Ƃ��̉摜
	int adjustmentDrawScreen;

	// �����@�B���ɉf��2D�̉摜
	int adjustment2DDraw[6];

	// �����@�B�ɂĔz�u����I�u�W�F�N�g�����肵�����ǂ���
	bool adjustmentSelectObject;

	// �ǂ̃I�u�W�F�N�g��z�u���邩�ǂ���
	AdjustmentObject adjustmentSelectObjectNumber;

	// �z�u����I�u�W�F�N�g�̍��W
	VECTOR adjustmentArrangementArea;

	// �z�u����I�u�W�F�N�g�̌���
	float adjustmentArrangementDire;

	// �X�e�B�b�N�̉����|�����ǂ����𒲂ׂ�(DLLXinput�ł��ׂ��Ȃ񂾂낤���Ƃ肠����
	int adjustmentControllStick[2];
	/// -------------------------------------------------------------------------------


	/// �J����-----------------------
	
	// �J�����̃|�C���^
	Camera* p_camera;


	// �e�̕`��
	void ShadowDraw();

	// �U���̃v���Z�X
	void AttackProcess();


	// �񓯊��e�N�X�`���؂�ւ�
	void ThsTextureReload() override {};


	/// Effekseer�֘A-----------------------
	int effectAttack;
	int playingEfAttack;


	// BGM�̉��ʕύX����x�����ĂԂ悤��
	int bgmOnceVolumeChange;


public:
	// �R���X�g���N�^
	MainMove2(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove2();

	
	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;

	// �J�����̃v���Z�X
	void CameraProcess() override;

	// �e�N�X�`���̐؂�ւ�
	void TextureReload() override {}

	// �I�v�V������ʂł̃��f���\��
	void OptionActorModel() override;

	// �I�v�V������ʂł̃��f���\���̏���
	void OptionActorModelBefore() override;

	// �I�v�V������ʂł̃��f���\���̌�n��
	void OptionActorModelAfter() override;
};

