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
#include "OrdinaryPerson.hpp"
#include "EnemyMove4.hpp"
#include "EnemyBossBefore.hpp"

#include <random>


/*
�l���W�߂�V�[��
�G��|���Č��ʂ�ɖ߂�
*/
class MainMove4 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, terminalModel, terminalTex0, terminalTex1, terminalDesc
		, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, bgm_Main, ordiPersonModel, ordiPersonTex0, enemyModel, enemyTex0
		, bgm_battle, moveDescription, damageDraw0, damageDraw1, damageDraw2
		, damageBlood0, damageBlood1, damageBlood2, damageBlood3, damageBlood4
		, damageBlood5, damageBlood6, damageBlood7, damageBlood8, damageBlood9
		, se_enemyDamage
	};


	/// �X�e�[�W-------------------------------------------------------------------------

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


	/// �L�����N�^�[--------------------------------------------------------------------

	// �L�����N�^�[�̃|�C���^
	CharacterSword* p_character;

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


	/// �l------------------------------------------------------------------------------

	// �l�̃|�C���^
	OrdinaryPerson* p_ordinaryPerson[50];

	// �l�̐�
	const int ordinaryNum = 50;


	/// �G-----------------------------------------------------------------------------

	// �{�X�̂���
	EnemyBossBefore* p_enemyBossBefore;

	// �G�̃|�C���^
	EnemyMove4* p_enemyMove;

	// �G���_���[�W�󂯂Ă��邩�ǂ���
	bool enemyDamage;

	// �G�ƃv���C���[�̋���
	int enemyAndPlayerDistance;

	// �G�̃X�N���[�����W
	VECTOR enemyScreenArea;


	/// �����@�B-----------------------------------------------------------------------

	// �����@�B�̃|�C���^
	AdjustmentMachine* p_adjustmentMachine;

	// �����@�B�̐����⏕�摜
	int adjustmentDescDraw;


	/// �J����-------------------------------------------------------------------------

	// �J�����̃|�C���^
	Camera* p_camera;


	/// ���[�u���̓����Ɋւ���--------------------------------------------------------

	// �e�̕`��
	void ShadowDraw();

	// �U���̃v���Z�X
	void AttackProcess();


	/// ���Ɋւ���-------------------------------------------------------------------

	// BGM�̐؂�ւ����s��ꂽ���ǂ���
	bool nowBattleBGM;


	/// �G�t�F�N�g�Ɋւ���----------------------------------------------------------

	int effeckBack[10];		// �_���[�W���o��10���
	int playingEfDamage;		// �_���[�W���o�p
	int effectAttack;
	int playingEfAttack;


public:
	// �R���X�g���N�^
	MainMove4(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove4();


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
