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

#include <random>


/*
����������߂��V�[��
�q����ǂ������܂킷
*/
class MainMove5 : public BaseMove
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
		, bgm_Main
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
	int charaSonmeEnemyDamageCount;


	/// �G---------------------


	/// �����@�B------------------------------

	// �����@�B�̃|�C���^
	AdjustmentMachine* p_adjustmentMachine;

	// �����@�B�̐����⏕�摜
	int adjustmentDescDraw;


	/// �J����------------------

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
	MainMove5(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove5();

	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;

	// �J�����̃v���Z�X
	void CameraProcess() override;

	// �e�N�X�`���̐؂�ւ�
	void TextureReload() override;

	// �I�v�V������ʂł̃��f���\��
	void OptionActorModel() override;

	// �I�v�V������ʂł̃��f���\���̏���
	void OptionActorModelBefore() override;
};
