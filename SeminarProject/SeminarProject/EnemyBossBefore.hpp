#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyBossBefore : public BasicCreature
{
public:
	// �R���X�g���N�^
	EnemyBossBefore();

	// �f�X�g���N�^
	~EnemyBossBefore();


	// �v���Z�X
	void Process();

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};
