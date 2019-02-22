#include "MainMove6.hpp"



/// --------------------------------------------------------------------------------------------------
void MainMove6::ShadowDraw()
{
	/// セットアップ
	BaseMove::ShadowCharaSetUpBefore();
	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	// キャラクター
	p_character->ModelDraw();


	/// キャラクター以外再セットアップ
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// 階段
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// 街灯
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// 階段と床
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->ModelDraw();
		}
	}
	BaseMove::ShadowSetUpAfter();


	/// 描画
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// ステージ
	p_stage->Draw();
	// 階段
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
	// 街灯
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
	// 階段と床
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
	// 一般人
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
	// キャラクター
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// キャラクター
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
} /// void MainMove6::ShadowDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove6::AttackProcess()
{
	/// プレイヤーを押し出す処理------------------------------------------------------------
	// ボスと当たっていたら
	if (HitCheck_Capsule_Capsule(
		p_enemyBossAfter->GetArea(), VAdd(p_enemyBossAfter->GetArea(), VGet(0.0f, p_enemyBossAfter->GetHeight(), 0.0f)), p_enemyBossAfter->GetWidth(),
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
	{

		// 自分を押し出す
		p_character->HitCircleReturn(p_enemyBossAfter->GetArea()
			, p_character->GetWidth() >= p_enemyBossAfter->GetWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetWidth());
	}



	/// プレイヤーの攻撃---------------------------------------------------------------------
	// プレイヤーの攻撃が終わったら
	if (p_character->GetAttackMotionEnd()) enemyHitDamage = false;


	// ダメージを受けていなくてプレイヤーが攻撃中だったら
	if (p_character->GetAttackNow() && !enemyHitDamage && p_character->GetArea().y >= 2100)
	{
		p_enemyBossAfter->HitLineReturn(p_character->GetAttackFirstFrameArea()
			, p_character->GetAttackEndFrameArea());
	}


	// 攻撃でダメージを受けたら
	if (p_enemyBossAfter->GetDamageFlag())
	{
		// ダメージを受けている
		enemyHitDamage = true;
		enemyDamageCount++;
		// バイブレーションさせる
		DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 15000, 15000);
	}


	/// 敵の攻撃の処理-----------------------------------------------------------------------
	// 何の攻撃をしたか
	e_attackPattern = p_enemyBossAfter->GetAttackPattern();


	// 敵が攻撃を始めたとき
	if (p_enemyBossAfter->GetAttackStartNow())
	{
		// 氷の柱を使う攻撃だったら
		if (e_attackPattern == EAttackPattern::icePillar)
		{
			// 微妙に散らばせる
			std::mt19937 mt(rnd());
			std::uniform_int_distribution<> paneruID(0, 65);        // パネルのID
			for (int i = 0; i != icePillarNum; ++i)
			{
				p_magicIcePillar[i]->Active(p_stagePaneru[paneruID(mt)]->GetArea());
			}
		}
		// 箱を使う攻撃だったら
		else if (e_attackPattern == EAttackPattern::magicBlock)
		{
			// 0番目のものが使われていなかったら
			if (!p_chaseBlock[0]->GetActive())
			{
				p_chaseBlock[0]->Active(p_character->GetArea());
			}
			// 0番目が稼働中だったら
			else
			{
				// 1番目のものが使われていなかったら
				if (!p_chaseBlock[1]->GetActive())
				{
					p_chaseBlock[1]->Active(p_character->GetArea());
				}
			}
		}
	} /// if (p_enemyBossAfter->GetAttackStartNow())
	/// 敵の攻撃の処理-----------------------------------------------------------------------


	/// 敵の攻撃によりダメージを受けているかどうか-------------------------------------------------------------------------------------------------------
	// 氷の柱を使う攻撃だったら
	if (e_attackPattern == EAttackPattern::icePillar)
	{
		for (int i = 0; i != icePillarNum; ++i)
		{
			// アクティブだったら
			if (p_magicIcePillar[i]->GetActive())
			{
				// 重なっていたら
				if (p_magicIcePillar[i]->GetArea().x - 100 < p_character->GetArea().x && p_magicIcePillar[i]->GetArea().x + 100 > p_character->GetArea().x
					&& p_magicIcePillar[i]->GetArea().y - 50 < p_character->GetArea().y && p_magicIcePillar[i]->GetArea().y + 250 > p_character->GetArea().y
					&& p_magicIcePillar[i]->GetArea().z - 100 < p_character->GetArea().z && p_magicIcePillar[i]->GetArea().z + 100 > p_character->GetArea().z)
				{
					// ダメージを与える
					p_character->SetDamage();
					damageCount++;
				}
			}
		}
	}
	// 箱を使う攻撃だったら
	else if (e_attackPattern == EAttackPattern::magicBlock)
	{
		// ID0番目がアクティブだったら
		if (p_chaseBlock[0]->GetActive())
		{
			// ID0番目の追尾箱と当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_chaseBlock[0]->GetArea(), VAdd(p_chaseBlock[0]->GetArea(), VGet(0.0f, p_chaseBlock[0]->GetHeight(), 0.0f)), p_chaseBlock[0]->GetWidth(),
				p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
			{

				// 自分を押し出す
				p_character->HitCircleReturn(p_chaseBlock[0]->GetArea()
					, p_character->GetWidth() >= p_chaseBlock[0]->GetWidth() ? p_character->GetWidth() : p_chaseBlock[0]->GetWidth());


				// ダメージを与える
				p_character->SetDamage();
				damageCount++;
			}
		}
		// ID1番目がアクティブだったら
		else if (p_chaseBlock[1]->GetActive())
		{
			// ID1番目の追尾箱と当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_chaseBlock[1]->GetArea(), VAdd(p_chaseBlock[1]->GetArea(), VGet(0.0f, p_chaseBlock[1]->GetHeight(), 0.0f)), p_chaseBlock[1]->GetWidth(),
				p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
			{

				// 自分を押し出す
				p_character->HitCircleReturn(p_chaseBlock[1]->GetArea()
					, p_character->GetWidth() >= p_chaseBlock[1]->GetWidth() ? p_character->GetWidth() : p_chaseBlock[1]->GetWidth());


				// ダメージを与える
				p_character->SetDamage();
				damageCount++;
			}
		}
	}
	// 手を振りかざす攻撃だったら
	else if (e_attackPattern == EAttackPattern::hand)
	{
		// 攻撃中だったら
		if (p_enemyBossAfter->GetAttackNow())
		{
			int temp = 0;		// 押し出し回数を仮置き


			// プレイヤーを押し出す
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameOneArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameOneWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameOneWidth());
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameTwoArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameTwoWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameTwoWidth());
			temp += p_character->HitCircleReturn(p_enemyBossAfter->GetAttackFlameThreeArea()
				, p_character->GetWidth() >= p_enemyBossAfter->GetAttackFlameThreeWidth() ? p_character->GetWidth() : p_enemyBossAfter->GetAttackFlameThreeWidth());


			// ぶつかっていたら
			if (temp != 0)
			{
				// ダメージを与える
				p_character->SetDamage();
				damageCount++;
			}
		}
	}
	/// 敵の攻撃によりダメージを受けているかどうか-------------------------------------------------------------------------------------------------------
} /// void MainMove6::AttackProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove6::FirstDraw()
{	
	// スカイボックスを描画
	BaseMove::SkyBoxDraw();


	// シャドウマップを描画
	ShadowDraw();


	// 敵ラスボスのあれ
	p_enemyBossBefore->ModelDraw();


	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			vp_ordinaryPerson[i]->Draw();
		}
	}


	// キャラクターを描画
	p_character->Draw();



	// ボスと距離が近かったらUIを表示する
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) < 250)
	{
		DrawGraph(960 - 200, 540 - 69 - 50, approachBossUIDraw[0], false);
		DrawGraph(960 - 500, 540 - 69 + 250, approachBossUIDraw[1], false);
		DrawGraph(960 + 100, 540 - 69 + 250, approachBossUIDraw[2], false);


		// 近づくにカーソルがあったとき
		if (approachUISelect)
		{
			DrawBox(960 - 500 + 5, 540 - 69 + 250 + 5, 960 - 500 + 400 - 5, 540 - 69 + 250 + 69 - 5, GetColor(50, 50, 200), false);
			DrawBox(960 - 500 + 4, 540 - 69 + 250 + 4, 960 - 500 + 400 - 4, 540 - 69 + 250 + 69 - 4, GetColor(50, 50, 200), false);
			DrawBox(960 - 500 + 3, 540 - 69 + 250 + 3, 960 - 500 + 400 - 3, 540 - 69 + 250 + 69 - 3, GetColor(50, 50, 200), false);
		}
		// 離れるにカーソルがあったとき
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
	// ボスと距離があったとき
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) >= 250)
	{
		// キャラクターのプロセス
		p_character->Process(p_camera->GetAngle());


		// カメラのプロセス
		p_camera->Process(p_character->GetArea());


		// 一般人のプロセス
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->Process();
			}
		}


		// 敵ラスボスのあれ
		p_enemyBossBefore->Process();


		// シャドウマップの位置を更新
		BaseMove::ShadowArea(p_character->GetArea());


		// スカイボックスの位置を更新
		BaseMove::SkyBoxProcess(p_character->GetArea());
	} /// if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyBossBefore->GetArea()) >= 250)
	// ボスと近かった時
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
		// カーソルを左に移動
		if (adjustmentControllStick[0] == 1)
		{
			approachUISelect = true;
		}
		// カーソルを右に移動
		if (adjustmentControllStick[1] == 1)
		{
			approachUISelect = false;
		}
		/// ---------------------------------------------------------------------------------------------------------------


		// 決定ボタンを押したら
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
		{
			// 近づくにカーソルがあったとき
			if (approachUISelect)
			{
				// シーンを移行する
				e_nowMove = ESceneMove6::Movie;
				p_cameraMove->SetView(VGet(4000, 50, 0));
				p_cameraMove->SetArea(VGet(3000, 200, 0));
				movieFrame = 0;
			}
			// 近づかないにカーソルがあったとき
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
		BaseMove::SkyBoxDraw();										// スカイボックスを描画


		ShadowDraw();												// シャドウマップを描画


		p_enemyBossBefore->ModelDraw();								// 敵ラスボスのあれ


		// 一般人
		if (BASICPARAM::ordinaryPeopleNum != 0)
		{
			for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
			{
				vp_ordinaryPerson[i]->Draw();
			}
		}


		p_character->Draw();										// キャラクターを描画


		DrawGraph(1920 - 260, 1080 - 80, movieSkipDraw, false);		// スキップの仕方を説明
	}
} /// void MainMove6::MovieDraw()



/// --------------------------------------------------------------------------------------------------
void MainMove6::MovieProcess()
{
	// 動きを管理
	movieFrame++;


	// ボス前のプロセスを呼ぶ
	p_enemyBossBefore->Process();
	p_enemyBossBefore->MoveReturn();


	// シャドウマップの位置を更新
	BaseMove::ShadowArea(p_cameraMove->GetArea());


	// スカイボックスの位置を更新
	BaseMove::SkyBoxProcess(p_cameraMove->GetArea());


	/// アクターごとの描画に関する---------------------------------------------
	// 300フレーム以上だったら地面に埋まらせる
	if (movieFrame >= 300)
	{
		// 存在していたらそれぞれを地面に埋まらせる
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


		// 600フレーム以上だったらボスを地面に埋まらせる
		if (movieFrame >= 600)
		{
			p_enemyBossBefore->AreaSetDown();
		}


		// 800フレーム以上だったらプレイヤーを地面に埋まらせる
		if (movieFrame >= 800)
		{
			p_character->AreaSetDown();
		}


		// ボスの埋めに合わせて地面に黒い円を出す
		if (movieFrame >= 600 && movieFrame < 800)
		{
			DrawCone3D(VGet(4000.0f, 0.0f, 0.0f), VGet(4000.0f, 1.0f, 0.0f), static_cast<float>(movieFrame - 600) * 2.0f, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);
		}
		else if (movieFrame >= 800)
		{
			DrawCone3D(VGet(4000.0f, 0.0f, 0.0f), VGet(4000.0f, 1.0f, 0.0f), static_cast<float>(1000 - movieFrame) * 2.0f, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);
		}
	} /// if (movieFrame >= 300)


	// 200フレーム以下だったら
	if (movieFrame <= 200)
	{
		// 操作できないプレイヤーのプロセスを呼ぶ
		p_character->NotOpeProcess(p_camera->GetAngle());
	}
	/// アクターごとの描画に関する---------------------------------------------


	/// カメラに関する------------------------------------------------------------------
	// 200フレームより多く300フレーム以下だったら
	if (movieFrame > 200 && movieFrame <= 400)
	{
		// カメラがボス注視するようにする
		p_cameraMove->SetView(VGet(4000 - (movieFrame - 200) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(3000 - (movieFrame - 200) * 10.0f, 200, 0));
		p_cameraMove->SetView(VGet(1000, 0, 1000));
	}


	// 400フレームより多く600フレーム以下だったら
	if (movieFrame > 400 && movieFrame <= 600)
	{
		// カメラがステージを見回すようにする
		p_cameraMove->SetView(VGet(2000 + (movieFrame - 400) * 10.0f, 50, 0));
		p_cameraMove->SetArea(VGet(1000 + (movieFrame - 400) * 10.0f, 200, 0));
	}
	/// カメラに関する------------------------------------------------------------------

	
	// シーン移行する
	if (movieFrame >= 1000
		|| DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_LB) == 1)
	{
		// いらないデータを削除
		{
			// 一般人
			if (BASICPARAM::ordinaryPeopleNum != 0)
			{
				for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
				{
					POINTER_RELEASE(vp_ordinaryPerson[i]);
				}
				vp_ordinaryPerson.clear();
				vp_ordinaryPerson.shrink_to_fit();
			}


			// 敵
			for (int i = 0; i != 3; ++i)
			{
				GRAPHIC_RELEASE(approachBossUIDraw[i]);
			}
			POINTER_RELEASE(p_enemyBossBefore);


			// 階段
			if (BASICPARAM::stairsNum != 0)
			{
				for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
				{
					POINTER_RELEASE(vp_stageStairs[i]);
				}
				vp_stageStairs.clear();
				vp_stageStairs.shrink_to_fit();
			}


			// 街灯
			if (BASICPARAM::streetLightNum != 0)
			{
				for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
				{
					POINTER_RELEASE(vp_stageStreetLight[i]);
				}
				vp_stageStreetLight.clear();
				vp_stageStreetLight.shrink_to_fit();
			}


			// 階段と床
			if (BASICPARAM::stairsRoadNum != 0)
			{
				for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
				{
					POINTER_RELEASE(vp_stageStairsRoad[i]);
				}
				vp_stageStairsRoad.clear();
				vp_stageStairsRoad.shrink_to_fit();
			}


			// ムービー用カメラ
			POINTER_RELEASE(p_cameraMove);


			// ムービー画像
			GRAPHIC_RELEASE(movieSkipDraw);
		}


		SetFogEnable(FALSE);														// フォグを解除
		BASICPARAM::paneruDrawFlag = true;											// パネルを描画させる
		BASICPARAM::lastPaneruView = true;											// パネルは必ず描画するように設定
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::boss, 255);		// BGMを再生
		e_nowMove = ESceneMove6::Battle;											// バトルへ移行
		p_character->PositionReset();												// キャラクターの座標を初期化
	}
} /// void MainMove6::MovieProcess()



/// --------------------------------------------------------------------------------------------------
void MainMove6::BattleDraw()
{
	// ステージの描画
	p_stage->Draw();


	// パネルの描画
	for (int i = 0; i != paneruNum; ++i)
	{
		if (!paneruArrival[0] && i >= 16 && i < 36) continue;
		if (!paneruArrival[1] && i >= 36 && i < 56) continue;
		if (!paneruArrival[2] && i >= 56 && i < 61) continue;
		if (!paneruArrival[3] && i >= 61 && i < 66) continue;
		p_stagePaneru[i]->ModelDraw();
	}


	// ボスの描画
	p_enemyBossAfter->DrawWhile();
	p_enemyBossAfter->Draw();


	// ボスの攻撃による追尾する箱
	p_chaseBlock[0]->Draw();
	p_chaseBlock[1]->Draw();


	// キャラクターの描画
	if (BASICPARAM::lastCharaView)
	{
		p_character->ModelDraw();
	}
	p_character->Draw();


	// 体力を表示する画像
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
	// キャラクターのプロセス
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	/// ワープ可能でその上にプレイヤーがいたら------------------------------------------------------------------------------------------------
	// すぐ左のパネル
	if (paneruArrival[0]
		&& p_stagePaneru[1]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[1]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[1]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[1]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[1]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[1]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// ボタン説明を出す
		DrawBillboard3D(VAdd(p_stagePaneru[1]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// Bボタンで移動する
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[7]->GetArea());
		}
	}
	// すぐ右のパネル
	else if (paneruArrival[1]
		&& p_stagePaneru[9]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[9]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[9]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[9]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[9]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[9]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// ボタン説明を出す
		DrawBillboard3D(VAdd(p_stagePaneru[9]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// Bボタンで移動する
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[15]->GetArea());
		}
	}
	// 左上のパネル
	else if (paneruArrival[2]
		&& p_stagePaneru[16]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[16]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[16]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[16]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[16]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[16]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// ボタン説明を出す
		DrawBillboard3D(VAdd(p_stagePaneru[16]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// Bボタンで移動する
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[35]->GetArea());
		}
	}
	// 右上のパネル
	else if (paneruArrival[3]
		&& p_stagePaneru[36]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[36]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[36]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[36]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[36]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[36]->GetArea().z + 100 > p_character->GetArea().z)
	{
		// ボタン説明を出す
		DrawBillboard3D(VAdd(p_stagePaneru[36]->GetArea(), VGet(0.0f, 300.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, warpDesc, false);


		// Bボタンで移動する
		if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
		{
			p_character->WarpMove6(p_stagePaneru[55]->GetArea());
		}
	}
	/// ワープ可能でその上にプレイヤーがいたら------------------------------------------------------------------------------------------------


	// 敵を目の前にして左の一番上に達したら
	if (!paneruArrival[0]
		&& p_stagePaneru[7]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[7]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[7]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[7]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[7]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[7]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[0] = true;
	}
	// 敵を目の前にして右の一番上に達したら
	if (!paneruArrival[1]
		&& p_stagePaneru[15]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[15]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[15]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[15]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[15]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[15]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[1] = true;
	}
	// 敵を目の前にして左の一番上に達した後で敵近くに到達したら
	if (paneruArrival[0] && !paneruArrival[2]
		&& p_stagePaneru[35]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[35]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[35]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[35]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[35]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[35]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[2] = true;
	}
	// 敵を目の前にして右の一番上に達した後で敵近くに到達したら
	if (paneruArrival[1] && !paneruArrival[3]
		&& p_stagePaneru[55]->GetArea().x - 100 < p_character->GetArea().x && p_stagePaneru[55]->GetArea().x + 100 > p_character->GetArea().x
		&& p_stagePaneru[55]->GetArea().y - 100 < p_character->GetArea().y && p_stagePaneru[55]->GetArea().y + 100 > p_character->GetArea().y
		&& p_stagePaneru[55]->GetArea().z - 100 < p_character->GetArea().z && p_stagePaneru[55]->GetArea().z + 100 > p_character->GetArea().z)
	{
		paneruArrival[3] = true;
	}


	// カメラのプロセス
	p_camera->Process(p_character->GetArea());


	// ボスのプロセス
	p_enemyBossAfter->Process();


	// 氷柱のエフェクト
	for (int i = 0; i != icePillarNum; ++i)
	{
		p_magicIcePillar[i]->Process();
	}


	// 追尾箱
	p_chaseBlock[0]->Process();
	p_chaseBlock[1]->Process();


	// 当たり判定のプロセス
	AttackProcess();


	/// ワープエフェクトの処理-----------------------------------------------------------------------------------------------------------
	// 敵を目の前にして左の一番上に到達したら
	if (paneruArrival[0])
	{
		// エフェクトが再生していなかったら
		if (IsEffekseer3DEffectPlaying(playingEfWarp[0]) != 0)
		{
			// 左一つ上のパネルで
			playingEfWarp[0] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[0], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[0], p_stagePaneru[1]->GetArea().x, p_stagePaneru[1]->GetArea().y + 55, p_stagePaneru[1]->GetArea().z);
		}
	}
	// 敵を目の前にして右の一番上に到達したら
	if (paneruArrival[1])
	{
		// エフェクトが再生していなかったら
		if (IsEffekseer3DEffectPlaying(playingEfWarp[1]) != 0)
		{
			// 右一つ上のパネルで
			playingEfWarp[1] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[1], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[1], p_stagePaneru[9]->GetArea().x, p_stagePaneru[9]->GetArea().y + 55, p_stagePaneru[9]->GetArea().z);
		}
	}
	// 敵を目の前にして左の敵近くに到達したら
	if (paneruArrival[2])
	{
		// エフェクトが再生していなかったら
		if (IsEffekseer3DEffectPlaying(playingEfWarp[2]) != 0)
		{
			// 左一番上のパネルで
			playingEfWarp[2] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[2], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[2], p_stagePaneru[16]->GetArea().x, p_stagePaneru[16]->GetArea().y + 55, p_stagePaneru[16]->GetArea().z);
		}
	}
	// 敵を目の前にして右の敵近くに到達したら
	if (paneruArrival[3])
	{
		// エフェクトが再生していなかったら
		if (IsEffekseer3DEffectPlaying(playingEfWarp[3]) != 0)
		{
			// 右一番上のパネルで
			playingEfWarp[3] = PlayEffekseer3DEffect(effectWarp);
			SetScalePlayingEffekseer3DEffect(playingEfWarp[3], 40, 40, 40);
			SetPosPlayingEffekseer3DEffect(playingEfWarp[3], p_stagePaneru[36]->GetArea().x, p_stagePaneru[36]->GetArea().y + 55, p_stagePaneru[36]->GetArea().z);
		}
	}
	/// ワープエフェクトの処理-----------------------------------------------------------------------------------------------------------


	// ボスが死んだら
	if (enemyDamageCount >= 1000 / enemyDamageHitCount)
	{
		// 次のシーンへ移行する
		if (p_enemyBossAfter->SetDeathBlendDraw())
		{
			p_camera->SetShakePower(0.0f);
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::ending);
			e_nowMove = ESceneMove6::Last;
			p_character->PositionReset();
			movieFrame = 0;
		}
		// 次のシーンへ移行する前の準備をする
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


	// プレイヤーが死んだら
	if (damageCount >= 477)
	{
		// タイトルへ強制的に移動させる
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FIRSTLOAD);
	}


#ifdef _DEBUG
	// 次のシーンへ移行
	if (CheckHitKey(KEY_INPUT_M) == 1)
	{
		// 次のシーンへ移行する
		if (p_enemyBossAfter->SetDeathBlendDraw())
		{
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::ending);
			e_nowMove = ESceneMove6::Last;
			p_character->PositionReset();
			movieFrame = 0;
		}
		// 次のシーンへ移行する前の準備をする
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
		LoadFile::MyLoad("media\\UI\\ゲージ\\normal.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージの中身1\\normal.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\normal.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\UI\\clph_icon\\D.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\D.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージ\\D.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージの中身1\\D.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\D.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\UI\\clph_icon\\P.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\P.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージ\\P.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージの中身1\\P.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\P.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\UI\\clph_icon\\normal.pyn", battleHealDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\no_name\\normal.pyn", battleHealDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージ\\normal.pyn", battleHealDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\ゲージの中身1\\normal.pyn", battleHealDraw[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\UI\\enemy\\normal.pyn", battleHealDraw[4], ELOADFILE::graph);
		break;
	}
}



/// --------------------------------------------------------------------------------------------------
void MainMove6::LastDraw()
{
	BaseMove::SkyBoxDraw();		// スカイボックスを描画


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


	// キャラクターのプロセス
	p_character->OnlyCollFloorProcess(p_camera->GetAngle());


	// カメラのプロセス
	p_camera->Process(p_character->GetArea());


	// スカイボックスの位置を更新
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
	// 初期化
	BASICPARAM::paneruDrawFlag = false;
	e_nowMove = ESceneMove6::First;


	// ポインタNULL初期化
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


	// ムービーでの画像
	movieSkipDraw = v_file[EFILE::movieSkip];


	// 戦闘中の画像
	battleHealDraw[static_cast<int>(EHealDraw::icon)]		 = v_file[EFILE::charaIcon];
	battleHealDraw[static_cast<int>(EHealDraw::iconBack)]	 = v_file[EFILE::charaIconBack];
	battleHealDraw[static_cast<int>(EHealDraw::gage)]		 = v_file[EFILE::charaGage];
	battleHealDraw[static_cast<int>(EHealDraw::gageBar)]	 = v_file[EFILE::charaGageBar];
	battleHealDraw[static_cast<int>(EHealDraw::enemyGage)]	 = v_file[EFILE::enemyGageBar];


	// ステージの初期化
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// キャラクターの初期化
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	damageCount = 0;
	warpDesc = v_file[EFILE::warpDescDraw];


	// カメラの初期化
	p_camera = new Camera(p_character->GetArea());
	p_cameraMove = new CameraMove6();
	cameraShakeParam = 0.0f;


	// パネルの初期化
	p_character->SetCollPaneruNum(paneruNum);
	for (int i = 0; i != paneruNum; ++i)
	{
		// 微妙に散らばせる
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-300, 300);        // X座標用乱数
		std::uniform_int_distribution<> randInZ(-300, 300);        // Z座標用乱数
		// 敵を目の前にして左上
		if (i < 8)
		{
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randInX(mt))
				, static_cast<float>(800.0f * i), static_cast<float>(500.0f * i)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 敵を目の前にして右上
		else if (i < 16)
		{
			int temp = i - 8;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randInX(mt))
				, static_cast<float>(800.0f * temp), static_cast<float>(-500.0f * temp)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 敵を目の前にして左の列
		else if (i < 36)
		{
			int temp = i - 16;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4370 / 20 * temp)
				, static_cast<float>(5600.0f - (2000 / 20 * temp)), static_cast<float>(3500 - (2500 / 20 * temp))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 敵を目の前にして右の列
		else if (i < 56)
		{
			int temp = i - 36;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4370 / 20 * temp)
				, static_cast<float>(5600.0f - (2000 / 20 * temp)), static_cast<float>((2500 / 20 * temp) - 3500)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 敵を目の前にして敵左から腹まで
		else if (i < 61)
		{
			int temp = i - 56;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4150 - (600 / 5 * temp))
				, static_cast<float>(3750 - (500 / 5 * temp)), static_cast<float>(1120 - (1120 / 5 * temp))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 敵を目の前にして敵右から腹まで
		else if (i < 66)
		{
			int temp = i - 61;
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(4150 - (600 / 5 * temp))
				, static_cast<float>(3750 - (500 / 5 * temp)), static_cast<float>((1120 / 5 * temp) - 1120)));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
		// 特に意味もなくこれまでのパネル内で散らばす
		else
		{
			std::uniform_int_distribution<> randX(1000, 3000);			// X座標用乱数
			std::uniform_int_distribution<> randY(2000, 4000);			// Y座標用乱数
			std::uniform_int_distribution<> randZ(-3000, 3000);			// Z座標用乱数
			p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(static_cast<float>(randX(mt))
				, static_cast<float>(randY(mt)), static_cast<float>(randZ(mt))));
			p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
		}
	}
	for (int i = 0; i != 4; ++i)
	{
		paneruArrival[i] = false;
	}


	// 階段と床の初期化
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


	// 街灯の初期化
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


	// 階段の初期化
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


	// 敵の初期化
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



	// 一般人
	if (BASICPARAM::ordinaryPeopleNum != 0)
	{
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-4000, 4000);		// X座標用乱数
		std::uniform_int_distribution<> randInZ(-4000, 4000);		// Z座標用乱数


		vp_ordinaryPerson.resize(BASICPARAM::ordinaryPeopleNum);
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			// X座標設定
			float tempX = static_cast<float>(randInX(mt));
			if (tempX <= 200.0f && tempX >= 0.0f)
			{
				tempX += 200.0f;
			}
			if (tempX >= -200.0f && tempX <= 0.0f)
			{
				tempX -= 200.0f;
			}

			// Y座標設定
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


	// スカイボックス
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// エンドロール関連
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


	// サウンドのロード
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


	// エフェクトのロード
	effectWarp = LoadEffekseerEffect("media\\Effect\\warp.efk");
	for (int i = 0; i != 4; ++i)
	{
		playingEfWarp[i] = -1;
	}
} /// MainMove6::MainMove6(const std::vector<int> v_file)



/// --------------------------------------------------------------------------------------------------
MainMove6::~MainMove6()
{
	// エフェクト開放
	for (int i = 0; i != 4; ++i)
	{
		StopEffekseer3DEffect(playingEfWarp[i]);
	}
	DeleteEffekseerEffect(effectWarp);


	// エンドロール
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(endrolDraw[i]);
	}


	// 一般人
	if (vp_ordinaryPerson.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::ordinaryPeopleNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_ordinaryPerson[i]);
		}
		vp_ordinaryPerson.clear();
		vp_ordinaryPerson.shrink_to_fit();
	}


	// 敵
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(approachBossUIDraw[i]);
	}
	POINTER_RELEASE(p_enemyBossBefore);
	POINTER_RELEASE(p_enemyBossAfter);


	// 階段
	if (vp_stageStairs.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairs[i]);
		}
		vp_stageStairs.clear();
		vp_stageStairs.shrink_to_fit();
	}


	// 街灯
	if (vp_stageStreetLight.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStreetLight[i]);
		}
		vp_stageStreetLight.clear();
		vp_stageStreetLight.shrink_to_fit();
	}


	// 階段と床
	if (vp_stageStairsRoad.size() != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairsRoad[i]);
		}
		vp_stageStairsRoad.clear();
		vp_stageStairsRoad.shrink_to_fit();
	}


	// パネル
	for (int i = 0; i != paneruNum; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// カメラ
	POINTER_RELEASE(p_cameraMove);
	POINTER_RELEASE(p_camera);


	// キャラクター
	GRAPHIC_RELEASE(warpDesc);
	POINTER_RELEASE(p_character);


	// ステージ
	POINTER_RELEASE(p_stage);


	// 戦闘中画像
	for (int i = 0; i != 5; ++i)
	{
		GRAPHIC_RELEASE(battleHealDraw[i]);
	}


	// ムービー画像
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
		// キャラクターのテクスチャが白黒指定じゃなかったら
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// キャラクター
			ths = p_character->ThsTextureReload();
			ths.join();
		}
	}


	if (textureReloadCountDo == 5)
	{
		// 戦闘敵の画像
		ths = p_enemyBossAfter->ThsTextureReload();
		ths.join();
	}


	if (textureReloadCountDo == 4)
	{
		// その他のテクスチャが白黒指定じゃなかったら
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// 一般人
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
		// 階段のテクスチャが白黒指定じゃなかったら
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
		// 街灯のテクスチャが白黒指定じゃなかったら
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
		// 階段と床のテクスチャが白黒指定じゃなかったら
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
		// 戦闘中画像
		ths = std::thread(&MainMove6::BattleTextureReload, this);
		ths.join();
	}


	if (++textureReloadCountDo <= 6)
	{
		ThsTextureReload();					// 読み込み終わるまで再帰
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
