#pragma once
#include "BasicCreature.hpp"


class CharacterSword : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���-----------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;


	/// ���[�V�����Ɋւ���--------------------------------------------------------------------------------------

	// ������ID
	enum MOTION { idle, action1, action2, action3, skyAction1, skyAction2, skyAction3, dash, walk, jump, fall
				, damage, death, gunAction, gunActionWalk, nagiharai, handUp};



	/// �K�i�Ɋւ���----------------------

	// �K�i�̃��f��
	int stairsHandle[10];

	// �K�i�̈ʒu
	VECTOR stairsArea[10];


	/// �p�l���Ɋւ���------------------------
	
	// �p�l���̃��f��
	int paneruHandle[10];

	// �p�l���̈ʒu
	VECTOR paneruArea[10];


	/// �����Ɋւ���------------------------------

	// ���ꂼ��̌���ID
	enum DIRECTION { left, down, right, up };

	// �����Ă��邩�ǂ���
	bool m_direction[4];

	// ���Ă��邩�ǂ���
	bool walkNow;

	// �����̃v���Z�X
	void MoveProcess();


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

	// �U���̃v���Z�X
	void AttackProcess();


	/// �W�����v�Ɋւ���------------------

	// �d��
	float gravity;

	// �W�����v��
	float flyJumpPower;

	// �����Ă���Ƃ���Y���ɗ^�����
	float fallJumpPower;

	// �W�����v�v���Z�X
	void JumpProcess();


	// �s���ɂ���ăA�j���[�V�����̊Ǘ�
	void AnimProcess();
	

	/// �e�N�X�`���Ɋւ���------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;
	int textureHandle4;


public:
	// �R���X�g���N�^
	CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle
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
	void SetStairsArea(const VECTOR stairsArea, const int num);

	// �p�l���̍��W��ݒ肷��
	void SetPaneruArea(const VECTOR paneruArea, const int num);

	// ���O�̃G���A��n��
	const VECTOR GetPreArea() const { return preArea; }

	// �U�����Ă��邩��n��
	bool GetAttackNow() { return attackNow; }

	// �U���̕���̏��߂̍��W��n��
	VECTOR GetAttackFirstFrameArea() { return MV1GetFramePosition(modelHandle, 66); }

	// �U���̕���̍Ō�̍��W��n��
	VECTOR GetAttackEndFrameArea() { return MV1GetFramePosition(modelHandle, 67); }
};

