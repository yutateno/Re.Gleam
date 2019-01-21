#include "CharacterSword.hpp"



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::MoveProcess()
{
	// 動いていたら
	if (moveFlag)
	{
		// ジャンプをしていなかったら
		if (!jumpNow)
		{
			// モーション速度が通常より早かったら下げる
			if (animSpeed > 0.75f)
			{
				animSpeed -= 0.02f;
			}
			// モーション速度が通常だったら
			else
			{
				animSpeed = 0.75f;
			}


			// 移動速度が通常より遅かったら上げる
			if (walkSpeed < maxWalkSpeedNormal - 1.0f)
			{
				walkSpeed += 5.0f;
			}
			// 移動速度が通常より早かったら下げる
			else if (walkSpeed > maxWalkSpeedNormal + 1.0f)
			{
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
			}
			// 移動速度が通常だったら
			else
			{
				walkSpeed = maxWalkSpeedNormal;
				modelWidth = 50.0f;
			}


			// 飛んでいるカウントが10以下だったら0にする
			if (flyCount <= 10) flyCount = 0;

			
			underWalkCount++;			// 地面を歩いているカウントを加算する
		} /// if (!jumpNow)
		// 飛んでいたら
		else
		{
			// モーション速度が早かったら下げる
			if (animSpeed > 1.0f)
			{
				animSpeed -= 0.02f;
			}
			// モーション速度が通常だったら
			else
			{
				animSpeed = 1.0f;
			}


			// 移動速度が遅かったら
			if (walkSpeed < maxWalkSpeedFly - 1.0f)
			{
				walkSpeed += 5.0f;
			}
			// 移動速度が早かったら
			else if (walkSpeed > maxWalkSpeedFly + 1.0f)
			{
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
			}
			// 移動速度が通常だったら
			else
			{
				walkSpeed = maxWalkSpeedFly;
				modelWidth = 50.0f;
			}
		} /// else(!if (!jumpNow))
	} /// if (moveFlag)
	// 動いていなかったら
	else
	{
		animSpeed = 0.5f;		// モーション速度を決める


		// ゆっくり止まるように処理
		if (walkSpeed > 0.0f)
		{
			walkSpeed -= 5.0f;
		}
		else
		{
			underWalkCount = 0;
			walkSpeed = 0.0f;
		}
	}


	// 瞬間移動の待機時間が0じゃなかったら減らす
	if (moveFastWaitCount > 0)
	{
		moveFastWaitCount--;
	}


	// ジャンプしていなくて瞬間移動の待機時間が残っていたら消す
	if (!jumpNow && moveFastWaitCount > maxFastMoveWaitCount)
	{
		moveFastWaitCount = 0;
	}


	// 移動速度が通常で最大のときにRBを押したら移動を早くする
	if (((walkSpeed >= maxWalkSpeedNormal - 1.0f && walkSpeed <= maxWalkSpeedNormal + 1.0f)
		|| (jumpNow && walkSpeed >= maxWalkSpeedFly - 1.0f && walkSpeed <= maxWalkSpeedFly + 1.0f))
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
		&& moveFastWaitCount == 0)
	{
		// ジャンプしていたら
		if (jumpNow)
		{
			jumpPower = 0.0f;
			jumpUpNow = false;
			moveFastWaitCount = maxFastMoveWaitCount * 3;		// ジャンプ中に二回以上させないために多めにとる
			walkSpeed = maxWalkSpeedFlyFast;
			modelWidth = maxWalkSpeedFlyFast * 1.5f;;
		}
		// ジャンプしていなかったら
		else
		{
			moveFastWaitCount = maxFastMoveWaitCount;
			walkSpeed = maxWalkSpeedFast;
			modelWidth = maxWalkSpeedFast * 1.5f;
		}


		// 残像のため
		blendCount = 140;
		animSpeed = 1.0f;
	}


	// 操作のプロセスを呼ぶ
	OpeProcess();


	/// 操作に対する向きと動き---------------------------------------------------------------------------------------
	// 左に移動するフラッグが立っていたら
	if (m_direction[static_cast<int>(DIRECTION::left)])
	{
		// 左下に移動するフラッグが立っていたら
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// 左上に移動するフラッグが立っていたら
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// 真左に移動するとき
		else
		{
			area.x += cosf(-angle) * walkSpeed;
			area.z += sinf(-angle) * walkSpeed;
		}
	}
	// 右に移動するフラッグが立っていたら
	if (m_direction[static_cast<int>(DIRECTION::right)])
	{
		// 右下に移動するフラッグが立っていたら
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// 右上に移動するフラッグが立っていたら
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// 真右に移動するとき
		else
		{
			area.x += cosf(-angle) * -walkSpeed;
			area.z += sinf(-angle) * -walkSpeed;
		}
	}
	// 左右どちらにも移動しないとき
	if (!m_direction[static_cast<int>(DIRECTION::right)] && !m_direction[static_cast<int>(DIRECTION::left)])
	{
		// 下に移動するとき
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed;
			area.z += cosf(angle + direXAngle) * walkSpeed;
		}
		// 上に移動するとき
		if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;
		}
	}
	/// 操作に対する向きと動き---------------------------------------------------------------------------------------
} /// void CharacterSword::MoveProcess()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::OpeProcess()
{
	// 左スティックが前に押されたら前進する
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		m_direction[DIRECTION::up] = true;
		direXAngle = 0.0f;
		direZAngle = 0.0f;
		moveFlag = true;
	}
	// 左スティックが前に押されていなかったら
	else
	{
		m_direction[DIRECTION::up] = false;
	}


	// 左スティックが後ろに押されたら後退する
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y))
	{
		m_direction[DIRECTION::down] = true;
		direXAngle = 0.0f;
		direZAngle = DX_PI_F;
		moveFlag = true;
	}
	// 左スティックが後ろに押されていなかったら
	else
	{
		m_direction[DIRECTION::down] = false;
	}


	// 左スティックが左に押されたら左に移動する
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X))
	{
		m_direction[DIRECTION::left] = true;
		m_direction[DIRECTION::right] = false;
		// スティックの傾きで微調整
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber()
			, DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, false);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
	}
	// 左スティックが右に押されたら右に移動する
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = true;
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber()
			, DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, true);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
	}
	// 左スティックが左右どちらにも押されていなかったら
	else
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = false;
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) == 0)
		{
			moveFlag = false;
		}
	}
} /// void CharacterSword::OpeProcess()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::AttackProcess()
{
	// 攻撃のコマンドを押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		// 最初の攻撃のとき
		if (attackFrame == 0)
		{
			// ジャンプをしていたら
			if (jumpNow)
			{
				// ジャンプ攻撃をしていなかったら
				if (!jumpAttackDo)
				{
					jumpPower = 0.0f;
					jumpUpNow = false;
					attackNumber = MOTION::skyAction1;
					jumpAttackDo = true;
				}
				// ジャンプ攻撃をしていなかったら
				else
				{
					// 疑似空中浮遊んあるので二度以上ジャンプで攻撃を始めさせない
					return;
				}
			}
			// ジャンプをしていなかったら
			else
			{
				attackNumber = MOTION::action1;
			}
			animSpeed = 0.4f;				// アニメーション速度を変更


			// 移動プロセスから流用して前方に移動させる
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;


			attackNow = true;				// 攻撃しているフラッグを立てる
		} /// if (attackFrame == 0)
		// 二回目以降の攻撃時
		else if (attackFrame < 10.0f)
		{
			attackNext = true;				// 次の攻撃モーションに移行するというフラッグを立てる
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)


	// 攻撃が終了してジャンプしていなかったらジャンプ攻撃の始動を許す
	if (attackFrame == 0 && !jumpNow) jumpAttackDo = false;


	// 攻撃をしたら
	if (attackNow)
	{
		attackMotionEnd = false;		// 攻撃モーション終了フラッグを下す


		// 攻撃の最大速度まで移動速度を上げる処理
		if (walkSpeed < maxWalkSpeedAttack)
		{
			walkSpeed += 20.0f;
		}
		else
		{
			walkSpeed = maxWalkSpeedAttack;
		}

		// 攻撃フレームがアニメーションよりも小さかったら(攻撃中に体の向きを変えさせないため
		if (attackFrame < animSpeed)
		{
			// 攻撃はじめだけ体の向きを変えさせる
			OpeProcess();


			// 敵が近くにいて動いていない状態(スティックを動かしていない)だったら
			if (!moveFlag && !(mostNearEnemyArea.y >= -1001.0f && mostNearEnemyArea.y <= -999.0f))
			{
				// 敵の方に向くようにする
				mostNearEnemyDire = atan2(VSub(area, mostNearEnemyArea).x, VSub(area, mostNearEnemyArea).z);
				direXAngle = mostNearEnemyDire;
				direZAngle = 0.0f;
				angle = 0.0f;
			}
		} /// if (attackFrame < animSpeed)
		attackFrame += animSpeed;
	} /// if (attackNow)


	// 攻撃モーションの終盤当たりで次の行動を決める
	if (attackFrame >= 9.0f)
	{
		attackMotionEnd = true;		// 攻撃のモーションが終了したフラッグをひとまず立てる


		// 次の攻撃へ移行するとフラッグが立っていたら
		if (attackNext)
		{
			// 直前の攻撃モーションで次のモーションを決める
			switch (preAttackNumber)
			{
			// 最初の攻撃時
			case MOTION::action1:
				animSpeed = 0.4f;						// アニメーション速度を変更
				attackNumber = MOTION::action2;
				preAttackNumber = attackNumber;
				break;


			// 二コンボ目の攻撃時
			case MOTION::action2:
				animSpeed = 0.4f;						// アニメーション速度を変更
				attackNumber = MOTION::action3;
				preAttackNumber = attackNumber;
				break;


			// 最後の攻撃時
			case MOTION::action3:
				attackNow = false;						// 次のコンボがないので攻撃フラッグを倒す
				attackNumber = MOTION::action1;
				preAttackNumber = attackNumber;
				walkSpeed = 0.0f;
				break;


			// ジャンプ中の最初の攻撃時
			case MOTION::skyAction1:
				animSpeed = 0.4f;
				attackNumber = MOTION::skyAction2;
				preAttackNumber = attackNumber;
				break;


			// ジャンプ中の二コンボ目の攻撃時
			case MOTION::skyAction2:
				animSpeed = 0.4f;
				attackNumber = MOTION::skyAction3;
				preAttackNumber = attackNumber;
				break;


			// ジャンプ中の最後の攻撃時
			case MOTION::skyAction3:
				attackNow = false;						// 次のコンボがないので攻撃を終了させる
				attackNumber = MOTION::action1;
				preAttackNumber = attackNumber;
				walkSpeed = 0.0f;
				break;


			default:
				break;
			}


			attackFrame = 0;		// 攻撃のフレームを消す
			attackNext = false;		// 次の攻撃するかどうかを倒す


			// 前方に移動する
			area.x += sinf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));
			area.z += cosf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));
		} /// if (attackNext)
		// 次の攻撃をしない
		else
		{
			walkSpeed = 0.0f;
			attackNow = false;					// 攻撃フラッグを倒す
			attackFrame = 0;
			attackNumber = MOTION::action1;
			preAttackNumber = attackNumber;
		}
	} /// if (attackFrame >= 9.0f)
} /// void CharacterSword::AttackProcess()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::JumpProcess()
{
	// ジャンプ攻撃中だったらやらない
	if (attackNow && jumpNow) return;


	// 浮いてない状態でジャンプするコマンドを押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1
		&& !jumpNow)
	{
		jumpNow = true;					// 飛んでいる
		jumpUpNow = true;				// 上に上がっている
		jumpPower = flyJumpPower;		// 飛ぶ速度を加える
	}


	// 足元に何もなかったら
	if (fallCount > 1)
	{
		// 飛ぶコマンドで飛んでいなかったら落下させる
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}


	// 飛んでいる
	if (jumpNow)
	{
		flyCount++;
		underWalkCount = 0;
		preJumpNow = true;
		jumpPower -= gravity;			// 落下重力を加え続ける
		area.y += jumpPower;			// Y座標に加え続ける
		
		
		// ジャンプにて最頂点に到達したら
		if (jumpPower <= flyJumpPower / 2.0f) jumpUpNow = false;			// 落下に切り替える


		// 落下させる
		area.y -= 10.5f;
	} /// if (jumpNow)


	// 着地したら
	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;
	}


	// 微妙な誤差からオブジェクトに乗っていると判断するが実際は空中を歩いていたとき
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// 飛んでいなかったら
		if (!jumpNow)
		{
			jumpNow = true;				// 飛んでいる

			jumpPower = fallJumpPower;	// 落下速度を加える
		}
	}
} /// void CharacterSword::JumpProcess()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::AnimProcess()
{
	// 飛んでいるとき
	if (jumpNow)
	{
		// 攻撃しているとき
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		// 攻撃していないとき
		else
		{
			// 上昇しているとき
			if (jumpUpNow)
			{
				Player_PlayAnim(MOTION::jump);
			}
			// 落下しているとき
			else
			{
				Player_PlayAnim(MOTION::fall);
			}
		}
	} /// if (jumpNow)
	// 飛んでいないとき
	else
	{
		// 攻撃している
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		// 攻撃していないとき
		else
		{
			// ダメージを受けているとき
			if (damageFlag)
			{
				Player_PlayAnim(MOTION::damage);
				damageFlag = false;
			}
			// ダメージを受けていないとき
			else
			{
				// 歩いているとき
				if (moveFlag)
				{
					Player_PlayAnim(MOTION::dash);
				}
				// 止まっているとき
				else
				{
					Player_PlayAnim(MOTION::idle);
				}
			}
		}
	} /// else(1if (jumpNow))
} /// void CharacterSword::AnimProcess()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::SEProcess()
{
	SoundProcess::SetCharaArea(area);		// 3Dサウンドのプレイヤーの位置を更新


	// 動いていたら
	if (moveFlag && !jumpNow)
	{
		// 左足が地面に着く位置に来たら
		if (leftFootArea <= MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y + 1.0f
			&& leftFootArea >= MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y - 1.0f)
		{
			// 歩いているカウントを2にする
			underWalkCount = 2;


			// y座標が10以上、つまりオブジェクトの上にいたら
			if (area.y >= 10.0f)
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
			}
			// 平地にいたら
			else
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
			}
		}


		// 地面を歩き始めた時
		if (underWalkCount == 1)
		{
			// 左足の位置を取得
			leftFootArea = MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y;


			// y座標が10以上、つまりオブジェクトの上にいたら
			if (area.y >= 10.0f)
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
			}
			// 平地にいたら
			else
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
			}
		}


		// 歩くカウント数が0ではなく14で割り切れる数だったら
		if (underWalkCount % 14 == 0 && underWalkCount != 0)
		{
			// オブジェクトの上にいたら
			if (area.y >= 10.0f)
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
			}
			// 平地にいたら
			else
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
			}
		}
	} /// if (moveFlag)


	// 攻撃のコマンドを押したら
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1
		&& attackFrame == 0)
	{
		// 剣先で攻撃音を出す
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack1, MV1GetFramePosition(modelHandle, 67));
	}


	// 攻撃モーションの終盤当たりで次に攻撃する意思があったら
	if (attackFrame >= 9.0f && attackNext)
	{
		// 攻撃二番目の攻撃SE
		if (preAttackNumber == MOTION::action1 || preAttackNumber == MOTION::skyAction1
			|| preAttackNumber == MOTION::skyAction2)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack2, MV1GetFramePosition(modelHandle, 67));
		}
		// 攻撃三番目の攻撃SE
		else if (preAttackNumber == MOTION::action2)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack3, MV1GetFramePosition(modelHandle, 67));
		}
	}


	// ジャンプした瞬間
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1
		&& !jumpNow)
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::jump, area);
	}


	// 着地したら
	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		// プレイヤーの高さに応じてオブジェクトに乗ったと判断し音を変える
		if (area.y >= 10.0f)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing, area);
		}
		else
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing2, area);
		}
	}
} /// void CharacterSword::SEProcess()



/// ---------------------------------------------------------------------------------------------------------------
CharacterSword::CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle
	, const int paneruHandle, const int stairsRoadHandle, const int tex0, const int tex1, const int tex2
	, const int tex3, const int tex4) : BasicCreature(true)
{
	// あたり判定のステージのコリジョン情報を設定する
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.7f, 0.7f, 0.7f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(stageHandle, -1);
	MV1SetFrameVisible(stageHandle, -1, false);
	MV1RefreshCollInfo(stageHandle, -1);


	// 足元影判定用のステージのコリジョン情報を設定する
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(shadowStageHandle, -1);
	MV1SetFrameVisible(shadowStageHandle, -1, false);
	MV1RefreshCollInfo(shadowStageHandle, -1);


	// ３Ｄモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// テクスチャ適応
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle3 = -1;
	textureHandle4 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	textureHandle2 = tex2;
	textureHandle3 = tex3;
	textureHandle4 = tex4;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);
	MV1SetTextureGraphHandle(this->modelHandle, 4, textureHandle4, true);


	// ３Ｄモデルのアニメーションをアタッチする
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの基本情報
	modelHeight = 160.0f;
	modelWidth = 50.0f;
	blendCount = 0;
	moveFastWaitCount = 0;


	// モデルの向きと位置
	area = VGet(0.0f, 50.0f, 0.0f);
	preArea = area;
	preDrawArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	leftFootArea = 0.0f;
	underWalkCount = 0;
	leftUnderTouchFrame = 13;


	// 足元の影に関する
	shadowHeight = 750.0f;
	shadowSize = 50.0f;


	// それぞれの速度
	walkSpeed = 0.0f;
	animSpeed = 0.25f;
	ZeroMemory(m_direction, sizeof(m_direction));


	// 攻撃に関して
	attackNow = false;
	attackNext = false;
	attackFrame = 0;
	attackNumber = MOTION::action1;
	preAttackNumber = MOTION::action1;
	jumpAttackDo = false;
	attackMotionEnd = true;
	mostNearEnemyArea = VGet(0, -1000, 0);


	// ジャンプに関して
	jumpNow = false;
	jumpUpNow = false;
	jumpPower = 0.0f;
	gravity = 0.75f;
	flyJumpPower = 50.0f;
	fallJumpPower = 3.0f;
	preJumpNow = false;
	flyCount = 0;


	// 階段
	v_stairsHandle.clear();
	this->v_stairsHandle.push_back(MV1DuplicateModel(stairsHandle));

	
	// パネル
	this->paneruHandle[0] = MV1DuplicateModel(paneruHandle);
	MV1SetScale(this->paneruHandle[0], VGet(50.0f, 50.0f, 50.0f));

	
	// 階段と床
	v_stairsRoadHandle.clear();
	this->v_stairsRoadHandle.push_back(MV1DuplicateModel(stairsRoadHandle));


	// モデルの座標を更新
	MV1SetPosition(this->modelHandle, area);

	
	// 3Dサウンドのプレイヤーの位置を更新
	SoundProcess::SetCharaArea(area);

	
	// アクター同士のあたり判定用の処理のセットアップ
	MV1SetupCollInfo(this->modelHandle, -1);
} /// CharacterSword::CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle



/// ---------------------------------------------------------------------------------------------------------------
CharacterSword::~CharacterSword()
{
	// テクスチャを解放
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);
	

	// パネルを解放
	for (int i = 0; i != 10; ++i)
	{
		MODEL_RELEASE(paneruHandle[i]);
	}


	// 階段と床の解放
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}


	// 階段の解放
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}


	// モデルを解放
	MODEL_RELEASE(modelHandle);


	// 影用ステージハンドルの解放
	MODEL_RELEASE(shadowStageHandle);

	
	// あたり判定用ステージハンドルの解放
	MODEL_RELEASE(stageHandle);
} /// CharacterSword::~CharacterSword()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::SetStairsArea(const VECTOR stairsArea, const int num, const float angle)
{
	// 階段のコリジョン情報の設定
	if (num != 0)
	{
		v_stairsHandle.push_back(MV1DuplicateModel(v_stairsHandle[0]));
	}
	MV1SetRotationXYZ(v_stairsHandle[num], VGet(0.0f, angle, 0.0f));
	MV1SetPosition(v_stairsHandle[num], stairsArea);
	MV1SetupCollInfo(v_stairsHandle[num], -1);
	MV1SetFrameVisible(v_stairsHandle[num], -1, false);
	MV1RefreshCollInfo(v_stairsHandle[num], -1);
}



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::SetPaneruArea(const VECTOR paneruArea, const int num)
{
	// パネルのコリジョン情報の設定
	if (num != 0)
	{
		paneruHandle[num] = MV1DuplicateModel(paneruHandle[0]);
		MV1SetScale(this->paneruHandle[num], VGet(50.0f, 50.0f, 50.0f));
	}
	MV1SetPosition(paneruHandle[num], paneruArea);
	MV1SetupCollInfo(paneruHandle[num], -1);
	MV1SetFrameVisible(paneruHandle[num], -1, false);
	MV1RefreshCollInfo(paneruHandle[num], -1);
}



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::SetStairsRoadArea(const VECTOR stairsRoadArea, const int num, const float angle)
{
	// 階段と床のコリジョン情報の更新
	if (num != 0)
	{
		v_stairsRoadHandle.push_back(MV1DuplicateModel(v_stairsRoadHandle[0]));
	}
	MV1SetRotationXYZ(v_stairsRoadHandle[num], VGet(0.0f, angle, 0.0f));
	MV1SetPosition(v_stairsRoadHandle[num], stairsRoadArea);
	MV1SetupCollInfo(v_stairsRoadHandle[num], -1);
	MV1SetFrameVisible(v_stairsRoadHandle[num], -1, false);
	MV1RefreshCollInfo(v_stairsRoadHandle[num], -1);
}



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::AreaSetDown()
{
	area.y -= 2.0f;
	MV1SetPosition(modelHandle, this->area);
}



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::Process(const float getAngle)
{
	preArea = area;		// 直前の座標


	// SEのプロセス
	SEProcess();


	// 動いているもしくは攻撃しているとき
	if (moveFlag || attackNow)
	{
		angle = getAngle;	// カメラ向きのアングル
	}


	// 攻撃をしていなかったら
	if (!attackNow)
	{
		MoveProcess();		// 動きのプロセスを呼ぶ
	}


	// 攻撃のプロセス
	AttackProcess();

	
	// モーションのシステム
	Player_AnimProcess();


	// モーションのプロセス
	AnimProcess();


	// どこにもあたっていないとする
	hitDimNum = 0;


	int setCollHitNum = 0;	// どこかのオブジェクトとあたったか確認する数値


	// パネルのあたり判定
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setCollHitNum += ActorHit(paneruHandle[i]);
		}
	}


	// あたり判定が生じていなかったら
	if (setCollHitNum == 0)
	{
		// 階段と床のあたり判定
		for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
		}
	}


	// あたり判定が生じていなかったら
	if (setCollHitNum == 0)
	{
		// 階段のあたり判定
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	// ステージのあたり判定
	ActorHit(stageHandle);


	// 瞬間移動をしていないもしくは瞬間移動をしてからある一定時間経過したら(空中で平行移動をさせるため
	if (moveFastWaitCount < (maxFastMoveWaitCount * 3) - 9)
	{
		JumpProcess();		// ジャンププロセスを呼び
	}


	// 要らないけど不安なので一応
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}
	if (area.x >= 4900.0f || area.x <= -4900.0f
		|| area.z >= 4900.0f || area.z <= -4900.0f)
	{
		area = VGet(0, 0, 0);
	}


	// 動いていない状態でロックオンした敵が近くにいて攻撃したとき
	if (!moveFlag && attackNow && !(mostNearEnemyArea.y >= -1001.0f && mostNearEnemyArea.y <= -999.0f))
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f,mostNearEnemyDire, 0.0f));
	}
	// 通常の時
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	}


	// 通常の移動速度の時
	if (walkSpeed != maxWalkSpeedFast)
	{
		// 指定位置にモデルを配置
		MV1SetPosition(modelHandle, area);
	}
} /// void CharacterSword::Process(const float getAngle)



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::NotOpeProcess(const float getAngle)
{
	moveFlag = false;
	attackNow = false;
	jumpUpNow = false;


	preArea = area;		// 直前の座標


	// SEのプロセス
	SEProcess();


	// 動いているもしくは攻撃しているとき
	if (moveFlag || attackNow)
	{
		angle = getAngle;	// カメラ向きのアングル
	}


	// モーションのシステム
	Player_AnimProcess();


	// モーションのプロセス
	AnimProcess();


	// どこにもあたっていないとする
	hitDimNum = 0;


	int setCollHitNum = 0;	// どこかのオブジェクトとあたったか確認する数値


	// パネルのあたり判定
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setCollHitNum += ActorHit(paneruHandle[i]);
		}
	}


	// あたり判定が生じていなかったら
	if (setCollHitNum == 0)
	{
		// 階段と床のあたり判定
		for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
		}
	}


	// あたり判定が生じていなかったら
	if (setCollHitNum == 0)
	{
		// 階段のあたり判定
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	// ステージのあたり判定
	ActorHit(stageHandle);

	
	// ジャンプのプロセス関数の一部
	{
		// 足元に何もなかったら
		if (fallCount > 1)
		{
			// 飛ぶコマンドで飛んでいなかったら落下させる
			if (!jumpNow)
			{
				jumpNow = true;				// 飛んでいる

				jumpPower = fallJumpPower;	// 落下速度を加える
			}
		}


		// 飛んでいる
		if (jumpNow)
		{
			flyCount++;
			underWalkCount = 0;
			preJumpNow = true;
			jumpPower -= gravity;			// 落下重力を加え続ける
			area.y += jumpPower;			// Y座標に加え続ける


			// ジャンプにて最頂点に到達したら
			if (jumpPower <= flyJumpPower / 2.0f) jumpUpNow = false;			// 落下に切り替える


			// 落下させる
			area.y -= 10.5f;
		} /// if (jumpNow)


		// 着地したら
		if (!jumpNow && preJumpNow && flyCount > 10)
		{
			flyCount = 0;
			preJumpNow = false;
		}


		// 微妙な誤差からオブジェクトに乗っていると判断するが実際は空中を歩いていたとき
		if (hitDimNum == 0 && area.y >= 10.0f)
		{
			// 飛んでいなかったら
			if (!jumpNow)
			{
				jumpNow = true;				// 飛んでいる

				jumpPower = fallJumpPower;	// 落下速度を加える
			}
		}
	}


	// 指定位置にモデルを配置
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void CharacterSword::NotOpeProcess(const float getAngle)



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::OnlyCollFloorProcess(const float getAngle)
{
	preArea = area;		// 直前の座標


	// SEのプロセス
	SEProcess();


	// 動いているもしくは攻撃しているとき
	if (moveFlag || attackNow)
	{
		angle = getAngle;	// カメラ向きのアングル
	}


	// 攻撃をしていなかったら
	if (!attackNow)
	{
		MoveProcess();		// 動きのプロセスを呼ぶ
	}


	// 攻撃のプロセス
	AttackProcess();


	// モーションのシステム
	Player_AnimProcess();


	// モーションのプロセス
	AnimProcess();


	// どこにもあたっていないとする
	hitDimNum = 0;


	int setCollHitNum = 0;	// どこかのオブジェクトとあたったか確認する数値


	// パネルのあたり判定
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setCollHitNum += ActorHit(paneruHandle[i]);
		}
	}


	// ステージのあたり判定
	ActorHit(stageHandle);


	// 瞬間移動をしていないもしくは瞬間移動をしてからある一定時間経過したら(空中で平行移動をさせるため
	if (moveFastWaitCount < (maxFastMoveWaitCount * 3) - 9)
	{
		JumpProcess();		// ジャンププロセスを呼び
	}


	// 要らないけど不安なので一応
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}
	if (area.x >= 4900.0f || area.x <= -4900.0f
		|| area.z >= 4900.0f || area.z <= -4900.0f)
	{
		area = VGet(0, 0, 0);
	}


	// 動いていない状態でロックオンした敵が近くにいて攻撃したとき
	if (!moveFlag && attackNow && !(mostNearEnemyArea.y >= -1001.0f && mostNearEnemyArea.y <= -999.0f))
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, mostNearEnemyDire, 0.0f));
	}
	// 通常の時
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	}


	// 通常の移動速度の時
	if (walkSpeed != maxWalkSpeedFast)
	{
		// 指定位置にモデルを配置
		MV1SetPosition(modelHandle, area);
	}
} /// void CharacterSword::OnlyCollFloorProcess(const float getAngle)



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);
	MV1SetTextureGraphHandle(this->modelHandle, 4, textureHandle4, true);
} /// void CharacterSword::TextureReload()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::Draw()
{
	int setShadowNum = 0;		// 足の影を生成したかどうかの個数を取得する


	// 瞬間移動したときの残像が消えていなかったら
	if (blendCount != 0)
	{
		// 残像の位置を保存する
		if (moveFastWaitCount == maxFastMoveWaitCount * 3 || walkSpeed == maxWalkSpeedFast)
		{
			preDrawArea = preArea;
		}


		// ムーブ5以降の実体に関するときで実体を取り戻していなかったら、に関係していないとき
		if (!(BASICPARAM::e_nowScene >= ESceneNumber::FIFTHLOAD && !BASICPARAM::lastCharaView))
		{
			// 残像モデルの描画
			MV1SetPosition(modelHandle, preDrawArea);
			MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
			MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
			MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
			MV1SetMaterialDrawBlendMode(this->modelHandle, 3, DX_BLENDMODE_ALPHA);
			MV1SetMaterialDrawBlendMode(this->modelHandle, 4, DX_BLENDMODE_ALPHA);
			MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
			MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
			MV1SetMaterialDrawBlendParam(this->modelHandle, 2, blendCount);
			MV1SetMaterialDrawBlendParam(this->modelHandle, 3, blendCount);
			MV1SetMaterialDrawBlendParam(this->modelHandle, 4, blendCount);
			MV1DrawModel(modelHandle);
		}


		// 通常モデルの描画
		MV1SetPosition(modelHandle, area);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 3, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 4, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 2, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 3, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 4, 255);
		blendCount -= 10;
	}


	// パネルでの足影
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setShadowNum += BasicObject::ShadowFoot(paneruHandle[i]);
		}
	}


	// 足影が生成されていたら
	if (setShadowNum != 0) return;
	// 階段での足影
	for (int i = 0; i != BASICPARAM::stairsNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsHandle[i]);
	}


	// 足影が生成されていたら
	if (setShadowNum != 0) return;
	// 階段と床での足影
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsRoadHandle[i]);
	}


	// 足影が生成されていたら
	if (setShadowNum != 0) return;
	// ステージでの足影
	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if(MyDebug::characterSwordDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
			, modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
} /// void CharacterSword::Draw()



/// ---------------------------------------------------------------------------------------------------------------
void CharacterSword::OptionActorDrawAfter()
{
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
}
