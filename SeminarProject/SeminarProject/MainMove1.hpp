#pragma once
#include "Stage.hpp"
#include "Character.hpp"
#include "EnemyMove1.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "DropItemMove1.hpp"

#include <random>


/*
�����W�߂�V�[��
�����Ă���ʂ��W�߂Č�����ɓ����
*/
class MainMove1 : public BaseMove
{
private:
	// ���[�h����n�����t�@�C���̏���
	enum EFILE {
		drawStage, collStage, character, sword, sound, seBallHigh, seBall
		, charaTex0, charaTex1, charaTex2, charaTex3, swordTex0
		, explanationLeftStick, explanationRightStick, moveDescription
	};


	/// �X�e�[�W--------------
	
	// �X�e�[�W�̃|�C���^
	Stage* p_stage;

	// �w�i�F
	int backgroundColor;


	/// �L�����N�^�[-----------------

	// �L�����N�^�[�̃|�C���^
	Character* p_character;

	// �G����ɓ��ꂽ��
	int catchEnemyNum;


	/// �G--------------------------------------

	// �G�̐�
	const int enemyNum = 30;

	// ���ꂼ��̓G�������������
	struct SLightBall
	{
		// �G�̃|�C���^
		EnemyMove1* p_enemyMove;

		// �����Ă��邩
		bool aliveNow;
	};

	// �G�̍\���̂�����
	SLightBall s_lightBall[30];


	/// �J����-------------------

	// �J�����̃|�C���^
	Camera* p_camera;


	/// �����蔻��-----------------------

	// �A�N�^�[���m�̂����蔻��
	void ActorHit();


	/// ���C�g�Ɋւ���--------------------------

	// ���C�g�n���h���̐�
	const int lightNum = 4;

	// ���C�g�n���h�����ێ�
	int lightHandle[4];

	// ���C�g�͈̔�
	float lightRange[4];

	// ���C�g�̍��W
	VECTOR lightArea[4];

	// ���C�g�Ɋւ���֐�
	void LightProcess();

	// �C�x���g���s��
	bool lightEventStart;

	// �C�x���g�̏I�����m�F
	bool lightEventEnd;	

	// �C�x���g�̃J�E���g
	int lightEventCount;

	// ���C�g������
	bool lightEnd;

	// �����̍L���̒��O�}�b�N�X
	float lightRangePreMax;

	// �����̍L�����L����X�s�[�h
	float lightRangeSpeed;
	/// ----------------------------------------


	/// �����Ă錕-----------------------------

	// ������A�C�e���i���j
	DropItemMove1* p_dropItem;


	/// ����------------------------------

	// ���X�e�B�b�N�����p�摜
	int stickLeftDraw;

	// �E�X�e�B�b�N�����p�摜
	int stickRightDraw;

	// �����摜�̃t�F�[�h
	int explanationDrawFeed;

	// �����摜�̃t�F�[�h�̖ړI�J�E���g
	int nextExplanationDrawFeed;


	/// �G�t�F�N�g�֘A------------------
	int effeckBack;
	int playingEfBack;


public:
	// �R���X�g���N�^
	MainMove1(const std::vector<int> v_file);

	// �f�X�g���N�^
	~MainMove1();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;


	// �J�����̃v���Z�X
	void CameraProcess() override;

	// �e�N�X�`���̐؂�ւ�
	void TextureReload() override {}

	// �e�N�X�`���̍����ւ��������̃��[�u�ł͎g��Ȃ�
	void ThsTextureReload() override {}

	// �I�v�V������ʂł̃��f���\��
	void OptionActorModel() override;

	// �I�v�V������ʂł̃��f���\���̏���
	void OptionActorModelBefore() override;

	// �I�v�V������ʂł̃��f���\���̌�n��
	void OptionActorModelAfter() override;
};
