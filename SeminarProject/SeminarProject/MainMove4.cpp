#include "MainMove4.hpp"



/// --------------------------------------------------------------------------------------------------
void MainMove4::DamageTextureReload()
{
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(damageDraw[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(damageBlend[i]);
	}

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\D.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\D.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\D.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\D.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\D.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\D.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\D.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\D.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\D.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\D.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\D.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\D.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\D.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\P.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\P.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\P.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\P.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\P.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\P.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\P.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\P.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\P.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\P.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\P.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\P.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\P.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;
	}
} /// void MainMove4::DamageTextureReload()



/// --------------------------------------------------------------------------------------------------
void MainMove4::ShadowDraw()
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
	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// 敵
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
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
	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// 敵
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


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
	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// 敵
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
	}
	// キャラクター
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// キャラクター
	p_character->ModelDraw();
} /// void MainMove4::ShadowDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove4::AttackProcess()
{
	/// 敵への攻撃に関する--------------------------------------------------------------------------------------------------------
	// 死んでいなかったら
	if (!p_enemyMove->GetDeathFlag())
	{
		// プレイヤーの攻撃モーションが終わったら
		if (p_character->GetAttackMotionEnd()) enemyDamage = false;


		// ダメージを受けていないがプレイヤーが攻撃中だったら
		if (p_character->GetAttackNow() && !enemyDamage)
		{
			p_enemyMove->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// 攻撃でダメージを受けたら
		if (p_enemyMove->GetDamageFlag())
		{
			// ダメージを受けているとする
			enemyDamage = true;


			// 一般人を生成させる
			BASICPARAM::ordinaryPeopleNum++;
			p_ordinaryPerson[BASICPARAM::ordinaryPeopleNum - 1]->SetAlive(p_enemyMove->GetArea());
			

			// バイブレーションさせる
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 10000, 10000);


			// エフェクトを再生する。
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// if (!p_enemyMove->GetDeathFlag())
	else
	{
		// 通常BGMが流れていなかったら
		if (nowBattleBGM)
		{
			nowBattleBGM = false;
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::normalBGM);
		}
	}
	/// 敵への攻撃に関する--------------------------------------------------------------------------------------------------------


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
	// ぶつかる距離だったら
	if (BaseMove::GetDistance<int>(p_enemyMove->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		// 当たっていたとき
		if (HitCheck_Capsule_Capsule(
			p_enemyMove->GetArea(), VAdd(p_enemyMove->GetArea(), VGet(0.0f, p_enemyMove->GetHeight(), 0.0f)), p_enemyMove->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// 敵を押し出す
			p_enemyMove->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemyMove->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyMove->GetWidth());
		}
	}


	// プレイヤーが近かったら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	// プレイヤーが遠かったら
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}


	// プレイヤーとの距離が近くて、触れるボタン押したら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		BASICPARAM::paneruDrawFlag = true;
	}
	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------


	/// キャラクターから押し出される----------------------------------------------------------------------------------------------------------------------
	// 死んでいなくてプレイヤーとの距離が近かったら
	if (!p_enemyMove->GetDeathFlag()
		&& BaseMove::GetDistance<int>(p_enemyMove->GetArea(), p_character->GetArea()) <= 250)
	{
		// プレイヤーと当たっていたら
		if (HitCheck_Capsule_Capsule(
			p_enemyMove->GetArea(), VAdd(p_enemyMove->GetArea(), VGet(0.0f, p_enemyMove->GetHeight(), 0.0f)), p_enemyMove->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// サイズが大きかったら
			if (p_enemyMove->GetBigNow())
			{
				// プレイヤーを押し出す
				p_character->HitCircleReturn(p_enemyMove->GetArea()
					, p_character->GetWidth() >= p_enemyMove->GetWidth() ? p_character->GetWidth() : p_enemyMove->GetWidth());
			}
			// サイズが大きくなかったら
			else
			{
				// 敵を押し出す
				p_enemyMove->HitCircleReturn(p_character->GetArea()
					, p_character->GetWidth() >= p_enemyMove->GetWidth() ? p_character->GetWidth() : p_enemyMove->GetWidth());
			}
		}
	}
	/// キャラクターから押し出される----------------------------------------------------------------------------------------------------------------------
} /// void MainMove4::AttackProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove4::ThsTextureReload()
{
	ths = std::thread(&MainMove4::TextureReload, this);
	ths.join();
}



/// --------------------------------------------------------------------------------------------------
MainMove4::MainMove4(const std::vector<int> v_file)
{
	// 初期化
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::ordinaryPeopleNum = 0;


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
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i] = nullptr;
	}
	p_enemyBossBefore = nullptr;
	p_enemyMove = nullptr;
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();


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


	// 人の初期化
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i] = new OrdinaryPerson(v_file[EFILE::ordiPersonModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::ordiPersonTex0], VGet(-1000.0f + i * 100.0f, i + 200.0f, 1000.0f), 0.0f);
	}


	// 敵の初期化
	p_enemyBossBefore = new EnemyBossBefore();
	p_enemyMove = new EnemyMove4(v_file[EFILE::enemyModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::enemyTex0], VGet(1000, 0, 1000), 0.0f);
	enemyAndPlayerDistance = 0;
	enemyScreenArea = VGet(0, 0, 0);
	enemyDamage = false;


	// スカイボックス
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// サウンドのロード
	nowBattleBGM = true;
	SoundProcess::Load(v_file[EFILE::se_attackOne], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_foot], SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor], SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump], SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing], SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond], SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main], SoundProcess::ESOUNDNAME_BGM::normalBGM);
	SoundProcess::Load(v_file[EFILE::bgm_battle], SoundProcess::ESOUNDNAME_BGM::battleBGM);
	SoundProcess::Load(v_file[EFILE::se_enemyDamage], SoundProcess::ESOUNDNAME_SE::strikeBomb);

	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::battleBGM, 255, 255);
	// SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 255, 255);


	// ダメージ演出
	damageCount = 0;
	preDamageCount = damageCount;
	notDamageCount = 101;
	damageDrawFrame = 0;
	damageDrawID = 0;
	damageDraw[0] = v_file[EFILE::damageDraw0];
	damageDraw[1] = v_file[EFILE::damageDraw1];
	damageDraw[2] = v_file[EFILE::damageDraw2];
	damageBlend[0] = v_file[EFILE::damageBlood0];
	damageBlend[1] = v_file[EFILE::damageBlood1];
	damageBlend[2] = v_file[EFILE::damageBlood2];
	damageBlend[3] = v_file[EFILE::damageBlood3];
	damageBlend[4] = v_file[EFILE::damageBlood4];
	damageBlend[5] = v_file[EFILE::damageBlood5];
	damageBlend[6] = v_file[EFILE::damageBlood6];
	damageBlend[7] = v_file[EFILE::damageBlood7];
	damageBlend[8] = v_file[EFILE::damageBlood8];
	damageBlend[9] = v_file[EFILE::damageBlood9];


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
	playingEfDamage = -1;
	effectAttack = LoadEffekseerEffect("media\\こっち\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
} /// MainMove4::MainMove4(const std::vector<int> v_file)



/// --------------------------------------------------------------------------------------------------
MainMove4::~MainMove4()
{
	// エフェクト開放
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);


	// ダメージ演出
	StopEffekseer2DEffect(playingEfDamage);
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


	// 敵
	POINTER_RELEASE(p_enemyBossBefore);
	POINTER_RELEASE(p_enemyMove);


	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		POINTER_RELEASE(p_ordinaryPerson[i]);
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
} /// MainMove4::~MainMove4()



/// --------------------------------------------------------------------------------------------------
void MainMove4::Draw()
{
	// スカイボックスを描画
	BaseMove::SkyBoxDraw();


	// シャドウマップを描画
	ShadowDraw();


	// 敵ラスボスのあれ
	p_enemyBossBefore->ModelDraw();


	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		// 存在を許されていなかったら
		if (!p_ordinaryPerson[i]->GetAlive()) continue;


		p_ordinaryPerson[i]->Draw();
	}


	// 敵
	if (!p_enemyMove->GetDeathFlag())
	{
		p_enemyMove->Draw();
	}


	// キャラクター
	p_character->Draw();


	// 精密機械との距離が近いとき
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// 説明画像を表示
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}

	/// ロックオンに関する------------------------------------------------------------------------------------------------------------
	// 存在していたら
	if (!p_enemyMove->GetEraseExistence())
	{
		// 攻撃範囲内だったら
		if (enemyAndPlayerDistance < 250)
		{
			// 横棒
			DrawBox(static_cast<int>(enemyScreenArea.x - 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x + 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
			// 縦棒
			DrawBox(static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y - 20.0f - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y + 20.0f - p_enemyMove->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
		}
		// 攻撃範囲外だったら
		else
		{
			// 横棒
			DrawBox(static_cast<int>(enemyScreenArea.x - 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x + 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
			// 縦棒
			DrawBox(static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y - 20.0f - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y + 20.0f - p_enemyMove->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
		}
	} /// if (!p_enemyMove->GetEraseExistence())
	/// ロックオンに関する------------------------------------------------------------------------------------------------------------


	/// ダメージに関する-----------------------------------------------------------------------------------------------------------
	/// エフェクトを再生する-------------------------------------------------------------------------------
	if (preDamageCount != damageCount / 10)
	{
		// ダメージカウントが10の倍数で次か前のエフェクトに切り替える
		preDamageCount = damageCount / 10;


		// エフェクトが再生中だったら
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);


		// エフェクトを再生する
		playingEfDamage = PlayEffekseer2DEffect(effeckBack[preDamageCount - 1]);
		SetScalePlayingEffekseer2DEffect(playingEfDamage, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfDamage, 960, 540, 0);
	}
	// ダメージを受けていなかったら
	if (damageCount == 0)
	{
		// エフェクトを止める
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);
	}
	/// エフェクトを再生する-------------------------------------------------------------------------------


	/// ダメージの演出
	if (damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	/// ダメージの蓄積で画面を埋め尽くす処理-----------------------------------------------
	if (damageCount > 0)
	{
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageCount * 25.5));
		DrawGraph(0, 0, damageBlend[0], true);
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 10)
	{
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 10) * 25.5));
		DrawGraph(0, 0, damageBlend[1], true);
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 20)
	{
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 20) * 25.5));
		DrawGraph(0, 0, damageBlend[2], true);
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 30)
	{
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 30) * 25.5));
		DrawGraph(0, 0, damageBlend[3], true);
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 40)
	{
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 40) * 25.5));
		DrawGraph(0, 0, damageBlend[4], true);
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 50)
	{
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 50) * 25.5));
		DrawGraph(0, 0, damageBlend[5], true);
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 60)
	{
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 60) * 25.5));
		DrawGraph(0, 0, damageBlend[6], true);
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 70)
	{
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 70) * 25.5));
		DrawGraph(0, 0, damageBlend[7], true);
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 80)
	{
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 80) * 25.5));
		DrawGraph(0, 0, damageBlend[8], true);
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 90)
	{
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 90) * 25.5));
		DrawGraph(0, 0, damageBlend[9], true);
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	/// ダメージの蓄積で画面を埋め尽くす処理-----------------------------------------------
	/// ダメージに関する-----------------------------------------------------------------------------------------------------------


	// ムーブ説明をする
	if (moveDescriptionFrame-- > 0)
	{
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 243, 540 - 141 - 70, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
} /// void MainMove4::Draw()


/// --------------------------------------------------------------------------------------------------
void MainMove4::Process()
{
	// キャラクターのプロセス
	p_character->Process(p_camera->GetAngle());


	/// ダメージを受けていないカウント数で処理---------------------------------------------------------
	notDamageCount++;


	// ダメージを受けていなかったら回復させる
	if (notDamageCount > 100 && damageCount > 0 && (notDamageCount - 100) % 10 == 0) damageCount--;


	// ダメージ演出画像が残っていたらだんだん消す
	if (damageDrawFrame > 0) damageDrawFrame--;
	/// ダメージを受けていないカウント数で処理---------------------------------------------------------


	// カメラのプロセス
	p_camera->Process(p_character->GetArea());


	// 人
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i]->Process();
	}


	// 敵ラスボスのあれ
	p_enemyBossBefore->Process();


	// 敵
	// 消滅していなかったら
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->Process();		// プロセスを呼ぶ

		
		// 死んでいなかったら
		if (!p_enemyMove->GetDeathFlag())
		{
			// ロックオンの情報を更新する
			enemyAndPlayerDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyMove->GetArea());
			enemyScreenArea = ConvWorldPosToScreenPos(p_enemyMove->GetArea());


			// プレイヤーから視認できる範囲だったら
			if (enemyAndPlayerDistance < 250)
			{
				p_character->SetMostNearEnemyArea(p_enemyMove->GetArea());
			}
			// プレイヤーから視認できない範囲だったら
			else
			{
				p_character->SetMostNearEnemyArea();
			}


			// プレイヤーの位置と距離を取得する
			p_enemyMove->SetCharacterArea(p_character->GetArea(), enemyAndPlayerDistance);


			// プレイヤーに対して攻撃出来たら
			if (p_enemyMove->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemyMove->GetArea().y + p_enemyMove->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyMove->GetArea().y)
			{
				// 攻撃SEを流す
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemyMove->GetArea(), 180);


				p_character->SetDamage();		// プレイヤーにダメージを与える


				// ダメージを受けていないカウントが0じゃなかったら
				if (notDamageCount != 0) notDamageCount = 0;


				// ダメージ数値が100以下だったら
				if (damageCount < 100)	damageCount++;


				// ダメージ演出画像が出ていなかったら
				if (damageDrawFrame == 0)
				{
					std::random_device rnd;     // 非決定的な乱数生成器を生成
					std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
					std::uniform_int_distribution<> blood(0, 2);        // X座標用乱数
					damageDrawID = blood(mt);		// ランダムでダメージ画像を表示する
					damageDrawFrame = 10;			// 10フレームだけ表示するようにする
				}
			}
		} /// if (!p_enemyMove->GetDeathFlag())
	} /// if (!p_enemyMove->GetEraseExistence())
	

	// シャドウマップの座標を更新
	BaseMove::ShadowArea(p_character->GetArea());

	
	// 当たり判定プロセス
	AttackProcess();


	// スカイボックスの座標を更新
	BaseMove::SkyBoxProcess(p_character->GetArea());


	// 次のシーンへ移行する場所に居たら
	if (p_character->GetArea().y >= 3550.0f)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIFTHLOAD);
	}


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIFTHLOAD);
	}
#endif
} /// void MainMove4::Process()



/// --------------------------------------------------------------------------------------------------
void MainMove4::CameraProcess()
{
	p_camera->SetUp();
}



/// --------------------------------------------------------------------------------------------------
void MainMove4::TextureReload()
{
	// キャラクターのテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// ダメージ演出
		DamageTextureReload();


		// キャラクター
		p_character->TextureReload();
	}


	// 敵
	if (!BASICPARAM::enemyTextureWhiteBlack)
	{
		if (!p_enemyMove->GetDeathFlag())
		{
			p_enemyMove->TextureReload();
		}
	}


	// その他のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// 精密機械
		p_adjustmentMachine->TextureReload();


		// 人
		for (int i = 0; i != ordinaryNum; ++i)
		{
			p_ordinaryPerson[i]->TextureReload();
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
} /// void MainMove4::TextureReload()



/// --------------------------------------------------------------------------------------------------
void MainMove4::OptionActorModel()
{
	p_character->OptionActorDraw();
}



/// --------------------------------------------------------------------------------------------------
void MainMove4::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}



/// --------------------------------------------------------------------------------------------------
void MainMove4::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
