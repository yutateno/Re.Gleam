#include "EnemyMove4.hpp"


// モーションプロセス
void EnemyMove4::MotionProcess()
{
	// プレイヤーとの距離が攻撃範囲内でキャラクターを視認していたら
	if (playerCharaDistance <= 200 && charaLookAt)
	{
		Player_PlayAnim(MOTION::attack);
		attackFrame += animSpeed;
		if (attackFrame >= MV1GetAnimTotalTime(modelHandle, MOTION::attack))
		{
			attackDamageNow = true;
			attackFrame = 0.0f;
		}
		else
		{
			attackDamageNow = false;
		}
	}
	// プレイヤーと合い関せずだったら
	else
	{
		Player_PlayAnim(MOTION::idle);
	}
}


// 自動的に動く
void EnemyMove4::AutoMoveProcess()
{
	// 直線方向だったら
	if (direXAngle == 0.0f)
	{
		// 移動速度が最大値より低かったら加算
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
		// 移動速度が最大値より低かったら加算
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	// 移動カウントが400以上だったら
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	// 移動カウントが100だったら
	else if (moveCount == 100)
	{
		// ランダム数値取得
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
		std::uniform_int_distribution<> randInX(-200, 200);			// X座標用乱数
		std::uniform_int_distribution<> moveTurn(-200, 200);				// Z座標用乱数


		// 移動先を更新
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		if (nextDireZAngle != 0.0f)
		{
			nextDireXAngle = -nextDireXAngle;
		}

	}


	// 移動先の方向と違ったら
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
	// ステージ外に向かっていたら乱数を再暗算
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		area.x += sinf(direXAngle + direZAngle) * walkSpeed * 2.0f;
		area.z += cosf(direXAngle + direZAngle) * walkSpeed * 2.0f;
		moveCount = 100;
		return;
	}
	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;
} /// void EnemyMove4::AutoMoveProcess()


// プレイヤーを追いかける
void EnemyMove4::ChaseMoveProcess()
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


// 落下処理
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
		walkSpeed = 10.0f;
		animSpeed = 1.0f;
		jumpPower -= gravity;			// 落下重力を加え続ける
		area.y += jumpPower;			// Y座標に加え続ける


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


// コンストラクタ
EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
	, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
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


	// テクスチャの適応
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, true);


	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// アタッチしたアニメーションの総再生時間を取得する
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 130.0f;
	modelWidth = 70.0f;


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
	shadowHeight = 65.0f;
	shadowSize = 35.0f;


	// それぞれの速度
	walkSpeed = 6.0f;
	animSpeed = 0.75f;
	jumpUpNow = false;


	// 攻撃
	attackFrame = 0;
	attackDamageNow = false;


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

	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
/// , const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)


// デストラクタ
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


// 描画
void EnemyMove4::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	/*static float aaaaaaaaaaaaaaa = modelHeight;
	static float bbbbbbbbbbbbbb = modelWidth;
	if (CheckHitKey(KEY_INPUT_Y) == 1)
	{
		aaaaaaaaaaaaaaa += 0.1f;
	}
	if (CheckHitKey(KEY_INPUT_H) == 1)
	{
		aaaaaaaaaaaaaaa -= 0.1f;
	}
	if (CheckHitKey(KEY_INPUT_U) == 1)
	{
		bbbbbbbbbbbbbb += 0.1f;
	}
	if (CheckHitKey(KEY_INPUT_J) == 1)
	{
		bbbbbbbbbbbbbb -= 0.1f;
	}*/
	if (MyDebug::enemyThreeCrayonHumanDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
	}

	if (MyDebug::enemyThreeCrayonHumanSearchLineDrawFlag)
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
} /// void EnemyMove4::Draw()


// プロセス
void EnemyMove4::Process()
{
	// 直前の座標
	preArea = area;


	// プレイヤーを視認できる距離じゃなかったら
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();
	}
	// プレイヤーを視認できる距離だったら
	else
	{
		// プレイヤーを視認したら
		if (charaLookAt)
		{
			ChaseMoveProcess();
		}
		// プレイヤーを視認したら
		else
		{
			AutoMoveProcess();
		}
	}


	MotionProcess();		// モーションプロセス


	Player_AnimProcess();	// モーション実態


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


	// 要らないけど不安なので一応
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}


	// プレイヤーを視認できる方向
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);


	// プレイヤーを視認出来たら
	if (fabsf(charaLookAtAngle) + (DX_PI_F / 6) > fabsf(direXAngle + direZAngle)
		&& fabsf(charaLookAtAngle) - (DX_PI_F / 6) < fabsf(direXAngle + direZAngle)
		&& playerCharaDistance <= 1500)
	{
		direXAngle = 0.0f;
		direZAngle = charaLookAtAngle;
		charaLookAt = true;
	}
	// プレイヤーを視認できなかったら
	else
	{
		charaLookAt = false;
	}


	// プレイヤーをロックオンしていたら
	if (charaLookAt)
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle, 0.0f));
	}
	// プレイヤーをロックオンしていなかったら
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	}


	// 指定位置にモデルを配置
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove4::Process()


// テクスチャ差し替え
void EnemyMove4::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\D\\D.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\P\\P.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\人（敵）\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, true);
}


// プレイヤーの位置と距離を取得する
void EnemyMove4::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
