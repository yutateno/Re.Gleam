#pragma once
#include "BasicObject.hpp"


class StageStairsRoad : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle0;
	int textureHandle1;


	// Y���ɉ�]
	float angle;


public:
	// �R���X�g���N�^
	StageStairsRoad(const int draw, const VECTOR area, const int tex0, const int tex1, const float angle);

	// �f�X�g���N�^
	~StageStairsRoad();


	// �e�N�X�`���؂�ւ�
	void TextureReload();


	// Y���̉�]
	const float GetYAngle() const { return angle; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

