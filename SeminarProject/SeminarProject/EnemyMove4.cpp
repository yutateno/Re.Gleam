#include "EnemyMove4.hpp"



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::MotionProcess()
{
	// 死んでいなかったら
	if (!deathFlag)
	{
		// サイズが大きいときだったら
		if (damageCount <= bigBodyChangeDamage)
		{
			Player_PlayAnim(MOTION::idle);
		}
		// サイズが小さくなったら
		else
		{
			// プレイヤーとの距離が攻撃範囲内でキャラクターを視認していたら
			if (playerCharaDistance <= 200)
			{
				// ダメージを受けているとき
				if (damageHit)
				{
					Player_PlayAnim(MOTION::damage);
				}
				// ダメージを受けていないとき
				else
				{
					Player_PlayAnim(MOTION::attack);


					attackFrame += animSpeed;
					
					
					// 攻撃が終わったら
					if (attackFrame >= MV1GetAnimTotalTime(modelHandle, MOTION::attack))
					{
						// フレームを初期化し、ダメージを反映させる
						attackDamageNow = true;
						attackFrame = 0.0f;
					}
					// 攻撃中だったら
					else
					{
						// ダメージを反映させない
						attackDamageNow = false;
					}
				}
			}
			// プレイヤーと合い関せずだったら
			else
			{
				Player_PlayAnim(MOTION::dash);
			}
		}
	}
	// 死んでいたら
	else
	{
		Player_PlayAnim(MOTION::death);
	}
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::ChaseMoveProcess()
{
	// キャラクターに近づく
	walkSpeed = 14.0f;
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



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::FallProcess()
{
	// 足元に何もなかったら
	if (fallCount > 1)
	{
		// 落下していなかったら
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
		animSpeed = 1.0f;
		jumpPower -= gravity;			// 落下重力を加え続ける
		area.y += jumpPower;			// Y座標に加え続ける


		// 落下させる
		area.y -= 10.5f;
	}


	// 着地しているとき
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
} /// void EnemyMove4::FallProcess()



/// ------------------------------------------------------------------------------------------------
EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle
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
	MV1SetScale(this->modelHandle, VGet(static_cast<float>(bigBodyChangeDamage)
		, static_cast<float>(bigBodyChangeDamage)
		, static_cast<float>(bigBodyChangeDamage)));

	// テクスチャの適応
	blendCount = 255;
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);


	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::dash;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// アタッチしたアニメーションの総再生時間を取得する
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 130.0f * bigBodyChangeDamage;
	modelWidth = 70.0f *  bigBodyChangeDamage / 4;


	// モデルの向きと位置
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireXAngle = 0.0f;
	nextDireZAngle = 0.0f;
	playerCharaArea = VGet(0, 0, 0);
	playerCharaDistance = 3000;
	moveCount = 0;


	// 足元の影に関する
	shadowHeight = 1.0f;
	shadowSize = 35.0f * bigBodyChangeDamage;


	// それぞれの速度
	walkSpeed = 14.0f;
	animSpeed = 0.5f;
	jumpUpNow = false;


	// 攻撃
	attackFrame = 0;
	attackDamageNow = false;
	damageCount = 0;


	// 階段
	v_stairsHandle.clear();
	if (BASICPARAM::stairsNum != 0)
	{
		v_stairsHandle.resize(BASICPARAM::stairsNum);


		// コリジョン情報の設定
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


		// コリジョン情報の設定
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
	MV1SetPosition(this->modelHandle, this->area);


	// 当たり判定のセットアップ
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle



/// ------------------------------------------------------------------------------------------------
EnemyMove4::~EnemyMove4()
{
	// テクスチャ解放
	GRAPHIC_RELEASE(textureHandle0);


	// 階段と床開放
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}

	
	// 階段開放
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}

	
	// モデル開放
	MODEL_RELEASE(modelHandle);


	// 足影用ステージ開放
	MODEL_RELEASE(shadowStageHandle);


	// 当たり判定用ステージ開放
	MODEL_RELEASE(stageHandle);
} /// EnemyMove4::~EnemyMove4()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if (MyDebug::enemyFourEnemyDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}

	if (MyDebug::enemyFourEnemySearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
		}
	}
#endif // _DEBUG
} /// void EnemyMove4::Draw()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::UniqueModelDraw()
{
	MV1DrawModel(modelHandle);
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::Process()
{
	// 消滅していたら
	if (eraseExistence) return;


	// 死んだとき
	if (deathFlag)
	{
		MotionProcess();			// モーションプロセス


		Player_AnimProcess();		// モーションの実態


		// 透過値が0以上だったら
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		else
		{
			eraseExistence = true;
		}


		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
		return;
	}


	// 直前の座標
	preArea = area;


	// サイズが小さかったら
	if (damageCount > bigBodyChangeDamage)
	{
		ChaseMoveProcess();		// プレイヤーを追う
	}


	MotionProcess();			// モーションプロセス


	Player_AnimProcess();		// モーション実態


	// 死んでいないがダメージを受けたら
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -28.0f;


		// モデルの大きさとそれに伴うあたり判定の更新
		if (damageCount <= bigBodyChangeDamage)
		{
			shadowHeight = 65.0f * (1 + bigBodyChangeDamage - damageCount);
			shadowSize = 35.0f * (1 + bigBodyChangeDamage - damageCount);
			MV1SetScale(modelHandle, VGet(static_cast<float>((1 + bigBodyChangeDamage - damageCount))
				, static_cast<float>(1 + (bigBodyChangeDamage - damageCount)), static_cast<float>((1 + bigBodyChangeDamage - damageCount))));
			modelHeight = 130.0f * (1 + bigBodyChangeDamage - damageCount);
			modelWidth = 70.0f * (1 + (bigBodyChangeDamage / 4) - (damageCount / 4));
			MV1RefreshCollInfo(modelHandle, -1);
		}


		// 死ぬくらいダメージを受けたら
		if (++damageCount >= 50)
		{
			deathFlag = true;
		}
	}


	int setCollHitNum = 0;		// 当たり判定の個数所持


	// 階段と床のあたり判定
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// どこにもあたっていなかったら
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


	// プレイヤーを常に視認してモデルを配置
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove4::Process()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\move4\\人（敵）\\ene_human_motionALL.fbm\\D\\D.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\move4\\人（敵）\\ene_human_motionALL.fbm\\P\\P.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, true);
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
