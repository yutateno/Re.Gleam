#pragma once
#include "BasicObject.hpp"


class StageStreetLight : public BasicObject
{
public:
	// �R���X�g���N�^
	StageStreetLight(const int draw, const int collStageHandle, const VECTOR area);

	// �f�X�g���N�^
	~StageStreetLight();


	// �`��
	void Draw();
};

