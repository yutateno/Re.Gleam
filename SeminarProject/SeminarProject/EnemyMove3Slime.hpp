#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove3Slime : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���-------------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;

	// ���̑O��̃L���������������ϐ�
	float nextDireZAngle;

	// ���̍��E�̃L���������������ϐ�
	float nextDireXAngle;


	/// ���[�V�����Ɋւ���----------

	// ���[�V������ID
	enum MOTION { idle, attack };


	/// �K�i�Ɋւ���--------------

	// �K�i�̃��f��
	std::vector<int> v_stairsHandle;


	/// �K�i�Ə��Ɋւ���----------

	// �K�i�Ə��̃��f��
	std::vector<int> v_stairsRoadHandle;


	/// �����Ɋւ���------------

	// �����̃v���Z�X
	void AutoMoveProcess();

	// �L�����N�^�[�Ɍ������悤�ȍs��
	void AttackMoveProcess();

	// �����̃J�E���g
	int moveCount;

	// �L�����N�^�[���߂��̂ŕ`�悵�ăv���Z�X�𓭂�����
	bool active;

	
	/// �����Ɋւ���

	// �d��
	float gravity;

	// �W�����v��
	float flyJumpPower;

	// �����Ă���Ƃ���Y���ɗ^�����
	float fallJumpPower;

	// �W�����v�v���Z�X
	void FallProcess();

	// �W�����v���珰�ɂ������ǂ���
	bool preJumpNow;

	// �����Ă���t���[����
	int flyCount;


	/// �e�N�X�`���Ɋւ���---------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;


public:
	// �R���X�g���N�^
	EnemyMove3Slime(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
		, const int tex0, const VECTOR area);

	// �f�X�g���N�^
	~EnemyMove3Slime();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �L�����N�^�[�̍��W��c������
	void SetCharacterArea(const VECTOR characterArea);

	// �A�N�e�B�u���ǂ���
	const bool GetActive() const { return active; }
};

