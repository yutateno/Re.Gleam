#include "EnemyMove3Slime.hpp"


void EnemyMove3Slime::MoveProcess()
{
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(0, 200);			// X座標用乱数
	std::uniform_int_distribution<> moveTurn(0, 314);				// Z座標用乱数

	moveCount++;

	// スムーズに動かせる
	if (moveFlag)
	{
		animSpeed = 0.75f;
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
	}
	else
	{
		animSpeed = 0.5f;
		if (walkSpeed > 0.0f)
		{
			walkSpeed -= 3.0f;
		}
		else
		{
			walkSpeed = 0.0f;
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

	area.x += sinf(angle + direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(angle + direXAngle + direZAngle) * -walkSpeed;
	moveFlag = true;
	Player_PlayAnim(MOTION::idle);

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

	if (area.x > 4000 || area.x < -4000
		|| area.z > 4000 || area.z < -4000)
	{
		moveCount = 100;
		nextDireXAngle = direXAngle;
		nextDireZAngle = direZAngle;
	}
}


EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle, const int tex0, const VECTOR area)
{
	// 3Dモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);

	// テクスチャの適応
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);

	// 3Dモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);

	// アタッチしたアニメーションの総再生時間を取得する
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 50.0f;
	modelWigth = 140.0f;

	// モデルの向きと位置
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireXAngle = 0.0f;
	nextDireZAngle = 0.0f;
	
	// 足元の影に関する
	shadowHeight = 25.0f;
	shadowSize = 70.0f;

	// それぞれの速度
	walkSpeed = 0.0f;
	animSpeed = 0.25f;

	// 階段
	v_stairsHandle.clear();
	this->v_stairsHandle.push_back(MV1DuplicateModel(stairsHandle));

	// 階段と床
	v_stairsRoadHandle.clear();
	this->v_stairsRoadHandle.push_back(MV1DuplicateModel(stairsRoadHandle));

	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, this->area);
}


EnemyMove3Slime::~EnemyMove3Slime()
{
	GRAPHIC_RELEASE(textureHandle0);

	for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
	{
		MODEL_RELEASE(v_stairsRoadHandle[i]);
	}
	v_stairsRoadHandle.clear();
	v_stairsRoadHandle.shrink_to_fit();

	for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
	{
		MODEL_RELEASE(v_stairsHandle[i]);
	}
	v_stairsHandle.clear();
	v_stairsHandle.shrink_to_fit();

	MODEL_RELEASE(modelHandle);
}


void EnemyMove3Slime::Draw()
{
	BasicObject::Draw();		// 基本的なものを引っ張ってくる

	BasicObject::ShadowFoot();

	
	DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWigth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// 当たり判定を確認用の表示テスト
}


void EnemyMove3Slime::Process()
{
	// 直前の座標
	preArea = area;

	// 動きのプロセス
	MoveProcess();

	// モーション
	Player_AnimProcess();

	// ステージのあたり判定
	StageHit();

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
