#include "CameraMove6.hpp"


// �R���X�g���N�^
CameraMove6::CameraMove6()
{
	area = VGet(0, 500, 0);
	viewArea = VGet(0, 0, 0);


	SetCameraNearFar(100.0f, 10000.0f);	// �J�����̕`��͈͂��w��
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}


// �f�X�g���N�^
CameraMove6::~CameraMove6()
{
}


// �ăZ�b�g�A�b�v
void CameraMove6::SetUp()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// �J�����̕`��͈͂��w��
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}
