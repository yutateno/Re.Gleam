#include "MainMove3.hpp"


void MainMove3::ShadowDraw()
{
	/// セットアップ
	BaseMove::ShadowCharaSetUpBefore();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// 精密機械
	p_adjustmentMachine->Draw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	// キャラクター
	p_character->Draw();
	BaseMove::ShadowCharaSetUpAfter();

	/// キャラクター以外再セットアップ
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// 精密機械
	p_adjustmentMachine->Draw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	BaseMove::ShadowAnotherCharaSetUpAfter();

	/// 描画
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// ステージ
	p_stage->Draw();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// 精密機械
	p_adjustmentMachine->Draw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	// キャラクター
	p_character->Draw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
}

void MainMove3::AttackProcess()
{
	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------
	// 当たっていたら押し出す
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()
		, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
	{
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
			, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
	}
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (BaseMove::GetDistance(p_enemySlime[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			p_enemySlime[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemySlime[i]->GetWidth());
		}
	}
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (BaseMove::GetDistance(p_enemyCrayonHuman[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			p_enemyCrayonHuman[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
		}
	}
	// 近くかどうかで見た目を変える
	if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}


	/// キャラクターを押し出す
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (BaseMove::GetDistance(p_enemySlime[i]->GetArea(), p_character->GetArea()) > 250) continue;
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			p_enemySlime[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_character->GetWidth() : p_enemySlime[i]->GetWidth());
			//p_character->HitCircleReturn(p_enemySlime[i]->GetArea(), VGet(0.0f, 140.0f, 0.0f));
		}
	}
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (BaseMove::GetDistance(p_enemyCrayonHuman[i]->GetArea(), p_character->GetArea()) > 250) continue;
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			p_enemyCrayonHuman[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_character->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
			//p_character->HitCircleReturn(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, 70.0f, 0.0f));
		}
	}


	/// 敵同士で押し出す
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		for (int j = 0; j != enemySlimeNum; ++j)
		{
			if (i == j) continue;
			if (BaseMove::GetDistance(p_enemySlime[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
				p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				p_enemySlime[i]->HitCircleReturn(p_enemySlime[j]->GetArea(), p_enemySlime[j]->GetWidth());
				//p_character->HitCircleReturn(p_enemySlime[i]->GetArea(), VGet(0.0f, 140.0f, 0.0f));
			}
		}

		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			if (BaseMove::GetDistance(p_enemySlime[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[j]->GetHeight(), 0.0f)), p_enemyCrayonHuman[j]->GetWidth()))
			{
				p_enemySlime[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea()
					, p_enemyCrayonHuman[j]->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_enemyCrayonHuman[j]->GetWidth() : p_enemySlime[i]->GetWidth());
				//p_character->HitCircleReturn(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, 70.0f, 0.0f));
			}
		}
	}
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			if (i == j) continue;
			if (BaseMove::GetDistance(p_enemyCrayonHuman[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()))
			{
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea(), p_enemyCrayonHuman[i]->GetWidth());
				//p_character->HitCircleReturn(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, 70.0f, 0.0f));
			}
		}

		for (int j = 0; j != enemySlimeNum; ++j)
		{
			if (BaseMove::GetDistance(p_enemyCrayonHuman[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemySlime[j]->GetArea()
					, p_enemySlime[j]->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_enemySlime[j]->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
				//p_character->HitCircleReturn(p_enemySlime[i]->GetArea(), VGet(0.0f, 140.0f, 0.0f));
			}
		}
	}


	/// ドロップに関する--------------------------------------------------------------------------------------
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;

		if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
		{
			p_dropItem[i]->StolenChara(p_character->GetArea());
		}


		if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
		{
			catchDropItemNum++;
			p_dropItem[i]->SetDeath(true);			// 生きさせない

			/// SEの再生をランダムにする-----------------------------------------------------------------------------
			//std::random_device rnd;     // 非決定的な乱数生成器を生成
			//std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
			//std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数

			//if (randPawnSE(mt) == 0)
			//{
			//	SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp, p_dropItem[i]->GetArea());
			//}
			//else
			//{
			//	SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp2, p_dropItem[i]->GetArea());
			//}
			/// -----------------------------------------------------------------------------------------------------
		}
	}
}

void MainMove3::ThsTextureReload()
{
	ths = std::thread(&MainMove3::ThsTextureReload, this);
	ths.join();
}

MainMove3::MainMove3(const std::vector<int> v_file)
{
	BASICPARAM::paneruDrawFlag = false;


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
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i] = nullptr;
	}
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i] = nullptr;
	}
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		p_dropItem[i] = nullptr;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();


	// ステージの初期化
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// キャラクターの初期化
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	charaSomeEnemyDamageCount = 0;

	// カメラの初期化
	p_camera = new Camera(p_character->GetArea(), v_file[EFILE::stageCollModel]);

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
				, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1], BASICPARAM::v_stairsAngle[i]);
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

	// 敵スライムの初期化
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i] = new EnemyMove3Slime(v_file[EFILE::slimeModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::slimeTex0], VGet(1000.0f - (i * 150.0f), 0.0f, 1000.0f), 0.0f);
	}

	// 敵クレヨンヒューマンの初期化
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i] = new EnemyMove3CrayonHuman(v_file[EFILE::crayonHumanModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::crayonHumanTex0], VGet(-1500.0f + (i * 150.0f), 0.0f, -1000.0f), 0.0f);
	}

	// ドロップアイテムの初期化
	catchDropItemNum = 0;
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove3(v_file[EFILE::dropItemModel], p_character->GetArea(), v_file[EFILE::dropItemTex0]);
	}

	// スカイボックス
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);

	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();

	// サウンドのロード
	SoundProcess::Load(v_file[EFILE::se_attackOne], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_ballPickUp], SoundProcess::ESOUNDNAME_SE::ballPickUp);
	SoundProcess::Load(v_file[EFILE::se_ballPickUp2], SoundProcess::ESOUNDNAME_SE::ballPickUp2);
	SoundProcess::Load(v_file[EFILE::se_foot], SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor], SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump], SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing], SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond], SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main], SoundProcess::ESOUNDNAME_BGM::normalBGM);

	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 255, 255);

	// ダメージ演出
	damageCount = 0;
	preDamageCount = damageCount;
	notDamageCount = 0;
	damageDrawFrame = 0;
	damageDrawID = 0;
	damageDraw[0] = LoadGraph("media\\こっち\\media\\damage\\damage1.png");
	damageDraw[1] = LoadGraph("media\\こっち\\media\\damage\\damage2.png");
	damageDraw[2] = LoadGraph("media\\こっち\\media\\damage\\damage3.png");
	damageBlend[0] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl1.png");
	damageBlend[1] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl2.png");
	damageBlend[2] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl3.png");
	damageBlend[3] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl4.png");
	damageBlend[4] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl5.png");
	damageBlend[5] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl6.png");
	damageBlend[6] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl7.png");
	damageBlend[7] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl8.png");
	damageBlend[8] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl9.png");
	damageBlend[9] = LoadGraph("media\\こっち\\media\\damage\\Blood\\bl10.png");
	// エフェクト読み込み
	effeckBack[0] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\one.efk");
	effeckBack[1] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\two.efk");
	effeckBack[2] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\three.efk");
	effeckBack[3] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\four.efk");
	effeckBack[4] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\five.efk");
	effeckBack[5] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\six.efk");
	effeckBack[6] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\seven.efk");
	effeckBack[7] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\eight.efk");
	effeckBack[8] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\nine.efk");
	effeckBack[9] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\ten.efk");
	playingEfBack = -1;
}

MainMove3::~MainMove3()
{
	// ダメージ演出
	StopEffekseer2DEffect(playingEfBack);
	for (int i = 0; i != 10; ++i)
	{
		DeleteEffekseerEffect(effeckBack[i]);
	}
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(damageDraw[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(damageBlend[i]);
	}
	// ドロップアイテム
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		POINTER_RELEASE(p_enemyCrayonHuman[i]);
	}
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		POINTER_RELEASE(p_enemySlime[i]);
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
}

void MainMove3::Draw()
{
	BaseMove::SkyBoxDraw();




	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->Draw();
	}

	ShadowDraw();


	if (p_adjustmentMachine->GetCanTouch())
	{
		if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
		{
			DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
		}
	}

	// エフェクトを再生する。
	if (preDamageCount != damageCount / 10)
	{
		preDamageCount = damageCount / 10;
		switch (damageCount)
		{
		case 1:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[0]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 2:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[1]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 3:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[2]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 4:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[3]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 5:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[4]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 6:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[5]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 7:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[6]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 8:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[7]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 9:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[8]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 10:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[9]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		default:
			break;
		}
	}
	if (damageCount == 0)
	{
		if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
	}


	if (damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}

	if (damageCount > 0)
	{
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageCount * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[0], true);
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 10)
	{
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 10) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[1], true);
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 20)
	{
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 20) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[2], true);
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 30)
	{
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 30) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[3], true);
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 40)
	{
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 40) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[4], true);
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 50)
	{
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 50) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[5], true);
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 60)
	{
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 60) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[6], true);
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 70)
	{
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 70) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[7], true);
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 80)
	{
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 80) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[8], true);
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	if (damageCount > 90)
	{
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 90) * 25.5));		//ブレンドモードをα(128/255)に設定
		DrawGraph(0, 0, damageBlend[9], true);
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}


	DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);
}

void MainMove3::Process()
{
	// キャラクターのプロセス
	p_character->Process(p_camera->GetAngle());
	charaSomeEnemyDamageCount = 0;

	notDamageCount++;
	if (notDamageCount > 100 && damageCount > 0 && (notDamageCount - 100) % 10 == 0) damageCount--;

	if (damageDrawFrame > 0) damageDrawFrame--;


	// カメラのプロセス
	p_camera->Process(p_character->GetArea());

	// 敵スライムのプロセス
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Process();
		p_enemySlime[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance(p_character->GetArea(), p_enemySlime[i]->GetArea()));
		if (p_enemySlime[i]->GetAttackDamage()
			&& p_character->GetArea().y <= p_enemySlime[i]->GetArea().y + p_enemySlime[i]->GetHeight()
			&& p_character->GetArea().y + p_character->GetHeight() >= p_enemySlime[i]->GetArea().y)
		{
			if (charaSomeEnemyDamageCount++ < 2)
			{
				p_character->SetDamage();

				notDamageCount = 0;
				if (damageCount < 100)	damageCount++;
				if (damageDrawFrame == 0)
				{
					std::random_device rnd;     // 非決定的な乱数生成器を生成
					std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
					std::uniform_int_distribution<> blood(0, 2);        // X座標用乱数
					damageDrawID = blood(mt);
					damageDrawFrame = 10;
				}
			}
		}
	}

	// 敵クレヨンヒューマンのプロセス
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Process();
		p_enemyCrayonHuman[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()));
		if (p_enemyCrayonHuman[i]->GetAttackDamage()
			&& p_character->GetArea().y <= p_enemyCrayonHuman[i]->GetArea().y + p_enemyCrayonHuman[i]->GetHeight()
			&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyCrayonHuman[i]->GetArea().y)
		{
			if (charaSomeEnemyDamageCount++ < 2)
			{
				p_character->SetDamage();

				notDamageCount = 0;
				if (damageCount < 100)	damageCount++;
				if (damageDrawFrame == 0)
				{
					std::random_device rnd;     // 非決定的な乱数生成器を生成
					std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
					std::uniform_int_distribution<> blood(0, 2);        // X座標用乱数
					damageDrawID = blood(mt);
					damageDrawFrame = 10;
				}
			}
		}
	}

	// ドロップアイテム
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		/*if (CheckHitKey(KEY_INPUT_Y) == 1)
		{
			if (!p_dropItem[i]->GetDeath()) p_dropItem[i]->SetAlive(true, p_character->GetArea());
		}*/
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->Process();
	}

	BaseMove::ShadowArea(p_character->GetArea());

	AttackProcess();

	BaseMove::SkyBoxProcess(p_character->GetArea());


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FORTHLOAD);
	}
#endif
}

void MainMove3::CameraProcess()
{
	p_camera->SetUp();
}

void MainMove3::TextureReload()
{
	// キャラクター
	p_character->TextureReload();

	// 精密機械
	p_adjustmentMachine->TextureReload();

	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->TextureReload();
		}
	}

	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->TextureReload();
		}
	}

	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->TextureReload();
		}
	}

	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag()) continue;
		p_enemySlime[i]->TextureReload();
	}

	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;
		p_enemyCrayonHuman[i]->TextureReload();
	}

	// ドロップアイテム
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->TextureReload();
	}
}

void MainMove3::OptionActorModel()
{
	p_character->OptionActorDraw();
}

void MainMove3::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}
