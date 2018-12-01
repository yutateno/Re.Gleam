#pragma once
#include "BasicCreature.hpp"
#include <random>


class OrdinaryPerson : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���---------------

	// �O��̃L���������������ϐ�
	float direZAngle;		

	// ���E�̃L���������������ϐ�
	float direXAngle;		

	// ���̑O��̃L���������������ϐ�
	float nextDireZAngle;

	// ���̍��E�̃L���������������ϐ�
	float nextDireXAngle;


	/// ���[�V�����Ɋւ���--------------------

	// ���[�V������ID
	enum MOTION { run, idle, walk };


	/// �����Ɋւ���-----------

	// �����̃v���Z�X
	void MoveProcess();

	// �����̃J�E���g
	int moveCount;


public:
	// �R���X�g���N�^
	OrdinaryPerson(const int modelHandle, const int collStageHandle, const VECTOR area);

	// �f�X�g���N�^
	~OrdinaryPerson();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();
};

