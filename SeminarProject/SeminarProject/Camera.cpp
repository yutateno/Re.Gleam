#include "Camera.hpp"


// コンストラクタ
Camera::Camera(const VECTOR charaarea, const int collStageHandle)
{
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(1.75f, 1.0f, 1.75f));
	MV1SetupCollInfo(stageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetFrameVisible(stageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(stageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）


	perspesctiveViewArea = VGet(0, 150, 0);
	orthoViewArea = VGet(0, 150, 0);

	charaArea = VAdd(charaarea, VGet(0.0f, 80.0f, 0.0f));

	speed = DX_PI_F / 90;
	angle = 0.0f;

	zRota = VGet(0, 530, 700);
	cameraPerspectiveArea = VGet(0, 530, 700);
	cameraOrthoArea = VGet(0, 1700, 2430);
	orthoArea = 2200.0f;

	if (!BASICPARAM::nowCameraOrtho)
	{
		SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraPerspectiveArea, charaArea), VAdd(perspesctiveViewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraPerspectiveArea));
	}
	else
	{
		SetupCamera_Ortho(orthoArea);

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraOrthoArea, charaArea), VAdd(orthoViewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraOrthoArea));
	}

	// DXライブラリのカメラとEffekseerのカメラを同期する。
	Effekseer_Sync3DSetting();
}

// デストラクタ
Camera::~Camera()
{
	MODEL_RELEASE(stageHandle);
}


// メインプロセス
void Camera::Process(const VECTOR charaarea)
{
	charaArea = VAdd(charaarea, VGet(0.0f, 80.0f, 0.0f));					// キャラの位置を更新し続ける


	// 左に回転中
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) < 0)
	{
		RLrotate(speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraPerspectiveArea.x, cameraPerspectiveArea.z);	// 回転処理
		RLrotate(speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraOrthoArea.x, cameraOrthoArea.z);	// 回転処理
		if ((angle >= DX_TWO_PI_F && !BASICPARAM::cameraHorizonReturn)
			|| (angle <= -DX_TWO_PI_F && BASICPARAM::cameraHorizonReturn))
		{
			angle = 0;
		}
		angle = angle + (speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f));
		//printfDx("%f\n", angle);
	}
	// 右に回転中
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
	{
		RLrotate(-speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraPerspectiveArea.x, cameraPerspectiveArea.z);	// 回転処理
		RLrotate(-speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f), cameraOrthoArea.x, cameraOrthoArea.z);			// 回転処理
		if ((angle <= -DX_TWO_PI_F && !BASICPARAM::cameraHorizonReturn)
			|| (angle >= DX_TWO_PI_F && BASICPARAM::cameraHorizonReturn))
		{
			angle = 0;
		}
		angle = angle - (speed * (BASICPARAM::cameraHorizonReturn ? -1.0f : 1.0f));
		//printfDx("%f\n", angle);
	}
	// 上下回転
	if (!BASICPARAM::nowCameraOrtho)
	{
		// 上に回転中
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_Y) > 0)
		{
			if ((zRota.y <= 600.0f && !BASICPARAM::cameraVerticalReturn)
				|| (zRota.y >= 0.0f && BASICPARAM::cameraVerticalReturn))
			{
				VECTOR temp = VSub(cameraPerspectiveArea, zRota);
				RLrotate(-speed * (BASICPARAM::cameraVerticalReturn ? -1.0f : 1.0f), zRota.z, zRota.y);	// 回転処理
				cameraPerspectiveArea = VAdd(VGet(cameraPerspectiveArea.x, 0, cameraPerspectiveArea.z), VGet(0, zRota.y + temp.y, 0));
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
				cameraPerspectiveArea = VAdd(VGet(cameraPerspectiveArea.x, 0, cameraPerspectiveArea.z), VGet(0, zRota.y + temp.y, 0));
			}
		}
	}


	if (!BASICPARAM::nowCameraOrtho)
	{
		SoundProcess::SetLisnerViewArea(perspesctiveViewArea);
		SoundProcess::SetLisnerArea(cameraPerspectiveArea);
	}
	else
	{
		SoundProcess::SetLisnerViewArea(orthoViewArea);
		SoundProcess::SetLisnerArea(cameraOrthoArea);
	}


	// DXライブラリのカメラとEffekseerのカメラを同期する。
	Effekseer_Sync3DSetting();
}

void Camera::SetUp()
{
	if (!BASICPARAM::nowCameraOrtho)
	{
		SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
		SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraPerspectiveArea, charaArea), VAdd(perspesctiveViewArea, charaArea));
		SoundProcess::SetLisnerArea(cameraPerspectiveArea);
		SoundProcess::Set3DRadius(VSize(cameraPerspectiveArea));
	}
	else
	{
		SetupCamera_Ortho(orthoArea);

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraOrthoArea, charaArea), VAdd(orthoViewArea, charaArea));
		SoundProcess::SetLisnerArea(cameraOrthoArea);
		SoundProcess::Set3DRadius(VSize(cameraOrthoArea));
	}

	// DXライブラリのカメラとEffekseerのカメラを同期する。
	Effekseer_Sync3DSetting();
}

const VECTOR Camera::GetArea()
{
	if (!BASICPARAM::nowCameraOrtho)
	{
		return cameraPerspectiveArea;
	}
	else
	{
		return cameraOrthoArea;
	}
}

// ang角回転する
void Camera::RLrotate(const float speed, float& axisOne, float& axisTwo)
{
	const float tempX = axisOne;
	const float tempY = axisTwo;
	axisOne = tempX * cosf(speed) + tempY * sinf(speed);
	axisTwo = -tempX * sinf(speed) + tempY * cosf(speed);
}
