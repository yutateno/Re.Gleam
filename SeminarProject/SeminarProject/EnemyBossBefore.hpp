#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyBossBefore : public BasicCreature
{
public:
	// �R���X�g���N�^
	EnemyBossBefore();

	// �R�s�[�R���X�g���N�^
	EnemyBossBefore(const int modelHandle, const int modelTex0, const int modeltex1, const int modelTex2);

	// �f�X�g���N�^
	~EnemyBossBefore();


	// �v���Z�X
	void Process();

	// ���[�u6�ɂĂ̂ݑ̂̌�����ς���
	void MoveReturn();

	// �̂�n�ʂɖ��܂点��(���[�u6�̂�
	void AreaSetDown();

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};
