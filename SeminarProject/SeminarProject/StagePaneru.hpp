#pragma once
#include "BasicObject.hpp"


/*
���̃X�e�[�W�ւ̖���������p�l���̃N���X
*/
class StagePaneru : public BasicObject
{
public:
	// �R���X�g���N�^
	StagePaneru(const int draw, const VECTOR area);

	// �f�X�g���N�^
	~StagePaneru();


	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}

};

