#pragma once
#include "BasicObject.hpp"


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


	// �`��
	void Draw();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// Y���̉�]
	const float GetYAngle() const { return angle; }
};

