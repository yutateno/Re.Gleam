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


	viewArea = VGet(0, 150, 0);

	charaArea = VAdd(charaarea, VGet(0.0f, 80.0f, 0.0f));

	speed = DX_PI_F / 90;
	angle = 0.0f;

	cameraPerspectiveArea = VGet(0, 530, 700);
	cameraOrthoArea = VGet(0, 1700, 2430);
	orthoArea = 2200.0f;

	if (!BASICPARAM::nowCameraOrtho)
	{
		SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraPerspectiveArea, charaArea), VAdd(viewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraPerspectiveArea));
	}
	else
	{
		SetupCamera_Ortho(orthoArea);

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraOrthoArea, charaArea), VAdd(viewArea, charaArea));
		SoundProcess::Set3DRadius(VSize(cameraOrthoArea));
	}
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
		RLrotate(speed, cameraPerspectiveArea);	// 回転処理
		RLrotate(speed, cameraOrthoArea);	// 回転処理
		angle += speed;
	}
	// 右に回転中
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
	{
		RLrotate(-speed, cameraPerspectiveArea);	// 回転処理
		RLrotate(-speed, cameraOrthoArea);			// 回転処理
		angle -= speed;
	}


	SoundProcess::SetLisnerViewArea(viewArea);
	if (!BASICPARAM::nowCameraOrtho)
	{
		SoundProcess::SetLisnerArea(cameraPerspectiveArea);
	}
	else
	{
		SoundProcess::SetLisnerArea(cameraOrthoArea);
	}
}

void Camera::SetUp()
{
	if (!BASICPARAM::nowCameraOrtho)
	{
		SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
		SetCameraNearFar(100.0f, 10000.0f);	// カメラの描画範囲を指定

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraPerspectiveArea, charaArea), VAdd(viewArea, charaArea));
		SoundProcess::SetLisnerArea(cameraPerspectiveArea);
		SoundProcess::Set3DRadius(VSize(cameraPerspectiveArea));
	}
	else
	{
		SetupCamera_Ortho(orthoArea);

		// 第一引数の視点から第二引数のターゲットを見る角度にカメラを設置
		SetCameraPositionAndTarget_UpVecY(VAdd(cameraOrthoArea, charaArea), VAdd(viewArea, charaArea));
		SoundProcess::SetLisnerArea(cameraOrthoArea);
		SoundProcess::Set3DRadius(VSize(cameraOrthoArea));
	}
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
void Camera::RLrotate(const float speed, VECTOR& p_cameraArea)
{
	float tempX = p_cameraArea.x;
	p_cameraArea.x = tempX * cosf(speed) + p_cameraArea.z *sinf(speed);
	p_cameraArea.z = -tempX * sinf(speed) + p_cameraArea.z * cosf(speed);
}
