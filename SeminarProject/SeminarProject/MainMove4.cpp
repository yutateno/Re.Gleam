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
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\D.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\D.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\D.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\D.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\D.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\D.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\D.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\D.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\D.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\D.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\D.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\D.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\D.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\P.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\P.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\P.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\P.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\P.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\P.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\P.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\P.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\P.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\P.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\P.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\P.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\P.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;
	}
} /// void MainMove4::DamageTextureReload()



/// --------------------------------------------------------------------------------------------------
void MainMove4::ShadowDraw()
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
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// �G
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
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
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// �G
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


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
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		if (!p_ordinaryPerson[i]->GetAlive()) continue;
		p_ordinaryPerson[i]->ModelDraw();
	}
	// �G
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->UniqueModelDraw();
	}
	// �L�����N�^�[
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// �L�����N�^�[
	p_character->ModelDraw();
} /// void MainMove4::ShadowDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove4::AttackProcess()
{
	/// �G�ւ̍U���Ɋւ���--------------------------------------------------------------------------------------------------------
	// ����ł��Ȃ�������
	if (!p_enemyMove->GetDeathFlag())
	{
		// �v���C���[�̍U�����[�V�������I�������
		if (p_character->GetAttackMotionEnd()) enemyDamage = false;


		// �_���[�W���󂯂Ă��Ȃ����v���C���[���U������������
		if (p_character->GetAttackNow() && !enemyDamage)
		{
			p_enemyMove->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// �U���Ń_���[�W���󂯂���
		if (p_enemyMove->GetDamageFlag())
		{
			// �_���[�W���󂯂Ă���Ƃ���
			enemyDamage = true;


			// ��ʐl�𐶐�������
			BASICPARAM::ordinaryPeopleNum++;
			p_ordinaryPerson[BASICPARAM::ordinaryPeopleNum - 1]->SetAlive(p_enemyMove->GetArea());
			

			// �o�C�u���[�V����������
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 10000, 10000);


			// �G�t�F�N�g���Đ�����B
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// if (!p_enemyMove->GetDeathFlag())
	else
	{
		// �ʏ�BGM������Ă��Ȃ�������
		if (nowBattleBGM)
		{
			nowBattleBGM = false;
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::normalBGM);
		}
	}
	/// �G�ւ̍U���Ɋւ���--------------------------------------------------------------------------------------------------------


	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------
	// �������Ă�����v���C���[�������o��
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()
		, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
	{
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
			, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
	}


	// �G�Ɋւ���
	// �Ԃ��鋗����������
	if (BaseMove::GetDistance<int>(p_enemyMove->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		// �������Ă����Ƃ�
		if (HitCheck_Capsule_Capsule(
			p_enemyMove->GetArea(), VAdd(p_enemyMove->GetArea(), VGet(0.0f, p_enemyMove->GetHeight(), 0.0f)), p_enemyMove->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// �G�������o��
			p_enemyMove->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemyMove->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyMove->GetWidth());
		}
	}


	// �v���C���[���߂�������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	// �v���C���[������������
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}


	// �v���C���[�Ƃ̋������߂��āA�G���{�^����������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		BASICPARAM::paneruDrawFlag = true;
	}
	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------


	/// �L�����N�^�[���牟���o�����----------------------------------------------------------------------------------------------------------------------
	// ����ł��Ȃ��ăv���C���[�Ƃ̋������߂�������
	if (!p_enemyMove->GetDeathFlag()
		&& BaseMove::GetDistance<int>(p_enemyMove->GetArea(), p_character->GetArea()) <= 250)
	{
		// �v���C���[�Ɠ������Ă�����
		if (HitCheck_Capsule_Capsule(
			p_enemyMove->GetArea(), VAdd(p_enemyMove->GetArea(), VGet(0.0f, p_enemyMove->GetHeight(), 0.0f)), p_enemyMove->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// �T�C�Y���傫��������
			if (p_enemyMove->GetBigNow())
			{
				// �v���C���[�������o��
				p_character->HitCircleReturn(p_enemyMove->GetArea()
					, p_character->GetWidth() >= p_enemyMove->GetWidth() ? p_character->GetWidth() : p_enemyMove->GetWidth());
			}
			// �T�C�Y���傫���Ȃ�������
			else
			{
				// �G�������o��
				p_enemyMove->HitCircleReturn(p_character->GetArea()
					, p_character->GetWidth() >= p_enemyMove->GetWidth() ? p_character->GetWidth() : p_enemyMove->GetWidth());
			}
		}
	}
	/// �L�����N�^�[���牟���o�����----------------------------------------------------------------------------------------------------------------------
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
	// ������
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::ordinaryPeopleNum = 0;


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
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i] = nullptr;
	}
	p_enemyBossBefore = nullptr;
	p_enemyMove = nullptr;
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();


	// ���[�u����
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 400;


	// �X�e�[�W�̏�����
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// �L�����N�^�[�̏�����
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);


	// �J�����̏�����
	p_camera = new Camera(p_character->GetArea());


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


	// �����@�B�̏�����
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminalModel], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);
	for (int i = 0; i != 15; ++i)
	{
		p_adjustmentMachine->CatchDropItem();
	}
	adjustmentDescDraw = v_file[EFILE::terminalDesc];


	// �l�̏�����
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i] = new OrdinaryPerson(v_file[EFILE::ordiPersonModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::ordiPersonTex0], VGet(-1000.0f + i * 100.0f, i + 200.0f, 1000.0f), 0.0f);
	}


	// �G�̏�����
	p_enemyBossBefore = new EnemyBossBefore();
	p_enemyMove = new EnemyMove4(v_file[EFILE::enemyModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::enemyTex0], VGet(1000, 0, 1000), 0.0f);
	enemyAndPlayerDistance = 0;
	enemyScreenArea = VGet(0, 0, 0);
	enemyDamage = false;


	// �X�J�C�{�b�N�X
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// �X�e�[�W�̏�
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// �T�E���h�̃��[�h
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


	// �_���[�W���o
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


	// �G�t�F�N�g�ǂݍ���
	effeckBack[0] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\one.efk");
	effeckBack[1] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\two.efk");
	effeckBack[2] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\three.efk");
	effeckBack[3] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\four.efk");
	effeckBack[4] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\five.efk");
	effeckBack[5] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\six.efk");
	effeckBack[6] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\seven.efk");
	effeckBack[7] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\eight.efk");
	effeckBack[8] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\nine.efk");
	effeckBack[9] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\ten.efk");
	playingEfDamage = -1;
	effectAttack = LoadEffekseerEffect("media\\������\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
} /// MainMove4::MainMove4(const std::vector<int> v_file)



/// --------------------------------------------------------------------------------------------------
MainMove4::~MainMove4()
{
	// �G�t�F�N�g�J��
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);


	// �_���[�W���o
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


	// �G
	POINTER_RELEASE(p_enemyBossBefore);
	POINTER_RELEASE(p_enemyMove);


	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		POINTER_RELEASE(p_ordinaryPerson[i]);
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


	/// �����摜���
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove4::~MainMove4()



/// --------------------------------------------------------------------------------------------------
void MainMove4::Draw()
{
	// �X�J�C�{�b�N�X��`��
	BaseMove::SkyBoxDraw();


	// �V���h�E�}�b�v��`��
	ShadowDraw();


	// �G���X�{�X�̂���
	p_enemyBossBefore->ModelDraw();


	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		// ���݂�������Ă��Ȃ�������
		if (!p_ordinaryPerson[i]->GetAlive()) continue;


		p_ordinaryPerson[i]->Draw();
	}


	// �G
	if (!p_enemyMove->GetDeathFlag())
	{
		p_enemyMove->Draw();
	}


	// �L�����N�^�[
	p_character->Draw();


	// �����@�B�Ƃ̋������߂��Ƃ�
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// �����摜��\��
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}

	/// ���b�N�I���Ɋւ���------------------------------------------------------------------------------------------------------------
	// ���݂��Ă�����
	if (!p_enemyMove->GetEraseExistence())
	{
		// �U���͈͓���������
		if (enemyAndPlayerDistance < 250)
		{
			// ���_
			DrawBox(static_cast<int>(enemyScreenArea.x - 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x + 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
			// �c�_
			DrawBox(static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y - 20.0f - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y + 20.0f - p_enemyMove->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
		}
		// �U���͈͊O��������
		else
		{
			// ���_
			DrawBox(static_cast<int>(enemyScreenArea.x - 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x + 20.0f)
				, static_cast<int>(enemyScreenArea.y - p_enemyMove->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
			// �c�_
			DrawBox(static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y - 20.0f - p_enemyMove->GetHeight() / 2.0f)
				, static_cast<int>(enemyScreenArea.x)
				, static_cast<int>(enemyScreenArea.y + 20.0f - p_enemyMove->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
		}
	} /// if (!p_enemyMove->GetEraseExistence())
	/// ���b�N�I���Ɋւ���------------------------------------------------------------------------------------------------------------


	/// �_���[�W�Ɋւ���-----------------------------------------------------------------------------------------------------------
	/// �G�t�F�N�g���Đ�����-------------------------------------------------------------------------------
	if (preDamageCount != damageCount / 10)
	{
		// �_���[�W�J�E���g��10�̔{���Ŏ����O�̃G�t�F�N�g�ɐ؂�ւ���
		preDamageCount = damageCount / 10;


		// �G�t�F�N�g���Đ�����������
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);


		// �G�t�F�N�g���Đ�����
		playingEfDamage = PlayEffekseer2DEffect(effeckBack[preDamageCount - 1]);
		SetScalePlayingEffekseer2DEffect(playingEfDamage, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfDamage, 960, 540, 0);
	}
	// �_���[�W���󂯂Ă��Ȃ�������
	if (damageCount == 0)
	{
		// �G�t�F�N�g���~�߂�
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);
	}
	/// �G�t�F�N�g���Đ�����-------------------------------------------------------------------------------


	/// �_���[�W�̉��o
	if (damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	/// �_���[�W�̒~�ςŉ�ʂ𖄂ߐs��������-----------------------------------------------
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
	/// �_���[�W�̒~�ςŉ�ʂ𖄂ߐs��������-----------------------------------------------
	/// �_���[�W�Ɋւ���-----------------------------------------------------------------------------------------------------------


	// ���[�u����������
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
	// �L�����N�^�[�̃v���Z�X
	p_character->Process(p_camera->GetAngle());


	/// �_���[�W���󂯂Ă��Ȃ��J�E���g���ŏ���---------------------------------------------------------
	notDamageCount++;


	// �_���[�W���󂯂Ă��Ȃ�������񕜂�����
	if (notDamageCount > 100 && damageCount > 0 && (notDamageCount - 100) % 10 == 0) damageCount--;


	// �_���[�W���o�摜���c���Ă����炾�񂾂����
	if (damageDrawFrame > 0) damageDrawFrame--;
	/// �_���[�W���󂯂Ă��Ȃ��J�E���g���ŏ���---------------------------------------------------------


	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());


	// �l
	for (int i = 0; i != ordinaryNum; ++i)
	{
		p_ordinaryPerson[i]->Process();
	}


	// �G���X�{�X�̂���
	p_enemyBossBefore->Process();


	// �G
	// ���ł��Ă��Ȃ�������
	if (!p_enemyMove->GetEraseExistence())
	{
		p_enemyMove->Process();		// �v���Z�X���Ă�

		
		// ����ł��Ȃ�������
		if (!p_enemyMove->GetDeathFlag())
		{
			// ���b�N�I���̏����X�V����
			enemyAndPlayerDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyMove->GetArea());
			enemyScreenArea = ConvWorldPosToScreenPos(p_enemyMove->GetArea());


			// �v���C���[���王�F�ł���͈͂�������
			if (enemyAndPlayerDistance < 250)
			{
				p_character->SetMostNearEnemyArea(p_enemyMove->GetArea());
			}
			// �v���C���[���王�F�ł��Ȃ��͈͂�������
			else
			{
				p_character->SetMostNearEnemyArea();
			}


			// �v���C���[�̈ʒu�Ƌ������擾����
			p_enemyMove->SetCharacterArea(p_character->GetArea(), enemyAndPlayerDistance);


			// �v���C���[�ɑ΂��čU���o������
			if (p_enemyMove->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemyMove->GetArea().y + p_enemyMove->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyMove->GetArea().y)
			{
				// �U��SE�𗬂�
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemyMove->GetArea(), 180);


				p_character->SetDamage();		// �v���C���[�Ƀ_���[�W��^����


				// �_���[�W���󂯂Ă��Ȃ��J�E���g��0����Ȃ�������
				if (notDamageCount != 0) notDamageCount = 0;


				// �_���[�W���l��100�ȉ���������
				if (damageCount < 100)	damageCount++;


				// �_���[�W���o�摜���o�Ă��Ȃ�������
				if (damageDrawFrame == 0)
				{
					std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
					std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
					std::uniform_int_distribution<> blood(0, 2);        // X���W�p����
					damageDrawID = blood(mt);		// �����_���Ń_���[�W�摜��\������
					damageDrawFrame = 10;			// 10�t���[�������\������悤�ɂ���
				}
			}
		} /// if (!p_enemyMove->GetDeathFlag())
	} /// if (!p_enemyMove->GetEraseExistence())
	

	// �V���h�E�}�b�v�̍��W���X�V
	BaseMove::ShadowArea(p_character->GetArea());

	
	// �����蔻��v���Z�X
	AttackProcess();


	// �X�J�C�{�b�N�X�̍��W���X�V
	BaseMove::SkyBoxProcess(p_character->GetArea());


	// ���̃V�[���ֈڍs����ꏊ�ɋ�����
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
	// �L�����N�^�[�̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// �_���[�W���o
		DamageTextureReload();


		// �L�����N�^�[
		p_character->TextureReload();
	}


	// �G
	if (!BASICPARAM::enemyTextureWhiteBlack)
	{
		if (!p_enemyMove->GetDeathFlag())
		{
			p_enemyMove->TextureReload();
		}
	}


	// ���̑��̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// �����@�B
		p_adjustmentMachine->TextureReload();


		// �l
		for (int i = 0; i != ordinaryNum; ++i)
		{
			p_ordinaryPerson[i]->TextureReload();
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
