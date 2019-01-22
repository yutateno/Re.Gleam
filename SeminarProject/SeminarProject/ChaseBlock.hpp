#pragma once
#include "Basic.hpp"


/*
���X�{�X�����u���b�N
*/
class ChaseBlock
{
private:
	// ���W
	VECTOR area;

	// �ǂ�������v���C���[�̍��W
	VECTOR chaseArea;

	// �ǂ��z���Ă��������܂ł̃t���[��
	int disappearFrame;

	// �A�N�e�B�u���イ���ǂ���
	bool activeNow;

	// �ړ����x
	VECTOR speed;


public:
	// �R���X�g���N�^
	ChaseBlock();

	// �f�X�g���N�^
	~ChaseBlock();


	// �v���Z�X
	void Process();

	// �`��
	void Draw();

	// �A�N�e�B�u�ɂ���
	void Active(VECTOR chaseArea);

	// �A�N�e�B�u���ؓn��
	const bool GetActive() const { return activeNow; }
};

