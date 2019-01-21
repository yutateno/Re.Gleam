#include "EnemyMove5.hpp"


// モーションのプロセス
void EnemyMove5::MotionProcess()
{
	// 死んでいなかったら
	if (!deathFlag)
	{
		Player_PlayAnim(MOTION::dash);
	}
	// 死んだら
	else
	{
		Player_PlayAnim(MOTION::death);
	}
} /// void EnemyMove3CrayonHuman::MotionProcess()


// 自動的な動きプロセス
void EnemyMove5::AutoMoveProcess()
{
	// 直前方向だったら
	if (direXAngle == 0.0f)
	{
		// 移動速度最大値より低かったら
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
		// 移動速度最大値より低かったら
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	// 動いているカウントが400以上だったら
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	// 動いているカウントが100だったら
	else if (moveCount == 100)
	{
		// 欄数値取得
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
		std::uniform_int_distribution<> randInX(-200, 200);			// X座標用乱数
		std::uniform_int_distribution<> moveTurn(-200, 200);				// Z座標用乱数


		// 次の移動先を決定
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
	}


	// 次の移動先と今の値が違ったら
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


	// 移動方向に動かす
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
	// ステージ外に向かっていたら乱数を再暗算
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
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
} /// void EnemyMove3CrayonHuman::AutoMoveProcess()


// プレイヤーから逃げるプロセス
void EnemyMove5::EscapeMoveProcess()
{
	walkSpeed = -7.0f;		// 移動速度を早めに設定


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
} /// void EnemyMove3CrayonHuman::ChaseMoveProcess()


// 落下処理
void EnemyMove5::FallProcess()
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
} /// void EnemyMove3CrayonHuman::FallProcess()


/// -----------------------------------------------------------------------------------------
EnemyMove5::EnemyMove5(const int modelHandle, const int collStageHandle
	, const int stairsHandle, const int stairsRoadHandle, const int tex0
	, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// 当たり判定用ステージのコリジョン情報の更新
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(stageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(stageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(stageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）


	// 足影用ステージのコリジョン情報の更新
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
	MV1SetScale(this->modelHandle, VGet(0.5f, 0.5f, 0.5f));


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
	modelHeight = 96.0f;
	modelWidth = 35.0f;


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
	shadowHeight = 48.0f;
	shadowSize = 17.0f;


	// それぞれの速度
	walkSpeed = 6.0f;
	animSpeed = 0.75f;
	jumpUpNow = false;


	// 攻撃
	attackFrame = 0;
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


	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, this->area);


	// アクター同士のあたり判定のセットアップ
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove3CrayonHuman::EnemyMove3CrayonHuman(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
/// , const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)


// デストラクタ
EnemyMove5::~EnemyMove5()
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


	// モデル開放
	MODEL_RELEASE(modelHandle);


	// 足影用ステージハンドル開放
	MODEL_RELEASE(shadowStageHandle);


	// 当たり判定ステージハンドル開放
	MODEL_RELEASE(stageHandle);
} /// EnemyMove3CrayonHuman::~EnemyMove3CrayonHuman()


// 描画
void EnemyMove5::Draw()
{
	if (deathFlag || eraseExistence) return;


	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if (MyDebug::enemyFifthEnemyDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
	}

	if (MyDebug::enemyFifthEnemySearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
			if (charaLookAt)
			{
				DrawLine3D(playerCharaArea, area, GetColor(0, 255, 0));
			}
			if (playerCharaDistance <= 200)
			{
				DrawLine3D(playerCharaArea, area, GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG
}


// プロセス
void EnemyMove5::Process()
{
	// 消滅していたら
	if (eraseExistence) return;


	// 死んだとき
	if (deathFlag)
	{
		MotionProcess();	// モーションプロセス


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


		return;
	}


	// 画面外にいたら処理させない
	if (notViewCount > 3) return;


	// 直前の座標
	preArea = area;


	// プレイヤーとの距離が索敵外だったら
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();		// 自動的に動かす
	}
	// プレイヤーとの距離が索敵内だったら
	else
	{
		// プレイヤーを視認できていたら
		if (--escapeFrame > 0)
		{
			EscapeMoveProcess();		// プレイヤーを追いかける
		}
		// プレイヤーを視認できていなかったら
		else
		{
			AutoMoveProcess();		// 自動的に動く
		}
	}


	MotionProcess();		// モーションのプロセス


	Player_AnimProcess();		// モーションの実態


	// ダメージを受けて死んでいないとき
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		deathFlag = true;
	}


	int setCollHitNum = 0;		// 当たり判定の個数を得る


	// 階段と床のあたり判定
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// どこにもあたっていなかったら
	if (setCollHitNum == 0)
	{
		// 階段のあたり判定処理
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	ActorHit(stageHandle);	// ステージのあたり判定


	FallProcess();	// 落下のプロセス


	// プレイヤーを視認できる角度
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);


	// プレイヤーを視認出来たら
	if (fabsf(charaLookAtAngle) + (DX_PI_F / 4) > fabsf(direXAngle + direZAngle)
		&& fabsf(charaLookAtAngle) - (DX_PI_F / 4) < fabsf(direXAngle + direZAngle)
		&& playerCharaDistance <= 1500)
	{
		direXAngle = DX_PI_F;
		direZAngle = charaLookAtAngle;
		charaLookAt = true;
		escapeFrame = 10;
	}
	// プレイヤーを視認できなかったら
	else
	{
		charaLookAt = false;
	}


	// プレイヤーを視認していたら
	if (charaLookAt)
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle + DX_PI_F, 0.0f));			// プレイヤーを向く方に回転させる
	}
	// プレイヤーを視認できなかったら
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	}


	// 指定位置にモデルを配置
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove3CrayonHuman::Process()


// テクスチャを差し替える
void EnemyMove5::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\kureyon_,motionALL.fbm\\normal\\SDchar.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\kureyon_,motionALL.fbm\\D\\SDchar.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\kureyon_,motionALL.fbm\\P\\SDchar.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\childCLPH\\sd_,motionALL.fbm\\kureyon_,motionALL.fbm\\normal\\SDchar.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}/// void EnemyMove3CrayonHuman::TextureReload()


// プレイヤーの位置と距離を取得する
void EnemyMove5::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
