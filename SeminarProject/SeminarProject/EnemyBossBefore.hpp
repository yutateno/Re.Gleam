#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
���[�u�P����{�X��܂łɏo�Ă���{�X�̃N���X
*/
class EnemyBossBefore : public BasicCreature
{
private:
	/// �����l----------------------------------------

	std::random_device rnd;


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
};
