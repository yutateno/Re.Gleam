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
�f�t�H���g�V�[���N���X�A��{�����̃R�s�y�p
*/
class DefaultMove : public BaseMove
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
	DefaultMove(const std::vector<int> v_file);

	// �f�X�g���N�^
	~DefaultMove();

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


///// ���[�u4�̃��[�h�f��-------------------------------------------------
//	// ���f���f�[�^
//move4str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
//move4str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
//move4str[2] = "media\\������\\media\\paneru\\paneru.myn";
//move4str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
//move4str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
//move4str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
//move4str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
//move4str[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
//
//// �L�����̃e�N�X�`���f�[�^
//move4str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
//move4str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
//move4str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
//move4str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
//move4str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";
//
//// �K�i�̃e�N�X�`���f�[�^
//move4str[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";
//
//// �X���̃e�N�X�`���f�[�^
//move4str[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
//move4str[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";
//
//// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
//move4str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";
//
//// ���Z�@�B�f�[�^
//move4str[17] = "media\\������\\media\\Terminal\\terminal.myn";					// 2
//
//// ���Z�@�B�e�N�X�`��
//move4str[18] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
//move4str[19] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";
//
//// �����@�B�̕⏕����
//move4str[20] = "media\\������\\media\\Terminal\\push.pyn";
//
//// �K�i�Ƃ��̂��Ƃ̏��f�[�^
//move4str[21] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2
//
//// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
//move4str[22] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
//move4str[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";
//
//// �K�i�Ə��̂����蔻��f�[�^
//move4str[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";
//
//// �L�����N�^�[�����3DSE
//move4str[25] = "media\\������\\media\\sound\\�W�����v.wyn";
//move4str[26] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
//move4str[27] = "media\\������\\media\\sound\\����.wyn";
//move4str[28] = "media\\������\\media\\sound\\���n.wyn";
//move4str[29] = "media\\������\\media\\sound\\���n�Q.wyn";
//
//// �L�����N�^�[�̍U���̉�
//move4str[30] = "media\\������\\media\\sound\\piano�U����1.wyn";
//move4str[31] = "media\\������\\media\\sound\\piano�U����2.wyn";
//move4str[32] = "media\\������\\media\\sound\\piano�U����3.wyn";
//
//// BGM
//move4str[33] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";
//
//load4[0] = ELOADFILE::mv1model;
//load4[1] = ELOADFILE::mv1model;
//load4[2] = ELOADFILE::mv1model;
//load4[3] = ELOADFILE::mv1model;
//load4[4] = ELOADFILE::mv1model;
//load4[5] = ELOADFILE::mv1model;
//load4[6] = ELOADFILE::mv1model;
//load4[7] = ELOADFILE::mv1model;
//
//load4[8] = ELOADFILE::graph;
//load4[9] = ELOADFILE::graph;
//load4[10] = ELOADFILE::graph;
//load4[11] = ELOADFILE::graph;
//load4[12] = ELOADFILE::graph;
//
//load4[13] = ELOADFILE::graph;
//
//load4[14] = ELOADFILE::graph;
//load4[15] = ELOADFILE::graph;
//
//load4[16] = ELOADFILE::graph;
//
//load4[17] = ELOADFILE::mv1model;
//
//load4[18] = ELOADFILE::graph;
//load4[19] = ELOADFILE::graph;
//
//load4[20] = ELOADFILE::graph;
//
//load4[21] = ELOADFILE::mv1model;
//
//load4[22] = ELOADFILE::graph;
//load4[23] = ELOADFILE::graph;
//
//load4[24] = ELOADFILE::mv1model;
//
//load4[25] = ELOADFILE::sound3DSource;
//load4[26] = ELOADFILE::sound3DSource;
//load4[27] = ELOADFILE::sound3DSource;
//load4[28] = ELOADFILE::sound3DSource;
//load4[29] = ELOADFILE::sound3DSource;
//
//load4[30] = ELOADFILE::sound3DSource;
//load4[31] = ELOADFILE::sound3DSource;
//load4[32] = ELOADFILE::sound3DSource;
//
//load4[33] = ELOADFILE::soundStream;
///// --------------------------------------------------------------------