#include "MainMove2.hpp"



void MainMove2::ShadowDraw()
{
	BaseMove::ShadowCharaSetUpBefore();
	p_character->Draw();
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
	BaseMove::ShadowCharaSetUpAfter();


	BaseMove::ShadowAnotherCharaSetUpBefore();
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence())	p_enemy[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
	BaseMove::ShadowAnotherCharaSetUpAfter();


	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	p_stage->Draw();
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->Draw();
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->Draw();
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]->Draw();
	}
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
	// ポインタNULL初期化
	p_camera					 = NULL;
	p_character					 = NULL;
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i]				 = NULL;
	}
	p_stage						 = NULL;
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]		 = NULL;
	}
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]	 = NULL;
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]		 = NULL;
	}
	for (int i = 0; i != 5; ++i)
	{
		p_dropItem[i] = NULL;
	}


	// サウンド読み込み
	SoundProcess::Load(v_file[EFILE::se_ballPickUp], SoundProcess::ESOUNDNAME_SE::ballPickUp, SoundProcess::ESOUNDTYPE::soundMem);


	// ポインタ初期化
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i] = new StageStairs(v_file[EFILE::stairs], v_file[EFILE::stage], VGet(-100.0f*i, 0.0f, -1000.0f), v_file[EFILE::stairTex0]);
	}
	p_stage		 = new Stage(v_file[EFILE::drawStage]);
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i] = new StageStreetLight(v_file[EFILE::streetLight], v_file[EFILE::stage], VGet(250.0f*i, 0.0f, -100.0f*i)
			, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1]);
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], v_file[EFILE::stage], VGet(500.0f * i, 300.0f*i, 100.0f*i));
	}
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i] = new EnemyMove2(v_file[EFILE::stage], VGet(1000.0f + (i * 150), 0.0f, -1000.0f), v_file[EFILE::block], v_file[EFILE::blockTex0]);
	}
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove2(v_file[EFILE::block], p_enemy[i / 5]->GetArea(), v_file[EFILE::blockTex0]);
	}


	catchDropItemNum = 0;


	// スカイボックス読み込み
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox], v_file[EFILE::skyBoxTex0]);


	// 階段のあたり判定
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetStairsArea(p_stageStairs[i]->GetArea(), i);
	}

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
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}
	for (int i = 0; i != 30; ++i)
	{
		POINTER_RELEASE(p_stageStreetLight[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stageStairs[i]);
	}
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
	BaseMove::SkyBoxDraw();


	ShadowDraw();


	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i]->Draw();
	}


	p_character->Draw();


	DrawFormatString(255, 0, GetColor(255, 255, 255), "手に入れたドロップアイテムの数: %d", catchDropItemNum);
}


// メインプロセス
void MainMove2::Process()
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


void MainMove2::CameraProcess()
{
	p_camera->SetUp();		// カメラのプロセスを呼ぶ
}



void MainMove2::ThsTextureReload()
{
	p_character->TextureReload();

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

	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i]->TextureReload();
	}

	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i]->TextureReload();
	}
}


void MainMove2::TextureReload()
{
	ths = std::thread(&MainMove2::ThsTextureReload, this);
	ths.join();
}
