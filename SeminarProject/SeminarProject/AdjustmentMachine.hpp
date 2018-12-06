#pragma once
#include "BasicObject.hpp"


class AdjustmentMachine : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle0;
	int textureHandle1;
	int textureHandleDisplayBlack;


public:
	AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1);
	~AdjustmentMachine();

	// �`��
	void Draw();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �G���ꎟ��Ńe�N�X�`����؂�ւ���
	void ChangeDisplayTexture(bool touchNow);
};

