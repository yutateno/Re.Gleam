#pragma once
#include "BasicObject.hpp"


class StageStairs : public BasicObject
{
public:
	// �R���X�g���N�^
	StageStairs(const int draw, const int collStageHandle, const VECTOR area);

	// �f�X�g���N�^
	~StageStairs();


	// �`��
	void Draw();
};

