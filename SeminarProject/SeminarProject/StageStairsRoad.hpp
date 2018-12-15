#pragma once
#include "BasicObject.hpp"


class StageStairsRoad : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle0;
	int textureHandle1;


public:
	// �R���X�g���N�^
	StageStairsRoad(const int draw, const VECTOR area, const int tex0, const int tex1);

	// �f�X�g���N�^
	~StageStairsRoad();


	// �`��
	void Draw();

	// �e�N�X�`���؂�ւ�
	void TextureReload();
};

