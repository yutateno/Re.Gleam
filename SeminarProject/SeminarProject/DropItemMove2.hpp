#pragma once
#include "BasicObject.hpp"

#include <random>

class DropItemMove2 : public BasicObject
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

public:
	DropItemMove2(const int draw, VECTOR area, const int tex0);
	~DropItemMove2();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();

	// �L�����N�^�[���߂Â�����
	void StolenChara(const VECTOR characterArea);

	// �e�N�X�`���؂�ւ�
	void TextureReload();

	// ���݂��ꐶ����
	void SetDeath(bool death) { deathNow = death; }

	// ���݂������ꂽ���ǂ���
	void SetAlive(bool alive) { aliveNow = alive; }

	// ���݂��ꐶ�����Ă��邩�ǂ����n��
	bool GetDeath() { return deathNow; }

	// ���݂�������ĂȂ����ǂ����n��
	bool GetAlive() { return aliveNow; }
};
