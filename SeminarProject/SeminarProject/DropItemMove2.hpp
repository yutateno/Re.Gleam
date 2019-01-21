#pragma once
#include "BasicObject.hpp"
#include <random>


/*
���[�u�Q�ŏo�Ă���h���b�v�A�C�e���̃N���X
*/
class DropItemMove2 : public BasicObject
{
private:
	// ��]�p�ϐ�
	int rotationY;

	// ���񂾂��ǂ���
	bool deathNow;

	// ���݂������ꂽ���ǂ���
	bool aliveNow;

	// ��юU��t���[��
	int flyAroundFrame;

	// ��юU������̍��W
	float nextAreaX, nextAreaZ, moveAreaY;

	// �����l
	std::random_device rnd;


public:
	// �R���X�g���N�^
	DropItemMove2(const int draw, VECTOR area, const int tex0);

	// �f�X�g���N�^
	~DropItemMove2();


	// �v���Z�X
	void Process();


	// �����̍��W�ɋ߂Â�
	void ChaseActor(const VECTOR chaseArea);

	// ���݂��ꐶ����
	void SetDeath(bool death) { deathNow = death; }

	// ���݂������ꂽ���ǂ���
	void SetAlive(bool alive) { aliveNow = alive; }

	// ���݂��ꐶ�����Ă��邩�ǂ����n��
	const bool GetDeath() { return deathNow; }

	// ���݂�������ĂȂ����ǂ����n��
	const bool GetAlive() { return aliveNow; }

	// �ړI�̍��W�ɒB�������ƂŃL�����N�^�[����ɓ�����邩�ǂ���
	const bool GetCanCatch() { return flyAroundFrame >= 60 ? true : false; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

