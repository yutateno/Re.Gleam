#include "OrdinaryPerson.hpp"


// 動きのプロセス
void OrdinaryPerson::MoveProcess()
{
	animSpeed = 0.75f;			// モーションの速度を決める

	
	// 移動が直進方向だったら
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
	// 移動が斜め方向だったら
	else
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


	// 移動カウントが400以上だったらリセットする
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	//移動カウントが100だったら移動先を決める
	else if (moveCount == 100)
	{
		// ランダム数値取得
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
		std::uniform_int_distribution<> randInX(-200, 200);			// X座標用乱数
		std::uniform_int_distribution<> moveTurn(-200, 200);		// Z座標用乱数


		// 移動先を更新
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
	}


	// 移動先の向きと違ったら
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


	// 移動先の向きと違ったら
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
	Player_PlayAnim(MOTION::walk);
	moveCount++;		// 移動カウントを加算
	float tempX = area.x + sinf(direXAngle + direZAngle) * -walkSpeed;
	float tempZ = area.z + cosf(direXAngle + direZAngle) * -walkSpeed;
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
} /// void OrdinaryPerson::MoveProcess()


// 落下処理
void OrdinaryPerson::FallProcess()
{
	// 足元に何もなかったら
	if (fallCount > 1)
	{
		// 落下中じゃなかったら
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


	// 誤差で空中浮遊判定だったら
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// 飛んでいなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}
} /// void OrdinaryPerson::FallProcess()


// コンストラクタ
OrdinaryPerson::OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
	, const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// あたり判定用のステージのコリジョン情報の更新
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(stageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(stageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(stageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）


	// 足影判定用のステージのコリジョン情報の更新
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// ステージの座標を更新
	MV1SetupCollInfo(shadowStageHandle, -1);									// モデルのコリジョン情報をセットアップ(-1による全体フレーム)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）
	MV1RefreshCollInfo(shadowStageHandle, -1);								// ステージを描画させない（でもどうせDraw呼ばないからこれ意味ない気もする）


	// ３Ｄモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// テクスチャの適応
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);


	// ３Ｄモデルの0番目のアニメーションをアタッチする
	attachNum = MOTION::walk;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// アタッチしたアニメーションの総再生時間を取得する
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 160.0f;
	modelWidth = 50.0f;
	alive = false;
	aliveBlendCount = 0;


	// モデルの向きと位置
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireZAngle = 0.0f;
	nextDireXAngle = 0.0f;


	// 足元の影に関する
	shadowHeight = 20.0f;
	shadowSize = 50.0f;


	// それぞれの速度
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	moveCount = 0;
	jumpUpNow = false;


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
} /// OrdinaryPerson::OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
/// , const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)



// デストラクタ
OrdinaryPerson::~OrdinaryPerson()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle0);


	// 階段と床解放
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


	// 影用ステージハンドル開放
	MODEL_RELEASE(shadowStageHandle);


	// あたり判定用ステージハンドル開放
	MODEL_RELEASE(stageHandle);
} /// OrdinaryPerson::~OrdinaryPerson()


// メインプロセス
void OrdinaryPerson::Process()
{
	// 生存を許してないとき
	if (!alive) return;


	preArea = area;		// 直前の座標


	// 動きのプロセス
	MoveProcess();


	// モーションの実態
	Player_AnimProcess();


	int setCollHitNum = 0;		// あたり判定の個数がいくつか


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


	// ステージのあたり判定
	ActorHit(stageHandle);

	
	// 落下のプロセス
	FallProcess();


	// 第二引数の回転角度をセット
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	// 指定位置にモデルを配置
	MV1SetPosition(modelHandle, area);
} /// void OrdinaryPerson::Process()


// 一般人のテクスチャ差し替え
void OrdinaryPerson::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\D\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\P\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\move4\\一般人＿その１\\human1_motionALL.fbm\\normal\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}


// 生存を許されたら座標を決める
void OrdinaryPerson::SetAlive(VECTOR area, bool alive)
{
	this->area = area;
	this->alive = alive;
}


// 描画
void OrdinaryPerson::Draw()
{
	// 生存を許してないとき
	if (!alive) return;


	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if(MyDebug::ordinaryDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
	}
#endif // _DEBUG
}
