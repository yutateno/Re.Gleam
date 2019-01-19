#include "MainMove5.hpp"


// �V���h�E�}�b�v�̕`��
void MainMove5::ShadowDraw()
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
	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// �G
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
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
	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// �G
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


	/// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �K�i
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
	// �X��
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
	// �K�i�Ə�
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
	// �p�l��
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
	// �����@�B
	if (enemyCatchNum >= 5)
	{
		p_adjustmentMachine->ModelDraw();
	}
	// ��ʐl
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
	// �G
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i]->ModelDraw();
	}
	// �L�����N�^�[
	if (enemyCatchNum >= 30)
	{
		p_character->ModelDraw();
	}
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// �L�����N�^�[
	if (enemyCatchNum >= 30)
	{
		p_character->ModelDraw();
	}
} /// void MainMove5::ShadowDraw()


// �����蔻��̃v���Z�X
void MainMove5::AttackProcess()
{
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
	for (int i = 0; i != enemyNum; ++i)
	{
		// �Ԃ��鋗����������
		if (BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
		{
			// �������Ă����Ƃ�
			if (HitCheck_Capsule_Capsule(
				p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth()
				, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
			{
				// �G�������o��
				p_enemyMove[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
					, p_adjustmentMachine->GetWidth() >= p_enemyMove[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyMove[i]->GetWidth());
			}
		}
	}


	// �v���C���[�Ƃ̋������߂��āA�G���{�^����������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		BASICPARAM::paneruDrawFlag = true;
	}


	// �v���C���[�Ƌ������߂�������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	// �v���C���[�Ƌ���������������
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}
	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------


	/// �v���C���[�ɐG���ꂽ��-----------------------------------------------------
	for (int i = 0; i != enemyNum; ++i)
	{
		// ����ł��邩�v���C���[�Ƃ̋������߂��ł͂Ȃ�������
		if (p_enemyMove[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// �v���C���[�Ɠ������Ă�����
		if (HitCheck_Capsule_Capsule(
			p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// ����
			p_enemyMove[i]->SetDie();
			enemyCatchNum++;
		}
	}
	/// �v���C���[���牟���o�����-----------------------------------------------------
	

	/// �G���m�ŉ����o��----------------------------------------------------------------
	for (int i = 0; i != enemyNum; ++i)
	{
		// ����ł�����
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		for (int j = 0; j != enemyNum; ++j)
		{
			// �����Ǝ����ōs�킹�Ȃ�������ł��邩����������������
			if (i == j || p_enemyMove[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyMove[i]->GetArea(), p_enemyMove[j]->GetArea()) > 250) continue;


			// �������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_enemyMove[i]->GetArea(), VAdd(p_enemyMove[i]->GetArea(), VGet(0.0f, p_enemyMove[i]->GetHeight(), 0.0f)), p_enemyMove[i]->GetWidth(),
				p_enemyMove[j]->GetArea(), VAdd(p_enemyMove[j]->GetArea(), VGet(0.0f, p_enemyMove[j]->GetHeight(), 0.0f)), p_enemyMove[j]->GetWidth()))
			{
				// �����������o�����
				p_enemyMove[i]->HitCircleReturn(p_enemyMove[j]->GetArea(), p_enemyMove[j]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemyNum; ++i)
	/// �G���m�ŉ����o��----------------------------------------------------------------
} /// void MainMove5::AttackProcess()


// �e�N�X�`���̔񓯊��ǂݍ���
void MainMove5::ThsTextureReload()
{
	ths = std::thread(&MainMove5::TextureReload, this);
	ths.join();
}


// �R���X�g���N�^
MainMove5::MainMove5(const std::vector<int> v_file)
{
	// ������
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::lastCharaView = false;
	BASICPARAM::lastOrdinaryView = false;
	BASICPARAM::lastPaneruView = false;
	BASICPARAM::lastStairsRoadView = false;
	BASICPARAM::lastStairsView = false;
	BASICPARAM::lastStreetLightView = false;


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
	p_enemyBossBefore = nullptr;
	for (int i = 0; i != enemyNum; ++i)
	{
		p_enemyMove[i] = nullptr;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();
	vp_ordinaryPerson.clear();


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


	// �G�̏�����
	p_enemyBossBefore = new EnemyBossBefore();
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z���W�p����
	for (int i = 0; i != enemyNum; ++i)
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
		p_enemyMove[i] = new EnemyMove5(v_file[EFILE::enemyModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::enemyTex0], VGet(tempX, 0.0f, tempZ), 0);
	}
	enemyCatchNum = 0;


	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
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


	// �T�E���h�̃��[�h
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


// �f�X�g���N�^
MainMove5::~MainMove5()
{
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
	POINTER_RELEASE(p_enemyBossBefore);
	for (int i = 0; i != enemyNum; ++i)
	{
		POINTER_RELEASE(p_enemyMove[i]);
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
} /// MainMove5::~MainMove5()


// �`��
void MainMove5::Draw()
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


	// �G
	for (int i = 0; i != enemyNum; ++i)
	{
		// ����ł�����
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		p_enemyMove[i]->Draw();
	}


	p_character->Draw();	// �L�����N�^�[��`��


	// �����@�B�Ƌ������߂�������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// �����摜��\������
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}


	// ���[�u����������
	if (moveDescriptionFrame-- > 0)
	{
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 291, 540 - 64 - 32, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
} /// void MainMove5::Draw()


// �v���Z�X
void MainMove5::Process()
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


	// �G�Ɋւ���
	for (int i = 0; i != enemyNum; ++i)
	{
		// ���ł�����
		if (p_enemyMove[i]->GetEraseExistence()) continue;


		p_enemyMove[i]->Process();			// �v���Z�X���Ă�


		// ����ł��Ȃ�������
		if (p_enemyMove[i]->GetDeathFlag()) continue;


		// �v���C���[�̈ʒu�Ƌ������擾����
		p_enemyMove[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyMove[i]->GetArea()));
	}


	// �V���h�E�}�b�v�̈ʒu���X�V
	BaseMove::ShadowArea(p_character->GetArea());


	AttackProcess();		// �����蔻��̃v���Z�X

	
	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_character->GetArea());


	/// ��ɓ��ꂽ����SE�𗬂�-------------------------------------------------
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


	// ���̃V�[���ֈڍs����ꏊ�ɋ�����
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


// �J�����̍ăZ�b�g�A�b�v
void MainMove5::CameraProcess()
{
	p_camera->SetUp();
}


// �e�N�X�`���̓ǂݍ���
void MainMove5::TextureReload()
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
		// �����@�B
		p_adjustmentMachine->TextureReload();


		// ��ʐl
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->TextureReload();
			}
		}
	}


	// �G
	if (!BASICPARAM::enemyTextureWhiteBlack)
	{
		for (int i = 0; i != enemyNum; ++i)
		{
			p_enemyMove[i]->TextureReload();
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
void MainMove5::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// �I�v�V������ʃ��f���̕`��̏���
void MainMove5::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// �I�v�V������ʃ��f���̕`��̌�n��
void MainMove5::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
