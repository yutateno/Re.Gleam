#include "MainMove6.hpp"



/// --------------------------------------------------------------------------------------------------
void MainMove6::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
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



/// --------------------------------------------------------------------------------------------------
void MainMove6::AttackProcess()
{
	/// �v���C���[�������o������------------------------------------------------------------
	// �{�X�Ɠ������Ă�����
	if (HitCheck_Capsule_Capsule(
		p_enemyBossAfter->GetArea(), VAdd(p_enemyBossAfter->GetArea(), VGet(0.0f, p_enemyBossAfter->GetHeight(), 0.0f)), p_enemyBossAfter->GetWidth(),
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
	{

		// �����������o��
		p_character->HitCircleReturn(p_enemyBossAfter->GetArea()
			, p_character->GetWidth() >= p_enemyBossAfter->GetWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetWidth());
	}



	/// �v���C���[�̍U��---------------------------------------------------------------------
	// �v���C���[�̍U�����I�������
	if (p_character->GetAttackMotionEnd()) enemyHitDamage = false;


	// �_���[�W���󂯂Ă��Ȃ��ăv���C���[���U������������
	if (p_character->GetAttackNow() && !enemyHitDamage && p_character->GetArea().y >= 2100)
	{
		p_enemyBossAfter->HitLineReturn(p_character->GetAttackFirstFrameArea()
			, p_character->GetAttackEndFrameArea());
	}


	// �U���Ń_���[�W���󂯂���
	if (p_enemyBossAfter->GetDamageFlag())
	{
		// �_���[�W���󂯂Ă���
		enemyHitDamage = true;
		enemyDamageCount++;
		// �o�C�u���[�V����������
		DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 15000, 15000);
	}


	/// �G�̍U���̏���-----------------------------------------------------------------------
	// ���̍U����������
	e_attackPattern = p_enemyBossAfter->GetAttackPattern();


	// �G���U�����n�߂��Ƃ�
	if (p_enemyBossAfter->GetAttackStartNow())
	{
		// �X�̒����g���U����������
		if (e_attackPattern == EAttackPattern::icePillar)
		{
			// �����ɎU��΂���
			std::mt19937 mt(rnd());
			std::uniform_int_distribution<> paneruID(0, 65);        // �p�l����ID
			for (int i = 0; i != icePillarNum; ++i)
			{
				p_magicIcePillar[i]->Active(p_stagePaneru[paneruID(mt)]->GetArea());
			}
		}
		// �����g���U����������
		else if (e_attackPattern == EAttackPattern::magicBlock)
		{
			// 0�Ԗڂ̂��̂��g���Ă��Ȃ�������
			if (!p_chaseBlock[0]->GetActive())
			{
				p_chaseBlock[0]->Active(p_character->GetArea());
			}
			// 0�Ԗڂ��ғ�����������
			else
			{
				// 1�Ԗڂ̂��̂��g���Ă��Ȃ�������
				if (!p_chaseBlock[1]->GetActive())
				{
					p_chaseBlock[1]->Active(p_character->GetArea());
				}
			}
		}
	} /// if (p_enemyBossAfter->GetAttackStartNow())
	/// �G�̍U���̏���-----------------------------------------------------------------------


	/// �G�̍U���ɂ��_���[�W���󂯂Ă��邩�ǂ���-------------------------------------------------------------------------------------------------------
	// �X�̒����g���U����������
	if (e_attackPattern == EAttackPattern::icePillar)
	{
		for (int i = 0; i != icePillarNum; ++i)
		{
			// �A�N�e�B�u��������
			if (p_magicIcePillar[i]->GetActive())
			{
				// �d�Ȃ��Ă�����
				if (p_magicIcePillar[i]->GetArea().x - 100 < p_character->GetArea().x && p_magicIcePillar[i]->GetArea().x + 100 > p_character->GetArea().x
					&& p_magicIcePillar[i]->GetArea().y - 50 < p_character->GetArea().y && p_magicIcePillar[i]->GetArea().y + 250 > p_character->GetArea().y
					&& p_magicIcePillar[i]->GetArea().z - 100 < p_character->GetArea().z && p_magicIcePillar[i]->GetArea().z + 100 > p_character->GetArea().z)
				{
					// �_���[�W��^����
					p_character->SetDamage();
					damageCount++;
				}
			}
		}
	}
	// �����g���U����������
	else if (e_attackPattern == EAttackPattern::magicBlock)
	{
		// ID0�Ԗڂ��A�N�e�B�u��������
		if (p_chaseBlock[0]->GetActive())
		{
			// ID0�Ԗڂ̒ǔ����Ɠ������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_chaseBlock[0]->GetArea(), VAdd(p_chaseBlock[0]->GetArea(), VGet(0.0f, p_chaseBlock[0]->GetHeight(), 0.0f)), p_chaseBlock[0]->GetWidth(),
				p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
			{

				// �����������o��
				p_character->HitCircleReturn(p_chaseBlock[0]->GetArea()
					, p_character->GetWidth() >= p_chaseBlock[0]->GetWidth() ? p_character->GetWidth() : p_chaseBlock[0]->GetWidth());


				// �_���[�W��^����
				p_character->SetDamage();
				damageCount++;
			}
		}
		// ID1�Ԗڂ��A�N�e�B�u��������
		else if (p_chaseBlock[1]->GetActive())
		{
			// ID1�Ԗڂ̒ǔ����Ɠ������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_chaseBlock[1]->GetArea(), VAdd(p_chaseBlock[1]->GetArea(), VGet(0.0f, p_chaseBlock[1]->GetHeight(), 0.0f)), p_chaseBlock[1]->GetWidth(),
				p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
			{

				// �����������o��
				p_character->HitCircleReturn(p_chaseBlock[1]->GetArea()
					, p_character->GetWidth() >= p_chaseBlock[1]->GetWidth() ? p_character->GetWidth() : p_chaseBlock[1]->GetWidth());


				// �_���[�W��^����
				p_character->SetDamage();
				damageCount++;
			}
		}
	}
	// ���U�肩�����U����������
	else if (e_attackPattern == EAttackPattern::hand)
	{
		// �U������������
		if (p_enemyBossAfter->GetAttackNow())
		{
			int temp = 0;		// �����o���񐔂����u��


			// �v���C���[�������o��
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameOneArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameOneWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameOneWidth());
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameTwoArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameTwoWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameTwoWidth());
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameThreeArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameThreeWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameThreeWidth());


			// �Ԃ����Ă�����
			if (temp != 0)
			{
				// �_���[�W��^����
				p_character->SetDamage();
				damageCount++;
			}
		}
	}
	/// �G�̍U���ɂ��_���[�W���󂯂Ă��邩�ǂ���-------------------------------------------------------------------------------------------------------
} /// void MainMove6::AttackProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove6::FirstDraw()
{	
	// �X�J�C�{�b�N�X��`��
	BaseMove::SkyBoxDraw();


	// �V���h�E�}�b�v��`��
	ShadowDraw();


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


	// �L�����N�^�[��`��
	p_character->Draw();



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



/// --------------------------------------------------------------------------------------------------
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
				// �V�[�����ڍs����
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



/// --------------------------------------------------------------------------------------------------
void MainMove6::MovieDraw()
{
	if (movieFrame < 1000
		|| DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) != 1)
	{
		BaseMove::SkyBoxDraw();										// �X�J�C�{�b�N�X��`��


		ShadowDraw();												// �V���h�E�}�b�v��`��


		p_enemyBossBefore->ModelDraw();								// �G���X�{�X�̂���


		// ��ʐl
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->Draw();
			}
		}


		p_character->Draw();										// �L�����N�^�[��`��


		DrawGraph(1920 - 260, 1080 - 80, movieSkipDraw, false);		// �X�L�b�v�̎d�������
	}
} /// void MainMove6::MovieDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove6::MovieProcess()
{
	// �������Ǘ�
	movieFrame++;


	// �{�X�O�̃v���Z�X���Ă�
	p_enemyBossBefore->Process();
	p_enemyBossBefore->MoveReturn();


	// �V���h�E�}�b�v�̈ʒu���X�V
	BaseMove::ShadowArea(p_cameraMove->GetArea());


	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_cameraMove->GetArea());


	/// �A�N�^�[���Ƃ̕`��Ɋւ���---------------------------------------------
	// 300�t���[���ȏゾ������n�ʂɖ��܂点��
	if (movieFrame >= 300)
	{
		// ���݂��Ă����炻�ꂼ���n�ʂɖ��܂点��
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


		// 600�t���[���ȏゾ������{�X��n�ʂɖ��܂点��
		if (movieFrame >= 600)
		{
			p_enemyBossBefore->AreaSetDown();
		}


		// 800�t���[���ȏゾ������v���C���[��n�ʂɖ��܂点��
		if (movieFrame >= 800)
		{
			p_character->AreaSetDown();
		}


		// �{�X�̖��߂ɍ��킹�Ēn�ʂɍ����~���o��
		if (movieFrame >= 600 && movieFrame < 800)
		{
			DrawCone3D(VGet(4000.0f, 0.0f, 0.0f), VGet(4000.0f, 1.0f, 0.0f), static_cast<float>(movieFrame - 600) * 2.0f, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);
		}
		else if (movieFrame >= 800)
		{
			DrawCone3D(VGet(4000.0f, 0.0f, 0.0f), VGet(4000.0f, 1.0f, 0.0f), static_cast<float>(1000 - movieFrame) * 2.0f, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);
		}
	} /// if (movieFrame >= 300)


	// 200�t���[���ȉ���������
	if (movieFrame <= 200)
	{
		// ����ł��Ȃ��v���C���[�̃v���Z�X���Ă�
		p_character->NotOpeProcess(p_camera->GetAngle());
	}
	/// �A�N�^�[���Ƃ̕`��Ɋւ���---------------------------------------------


	/// �J�����Ɋւ���------------------------------------------------------------------
	// 200�t���[����葽��300�t���[���ȉ���������
	if (movieFrame > 200 && movieFrame <= 400)
	{
		// �J�������{�X��������悤�ɂ���
		p_cameraMove->SetView(VGet(4000 - (movieFrame - 200) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(3000 - (movieFrame - 200) * 10.0f, 200, 0));
		p_cameraMove->SetView(VGet(1000, 0, 1000));
	}


	// 400�t���[����葽��600�t���[���ȉ���������
	if (movieFrame > 400 && movieFrame <= 600)
	{
		// �J�������X�e�[�W�����񂷂悤�ɂ���
		p_cameraMove->SetView(VGet(2000 + (movieFrame - 400) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(1000 + (movieFrame - 400) * 10.0f, 200, 0));
	}
	/// �J�����Ɋւ���------------------------------------------------------------------

	
	// �V�[���ڍs����
	if (movieFrame >= 1000
		|| DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) == 1)
	{
		// ����Ȃ��f�[�^���폜
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


			// ���[�r�[�p�J����
			POINTER_RELEASE(p_cameraMove);


			// ���[�r�[�摜
			GRAPHIC_RELEASE(movieSkipDraw);
		}


		SetFogEnable(FALSE);														// �t�H�O������
		BASICPARAM::paneruDrawFlag = true;											// �p�l����`�悳����
		BASICPARAM::lastPaneruView = true;											// �p�l���͕K���`�悷��悤�ɐݒ�
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::boss, 255);		// BGM���Đ�
		e_nowMove = ESceneMove6::Battle;											// �o�g���ֈڍs
		p_character->PositionReset();												// �L�����N�^�[�̍��W��������
	}
} /// void MainMove6::MovieProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove6::BattleDraw()
{
	// �X�e�[�W�̕`��
	p_stage->Draw();


	// �p�l���̕`��
	for (int i = 0; i != paneruNum; ++i)
	{
		if (!paneruArrival[0] && i >= 16 && i < 36) continue;
		if (!paneruArrival[1] && i >= 36 && i < 56) continue;
		if (!paneruArrival[2] && i >= 56 && i < 61) continue;
		if (!paneruArrival[3] && i >= 61 && i < 66) continue;
		p_stagePaneru[i]->ModelDraw();
	}


	// �{�X�̕`��
	p_enemyBossAfter->DrawWhile();
	p_enemyBossAfter->Draw();


	// �{�X�̍U���ɂ��ǔ����锠
	p_chaseBlock[0]->Draw();
	p_chaseBlock[1]->Draw();


	// �L�����N�^�[�̕`��
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
	p_character->Draw();


	// �̗͂�\������摜
	DrawExtendGraph(62, 235, 477 - damageCount, 260, battleHealDraw[static_cast<int>(EHealDraw::gageBar)], true);
	DrawExtendGraph(340, 42, 575, 258, battleHealDraw[static_cast<int>(EHealDraw::iconBack)], true);
	DrawExtendGraph(337, 50, 537, 233, battleHealDraw[static_cast<int>(EHealDraw::icon)], true);
	DrawExtendGraph(21, 146, 562, 293, battleHealDraw[static_cast<int>(EHealDraw::gage)], true);
	DrawBox(460, 1000, 1460, 1030, GetColor(0, 0, 0), false);
	DrawExtendGraph(460, 1000, 1460 - enemyDamageCount * enemyDamageHitCount, 1030, battleHealDraw[static_cast<int>(EHealDraw::enemyGage)], true);
} /// void MainMove6::BattleDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove6::BattleProcess()
{
	// �L�����N�^�[�̃v���Z�X
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	/// ���[�v�\�ł��̏�Ƀv���C���[��������------------------------------------------------------------------------------------------------
	// �������̃p�l��
	if (paneruArrival[0]
		&& p_stagePaneru[1]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[1]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[1]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[1]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[1]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[1]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// �{�^���������o��
		DrawBillboard3D(VAdd(p_stagePaneru[1]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// B�{�^���ňړ�����
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[7]->GetArea());
		}
	}
	// �����E�̃p�l��
	else if (paneruArrival[1]
		&& p_stagePaneru[9]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[9]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[9]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[9]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[9]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[9]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// �{�^���������o��
		DrawBillboard3D(VAdd(p_stagePaneru[9]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// B�{�^���ňړ�����
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[15]->GetArea());
		}
	}
	// ����̃p�l��
	else if (paneruArrival[2]
		&& p_stagePaneru[16]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[16]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[16]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[16]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[16]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[16]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// �{�^���������o��
		DrawBillboard3D(VAdd(p_stagePaneru[16]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// B�{�^���ňړ�����
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[35]->GetArea());
		}
	}
	// �E��̃p�l��
	else if (paneruArrival[3]
		&& p_stagePaneru[36]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[36]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[36]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[36]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[36]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[36]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// �{�^���������o��
		DrawBillboard3D(VAdd(p_stagePaneru[36]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// B�{�^���ňړ�����
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[55]->GetArea());
		}
	}
	/// ���[�v�\�ł��̏�Ƀv���C���[��������------------------------------------------------------------------------------------------------


	// �G��ڂ̑O�ɂ��č��̈�ԏ�ɒB������
	if (!paneruArrival[0]
		&& p_stagePaneru[7]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[7]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[7]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[7]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[7]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[7]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[0] = true;
	}
	// �G��ڂ̑O�ɂ��ĉE�̈�ԏ�ɒB������
	if (!paneruArrival[1]
		&& p_stagePaneru[15]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[15]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[15]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[15]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[15]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[15]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[1] = true;
	}
	// �G��ڂ̑O�ɂ��č��̈�ԏ�ɒB������œG�߂��ɓ��B������
	if (paneruArrival[0] && !paneruArrival[2]
		&& p_stagePaneru[35]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[35]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[35]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[35]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[35]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[35]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[2] = true;
	}
	// �G��ڂ̑O�ɂ��ĉE�̈�ԏ�ɒB������œG�߂��ɓ��B������
	if (paneruArrival[1] && !paneruArrival[3]
		&& p_stagePaneru[55]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[55]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[55]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[55]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[55]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[55]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[3] = true;
	}


	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());


	// �{�X�̃v���Z�X
	p_enemyBossAfter->Process();


	// �X���̃G�t�F�N�g
	for (int i = 0; i != icePillarNum; ++i)
	{
		p_magicIcePillar[i]->Process();
	}


	// �ǔ���
	p_chaseBlock[0]->Process();
	p_chaseBlock[1]->Process();


	// �����蔻��̃v���Z�X
	AttackProcess();


	/// ���[�v�G�t�F�N�g�̏���-----------------------------------------------------------------------------------------------------------
	// �G��ڂ̑O�ɂ��č��̈�ԏ�ɓ��B������
	if (paneruArrival[0])
	{
		// �G�t�F�N�g���Đ����Ă��Ȃ�������
		if (IsEffekseer3DEffectPlaying(playingEfWarp[0]) != 0)
		{
			// �����̃p�l����
			playingEfWarp[0] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[0], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[0], p_stagePaneru[1]->GetArea().x, p_stagePaneru[1]->GetArea().y + 55, p_stagePaneru[1]->GetArea().z);
		}
	}
	// �G��ڂ̑O�ɂ��ĉE�̈�ԏ�ɓ��B������
	if (paneruArrival[1])
	{
		// �G�t�F�N�g���Đ����Ă��Ȃ�������
		if (IsEffekseer3DEffectPlaying(playingEfWarp[1]) != 0)
		{
			// �E���̃p�l����
			playingEfWarp[1] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[1], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[1], p_stagePaneru[9]->GetArea().x, p_stagePaneru[9]->GetArea().y + 55, p_stagePaneru[9]->GetArea().z);
		}
	}
	// �G��ڂ̑O�ɂ��č��̓G�߂��ɓ��B������
	if (paneruArrival[2])
	{
		// �G�t�F�N�g���Đ����Ă��Ȃ�������
		if (IsEffekseer3DEffectPlaying(playingEfWarp[2]) != 0)
		{
			// ����ԏ�̃p�l����
			playingEfWarp[2] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[2], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[2], p_stagePaneru[16]->GetArea().x, p_stagePaneru[16]->GetArea().y + 55, p_stagePaneru[16]->GetArea().z);
		}
	}
	// �G��ڂ̑O�ɂ��ĉE�̓G�߂��ɓ��B������
	if (paneruArrival[3])
	{
		// �G�t�F�N�g���Đ����Ă��Ȃ�������
		if (IsEffekseer3DEffectPlaying(playingEfWarp[3]) != 0)
		{
			// �E��ԏ�̃p�l����
			playingEfWarp[3] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[3], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[3], p_stagePaneru[36]->GetArea().x, p_stagePaneru[36]->GetArea().y + 55, p_stagePaneru[36]->GetArea().z);
		}
	}
	/// ���[�v�G�t�F�N�g�̏���-----------------------------------------------------------------------------------------------------------


	// �{�X�����񂾂�
	if (enemyDamageCount >= 1000 / enemyDamageHitCount)
	{
		// ���̃V�[���ֈڍs����
		if (p_enemyBossAfter->SetDeathBlendDraw())
		{
			p_camera->SetShakePower(0.0f);
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::ending);
			e_nowMove = ESceneMove6::Last;
			p_character->PositionReset();
			movieFrame = 0;
		}
		// ���̃V�[���ֈڍs����O�̏���������
		else
		{
			if (std::fabsf(cameraShakeParam) <= 20.0f)
			{
				if (cameraShakeParam < 0.0f)
				{
					cameraShakeParam -= 1.0f;
				}
				else
				{
					cameraShakeParam += 1.0f;
				}
			}
			cameraShakeParam *= -1.0f;
			p_camera->SetShakePower(cameraShakeParam);
		}
	}


	// �v���C���[�����񂾂�
	if (damageCount >= 477)
	{
		// �^�C�g���֋����I�Ɉړ�������
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}


#ifdef _DEBUG
	// ���̃V�[���ֈڍs
	if (CheckHitKey(KEY_INPUT_M) == 1)
	{
		// ���̃V�[���ֈڍs����
		if (p_enemyBossAfter->SetDeathBlendDraw())
		{
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::ending);
			e_nowMove = ESceneMove6::Last;
			p_character->PositionReset();
			movieFrame = 0;
		}
		// ���̃V�[���ֈڍs����O�̏���������
		else
		{
			if (std::fabsf(cameraShakeParam) <= 20.0f)
			{
				if (cameraShakeParam < 0.0f)
				{
					cameraShakeParam -= 1.0f;
				}
				else
				{
					cameraShakeParam += 1.0f;
				}
			}
			cameraShakeParam *= -1.0f;
			p_camera->SetShakePower(cameraShakeParam);
		}
	}
#endif
} /// void MainMove6::BattleProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove6::BattleTextureReload()
{
	for (int i = 0; i != 5; ++i)
	{
		GRAPHIC_RELEASE(battleHealDraw[i]);
	}


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\UI\\clph_icon\\normal.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\normal.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W\\normal.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W�̒��g1\\normal.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\normal.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\UI\\clph_icon\\D.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\D.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W\\D.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W�̒��g1\\D.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\D.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\UI\\clph_icon\\P.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\P.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W\\P.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W�̒��g1\\P.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\P.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\UI\\clph_icon\\normal.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\normal.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W\\normal.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\�Q�[�W�̒��g1\\normal.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\normal.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;
	}
}



/// --------------------------------------------------------------------------------------------------
void MainMove6::LastDraw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X��`��


	p_stage->Draw();


	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
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



/// --------------------------------------------------------------------------------------------------
void MainMove6::LastProcess()
{
	movieFrame++;


	// �L�����N�^�[�̃v���Z�X
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	// �J�����̃v���Z�X
	p_camera->Process(p_character->GetArea());


	// �X�J�C�{�b�N�X�̈ʒu���X�V
	BaseMove::SkyBoxProcess(p_character->GetArea());


	if (movieFrame >= 3700)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}
} /// void MainMove6::LastProcess()



/// --------------------------------------------------------------------------------------------------
MainMove6::MainMove6(const std::vector<int> v_file)
{
	// ������
	BASICPARAM::paneruDrawFlag = false;
	e_nowMove = ESceneMove6::First;


	// �|�C���^NULL������
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_stage = nullptr;
	for (int i = 0; i != paneruNum; ++i)
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
	for (int i = 0; i != icePillarNum; ++i)
	{
		p_magicIcePillar[i] = nullptr;
	}
	p_chaseBlock[0] = nullptr;
	p_chaseBlock[1] = nullptr;


	// ���[�r�[�ł̉摜
	movieSkipDraw = v_file[EFILE::movieSkip];


	// �퓬���̉摜
	battleHealDraw[static_cast<int>(EHealDraw::icon)]		 = v_file[EFILE::charaIcon];
	battleHealDraw[static_cast<int>(EHealDraw::iconBack)]	 = v_file[EFILE::charaIconBack];
	battleHealDraw[static_cast<int>(EHealDraw::gage)]		 = v_file[EFILE::charaGage];
	battleHealDraw[static_cast<int>(EHealDraw::gageBar)]	 = v_file[EFILE::charaGageBar];
	battleHealDraw[static_cast<int>(EHealDraw::enemyGage)]	 = v_file[EFILE::enemyGageBar];


	// �X�e�[�W�̏�����
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// �L�����N�^�[�̏�����
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	damageCount = 0;
	warpDesc = v_file[EFILE::warpDescDraw];


	// �J�����̏�����
	p_camera = new Camera(p_character->GetArea());
	p_cameraMove = new CameraMove6();
	cameraShakeParam = 0.0f;


	// �p�l���̏�����
	p_character->SetCollPaneruNum(paneruNum);
	for (int i = 0; i != paneruNum; ++i)
	{
		// �����ɎU��΂���
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-300, 300);        // X���W�p����
		std::uniform_int_distribution<> randInZ(-300, 300);        // Z���W�p����
		// �G��ڂ̑O�ɂ��č���
		if (i < 8)
		{
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randInX(mt))
				, static_cast<float>(800.0f * i), static_cast<float>(500.0f * i)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// �G��ڂ̑O�ɂ��ĉE��
		else if (i < 16)
		{
			int temp = i - 8;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randInX(mt))
				, static_cast<float>(800.0f * temp), static_cast<float>(-500.0f * temp)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// �G��ڂ̑O�ɂ��č��̗�
		else if (i < 36)
		{
			int temp = i - 16;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4370 / 20 * temp)
				, static_cast<float>(5600.0f - (2000 / 20 * temp)), static_cast<float>(3500 - (2500 / 20 * temp))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// �G��ڂ̑O�ɂ��ĉE�̗�
		else if (i < 56)
		{
			int temp = i - 36;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4370 / 20 * temp)
				, static_cast<float>(5600.0f - (2000 / 20 * temp)), static_cast<float>((2500 / 20 * temp) - 3500)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// �G��ڂ̑O�ɂ��ēG�����畠�܂�
		else if (i < 61)
		{
			int temp = i - 56;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4150 - (600 / 5 * temp))
				, static_cast<float>(3750 - (500 / 5 * temp)), static_cast<float>(1120 - (1120 / 5 * temp))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// �G��ڂ̑O�ɂ��ēG�E���畠�܂�
		else if (i < 66)
		{
			int temp = i - 61;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4150 - (600 / 5 * temp))
				, static_cast<float>(3750 - (500 / 5 * temp)), static_cast<float>((1120 / 5 * temp) - 1120)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// ���ɈӖ����Ȃ�����܂ł̃p�l�����ŎU��΂�
		else
		{
			std::uniform_int_distribution<> randX(1000, 3000);			// X���W�p����
			std::uniform_int_distribution<> randY(2000, 4000);			// Y���W�p����
			std::uniform_int_distribution<> randZ(-3000, 3000);			// Z���W�p����
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randX(mt))
				, static_cast<float>(randY(mt)), static_cast<float>(randZ(mt))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
	}
	for (int i = 0; i != 4; ++i)
	{
		paneruArrival[i] = false;
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
	p_enemyBossAfter = new EnemyBossAfter(v_file[EFILE::bossBeforeModel], v_file[EFILE::bossAfterTex0], v_file[EFILE::bossAfterTex1], v_file[EFILE::bossAfterTex2]);
	approachBossUIDraw[0] = v_file[EFILE::approachUINear];
	approachBossUIDraw[1] = v_file[EFILE::approachUIYes];
	approachBossUIDraw[2] = v_file[EFILE::approachUINo];
	approachUISelect = true;
	e_attackPattern = EAttackPattern::hand;
	for (int i = 0; i != icePillarNum; ++i)
	{
		p_magicIcePillar[i] = new MagicIcePillar();
	}
	p_chaseBlock[0] = new ChaseBlock();
	p_chaseBlock[1] = new ChaseBlock();
	enemyHitDamage = false;
	enemyDamageCount = 0;
	enemyDamageHitCount = BASICPARAM::ordinaryPeopleNum + BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum;
	while(1000 % ++enemyDamageHitCount != 0){}
	enemyDamageHitCount = 1000 / enemyDamageHitCount;
	if (enemyDamageHitCount < 50)
	{
		enemyDamageHitCount = 50;
	}
	if (enemyDamageHitCount > 500)
	{
		enemyDamageHitCount = 500;
	}



	// ��ʐl
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-4000, 4000);		// X���W�p����
		std::uniform_int_distribution<> randInZ(-4000, 4000);		// Z���W�p����


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
	SoundProcess::Load(v_file[EFILE::se_attackOne]		, SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid]	, SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo]		, SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_foot]			, SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor]	, SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump]			, SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing]		, SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond]	, SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main]			, SoundProcess::ESOUNDNAME_BGM::boss);
	SoundProcess::Load(v_file[EFILE::bgm_end]			, SoundProcess::ESOUNDNAME_BGM::ending);
	
	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::boss, 0, 0);


	// �G�t�F�N�g�̃��[�h
	effectWarp = LoadEffekseerEffect("media\\Effect\\warp.efk");
	for (int i = 0; i != 4; ++i)
	{
		playingEfWarp[i] = -1;
	}
} /// MainMove6::MainMove6(const std::vector<int> v_file)



/// --------------------------------------------------------------------------------------------------
MainMove6::~MainMove6()
{
	// �G�t�F�N�g�J��
	for (int i = 0; i != 4; ++i)
	{
		StopEffekseer3DEffect(playingEfWarp[i]);
	}
	DeleteEffekseerEffect(effectWarp);


	// �G���h���[��
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(endrolDraw[i]);
	}


	// ��ʐl
	if (vp_ordinaryPerson.size() != 0)
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
	POINTER_RELEASE(p_enemyBossAfter);


	// �K�i
	if (vp_stageStairs.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairs[i]);
		}
		vp_stageStairs.clear();
		vp_stageStairs.shrink_to_fit();
	}


	// �X��
	if (vp_stageStreetLight.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStreetLight[i]);
		}
		vp_stageStreetLight.clear();
		vp_stageStreetLight.shrink_to_fit();
	}


	// �K�i�Ə�
	if (vp_stageStairsRoad.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairsRoad[i]);
		}
		vp_stageStairsRoad.clear();
		vp_stageStairsRoad.shrink_to_fit();
	}


	// �p�l��
	for (int i = 0; i != paneruNum; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// �J����
	POINTER_RELEASE(p_cameraMove);
	POINTER_RELEASE(p_camera);


	// �L�����N�^�[
	GRAPHIC_RELEASE(warpDesc);
	POINTER_RELEASE(p_character);


	// �X�e�[�W
	POINTER_RELEASE(p_stage);


	// �퓬���摜
	for (int i = 0; i != 5; ++i)
	{
		GRAPHIC_RELEASE(battleHealDraw[i]);
	}


	// ���[�r�[�摜
	GRAPHIC_RELEASE(movieSkipDraw);
} /// MainMove5::~MainMove5()



/// --------------------------------------------------------------------------------------------------
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



/// --------------------------------------------------------------------------------------------------
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



/// --------------------------------------------------------------------------------------------------
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



/// --------------------------------------------------------------------------------------------------
void MainMove6::ThsTextureReload()
{
	if (textureReloadCountDo == 6)
	{
		// �L�����N�^�[�̃e�N�X�`���������w�肶��Ȃ�������
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����N�^�[
			ths = p_character->ThsTextureReload();
			ths.join();
		}
	}


	if (textureReloadCountDo == 5)
	{
		// �퓬�G�̉摜
		ths = p_enemyBossAfter->ThsTextureReload();
		ths.join();
	}


	if (textureReloadCountDo == 4)
	{
		// ���̑��̃e�N�X�`���������w�肶��Ȃ�������
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// ��ʐl
			if (vp_ordinaryPerson.size() != 0)
			{
				for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
				{
					ths = vp_ordinaryPerson[i]->ThsTextureReload();
					ths.join();
				}
			}
		}
	}


	if (textureReloadCountDo == 3)
	{
		// �K�i�̃e�N�X�`���������w�肶��Ȃ�������
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			if (vp_stageStairs.size() != 0)
			{
				for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
				{
					ths = vp_stageStairs[i]->ThsTextureReload();
					ths.join();
				}
			}
		}
	}


	if (textureReloadCountDo == 2)
	{
		// �X���̃e�N�X�`���������w�肶��Ȃ�������
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			if (vp_stageStreetLight.size() != 0)
			{
				for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
				{
					ths = vp_stageStreetLight[i]->ThsTextureReload();
					ths.join();
				}
			}
		}
	}


	if (textureReloadCountDo == 1)
	{
		// �K�i�Ə��̃e�N�X�`���������w�肶��Ȃ�������
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			if (vp_stageStairsRoad.size() != 0)
			{
				for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
				{
					ths = vp_stageStairsRoad[i]->ThsTextureReload();
					ths.join();
				}
			}
		}
	}


	if (textureReloadCountDo == 0)
	{
		// �퓬���摜
		ths = std::thread(&MainMove6::BattleTextureReload, this);
		ths.join();
	}


	if (++textureReloadCountDo <= 6)
	{
		ThsTextureReload();					// �ǂݍ��ݏI���܂ōċA
	}
} /// void MainMove5::TextureReload()



/// --------------------------------------------------------------------------------------------------
void MainMove6::OptionActorModel()
{
	p_character->OptionActorDraw();
}



/// --------------------------------------------------------------------------------------------------
void MainMove6::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}



/// --------------------------------------------------------------------------------------------------
void MainMove6::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
