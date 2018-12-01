#pragma once
#include "BasicCreature.hpp"


class Character : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���-----------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;


	/// ���[�V�����Ɋւ���--------------------
	enum MOTION { run, idle, walk };


	/// �����Ɋւ���----------------------------------

	// �����̌���
	enum DIRECTION { left, down, right, up };

	// �����Ă��邩�ǂ���
	bool m_direction[4];

	// �����̃v���Z�X
	void MoveProcess();


public:
	// �R���X�g���N�^
	Character(const int modelHandle, const int collStageHandle);

	// �f�X�g���N�^
	~Character();


	// �`��
	void Draw();

	// �v���Z�X
	void Process(const float getAngle);


	// �ʒu��������
	void PositionReset();
};