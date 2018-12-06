#include "MainMove2.hpp"



void MainMove2::ShadowDraw()
{
	BaseMove::ShadowCharaSetUpBefore();
	p_character->Draw();
	for (int i = 0; i != enemyNum; ++i)
	{
		if (!p_enemy[i]->GetViewDrawFlag()) p_enemy[i]->Draw();
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
		if (!p_enemy[i]->GetViewDrawFlag())	p_enemy[i]->Draw();
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
		if (!p_enemy[i]->GetViewDrawFlag()) p_enemy[i]->Draw();
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
	for (int i = 0; i != enemyNum; ++i)
	{
		// �������Ă��Ȃ������牽�����Ȃ�
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 100.0f)
			&& !p_enemy[i]->GetDeathFlag())
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
		}

		// �U������������
		if (p_character->GetAttackNow() && !p_enemy[i]->GetDeathFlag())
		{
			p_enemy[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}
	}
}


MainMove2::MainMove2(const std::vector<int> v_file)
{
	// �|�C���^NULL������
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
		p_dropItem[i]			 = NULL;
	}


	// �|�C���^������
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


	// �X�J�C�{�b�N�X�ǂݍ���
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox], v_file[EFILE::skyBoxTex0]);


	// �K�i�̂����蔻��
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetStairsArea(p_stageStairs[i]->GetArea(), i);
	}

	// �p�l���̂����蔻��
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


// �`��
void MainMove2::Draw()
{
	BaseMove::SkyBoxDraw();


	ShadowDraw();


	for (int i = 0; i != enemyNum; ++i)
	{
		if (p_enemy[i]->GetViewDrawFlag())
		{
			for (int j = i * 5, n = (i + 1) * 5; j != n; ++j)
			{
				p_dropItem[j]->Draw();
			}
		}
	}


	p_character->Draw();
}


// ���C���v���Z�X
void MainMove2::Process()
{
	p_character->Process(p_camera->GetAngle());		// �L�����N�^�[�̃v���Z�X���Ă�


	p_camera->Process(p_character->GetArea());		// �J�����̃v���Z�X���Ă�


	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i]->Process();												// �G�̃v���Z�X
	}


	BaseMove::ShadowArea(p_character->GetArea());

	AttackProcess();

	BaseMove::SkyBoxProcess(p_character->GetArea());
}


void MainMove2::CameraProcess()
{
	p_camera->SetUp();		// �J�����̃v���Z�X���Ă�
}



void MainMove2::ThsTextureReload()
{
	p_character->TextureReload();

	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemy[i]->TextureReload();
	}

	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
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
