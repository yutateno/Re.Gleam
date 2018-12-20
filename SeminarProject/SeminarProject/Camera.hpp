#pragma once
#include "Basic.hpp"
#include "SoundProcess.hpp"


class Camera
{
private:
	// �J�����̈ʒu
	VECTOR cameraPerspectiveArea;		// ���ߖ@�J����
	VECTOR cameraOrthoArea;				// ���ˉe�J����

	// �����������
	VECTOR viewArea;

	// �L�����ʒu
	VECTOR charaArea;

	// �L�����N�^�[�̃A���O��
	float angle;

	// �����蔻��p�X�e�[�W
	int stageHandle;

	// ���ˉe�J�����p�̍��W
	float orthoArea;

	// ��]�X�s�[�h
	float speed;

	// ��]���s���֐�
	void RLrotate(const float speed, VECTOR& p_cameraArea);


public:
	// �L�����̈ʒu�������Ɏ�����R���X�g���N�^
	Camera(const VECTOR charaarea, const int collStageHandle);

	// �f�X�g���N�^
	~Camera();


	// �L�����̈ʒu�������Ɏ�����v���Z�X
	void Process(const VECTOR charaarea);		

	// �J�����̃Z�b�g�A�b�v
	void SetUp();

	// �L�����N�^�[�̃A���O��
	const float GetAngle() const { return angle; }

	// �J�����̍��W
	const VECTOR GetArea();
};