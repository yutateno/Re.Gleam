#include "EnemyMove3Slime.hpp"



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::MotionProcess()
{
	// プレイヤーとの距離が攻撃範囲だったら
	if (playerCharaDistance <= 250)
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::attack);
		attackFrame += animSpeed;


		// 攻撃モーション中だったら
		if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attack))
		{
			attackDamageNow = true;
			attackFrame = 0.0f;
		}
		else
		{
			attackDamageNow = false;
		}
	}
	// プレイヤーとの距離が攻撃範囲外だったら
	else
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::idle);
	}
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::AutoMoveProcess()
{
	// 直線方向だったら
	if (direXAngle == 0.0f)
	{
		// 移動速度が最大値より小さかったら
		if (walkSpeed < 6.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 6.0f;
		}
	}
	// 斜め方向だったら
	else
	{
		// 移動速度が最大値より小さかったら
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	// 移動したカウントが400以上だったら
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	// 移動したカウントが100だったら
	else if (moveCount == 100)
	{
		// ランダム数値取得
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-200, 200);			// X座標用乱数
		std::uniform_int_distribution<> moveTurn(-200, 200);		// Z座標用乱数


		// 移動先を更新する
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		
	}


	// 移動先方向と異なっていたら
	if (nextDireXAngle != direXAngle)
	{
		if (direXAngle > nextDireXAngle)
		{
			direXAngle -= 0.01f;
		}
		else
		{
			direXAngle += 0.01f;
		}
	}
	if (nextDireZAngle != direZAngle)
	{
		if (direZAngle > nextDireZAngle)
		{
			direZAngle -= 0.01f;
		}
		else
		{
			direZAngle += 0.01f;
		}
	}


	// 移動させる
	moveCount++;		// 移動カウントを加算
	float tempX = area.x + sinf(direXAngle + direZAngle) * -walkSpeed;
	float tempZ = area.z + cosf(direXAngle + direZAngle) * -walkSpeed;


	// どうしようもなくなったら初期値に戻す
	if (area.y < -10)
	{
		area = VGet(0, 0, 0);
		moveCount = 100;
		return;
	}


	// ステージ外に行ったら
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-4000, 4000);        // X座標用乱数
		std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z座標用乱数
		// X座標設定
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 200.0f && tempX >= 0.0f)
		{
			tempX += 200.0f;
		}
		if (tempX >= -200.0f && tempX <= 0.0f)
		{
			tempX -= 200.0f;
		}
		// Y座標設定
		float tempZ = static_cast<float>(randInZ(mt));
		if (tempZ <= 200.0f && tempZ >= 0.0f)
		{
			tempZ += 200.0f;
		}
		if (tempZ >= -200.0f && tempZ <= 0.0f)
		{
			tempZ -= 200.0f;
		}
		area = VGet(tempX, 0, tempZ);
		moveCount = 100;
		return;
	}
	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;
} /// void EnemyMove3Slime::AutoMoveProcess()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::ChaseMoveProcess()
{
	walkSpeed = 7.0f;
	// キャラクターに近づく
	if (playerCharaArea.x < area.x - walkSpeed + 2.0f)
	{
		area.x -= walkSpeed;
	}
	else if (playerCharaArea.x > area.x + walkSpeed + 2.0f)
	{
		area.x += walkSpeed;
	}
	if (playerCharaArea.z < area.z - walkSpeed + 2.0f)
	{
		area.z -= walkSpeed;
	}
	else if (playerCharaArea.z > area.z + walkSpeed + 2.0f)
	{
		area.z += walkSpeed;
	}
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::DamageProcess()
{
	// 死んでいないがダメージを受けたら
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -3.0f;


		// 死ぬくらいダメージを受けたら
		if (++damageCount >= 3)
		{
			deathFlag = true;
		}
	}
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::FallProcess()
{
	// 足元に何もなかったら
	if (fallCount > 1)
	{
		// 落ちていなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}


	// 落下している
	if (jumpNow)
	{
		flyCount++;
		preJumpNow = true;
		walkSpeed = 10.0f;
		animSpeed = 1.0f;
		jumpPower -= gravity;			// 落下重力を加え続ける
		area.y += jumpPower;			// Y座標に加え続ける


		area.y -= 10.5f;
	}


	// 着地していたら
	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;
	}


	// 誤差で空中浮遊していたら
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// 落下していなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}
} /// void EnemyMove3Slime::FallProcess()



/// --------------------------------------------------------------------------------------
EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle
	, const int stairsHandle, const int stairsRoadHandle, const int tex0
	, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// 当たり判定用ステージのコリジョン情報の設定
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(stageHandle, -1);
	MV1SetFrameVisible(stageHandle, -1, false);
	MV1RefreshCollInfo(stageHandle, -1);


	// 足影用ステージのコリジョン情報の設定
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(shadowStageHandle, -1);
	MV1SetFrameVisible(shadowStageHandle, -1, false);
	MV1RefreshCollInfo(shadowStageHandle, -1);


	// 3Dモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// テクスチャの適応
	blendCount = 255;
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 50.0f;
	modelWidth = 140.0f;


	// モデルの向きと位置
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireXAngle = 0.0f;
	nextDireZAngle = 0.0f;
	playerCharaArea = VGet(0, 0, 0);
	playerCharaDistance = 0;
	moveCount = 0;
	

	// 足元の影に関する
	shadowHeight = 1.0f;
	shadowSize = 140.0f;


	// それぞれの速度
	walkSpeed = 6.0f;
	animSpeed = 0.45f;
	jumpUpNow = false;


	// 攻撃
	attackFrame = 0.0f;
	attackDamageNow = false;
	damageCount = 0;


	// 階段
	v_stairsHandle.clear();
	if (BASICPARAM::stairsNum != 0)
	{
		v_stairsHandle.resize(BASICPARAM::stairsNum);


		// 階段のコリジョン情報を設定
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			v_stairsHandle[i] = MV1DuplicateModel(stairsHandle);
			MV1SetRotationXYZ(v_stairsHandle[i], VGet(0.0f, BASICPARAM::v_stairsAngle[i], 0.0f));
			MV1SetPosition(v_stairsHandle[i], BASICPARAM::v_stairsArea[i]);
			MV1SetupCollInfo(v_stairsHandle[i], -1);
			MV1SetFrameVisible(v_stairsHandle[i], -1, false);
			MV1RefreshCollInfo(v_stairsHandle[i], -1);
		}
	}


	// 階段と床
	v_stairsRoadHandle.clear();
	if (BASICPARAM::stairsRoadNum != 0)
	{
		v_stairsRoadHandle.resize(BASICPARAM::stairsRoadNum);


		// 階段と床のコリジョン情報を設定
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			v_stairsRoadHandle[i] = MV1DuplicateModel(stairsRoadHandle);
			MV1SetRotationXYZ(v_stairsRoadHandle[i], VGet(0.0f, BASICPARAM::v_stairsRoadAngle[i], 0.0f));
			MV1SetPosition(v_stairsRoadHandle[i], BASICPARAM::v_stairsRoadArea[i]);
			MV1SetupCollInfo(v_stairsRoadHandle[i], -1);
			MV1SetFrameVisible(v_stairsRoadHandle[i], -1, false);
			MV1RefreshCollInfo(v_stairsRoadHandle[i], -1);
		}
	}


	// モデルの座標を更新
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, rotationY, 0.0f));
	MV1SetPosition(this->modelHandle, this->area);


	// コリジョン情報のセットアップ
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle



/// --------------------------------------------------------------------------------------
EnemyMove3Slime::~EnemyMove3Slime()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle0);


	// 階段と床の解放
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}


	// 階段の解放
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}


	// モデルの解放
	MODEL_RELEASE(modelHandle);


	// 足影用ステージの解放
	MODEL_RELEASE(shadowStageHandle);


	// 当たり判定用ステージの解放
	MODEL_RELEASE(stageHandle);
} /// EnemyMove3Slime::~EnemyMove3Slime()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::Draw()
{
	// 死んでいるか存在を許されていなかったら
	if (deathFlag || eraseExistence) return;


	// 画面外にいたら処理させない
	if (notViewCount > 3) return;


	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if (MyDebug::enemyThreeSlimeDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
	if (MyDebug::enemyThreeSlimeSearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
			if (playerCharaDistance <= 250)
			{
				DrawLine3D(playerCharaArea, area, GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::Process()
{
	if (eraseExistence) return;


	// 死んだとき
	if (deathFlag)
	{	
		// 透過値が0以上だったら
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		// 消失したら
		else
		{
			eraseExistence = true;
		}


		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		return;
	}


	// 画面外だったら処理させない
	if (notViewCount > 3) return;


	// 直前の座標
	preArea = area;


	// プレイヤーの索敵範囲外だったら
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();
	}
	// プレイヤーの索敵範囲内だったら
	else
	{
		ChaseMoveProcess();
	}

	MotionProcess();	// モーションプロセス


	Player_AnimProcess();		// モーションの実態

	
	DamageProcess();		// ダメージのプロセス


	int setCollHitNum = 0;		// 当たり判定個数を取得


	// 階段と床のあたり判定
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// どこにもぶつかっていなかったら
	if (setCollHitNum == 0)
	{
		// 階段のあたり判定
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	ActorHit(stageHandle);	// ステージのあたり判定


	FallProcess();	// 落下のプロセス


	// 指定位置にモデルを配置
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove3Slime::Process()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\D\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\P\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}



/// --------------------------------------------------------------------------------------
std::thread EnemyMove3Slime::ThsTextureReload()
{
	return std::thread(&EnemyMove3Slime::TextureReload, this);
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	// 画面外にいたら処理させない
	if (notViewCount > 3) return;


	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
