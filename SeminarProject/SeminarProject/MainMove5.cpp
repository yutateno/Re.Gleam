#include "MainMove5.hpp"


// シャドウマップの描画
void MainMove5::ShadowDraw()
{
	/// セットアップ
	BaseMove::ShadowCharaSetUpBefore();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	p_adjustmentMachine->ModelDraw();
	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// 敵
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
	}
	// キャラクター
	p_character->ModelDraw();


	/// キャラクター以外再セットアップ
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	p_adjustmentMachine->ModelDraw();
	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// 敵
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


	/// 描画
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// ステージ
	p_stage->Draw();
	// 階段
	if (enemyCatchNum >= 40)
	{
		if (BASICPARAM::stairsNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
			{
				vp_stageStairs[i]->ModelDraw();
			}
		}
	}
	// 街灯
	if (enemyCatchNum >= 20)
	{
		if (BASICPARAM::streetLightNum != 0)
		{
			for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
			{
				vp_stageStreetLight[i]->ModelDraw();
			}
		}
	}
	// 階段と床
	if (enemyCatchNum >= 45)
	{
		if (BASICPARAM::stairsRoadNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
			{
				vp_stageStairsRoad[i]->ModelDraw();
			}
		}
	}
	// パネル
	if (enemyCatchNum >= 35)
	{
		if (BASICPARAM::paneruDrawFlag)
		{
			for (int i = 0; i != 10; ++i)
			{
				p_stagePaneru[i]->ModelDraw();
			}
		}
	}
	// 精密機械
	if (enemyCatchNum >= 5)
	{
		p_adjustmentMachine->ModelDraw();
	}
	// 一般人
	if (enemyCatchNum >= 15)
	{
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->ModelDraw();
			}
		}
	}
	// 敵
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
	}
	// キャラクター
	if (enemyCatchNum >= 30)
	{
		p_character->ModelDraw();
	}
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// キャラクター
	if (enemyCatchNum >= 30)
	{
		p_character->ModelDraw();
	}
} /// void MainMove5::ShadowDraw()


// 当たり判定のプロセス
void MainMove5::AttackProcess()
{
	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------
	// 当たっていたらプレイヤーを押し出す
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()
		, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
	{
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
			, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
	}


	// 敵に関する
	for (int i = 0; i != enemyNum; ++i)
	{
		// ぶつかる距離だったら
		if (BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
		{
			// 当たっていたとき
			if (HitCheck_Capsule_Capsule(
				p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth()
				, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
			{
				// 敵を押し出す
				p_enemyMove[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
					, p_adjustmentMachine->GetWidth() >= p_enemyMove[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyMove[i]->GetWidth());
			}
		}
	}


	// プレイヤーとの距離が近くて、触れるボタン押したら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		BASICPARAM::paneruDrawFlag = true;
	}


	// プレイヤーと距離が近かったら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	// プレイヤーと距離が遠かったら
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}
	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------


	/// プレイヤーに触れられたら-----------------------------------------------------
	for (int i = 0; i != enemyNum; ++i)
	{
		// 死んでいるかプレイヤーとの距離が近くではなかったら
		if (p_enemyMove[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// プレイヤーと当たっていたら
		if (HitCheck_Capsule_Capsule(
			p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// 死ぬ
			p_enemyMove[i]->SetDie();
			enemyCatchNum++;
		}
	}
	/// プレイヤーから押し出される-----------------------------------------------------
	

	/// 敵同士で押し出す----------------------------------------------------------------
	for (int i = 0; i != enemyNum; ++i)
	{
		// 死んでいたら
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		for (int j = 0; j != enemyNum; ++j)
		{
			// 自分と自分で行わせないか死んでいるか距離が遠かったら
			if (i == j || p_enemyMove[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_enemyMove[j]->GetArea()) > 250) continue;


			// 当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth(),
				p_enemyMove[j]->GetArea(), VAdd(p_enemyMove[j]->GetArea(), VGet(0.0f, p_enemyMove[j]->GetHeight(), 0.0f)), p_enemyMove[j]->GetWidth()))
			{
				// 自分が押し出される
				p_enemyMove[i]->HitCircleReturn(p_enemyMove[j]->GetArea(), p_enemyMove[j]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemyNum; ++i)
	/// 敵同士で押し出す----------------------------------------------------------------
} /// void MainMove5::AttackProcess()


// テクスチャの非同期読み込み
void MainMove5::ThsTextureReload()
{
	ths = std::thread(&MainMove5::TextureReload, this);
	ths.join();
}


// コンストラクタ
MainMove5::MainMove5(const std::vector<int> v_file)
{
	// 初期化
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::lastCharaView = false;
	BASICPARAM::lastOrdinaryView = false;
	BASICPARAM::lastPaneruView = false;
	BASICPARAM::lastStairsRoadView = false;
	BASICPARAM::lastStairsView = false;
	BASICPARAM::lastStreetLightView = false;


	// ポインタNULL初期化
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_adjustmentMachine = nullptr;
	p_stage = nullptr;
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = nullptr;
	}
	p_enemyBossBefore = nullptr;
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i] = nullptr;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();
	vp_ordinaryPerson.clear();


	// ムーブ説明
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 400;


	// ステージの初期化
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// キャラクターの初期化
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);


	// カメラの初期化
	p_camera = new Camera(p_character->GetArea());


	// パネルの初期化
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(500.0f * i, 300.0f * i, 100.0f * i));
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// 階段と床の初期化
	if (BASICPARAM::stairsRoadNum != 0)
	{
		vp_stageStairsRoad.resize(BASICPARAM::stairsRoadNum);
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i] = nullptr;
			vp_stageStairsRoad[i] = new StageStairsRoad(v_file[EFILE::stairsRoadDrawModel], BASICPARAM::v_stairsRoadArea[i]
				, v_file[EFILE::stairsRoadTex0], v_file[EFILE::stairsRoadTex1], BASICPARAM::v_stairsRoadAngle[i]);
			p_character->SetStairsRoadArea(vp_stageStairsRoad[i]->GetArea(), i, BASICPARAM::v_stairsRoadAngle[i]);
		}
	}


	// 街灯の初期化
	if (BASICPARAM::streetLightNum != 0)
	{
		vp_stageStreetLight.resize(BASICPARAM::streetLightNum);
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i] = nullptr;
			vp_stageStreetLight[i] = new StageStreetLight(v_file[EFILE::streetLightModel], BASICPARAM::v_streetLightArea[i]
				, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1], BASICPARAM::v_streetLightAngle[i]);
		}
	}


	// 階段の初期化
	if (BASICPARAM::stairsNum != 0)
	{
		vp_stageStairs.resize(BASICPARAM::stairsNum);
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i] = nullptr;
			vp_stageStairs[i] = new StageStairs(v_file[EFILE::stairsDrawModel], BASICPARAM::v_stairsArea[i], v_file[EFILE::stairsTex0], BASICPARAM::v_stairsAngle[i]);
			p_character->SetStairsArea(vp_stageStairs[i]->GetArea(), i, BASICPARAM::v_stairsAngle[i]);
		}
	}


	// 精密機械の初期化
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminalModel], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);
	for (int i = 0; i != 15; ++i)
	{
		p_adjustmentMachine->CatchDropItem();
	}
	adjustmentDescDraw = v_file[EFILE::terminalDesc];


	// 敵の初期化
	p_enemyBossBefore = new EnemyBossBefore();
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z座標用乱数
	for (int i = 0; i != enemyNum; ++i)
	{
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
		p_enemyMove[i] = new EnemyMove5(v_file[EFILE::enemyModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::enemyTex0], VGet(tempX, 0.0f, tempZ), 0);
	}
	enemyCatchNum = 0;


	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		vp_ordinaryPerson.resize(BASICPARAM::ordinaryPeopleNum);
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
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
			vp_ordinaryPerson[i] = nullptr;
			vp_ordinaryPerson[i] = new OrdinaryPerson(v_file[EFILE::ordinaryModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
				, v_file[EFILE::stairsRoadCollModel], v_file[EFILE::ordinaryTex0], VGet(tempX, 0.0f, tempZ), 0);
			vp_ordinaryPerson[i]->SetAlive(VGet(tempX, 0.0f, tempZ));
		}
	}


	// スカイボックス
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// サウンドのロード
	SoundProcess::Load(v_file[EFILE::se_attackOne], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_foot], SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor], SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump], SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing], SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond], SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main], SoundProcess::ESOUNDNAME_BGM::normalBGM);
	SoundProcess::Load(v_file[EFILE::se_catch_saveMiss], SoundProcess::ESOUNDNAME_SE::saveMiss);

	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 255, 255);
	certainCatchSEDo = false;
} /// MainMove5::MainMove5(const std::vector<int> v_file)


// デストラクタ
MainMove5::~MainMove5()
{
	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_ordinaryPerson[i]);
		}
		vp_ordinaryPerson.clear();
		vp_ordinaryPerson.shrink_to_fit();
	}


	// 敵
	POINTER_RELEASE(p_enemyBossBefore);
	for (int i = 0; i != enemyNum; ++i)
	{
		POINTER_RELEASE(p_enemyMove[i]);
	}


	// 精密機械
	GRAPHIC_RELEASE(adjustmentDescDraw);
	POINTER_RELEASE(p_adjustmentMachine);


	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairs[i]);
		}
		vp_stageStairs.clear();
		vp_stageStairs.shrink_to_fit();
	}


	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStreetLight[i]);
		}
		vp_stageStreetLight.clear();
		vp_stageStreetLight.shrink_to_fit();
	}


	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairsRoad[i]);
		}
		vp_stageStairsRoad.clear();
		vp_stageStairsRoad.shrink_to_fit();
	}


	// パネル
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// カメラ
	POINTER_RELEASE(p_camera);


	// キャラクター
	POINTER_RELEASE(p_character);


	// ステージ
	POINTER_RELEASE(p_stage);


	/// 説明画像解放
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove5::~MainMove5()


// 描画
void MainMove5::Draw()
{
	BaseMove::SkyBoxDraw();		// スカイボックスを描画


	ShadowDraw();		// シャドウマップを描画


	// 敵ラスボスのあれ
	p_enemyBossBefore->ModelDraw();


	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Draw();
		}
	}


	// 敵
	for (int i = 0; i != enemyNum; ++i)
	{
		// 死んでいたら
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		p_enemyMove[i]->Draw();
	}


	p_character->Draw();	// キャラクターを描画


	// 精密機械と距離が近かったら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// 説明画像を表示する
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}


	// ムーブ説明をする
	if (moveDescriptionFrame-- > 0)
	{
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 291, 540 - 64 - 32, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
} /// void MainMove5::Draw()


// プロセス
void MainMove5::Process()
{
	// キャラクターのプロセス
	p_character->Process(p_camera->GetAngle());


	// カメラのプロセス
	p_camera->Process(p_character->GetArea());


	// 一般人のプロセス
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Process();
		}
	}


	// 敵ラスボスのあれ
	p_enemyBossBefore->Process();


	// 敵に関する
	for (int i = 0; i != enemyNum; ++i)
	{
		// 消滅したら
		if (p_enemyMove[i]->GetEraseExistence()) continue;


		p_enemyMove[i]->Process();			// プロセスを呼ぶ


		// 死んでいなかったら
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		// プレイヤーの位置と距離を取得する
		p_enemyMove[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyMove[i]->GetArea()));
	}


	// シャドウマップの位置を更新
	BaseMove::ShadowArea(p_character->GetArea());


	AttackProcess();		// 当たり判定のプロセス

	
	// スカイボックスの位置を更新
	BaseMove::SkyBoxProcess(p_character->GetArea());


	/// 手に入れた数でSEを流す-------------------------------------------------
	if (enemyCatchNum == 5)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 15)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 20)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 30)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 35)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 40)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else if (enemyCatchNum == 45)
	{
		if (!certainCatchSEDo)
		{
			certainCatchSEDo = true;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::saveMiss);
		}
	}
	else
	{
		if (certainCatchSEDo) certainCatchSEDo = false;
	}


	// 次のシーンへ移行する場所に居たら
	if (p_character->GetArea().y >= 3550.0f)
	{
		if (enemyCatchNum >= 30) BASICPARAM::lastCharaView = true;
		if (enemyCatchNum >= 15) BASICPARAM::lastOrdinaryView = true;
		if (enemyCatchNum >= 35) BASICPARAM::lastPaneruView = true;
		if (enemyCatchNum >= 45) BASICPARAM::lastStairsRoadView = true;
		if (enemyCatchNum >= 40) BASICPARAM::lastStairsView = true;
		if (enemyCatchNum >= 20) BASICPARAM::lastStreetLightView = true;
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SIXLOAD);
	}

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		if (enemyCatchNum >= 30) BASICPARAM::lastCharaView = true;
		if (enemyCatchNum >= 15) BASICPARAM::lastOrdinaryView = true;
		if (enemyCatchNum >= 35) BASICPARAM::lastPaneruView = true;
		if (enemyCatchNum >= 45) BASICPARAM::lastStairsRoadView = true;
		if (enemyCatchNum >= 40) BASICPARAM::lastStairsView = true;
		if (enemyCatchNum >= 20) BASICPARAM::lastStreetLightView = true;
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SIXLOAD);
	}
#endif
} /// void MainMove5::Process()


// カメラの再セットアップ
void MainMove5::CameraProcess()
{
	p_camera->SetUp();
}


// テクスチャの読み込み
void MainMove5::TextureReload()
{
	// キャラクターのテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// キャラクター
		p_character->TextureReload();
	}


	// その他のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// 精密機械
		p_adjustmentMachine->TextureReload();


		// 一般人
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->TextureReload();
			}
		}
	}


	// 敵
	if (!BASICPARAM::enemyTextureWhiteBlack)
	{
		for (int i = 0; i != enemyNum; ++i)
		{
			p_enemyMove[i]->TextureReload();
		}
	}


	// 階段のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::stairsTextureWhiteBlack)
	{
		if (BASICPARAM::stairsNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
			{
				vp_stageStairs[i]->TextureReload();
			}
		}
	}


	// 街灯のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::lightStreetTextureWhiteBlack)
	{
		if (BASICPARAM::streetLightNum != 0)
		{
			for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
			{
				vp_stageStreetLight[i]->TextureReload();
			}
		}
	}


	// 階段と床のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::stairsRoadTextureWhiteBlack)
	{
		if (BASICPARAM::stairsRoadNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
			{
				vp_stageStairsRoad[i]->TextureReload();
			}
		}
	}
} /// void MainMove5::TextureReload()


// オプション画面モデルの描画
void MainMove5::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// オプション画面モデルの描画の準備
void MainMove5::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// オプション画面モデルの描画の後始末
void MainMove5::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
