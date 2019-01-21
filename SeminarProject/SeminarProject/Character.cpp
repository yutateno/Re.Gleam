#include "Character.hpp"



/// ----------------------------------------------------------------------------------------------------------------
void Character::MoveProcess()
{
	// 歩く状態だったら
	if (moveFlag)
	{
		animSpeed = 1.0f;			// モーションの速度を決める

		
		// 歩くはじめをゆっくりなるように処理
		if (walkSpeed < 10.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 10.0f;
		}
	}
	// 歩き状態でなかったら(止まり)
	else
	{
		animSpeed = 0.5f;			// モーションの速度を決める


		// ゆっくり停止するように処理
		if (walkSpeed > 0.0f)
		{
			walkSpeed -= 5.0f;
		}
		else
		{
			walkSpeed = 0.0f;
		}
	}


	// 操作のプロセスを呼ぶ
	OpeProcess();


	/// 操作に対する向きと動き--------------------------------------------------------------------------------------
	// 左方向に移動するフラッグが立っているとき
	if (m_direction[static_cast<int>(DIRECTION::left)])
	{
		// 左下向きに移動するフラッグが立っているとき
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// 左上向きに移動するフラッグが立っているとき
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// 真左に移動するとき
		else
		{
			area.x += cosf(-angle) * walkSpeed;
			area.z += sinf(-angle) * walkSpeed;
		}
	}
	// 右方向に移動するフラッグが立っているとき
	if (m_direction[static_cast<int>(DIRECTION::right)])
	{
		// 右下に移動するフラッグが立っているとき
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// 右上に移動するフラッグが立っているとき
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// 真右に移動するフラッグが立っているとき
		else
		{
			area.x += cosf(-angle) * -walkSpeed;
			area.z += sinf(-angle) * -walkSpeed;
		}
	}
	// 左と右への移動フラッグが立っていないとき
	if (!m_direction[static_cast<int>(DIRECTION::right)] && !m_direction[static_cast<int>(DIRECTION::left)])
	{
		// 下に移動するフラッグが立っているとき
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed;
			area.z += cosf(angle + direXAngle) * walkSpeed;
		}
		// 上に移動するフラッグが立っているとき
		if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;
		}
	}
	/// 操作に対する向きと動き--------------------------------------------------------------------------------------
} /// void Character::MoveProcess()



/// ----------------------------------------------------------------------------------------------------------------
void Character::OpeProcess()
{
	// 左スティックが前に押されたら前進する
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		m_direction[DIRECTION::up] = true;
		direXAngle = 0.0f;
		direZAngle = 0.0f;
		moveFlag = true;
		Player_PlayAnim(MOTION::walk);
	}
	// 左スティックが前に押されていない
	else
	{
		m_direction[DIRECTION::up] = false;
	}


	// 左スティックが後ろに押されたら後退する
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y))
	{
		m_direction[DIRECTION::down] = true;
		direXAngle = 0.0f;
		direZAngle = DX_PI_F;
		moveFlag = true;
		Player_PlayAnim(MOTION::walk);
	}
	// 左スティックが後ろに押されていない
	else
	{
		m_direction[DIRECTION::down] = false;
	}


	// 左スティックが左に押されたら左に移動する
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X))
	{
		m_direction[DIRECTION::left] = true;
		m_direction[DIRECTION::right] = false;
		
		
		// スティックの傾きで微調整
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber()
			, DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, false);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
		Player_PlayAnim(MOTION::walk);
	}
	// 左スティックが右に押されたら右に移動する
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = true;


		// スティックの傾きで微調整
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber()
			, DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, true);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
		Player_PlayAnim(MOTION::walk);
	}
	// 左スティックが左右どちらにも傾いていなかったら
	else
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = false;
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) == 0)
		{
			moveFlag = false;
			Player_PlayAnim(MOTION::idle);
		}
	}
} /// void Character::OpeProcess()



/// ----------------------------------------------------------------------------------------------------------------
Character::Character(const int modelHandle, const int collStageHandle, const int tex0, const int tex1
	, const int tex2, const int tex3) : BasicCreature(true)
{
	// あたり判定用ステージのコリジョン情報を設定する
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(stageHandle, -1);
	MV1SetFrameVisible(stageHandle, -1, false);
	MV1RefreshCollInfo(stageHandle, -1);


	// 足影判定用ステージのコリジョン情報を設定する
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(shadowStageHandle, -1);
	MV1SetFrameVisible(shadowStageHandle, -1, false);
	MV1RefreshCollInfo(shadowStageHandle, -1);


	// ３Ｄモデルの読み込み
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(modelHandle);
	

	// テクスチャ適応
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle3 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	textureHandle2 = tex2;
	textureHandle3 = tex3;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, true);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);


	// ３Ｄモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 160.0f;
	modelWidth = 50.0f;


	// モデルの向きと位置
	area = VGet(0.0f, 0.0f, 0.0f);
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;


	// 足元の影に関する
	shadowHeight = 35.0f;
	shadowSize = 50.0f;


	// それぞれの速度
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	ZeroMemory(m_direction, sizeof(m_direction));


	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, area);
} /// Character::Character(const int modelHandle, const int collStageHandle, const int tex0, const int tex1



/// ----------------------------------------------------------------------------------------------------------------
Character::~Character()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);

	MODEL_RELEASE(modelHandle);
	MODEL_RELEASE(shadowStageHandle);
	MODEL_RELEASE(stageHandle);
}



/// ----------------------------------------------------------------------------------------------------------------
void Character::Process(const float getAngle)
{
	// 直前の座標
	preArea = area;

	
	// 動いていたら
	if (moveFlag)
	{
		angle = getAngle;	// カメラ向きのアングルを渡す
	}


	// 動きのプロセス
	MoveProcess();


	// モーションの実態
	Player_AnimProcess();


	// ステージのあたり判定
	ActorHit(stageHandle);


	// 要らないけど不安なので一応
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}


	// 指定位置にモデルを配置
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void Character::Process(const float getAngle)



/// ----------------------------------------------------------------------------------------------------------------
void Character::OptionActorDrawAfter()
{
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
}



/// ----------------------------------------------------------------------------------------------------------------
void Character::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if(MyDebug::characterDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}
