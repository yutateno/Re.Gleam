#pragma once
#include "Basic.hpp"


class CameraMove6
{
private:
	// �J�����̈ʒu
	VECTOR area;
	VECTOR viewArea;


public:
	// �R���X�g���N�^
	CameraMove6();

	// �f�X�g���N�^
	~CameraMove6();


	// �J�����̃Z�b�g�A�b�v
	void SetUp();

	// �J�����̍��W��n��
	const VECTOR GetArea() const { return area; }

	// �J�����̍��W��ݒ肷��
	void SetArea(VECTOR t_area) { area = t_area; }

	// �J�����̒��ړ_��ݒ肷��
	void SetView(VECTOR t_viewArea) { viewArea = t_viewArea; }
};

