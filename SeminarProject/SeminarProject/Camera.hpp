#pragma once
#include "Basic.hpp"


/*
�ʏ�̃J�����̃N���X
*/
class Camera
{
private:
	// �J�����̈ʒu
	VECTOR cameraPerspectiveArea;		// ���ߖ@�J����
	VECTOR cameraOrthoArea;				// ���ˉe�J����

	// �����������
	VECTOR perspesctiveViewArea;		// ���ߖ@�J����
	VECTOR orthoViewArea;				// ���ˉe�J����

	// �L�����ʒu
	VECTOR charaArea;

	// �L�����N�^�[�̃A���O��
	float angle;

	// ���ˉe�J�����p�̍��W
	float orthoArea;

	// ��]�X�s�[�h
	float speed;

	// ��]���s���֐�
	void RLrotate(const float speed, float& axisOne, float& axisTwo);

	// �㉺��]�p
	VECTOR zRota;

	// ��ʗh��̃p�����[�^
	float shakePower;


public:
	// �L�����̈ʒu�������Ɏ�����R���X�g���N�^
	Camera(const VECTOR charaarea);

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


	// ��ʗh��̃p�����[�^��ݒ肷��
	void SetShakePower(float shakeParameter) { this->shakePower = shakeParameter; }
};