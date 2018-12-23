#include "MainMove2.hpp"




void MainMove2::AdjustmentProcess()
{
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		adjustmentSelectObject = !adjustmentSelectObject;
	}
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		if (adjustmentSelectObject)
		{
			AdjuctmentCreate(adjustmentArrangementArea, adjustmentSelectObjectNumber, adjustmentArrangementDire);
		}
		else
		{
			adjustmentFeedNow = true;
			adjustmentStartFeed = false;
		}
	}

	/*if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		AdjuctmentCreate(VGet(-160.0f*BASICPARAM::stairsNum, 0.0f, -1000.0f), AdjustmentObject::Stairs);
		printfDx("�K�i�𐶐�: %d\n", BASICPARAM::stairsNum);
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		AdjuctmentCreate(VGet(50.0f*BASICPARAM::streetLightNum, 0.0f, -100.0f), AdjustmentObject::StreetLight);
		printfDx("�X���𐶐�: %d\n", BASICPARAM::streetLightNum);
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_Y) == 1)
	{
		BASICPARAM::paneruDrawFlag = !BASICPARAM::paneruDrawFlag;
		printfDx("�p�l����\��: %s\n", BASICPARAM::paneruDrawFlag ? "true" : "false");
	}

	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_UP) == 1)
	{
		AdjuctmentCreate(VGet(-900.0f*BASICPARAM::stairsRoadNum, 0.0f, 1000.0f), AdjustmentObject::StairsRoad);
		printfDx("�K�i�Ə��𐶐�: %d\n", BASICPARAM::stairsRoadNum);
	}*/

	if (adjustmentSelectObject)
	{
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			adjustmentArrangementArea.x -= 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			adjustmentArrangementArea.x += 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
		{
			adjustmentArrangementArea.z -= 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
		{
			adjustmentArrangementArea.z += 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
		{
			adjustmentArrangementDire += DX_PI_F / 60;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) < 0)
		{
			adjustmentArrangementDire -= DX_PI_F / 60;
		}
	}
	else
	{
		// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤�����B
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
		if (adjustmentControllStick[0] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp > 0 ? --temp : temp);
		}
		if (adjustmentControllStick[1] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp < 2 ? ++temp : temp);
		}
	}
}


void MainMove2::AdjustmentDraw()
{
	/// �I�y���[�^�[�̃t�F�[�h�\���Ɋւ���-----------------------------------------------------------
	if (adjustmentSceneFeed >= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(255, 255, 255), true);


		/// �z�u����Ă���I�u�W�F�N�g��2D----------------------------------------------------------------------------------------------------------------------------------------
		// �G~~
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - p_enemy[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + p_enemy[i]->GetArea().z) / 9000 * 1080)
				, 0.1, 0.0, adjustment2DDraw[0], true);
		}
		// �X��~~
		for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStreetLight[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStreetLight[i]->GetArea().z) / 9000 * 1080)
				, 0.15, vp_stageStreetLight[i]->GetYAngle(), adjustment2DDraw[2], true);
		}
		// �K�i~~
		for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStairs[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStairs[i]->GetArea().z) / 9000 * 1080)
				, 0.22, DX_PI + vp_stageStairs[i]->GetYAngle(), adjustment2DDraw[3], true);
		}
		// �I�y���[�^�[
		if (p_adjustmentMachine->GetCanTouch()) DrawRotaGraph(static_cast<int>((4500 - p_adjustmentMachine->GetArea().x) / 9000 * 1920)
			, static_cast<int>((4500 + p_adjustmentMachine->GetArea().z) / 9000 * 1080)
			, 0.08, DX_PI, adjustment2DDraw[4], true);

		// �K�i�Ə�~~
		for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStairsRoad[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStairsRoad[i]->GetArea().z) / 9000 * 1080)
				, 0.75, DX_PI + vp_stageStairsRoad[i]->GetYAngle(), adjustment2DDraw[5], true);
		}
		// �p�l��~~
		if (BASICPARAM::paneruDrawFlag)
		{
			for (int i = 0, n = 10; i != n; ++i)
			{
				DrawRotaGraph(static_cast<int>((4500 - p_stagePaneru[i]->GetArea().x) / 9000 * 1920)
					, static_cast<int>((4500 + p_stagePaneru[i]->GetArea().z) / 9000 * 1080)
					, 0.2, 0.0, adjustment2DDraw[5], true);
			}
		}
		// �L�����N�^�[
		DrawRotaGraph(static_cast<int>((4500 - p_character->GetArea().x) / 9000 * 1920)
			, static_cast<int>((4500 + p_character->GetArea().z) / 9000 * 1080)
			, 0.1, p_character->GetAngle() - DX_PI, adjustment2DDraw[1], true);


		// �z�u����I�u�W�F�N�g�ɂ���
		if (adjustmentSelectObject)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
			if (adjustmentSelectObjectNumber==AdjustmentObject::Stairs)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.22, adjustmentArrangementDire, adjustment2DDraw[3], true);
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.75, adjustmentArrangementDire, adjustment2DDraw[5], true);
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.15, adjustmentArrangementDire, adjustment2DDraw[2], true);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
		else
		{
			DrawBox(0, 0, 980, 540, GetColor(255, 255, 255), true);
			DrawBox(0, 0, 980, 540, GetColor(0, 0, 0), false);
			DrawRotaGraph(120, 120, 0.22, 0.0, adjustment2DDraw[3], true);
			DrawRotaGraph(320, 130, 0.75, 0.0, adjustment2DDraw[5], true);
			DrawRotaGraph(500, 120, 0.15, 0.0, adjustment2DDraw[2], true);
			DrawFormatString(50, 170, GetColor(0, 0, 0), "�K�i: 15�u���b�N");
			DrawFormatString(240, 250, GetColor(0, 0, 0), "�K�i����: 45�u���b�N");
			DrawFormatString(430, 170, GetColor(0, 0, 0), "�X��: 5�u���b�N");
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs)
			{
				DrawBox(30, 30, 200, 230, GetColor(255, 0, 0), false);
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				DrawBox(230, 30, 420, 280, GetColor(255, 0, 0), false);
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				DrawBox(420, 60, 570, 220, GetColor(255, 0, 0), false);
			}
		}
	}
	//else
	//{
	//	DrawGraph(0, 0, adjustmentDrawScreen, true);
	//}


	if (adjustmentSceneFeed >= 5 && adjustmentSceneFeed <= 55)
	{
		DrawBox(0, 108 * 0, BASICPARAM::winWidth, 108 * 1, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 10 && adjustmentSceneFeed <= 60)
	{
		DrawBox(0, 108 * 1, BASICPARAM::winWidth, 108 * 2, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 15 && adjustmentSceneFeed <= 65)
	{
		DrawBox(0, 108 * 2, BASICPARAM::winWidth, 108 * 3, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 20 && adjustmentSceneFeed <= 70)
	{
		DrawBox(0, 108 * 3, BASICPARAM::winWidth, 108 * 4, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 25 && adjustmentSceneFeed <= 75)
	{
		DrawBox(0, 108 * 4, BASICPARAM::winWidth, 108 * 5, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 30 && adjustmentSceneFeed <= 80)
	{
		DrawBox(0, 108 * 5, BASICPARAM::winWidth, 108 * 6, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 35 && adjustmentSceneFeed <= 85)
	{
		DrawBox(0, 108 * 6, BASICPARAM::winWidth, 108 * 7, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 40 && adjustmentSceneFeed <= 90)
	{
		DrawBox(0, 108 * 7, BASICPARAM::winWidth, 108 * 8, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 45 && adjustmentSceneFeed <= 95)
	{
		DrawBox(0, 108 * 8, BASICPARAM::winWidth, 108 * 9, GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed >= 50 && adjustmentSceneFeed <= 100)
	{
		DrawBox(0, 108 * 9, BASICPARAM::winWidth, 108 * 10, GetColor(0, 0, 0), true);
	}
	/// ---------------------------------------------------------------------------------------------

}


void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction)
{
	switch (obujectID)
	{
	case AdjustmentObject::Stairs:
		vp_stageStairs.push_back(new StageStairs(stairsHandle, area, stairsTexture0, DX_PI_F + direction));
		p_character->SetStairsArea(vp_stageStairs[BASICPARAM::stairsNum]->GetArea(), BASICPARAM::stairsNum, DX_PI_F + direction);
		BASICPARAM::stairsNum++;
		BASICPARAM::v_stairsArea.push_back(area);
		break;

	case AdjustmentObject::StreetLight:
		vp_stageStreetLight.push_back(new StageStreetLight(streetLightHandle, area, streetLightTexture0, streetLightTexture1, direction));
		BASICPARAM::streetLightNum++;
		BASICPARAM::v_streetLightArea.push_back(area);
		break;

	case AdjustmentObject::StairsRoad:
		vp_stageStairsRoad.push_back(new StageStairsRoad(stairsRoadHandle, area, stairsRoadTexture0, stairsRoadTexture1, DX_PI_F + direction));
		p_character->SetStairsRoadArea(vp_stageStairsRoad[BASICPARAM::stairsRoadNum]->GetArea(), BASICPARAM::stairsRoadNum, DX_PI_F + direction);
		BASICPARAM::stairsRoadNum++;
		BASICPARAM::v_stairsRoadArea.push_back(area);
		break;

	default:
		break;
	}
}


void MainMove2::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	// �X��
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->Draw();
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
	if(p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->Draw();
	// �L�����N�^�[
	p_character->Draw();
	BaseMove::ShadowCharaSetUpAfter();


	// �L�����N�^�[�ȊO�ăZ�b�g�A�b�v
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence())	p_enemy[i]->Draw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->Draw();
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
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->Draw();
	BaseMove::ShadowAnotherCharaSetUpAfter();


	// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->Draw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->Draw();
	}
	// �X��
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->Draw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->Draw();
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
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->Draw();
	// �L�����N�^�[
	p_character->Draw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
}


void MainMove2::AttackProcess()
{
	/// �G�Ɋւ���--------------------------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (p_enemy[i]->GetDeathFlag()) continue;

		// �������Ă����牟���o��
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 100.0f))
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
		}

		// �U������������
		if (p_character->GetAttackNow())
		{
			p_enemy[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}
	}


	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------
	if (p_adjustmentMachine->GetCanTouch())
	{
		// �������Ă����牟���o��
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, 160.0f, 0.0f)), 50.0f,
			p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 100.0f, 0.0f)), 70.0f))
		{
			p_character->HitCircleReturn(p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 100.0f, 0.0f)));
		}

		// �������߂����ŐG���{�^����������
		if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
			&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
			&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			//GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, adjustmentDrawScreen);
			adjustmentFeedNow = true;
			adjustmentStartFeed = true;
			changeAdjustmentScene = true;
		}
		if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
		{
			p_adjustmentMachine->ChangeDisplayTexture(true);
		}
		else
		{
			p_adjustmentMachine->ChangeDisplayTexture(false);
		}
	}
	

	/// �h���b�v�Ɋւ���--------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;

		if (p_adjustmentMachine->GetFullDropItem())
		{
			if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				catchDropItemNum++;
				p_dropItem[i]->SetDeath(true);			// ���������Ȃ�
				if (i % 5 == 0) SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp);
			}

			if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
			{
				p_dropItem[i]->StolenChara(p_character->GetArea());
			}
		}
		else
		{
			if (BaseMove::GetDistance(p_adjustmentMachine->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				p_adjustmentMachine->CatchDropItem();
				p_dropItem[i]->SetDeath(true);			// ���������Ȃ�
				if (i % 5 == 0) SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp);
			}

			p_dropItem[i]->StolenChara(p_adjustmentMachine->GetArea());
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


	// �|�C���^NULL������
	p_camera					 = NULL;
	p_character					 = NULL;
	for (int i = 0, n = enemyNum; i != n; ++i)
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
	vp_stageStairsRoad.clear();



	// �T�E���h�ǂݍ���
	SoundProcess::Load(v_file[EFILE::se_ballPickUp], SoundProcess::ESOUNDNAME_SE::ballPickUp);


	// �K�i�̏�����
	stairsHandle = v_file[EFILE::stairs];
	stairsTexture0 = v_file[EFILE::stairTex0];


	// �X�e�[�W�̏�����
	p_stage		 = new Stage(v_file[EFILE::drawStage]);


	// �L�����N�^�[�̏�����
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru], v_file[EFILE::stairsRoadColl]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);


	// �J�����̏�����
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);


	// �X���̏�����
	streetLightHandle = v_file[EFILE::streetLight];
	streetLightTexture0 = v_file[EFILE::streetLightTex0];
	streetLightTexture1 = v_file[EFILE::streetLightTex1];


	// �K�i�Ə��Ɋւ���
	stairsRoadHandle = v_file[EFILE::stairsRoad];
	stairsRoadTexture0 = v_file[EFILE::stairsRoadTex0];
	stairsRoadTexture1 = v_file[EFILE::stairsRoadTex1];


	// �p�l���̏�����
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], VGet(500.0f * i, 300.0f*i, 100.0f*i));
	}


	// �G�̏�����
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		p_enemy[i] = new EnemyMove2(VGet(1000.0f + (i * 150), 0.0f, -1000.0f), v_file[EFILE::block], v_file[EFILE::blockTex0]);
	}


	// �h���b�v�A�C�e���̏�����
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove2(v_file[EFILE::block], p_enemy[i / 5]->GetArea(), v_file[EFILE::blockTex0]);
	}


	// �����@�B�̏�����
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminal], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);


	// �����@�B�Ɋւ���
	changeAdjustmentScene = false;
	adjustmentDescriptionDraw = v_file[EFILE::terminalDescription];
	adjustmentSceneFeed = 0;
	adjustmentFeedNow = false;
	adjustmentSelectObject = false;
	adjustmentSelectObjectNumber = AdjustmentObject::Stairs;
	adjustmentArrangementArea = VGet(0, 0, 0);
	adjustmentArrangementDire = 0.0f;
	//adjustmentDrawScreen = MakeGraph(BASICPARAM::winWidth, BASICPARAM::winHeight);

	
	// �����@�B�ł�2D
	for (int i = 0, n = EFILE::stairsRoad2D + 1 - EFILE::block2D; i != n; ++i)
	{
		adjustment2DDraw[i] = v_file[i + EFILE::block2D];
	}


	// �h���b�v�A�C�e������ɓ��ꂽ��
	catchDropItemNum = 0;


	// �X�J�C�{�b�N�X�ǂݍ���
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox], v_file[EFILE::skyBoxTex0]);


	// �p�l���̂����蔻��
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// �X�e�[�W�̏�
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();


	// �T�E���h�̃��[�h
	SoundProcess::Load(v_file[EFILE::jump3DSE]			, SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::footCorridor3DSE]	, SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::foot3DSE]			, SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::landing3DSE]		, SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::landingSecond3DSE]	, SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::charaAttackOne3DSE], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::charaAttackTwo3DSE], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::charaAttackThree3DSE], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
}


MainMove2::~MainMove2()
{
	//GRAPHIC_RELEASE(adjustmentDrawScreen);

	/// �����@�B�Ɋւ���
	GRAPHIC_RELEASE(adjustmentDescriptionDraw);
	for (int i = 0; i != 6; ++i)
	{
		GRAPHIC_RELEASE(adjustment2DDraw[i]);
	}

	/// �p�l���Ɋւ���
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}

	/// �X���Ɋւ���
	MODEL_RELEASE(streetLightHandle);
	GRAPHIC_RELEASE(streetLightTexture0);
	GRAPHIC_RELEASE(streetLightTexture1);
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStreetLight[i]);
	}
	vp_stageStreetLight.clear();
	vp_stageStreetLight.shrink_to_fit();

	/// �K�i�Ɋւ���
	MODEL_RELEASE(stairsHandle);
	GRAPHIC_RELEASE(stairsTexture0);
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStairs[i]);
	}
	vp_stageStairs.clear();
	vp_stageStairs.shrink_to_fit();

	/// �K�i�Ə��Ɋւ���
	MODEL_RELEASE(stairsRoadHandle);
	GRAPHIC_RELEASE(stairsRoadTexture0);
	GRAPHIC_RELEASE(stairsRoadTexture1);
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStairsRoad[i]);
	}
	vp_stageStairsRoad.clear();
	vp_stageStairsRoad.shrink_to_fit();

	/// �J�����Ɋւ���
	POINTER_RELEASE(p_camera);

	/// �h���b�v�A�C�e���Ɋւ���
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}

	/// �G�Ɋւ���
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		POINTER_RELEASE(p_enemy[i]);
	}

	/// �L�����N�^�[�Ɋւ���
	POINTER_RELEASE(p_character);

	/// �X�e�[�W�Ɋւ���
	POINTER_RELEASE(p_stage);
}


// �`��
void MainMove2::Draw()
{
//	if (!changeAdjustmentScene)
//	{
		BaseMove::SkyBoxDraw();


		ShadowDraw();

		if (!p_adjustmentMachine->GetCanTouch())
		{
			p_adjustmentMachine->Draw();
		}


		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			p_dropItem[i]->Draw();
		}


		p_character->Draw();

		if (p_adjustmentMachine->GetCanTouch())
		{
			if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
			{
				DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescriptionDraw, false);
			}
		}


		DrawFormatString(255, 0, GetColor(255, 255, 255), "��ɓ��ꂽ�h���b�v�A�C�e���̐�: %d", catchDropItemNum);
	//}
	////else
	//{
		AdjustmentDraw();
	//}
}


// ���C���v���Z�X
void MainMove2::Process()
{
	if (!changeAdjustmentScene)
	{
		// �L�����N�^�[�̃v���Z�X���Ă�
		p_character->Process(p_camera->GetAngle());		


		// �J�����̃v���Z�X���Ă�
		p_camera->Process(p_character->GetArea());		


		// �G�̃v���Z�X
		for (int i = 0, n = enemyNum; i != n; ++i)
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
			p_enemy[i]->Process();												
		}

		// �h���b�v�A�C�e��
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
		if (adjustmentStartFeed)
		{
			if (adjustmentSceneFeed <= 100)
			{
				adjustmentSceneFeed++;
			}
			else
			{
				adjustmentFeedNow = false;
			}
		}
		else
		{
			if (adjustmentSceneFeed >= 0)
			{
				adjustmentSceneFeed--;
			}
			else
			{
				changeAdjustmentScene = false;
				adjustmentFeedNow = false;
			}
		}

		if (!adjustmentFeedNow)
		{
			AdjustmentProcess();
		}
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
	//if (!changeAdjustmentScene)
	//{
		p_camera->SetUp();		// �J�����̃v���Z�X���Ă�
	//}
}



void MainMove2::ThsTextureReload()
{
	// �L�����N�^�[
	p_character->TextureReload();

	// �����@�B
	p_adjustmentMachine->TextureReload();

	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (p_enemy[i]->GetDeathFlag()) continue;
		p_enemy[i]->TextureReload();
	}

	// �h���b�v�A�C�e��
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->TextureReload();
	}

	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->TextureReload();
	}

	// �X��
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->TextureReload();
	}

	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->TextureReload();
	}
}


void MainMove2::TextureReload()
{
	ths = std::thread(&MainMove2::ThsTextureReload, this);
	ths.join();
}

void MainMove2::OptionActorModel()
{
	p_character->OptionActorDraw();
}
