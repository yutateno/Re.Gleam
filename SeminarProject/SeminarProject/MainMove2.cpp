#include "MainMove2.hpp"



void MainMove2::AdjustmentProcess()
{
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		printfDx("戻れー");
		changeAdjustmentScene = false;
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		AdjuctmentCreate(VGet(-100.0f*BASICPARAM::stairsNum, 0.0f, -1000.0f), AdjustmentObject::Stairs);
		printfDx("階段を生成: %d\n", BASICPARAM::stairsNum);
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		AdjuctmentCreate(VGet(250.0f*BASICPARAM::streetLightNum, 0.0f, -100.0f*BASICPARAM::streetLightNum), AdjustmentObject::StreetLight);
		printfDx("街灯を生成: %d\n", BASICPARAM::streetLightNum);
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_Y) == 1)
	{
		BASICPARAM::paneruDrawFlag = !BASICPARAM::paneruDrawFlag;
		printfDx("パネルを表示: %s\n", BASICPARAM::paneruDrawFlag ? "true" : "false");
	}
}


void MainMove2::AdjustmentDraw()
{
	DrawFormatString(0, 0, 255, "オペレーターシーンなう");
}


void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID)
{
	switch (obujectID)
	{
	case AdjustmentObject::Stairs:
		vp_stageStairs.push_back(new StageStairs(stairsHandle, area, stairsTexture0));
		p_character->SetStairsArea(vp_stageStairs[BASICPARAM::stairsNum]->GetArea(), BASICPARAM::stairsNum);
		BASICPARAM::stairsNum++;
		BASICPARAM::v_stairsArea.push_back(area);
		break;

	case AdjustmentObject::StreetLight:
		vp_stageStreetLight.push_back(new StageStreetLight(streetLightHandle, area, streetLightTexture0, streetLightTexture1));
		BASICPARAM::streetLightNum++;
		BASICPARAM::v_streetLightArea.push_back(area);
		break;

	default:
		break;
	}
}


void MainMove2::ShadowDraw()
{
	BaseMove::ShadowCharaSetUpBefore();
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	for (int i = 0; i != vp_stageStreetLight.size(); ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	p_adjustmentMachine->Draw();
	p_character->Draw();
	BaseMove::ShadowCharaSetUpAfter();


	BaseMove::ShadowAnotherCharaSetUpBefore();
	for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence())	p_enemy[i]->Draw();
	}
	for (int i = 0; i != vp_stageStreetLight.size(); ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	p_adjustmentMachine->Draw();
	BaseMove::ShadowAnotherCharaSetUpAfter();


	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	p_stage->Draw();
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	for (int i = 0; i != vp_stageStreetLight.size(); ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	p_adjustmentMachine->Draw();
	p_character->Draw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
}


void MainMove2::AttackProcess()
{
	/// 敵に関する--------------------------------------------------------------------------------------------------------
	for (int i = 0; i != enemyNum; ++i)
	{
		if (p_enemy[i]->GetDeathFlag()) continue;

		// 当たっていたら押し出す
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 100.0f))
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
		}

		// 攻撃中だったら
		if (p_character->GetAttackNow())
		{
			p_enemy[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}
	}


	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------

	// 当たっていたら押し出す
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
		p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 70.0f))
	{
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
	}

	// 距離が近かくで触れるボタン押したら
	if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(),DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		printfDx("移れー");
		changeAdjustmentScene = true;
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	
	/// ドロップに関する--------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;

		if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 50)
		{
			catchDropItemNum++;
			p_dropItem[i]->SetDeath(true);			// 生きさせない
			if (i % 5 == 0) SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp);
		}

		if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
		{
			p_dropItem[i]->StolenChara(p_character->GetArea());
		}
	}
}


MainMove2::MainMove2(const std::vector<int> v_file)
{
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::stairsNum = 0;
	BASICPARAM::streetLightNum = 0;
	BASICPARAM::v_stairsArea.clear();
	BASICPARAM::v_streetLightArea.clear();


	// ポインタNULL初期化
	p_camera					 = NULL;
	p_character					 = NULL;
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i]				 = NULL;
	}
	p_stage						 = NULL;
	vp_stageStairs.clear();
	vp_stageStreetLight.clear();
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]		 = NULL;
	}
	for (int i = 0; i != 5; ++i)
	{
		p_dropItem[i] = NULL;
	}
	p_adjustmentMachine = NULL;



	// サウンド読み込み
	SoundProcess::Load(v_file[EFILE::se_ballPickUp], SoundProcess::ESOUNDNAME_SE::ballPickUp, SoundProcess::ESOUNDTYPE::soundMem);


	// ポインタ初期化
	stairsHandle = v_file[EFILE::stairs];
	stairsTexture0 = v_file[EFILE::stairTex0];
	/*for (int i = 0; i != 40; ++i)
	{
		vp_stageStairs.push_back(new StageStairs(v_file[EFILE::stairs], VGet(-100.0f*i, 0.0f, -1000.0f), v_file[EFILE::stairTex0]));
	}*/
	p_stage		 = new Stage(v_file[EFILE::drawStage]);
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);

	streetLightHandle = v_file[EFILE::streetLight];
	streetLightTexture0 = v_file[EFILE::streetLightTex0];
	streetLightTexture1 = v_file[EFILE::streetLightTex1];
	/*for (int i = 0; i != 30; ++i)
	{
		vp_stageStreetLight.push_back(new StageStreetLight(v_file[EFILE::streetLight], VGet(250.0f*i, 0.0f, -100.0f*i)
			, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1]));
	}*/
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], VGet(500.0f * i, 300.0f*i, 100.0f*i));
	}
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i] = new EnemyMove2(VGet(1000.0f + (i * 150), 0.0f, -1000.0f), v_file[EFILE::block], v_file[EFILE::blockTex0]);
	}
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove2(v_file[EFILE::block], p_enemy[i / 5]->GetArea(), v_file[EFILE::blockTex0]);
	}
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminal], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);


	changeAdjustmentScene = false;
	adjustmentDescriptionDraw = v_file[EFILE::terminalDescription];

	catchDropItemNum = 0;


	// スカイボックス読み込み
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox], v_file[EFILE::skyBoxTex0]);


	// 階段のあたり判定
	/*for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		p_character->SetStairsArea(vp_stageStairs[i]->GetArea(), i);
	}*/

	// パネルのあたり判定
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}

	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();
}


MainMove2::~MainMove2()
{
	GRAPHIC_RELEASE(adjustmentDescriptionDraw);

	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}

	for (int i = 0; i != vp_stageStreetLight.size(); ++i)
	{
		POINTER_RELEASE(vp_stageStreetLight[i]);
	}
	vp_stageStreetLight.clear();
	vp_stageStreetLight.shrink_to_fit();

	for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		POINTER_RELEASE(vp_stageStairs[i]);
	}
	vp_stageStairs.clear();
	vp_stageStairs.shrink_to_fit();

	POINTER_RELEASE(p_camera);

	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}

	for (int i = 0; i != enemyNum; ++i)
	{
		POINTER_RELEASE(p_enemy[i]);
	}

	POINTER_RELEASE(p_character);

	POINTER_RELEASE(p_stage);
}


// 描画
void MainMove2::Draw()
{
	if (!changeAdjustmentScene)
	{
		BaseMove::SkyBoxDraw();


		ShadowDraw();


		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			p_dropItem[i]->Draw();
		}


		p_character->Draw();

		if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
		{
			DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescriptionDraw, false);
		}


		DrawFormatString(255, 0, GetColor(255, 255, 255), "手に入れたドロップアイテムの数: %d", catchDropItemNum);
	}
	else
	{
		AdjustmentDraw();
	}
}


// メインプロセス
void MainMove2::Process()
{
	if (!changeAdjustmentScene)
	{
		p_character->Process(p_camera->GetAngle());		// キャラクターのプロセスを呼ぶ


		p_camera->Process(p_character->GetArea());		// カメラのプロセスを呼ぶ


		for (int i = 0; i != enemyNum; ++i)
		{
			if (p_enemy[i]->GetEraseExistence())
			{
				p_dropItem[(i * 5)]->SetAlive(true);
				p_dropItem[(i * 5) + 1]->SetAlive(true);
				p_dropItem[(i * 5) + 2]->SetAlive(true);
				p_dropItem[(i * 5) + 3]->SetAlive(true);
				p_dropItem[(i * 5) + 4]->SetAlive(true);
				continue;
			}
			p_enemy[i]->Process();												// 敵のプロセス
		}

		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			p_dropItem[i]->Process();
		}


		BaseMove::ShadowArea(p_character->GetArea());

		AttackProcess();

		BaseMove::SkyBoxProcess(p_character->GetArea());
	}
	else
	{
		AdjustmentProcess();
	}


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}
#endif
}


void MainMove2::CameraProcess()
{
	if (!changeAdjustmentScene)
	{
		p_camera->SetUp();		// カメラのプロセスを呼ぶ
	}
}



void MainMove2::ThsTextureReload()
{
	p_character->TextureReload();

	p_adjustmentMachine->TextureReload();

	for (int i = 0; i != enemyNum; ++i)
	{
		if (p_enemy[i]->GetDeathFlag()) continue;
		p_enemy[i]->TextureReload();
	}

	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->TextureReload();
	}

	for (int i = 0; i != vp_stageStairs.size(); ++i)
	{
		vp_stageStairs[i]->TextureReload();
	}

	for (int i = 0; i != vp_stageStreetLight.size(); ++i)
	{
		vp_stageStreetLight[i]->TextureReload();
	}
}


void MainMove2::TextureReload()
{
	ths = std::thread(&MainMove2::ThsTextureReload, this);
	ths.join();
}
