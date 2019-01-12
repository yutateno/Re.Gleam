#include "MainMove2.hpp"


// 精密機械のプロセス
void MainMove2::AdjustmentProcess()
{
	// Aボタンを押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// 配置するオブジェクトを選択していないとき
		if (!adjustmentSelectObject)
		{
			// 階段にカーソルがのっているとき
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				&& catchDropItemNum >= createStairsNeedNum)
			{
				catchDropItemNum -= createStairsNeedNum;
				adjustmentSelectObject = true;
			}
			// 階段と床にカーソルがのっているとき
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				&& catchDropItemNum >= createStreetLightNeedNum)
			{
				catchDropItemNum -= createStreetLightNeedNum;
				adjustmentSelectObject = true;
			}
			// 街灯にカーソルがのっているとき
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight
				&& catchDropItemNum >= 5)
			{
				catchDropItemNum -= 5;
				adjustmentSelectObject = true;
			}
		} /// if (!adjustmentSelectObject)
		// 配置するオブジェクトを選択してあるとき
		else
		{
			// キャラクターと配置予定の階段が被っていたら
			if (adjustmentSelectObjectNumber == AdjustmentObject::Stairs
				&& adjustmentArrangementArea.x + 120.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 120.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 250.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 250.0f < p_character->GetArea().z)
			{
				return;
			}
			// キャラクターと配置予定の階段と床が被っていたら
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad
				&& adjustmentArrangementArea.x + 500.0f > p_character->GetArea().x
				&& adjustmentArrangementArea.x - 500.0f < p_character->GetArea().x
				&& adjustmentArrangementArea.z + 670.0f > p_character->GetArea().z
				&& adjustmentArrangementArea.z - 670.0f < p_character->GetArea().z)
			{
				return;
			}


			// 配置する
			adjustmentSelectObject = false;
			AdjuctmentCreate(adjustmentArrangementArea, adjustmentSelectObjectNumber, adjustmentArrangementDire);
		} /// else (!if (!adjustmentSelectObject))
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// Bボタンが押されたら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// オブジェクトを選択して配置するシーンじゃなかったら
		if (!adjustmentSelectObject)
		{
			// 精密機械のシーンから戻る
			adjustmentFeedNow = true;
			adjustmentStartFeed = false;
		}
	}


	// オブジェクトを選択し終えて配置するシーンのとき
	if (adjustmentSelectObject)
	{
		// 画面外に出ない位置で左スティックを右に押されたら
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0
			&& adjustmentArrangementArea.x > -4500.0f)
		{
			adjustmentArrangementArea.x -= 10.0f;
		}
		// 画面外に出ない位置で左スティックを左に
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0
			&& adjustmentArrangementArea.x < 4500.0f)
		{
			adjustmentArrangementArea.x += 10.0f;
		}
		// 画面外に出ない位置で左スティックを上に
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0
			&& adjustmentArrangementArea.z > -4500.0f)
		{
			adjustmentArrangementArea.z -= 10.0f;
		}
		// 画面外に出ない位置で左スティックを下に
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0
			&& adjustmentArrangementArea.z < 4500.0f)
		{
			adjustmentArrangementArea.z += 10.0f;
		}
		// 右スティックを右に
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) > 0)
		{
			adjustmentArrangementDire += DX_PI_F / 60;
		}
		// 右スティックを左に
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_RIGHT_X) < 0)
		{
			adjustmentArrangementDire -= DX_PI_F / 60;
		}
	} /// if (adjustmentSelectObject)
	// オブジェクトを選択するシーンのとき
	else
	{
		/// スティックの一回押し倒しで更新するよう調整----------------------------------------------------------------------
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

		
		// カーソルを右に移動
		if (adjustmentControllStick[0] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp > 0 ? --temp : temp);
		}
		// カーソルを左に移動
		if (adjustmentControllStick[1] == 1)
		{
			int temp = static_cast<int>(adjustmentSelectObjectNumber);
			adjustmentSelectObjectNumber = static_cast<AdjustmentObject>(temp < 2 ? ++temp : temp);
		}


		// RBボタンが押されたら
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
			&& !BASICPARAM::paneruDrawFlag)
		{
			// 次のシーンへ行くためのパネルを描画するように処理
			BASICPARAM::paneruDrawFlag = true;
		}
	} /// else (!if (adjustmentSelectObject))
} /// void MainMove2::AdjustmentProcess()


// 精密機械の描画
void MainMove2::AdjustmentDraw()
{
	// フェードシーンの描画が切り替わるシーン以上の数値へ行ったら
	if (adjustmentSceneFeed >= 50)
	{
		// 背景
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(247, 247, 247), true);


		/// 配置されているオブジェクトの2D-----------------------------------------------------------------------------------------------
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
		/// -------------------------------------------------------------------------------------------------------------------------------


		// 配置したオブジェクトを配置するとき
		if (adjustmentSelectObject)
		{
			// ボタン説明
			DrawFormatString(30, 60, GetColor(0, 0, 0), "Aボタンで配置");

			/// 半透明でオブジェクトを表示-------------------------------------------------------------
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
			// 階段の表示
			if (adjustmentSelectObjectNumber==AdjustmentObject::Stairs)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.22, adjustmentArrangementDire, adjustment2DDraw[3], true);
			}
			// 階段と床の表示
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StairsRoad)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.75, adjustmentArrangementDire, adjustment2DDraw[5], true);
			}
			// 街灯の表示
			else if (adjustmentSelectObjectNumber == AdjustmentObject::StreetLight)
			{
				DrawRotaGraph(static_cast<int>((4500 - adjustmentArrangementArea.x) / 9000 * 1920)
					, static_cast<int>((4500 + adjustmentArrangementArea.z) / 9000 * 1080)
					, 0.15, adjustmentArrangementDire, adjustment2DDraw[2], true);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			/// -------------------------------------------------------------------------------------------
		} /// if (adjustmentSelectObject)
		// 配置するオブジェクトを選択していないとき
		else
		{
			// ボックス表示
			DrawBox(0, 0, 980, 540, GetColor(255, 255, 255), true);
			DrawBox(0, 0, 980, 540, GetColor(0, 0, 0), false);

			// 操作説明
			DrawFormatString(10, 10, GetColor(0, 0, 0), "Aボタンで決定");

			// 階段表示
			if (catchDropItemNum < createStairsNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(120, 120, 0.22, 0.0, adjustment2DDraw[3], true);
			DrawFormatString(50, 170, GetColor(0, 0, 0), "階段: %dブロック", createStairsNeedNum);
			if (catchDropItemNum < createStairsNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// 階段と床表示
			if (catchDropItemNum < createStreetLightNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(320, 130, 0.75, 0.0, adjustment2DDraw[5], true);
			DrawFormatString(240, 250, GetColor(0, 0, 0), "階段＆床: %dブロック", createStreetLightNeedNum);
			if (catchDropItemNum < createStreetLightNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// 街灯表示
			if (catchDropItemNum < createStairsRoadNeedNum) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
			DrawRotaGraph(500, 120, 0.15, 0.0, adjustment2DDraw[2], true);
			DrawFormatString(430, 170, GetColor(0, 0, 0), "街灯: %dブロック", createStairsRoadNeedNum);
			if (catchDropItemNum < createStairsRoadNeedNum) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			// パネル説明
			DrawFormatString(20, 350, GetColor(0, 0, 0), "RBボタンで次のステージへの道");

			// 階段でのカーソル表示
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
			// 階段と床のカーソル表示
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
			// 街灯のカーソル表示
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

			// 戻る説明
			DrawFormatString(30, 500, GetColor(0, 0, 0), "Bボタンで戻る");

			// 現在の取得ドロップ数表示
			DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);
		} /// else (!if (adjustmentSelectObject))
	} /// if (adjustmentSceneFeed >= 50)


	/// オペレーターのフェード表現に関する-----------------------------------------------------------
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


// 精密機械でオブジェクトの生成プロセス
void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction)
{
	// どのオブジェクトが選択されたか
	switch (obujectID)
	{
	// 階段が選択されていたら
	case AdjustmentObject::Stairs:
		vp_stageStairs.push_back(new StageStairs(stairsHandle, area, stairsTexture0, DX_PI_F + direction));		// 生成
		p_character->SetStairsArea(vp_stageStairs[BASICPARAM::stairsNum]->GetArea(), BASICPARAM::stairsNum, DX_PI_F + direction);	// キャラクターに対して当たり判定生成
		BASICPARAM::stairsNum++;									// 全体で確認できるように階段の個数を追加
		BASICPARAM::v_stairsArea.push_back(area);					// 全体で確認できるように場所を追加
		BASICPARAM::v_stairsAngle.push_back(DX_PI_F + direction);	// 全体で確認できるように角度を追加
		break;


	// 街灯が選択されていたら
	case AdjustmentObject::StreetLight:
		vp_stageStreetLight.push_back(new StageStreetLight(streetLightHandle, area, streetLightTexture0, streetLightTexture1, direction));	// 生成
		BASICPARAM::streetLightNum++;								// 全体で確認できるように街灯の個数を追加
		BASICPARAM::v_streetLightArea.push_back(area);				// 全体で確認できるように場所を追加
		BASICPARAM::v_streetLightAngle.push_back(direction);		// 全体で確認できるように角度を追加
		break;


	// 階段と床が選択されていたら
	case AdjustmentObject::StairsRoad:
		vp_stageStairsRoad.push_back(new StageStairsRoad(stairsRoadHandle, area, stairsRoadTexture0, stairsRoadTexture1, DX_PI_F + direction));		// 生成
		p_character->SetStairsRoadArea(vp_stageStairsRoad[BASICPARAM::stairsRoadNum]->GetArea(), BASICPARAM::stairsRoadNum, DX_PI_F + direction);	// キャラクターに対してあたり判定生成
		BASICPARAM::stairsRoadNum++;									// 全体で確認できるように階段と床の個数を追加
		BASICPARAM::v_stairsRoadArea.push_back(area);					// 全体で確認できるように場所を追加
		BASICPARAM::v_stairsRoadAngle.push_back(DX_PI_F + direction);	// 全体で確認できるように角度を追加
		break;

	default:
		break;
	}
} /// void MainMove2::AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction)


// シャドウマップでの影を描画
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
	BaseMove::ShadowSetUpAfter();


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
} /// void MainMove2::ShadowDraw()


// 攻撃とあたり判定のプロセス
void MainMove2::AttackProcess()
{
	/// 敵に関する--------------------------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		// 死んでいたら次へ
		if (p_enemy[i]->GetDeathFlag()) continue;

		// 当たっていたらプレイヤーを押し出す
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_enemy[i]->GetArea(), VAdd(p_enemy[i]->GetArea(), VGet(0.0f, p_enemy[i]->GetHeight(), 0.0f)), p_enemy[i]->GetWidth()))
		{
			p_character->HitCircleReturn(p_enemy[i]->GetArea()
				, p_enemy[i]->GetWidth() >= p_character->GetWidth() ? p_enemy[i]->GetWidth() : p_character->GetWidth());
		}


		// プレイヤーが攻撃中だったら
		if (p_character->GetAttackNow())
		{
			// 敵に剣が触れたかどうか調べる
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
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemyNum; i != n; ++i)


	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------
	if (p_adjustmentMachine->GetCanTouch())
	{
		// 当たっていたらプレイヤーを押し出す
		if (HitCheck_Capsule_Capsule(
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth(),
			p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
		}

		// 距離が近かくで触れるボタン(Bボタン)を押したら
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
			&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
			&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			// 精密機械のシーンへ移行
			//GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, adjustmentDrawScreen);
			adjustmentFeedNow = true;
			adjustmentStartFeed = true;
			changeAdjustmentScene = true;
		}

		
		// プレイヤーとの距離で精密機械のパネルのテクスチャを変える
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
		{
			p_adjustmentMachine->ChangeDisplayTexture(true);
		}
		else
		{
			p_adjustmentMachine->ChangeDisplayTexture(false);
		}
	} /// if (p_adjustmentMachine->GetCanTouch())
	

	/// ドロップに関する--------------------------------------------------------------------------------------
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		// もう拾われているかどうかで次へ
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;


		// 精密機械がドロップ数を十分手に入れていたら
		if (p_adjustmentMachine->GetFullDropItem())
		{
			// プレイヤーが近かったら
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
			{
				// プレイヤーに近づく
				p_dropItem[i]->ChaseActor(p_character->GetArea());
			}


			// プレイヤーとの距離が取られる距離だったら
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				catchDropItemNum++;
				p_dropItem[i]->SetDeath(true);			// 生きさせない

				/// SEの再生をランダムにする-----------------------------------------------------------------------------
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
				std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数

				// ドロップアイテムを取得するSEを流す
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
		// 精密機械がドロップ数を十分に手に入れていなかったら
		else
		{
			// 精密機械との距離が近かったら
			if (BaseMove::GetDistance<int>(p_adjustmentMachine->GetArea(), p_dropItem[i]->GetArea()) <= 75)
			{
				p_adjustmentMachine->CatchDropItem();
				p_dropItem[i]->SetDeath(true);			// 生きさせない

				/// SEの再生をランダムにする-----------------------------------------------------------------------------
				std::random_device rnd;     // 非決定的な乱数生成器を生成
				std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
				std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数

				// ドロップ取得のSEを流す
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

			// 精密機械へ向かう
			p_dropItem[i]->ChaseActor(p_adjustmentMachine->GetArea());
		} /// else (!if (p_adjustmentMachine->GetFullDropItem()))
	} /// for (int i = 0, n = enemyNum * 5; i != n; ++i)
} /// void MainMove2::AttackProcess()


// コンストラクタ
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
	p_camera	 = new Camera(p_character->GetArea());


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
	BaseMove::ShadowSetUpAfter();


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
} /// MainMove2::MainMove2(const std::vector<int> v_file)


// デストラクタ
MainMove2::~MainMove2()
{
	/// エフェクトに関する
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
} /// MainMove2::~MainMove2()


// 描画
void MainMove2::Draw()
{
	// スカイボックスの描画
	BaseMove::SkyBoxDraw();


	// 影の描画
	ShadowDraw();


	// ドロップ数が集まる前の精密機械の描画
	if (!p_adjustmentMachine->GetCanTouch())
	{
		p_adjustmentMachine->Draw();
		p_adjustmentMachine->ModelDraw();
	}


	// ドロップアイテムの描画
	for (int i = 0, n = enemyNum * 5; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;
		p_dropItem[i]->ModelDraw();
	}


	// キャラクター
	p_character->Draw();


	// 精密機械へのドロップ数が十分だったとき
	if (p_adjustmentMachine->GetCanTouch())
	{
		// 精密機械の頭上に起動操作の説明描画
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
		{
			DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescriptionDraw, false);
		}
	}


	// プレイヤーの操作説明描画
	for (int i = 0; i != 4; ++i)
	{
		// ブレンド値を変移させる
		if (operationUIFeed[i] < nextOperationUIFeed[i]) operationUIFeed[i]++;
		if (operationUIFeed[i] > nextOperationUIFeed[i]) operationUIFeed[i]--;


		/// 描画画像をブレンドする----------------------------------------------
		// 説明画像のブレンド値が0以上だったら
		if (operationUIFeed[i] > 0)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, operationUIFeed[i]);

			// 左の画像
			if (i % 2 == 0)
			{
				DrawGraph(100, 100, operationUIDraw[i], true);
			}
			// 右の画像
			else
			{

				DrawGraph(1200, 100, operationUIDraw[i], true);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}


	// プレイヤーから近い敵に対してロックオンのような描画をスクリーン座標にさせる
	if (mostNearEnemyDistance <= 1000 && !p_enemy[lockONNowEnemyID]->GetEraseExistence())
	{
		// 距離が攻撃で当たるくらいの距離だったら
		if (mostNearEnemyDistance < 250)
		{
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
		}
		// 攻撃は当たらないが近かったら
		else
		{
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
			DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f)
				, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemy[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
		}
	}


	// 取得したドロップ数の表示
	DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);


	// 精密機械のシーンの描画
	AdjustmentDraw();

#ifdef _DEBUG
	// 敵
	for (int i = 0, n = enemyNum; i != n; ++i)
	{
		p_enemy[i]->Draw();
	}
#endif // _DEBUG
} /// void MainMove2::Draw()


// メインプロセス
void MainMove2::Process()
{
	// 精密機械のシーンじゃなかったら
	if (!changeAdjustmentScene)
	{
		// キャラクターのプロセスを呼ぶ
		p_character->Process(p_camera->GetAngle());		


		// 初めて攻撃をしたら
		if (p_character->GetAttackNow() && nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] != 0)
		{
			// 攻撃の操作説明UIを消す
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::attack)] = 0;
		}


		// 初めてジャンプをしたら
		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] != 0
			&& p_character->GetArea().y > 50.0f)
		{
			// ジャンプの操作説明UIを消す
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::jump)] = 0;
		}


		// 初めて瞬間移動をしたら
		if (nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] != 0
			&& p_character->GetMoveFastWaitCount())
		{
			// 瞬間移動とオプション画面への操作説明UIを消す
			opeFastOptionEnd = true;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 0;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 0;
		}
		

		// 攻撃とジャンプの操作説明UIを消したら
		if (operationUIFeed[static_cast<int>(EOPERATION_UI::attack)] == 0
			&& operationUIFeed[static_cast<int>(EOPERATION_UI::jump)] == 0
			&& !opeFastOptionEnd)
		{
			// 瞬間移動とオプション画面への操作説明UIを表示させる
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::fastSpeed)] = 255;
			nextOperationUIFeed[static_cast<int>(EOPERATION_UI::option)] = 255;
		}


		// カメラのプロセスを呼ぶ
		p_camera->Process(p_character->GetArea());		


		// 敵のプロセス
		for (int i = 0, n = enemyNum; i != n; ++i)
		{
			// 敵が消滅したら
			if (p_enemy[i]->GetEraseExistence())
			{
				// ロックオン対象だったら
				if (i == lockONNowEnemyID)
				{
					// 除外させる
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// ドロップアイテムを描画させる
				if (!p_dropItem[(i * 5)]->GetDeath() && !p_dropItem[(i * 5)]->GetAlive()) p_dropItem[(i * 5)]->SetAlive(true);
				else continue;
				if (!p_dropItem[(i * 5) + 1]->GetDeath() && !p_dropItem[(i * 5) + 1]->GetAlive()) p_dropItem[(i * 5) + 1]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 2]->GetDeath() && !p_dropItem[(i * 5) + 2]->GetAlive()) p_dropItem[(i * 5) + 2]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 3]->GetDeath() && !p_dropItem[(i * 5) + 3]->GetAlive()) p_dropItem[(i * 5) + 3]->SetAlive(true);
				if (!p_dropItem[(i * 5) + 4]->GetDeath() && !p_dropItem[(i * 5) + 4]->GetAlive()) p_dropItem[(i * 5) + 4]->SetAlive(true);
				continue;
			}


			// 敵のプロセスを呼ぶ
			p_enemy[i]->Process();


			// 敵とプレイヤーの距離がロックオン対象より近かったら
			if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[lockONNowEnemyID]->GetArea())
				>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[i]->GetArea()))
			{
				// ロックオン対象を更新する
				mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemy[i]->GetArea());
				mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemy[i]->GetArea());
				lockONNowEnemyID = i;


				// ロックオンの距離より近かったら
				if (mostNearEnemyDistance < 250)
				{
					p_character->SetMostNearEnemyArea(p_enemy[i]->GetArea());
				}
				// ロックオンできない距離だったら除外する
				else
				{
					p_character->SetMostNearEnemyArea();
				}
			}
		} /// for (int i = 0, n = enemyNum; i != n; ++i)


		// ドロップアイテム
		for (int i = 0, n = enemyNum * 5; i != n; ++i)
		{
			if (p_dropItem[i]->GetDeath()) continue;
			p_dropItem[i]->Process();
		}


		// シャドウマップのプレイヤーの位置を更新
		BaseMove::ShadowArea(p_character->GetArea());


		// 攻撃プロセスを呼ぶ
		AttackProcess();


		// スカイボックスのプレイヤーの位置を更新
		BaseMove::SkyBoxProcess(p_character->GetArea());


		/// プレイヤーの座標にて次のシーンのBGMを流す---------------------------------------------------------------------
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


		// プレイヤーの位置にて次のシーンへ移動する
		if (p_character->GetArea().y >= 3550.0f)
		{
			BASICPARAM::endFeedNow = true;
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			BaseMove::SetScene(ESceneNumber::THIRDLOAD);
		}
	} /// if (!changeAdjustmentScene)
	else
	{
		// 精密機械から通常へのフェードシーンが始まったら
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
		// 通常から精密機械へのフェードシーンが始めまったら
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

		
		// 精密機械へのフェードシーンが終わったらプロセスを呼ぶ
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


// カメラの再セットアップ
void MainMove2::CameraProcess()
{
	p_camera->SetUp();
}


// オプション画面モデル用の表示
void MainMove2::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// オプション画面モデルの準備
void MainMove2::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// オプション画面モデルの解消
void MainMove2::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
