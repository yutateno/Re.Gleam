#pragma once
#include "BaseMove.hpp"
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "AdjustmentMachine.hpp"
#include "StageStairsRoad.hpp"
#include "EnemyMove3Slime.hpp"
#include "EnemyMove3CrayonHuman.hpp"
#include "DropItemMove3.hpp"

#include <random>


/*
�F���W�߂�V�[��
�G��|���ĐF�����߂�
*/
class MainMove3 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, se_ballPickUp, terminalModel, terminalTex0, terminalTex1
		, terminalDesc, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, se_ballPickUp2, bgm_Main, slimeModel, slimeTex0, crayonHumanModel
		, crayonHumanTex0, dropItemModel, dropItemTex0
		, damageDraw0, damageDraw1, damageDraw2, damageBlood0, damageBlood1
		, damageBlood2, damageBlood3, damageBlood4, damageBlood5, damageBlood6
		, damageBlood7, damageBlood8, damageBlood9, enemyAttackSE, crayonDeadSE
		, fightBGM
	};


	/// �X�e�[�W-----------------------------------------

	// �X�e�[�W�̃|�C���^
	Stage* p_stage;

	// �K�i�̃|�C���^
	std::vector<StageStairs*> vp_stageStairs;

	// �X���̃|�C���^
	std::vector<StageStreetLight*> vp_stageStreetLight;

	// �p�l���̃|�C���^
	StagePaneru* p_stagePaneru[10];

	// �K�i�Ə��̃|�C���^
	std::vector<StageStairsRoad*> vp_stageStairsRoad;


	/// �L�����N�^�[-------------------

	// �L�����N�^�[�̃|�C���^
	CharacterSword* p_character;

	// �����̓G�Ƀ_���[�W�󂯂����ɑ�\��̂̂ݎ󂯂�悤�ɂ���J�E���g
	int charaSomeEnemyDamageCount;

	// �_���[�W���l
	int damageCount;

	// ���O�̃_���[�W�J�E���g
	int preDamageCount;

	// �_���[�W�̃u�����h���l
	int damageBlend[10];

	// �_���[�W�\���摜
	int damageDraw[3];

	// �_���[�W���󂯂Ă��Ȃ��J�E���g
	int notDamageCount;

	// �_���[�W�\���摜�̃t���[��
	int damageDrawFrame;

	// �_���[�W�摜��ID
	int damageDrawID;

	// �_���[�W�摜�̐F�o�����ւ�
	void DamageTextureReload();


	/// �G---------------------

	// �X���C���̃|�C���^
	EnemyMove3Slime* p_enemySlime[10];

	// �X���C���̃_���[�W�u��
	bool enemySlimeDamage[10];

	// �X���C���̐�
	const int enemySlimeNum = 10;

	// �N�������q���[�}���̃|�C���^
	EnemyMove3CrayonHuman* p_enemyCrayonHuman[10];

	// �X���C���̃_���[�W�u��
	bool enemyCrayonHumanDamage[10];

	// �N�������q���[�}���̐�
	const int enemyCrayonHumanNum = 10;

	// �h���b�v�A�C�e���̐�
	const int dropItemNum = 100;

	// �h���b�v�A�C�e��
	DropItemMove3* p_dropItem[100];

	// ���̃h���b�v�A�C�e������Ɏ�������
	int catchDropItemNum;

	// ��ԃv���C���[�ɋ߂��G�̋���
	int mostNearEnemyDistance;

	// ��ԃv���C���[�ɋ߂��G�̃X�N���[�����W
	VECTOR mostNearEnemyScreenArea;

	// ���b�N�I�����Ă���G��ID
	int lockONNowEnemyID;

	// ���b�N�I�����Ă���G���X���C�����ǂ���
	bool lockOnEnemySlime;


	/// �����@�B------------------------------

	// �����@�B�̃|�C���^
	AdjustmentMachine* p_adjustmentMachine;

	// �����@�B�̐����⏕�摜
	int adjustmentDescDraw;

	// �����@�B�̃V�[���Ɉڍs
	bool changeAdjustmentScene;

	// �����@�B�̃v���Z�X
	void AdjustmentProcess();

	// �����@�B�̕`��
	void AdjustmentDraw();

	// �����@�B�̃V�[���ւ̃t�F�[�h
	int adjustmentSceneFeed;

	// �����@�B�̃t�F�[�h���I���������ǂ���
	bool adjustmentFeedNow;

	// �����@�B�̕��Ɉڂ�t�F�[�h���ǂ���
	bool adjustmentStartFeed;


	/// �J����------------------

	// �J�����̃|�C���^
	Camera* p_camera;


	// �e�̕`��
	void ShadowDraw();

	// �U���̃v���Z�X
	void AttackProcess();


	/// �G�t�F�N�g�Ɋւ���
	
	int effeckBack[10];		// �_���[�W���o��10���
	int playingEfDamage;		// �_���[�W���o�p
	int effectAttack;
	int playingEfAttack;

	
	// BGM�̐؂�ւ����s��ꂽ���ǂ���
	bool nowBattleBGM;


public:
	// �R���X�g���N�^
	MainMove3(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove3();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;


	// �J�����̃v���Z�X
	void CameraProcess() override;

	// �e�N�X�`���̐؂�ւ�
	void TextureReload() override;

	// �񓯊��e�N�X�`���؂�ւ�
	void ThsTextureReload() override;

	// �I�v�V������ʂł̃��f���\��
	void OptionActorModel() override;

	// �I�v�V������ʂł̃��f���\���̏���
	void OptionActorModelBefore() override;

	// �I�v�V������ʂł̃��f���\���̌�n��
	void OptionActorModelAfter() override;
};
