#pragma once
#include "BasicCreature.hpp"


class Character : public BasicCreature
{
private:
	// ���ꂼ��̈ʒu�Ɋւ���
	float direZAngle;		// �O��̃L���������������ϐ�
	float direXAngle;		// ���E�̃L���������������ϐ�


	// ���[�V�����Ɋւ���
	enum MOTION { run, idle, walk };


	// �����Ɋւ���
	enum DIRECTION { left, down, right, up };
	bool m_direction[4];
	void MoveProcess();


public:
	Character(const int modelHandle, const int collStageHandle);	// �R���X�g���N�^
	~Character();					// �f�X�g���N�^


	void Draw();
	void Process(const float getAngle);


	void PositionReset();
};