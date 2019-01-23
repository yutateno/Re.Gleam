#pragma once
#include "Basic.hpp"


/*
���X�{�X�����X�̒�
*/
class MagicIcePillar
{
private:
	// �o�����̃G�t�F�N�g
	int effectAppear;
	int playingEfAppear;

	// �U�����̃G�t�F�N�g
	int effectAttack;
	int playingEfAttack;

	// ���W
	VECTOR area;

	// �����t���[��
	const int aliveTime = 100;
	int nowTime;

	// �J�n���邩�ǂ���
	bool playEffect;


public:
	// �R���X�g���N�^
	MagicIcePillar();

	// �f�X�g���N�^
	~MagicIcePillar();


	// �v���Z�X
	void Process();

	// �A�N�e�B�u�ɂ���
	void Active(VECTOR area);

	// �A�N�e�B�u�����n��
	const bool GetActive() const { return playEffect; }

	// ������n��
	const float GetWidth() const { return 50.0f; }

	// �c����n��
	const float GetHeight() const { return 200.0f; }

	// ���̍��W��n��
	const VECTOR GetArea() const { return area; }
};

