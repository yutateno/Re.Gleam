#pragma once
#include "BasicObject.hpp"


class StagePaneru : public BasicObject
{
public:
	// �R���X�g���N�^
	StagePaneru(const int draw, const int collStageHandle, const VECTOR area);

	// �f�X�g���N�^
	~StagePaneru();


	// �`��
	void Draw();
};

