#pragma once
#include "LoadFile.hpp"


/*
�S�A�N�^�[�̕K�v�ȗv�f���������N���X
*/
class BasicObject
{
protected:
	/// ���f���Ɋւ���---------------------------------------

	// ���f���̃n���h��
	int modelHandle;

	// ���f���̍���
	float modelHeight;

	// ���f���̉���
	float modelWidth;

	// ��ʊO�ɊO��ĕ`�悳���Ȃ�����܂ł̃J�E���g
	int notViewCount;


	/// �����e�Ɋւ���----------------------------------------

	// �����e�̍���
	float shadowHeight;

	// �����e�̃T�C�Y
	float shadowSize;

	// �����e�̃v���Z�X
	bool ShadowFoot(int shadowModel);

	// �����e�̃G���A
	VECTOR area;


private:
	/// �e�Ɋւ���--------------------------------------------

	// ���͂̃|���S����������\����
	MV1_COLL_RESULT_POLY_DIM shadowHitResDim;

	// �e�̃|���S���̍\����
	MV1_COLL_RESULT_POLY *shadowHitRes;

	// �e�̍s��
	VERTEX3D shadowVertex[3];

	// �e�̍��W
	VECTOR shadowSlideVec;

	// �e�̃n���h��
	int shadowHandle;


	/// ���[�u6�݂̂Ɋւ���ϐ�-------------------------------

	// �~�̔��a
	float move6_circle;

	// ���̓���
	float move6_line;


public:
	// �R���X�g���N�^
	BasicObject();

	// �R�s�[�R���X�g���N�^
	BasicObject(bool shadowDo);

	// �f�X�g���N�^
	virtual ~BasicObject();


	// �`��
	void ModelDraw();

	// ���[�u6�ɂĒn�ʂɒ��߂�
	void Move6SetDownArea();


	/// �Q�b�^�[�Z�b�^�[--------------------------------------

	// ���W��n��
	const VECTOR GetArea() const { return area; }

	// �c����n��
	const float GetHeight() const { return modelHeight; }

	// ������n��
	const float GetWidth() const { return modelWidth; }
};

