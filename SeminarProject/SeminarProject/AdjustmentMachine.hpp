#pragma once
#include "BasicObject.hpp"


/*
���[�u�Q�ȍ~�ɏo�āA���ւ̃X�e�[�W���o���I�y���[�^�[�̃N���X
*/
class AdjustmentMachine : public BasicObject
{
private:
	// �e�N�X�`��
	int textureHandle0;
	int textureHandle1;
	int textureHandleDisplayBlack;


	/// ���[�u2�p�̃u�����h-------------------------------

	int blendCount;
	int nextBlendCount;
	// ���[�u2�ɂĉ��h���b�v�A�C�e���������ǂ���
	int dropCount;

	
	// �G���t���b�O
	bool canTouch;


public:
	AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1);
	~AdjustmentMachine();

	// �`��
	void Draw();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �񓯊��e�N�X�`�������ւ�
	std::thread ThsTextureReload();

	// �G���ꎟ��Ńe�N�X�`����؂�ւ���
	void ChangeDisplayTexture(bool touchNow);

	// �G���t���b�O
	const bool GetCanTouch()const { return canTouch; }

	// �����h���b�v�A�C�e���������ǂ���
	void CatchDropItem() { dropCount++; }

	// �����h���b�v�A�C�e������Ȃ����ǂ���
	const bool GetFullDropItem() const { return dropCount < 15 ? false : true; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

