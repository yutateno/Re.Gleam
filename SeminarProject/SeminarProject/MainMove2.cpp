#include "MainMove2.hpp"




void MainMove2::AdjustmentProcess()
{
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		if (!adjustmentSelectObject)
		{
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				/*&& catchDropItemNum >= 15*/)
			{
				catchDropItemNum -= 15;
				adjustmentSelectObject = true;
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				/*&& catchDropItemNum >= 45*/)
			{
				catchDropItemNum -= 45;
				adjustmentSelectObject = true;
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight
				/*&& catchDropItemNum >= 5*/)
			{
				catchDropItemNum -= 5;
				adjustmentSelectObject = true;
			}
		}
		else
		{
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				&& adjustmentArrangementArea.x + 120.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 120.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 250.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 250.0f < p_character->GetArea().z)
			{
				return;
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				&& adjustmentArrangementArea.x + 500.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 500.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 670.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 670.0f < p_character->GetArea().z)
			{
				return;
			}
			adjustmentSelectObject = false;
			AdjuctmentCreate(adjustmentArrangementArea, adjustmentSelectObjectNumber, adjustmentArrangementDire);
		}
	}
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		if (!adjustmentSelectObject)
		{
			adjustmentFeedNow = true;
			adjustmentStartFeed = false;
		}
	}

	if (adjustmentSelectObject)
	{
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0
			&& adjustmentArrangementArea.x > -4500.0f)
		{
			adjustmentArrangementArea.x -= 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0
			&& adjustmentArrangementArea.x < 4500.0f)
		{
			adjustmentArrangementArea.x += 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0
			&& adjustmentArrangementArea.z > -4500.0f)
		{
			adjustmentArrangementArea.z -= 10.0f;
		}
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0
			&& adjustmentArrangementArea.z < 4500.0f)
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
		// スティックの一回押し倒しで更新するよう調整。
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
		
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
			&& !BASICPARAM::paneruDrawFlag)
		{
			BASICPARAM::paneruDrawFlag = true;
		}
	}
}


void MainMove2::AdjustmentDraw()
{
	if (adjustmentSceneFeed >= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(247, 247, 247), true);


		/// 配置されているオブジェクトの2D----------------------------------------------------------------------------------------------------------------------------------------
		// 敵~~
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			if (p_enemy[i]->GetDeathFlag()) continue;
			DrawRotaGraph(static_cast<int>((4500 - p_enemy[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + p_enemy[i]->GetArea().z) / 9000 * 1080)
				, 0.1, 0.0, adjustment2DDraw[0], true);
		}
		// 街灯~~
		for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStreetLight[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStreetLight[i]->GetArea().z) / 9000 * 1080)
				, 0.15, vp_stageStreetLight[i]->GetYAngle(), adjustment2DDraw[2], true);
		}
		// 階段~~
		for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStairs[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStairs[i]->GetArea().z) / 9000 * 1080)
				, 0.22, DX_PI + vp_stageStairs[i]->GetYAngle(), adjustment2DDraw[3], true);
		}
		// オペレーター
		if (p_adjustmentMachine->GetCanTouch()) DrawRotaGraph(static_cast<int>((4500 - p_adjustmentMachine->GetArea().x) / 9000 * 1920)
			, static_cast<int>((4500 + p_adjustmentMachine->GetArea().z) / 9000 * 1080)
			, 0.08, DX_PI, adjustment2DDraw[4], true);

		// 階段と床~~
		for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
		{
			DrawRotaGraph(static_cast<int>((4500 - vp_stageStairsRoad[i]->GetArea().x) / 9000 * 1920)
				, static_cast<int>((4500 + vp_stageStairsRoad[i]->GetArea().z) / 9000 * 1080)
				, 0.75, DX_PI + vp_stageStairsRoad[i]->GetYAngle(), adjustment2DDraw[5], true);
		}
		// パネル~~
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
		// キャラクター
		DrawRotaGraph(static_cast<int>((4500 - p_character->GetArea().x) / 9000 * 1920)
			, static_cast<int>((4500 + p_character->GetArea().z) / 9000 * 1080)
			, 0.1, p_character->GetAngle() - DX_PI, adjustment2DDraw[1], true);


		// 配置するオブジェクトについて
		if (adjustmentSelectObject)
		{
			DrawFormatString(30, 60, GetColor(0, 0, 0), "Aボタンで配置");

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

			DrawFormatString(10, 10, GetColor(0, 0, 0), "Aボタンで決定");

			if (catchDropItemNum < 15) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawRotaGraph(120, 120, 0.22, 0.0, adjustment2DDraw[3], true);
			DrawFormatString(50, 170, GetColor(0, 0, 0), "階段: 15ブロック");
			if (catchDropItemNum < 15) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			if (catchDropItemNum < 45) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawRotaGraph(320, 130, 0.75, 0.0, adjustment2DDraw[5], true);
			DrawFormatString(240, 250, GetColor(0, 0, 0), "階段＆床: 45ブロック");
			if (catchDropItemNum < 45) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			if (catchDropItemNum < 5) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
			DrawRotaGraph(500, 120, 0.15, 0.0, adjustment2DDraw[2], true);
			DrawFormatString(430, 170, GetColor(0, 0, 0), "街灯: 5ブロック");
			if (catchDropItemNum < 5) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			DrawFormatString(20, 350, GetColor(0, 0, 0), "RBボタンで次のステージへの道");

			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs)
			{
				if (catchDropItemNum < 15)
				{
					DrawBox(30, 30, 200, 230, GetColor(0, 0, 255), false);
				}
				else
				{
					DrawBox(30, 30, 200, 230, GetColor(255, 0, 0), false);
				}
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				if (catchDropItemNum < 45)
				{
					DrawBox(230, 30, 420, 280, GetColor(0, 0, 255), false);
				}
				else
				{
					DrawBox(230, 30, 420, 280, GetColor(255, 0, 0), false);
				}
			}
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				if (catchDropItemNum < 5)
				{
					DrawBox(420, 60, 570, 220, GetColor(0, 0, 255), false);
				}
				else
				{
					DrawBox(420, 60, 570, 220, GetColor(255, 0, 0), false);
				}
			}

			DrawFormatString(30, 500, GetColor(0, 0, 0), "Bボタンで戻る");

			DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);
		}
	}
	//else
	//{
	//	DrawGraph(0, 0, adjustmentDrawScreen, true);
	//}

	/// オペレーターのフェード表現に関する-----------------------------------------------------------
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
		BASICPARAM::v_stairsAngle.push_back(DX_PI_F + direction);
		break;

	case AdjustmentObject::StreetLight:
		vp_stageStreetLight.push_back(new StageStreetLight(streetLightHandle, area, streetLightTexture0, streetLightTexture1, direction));
		BASICPARAM::streetLightNum++;
		BASICPARAM::v_streetLightArea.push_back(area);
		BASICPARAM::v_streetLightAngle.push_back(direction);
		break;

	case AdjustmentObject::StairsRoad:
		vp_stageStairsRoad.push_back(new StageStairsRoad(stairsRoadHandle, area, stairsRoadTexture0, stairsRoadTexture1, DX_PI_F + direction));
		p_character->SetStairsRoadArea(vp_stageStairsRoad[BASICPARAM::stairsRoadNum]->GetArea(), BASICPARAM::stairsRoadNum, DX_PI_F + direction);
		BASICPARAM::stairsRoadNum++;
		BASICPARAM::v_stairsRoadArea.push_back(area);
		BASICPARAM::v_stairsRoadAngle.push_back(DX_PI_F + direction);
		break;

	default:
		break;
	}
}


void MainMove2::ShadowDraw()
{
	/// セットアップ
	BaseMove::ShadowCharaSetUpBefore();
	// 敵
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->ModelDraw();
	}
	// 階段
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// 街灯
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// 階段と床
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	if(p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	// キャラクター
	p_character->ModelDraw();
	BaseMove::ShadowCharaSetUpAfter();


	/// キャラクター以外再セットアップ
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// 階段
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// 敵
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence())	p_enemy[i]->ModelDraw();
	}
	// 階段
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// 階段と床
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	BaseMove::ShadowAnotherCharaSetUpAfter();


	/// 描画
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// ステージ
	p_stage->Draw();
	// 敵
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (!p_enemy[i]->GetEraseExistence()) p_enemy[i]->ModelDraw();
	}
	// 階段
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		vp_stageStairs[i]->ModelDraw();
	}
	// 街灯
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		vp_stageStreetLight[i]->ModelDraw();
	}
	// 階段と床
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		vp_stageStairsRoad[i]->ModelDraw();
	}
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	if (p_adjustmentMachine->GetCanTouch()) p_adjustmentMachine->ModelDraw();
	// キャラクター
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// キャラクター
	p_character->ModelDraw();
}


void MainMove2::AttackProcess()
{
	/// 敵に関する--------------------------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		if (p_enemy[i]->GetDeathFlag()) continue;

		// 当たっていたら押し出す
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, p_enemy[i]->GetHeight(), 0.0f)), p_enemy[i]->GetWidth()))
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea()
				, p_enemy[i]->GetWidth() >= p_character->GetWidth() ? p_enemy[i]->GetWidth() : p_character->GetWidth());
		}

		// 攻撃中だったら
		if (p_character->GetAttackNow())
		{
			if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] != 0) nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] = 0;
			p_enemy[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// 攻撃でダメージを受けたら
		if (p_enemy[i]->GetDamageFlag())
		{
			// バイブレーションさせる
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);

			// エフェクトを再生する。
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	}


	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------
	if (p_adjustmentMachine->GetCanTouch())
	{
		// 当たっていたら押し出す
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
		}

		// 距離が近かくで触れるボタン押したら
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
	

	/// ドロップに関する--------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;

		if (p_adjustmentMachine->GetFullDropItem())
		{
			if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
			{
				p_dropItem[i]->StolenChara(p_character->GetArea());
			}


			if (BaseMove::GetDistance(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				catchDropItemNum++;
				p_dropItem[i]->SetDeath(true);			// 生きさせない

				/// SEの再生をランダムにする-----------------------------------------------------------------------------
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
				std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数

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
		}
		else
		{
			if (BaseMove::GetDistance(p_adjustmentMachine->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				p_adjustmentMachine->CatchDropItem();
				p_dropItem[i]->SetDeath(true);			// 生きさせない

				/// SEの再生をランダムにする-----------------------------------------------------------------------------
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
				std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数

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

			p_dropItem[i]->StolenChara(p_adjustmentMachine->GetArea());
		}
	}
}


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


	// ポインタNULL初期化
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


	// 階段の初期化
	stairsHandle = v_file[EFILE::stairs];
	stairsTexture0 = v_file[EFILE::stairTex0];


	// ステージの初期化
	p_stage		 = new Stage(v_file[EFILE::drawStage]);


	// キャラクターの初期化
	p_character	 = new CharacterSword(v_file[EFILE::characterAttack], v_file[EFILE::stage], v_file[EFILE::stairsColl], v_file[EFILE::paneru], v_file[EFILE::stairsRoadColl]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);

	// 操作説明画像の初期化
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


	// カメラの初期化
	p_camera	 = new Camera(p_character->GetArea(), v_file[EFILE::stage]);


	// 街灯の初期化
	streetLightHandle = v_file[EFILE::streetLight];
	streetLightTexture0 = v_file[EFILE::streetLightTex0];
	streetLightTexture1 = v_file[EFILE::streetLightTex1];


	// 階段と床に関する
	stairsRoadHandle = v_file[EFILE::stairsRoad];
	stairsRoadTexture0 = v_file[EFILE::stairsRoadTex0];
	stairsRoadTexture1 = v_file[EFILE::stairsRoadTex1];


	// パネルの初期化
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneru], VGet(500.0f * i, 300.0f * i, 100.0f * i));
	}


	// 敵の初期化
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z座標用乱数
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		// 玉のX座標設定
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 200.0f && tempX >= 0.0f)
		{
			tempX += 200.0f;
		}
		if (tempX >= -200.0f && tempX <= 0.0f)
		{
			tempX -= 200.0f;
		}

		// 玉のY座標設定
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


	// ドロップアイテムの初期化
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove2(v_file[EFILE::block], p_enemy[i / 5]->GetArea(), v_file[EFILE::blockTex0]);
	}


	// 精密機械の初期化
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminal], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);


	// 精密機械に関する
	changeAdjustmentScene = false;
	adjustmentDescriptionDraw = v_file[EFILE::terminalDescription];
	adjustmentSceneFeed = 0;
	adjustmentFeedNow = false;
	adjustmentSelectObject = false;
	adjustmentSelectObjectNumber = AdjustmentObject::Stairs;
	adjustmentArrangementArea = VGet(0, 0, 0);
	adjustmentArrangementDire = 0.0f;
	//adjustmentDrawScreen = MakeGraph(BASICPARAM::winWidth, BASICPARAM::winHeight);

	
	// 精密機械での2D
	for (int i = 0, n = EFILE::stairsRoad2D + 1 - EFILE::block2D; i != n; ++i)
	{
		adjustment2DDraw[i] = v_file[i + EFILE::block2D];
	}


	// ドロップアイテムを手に入れた数
	catchDropItemNum = 0;


	// スカイボックス読み込み
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBox], v_file[EFILE::skyBoxTex0]);


	// パネルのあたり判定
	for (int i = 0; i != 10; ++i)
	{
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowNoMoveSetUpAfter();


	// サウンドのロード
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

	// エフェクト読み込み
	effectAttack = LoadEffekseerEffect("media\\こっち\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
}


MainMove2::~MainMove2()
{
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);
	//GRAPHIC_RELEASE(adjustmentDrawScreen);

	/// 精密機械に関する
	GRAPHIC_RELEASE(adjustmentDescriptionDraw);
	for (int i = 0; i != 6; ++i)
	{
		GRAPHIC_RELEASE(adjustment2DDraw[i]);
	}

	/// パネルに関する
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}

	/// 街灯に関する
	MODEL_RELEASE(streetLightHandle);
	GRAPHIC_RELEASE(streetLightTexture0);
	GRAPHIC_RELEASE(streetLightTexture1);
	for (int i = 0, n = static_cast<int>(vp_stageStreetLight.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStreetLight[i]);
	}
	vp_stageStreetLight.clear();
	vp_stageStreetLight.shrink_to_fit();

	/// 階段に関する
	MODEL_RELEASE(stairsHandle);
	GRAPHIC_RELEASE(stairsTexture0);
	for (int i = 0, n = static_cast<int>(vp_stageStairs.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStairs[i]);
	}
	vp_stageStairs.clear();
	vp_stageStairs.shrink_to_fit();

	/// 階段と床に関する
	MODEL_RELEASE(stairsRoadHandle);
	GRAPHIC_RELEASE(stairsRoadTexture0);
	GRAPHIC_RELEASE(stairsRoadTexture1);
	for (int i = 0, n = static_cast<int>(vp_stageStairsRoad.size()); i != n; ++i)
	{
		POINTER_RELEASE(vp_stageStairsRoad[i]);
	}
	vp_stageStairsRoad.clear();
	vp_stageStairsRoad.shrink_to_fit();

	/// カメラに関する
	POINTER_RELEASE(p_camera);

	/// ドロップアイテムに関する
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}

	/// 敵に関する
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		POINTER_RELEASE(p_enemy[i]);
	}

	/// 説明画像に関する
	for (int i = 0; i != 4; ++i)
	{
		GRAPHIC_RELEASE(operationUIDraw[i]);
	}

	/// キャラクターに関する
	POINTER_RELEASE(p_character);

	/// ステージに関する
	POINTER_RELEASE(p_stage);
}


// 描画
void MainMove2::Draw()
{
//	if (!changeAdjustmentScene)
//	{
		BaseMove::SkyBoxDraw();

		ShadowDraw();

		if (!p_adjustmentMachine->GetCanTouch())
		{
			p_adjustmentMachine->Draw();
			p_adjustmentMachine->ModelDraw();
		}

		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;
			p_dropItem[i]->ModelDraw();
		}

		// キャラクター
		p_character->Draw();


		if (p_adjustmentMachine->GetCanTouch())
		{
			if (BaseMove::GetDistance(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
			{
				DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescriptionDraw, false);
			}
		}

		for (int i = 0; i != 4; ++i)
		{
			// 最大光度から減っていたら減らすようにする
			if (operationUIFeed[i] < nextOperationUIFeed[i]) operationUIFeed[i]++;
			if (operationUIFeed[i] > nextOperationUIFeed[i]) operationUIFeed[i]--;

			/// ブレンドする----------------------------------------------
			// 説明画像の光度が0以上だったら
			if (operationUIFeed[i] > 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, operationUIFeed[i]);

				// 左スティック説明画像
				if (i % 2 == 0)
				{
					DrawGraph(100, 100, operationUIDraw[i], true);
				}
				else
				{
					// 右スティック説明画像
					DrawGraph(1200, 100, operationUIDraw[i], true);
				}

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
		}

		if (mostNearEnemyDistance <= 1000 && !p_enemy[lockONNowEnemyID]->GetEraseExistence())
		{
			if (mostNearEnemyDistance < 250)
			{
				DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
					, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
				DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
					, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
			}
			else
			{
				DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
					, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
				DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
					, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
			}
		}

		DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);

	//}
	////else
	//{
		AdjustmentDraw();
	//}

#ifdef _DEBUG
		// 敵
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			p_enemy[i]->Draw();
		}
#endif // _DEBUG
}


// メインプロセス
void MainMove2::Process()
{
	if (!changeAdjustmentScene)
	{
		// キャラクターのプロセスを呼ぶ
		p_character->Process(p_camera->GetAngle());		

		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] != 0
			&& p_character->GetArea().y > 50.0f)
		{
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] = 0;
		}
		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] != 0
			&& p_character->GetMoveFastWaitCount())
		{
			opeFastOptionEnd = true;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 0;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 0;
		}
		
		if (operationUIFeed[static_cast<int>(EOPERATION_UI::attack)] == 0
			&& operationUIFeed[static_cast<int>(EOPERATION_UI::jump)] == 0
			&& !opeFastOptionEnd)
		{
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 255;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 255;
		}

		// カメラのプロセスを呼ぶ
		p_camera->Process(p_character->GetArea());		


		// 敵のプロセス
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			if (p_enemy[i]->GetEraseExistence())
			{
				if (i == lockONNowEnemyID)
				{
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}
				if (!p_dropItem[(i * 5)]->GetDeath() && !p_dropItem[(i * 5)]->GetAlive()) p_dropItem[(i * 5)]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 1]->GetDeath() && !p_dropItem[(i * 5) + 1]->GetAlive()) p_dropItem[(i * 5) + 1]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 2]->GetDeath() && !p_dropItem[(i * 5) + 2]->GetAlive()) p_dropItem[(i * 5) + 2]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 3]->GetDeath() && !p_dropItem[(i * 5) + 3]->GetAlive()) p_dropItem[(i * 5) + 3]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 4]->GetDeath() && !p_dropItem[(i * 5) + 4]->GetAlive()) p_dropItem[(i * 5) + 4]->SetAlive(true);
				continue;
			}
			p_enemy[i]->Process();
			if (BaseMove::GetDistance(p_character->GetArea(), p_enemy[lockONNowEnemyID]->GetArea())
				>= BaseMove::GetDistance(p_character->GetArea(), p_enemy[i]->GetArea()))
			{
				mostNearEnemyDistance = BaseMove::GetDistance(p_character->GetArea(), p_enemy[i]->GetArea());
				mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemy[i]->GetArea());
				lockONNowEnemyID = i;
				if (mostNearEnemyDistance < 250)
				{
					p_character->SetMostNearEnemyArea(p_enemy[i]->GetArea());
				}
				else
				{
					p_character->SetMostNearEnemyArea();
				}
			}
		}

		// ドロップアイテム
		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			if (p_dropItem[i]->GetDeath()) continue;
			p_dropItem[i]->Process();
		}


		BaseMove::ShadowArea(p_character->GetArea());

		AttackProcess();

		BaseMove::SkyBoxProcess(p_character->GetArea());


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


		if (p_character->GetArea().y >= 3550.0f)
		{
			BASICPARAM::endFeedNow = true;
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			BaseMove::SetScene(ESceneNumber::THIRDLOAD);
		}
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
		BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
		BaseMove::SetScene(ESceneNumber::THIRDLOAD);
	}
#endif
}


void MainMove2::CameraProcess()
{
	//if (!changeAdjustmentScene)
	//{
		p_camera->SetUp();		// カメラのプロセスを呼ぶ
	//}
}


void MainMove2::OptionActorModel()
{
	p_character->OptionActorDraw();
}


void MainMove2::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}

void MainMove2::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
