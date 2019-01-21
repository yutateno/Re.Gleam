#include "CameraMove6.hpp"



/// ------------------------------------------------------------------------------------
CameraMove6::CameraMove6()
{
	area = VGet(0, 500, 0);
	viewArea = VGet(0, 0, 0);


	SetCameraNearFar(100.0f, 10000.0f);
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}



/// ------------------------------------------------------------------------------------
CameraMove6::~CameraMove6()
{
}



/// ------------------------------------------------------------------------------------
void CameraMove6::SetUp()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}
