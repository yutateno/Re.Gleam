#pragma once
#include "BasicCreature.hpp"

#include <random>

class CharacterSword : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���-----------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;

	// �c���p�`��
	VECTOR preDrawArea;


	/// ���[�V�����Ɋւ���--------------------------------------------------------------------------------------

	// ������ID
	enum MOTION { idle, action1, action2, action3, skyAction1, skyAction2, skyAction3, dash, walk, jump, fall
				, damage, death, gunAction, gunActionWalk, nagiharai, handUp};

	// �u�ԓI�ɑ����ł���Ƃ�
	int moveFastWaitCount;



	/// �K�i�Ɋւ���----------------------

	// �K�i�̃��f��
	std::vector<int> v_stairsHandle;


	/// �K�i�Ə��Ɋւ���

	// �K�i�Ə��̃��f��
	std::vector<int> v_stairsRoadHandle;


	/// �p�l���Ɋւ���------------------------
	
	// �p�l���̃��f��
	int paneruHandle[10];


	/// �����Ɋւ���------------------------------

	// ���ꂼ��̌���ID
	enum DIRECTION { left, down, right, up };

	// �����Ă��邩�ǂ���
	bool m_direction[4];

	// ���Ă��邩�ǂ���
	bool walkNow;

	// �����̃v���Z�X
	void MoveProcess();

	// �����̈ʒu
	float leftFootArea;

	// �����Ă���t���[����
	int underWalkCount;

	// �Б������ɐG���t���[����
	int leftUnderTouchFrame;


	/// �U���Ɋւ���-----------------------

	// ���U�����Ă��邩�ǂ���
	bool attackNow;
	
	// ���̃R���{�ւȂ��邩�ǂ���
	bool attackNext;

	// ���̍U���̃t���[����
	float attackFrame;

	// �U���̔ԍ�
	int attackNumber;

	// ���O�̍U���̔ԍ�
	int preAttackNumber;

	// �W�����v�ł̍U�����������ǂ���
	bool jumpAttackDo;

	// �U���̃v���Z�X
	void AttackProcess();

	// �_���[�W���󂯂Ă��邩�ǂ���
	bool damageFlag;

	// �_���[�W�J�E���g
	int damageCount;

	// ���O�̃_���[�W�J�E���g
	int preDamageCount;

	// �_���[�W�̃u�����h���l
	int damageBlend[10];

	// �_���[�W�\���摜
	int damageDraw[3];

	// �_���[�W���󂯂Ă��Ȃ��J�E���g
	int notDamegaCount;

	// �_���[�W�\���摜�̃t���[��
	int damageDrawFrame;

	// �_���[�W�摜��ID
	int damageDrawID;


	/// �W�����v�Ɋւ���------------------

	// �d��
	float gravity;

	// �W�����v��
	float flyJumpPower;

	// �����Ă���Ƃ���Y���ɗ^�����
	float fallJumpPower;

	// �W�����v�v���Z�X
	void JumpProcess();

	// �W�����v���珰�ɂ������ǂ���
	bool preJumpNow;

	// �����Ă���t���[����
	int flyCount;

	// �s���ɂ���ăA�j���[�V�����̊Ǘ�
	void AnimProcess();
	

	/// �e�N�X�`���Ɋւ���------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;
	int textureHandle4;


	/// �G�t�F�N�g�Ɋւ���
	int effeckBack[10];
	int playingEfBack;


public:
	// �R���X�g���N�^
	CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle, const int stairsRoadHandle
	, const int tex0, const int tex1, const int tex2, const int tex3, const int tex4);

	// �f�X�g���N�^
	~CharacterSword();


	// �`��
	void Draw();
	
	// �v���Z�X
	void Process(const float getAngle);

	// �|�W�V����������������
	void PositionReset();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();


	/// �Q�b�^�[�Z�b�^�[--------------------

	// �K�i�̍��W��ݒ肷��
	void SetStairsArea(const VECTOR stairsArea, const int num, const float angle);

	// �p�l���̍��W��ݒ肷��
	void SetPaneruArea(const VECTOR paneruArea, const int num);

	// �K�i�Ə��̍��W��ݒ肷��
	void SetStairsRoadArea(const VECTOR stairsRoadArea, const int num, const float angle);

	// ���O�̃G���A��n��
	const VECTOR GetPreArea() const { return preArea; }

	// �U�����Ă��邩��n��
	const bool GetAttackNow() const { return attackNow; }

	// �U���̕���̏��߂̍��W��n��
	const VECTOR GetAttackFirstFrameArea() const { return MV1GetFramePosition(modelHandle, 66); }

	// �U���̕���̍Ō�̍��W��n��
	const VECTOR GetAttackEndFrameArea() const { return MV1GetFramePosition(modelHandle, 67); }

	// �L�����N�^�[�̌����Ă������
	const float GetAngle() const { return angle + direXAngle + direZAngle; }

	// �U�����󂯂Ă���
	void SetDamage();
};

