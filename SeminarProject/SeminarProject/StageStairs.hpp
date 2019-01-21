#pragma once
#include "BasicObject.hpp"


/*
�K�i�̃N���X
*/
class StageStairs : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle;

	
	// Y���ɉ�]
	float angle;


public:
	// �R���X�g���N�^
	StageStairs(const int draw, const VECTOR area, const int tex0, const float angle);

	// �f�X�g���N�^
	~StageStairs();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();


	// Y���̉�]
	const float GetYAngle() const { return angle; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

