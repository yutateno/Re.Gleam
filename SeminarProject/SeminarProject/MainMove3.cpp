#include "MainMove3.hpp"


void MainMove3::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// �����@�B
	p_adjustmentMachine->Draw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	// �L�����N�^�[
	p_character->Draw();
	BaseMove::ShadowCharaSetUpAfter();

	/// �L�����N�^�[�ȊO�ăZ�b�g�A�b�v
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// �����@�B
	p_adjustmentMachine->Draw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	BaseMove::ShadowAnotherCharaSetUpAfter();

	/// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->Draw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->Draw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->Draw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->Draw();
		}
	}
	// �����@�B
	p_adjustmentMachine->Draw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Draw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Draw();
	}
	// �L�����N�^�[
	p_character->Draw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
}

void MainMove3::AttackProcess()
{
	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------
	// �������Ă����牟���o��
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
	// �߂����ǂ����Ō����ڂ�ς���
	if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}


	/// �L�����N�^�[�������o��
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


	/// �G���m�ŉ����o��
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


	/// �h���b�v�Ɋւ���--------------------------------------------------------------------------------------
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
			p_dropItem[i]->SetDeath(true);			// ���������Ȃ�

			/// SE�̍Đ��������_���ɂ���-----------------------------------------------------------------------------
			//std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
			//std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
			//std::uniform_int_distribution<> randPawnSE(0, 1);        // ����

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


	// �|�C���^NULL������
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


	// �X�e�[�W�̏�����
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// �L�����N�^�[�̏�����
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	charaSonmeEnemyDamageCount = 0;

	// �J�����̏�����
	p_camera = new Camera(p_character->GetArea(), v_file[EFILE::stageCollModel]);

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
				, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1], BASICPARAM::v_stairsAngle[i]);
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

	// �����@�B�̏�����
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminalModel], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);
	for (int i = 0; i != 15; ++i)
	{
		p_adjustmentMachine->CatchDropItem();
	}
	adjustmentDescDraw = v_file[EFILE::terminalDesc];

	// �G�X���C���̏�����
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i] = new EnemyMove3Slime(v_file[EFILE::slimeModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::slimeTex0], VGet(1000.0f - (i * 150.0f), 0.0f, 1000.0f), 0.0f);
	}

	// �G�N�������q���[�}���̏�����
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i] = new EnemyMove3CrayonHuman(v_file[EFILE::crayonHumanModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::crayonHumanTex0], VGet(-1500.0f + (i * 150.0f), 0.0f, -1000.0f), 0.0f);
	}

	// �h���b�v�A�C�e���̏�����
	catchDropItemNum = 0;
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove3(v_file[EFILE::dropItemModel], p_character->GetArea(), v_file[EFILE::dropItemTex0]);
	}

	// �X�J�C�{�b�N�X
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);

	// �X�e�[�W�̏�
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();

	// �T�E���h�̃��[�h
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
}

MainMove3::~MainMove3()
{
	// �h���b�v�A�C�e��
	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		POINTER_RELEASE(p_enemyCrayonHuman[i]);
	}
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		POINTER_RELEASE(p_enemySlime[i]);
	}

	// �����@�B
	GRAPHIC_RELEASE(adjustmentDescDraw);
	POINTER_RELEASE(p_adjustmentMachine);

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
	POINTER_RELEASE(p_camera);

	// �L�����N�^�[
	POINTER_RELEASE(p_character);

	// �X�e�[�W
	POINTER_RELEASE(p_stage);
}

void MainMove3::Draw()
{
	BaseMove::SkyBoxDraw();


	ShadowDraw();


	for (int i = 0, n = enemySlimeNum + enemyCrayonHumanNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->Draw();
	}


	p_character->Draw();


	if (p_adjustmentMachine->GetCanTouch())
	{
		if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
		{
			DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
		}
	}

	DrawFormatString(1020, 20, GetColor(0, 0, 0), "��ɓ��ꂽ�h���b�v�A�C�e���̐�: %d", catchDropItemNum);
}

void MainMove3::Process()
{
	// �L�����N�^�[�̃v���Z�X
	p_character->Process(p_camera->GetAngle());
	charaSonmeEnemyDamageCount = 0;

	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());

	// �G�X���C���̃v���Z�X
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i]->Process();
		p_enemySlime[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance(p_character->GetArea(), p_enemySlime[i]->GetArea()));
		if (p_enemySlime[i]->GetAttackDamage()
			&& p_character->GetArea().y <= p_enemySlime[i]->GetArea().y + p_enemySlime[i]->GetHeight()
			&& p_character->GetArea().y + p_character->GetHeight() >= p_enemySlime[i]->GetArea().y)
		{
			if (charaSonmeEnemyDamageCount++ < 2)
			{
				p_character->SetDamage();
			}
		}
	}

	// �G�N�������q���[�}���̃v���Z�X
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i]->Process();
		p_enemyCrayonHuman[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()));
		if (p_enemyCrayonHuman[i]->GetAttackDamage()
			&& p_character->GetArea().y <= p_enemyCrayonHuman[i]->GetArea().y + p_enemyCrayonHuman[i]->GetHeight()
			&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyCrayonHuman[i]->GetArea().y)
		{
			if (charaSonmeEnemyDamageCount++ < 2)
			{
				p_character->SetDamage();
			}
		}
	}

	// �h���b�v�A�C�e��
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
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}
#endif
}

void MainMove3::CameraProcess()
{
	p_camera->SetUp();
}

void MainMove3::TextureReload()
{
	// �L�����N�^�[
	p_character->TextureReload();

	// �����@�B
	p_adjustmentMachine->TextureReload();

	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->TextureReload();
		}
	}

	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->TextureReload();
		}
	}

	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->TextureReload();
		}
	}

	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag()) continue;
		p_enemySlime[i]->TextureReload();
	}

	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;
		p_enemyCrayonHuman[i]->TextureReload();
	}

	// �h���b�v�A�C�e��
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
