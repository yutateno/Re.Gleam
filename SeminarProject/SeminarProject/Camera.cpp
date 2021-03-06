#include "Camera.hpp"



/// ------------------------------------------------------------------------------------
void Camera::RLrotate(const float speed, float& axisOne, float& axisTwo)
{
	const float tempX = axisOne;
	const float tempY = axisTwo;
	axisOne = tempX * cosf(speed) + tempY * sinf(speed);
	axisTwo = -tempX * sinf(speed) + tempY * cosf(speed);
}



/// ------------------------------------------------------------------------------------
Camera::Camera(const VECTOR charaarea)
{
	// 遠近法カメラの初期化
	perspesctiveViewArea = VGet(0, 150, 0);
	cameraPerspectiveArea = VGet(0, 530, 700);


	// 正射影カメラの初期化
	orthoViewArea = VGet(0, 150, 0);
	cameraOrthoArea = VGet(0, 1700, 2430);
	orthoArea = 2200.0f;


	// プレイヤーの座標初期化
	charaArea = VAdd(charaarea, VGet(0.0f, 80.0f, 0.0f));


	// 基本情報初期化
	speed = DX_PI_F / 90;
	angle = 0.0f;
	zRota = VGet(0, 530, 700);
	shakePower = 0.0f;


	// 遠近法カメラだったら
	if (!BASICPARAM::nowCameraOrtho)
	{
		SetCameraNearFar(100.0f, 9500.0f);	// カメラの描画範囲を指定
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraPerspectiveArea, charaArea), VAdd(perspesctiveViewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraPerspectiveArea));
	}
	// 正射影カメラだったら
	else
	{
		SetupCamera_Ortho(orthoArea);
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraOrthoArea, charaArea), VAdd(orthoViewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraOrthoArea));
	}


	// DXライブラリのカメラとEffekseerのカメラを同期
	Effekseer_Sync3DSetting();
} /// Camera::Camera(const VECTOR charaarea, const int collStageHandle)



/// ------------------------------------------------------------------------------------
Camera::~Camera()
{
}



/// ------------------------------------------------------------------------------------
void Camera::Process(const VECTOR charaarea)
{
	charaArea = VAdd(charaarea, VGet(0.0f, 80.0f, 0.0f));		// キャラの位置を更新


	// 左に回転中
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) < 0)
	{
		// 遠近法カメラの回転処理
		RLrotate(speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraPerspectiveArea.x, cameraPerspectiveArea.z);
		// 正射影カメラの回転処理
		RLrotate(speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraOrthoArea.x, cameraOrthoArea.z);


		// カメラの方向
		if ((angle >= DX_TWO_PI_F && !BASICPARAM::cameraHorizonReturn)
			|| (angle <= -DX_TWO_PI_F && BASICPARAM::cameraHorizonReturn))
		{
			angle = 0;
		}
		angle = angle + (speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f));
	}
	// 右に回転中
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
	{
		// 遠近法カメラの回転処理
		RLrotate(-speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraPerspectiveArea.x, cameraPerspectiveArea.z);
		// 正射影カメラの回転処理
		RLrotate(-speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraOrthoArea.x, cameraOrthoArea.z);


		// カメラの方向
		if ((angle <= -DX_TWO_PI_F && !BASICPARAM::cameraHorizonReturn)
			|| (angle >= DX_TWO_PI_F && BASICPARAM::cameraHorizonReturn))
		{
			angle = 0;
		}
		angle = angle - (speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f));
	}


	// 正射影カメラじゃなかったら
	if (!BASICPARAM::nowCameraOrtho)
	{
		// 上に回転
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_Y) > 0)
		{
			if ((zRota.y <= 600.0f && !BASICPARAM::cameraVerticalReturn)
				|| (zRota.y >= 0.0f && BASICPARAM::cameraVerticalReturn))
			{
				VECTOR temp = VSub(cameraPerspectiveArea, zRota);
				RLrotate(-speed * (BASICPARAM::cameraVerticalReturn ? -1.0f : 1.0f), zRota.z, zRota.y);		// 回転処理
				cameraPerspectiveArea = VAdd(VGet(cameraPerspectiveArea.x, 0, cameraPerspectiveArea.z)
					, VGet(0, zRota.y + temp.y, 0));
			}
		}
		// 下に回転
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_Y) < 0)
		{
			if ((zRota.y >= 0.0f && !BASICPARAM::cameraVerticalReturn)
				|| (zRota.y <= 600.0f && BASICPARAM::cameraVerticalReturn))
			{
				VECTOR temp = VSub(cameraPerspectiveArea, zRota);
				RLrotate(speed * (BASICPARAM::cameraVerticalReturn ? -1.0f : 1.0f), zRota.z, zRota.y);	// 回転処理
				cameraPerspectiveArea = VAdd(VGet(cameraPerspectiveArea.x, 0, cameraPerspectiveArea.z)
					, VGet(0, zRota.y + temp.y, 0));
			}
		}
	}


	// 遠近法カメラだったら
	if (!BASICPARAM::nowCameraOrtho)
	{
		// 3Dサウンドの更新
		SoundProcess::SetLisnerViewArea(perspesctiveViewArea);
		SoundProcess::SetLisnerArea(cameraPerspectiveArea);
	}
	// 正射影カメラだったら
	else
	{
		// 3Dサウンドの更新
		SoundProcess::SetLisnerViewArea(orthoViewArea);
		SoundProcess::SetLisnerArea(cameraOrthoArea);
	}


	// DXライブラリのカメラとEffekseerのカメラを同期
	Effekseer_Sync3DSetting();
} /// void Camera::Process(const VECTOR charaarea)



/// ------------------------------------------------------------------------------------
void Camera::SetUp()
{
	// 遠近法カメラだったら
	if (!BASICPARAM::nowCameraOrtho)
	{
		VECTOR tempArea = VAdd(cameraPerspectiveArea, VGet(0, shakePower, 0));
		VECTOR tempViewArea = VAdd(perspesctiveViewArea, VGet(0, shakePower, 0));
		SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
		SetCameraNearFar(100.0f, 9500.0f);
		SetCameraPositionAndTarget_UpVecY(VAdd(tempArea, charaArea), VAdd(tempViewArea, charaArea));
		SoundProcess::SetLisnerArea(tempArea);
		SoundProcess::Set3DRadius(VSize(tempArea));
	}
	// 正射影カメラだったら
	else
	{
		VECTOR tempArea = VAdd(cameraOrthoArea, VGet(0, shakePower, 0));
		VECTOR tempViewArea = VAdd(orthoViewArea, VGet(0, shakePower, 0));
		SetupCamera_Ortho(orthoArea);
		SetCameraPositionAndTarget_UpVecY(VAdd(tempArea, charaArea), VAdd(tempViewArea, charaArea));
		SoundProcess::SetLisnerArea(tempArea);
		SoundProcess::Set3DRadius(VSize(tempArea));
	}


	// DXライブラリのカメラとEffekseerのカメラを同期
	Effekseer_Sync3DSetting();
}



/// ------------------------------------------------------------------------------------
const VECTOR Camera::GetArea()
{
	// 遠近法カメラだったら
	if (!BASICPARAM::nowCameraOrtho)
	{
		return cameraPerspectiveArea;
	}
	// 正射影カメラだったら
	else
	{
		return cameraOrthoArea;
	}
}
