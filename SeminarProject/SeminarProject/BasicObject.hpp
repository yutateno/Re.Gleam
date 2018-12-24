#pragma once
#include "LoadFile.hpp"


class BasicObject
{
protected:
	// ���f���̃n���h��
	int modelHandle;

	// ���f���̍���
	float modelHeight;


	/// �����e�Ɋւ���----------------

	// �����e�̍���
	float shadowHeight;

	// �����e�̃T�C�Y
	float shadowSize;

	// �����e�̃v���Z�X
	void ShadowFoot();

	// �����e�̃G���A
	VECTOR area;


private:
	/// �e�Ɋւ���------------------------------------

	// ���͂̃|���S����������\����
	MV1_COLL_RESULT_POLY_DIM ShadowHitResDim;

	// �e�̃|���S���̍\����
	MV1_COLL_RESULT_POLY *ShadowHitRes;

	// �e�̍s��
	VERTEX3D ShadowVertex[3];

	// �e�̍��W
	VECTOR ShadowSlideVec;

	// �e�̃n���h��
	int shadowHandle;


	// �X�e�[�W�n���h��
	int stageHandle;

	// ��ʊO�ɊO��ĕ`�悳���Ȃ�����܂ł̃J�E���g
	int notViewCount;

	// �I�v�V�����ł̉�]��
	int optionRotaCount;

	// �I�v�V�����ł����f���\���J�E���g
	int optionModelDrawCount;

public:
	// �R���X�g���N�^
	BasicObject();

	// �R�s�[�R���X�g���N�^
	BasicObject(const int collStageHandle);

	// �f�X�g���N�^
	virtual ~BasicObject();


	// �`��
	void Draw();

	// �I�v�V�����p���f���`��
	void OptionActorDraw();

	// �I�v�V�����p���f���`��̏���
	void OptionActorDrawBefore();


	/// �Q�b�^�[�Z�b�^�[

	// ���W��n��
	const VECTOR GetArea() const { return area; }
};

