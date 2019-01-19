#include "MainMove6.hpp"


// �V���h�E�}�b�v�̕`��
void MainMove6::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// �L�����N�^�[
	p_character->ModelDraw();


	/// �L�����N�^�[�ȊO�ăZ�b�g�A�b�v
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	BaseMove::ShadowSetUpAfter();


	/// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �K�i
	if (BASICPARAM::lastStairsView)
	{
		if (BASICPARAM::stairsNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
			{
				vp_stageStairs[i]->ModelDraw();
			}
		}
	}
	// �X��
	if (BASICPARAM::lastStreetLightView)
	{
		if (BASICPARAM::streetLightNum != 0)
		{
			for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
			{
				vp_stageStreetLight[i]->ModelDraw();
			}
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::lastStairsRoadView)
	{
		if (BASICPARAM::stairsRoadNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
			{
				vp_stageStairsRoad[i]->ModelDraw();
			}
		}
	}
	// �p�l��
	if (BASICPARAM::lastPaneruView)
	{
		if (BASICPARAM::paneruDrawFlag)
		{
			for (int i = 0; i != 10; ++i)
			{
				p_stagePaneru[i]->ModelDraw();
			}
		}
	}
	// ��ʐl
	if (BASICPARAM::lastOrdinaryView)
	{
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->ModelDraw();
			}
		}
	}
	// �L�����N�^�[
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// �L�����N�^�[
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
} /// void MainMove6::ShadowDraw()


// �����蔻��̃v���Z�X
void MainMove6::AttackProcess()
{
	/// �v���C���[�ɐG���ꂽ��-----------------------------------------------------
	//for (int i = 0; i != enemyNum; ++i)
	//{
	//	// ����ł��邩�v���C���[�Ƃ̋������߂��ł͂Ȃ�������
	//	if (p_enemyMove[i]->GetDeathFlag()
	//		|| BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_character->GetArea()) > 250) continue;


	//	// �v���C���[�Ɠ������Ă�����
	//	if (HitCheck_Capsule_Capsule(
	//		p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth(),
	//		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
	//	{
	//		// ����
	//		p_enemyMove[i]->SetDie();
	//		enemyCatchNum++;
	//	}
	//}
	/// �v���C���[���牟���o�����-----------------------------------------------------
} /// void MainMove6::AttackProcess()


// �e�N�X�`���̔񓯊��ǂݍ���
void MainMove6::ThsTextureReload()
{
	ths = std::thread(&MainMove6::TextureReload, this);
	ths.join();
}


// �ŏ��̕`��
void MainMove6::FirstDraw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X��`��


	ShadowDraw();		// �V���h�E�}�b�v��`��


	// �G���X�{�X�̂���
	p_enemyBossBefore->ModelDraw();


	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Draw();
		}
	}


	p_character->Draw();	// �L�����N�^�[��`��



	// �{�X�Ƌ������߂�������UI��\������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) < 250)
	{
		DrawGraph(960 - 200, 540 - 69 - 50, approachBossUIDraw[0], false);
		DrawGraph(960 - 500, 540 - 69 + 250, approachBossUIDraw[1], false);
		DrawGraph(960 + 100, 540 - 69 + 250, approachBossUIDraw[2], false);


		// �߂Â��ɃJ�[�\�����������Ƃ�
		if (approachUISelect)
		{
			DrawBox(960 - 500 + 5, 540 - 69 + 250 + 5, 960 - 500 + 400 - 5, 540 - 69 + 250 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(960 - 500 + 4, 540 - 69 + 250 + 4, 960 - 500 + 400 - 4, 540 - 69 + 250 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(960 - 500 + 3, 540 - 69 + 250 + 3, 960 - 500 + 400 - 3, 540 - 69 + 250 + 69 - 3, GetColor(50, 50, 200), false);
		}
		// �����ɃJ�[�\�����������Ƃ�
		else
		{

			DrawBox(960 + 100 + 5, 540 - 69 + 250 + 5, 960 + 100 + 400 - 5, 540 - 69 + 250 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(960 + 100 + 4, 540 - 69 + 250 + 4, 960 + 100 + 400 - 4, 540 - 69 + 250 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(960 + 100 + 3, 540 - 69 + 250 + 3, 960 + 100 + 400 - 3, 540 - 69 + 250 + 69 - 3, GetColor(50, 50, 200), false);
		}
	}
} /// void MainMove6::FirstDraw()


// �ŏ��̃v���Z�X
void MainMove6::FirstProcess()
{
	// �{�X�Ƌ������������Ƃ�
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) >= 250)
	{
		// �L�����N�^�[�̃v���Z�X
		p_character->Process(p_camera->GetAngle());


		// �J�����̃v���Z�X
		p_camera->Process(p_character->GetArea());


		// ��ʐl�̃v���Z�X
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->Process();
			}
		}


		// �G���X�{�X�̂���
		p_enemyBossBefore->Process();


		// �V���h�E�}�b�v�̈ʒu���X�V
		BaseMove::ShadowArea(p_character->GetArea());


		// �X�J�C�{�b�N�X�̈ʒu���X�V
		BaseMove::SkyBoxProcess(p_character->GetArea());
	} /// if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) >= 250)
	// �{�X�Ƌ߂�������
	else
	{
		/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����----------------------------------------------------------------------
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			if (adjustmentControllStick[0] < 2) adjustmentControllStick[0]++;
		}
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			if (adjustmentControllStick[1] < 2) adjustmentControllStick[1]++;
		}
		else
		{
			adjustmentControllStick[0] = 0;
			adjustmentControllStick[1] = 0;
		}
		// �J�[�\�������Ɉړ�
		if (adjustmentControllStick[0] == 1)
		{
			approachUISelect = true;
		}
		// �J�[�\�����E�Ɉړ�
		if (adjustmentControllStick[1] == 1)
		{
			approachUISelect = false;
		}
		/// ---------------------------------------------------------------------------------------------------------------


		// ����{�^������������
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
		{
			// �߂Â��ɃJ�[�\�����������Ƃ�
			if (approachUISelect)
			{
				e_nowMove = ESceneMove6::Movie;
				p_cameraMove->SetView(VGet(4000, 50, 0));
				p_cameraMove->SetArea(VGet(3000, 200, 0));
				movieFrame = 0;
			}
			// �߂Â��Ȃ��ɃJ�[�\�����������Ƃ�
			else
			{
				p_character->PositionReset();
			}
		}
	} /// else(!if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) >= 250))
} /// void MainMove6::FirstProcess()


// ���[�r�[���̕`��
void MainMove6::MovieDraw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X��`��


	ShadowDraw();		// �V���h�E�}�b�v��`��


	// �G���X�{�X�̂���
	p_enemyBossBefore->ModelDraw();


	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Draw();
		}
	}


	p_character->Draw();	// �L�����N�^�[��`��
} /// void MainMove6::MovieDraw()


// ���[�r�[���̃v���Z�X
void MainMove6::MovieProcess()
{
	// �������Ǘ�
	movieFrame++;


	// �{�X�O�̃v���Z�X���Ă�
	p_enemyBossBefore->Process();


	// �V���h�E�}�b�v�̈ʒu���X�V
	BaseMove::ShadowArea(p_cameraMove->GetArea());


	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_cameraMove->GetArea());


	/// �A�N�^�[���Ƃ̕`��Ɋւ���---------------------------------------------
	// 300�t���[���ȏゾ������n�ʂɖ��܂点��
	if (movieFrame >= 300)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Move6SetDownArea();
		}
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Move6SetDownArea();
		}
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Move6SetDownArea();
		}
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Move6SetDownArea();
		}
	}


	// 600�t���[���ȏゾ������n�ʂɖ��܂点��
	if (movieFrame >= 600)
	{
		p_enemyBossBefore->AreaSetDown();
	}


	// 800�t���[���ȏゾ������n�ʂɖ��܂点��
	if (movieFrame >= 800)
	{
		p_character->AreaSetDown();
	}
	/// �A�N�^�[���Ƃ̕`��Ɋւ���---------------------------------------------


	/// �J�����Ɋւ���------------------------------------------------------------------
	// 200�t���[���ȉ���������
	if (movieFrame <= 200)
	{
		// ����ł��Ȃ��v���C���[�̃v���Z�X���Ă�
		p_character->NotOpeProcess(p_camera->GetAngle());
		p_enemyBossBefore->MoveReturn();
	}


	// 200�t���[����葽��300�t���[���ȉ���������
	if (movieFrame > 200 && movieFrame <= 400)
	{
		p_cameraMove->SetView(VGet(4000 - (movieFrame - 200) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(3000 - (movieFrame - 200) * 10.0f, 200, 0));
		p_cameraMove->SetView(VGet(1000, 0, 1000));
	}


	// 300�t���[����葽��400�t���[���ȉ���������
	if (movieFrame > 400 && movieFrame <= 600)
	{
		p_cameraMove->SetView(VGet(2000 + (movieFrame - 400) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(1000 + (movieFrame - 400) * 10.0f, 200, 0));
		p_enemyBossBefore->MoveReturn();
	}
	/// �J�����Ɋւ���------------------------------------------------------------------

	
	if (movieFrame >= 1000)
	{
		SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::boss);
		e_nowMove = ESceneMove6::Battle;
		p_character->PositionReset();
	}
} /// void MainMove6::MovieProcess()


// �퓬�̕`��
void MainMove6::BattleDraw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X��`��

	
	p_stage->Draw();


	p_character->ModelDraw();
	p_character->Draw();
} /// void MainMove6::BattleDraw()


// �퓬�̃v���Z�X
void MainMove6::BattleProcess()
{
	// �L�����N�^�[�̃v���Z�X
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());


	// �V���h�E�}�b�v�̈ʒu���X�V
	BaseMove::ShadowArea(p_character->GetArea());


	AttackProcess();		// �����蔻��̃v���Z�X


	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_character->GetArea());


	// test
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::ending);
		e_nowMove = ESceneMove6::Last;
		p_character->PositionReset();
		movieFrame = 0;
	}
} /// void MainMove6::BattleProcess()


// �Ō�̕`��
void MainMove6::LastDraw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X��`��


	p_stage->Draw();


	p_character->ModelDraw();
	p_character->Draw();


	DrawGraph(960 - 600	, (1080 + 0) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::title)], false);
	DrawGraph(50		, (1080 + 400) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::program)], false);
	DrawGraph(50		, (1080 + 600) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::graphic)], false);
	DrawGraph(50		, (1080 + 800) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::sound)], false);
	DrawGraph(960 - 400	, (2160 + 300) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::libThanks)], false);
	DrawGraph(50		, (2160 + 450) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::dxlib)], false);
	DrawGraph(50		, (2160 + 650) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::effekseer)], false);
	DrawGraph(960 - 300	, (3240 + 0) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::specialThanks)], false);
	DrawGraph(50		, (3240 + 150) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::test)], false);
	DrawGraph(50		, (3240 + 350) - movieFrame, endrolDraw[static_cast<int>(EEndRolUI::youser)], false);
} /// void MainMove6::LastDraw()


// �Ō�̃v���Z�X
void MainMove6::LastProcess()
{
	movieFrame++;


	// �L�����N�^�[�̃v���Z�X
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());


	// �V���h�E�}�b�v�̈ʒu���X�V
	BaseMove::ShadowArea(p_character->GetArea());


	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_character->GetArea());


	if (movieFrame >= 3700)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SIXLOAD);
	}
} /// void MainMove6::LastProcess()


// �R���X�g���N�^
MainMove6::MainMove6(const std::vector<int> v_file)
{
	// ������
	BASICPARAM::paneruDrawFlag = false;


	// �|�C���^NULL������
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_stage = nullptr;
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = nullptr;
	}
	p_enemyBossBefore = nullptr;
	for (int i = 0; i != 3; ++i)
	{
		approachBossUIDraw[i] = -1;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();
	vp_ordinaryPerson.clear();


	// �X�e�[�W�̏�����
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// �L�����N�^�[�̏�����
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);


	// �J�����̏�����
	p_camera = new Camera(p_character->GetArea());
	p_cameraMove = new CameraMove6();


	// �p�l���̏�����
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(500.0f * i, 300.0f * i, 100.0f * i));
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// �K�i�Ə��̏�����
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


	// �X���̏�����
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


	// �K�i�̏�����
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


	// �G�̏�����
	p_enemyBossBefore = new EnemyBossBefore(v_file[EFILE::bossBeforeModel], v_file[EFILE::bossBeforeTex0], v_file[EFILE::bossBeforeTex1], v_file[EFILE::bossBeforeTex2]);
	approachBossUIDraw[0] = v_file[EFILE::approachUINear];
	approachBossUIDraw[1] = v_file[EFILE::approachUIYes];
	approachBossUIDraw[2] = v_file[EFILE::approachUINo];
	approachUISelect = true;


	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
		std::uniform_int_distribution<> randInX(-4000, 4000);        // X���W�p����
		std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z���W�p����


		vp_ordinaryPerson.resize(BASICPARAM::ordinaryPeopleNum);
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			// X���W�ݒ�
			float tempX = static_cast<float>(randInX(mt));
			if (tempX <= 200.0f && tempX >= 0.0f)
			{
				tempX += 200.0f;
			}
			if (tempX >= -200.0f && tempX <= 0.0f)
			{
				tempX -= 200.0f;
			}

			// Y���W�ݒ�
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


	// �X�J�C�{�b�N�X
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// �X�e�[�W�̏�
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// �G���h���[���֘A
	for (int i = 0; i != 10; ++i)
	{
		endrolDraw[i] = -1;
	}
	endrolDraw[static_cast<int>(EEndRolUI::title)]			 = v_file[EFILE::end_Title];
	endrolDraw[static_cast<int>(EEndRolUI::program)]		 = v_file[EFILE::end_Program];
	endrolDraw[static_cast<int>(EEndRolUI::graphic)]		 = v_file[EFILE::end_Graphic];
	endrolDraw[static_cast<int>(EEndRolUI::sound)]			 = v_file[EFILE::end_Sound];
	endrolDraw[static_cast<int>(EEndRolUI::libThanks)]		 = v_file[EFILE::end_ThanksLib];
	endrolDraw[static_cast<int>(EEndRolUI::dxlib)]			 = v_file[EFILE::end_DxLib];
	endrolDraw[static_cast<int>(EEndRolUI::effekseer)]		 = v_file[EFILE::end_Effekseer];
	endrolDraw[static_cast<int>(EEndRolUI::specialThanks)]	 = v_file[EFILE::end_Special];
	endrolDraw[static_cast<int>(EEndRolUI::test)]			 = v_file[EFILE::end_Test];
	endrolDraw[static_cast<int>(EEndRolUI::youser)]			 = v_file[EFILE::end_Youser];


	// �T�E���h�̃��[�h
	SoundProcess::Load(v_file[EFILE::se_attackOne], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_foot], SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor], SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump], SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing], SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond], SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main], SoundProcess::ESOUNDNAME_BGM::boss);
	SoundProcess::Load(v_file[EFILE::bgm_end], SoundProcess::ESOUNDNAME_BGM::ending);
	
	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::boss, 0, 0);
} /// MainMove6::MainMove6(const std::vector<int> v_file)


// �f�X�g���N�^
MainMove6::~MainMove6()
{
	// �G���h���[��
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(endrolDraw[i]);
	}


	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_ordinaryPerson[i]);
		}
		vp_ordinaryPerson.clear();
		vp_ordinaryPerson.shrink_to_fit();
	}


	// �G
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(approachBossUIDraw[i]);
	}
	POINTER_RELEASE(p_enemyBossBefore);


	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairs[i]);
		}
		vp_stageStairs.clear();
		vp_stageStairs.shrink_to_fit();
	}


	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStreetLight[i]);
		}
		vp_stageStreetLight.clear();
		vp_stageStreetLight.shrink_to_fit();
	}


	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairsRoad[i]);
		}
		vp_stageStairsRoad.clear();
		vp_stageStairsRoad.shrink_to_fit();
	}


	// �p�l��
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// �J����
	POINTER_RELEASE(p_cameraMove);
	POINTER_RELEASE(p_camera);


	// �L�����N�^�[
	POINTER_RELEASE(p_character);


	// �X�e�[�W
	POINTER_RELEASE(p_stage);
} /// MainMove5::~MainMove5()


// �`��
void MainMove6::Draw()
{
	switch (e_nowMove)
	{
	case ESceneMove6::First:
		FirstDraw();
		break;


	case ESceneMove6::Movie:
		MovieDraw();
		break;


	case ESceneMove6::Battle:
		BattleDraw();
		break;


	case ESceneMove6::Last:
		LastDraw();
		break;


	default:
		break;
	}
	
} /// void MainMove6::Draw()


// �v���Z�X
void MainMove6::Process()
{
	switch (e_nowMove)
	{
	case ESceneMove6::First:
		FirstProcess();
		break;


	case ESceneMove6::Movie:
		MovieProcess();
		break;


	case ESceneMove6::Battle:
		BattleProcess();
		break;


	case ESceneMove6::Last:
		LastProcess();
		break;


	default:
		break;
	}
	


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}
#endif
} /// void MainMove6::Process()


// �J�����̍ăZ�b�g�A�b�v
void MainMove6::CameraProcess()
{
	if (e_nowMove == ESceneMove6::Movie)
	{
		p_cameraMove->SetUp();
	}
	else
	{
		p_camera->SetUp();
	}
}


// �e�N�X�`���̓ǂݍ���
void MainMove6::TextureReload()
{
	// �L�����N�^�[�̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// �L�����N�^�[
		p_character->TextureReload();
	}


	// ���̑��̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// ��ʐl
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->TextureReload();
			}
		}
	}


	// �K�i�̃e�N�X�`���������w�肶��Ȃ�������
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


	// �X���̃e�N�X�`���������w�肶��Ȃ�������
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


	// �K�i�Ə��̃e�N�X�`���������w�肶��Ȃ�������
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


// �I�v�V������ʃ��f���̕`��
void MainMove6::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// �I�v�V������ʃ��f���̕`��̏���
void MainMove6::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// �I�v�V������ʃ��f���̕`��̌�n��
void MainMove6::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}