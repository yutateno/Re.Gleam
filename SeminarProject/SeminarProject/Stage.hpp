#pragma once
#include "Basic.hpp"


/*
�S���[�u�ł̃X�e�[�W�̃N���X
*/
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
