#include "EnemyMove3Slime.hpp"


void EnemyMove3Slime::MotionProcess()
{
	if (playerCharaDistance <= 250)
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::attack);
		attackFrame += animSpeed;
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
	else
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::idle);
	}
}


void EnemyMove3Slime::AutoMoveProcess()
{
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-200, 200);			// X座標用乱数
	std::uniform_int_distribution<> moveTurn(0, 314);				// Z座標用乱数

	moveCount++;

	// スムーズに動かせる
	if (direXAngle == 0.0f)
	{
		if (walkSpeed < 6.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 6.0f;
		}
	}
	else	// 斜め方向
	{
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	else if (moveCount == 100)
	{
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		if (nextDireZAngle != 0.0f)
		{
			nextDireXAngle = -nextDireXAngle;
		}
		
	}

	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;

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
}


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
	else {}
	if (playerCharaArea.z < area.z - walkSpeed + 2.0f)
	{
		area.z -= walkSpeed;
	}
	else if (playerCharaArea.z > area.z + walkSpeed + 2.0f)
	{
		area.z += walkSpeed;
	}
	else {}
}


void EnemyMove3Slime::FallProcess()
{
	// 足元に何もなかったら
	if (fallCount > 1)
	{
		// 飛ぶコマンドで飛んでいなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}


	// 飛んでいる
	if (jumpNow)
	{
		flyCount++;
		preJumpNow = true;
		walkSpeed = 10.0f;
		animSpeed = 1.0f;
		jumpPower -= gravity;			// 落下重力を加え続ける
		area.y += jumpPower;			// Y座標に加え続ける


		// ジャンプにて最頂点に到達したら
		if (jumpPower <= flyJumpPower / 2.0f)
		{
			jumpUpNow = false;			// 落下に切り替える

			//// 地面に触れたら
			//if (fallCount <= 1)
			//{
			//	if (CheckHitKey(KEY_INPUT_G) >= 1)
			//	{
			//		printfDx("asdas\n");
			//	}
			//	jumpPower = 0.0f;
			//	jumpUpNow = false;
			//}
		}


		area.y -= 10.5f;
	}


	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;
	}


	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// 飛ぶコマンドで飛んでいなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}
}


EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
	, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// ステージのコリジョン情報の更新
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(stageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(stageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(stageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）

	// ステージのコリジョン情報の更新
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(shadowStageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(shadowStageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）

	// 3Dモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);

	// テクスチャの適応
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);

	// アタッチしたアニメーションの総再生時間を取得する
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

	// 攻撃
	attackFrame = 0.0f;
	attackDamageNow = false;
	damageCount = 0;

	// 階段
	v_stairsHandle.clear();
	if (BASICPARAM::stairsNum != 0)
	{
		v_stairsHandle.resize(BASICPARAM::stairsNum);
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			v_stairsHandle[i] = MV1DuplicateModel(stairsHandle);
			MV1SetRotationXYZ(v_stairsHandle[i], VGet(0.0f, BASICPARAM::v_stairsAngle[i], 0.0f));
			MV1SetPosition(v_stairsHandle[i], BASICPARAM::v_stairsArea[i]);				// ステージの座標を更新
			MV1SetupCollInfo(v_stairsHandle[i], -1);						// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
			MV1SetFrameVisible(v_stairsHandle[i], -1, false);				// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
			MV1RefreshCollInfo(v_stairsHandle[i], -1);
		}
	}

	// 階段と床
	v_stairsRoadHandle.clear();
	if (BASICPARAM::stairsRoadNum != 0)
	{
		v_stairsRoadHandle.resize(BASICPARAM::stairsRoadNum);
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			v_stairsRoadHandle[i] = MV1DuplicateModel(stairsRoadHandle);
			MV1SetRotationXYZ(v_stairsRoadHandle[i], VGet(0.0f, BASICPARAM::v_stairsRoadAngle[i], 0.0f));
			MV1SetPosition(v_stairsRoadHandle[i], BASICPARAM::v_stairsRoadArea[i]);				// ステージの座標を更新
			MV1SetupCollInfo(v_stairsRoadHandle[i], -1);						// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
			MV1SetFrameVisible(v_stairsRoadHandle[i], -1, false);				// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
			MV1RefreshCollInfo(v_stairsRoadHandle[i], -1);
		}
	}

	// 第二引数の回転角度をセット
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, rotationY, 0.0f));
	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, this->area);

	MV1SetupCollInfo(this->modelHandle, -1);
}


EnemyMove3Slime::~EnemyMove3Slime()
{
	GRAPHIC_RELEASE(textureHandle0);

	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}

	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}

	MODEL_RELEASE(modelHandle);
	MODEL_RELEASE(shadowStageHandle);
	MODEL_RELEASE(stageHandle);
}


void EnemyMove3Slime::Draw()
{
	if (deathFlag || eraseExistence) return;

	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if (MyDebug::enemyThreeSlimeDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
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


void EnemyMove3Slime::Process()
{
	if (eraseExistence) return;

	// 死んだとき
	if (deathFlag)
	{	
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		else
		{
			eraseExistence = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);

		return;
	}

	if (notViewCount > 3) return;

	// 直前の座標
	preArea = area;


	// 動きのプロセス
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();
	}
	else
	{
		ChaseMoveProcess();
	}

	MotionProcess();

	// モーション
	Player_AnimProcess();
	
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -3.0f;
		if (++damageCount >= 3.0f)
		{
			deathFlag = true;
		}
	}

	int setCollHitNum = 0;

	// 階段と床のあたり判定
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}

	// 階段のあたり判定
	if (setCollHitNum == 0)
	{
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}

	// ステージのあたり判定
	ActorHit(stageHandle);

	// 落下のプロセス
	FallProcess();

	// 要らないけど不安なので一応
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}

	// 第二引数の回転角度をセット
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	// 指定位置にモデルを配置
	MV1SetPosition(modelHandle, area);
}

void EnemyMove3Slime::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\D\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\P\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\move3\\インクスライム\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}

void EnemyMove3Slime::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
