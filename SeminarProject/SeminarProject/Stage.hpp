#pragma once
#include "Basic.hpp"


class Stage
{
private:
	// �X�e�[�W
	int drawStageHandle;		


public:
	// �R���X�g���N�^
	Stage(const int drawStageHandle);		

	// �f�X�g���N�^
	~Stage();						


	// �`��
	void Draw();
};
