#pragma once
#include "BasicObject.hpp"


/*
���[�u�P�ɂė����Ă��錕�̃N���X
*/
class DropItemMove1 : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle;


public:
	// �R���X�g���N�^
	DropItemMove1(const int draw, const int tex0);

	// �f�X�g���N�^
	~DropItemMove1();


	// �`��
	void Draw();
};

