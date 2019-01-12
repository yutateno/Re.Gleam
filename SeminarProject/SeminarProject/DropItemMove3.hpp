#pragma once
#include "BasicObject.hpp"

#include <random>

class DropItemMove3 : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle;

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


public:
	// �R���X�g���N�^
	DropItemMove3(const int draw, VECTOR area, const int tex0);

	// �f�X�g���N�^
	~DropItemMove3();


	// �v���Z�X
	void Process();

	// �����̍��W�ɑ΂��ċ߂Â�����
	void ChaseActor(const VECTOR chaseArea);

	// �e�N�X�`���؂�ւ�
	void TextureReload();

	// ���݂��ꐶ����
	void SetDeath(bool death) { deathNow = death; }

	// ���݂������ꂽ���ǂ���
	void SetAlive(VECTOR dropArea, bool alive = true);

	// ���݂��ꐶ�����Ă��邩�ǂ����n��
	const bool GetDeath() { return deathNow; }

	// ���݂�������ĂȂ����ǂ����n��
	const bool GetAlive() { return aliveNow; }

	// �ړI�̍��W�ɒB�������ƂŃL�����N�^�[����ɓ�����邩�ǂ���
	const bool GetCanCatch() { return flyAroundFrame >= 60 ? true : false; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

