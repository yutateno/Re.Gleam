#pragma once
#include "BasicObject.hpp"


class StageStreetLight : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle0;
	int textureHandle1;


public:
	// �R���X�g���N�^
	StageStreetLight(const int draw, const VECTOR area, const int tex0, const int tex1);

	// �f�X�g���N�^
	~StageStreetLight();


	// �`��
	void Draw();

	// �e�N�X�`���؂�ւ�
	void TextureReload();
};

