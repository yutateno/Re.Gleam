#include "EnemyBossAfter.hpp"



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::MotionProcess()
{
	// 攻撃の時になったら
	if (attackMotionNow)
	{
		// 手を振りかざす攻撃だったら
		if (e_attackPattern == EAttackPattern::hand)
		{
			// アニメーションを設定する
			animSpeed = 0.05f;
			Player_PlayAnim(MOTION::attack);
			attackFrame += animSpeed;


			// モーションが終了したら
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attack) - 4)
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
		// 氷の柱を使う攻撃だったら
		else if (e_attackPattern == EAttackPattern::icePillar)
		{
			// アニメーションを設定する
			animSpeed = 0.4f;
			Player_PlayAnim(MOTION::attackMagic);
			attackFrame += animSpeed;


			// モーションが終了したら
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attackMagic))
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
		// 箱を使う攻撃だったら
		else if (e_attackPattern == EAttackPattern::magicBlock)
		{
			// アニメーションを設定する
			animSpeed = 0.1f;
			Player_PlayAnim(MOTION::attackMagic2);
			attackFrame += animSpeed;


			// モーションが終了したら
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attackMagic2))
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
	} /// if (attackMotionNow)
	// 攻撃しないとき
	else
	{
		// アニメーションを設定する
		animSpeed = 0.2f;
		Player_PlayAnim(MOTION::idleDevile);
	}
} /// void EnemyBossAfter::MotionProcess()



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::MoveProcess()
{

}



/// ----------------------------------------------------------------------------------------
EnemyBossAfter::EnemyBossAfter(const int modelHandle, const int modelTex0
	, const int modeltex1, const int modelTex2) : BasicCreature()
{
	// 3Dモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);

	
	// テクスチャの適応
	blendCount = 255;
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle0 = modelTex0;
	textureHandle1 = modeltex1;
	textureHandle2 = modelTex2;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 2, blendCount);
	MV1SetMaterialEmiColor(this->modelHandle, 0, GetColorF(1.0f, 1.0f, 1.0f, 1.0f));
	MV1SetMaterialEmiColor(this->modelHandle, 1, GetColorF(0.3f, 0.3f, 0.3f, 1.0f));
	MV1SetMaterialEmiColor(this->modelHandle, 2, GetColorF(0.3f, 0.3f, 0.3f, 1.0f));


	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::idleDevile;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// 初期化
	modelHeight = 4100.0f;
	modelWidth = 600.0f;
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	jumpUpNow = false;
	area = VGet(4300.0f, 200.0f, 0.0f);
	angle = DX_PI_F / 2.0f;
	MV1SetScale(this->modelHandle, VGet(25, 25, 25));


	// 攻撃
	moveCount = 0;
	attackFrame = 0.0f;
	attackDamageNow = false;
	attackStartNow = false;
	e_attackPattern = EAttackPattern::hand;
	e_preAttackPattern = EAttackPattern::hand;
	damageCount = 0;
	moveDoCount = 1000;


	// モデルの座標を更新
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, angle, 0.0f));
	MV1SetPosition(this->modelHandle, this->area);


	// コリジョン情報のセットアップ
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyBossAfter::EnemyBossAfter(const int modelHandle, const int modelTex0



/// ----------------------------------------------------------------------------------------
EnemyBossAfter::~EnemyBossAfter()
{
	// テクスチャ開放
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);


	// モデル開放
	MODEL_RELEASE(modelHandle);
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::Draw()
{
#ifdef _DEBUG
	if (MyDebug::enemyLastBossDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
	if (MyDebug::enemyLastBossAttackFlameDrawFlag)
	{
		DrawCapsule3D(VScale(VAdd(MV1GetFramePosition(modelHandle, 15), MV1GetFramePosition(modelHandle, 14)), 0.5)
			, VAdd(VScale(VAdd(MV1GetFramePosition(modelHandle, 15), MV1GetFramePosition(modelHandle, 14)), 0.5), VGet(0, 20, 0))
			, 350, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);

		DrawCapsule3D(VScale(VAdd(MV1GetFramePosition(modelHandle, 16), MV1GetFramePosition(modelHandle, 15)), 0.5)
			, VAdd(VScale(VAdd(MV1GetFramePosition(modelHandle, 16), MV1GetFramePosition(modelHandle, 15)), 0.5), VGet(0, 50, 0))
			, 460, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);

		DrawCapsule3D(VScale(VAdd(MV1GetFramePosition(modelHandle, 17), MV1GetFramePosition(modelHandle, 16)), 0.5)
			, VAdd(VScale(VAdd(MV1GetFramePosition(modelHandle, 17), MV1GetFramePosition(modelHandle, 16)), 0.5), VGet(0, 50, 0))
			, 360, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::DrawWhile()
{
	MV1DrawModel(modelHandle);
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::Process()
{
	attackStartNow = false;		// 攻撃をし始めてないとする


	// 300フレームに到達したら
	if (moveCount++ > moveDoCount)
	{
		// 前回とは違う攻撃をさせる
		while (e_preAttackPattern == e_attackPattern)
		{
			std::mt19937 mt(rnd());
			std::uniform_int_distribution<> attackPatternRnd(0, 2);        // 乱数
			e_attackPattern = static_cast<EAttackPattern>(attackPatternRnd(mt));
		}


		// 攻撃を実行させる
		e_preAttackPattern = e_attackPattern;
		attackStartNow = true;
		moveCount = 0;
		attackMotionNow = true;
	}


	// ダメージを受けたとき
	if (damageHit)
	{
		damageHit = false;
		damageCount++;

		// ダメージの数値
		if (damageCount >= 5)
		{
			moveDoCount = 600;
		}
		else if (damageCount >= 10)
		{
			moveDoCount = 400;
		}
		else if (damageCount >= 15)
		{
			moveDoCount = 200;
		}
	}


	// モーションの実態
	Player_AnimProcess();

	
	// モーションのプロセス
	MotionProcess();
} /// void EnemyBossAfter::Process()



/// ----------------------------------------------------------------------------------------
bool EnemyBossAfter::SetDeathBlendDraw()
{
	// モデルの透過値が0以上だったら
	if (blendCount >= 0)
	{
		blendCount -= 2;
	}
	// モデルが透過したら
	else
	{
		// 存在を消したことにする
		return true;
	}


	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 2, blendCount);


	return false;
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);


	switch (BASICPARAM::e_TextureColor)
	{
		// 通常色にする
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\normal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\normal.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\normal.pyn", textureHandle2, ELOADFILE::graph);
		break;
		// D型補正にする
	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\D.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\D.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\D.pyn", textureHandle2, ELOADFILE::graph);
		break;
		// P型補正にする
	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\P.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\P.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\P.pyn", textureHandle2, ELOADFILE::graph);
		break;
	default:
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\normal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\normal.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\normal.pyn", textureHandle2, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
} /// void EnemyBossAfter::TextureReload()



/// ----------------------------------------------------------------------------------------
std::thread EnemyBossAfter::ThsTextureReload()
{
	return std::thread(&EnemyBossAfter::TextureReload, this);
}
