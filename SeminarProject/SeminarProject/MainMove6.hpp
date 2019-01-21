#pragma once
#include "BaseMove.hpp"
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "StageStairsRoad.hpp"
#include "OrdinaryPerson.hpp"
#include "EnemyBossAfter.hpp"
#include "EnemyBossBefore.hpp"
#include "CameraMove6.hpp"


/*
���X�{�X�V�[��
�|��
*/
class MainMove6 : public BaseMove
{
private:
	// ���[�h�œn�����t�@�C��
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, bgm_Main, ordinaryModel, ordinaryTex0, approachUINear, approachUIYes
		, approachUINo, bossBeforeModel, bossBeforeTex0, bossBeforeTex1, bossBeforeTex2
		, end_Title, end_DxLib, end_Effekseer, end_Graphic, end_Program, end_Sound
		, end_Special, end_Test, end_ThanksLib, end_Youser, bgm_end
	};

	
	/// �X�e�[�W-----------------------------------------------------------------------

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


	/// �L�����N�^�[-------------------------------------------------------------------

	// �L�����N�^�[
	CharacterSword* p_character;


	/// �G----------------------------------------------------------------------------

	// �{�X�̂���
	EnemyBossBefore* p_enemyBossBefore;

	// �{�X�̖{��
	EnemyBossAfter* p_enemyBossAfter;

	// �{�X�ɋ߂Â����Ƃ��ɂ������UI
	int approachBossUIDraw[3];

	//�{�X�ɋ߂Â����Ƃ��ɂ������UI�ɂĂǂ����I��������
	bool approachUISelect;
	
	// �X�e�B�b�N�̉����|�����ǂ����𒲂ׂ�
	int adjustmentControllStick[2];


	/// ��ʐl-----------------------------------------------------------------------

	// ��ʐl�̃|�C���^
	std::vector<OrdinaryPerson*> vp_ordinaryPerson;


	/// �J����----------------------------------------------------------------------

	// �J�����̃|�C���^
	Camera* p_camera;

	// ���[�r�[���̃J����
	CameraMove6* p_cameraMove;


	/// �e--------------------------------------------------------------------------
	
	// �e�̕`��
	void ShadowDraw();


	/// �U���y�т����蔻��---------------------------------------------------------

	// �U���̃v���Z�X
	void AttackProcess();


	/// �V�[�����ł̎�蕪��------------------------------------------------------

	// �V�[����ID����
	enum class ESceneMove6 { First, Movie, Battle, Last };
	ESceneMove6 e_nowMove;

	/// �ŏ��̃V�[��-------------------------------------------------

	// �ŏ��̕`��
	void FirstDraw();

	// �ŏ��̃v���Z�X
	void FirstProcess();

	/// ���[�r�[���̃V�[��-----------------------------------------

	// ���[�r�[���̕`��
	void MovieDraw();

	// ���[�r�[���̃v���Z�X
	void MovieProcess();

	// ���[�r�[���̓������܂Ƃ߂鎞�ԃt���[��
	int movieFrame;

	// ���[�r�[�O�����ˉe�J�������������ǂ���
	bool movieBeforeCameraOrtho;

	/// �퓬�̃V�[��-----------------------------------------------

	// �퓬�̕`��
	void BattleDraw();

	// �퓬�̃v���Z�X
	void BattleProcess();

	/// �Ō�̃V�[��----------------------------------------------

	// �Ō�̕`��
	void LastDraw();

	// �Ō�̃v���Z�X
	void LastProcess();

	// �G���h���[���p�摜
	enum class EEndRolUI {
		title, program, graphic, sound
		, libThanks, dxlib, effekseer, specialThanks, test, youser
	};
	int endrolDraw[10];


	/// �����l-----------------------------------------------------

	std::random_device rnd;


public:
	// �R���X�g���N�^
	MainMove6(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove6();


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
