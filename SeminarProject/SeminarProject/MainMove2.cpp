#include "MainMove2.hpp"


// �����@�B�̃v���Z�X
void MainMove2::AdjustmentProcess()
{
	// A�{�^������������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// �z�u����I�u�W�F�N�g��I�����Ă��Ȃ��Ƃ�
		if (!adjustmentSelectObject)
		{
			// �K�i�ɃJ�[�\�����̂��Ă���Ƃ�
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				&& catchDropItemNum >= createStairsNeedNum)
			{
				catchDropItemNum -= createStairsNeedNum;
				adjustmentSelectObject = true;
			}
			// �K�i�Ə��ɃJ�[�\�����̂��Ă���Ƃ�
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				&& catchDropItemNum >= createStreetLightNeedNum)
			{
				catchDropItemNum -= createStreetLightNeedNum;
				adjustmentSelectObject = true;
			}
			// �X���ɃJ�[�\�����̂��Ă���Ƃ�
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight
				&& catchDropItemNum >= 5)
			{
				catchDropItemNum -= 5;
				adjustmentSelectObject = true;
			}
		} /// if (!adjustmentSelectObject)
		// �z�u����I�u�W�F�N�g��I�����Ă���Ƃ�
		else
		{
			// �L�����N�^�[�Ɣz�u�\��̊K�i������Ă�����
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				&& adjustmentArrangementArea.x + 120.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 120.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 250.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 250.0f < p_character->GetArea().z)
			{
				return;
			}
			// �L�����N�^�[�Ɣz�u�\��̊K�i�Ə�������Ă�����
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				&& adjustmentArrangementArea.x + 500.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 500.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 670.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 670.0f < p_character->GetArea().z)
			{
				return;
			}


			// �z�u����
			adjustmentSelectObject = false;
			AdjuctmentCreate(adjustmentArrangementArea, adjustmentSelectObjectNumber, adjustmentArrangementDire);
		} /// else (!if (!adjustmentSelectObject))
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// B�{�^���������ꂽ��
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// �I�u�W�F�N�g��I�����Ĕz�u����V�[������Ȃ�������
		if (!adjustmentSelectObject)
		{
			// �����@�B�̃V�[������߂�
			adjustmentFeedNow = true;
			adjustmentStartFeed = false;
		}
	}


	// �I�u�W�F�N�g��I�����I���Ĕz�u����V�[���̂Ƃ�
	if (adjustmentSelectObject)
	{
		// ��ʊO�ɏo�Ȃ��ʒu�ō��X�e�B�b�N���E�ɉ����ꂽ��
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0
			&& adjustmentArrangementArea.x > -4500.0f)
		{
			adjustmentArrangementArea.x -= 10.0f;
		}
		// ��ʊO�ɏo�Ȃ��ʒu�ō��X�e�B�b�N������
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0
			&& adjustmentArrangementArea.x < 4500.0f)
		{
			adjustmentArrangementArea.x += 10.0f;
		}
		// ��ʊO�ɏo�Ȃ��ʒu�ō��X�e�B�b�N�����
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0
			&& adjustmentArrangementArea.z > -4500.0f)
		{
			adjustmentArrangementArea.z -= 10.0f;
		}
		// ��ʊO�ɏo�Ȃ��ʒu�ō��X�e�B�b�N������
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0
			&& adjustmentArrangementArea.z < 4500.0f)
		{
			adjustmentArrangementArea.z += 10.0f;
		}
		// �E�X�e�B�b�N���E��
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
		{
			adjustmentArrangementDire += DX_PI_F / 60;
		}
		// �E�X�e�B�b�N������
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) < 0)
		{
			adjustmentArrangementDire -= DX_PI_F / 60;
		}
	} /// if (adjustmentSelectObject)
	// �I�u�W�F�N�g��I������V�[���̂Ƃ�
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
		/// ---------------------------------------------------------------------------------------------------------------

		
		// �J�[�\�����E�Ɉړ�
		if (adjustmentControllStick[0] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp > 0 ? --temp : temp);
		}
		// �J�[�\�������Ɉړ�
		if (adjustmentControllStick[1] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp < 2 ? ++temp : temp);
		}


		// RB�{�^���������ꂽ��
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
			&& !BASICPARAM::paneruDrawFlag)
		{
			// ���̃V�[���֍s�����߂̃p�l����`�悷��悤�ɏ���
			BASICPARAM::paneruDrawFlag = true;
		}
	} /// else (!if (adjustmentSelectObject))
} /// void MainMove2::AdjustmentProcess()


// �����@�B�̕`��
void MainMove2::AdjustmentDraw()
{
	// �t�F�[�h�V�[���̕`�悪�؂�ւ��V�[���ȏ�̐��l�֍s������
	if (adjustmentSceneFeed >= 50)
	{
		// �w�i
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(247, 247, 247), true);


		/// �z�u����Ă���I�u�W�F�N�g��2D-----------------------------------------------------------------------------------------------
		// �G~~
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			if (p_enemy[i]->GetDeathFlag()) continue;
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
				DrawBox(static_cast<int>((4500 - p_stagePaneru[i]->GetArea().x) / 9000 * 1920) - 25
					, static_cast<int>((4500 + p_stagePaneru[i]->GetArea().z) / 9000 * 1080) - 25
					, static_cast<int>((4500 - p_stagePaneru[i]->GetArea().x) / 9000 * 1920) + 25
					, static_cast<int>((4500 + p_stagePaneru[i]->GetArea().z) / 9000 * 1080) + 25
					, GetColor(200, 200, 200), true);
			}
		}
		// �L�����N�^�[
		DrawRotaGraph(static_cast<int>((4500 - p_character->GetArea().x) / 9000 * 1920)
			, static_cast<int>((4500 + p_character->GetArea().z) / 9000 * 1080)
			, 0.1, p_character->GetAngle() - DX_PI, adjustment2DDraw[1], true);
		/// -------------------------------------------------------------------------------------------------------------------------------


		// �z�u�����I�u�W�F�N�g��z�u����Ƃ�
		if (adjustmentSelectObject)
		{
			// �{�^������
			DrawFormatString(30, 60, GetColor(0, 0, 0), "A�{�^���Ŕz�u");

			/// �������ŃI�u�W�F�N�g��\��-------------------------------------------------------------
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
			// �K�i�̕\��
			if (adjustmentSelectObjectNumber==AdjustmentObject::Stairs)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.22, adjustmentArrangementDire, adjustment2DDraw[3], true);
			}
			// �K�i�Ə��̕\��
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.75, adjustmentArrangementDire, adjustment2DDraw[5], true);
			}
			// �X���̕\��
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.15, adjustmentArrangementDire, adjustment2DDraw[2], true);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			/// -------------------------------------------------------------------------------------------
		} /// if (adjustmentSelectObject)
		// �z�u����I�u�W�F�N�g��I�����Ă��Ȃ��Ƃ�
		else
		{
			// �{�b�N�X�\��
			DrawBox(0, 0, 980, 540, GetColor(255, 255, 255), true);
			DrawBox(0, 0, 980, 540, GetColor(0, 0, 0), false);

			// �������
			DrawFormatString(10, 10, GetColor(0, 0, 0), "A�{�^���Ō���");

			// �K�i�\��
			if (catchDropItemNum < createStairsNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(120, 120, 0.22, 0.0, adjustment2DDraw[3], true);
			DrawFormatString(50, 170, GetColor(0, 0, 0), "�K�i: %d�u���b�N", createStairsNeedNum);
			if (catchDropItemNum < createStairsNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// �K�i�Ə��\��
			if (catchDropItemNum < createStreetLightNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(320, 130, 0.75, 0.0, adjustment2DDraw[5], true);
			DrawFormatString(240, 250, GetColor(0, 0, 0), "�K�i����: %d�u���b�N", createStreetLightNeedNum);
			if (catchDropItemNum < createStreetLightNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// �X���\��
			if (catchDropItemNum < createStairsRoadNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(500, 120, 0.15, 0.0, adjustment2DDraw[2], true);
			DrawFormatString(430, 170, GetColor(0, 0, 0), "�X��: %d�u���b�N", createStairsRoadNeedNum);
			if (catchDropItemNum < createStairsRoadNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// �p�l������
			DrawFormatString(20, 350, GetColor(0, 0, 0), "RB�{�^���Ŏ��̃X�e�[�W�ւ̓�");

			// �K�i�ł̃J�[�\���\��
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs)
			{
				if (catchDropItemNum < createStairsNeedNum)
				{
					DrawBox(30, 30, 200, 230, GetColor(125, 125, 125), false);
				}
				else
				{
					DrawBox(30, 30, 200, 230, GetColor(0, 0, 0), false);
				}
			}
			// �K�i�Ə��̃J�[�\���\��
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				if (catchDropItemNum < createStreetLightNeedNum)
				{
					DrawBox(230, 30, 420, 280, GetColor(125, 125, 125), false);
				}
				else
				{
					DrawBox(230, 30, 420, 280, GetColor(0, 0, 0), false);
				}
			}
			// �X���̃J�[�\���\��
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				if (catchDropItemNum < createStairsRoadNeedNum)
				{
					DrawBox(420, 60, 570, 220, GetColor(125, 125, 125), false);
				}
				else
				{
					DrawBox(420, 60, 570, 220, GetColor(0, 0, 0), false);
				}
			}

			// �߂����
			DrawFormatString(30, 500, GetColor(0, 0, 0), "B�{�^���Ŗ߂�");

			// ���݂̎擾�h���b�v���\��
			DrawFormatString(1020, 20, GetColor(0, 0, 0), "��ɓ��ꂽ�h���b�v�A�C�e���̐�: %d", catchDropItemNum);
		} /// else (!if (adjustmentSelectObject))
	} /// if (adjustmentSceneFeed >= 50)


	/// �I�y���[�^�[�̃t�F�[�h�\���Ɋւ���-----------------------------------------------------------
	if (adjustmentSceneFeed <= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed > 50 && adjustmentSceneFeed <= 100)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (20 - adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
	/// ---------------------------------------------------------------------------------------------

} /// void MainMove2::AdjustmentDraw()


// �����@�B�ŃI�u�W�F�N�g�̐����v���Z�X
void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction)
{
	// �ǂ̃I�u�W�F�N�g���I�����ꂽ��
	switch (obujectID)
	{
	// �K�i���I������Ă�����
	case AdjustmentObject::Stairs:
		vp_stageStairs.push_back(new StageStairs(stairsHandle, area, stairsTexture0, DX_PI_F + direction));		// ����
		p_character->SetStairsArea(vp_stageStairs[BASICPARAM::stairsNum]->GetArea(), BASICPARAM::stairsNum, DX_PI_F + direction);	// �L�����N�^�[�ɑ΂��ē����蔻�萶��
		BASICPARAM::stairsNum++;									// �S�̂Ŋm�F�ł���悤�ɊK�i�̌���ǉ�
		BASICPARAM::v_stairsArea.push_back(area);					// �S�̂Ŋm�F�ł���悤�ɏꏊ��ǉ�
		BASICPARAM::v_stairsAngle.push_back(DX_PI_F + direction);	// �S�̂Ŋm�F�ł���悤�Ɋp�x��ǉ�
		break;


	// �X�����I������Ă�����
	case AdjustmentObject::StreetLight:
		vp_stageStreetLight.push_back(new StageStreetLight(streetLightHandle, area, streetLightTexture0, streetLightTexture1, direction));	// ����
		BASICPARAM::streetLightNum++;								// �S�̂Ŋm�F�ł���悤�ɊX���̌���ǉ�
		BASICPARAM::v_streetLightArea.push_back(area);				// �S�̂Ŋm�F�ł���悤�ɏꏊ��ǉ�
		BASICPARAM::v_streetLightAngle.push_back(direction);		// �S�̂Ŋm�F�ł���悤�Ɋp�x��ǉ�
		break;


	// �K�i�Ə����I������Ă�����
	case AdjustmentObject::StairsRoad:
		vp_stageStairsRoad.push_back(new StageStairsRoad(stairsRoadHandle, area, stairsRoadTexture0, stairsRoadTexture1, DX_PI_F + direction));		// ����
		p_character->SetStairsRoadArea(vp_stageStairsRoad[BASICPARAM::stairsRoadNum]->GetArea(), BASICPARAM::stairsRoadNum, DX_PI_F + direction);	// �L�����N�^�[�ɑ΂��Ă����蔻�萶��
		BASICPARAM::stairsRoadNum++;									// �S�̂Ŋm�F�ł���悤�ɊK�i�Ə��̌���ǉ�
		BASICPARAM::v_stairsRoadArea.push_back(area);					// �S�̂Ŋm�F�ł���悤�ɏꏊ��ǉ�
		BASICPARAM::v_stairsRoadAngle.push_back(DX_PI_F + direction);	// �S�̂Ŋm�F�ł���悤�Ɋp�x��ǉ�
		break;

	default:
		break;
	}
} /// void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction)


// �V���h�E�}�b�v�ł̉e��`��
void MainMove2::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->ModelDraw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// �X��
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
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
	if(p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	// �L�����N�^�[
	p_character->ModelDraw();


	/// �L�����N�^�[�ȊO�ăZ�b�g�A�b�v
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence())	p_enemy[i]->ModelDraw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
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
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	BaseMove::ShadowSetUpAfter();


	/// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->ModelDraw();
	}
	// �K�i
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// �X��
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// �K�i�Ə�
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
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
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	// �L�����N�^�[
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// �L�����N�^�[
	p_character->ModelDraw();
} /// void MainMove2::ShadowDraw()


// �U���Ƃ����蔻��̃v���Z�X
void MainMove2::AttackProcess()
{
	/// �G�Ɋւ���--------------------------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		// ����ł����玟��
		if (p_enemy[i]->GetDeathFlag()) continue;

		// �������Ă�����v���C���[�������o��
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, p_enemy[i]->GetHeight(), 0.0f)), p_enemy[i]->GetWidth()))
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea()
				, p_enemy[i]->GetWidth() >= p_character->GetWidth() ? p_enemy[i]->GetWidth() : p_character->GetWidth());
		}


		// �v���C���[���U������������
		if (p_character->GetAttackNow())
		{
			// �G�Ɍ����G�ꂽ���ǂ������ׂ�
			p_enemy[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// �U���Ń_���[�W���󂯂���
		if (p_enemy[i]->GetDamageFlag())
		{
			// �o�C�u���[�V����������
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);

			// �G�t�F�N�g���Đ�����B
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemyNum; i != n; ++i)


	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------
	if (p_adjustmentMachine->GetCanTouch())
	{
		// �������Ă�����v���C���[�������o��
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
		}

		// �������߂����ŐG���{�^��(B�{�^��)����������
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
			&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
			&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			// �����@�B�̃V�[���ֈڍs
			//GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, adjustmentDrawScreen);
			adjustmentFeedNow = true;
			adjustmentStartFeed = true;
			changeAdjustmentScene = true;
		}

		
		// �v���C���[�Ƃ̋����Ő����@�B�̃p�l���̃e�N�X�`����ς���
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
		{
			p_adjustmentMachine->ChangeDisplayTexture(true);
		}
		else
		{
			p_adjustmentMachine->ChangeDisplayTexture(false);
		}
	} /// if (p_adjustmentMachine->GetCanTouch())
	

	/// �h���b�v�Ɋւ���--------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		// �����E���Ă��邩�ǂ����Ŏ���
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;


		// �����@�B���h���b�v�����\����ɓ���Ă�����
		if (p_adjustmentMachine->GetFullDropItem())
		{
			// �v���C���[���߂�������
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
			{
				// �v���C���[�ɋ߂Â�
				p_dropItem[i]->ChaseActor(p_character->GetArea());
			}


			// �v���C���[�Ƃ̋���������鋗����������
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				catchDropItemNum++;
				p_dropItem[i]->SetDeath(true);			// ���������Ȃ�

				/// SE�̍Đ��������_���ɂ���-----------------------------------------------------------------------------
				std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
				std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
				std::uniform_int_distribution<> randPawnSE(0, 1);        // ����

				// �h���b�v�A�C�e�����擾����SE�𗬂�
				if (randPawnSE(mt) == 0)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp, p_dropItem[i]->GetArea());
				}
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp2, p_dropItem[i]->GetArea());
				}
				/// -----------------------------------------------------------------------------------------------------
			}
		} /// if (p_adjustmentMachine->GetFullDropItem())
		// �����@�B���h���b�v�����\���Ɏ�ɓ���Ă��Ȃ�������
		else
		{
			// �����@�B�Ƃ̋������߂�������
			if (BaseMove::GetDistance<int>(p_adjustmentMachine->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				p_adjustmentMachine->CatchDropItem();
				p_dropItem[i]->SetDeath(true);			// ���������Ȃ�

				/// SE�̍Đ��������_���ɂ���-----------------------------------------------------------------------------
				std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
				std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
				std::uniform_int_distribution<> randPawnSE(0, 1);        // ����

				// �h���b�v�擾��SE�𗬂�
				if (randPawnSE(mt) == 0)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp, p_dropItem[i]->GetArea());
				}
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp2, p_dropItem[i]->GetArea());
				}
				/// -----------------------------------------------------------------------------------------------------
			}

			// �����@�B�֌�����
			p_dropItem[i]->ChaseActor(p_adjustmentMachine->GetArea());
		} /// else (!if (p_adjustmentMachine->GetFullDropItem()))
	} /// for (int i = 0, n = enemyNum * 5; i != n; ++i)
} /// void MainMove2::AttackProcess()


// �R���X�g���N�^
MainMove2::MainMove2(const std::vector<int> v_file)
{
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::stairsNum = 0;
	BASICPARAM::streetLightNum = 0;
	BASICPARAM::stairsRoadNum = 0;
	BASICPARAM::v_stairsArea.clear();
	BASICPARAM::v_stairsAngle.clear();
	BASICPARAM::v_streetLightArea.clear();
	BASICPARAM::v_streetLightAngle.clear();
	BASICPARAM::v_stairsRoadArea.clear();
	BASICPARAM::v_stairsRoadAngle.clear();


	// �|�C���^NULL������
	p_camera					 = nullptr;
	p_character					 = nullptr;
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		p_enemy[i]				 = nullptr;
	}
	p_stage						 = nullptr;
	vp_stageStairs.clear();
	vp_stageStreetLight.clear();
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i]		 = nullptr;
	}
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i] = nullptr;
	}
	p_adjustmentMachine = nullptr;
	vp_stageStairsRoad.clear();


	// �K�i�̏�����
	stairsHandle = v_file[EFILE::stairs];
	stairsTexture0 = v_file[EFILE::stairTex0];


	// �X�e�[�W�̏�����
	p_stage		 = new Stage(v_file[EFILE::drawStage]);


	// �L�����N�^�[�̏�����
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru], v_file[EFILE::stairsRoadColl]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);


	// ��������摜�̏�����
	operationUIDraw[static_cast<int>(EOPERATION_UI::attack)] = v_file[EFILE::attackUI];
	operationUIDraw[static_cast<int>(EOPERATION_UI::jump)] = v_file[EFILE::jumpUI];
	operationUIDraw[static_cast<int>(EOPERATION_UI::fastSpeed)] = v_file[EFILE::fastSpeedUI];
	operationUIDraw[static_cast<int>(EOPERATION_UI::option)] = v_file[EFILE::optionUI];
	for (int i = 0; i != 2; ++i)
	{
		operationUIFeed[i] = 255;
		nextOperationUIFeed[i] = 255;
	}
	for (int i = 3; i != 4; ++i)
	{
		operationUIFeed[i] = 0;
		nextOperationUIFeed[i] = 0;
	}
	opeFastOptionEnd = false;


	// �J�����̏�����
	p_camera	 = new Camera(p_character->GetArea());


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
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], VGet(500.0f * i, 300.0f * i, 100.0f * i));
	}


	// �G�̏�����
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z���W�p����
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		// �ʂ�X���W�ݒ�
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 200.0f && tempX >= 0.0f)
		{
			tempX += 200.0f;
		}
		if (tempX >= -200.0f && tempX <= 0.0f)
		{
			tempX -= 200.0f;
		}

		// �ʂ�Y���W�ݒ�
		float tempZ = static_cast<float>(randInZ(mt));
		if (tempZ <= 200.0f && tempZ >= 0.0f)
		{
			tempZ += 200.0f;
		}
		if (tempZ >= -200.0f && tempZ <= 0.0f)
		{
			tempZ -= 200.0f;
		}
		p_enemy[i] = new EnemyMove2(VGet(tempX, 0.0f, tempZ), v_file[EFILE::block], v_file[EFILE::blockTex0]);
	}
	mostNearEnemyDistance = 10000;
	lockONNowEnemyID = 0;


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
	BaseMove::ShadowSetUpAfter();


	// �T�E���h�̃��[�h
	SoundProcess::Load(v_file[EFILE::se_ballPickUp]			, SoundProcess::ESOUNDNAME_SE::ballPickUp);
	SoundProcess::Load(v_file[EFILE::jump3DSE]				, SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::footCorridor3DSE]		, SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::foot3DSE]				, SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::landing3DSE]			, SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::landingSecond3DSE]		, SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::charaAttackOne3DSE]	, SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::charaAttackTwo3DSE]	, SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::charaAttackThree3DSE]	, SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_ballPickUp2]		, SoundProcess::ESOUNDNAME_SE::ballPickUp2);
	SoundProcess::Load(v_file[EFILE::nextStageBGM]			, SoundProcess::ESOUNDNAME_BGM::normalBGM);

	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 0, 0);
	bgmOnceVolumeChange = 0;


	// �G�t�F�N�g�ǂݍ���
	effectAttack = LoadEffekseerEffect("media\\������\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
} /// MainMove2::MainMove2(const std::vector<int> v_file)


// �f�X�g���N�^
MainMove2::~MainMove2()
{
	/// �G�t�F�N�g�Ɋւ���
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);
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


	/// �����摜�Ɋւ���
	for (int i = 0; i != 4; ++i)
	{
		GRAPHIC_RELEASE(operationUIDraw[i]);
	}


	/// �L�����N�^�[�Ɋւ���
	POINTER_RELEASE(p_character);


	/// �X�e�[�W�Ɋւ���
	POINTER_RELEASE(p_stage);
} /// MainMove2::~MainMove2()


// �`��
void MainMove2::Draw()
{
	// �X�J�C�{�b�N�X�̕`��
	BaseMove::SkyBoxDraw();


	// �e�̕`��
	ShadowDraw();


	// �h���b�v�����W�܂�O�̐����@�B�̕`��
	if (!p_adjustmentMachine->GetCanTouch())
	{
		p_adjustmentMachine->Draw();
		p_adjustmentMachine->ModelDraw();
	}


	// �h���b�v�A�C�e���̕`��
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;
		p_dropItem[i]->ModelDraw();
	}


	// �L�����N�^�[
	p_character->Draw();


	// �����@�B�ւ̃h���b�v�����\���������Ƃ�
	if (p_adjustmentMachine->GetCanTouch())
	{
		// �����@�B�̓���ɋN������̐����`��
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
		{
			DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescriptionDraw, false);
		}
	}


	// �v���C���[�̑�������`��
	for (int i = 0; i != 4; ++i)
	{
		// �u�����h�l��ψڂ�����
		if (operationUIFeed[i] < nextOperationUIFeed[i]) operationUIFeed[i]++;
		if (operationUIFeed[i] > nextOperationUIFeed[i]) operationUIFeed[i]--;


		/// �`��摜���u�����h����----------------------------------------------
		// �����摜�̃u�����h�l��0�ȏゾ������
		if (operationUIFeed[i] > 0)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, operationUIFeed[i]);

			// ���̉摜
			if (i % 2 == 0)
			{
				DrawGraph(100, 100, operationUIDraw[i], true);
			}
			// �E�̉摜
			else
			{

				DrawGraph(1200, 100, operationUIDraw[i], true);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}


	// �v���C���[����߂��G�ɑ΂��ă��b�N�I���̂悤�ȕ`����X�N���[�����W�ɂ�����
	if (mostNearEnemyDistance <= 1000 && !p_enemy[lockONNowEnemyID]->GetEraseExistence())
	{
		// �������U���œ����邭�炢�̋�����������
		if (mostNearEnemyDistance < 250)
		{
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
		}
		// �U���͓�����Ȃ����߂�������
		else
		{
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
		}
	}


	// �擾�����h���b�v���̕\��
	DrawFormatString(1020, 20, GetColor(0, 0, 0), "��ɓ��ꂽ�h���b�v�A�C�e���̐�: %d", catchDropItemNum);


	// �����@�B�̃V�[���̕`��
	AdjustmentDraw();

#ifdef _DEBUG
	// �G
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		p_enemy[i]->Draw();
	}
#endif // _DEBUG
} /// void MainMove2::Draw()


// ���C���v���Z�X
void MainMove2::Process()
{
	// �����@�B�̃V�[������Ȃ�������
	if (!changeAdjustmentScene)
	{
		// �L�����N�^�[�̃v���Z�X���Ă�
		p_character->Process(p_camera->GetAngle());		


		// ���߂čU����������
		if (p_character->GetAttackNow() && nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] != 0)
		{
			// �U���̑������UI������
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] = 0;
		}


		// ���߂ăW�����v��������
		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] != 0
			&& p_character->GetArea().y > 50.0f)
		{
			// �W�����v�̑������UI������
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] = 0;
		}


		// ���߂ďu�Ԉړ���������
		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] != 0
			&& p_character->GetMoveFastWaitCount())
		{
			// �u�Ԉړ��ƃI�v�V������ʂւ̑������UI������
			opeFastOptionEnd = true;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 0;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 0;
		}
		

		// �U���ƃW�����v�̑������UI����������
		if (operationUIFeed[static_cast<int>(EOPERATION_UI::attack)] == 0
			&& operationUIFeed[static_cast<int>(EOPERATION_UI::jump)] == 0
			&& !opeFastOptionEnd)
		{
			// �u�Ԉړ��ƃI�v�V������ʂւ̑������UI��\��������
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 255;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 255;
		}


		// �J�����̃v���Z�X���Ă�
		p_camera->Process(p_character->GetArea());		


		// �G�̃v���Z�X
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			// �G�����ł�����
			if (p_enemy[i]->GetEraseExistence())
			{
				// ���b�N�I���Ώۂ�������
				if (i == lockONNowEnemyID)
				{
					// ���O������
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// �h���b�v�A�C�e����`�悳����
				if (!p_dropItem[(i * 5)]->GetDeath() && !p_dropItem[(i * 5)]->GetAlive()) p_dropItem[(i * 5)]->SetAlive(true);
				else continue;
				if (!p_dropItem[(i * 5) + 1]->GetDeath() && !p_dropItem[(i * 5) + 1]->GetAlive()) p_dropItem[(i * 5) + 1]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 2]->GetDeath() && !p_dropItem[(i * 5) + 2]->GetAlive()) p_dropItem[(i * 5) + 2]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 3]->GetDeath() && !p_dropItem[(i * 5) + 3]->GetAlive()) p_dropItem[(i * 5) + 3]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 4]->GetDeath() && !p_dropItem[(i * 5) + 4]->GetAlive()) p_dropItem[(i * 5) + 4]->SetAlive(true);
				continue;
			}


			// �G�̃v���Z�X���Ă�
			p_enemy[i]->Process();


			// �G�ƃv���C���[�̋��������b�N�I���Ώۂ��߂�������
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[lockONNowEnemyID]->GetArea())
				>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[i]->GetArea()))
			{
				// ���b�N�I���Ώۂ��X�V����
				mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[i]->GetArea());
				mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemy[i]->GetArea());
				lockONNowEnemyID = i;


				// ���b�N�I���̋������߂�������
				if (mostNearEnemyDistance < 250)
				{
					p_character->SetMostNearEnemyArea(p_enemy[i]->GetArea());
				}
				// ���b�N�I���ł��Ȃ������������珜�O����
				else
				{
					p_character->SetMostNearEnemyArea();
				}
			}
		} /// for (int i = 0, n = enemyNum; i != n; ++i)


		// �h���b�v�A�C�e��
		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			if (p_dropItem[i]->GetDeath()) continue;
			p_dropItem[i]->Process();
		}


		// �V���h�E�}�b�v�̃v���C���[�̈ʒu���X�V
		BaseMove::ShadowArea(p_character->GetArea());


		// �U���v���Z�X���Ă�
		AttackProcess();


		// �X�J�C�{�b�N�X�̃v���C���[�̈ʒu���X�V
		BaseMove::SkyBoxProcess(p_character->GetArea());


		/// �v���C���[�̍��W�ɂĎ��̃V�[����BGM�𗬂�---------------------------------------------------------------------
		if (p_character->GetArea().y >= 2500.0f)
		{
			if (bgmOnceVolumeChange != 5) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 200, 200);
			bgmOnceVolumeChange = 5;
		}
		else if (p_character->GetArea().y >= 2000.0f)
		{
			if (bgmOnceVolumeChange != 4) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 170, 170);
			bgmOnceVolumeChange = 4;
		}
		else if (p_character->GetArea().y >= 1500.0f)
		{
			if (bgmOnceVolumeChange != 3) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 150, 150);
			bgmOnceVolumeChange = 3;
		}
		else if (p_character->GetArea().y >= 1000.0f)
		{
			if (bgmOnceVolumeChange != 2) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 100, 100);
			bgmOnceVolumeChange = 2;
		}
		else if (p_character->GetArea().y >= 500.0f)
		{
			if (bgmOnceVolumeChange != 1) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 50, 50);
			bgmOnceVolumeChange = 1;
		}
		else
		{
			if (bgmOnceVolumeChange != 0) SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 0, 0);
			bgmOnceVolumeChange = 0;
		}
		/// ------------------------------------------------------------------------------------------------------------------


		// �v���C���[�̈ʒu�ɂĎ��̃V�[���ֈړ�����
		if (p_character->GetArea().y >= 3550.0f)
		{
			BASICPARAM::endFeedNow = true;
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			BaseMove::SetScene(ESceneNumber::THIRDLOAD);
		}
	} /// if (!changeAdjustmentScene)
	else
	{
		// �����@�B����ʏ�ւ̃t�F�[�h�V�[�����n�܂�����
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
		// �ʏ킩�琸���@�B�ւ̃t�F�[�h�V�[�����n�߂܂�����
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

		
		// �����@�B�ւ̃t�F�[�h�V�[�����I�������v���Z�X���Ă�
		if (!adjustmentFeedNow)
		{
			AdjustmentProcess();
		}
	} /// else (!if (!changeAdjustmentScene))

#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
		BaseMove::SetScene(ESceneNumber::THIRDLOAD);
	}
#endif
} /// void MainMove2::Process()


// �J�����̍ăZ�b�g�A�b�v
void MainMove2::CameraProcess()
{
	p_camera->SetUp();
}


// �I�v�V������ʃ��f���p�̕\��
void MainMove2::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// �I�v�V������ʃ��f���̏���
void MainMove2::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// �I�v�V������ʃ��f���̉���
void MainMove2::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
