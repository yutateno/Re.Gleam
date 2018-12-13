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

#include <random>

/*
�I�u�W�F�N�g���W�߂�V�[��
�����󂵂ăh���b�v�A�C�e���𓾂�A������t�B�[���h�̓���̒n�_�Ŏg�p���ăI�u�W�F�N�g�𐶐�����B
*/
class MainMove2 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE { stage, characterAttack, paneru, stairs, stairsColl, streetLight, skyBox, block, drawStage
	, charaTex0, charaTex1, charaTex2, charaTex3, charaTex4, stairTex0, streetLightTex0, streetLightTex1
	, skyBoxTex0, blockTex0, se_ballPickUp, terminal, terminalTex0, terminalTex1, terminalDescription };


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
	

	/// �L�����N�^�[----------------------

	// �L�����N�^�[�̃|�C���^
	CharacterSword* p_character;


	/// �G---------------------

	// �G�̐�
	const int enemyNum = 5;

	// �G�̃|�C���^
	EnemyMove2* p_enemy[5];

	// �h���b�v�A�C�e���i�P�̂ɑ΂��ĂT��
	DropItemMove2* p_dropItem[25];

	int dropItemSE;

	// ���̃h���b�v�A�C�e������Ɏ�������
	int catchDropItemNum;


	/// ���Z�@�B-------------

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
	enum class AdjustmentObject { Stairs, StreetLight };

	// �����@�B����I�u�W�F�N�g����
	void AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID);

	// �����@�B�̃V�[���ւ̃t�F�[�h
	int adjustmentSceneFeed;

	// �����@�B�̃t�F�[�h���I���������ǂ���
	bool adjustmentFeedNow;

	// �����@�B�̕��Ɉڂ�t�F�[�h���ǂ���
	bool adjustmentStartFeed;

	// �����@�B�Ɉڂ�Ƃ��̉摜
	int adjustmentDrawScreen;


	/// �J����-----------------------
	// �J�����̃|�C���^
	Camera* p_camera;


	// �e�̕`��
	void ShadowDraw();

	// �U���̃v���Z�X
	void AttackProcess();


	// �񓯊��e�N�X�`���؂�ւ�
	void ThsTextureReload() override;




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
	void TextureReload() override;
};

