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

	// �����̃v���Z�X
	void MoveProcess();

	// �����̈ʒu
	float leftFootArea;

	// �����Ă���t���[����
	int underWalkCount;

	// �Б������ɐG���t���[����
	int leftUnderTouchFrame;

	// ����̃v���Z�X
	void OpeProcess();


	/// walkSpeed�̊e�X�̏󋵂̍ő�l---------------------------------------

	// �U�����̍ő�ړ��l
	const float maxWalkSpeedAttack = 60.0f;

	// �u�ԉ������̍ő�ړ���
	const float maxWalkSpeedFast = 85.0f;

	// �󒆂ŏu�ԉ������̍ő�ړ���
	const float maxWalkSpeedFlyFast = 80.0f;

	// �ʏ펞�̍ő�ړ���
	const float maxWalkSpeedNormal = 30.0f;

	// �󒆎��̍ő�ړ���
	const float maxWalkSpeedFly = 15.0f;

	// �u�ԉ������̍Ďg�p�ҋ@����
	const int maxFastMoveWaitCount = 34;


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

	// ��̍U�����[�V�������I��������ǂ���
	bool attackMotionEnd;

	// �ł��߂��G
	VECTOR mostNearEnemyArea;

	// �ł��߂��G�����b�N�I�������Ƃ��̌���
	float mostNearEnemyDire;


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


	/// ���Ɋւ���----------------------

	void SEProcess();


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

	// ����ł��Ȃ��v���Z�X
	void NotOpeProcess(const float getAngle);

	// ���ȊO�����蔻��������Ȃ��v���Z�X
	void OnlyCollFloorProcess(const float getAngle);


	// �|�W�V����������������
	void PositionReset() { area = VGet(0.0f, 50.0f, 0.0f); }

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �U�����󂯂Ă���
	void SetDamage() { damageFlag = true; }

	// �̂�n�ʂɖ��܂点��(���[�u6�̂�
	void AreaSetDown();

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override;


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

	// ���x�����������������ǂ���
	const bool GetMoveFastWaitCount() const { return moveFastWaitCount > 0 ? true : false; }

	// �U���̍Ō�̃��[�V����
	const bool GetAttackMotionEnd() const { return attackMotionEnd; }

	// �ł��߂��ă��b�N�I�����Ă���G
	void SetMostNearEnemyArea(VECTOR enemyArea = VGet(0, -1000, 0)) { mostNearEnemyArea = enemyArea; }
};

