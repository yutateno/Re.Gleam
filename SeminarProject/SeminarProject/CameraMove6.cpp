#include "CameraMove6.hpp"


// コンストラクタ
CameraMove6::CameraMove6()
{
	area = VGet(0, 500, 0);
	viewArea = VGet(0, 0, 0);


	SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}


// デストラクタ
CameraMove6::~CameraMove6()
{
}


// 再セットアップ
void CameraMove6::SetUp()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定
	SetCameraPositionAndTarget_UpVecY(area, viewArea);
}
