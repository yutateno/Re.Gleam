#pragma once
#include "BasicObject.hpp"

#include <random>

class DropItemMove2 : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle;

public:
	DropItemMove2(const int draw, VECTOR area, const int tex0);
	~DropItemMove2();


	// �`��
	void Draw();

	// �e�N�X�`���؂�ւ�
	void TextureReload();
};

