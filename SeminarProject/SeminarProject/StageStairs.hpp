#pragma once
#include "BasicObject.hpp"


class StageStairs : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle;


public:
	// �R���X�g���N�^
	StageStairs(const int draw, const VECTOR area, const int tex0);

	// �f�X�g���N�^
	~StageStairs();


	// �`��
	void Draw();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();
};

