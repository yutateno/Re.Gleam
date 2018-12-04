#pragma once
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "EnemyMove2.hpp"

#include <random>

/*
�I�u�W�F�N�g���W�߂�V�[��
�����󂵂ăh���b�v�A�C�e���𓾂�A������t�B�[���h�̓���̒n�_�Ŏg�p���ăI�u�W�F�N�g�𐶐�����B
*/
class MainMove2 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE { stage, characterAttack, paneru, stairs, stairsColl, streetLight, skyBox, block, drawStage };


	/// �X�e�[�W-------------------------------------
	
	// �X�e�[�W�̃|�C���^
	Stage* p_stage;

	// �K�i�̃|�C���^
	StageStairs* p_stageStairs[10];

	// �X���̃|�C���^
	StageStreetLight* p_stageStreetLight[50];

	// �p�l���̃|�C���^
	StagePaneru* p_stagePaneru[10];


	/// �L�����N�^�[----------------------

	// �L�����N�^�[�̃|�C���^
	CharacterSword* p_character;


	/// �G---------------------

	// �G�̃|�C���^
	EnemyMove2* p_enemy;


	/// �J����-----------------------
	// �J�����̃|�C���^
	Camera* p_camera;


	// �e�̕`��
	void ShadowDraw();

	// �U���̃v���Z�X
	void AttackProcess();


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
};

