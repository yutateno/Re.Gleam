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
	StageStreetLight(const int draw, const int collStageHandle, const VECTOR area);

	// �f�X�g���N�^
	~StageStreetLight();


	// �`��
	void Draw();
};

