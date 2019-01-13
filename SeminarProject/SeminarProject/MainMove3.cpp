#include "MainMove3.hpp"


// ダメージテクスチャの差し替え
void MainMove3::DamageTextureReload()
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
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\D.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\D.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\D.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\D.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\D.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\D.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\D.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\D.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\D.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\D.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\D.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\D.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\D.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\P.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\P.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\P.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\P.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\P.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\P.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\P.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\P.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\P.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\P.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\P.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\P.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\P.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\こっち\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;
	}
} /// void MainMove3::DamageTextureReload()


// 精密機械のプロセス
void MainMove3::AdjustmentProcess()
{
	// 決定ボタンを押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// キーボードで1を押していたら
		if (CheckHitKey(KEY_INPUT_1) == 1)
		{
			// キャラクター関係のテクスチャを白黒から戻す
			if (BASICPARAM::charaTextureWhiteBlack)
			{
				// ダメージ演出
				DamageTextureReload();


				// キャラクター
				p_character->TextureReload();
				BASICPARAM::charaTextureWhiteBlack = false;
			}
		}
		// キーボードで2を押していたら
		if (CheckHitKey(KEY_INPUT_2) == 1)
		{
			// そのほかのアクターのテクスチャを白黒から戻す
			if (BASICPARAM::anothreTextureWhiteBlack)
			{
				// 精密機械
				p_adjustmentMachine->TextureReload();
				BASICPARAM::anothreTextureWhiteBlack = false;
			}
		}
		// キーボードで3を押していたら
		if (CheckHitKey(KEY_INPUT_3) == 1)
		{
			// 敵のテクスチャを白黒から戻す
			if (BASICPARAM::enemyTextureWhiteBlack)
			{
				BASICPARAM::enemyTextureWhiteBlack = false;
			}
		}
		// キーボードで4を押していたら
		if (CheckHitKey(KEY_INPUT_4) == 1)
		{
			// 街灯のテクスチャを白黒から戻す
			if (BASICPARAM::lightStreetTextureWhiteBlack)
			{
				if (BASICPARAM::streetLightNum != 0)
				{
					for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
					{
						vp_stageStreetLight[i]->TextureReload();
					}
				}
				BASICPARAM::lightStreetTextureWhiteBlack = false;
			}
		}
		// キーボードで5を押していたら
		if (CheckHitKey(KEY_INPUT_5) == 1)
		{
			// 階段と床のテクスチャを白黒から戻す
			if (BASICPARAM::stairsRoadTextureWhiteBlack)
			{
				if (BASICPARAM::stairsRoadNum != 0)
				{
					for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
					{
						vp_stageStairsRoad[i]->TextureReload();
					}
				}
				BASICPARAM::stairsRoadTextureWhiteBlack = false;
			}
		}
		// キーボードで6を押していたら
		if (CheckHitKey(KEY_INPUT_6) == 1)
		{
			// 階段のテクスチャを白黒から戻す
			if (BASICPARAM::stairsTextureWhiteBlack)
			{
				if (BASICPARAM::stairsNum != 0)
				{
					for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
					{
						vp_stageStairs[i]->TextureReload();
					}
				}
				BASICPARAM::stairsTextureWhiteBlack = false;
			}
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// Bボタンが押されたら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// 精密機械から戻る
		adjustmentFeedNow = true;
		adjustmentStartFeed = false;
	}

	
	// RBボタンが押されたらパネルを描画する
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
		&& !BASICPARAM::paneruDrawFlag)
	{
		BASICPARAM::paneruDrawFlag = true;
	}
} /// void MainMove3::AdjustmentProcess()


// 精密機械の描画
void MainMove3::AdjustmentDraw()
{
	// フェードが終わったら
	if (adjustmentSceneFeed >= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(247, 247, 247), true);

		DrawFormatString(50, 50, 255, "1: charaTextureWhiteBlack : %s\n", BASICPARAM::charaTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 150, 255, "3: enemyTextureWhiteBlack : %s\n", BASICPARAM::enemyTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 250, 255, "6: stairsTextureWhiteBlack : %s\n", BASICPARAM::stairsTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 350, 255, "5: stairsRoadTextureWhiteBlack : %s\n", BASICPARAM::stairsRoadTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 450, 255, "4: lightStreetTextureWhiteBlack : %s\n", BASICPARAM::lightStreetTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 550, 255, "2: anothreTextureWhiteBlack : %s\n", BASICPARAM::anothreTextureWhiteBlack ? "true" : "false");
	}


	// 精密機械への切り替えフェード
	if (adjustmentSceneFeed <= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed > 50 && adjustmentSceneFeed <= 100)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (20 - adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
}


// シャドウマップ描画
void MainMove3::ShadowDraw()
{
	/// セットアップ
	BaseMove::ShadowCharaSetUpBefore();
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
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	p_adjustmentMachine->ModelDraw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag() || p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag() || p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
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
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	p_adjustmentMachine->ModelDraw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


	/// 描画
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// ステージ
	p_stage->Draw();
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
	// パネル
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// 精密機械
	p_adjustmentMachine->ModelDraw();
	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
	}
	// キャラクター
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// キャラクター
	p_character->ModelDraw();
} /// void MainMove3::ShadowDraw()


// 当たり判定処理
void MainMove3::AttackProcess()
{
	/// 敵への攻撃に関する--------------------------------------------------------------------------------------------------------
	// クレヨンヒューマンに関する
	for (int i = 0, n = enemyCrayonHumanNum; i != n; ++i)
	{
		// 死んでいたら
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		// プレイヤーの攻撃モーションが終わったら
		if (p_character->GetAttackMotionEnd()) enemyCrayonHumanDamage[i] = false;


		// ダメージを受けていないがプレイヤーが攻撃中だったら
		if (p_character->GetAttackNow() && !enemyCrayonHumanDamage[i])
		{
			p_enemyCrayonHuman[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// 攻撃でダメージを受けたら
		if (p_enemyCrayonHuman[i]->GetDamageFlag())
		{
			// 戦闘BGMが流れていなかったら
			if (!nowBattleBGM)
			{
				nowBattleBGM = true;
				SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
			}
			

			// ダメージを受けているとする
			enemyCrayonHumanDamage[i] = true;
			// バイブレーションさせる
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);


			// エフェクトを再生する。
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemyCrayonHumanNum; i != n; ++i)
	// スライムに関する
	for (int i = 0, n = enemySlimeNum; i != n; ++i)
	{
		// 死んでいたら
		if (p_enemySlime[i]->GetDeathFlag()) continue;

		
		// プレイヤーの攻撃が終わったら
		if (p_character->GetAttackMotionEnd()) enemySlimeDamage[i] = false;


		// ダメージを受けていなくてプレイヤーが攻撃中だったら
		if (p_character->GetAttackNow() && !enemySlimeDamage[i])
		{
			p_enemySlime[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// 攻撃でダメージを受けたら
		if (p_enemySlime[i]->GetDamageFlag())
		{
			// 戦闘BGMが流れていなかったら
			if (!nowBattleBGM)
			{
				nowBattleBGM = true;
				SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
			}


			// ダメージを受けている
			enemySlimeDamage[i] = true;
			// バイブレーションさせる
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);


			// エフェクトを再生する。
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemySlimeNum; i != n; ++i)
	/// 敵への攻撃に関する--------------------------------------------------------------------------------------------------------


	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------
	// プレイヤーが当たっていたとき
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()
		, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
	{
		// プレイヤーを押し出す
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
			, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
	}
	// スライムに関する
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// スライムとの距離がぶつかる距離だったら
		if (BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;


		// スライムが当たっていたとき
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// スライムを押し出す
			p_enemySlime[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemySlime[i]->GetWidth());
		}
	}
	// クレヨンヒューマンに関する
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// クレヨンヒューマンとの距離がぶつかる距離だったら
		if (BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;


		// クレヨンヒューマンが当たっていたとき
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// クレヨンヒューマンを押し出す
			p_enemyCrayonHuman[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
		}
	}
	// プレイヤーとの距離が近くて、触れるボタン押したら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// 精密機械へのシーンへフェードする
		adjustmentFeedNow = true;
		adjustmentStartFeed = true;
		changeAdjustmentScene = true;
	}
	// プレイヤーが近くかどうかで見た目を変える
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}
	/// 精算機械に関する-------------------------------------------------------------------------------------------------------------------


	/// キャラクターから押し出される-------------------------------------------------------------------------------------------------------
	// スライムに関する
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// 死んでいるかプレイヤーとの距離が近くではなかったら
		if (p_enemySlime[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// プレイヤーと当たっていたら
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// スライムを押し出す
			p_enemySlime[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_character->GetWidth() : p_enemySlime[i]->GetWidth());
		}
	}
	// クレヨンヒューマンに関する
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// 死んでいるかプレイヤーとの距離が近くではなかったら
		if (p_enemyCrayonHuman[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// プレイヤーと当たっていたら
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// クレヨンヒューマンを押し出す
			p_enemyCrayonHuman[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_character->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
		}
	}
	/// キャラクターから押し出される-------------------------------------------------------------------------------------------------------


	/// 敵同士で押し出す---------------------------------------------------------------------------------------------------------------------
	// 主体をスライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// 死んでいたら
		if (p_enemySlime[i]->GetDeathFlag()) continue;


		// 相手がスライム
		for (int j = 0; j != enemySlimeNum; ++j)
		{
			// 自分と自分で行わせないかスライムが死んでいるか距離が遠かったら
			if (i == j || p_enemySlime[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;


			// 当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
				p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				// 自分が押し出される
				p_enemySlime[i]->HitCircleReturn(p_enemySlime[j]->GetArea(), p_enemySlime[j]->GetWidth());
			}
		} /// for (int j = 0; j != enemySlimeNum; ++j)
		

		// 相手がクレヨンヒューマン
		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			// 死んでいるか距離が遠かったら
			if (p_enemyCrayonHuman[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;


			// 当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[j]->GetHeight(), 0.0f)), p_enemyCrayonHuman[j]->GetWidth()))
			{
				// 自分が押し出される
				p_enemySlime[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea()
					, p_enemyCrayonHuman[j]->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_enemyCrayonHuman[j]->GetWidth() : p_enemySlime[i]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemySlimeNum; ++i)
	// 主体をクレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// 死んでいたら
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		// 相手がクレヨンヒューマン
		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			// 自分と自分では行わないか死んでいたらか距離が遠かったら
			if (i == j || p_enemyCrayonHuman[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;


			// 当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()))
			{
				// 自分を押し出す
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea(), p_enemyCrayonHuman[i]->GetWidth());
			}
		} /// for (int j = 0; j != enemyCrayonHumanNum; ++j)
		// 相手がスライム
		for (int j = 0; j != enemySlimeNum; ++j)
		{
			// 死んでいるか距離が遠かったら
			if (p_enemySlime[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;


			// 当たっていたら
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				// 自分を押し出す
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemySlime[j]->GetArea()
					, p_enemySlime[j]->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_enemySlime[j]->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemyCrayonHumanNum; ++i)
	/// 敵同士で押し出す---------------------------------------------------------------------------------------------------------------------


	/// ドロップに関する--------------------------------------------------------------------------------------
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		// ドロップが手に入れられる状態ではなかったら
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;


		// プレイヤーとの距離が近づける距離だったら
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
		{
			p_dropItem[i]->ChaseActor(p_character->GetArea());
		}


		// プレイヤーが拾える距離だったら
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
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
} /// void MainMove3::AttackProcess()


// 非同期ロード
void MainMove3::ThsTextureReload()
{
	ths = std::thread(&MainMove3::TextureReload, this);
	ths.join();
}


// コンストラクタ
MainMove3::MainMove3(const std::vector<int> v_file)
{
	// パネルを非表示にする
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::charaTextureWhiteBlack = true;
	BASICPARAM::anothreTextureWhiteBlack = true;
	BASICPARAM::enemyTextureWhiteBlack = true;
	BASICPARAM::lightStreetTextureWhiteBlack = true;
	BASICPARAM::stairsRoadTextureWhiteBlack = true;
	BASICPARAM::stairsTextureWhiteBlack = true;


	// ポインタNULL初期化
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
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		p_dropItem[i] = nullptr;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();


	// ムーブ説明
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 750;


	// ステージの初期化
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// キャラクターの初期化
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	charaSomeEnemyDamageCount = 0;


	// カメラの初期化
	p_camera = new Camera(p_character->GetArea());


	// パネルの初期化
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(500.0f * i, 300.0f * i, 100.0f * i));
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// 階段と床の初期化
	if (BASICPARAM::stairsRoadNum != 0)
	{
		vp_stageStairsRoad.resize(BASICPARAM::stairsRoadNum + 1);
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
		vp_stageStreetLight.resize(BASICPARAM::streetLightNum + 1);
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
		vp_stageStairs.resize(BASICPARAM::stairsNum + 1);
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i] = nullptr;
			vp_stageStairs[i] = new StageStairs(v_file[EFILE::stairsDrawModel], BASICPARAM::v_stairsArea[i], v_file[EFILE::stairsTex0], BASICPARAM::v_stairsAngle[i]);
			p_character->SetStairsArea(vp_stageStairs[i]->GetArea(), i, BASICPARAM::v_stairsAngle[i]);
		}
	}


	// 精密機械の初期化
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminalModel], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);
	for (int i = 0; i != 15; ++i)
	{
		p_adjustmentMachine->CatchDropItem();
	}
	adjustmentDescDraw = v_file[EFILE::terminalDesc];
	changeAdjustmentScene = false;
	adjustmentSceneFeed = 0;
	adjustmentFeedNow = false;


	// 敵スライムの初期化
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z座標用乱数
	for (int i = 0; i != enemySlimeNum; ++i)
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
		p_enemySlime[i] = new EnemyMove3Slime(v_file[EFILE::slimeModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::slimeTex0], VGet(tempX, 0.0f, tempZ), 0.0f);
		enemySlimeDamage[i] = false;
	}

	// 敵クレヨンヒューマンの初期化
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
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
		p_enemyCrayonHuman[i] = new EnemyMove3CrayonHuman(v_file[EFILE::crayonHumanModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::crayonHumanTex0], VGet(tempX, 0.0f, tempZ), 0.0f);
		enemyCrayonHumanDamage[i] = false;
	}
	mostNearEnemyDistance = 10000;
	lockONNowEnemyID = 0;
	lockOnEnemySlime = false;


	// ドロップアイテムの初期化
	catchDropItemNum = 0;
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove3(v_file[EFILE::dropItemModel], p_character->GetArea(), v_file[EFILE::dropItemTex0]);
	}


	// スカイボックス
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// ステージの床
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// サウンドのロード
	nowBattleBGM = false;
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
	SoundProcess::Load(v_file[EFILE::enemyAttackSE], SoundProcess::ESOUNDNAME_SE::strikeBomb);
	SoundProcess::Load(v_file[EFILE::crayonDeadSE], SoundProcess::ESOUNDNAME_SE::crayonDie);
	SoundProcess::Load(v_file[EFILE::fightBGM], SoundProcess::ESOUNDNAME_BGM::battleBGM);

	//SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::battleBGM, 0, 0);
	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 255, 255);


	// ダメージ演出
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


	// エフェクト読み込み
	effeckBack[0] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\one.efk");
	effeckBack[1] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\two.efk");
	effeckBack[2] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\three.efk");
	effeckBack[3] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\four.efk");
	effeckBack[4] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\five.efk");
	effeckBack[5] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\six.efk");
	effeckBack[6] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\seven.efk");
	effeckBack[7] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\eight.efk");
	effeckBack[8] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\nine.efk");
	effeckBack[9] = LoadEffekseerEffect("media\\こっち\\media\\Effect\\damagePerticle\\ten.efk");
	playingEfDamage = -1;
	effectAttack = LoadEffekseerEffect("media\\こっち\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
} /// MainMove3::MainMove3(const std::vector<int> v_file)


// デストラクタ
MainMove3::~MainMove3()
{
	// エフェクト開放
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);


	// ダメージ演出
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


	// ドロップアイテム
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}


	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		POINTER_RELEASE(p_enemyCrayonHuman[i]);
	}


	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		POINTER_RELEASE(p_enemySlime[i]);
	}


	// 精密機械
	GRAPHIC_RELEASE(adjustmentDescDraw);
	POINTER_RELEASE(p_adjustmentMachine);


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


	// パネル
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// カメラ
	POINTER_RELEASE(p_camera);


	// キャラクター
	POINTER_RELEASE(p_character);


	// ステージ
	POINTER_RELEASE(p_stage);


	/// 説明画像解放
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove3::~MainMove3()


// 描画
void MainMove3::Draw()
{
	BaseMove::SkyBoxDraw();		// スカイボックスの描画


	ShadowDraw();		// シャドウマップの描画


	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// 死んでいたら
		if (p_enemySlime[i]->GetDeathFlag()) continue;


		p_enemySlime[i]->Draw();
	}


	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// 死んでいたら
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		p_enemyCrayonHuman[i]->Draw();
	}


	// ドロップアイテム
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		// 手に入れられる状態じゃなかったら
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;


		p_dropItem[i]->ModelDraw();
	}


	// キャラクター
	p_character->Draw();


	// 精密機械と距離が近かったら
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// 精密機械の説明画像
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}


	/// ロックオンに関する------------------------------------------------------------------------------------------------------------
	// プレイヤーと近い敵にロックオンの描画をする
	if (mostNearEnemyDistance <= 1000)
	{
		// ロックオン対象がスライムだったら
		if (lockOnEnemySlime)
		{
			// 存在していたら
			if (!p_enemySlime[lockONNowEnemyID]->GetEraseExistence())
			{
				// 攻撃範囲内だったら
				if (mostNearEnemyDistance < 250)
				{
					// 横棒
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
					// 縦棒
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
				}
				// 攻撃範囲外だったら
				else
				{
					// 横棒
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
					// 縦棒
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
				}
			}
		} /// if (lockOnEnemySlime)
		// ロックオン対象がクレヨンヒューマンだったら
		else
		{
			// 存在していたら
			if (!p_enemyCrayonHuman[lockONNowEnemyID]->GetEraseExistence())
			{
				// 攻撃範囲内だったら
				if (mostNearEnemyDistance < 250)
				{
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
				}
				// 攻撃範囲外だったら
				else
				{
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
				}
			}
		} /// else(!if (lockOnEnemySlime))
	} /// if (mostNearEnemyDistance <= 1000)
	/// ロックオンに関する------------------------------------------------------------------------------------------------------------


	/// ダメージに関する-----------------------------------------------------------------------------------------------------------
	/// エフェクトを再生する-------------------------------------------------------------------------------
	if (preDamageCount != damageCount / 10)
	{
		// ダメージカウントが10の倍数で次か前のエフェクトに切り替える
		preDamageCount = damageCount / 10;


		// エフェクトが再生中だったら
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);


		// エフェクトを再生する
		playingEfDamage = PlayEffekseer2DEffect(effeckBack[preDamageCount - 1]);
		SetScalePlayingEffekseer2DEffect(playingEfDamage, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfDamage, 960, 540, 0);
	}
	// ダメージを受けていなかったら
	if (damageCount == 0)
	{
		// エフェクトを止める
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);
	}
	/// エフェクトを再生する-------------------------------------------------------------------------------


	/// ダメージの演出
	if (damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	/// ダメージの蓄積で画面を埋め尽くす処理-----------------------------------------------
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
	/// ダメージの蓄積で画面を埋め尽くす処理-----------------------------------------------
	/// ダメージに関する-----------------------------------------------------------------------------------------------------------



	DrawFormatString(1020, 20, GetColor(0, 0, 0), "手に入れたドロップアイテムの数: %d", catchDropItemNum);


	AdjustmentDraw();		// 精密機械の描画


	// ムーブ説明をする
	if (moveDescriptionFrame-- > 0)
	{
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 268, 540 - 146 - 73, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
} /// void MainMove3::Draw()


// プロセス
void MainMove3::Process()
{
	// 精密機械のシーンじゃなかったら
	if (!changeAdjustmentScene)
	{
		// キャラクターのプロセス
		p_character->Process(p_camera->GetAngle());
		charaSomeEnemyDamageCount = 0;					// 何体の敵から同時にダメージを受けているか取得する数値


		/// ダメージを受けていないカウント数で処理---------------------------------------------------------
		notDamageCount++;


		// ダメージを受けていなかったら回復させる
		if (notDamageCount > 100 && damageCount > 0 && (notDamageCount - 100) % 10 == 0) damageCount--;

		
		// ダメージ演出画像が残っていたらだんだん消す
		if (damageDrawFrame > 0) damageDrawFrame--;


		// 戦闘BGMだったら通常BGMに切り替える
		if (notDamageCount > 100 && nowBattleBGM)
		{
			nowBattleBGM = false;
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::normalBGM);
		}
		/// ダメージを受けていないカウント数で処理---------------------------------------------------------


		// カメラのプロセス
		p_camera->Process(p_character->GetArea());


		// ドロップアイテム
		for (int i = 0, n = dropItemNum; i != n; ++i)
		{
			// 死んでいたら
			if (p_dropItem[i]->GetDeath()) continue;
			p_dropItem[i]->Process();
		}


		/// スライムのプロセスに関する-------------------------------------------------------------------------------------------------------------------------------
		// 敵スライムのプロセス
		for (int i = 0; i != enemySlimeNum; ++i)
		{
			// 消滅したら
			if (p_enemySlime[i]->GetEraseExistence())
			{
				// ロックオン対象だったら
				if (i == lockONNowEnemyID && lockOnEnemySlime)
				{
					// ロックオンから除外する
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// ドロップアイテムを落とす
				if (!p_dropItem[(i * 5)]->GetDeath() && !p_dropItem[(i * 5)]->GetAlive()) p_dropItem[(i * 5)]->SetAlive(p_enemySlime[i]->GetArea());
				else continue;
				if (!p_dropItem[(i * 5) + 1]->GetDeath() && !p_dropItem[(i * 5) + 1]->GetAlive()) p_dropItem[(i * 5) + 1]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 2]->GetDeath() && !p_dropItem[(i * 5) + 2]->GetAlive()) p_dropItem[(i * 5) + 2]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 3]->GetDeath() && !p_dropItem[(i * 5) + 3]->GetAlive()) p_dropItem[(i * 5) + 3]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 4]->GetDeath() && !p_dropItem[(i * 5) + 4]->GetAlive()) p_dropItem[(i * 5) + 4]->SetAlive(p_enemySlime[i]->GetArea());
				continue;
			}


			// プロセスを呼ぶ
			p_enemySlime[i]->Process();


			// 死んでいたら
			if (p_enemySlime[i]->GetDeathFlag()) continue;


			// ロックオン対象がスライムだったら
			if (lockOnEnemySlime)
			{
				// 現在のロックオン対象より近かったら
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()))
				{
					// ロックオン対象をこのスライムに更新する
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemySlime[i]->GetArea());
					lockONNowEnemyID = i;


					// 更新した対象がプレイヤーから視認できる範囲だったら
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemySlime[i]->GetArea());
					}
					// 更新した対象がプレイヤーから視認できない範囲だったら
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}
			// ロックオン対象がクレヨンヒューマンだったら
			else
			{
				// 現在のロックオン対象より近かったら
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()))
				{
					// ロックオン対象を更新する
					lockOnEnemySlime = true;
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemySlime[i]->GetArea());
					lockONNowEnemyID = i;


					// 更新した対象がプレイヤーから視認できる範囲だったら
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemySlime[i]->GetArea());
					}
					// 更新した対象がプレイヤーから視認できない範囲だったら
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}


			// プレイヤーの場所と距離を更新する
			p_enemySlime[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()));


			// プレイヤーを攻撃出来たら
			if (p_enemySlime[i]->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemySlime[i]->GetArea().y + p_enemySlime[i]->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemySlime[i]->GetArea().y)
			{
				// 戦闘BGMじゃなかったら
				if (!nowBattleBGM)
				{
					// 戦闘BGMを流す
					nowBattleBGM = true;
					SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
				}


				// プレイヤーを攻撃している個体数が2以下だったら
				if (charaSomeEnemyDamageCount++ < 2)
				{
					// 攻撃SEを流す
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemySlime[i]->GetArea(), 180);


					p_character->SetDamage();					// プレイヤーにダメージを受けさせる


					// プレイヤーのダメージを受けていないカウントが0じゃなかったら
					if(notDamageCount != 0) notDamageCount = 0;


					// プレイヤーのダメージ数値が100以下だったら
					if (damageCount < 100)	damageCount++;


					// ダメージ演出画像が出ていなかったら
					if (damageDrawFrame == 0)
					{
						std::random_device rnd;     // 非決定的な乱数生成器を生成
						std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
						std::uniform_int_distribution<> blood(0, 2);        // X座標用乱数
						damageDrawID = blood(mt);		// 乱数から画像を選ぶ
						damageDrawFrame = 10;			// 10フレーム出すようにする
					}
				}
			}
		} /// for (int i = 0; i != enemySlimeNum; ++i)
		/// スライムのプロセスに関する-------------------------------------------------------------------------------------------------------------------------------


		/// クレヨンヒューマンのプロセスに関する--------------------------------------------------------------------------------------------------------------------
		// 敵クレヨンヒューマンのプロセス
		for (int i = 0; i != enemyCrayonHumanNum; ++i)
		{
			// 消滅していたら
			if (p_enemyCrayonHuman[i]->GetEraseExistence())
			{
				// ロックオン対象だったら
				if (i == lockONNowEnemyID && !lockOnEnemySlime)
				{
					// 除外する
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// ドロップアイテムを出す
				int temp = enemySlimeNum * 5;
				if (!p_dropItem[(i * 5) + temp]->GetDeath() && !p_dropItem[(i * 5) + temp]->GetAlive()) p_dropItem[(i * 5) + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				else continue;
				if (!p_dropItem[(i * 5) + 1 + temp]->GetDeath() && !p_dropItem[(i * 5) + 1 + temp]->GetAlive()) p_dropItem[(i * 5) + 1 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 2 + temp]->GetDeath() && !p_dropItem[(i * 5) + 2 + temp]->GetAlive()) p_dropItem[(i * 5) + 2 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 3 + temp]->GetDeath() && !p_dropItem[(i * 5) + 3 + temp]->GetAlive()) p_dropItem[(i * 5) + 3 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 4 + temp]->GetDeath() && !p_dropItem[(i * 5) + 4 + temp]->GetAlive()) p_dropItem[(i * 5) + 4 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				continue;
			}


			p_enemyCrayonHuman[i]->Process();		// クレヨンヒューマンのプロセス

			
			// 死んでいたら
			if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


			// ロックオン対象がスライムだったら
			if (lockOnEnemySlime)
			{
				// 現在のロックオン対象より近かったら
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()))
				{
					// ロックオン対象を更新する
					lockOnEnemySlime = false;
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemyCrayonHuman[i]->GetArea());
					lockONNowEnemyID = i;


					// 更新した対象がプレイヤーの視認内だったら
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemyCrayonHuman[i]->GetArea());
					}
					// 更新した対象がプレイヤーの視認外だったら
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}
			// ロックオン対象がクレヨンヒューマンだったら
			else
			{
				// 現在のロックオン対象より近かったら
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()))
				{
					// ロックオン対象を更新する
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemyCrayonHuman[i]->GetArea());
					lockONNowEnemyID = i;


					// 更新した対象がプレイヤーの視認内だったら
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemyCrayonHuman[i]->GetArea());
					}
					// 更新した対象がプレイヤーの視認外だったら
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}


			// プレイヤーの位置と距離を取得する
			p_enemyCrayonHuman[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()));


			// プレイヤーに対して攻撃出来たら
			if (p_enemyCrayonHuman[i]->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemyCrayonHuman[i]->GetArea().y + p_enemyCrayonHuman[i]->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyCrayonHuman[i]->GetArea().y)
			{
				// 戦闘BGMじゃなかったら
				if (!nowBattleBGM)
				{
					// 戦闘BGMに切り替える
					nowBattleBGM = true;
					SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
				}


				// プレイヤーを攻撃している個体数が2以下だったら
				if (charaSomeEnemyDamageCount++ < 2)
				{
					// 攻撃SEを流す
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemyCrayonHuman[i]->GetArea(), 180);


					p_character->SetDamage();		// プレイヤーにダメージを与える


					// ダメージを受けていないカウントが0じゃなかったら
					if(notDamageCount != 0) notDamageCount = 0;


					// ダメージ数値が100以下だったら
					if (damageCount < 100)	damageCount++;


					// ダメージ演出画像が出ていなかったら
					if (damageDrawFrame == 0)
					{
						std::random_device rnd;     // 非決定的な乱数生成器を生成
						std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
						std::uniform_int_distribution<> blood(0, 2);        // X座標用乱数
						damageDrawID = blood(mt);		// ランダムでダメージ画像を表示する
						damageDrawFrame = 10;			// 10フレームだけ表示するようにする
					}
				}
			}
		} /// for (int i = 0; i != enemyCrayonHumanNum; ++i)
		/// クレヨンヒューマンのプロセスに関する--------------------------------------------------------------------------------------------------------------------


		BaseMove::ShadowArea(p_character->GetArea());		// シャドウマップの位置を更新する


		AttackProcess();		// 当たり判定処理


		BaseMove::SkyBoxProcess(p_character->GetArea());	// スカイボックスの位置を更新する


		// 次のシーンへ移行する場所に居たら
		if (p_character->GetArea().y >= 3550.0f)
		{
			BASICPARAM::endFeedNow = true;
			BaseMove::SetScene(ESceneNumber::FOURTHLOAD);
		}
	} /// if (!changeAdjustmentScene)
	// 精密機械のシーンだったら
	else
	{
		// 精密機械への移行シーンだったら
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
		// 精密機械からの移行シーンだったら
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


		// 精密機械のフェード中じゃなかったら
		if (!adjustmentFeedNow)
		{
			AdjustmentProcess();
		}
	} /// else(!if (!changeAdjustmentScene))


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FOURTHLOAD);
	}
#endif
} /// void MainMove3::Process()


// カメラの再セットアップ
void MainMove3::CameraProcess()
{
	p_camera->SetUp();
}


// テクスチャの再読み込み
void MainMove3::TextureReload()
{
	// キャラクターのテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// ダメージ演出
		DamageTextureReload();

		// キャラクター
		p_character->TextureReload();
	}
	

	// その他のテクスチャが白黒指定じゃなかったら
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// 精密機械
		p_adjustmentMachine->TextureReload();
	}


	// 階段のテクスチャが白黒指定じゃなかったら
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


	// 街灯のテクスチャが白黒指定じゃなかったら
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


	// 階段と床のテクスチャが白黒指定じゃなかったら
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


	// 敵スライム
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag()) continue;
		p_enemySlime[i]->TextureReload();
	}


	// 敵クレヨンヒューマン
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;
		p_enemyCrayonHuman[i]->TextureReload();
	}


	// ドロップアイテムのテクスチャが白黒指定じゃなかったら
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->TextureReload();
	}
} /// void MainMove3::TextureReload()


// オプション画面モデルの描画
void MainMove3::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// オプション画面モデルの描画の準備
void MainMove3::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// オプション画面モデルの描画の後処理
void MainMove3::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
