#include "MainMove2.hpp"



void MainMove2::ShadowDraw()
{
	BaseMove::ShadowCharaSetUpBefore();
	p_character->Draw();
	p_enemy->Draw();
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
	p_enemy->Draw();
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
	p_enemy->Draw();
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
	// �������Ă��Ȃ������牽�����Ȃ�
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
		p_enemy->GetArea(), VAdd(p_enemy->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 100.0f))
	{
		p_character->HitCircleReturn(p_enemy->GetArea(), VAdd(p_enemy->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
	}

	// �U������������
	if (p_character->GetAttackNow())
	{
		p_enemy->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
	}
}


MainMove2::MainMove2(const std::vector<int> v_file)
{
	// �|�C���^NULL������
	p_camera					 = NULL;
	p_character					 = NULL;
	p_enemy						 = NULL;
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


	// �|�C���^������
	for (int i = 0; i != 10; ++i)
	{
		p_stageStairs[i] = new StageStairs(v_file[EFILE::stairs], v_file[EFILE::stage], VGet(-100.0f*i, 0.0f, -1000.0f));
	}
	p_stage		 = new Stage(v_file[EFILE::stage]);
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru]);
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);
	for (int i = 0; i != 30; ++i)
	{
		p_stageStreetLight[i] = new StageStreetLight(v_file[EFILE::streetLight], v_file[EFILE::stage], VGet(250.0f*i, 0.0f, -100.0f*i));
	}
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], v_file[EFILE::stage], VGet(500.0f * i, 300.0f*i, 100.0f*i));
	}
	p_enemy = new EnemyMove2(v_file[EFILE::stage], VGet(1000.0f, 0.0f, -1000.0f), v_file[EFILE::block]);


	// �X�J�C�{�b�N�X�ǂݍ���
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox]);


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
	POINTER_RELEASE(p_enemy);
	POINTER_RELEASE(p_character);
	POINTER_RELEASE(p_stage);
}


// �`��
void MainMove2::Draw()
{
	BaseMove::SkyBoxDraw();


	ShadowDraw();


	p_character->Draw();
}


// ���C���v���Z�X
void MainMove2::Process(const unsigned __int8 controllNumber)
{
	p_character->Process(controllNumber, p_camera->GetAngle());		// �L�����N�^�[�̃v���Z�X���Ă�


	p_camera->Process(p_character->GetArea(), controllNumber);		// �J�����̃v���Z�X���Ă�


	p_enemy->Process();												// �G�̃v���Z�X


	BaseMove::ShadowArea(p_character->GetArea());

	AttackProcess();

	BaseMove::SkyBoxProcess(p_character->GetArea());
}


void MainMove2::CameraProcess()
{
	p_camera->SetUp();		// �J�����̃v���Z�X���Ă�
}