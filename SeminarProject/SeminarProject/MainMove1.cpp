#include "MainMove1.hpp"


/// -----------------------------------------------------------------------------------------------------
void MainMove1::ActorHit()
{
	for (int i = 0; i < enemyNum; ++i)
	{
		// 生存していたら
		if (s_lightBall[i].aliveNow)
		{
			// プレイヤーと玉が接触したら
			if (BaseMove::GetDistance<int>(p_character->GetArea()
				, s_lightBall[i].p_enemyMove->GetArea()) <= 60)
			{
				// 生きさせない
				s_lightBall[i].aliveNow = false;
				POINTER_RELEASE(s_lightBall[i].p_enemyMove);
				catchEnemyNum++;


				// 音を流すタイミングがここなのでここで音周り呼ぶ
				MoveSoundProcess();
				

				/// 操作説明に関する-----------------------------
				if (catchEnemyNum == 1)
				{
					// ブレンドが200になるようにする
					nextExplanationDrawFeed = 200;
				}
				else if (catchEnemyNum == 2)
				{
					// ブレンドが150になるようにする
					nextExplanationDrawFeed = 150;
				}
				else if (catchEnemyNum == 3)
				{
					// ブレンドが50になるようにする
					nextExplanationDrawFeed = 50;
				}
				else if (catchEnemyNum == 4)
				{
					// ブレンドが0になるようにする
					nextExplanationDrawFeed = 0;
				}
			} /// if (BaseMove::GetDistance<int>(p_character->GetArea()
			// プレイヤーと玉との距離がある程度近くなったら
			else if (BaseMove::GetDistance<int>(p_character->GetArea()
				, s_lightBall[i].p_enemyMove->GetArea()) <= 300)
			{
				// 玉をプレイヤーに近づくようにする
				s_lightBall[i].p_enemyMove->NearChara(p_character->GetArea());
			}
		}
	} /// for (int i = 0; i < enemyNum; ++i)

	
	// 玉をすべて手に入れ、エンドイベントが終わってかつ剣に触れたら次のシーンに移行させる
	if (catchEnemyNum==30 && lightEventCount >= 100
		&& BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem->GetArea()) <= 60)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SECONDLOAD);
	}


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SECONDLOAD);
	}
#endif
} /// void MainMove1::ActorHit()


/// ---------------------------------------------------------------------------------------------
void MainMove1::LightProcess()
{
	// 光源の情報を更新させる
	for (int i = 0; i != lightNum; ++i)
	{
		// 光源の広さを更新
		SetLightRangeAttenHandle(lightHandle[i], lightRange[i], 0.0f, 0.002f, 0.0f);		

		// 光源の位置を更新
		SetLightPositionHandle(lightHandle[i], lightArea[i]);								
	}


	/// 玉の個数でライトの状況を変化させる命令をする-----------------------------
	if (catchEnemyNum == 1)
	{
		// ライトを一つ有効にする
		SetLightEnableHandle(lightHandle[0], TRUE);
	}
	else if (catchEnemyNum == 2)
	{
		// ライトを合計二つ有効にする
		SetLightEnableHandle(lightHandle[1], TRUE);
	}
	else if (catchEnemyNum == 3)
	{
		// ライトを合計三つ有効にする
		SetLightEnableHandle(lightHandle[2], TRUE);
	}
	else if (catchEnemyNum >= 4 && catchEnemyNum <= 5)
	{
		// イベントが何も起きていなかったら
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 7.0f;			// 光源範囲を広げるスピードを変更
			lightRangePreMax = 1000.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// イベントカウントが10以上だったら
		if (lightEventCount >= 10)
		{
			// 四つ目の光源を出す
			SetLightEnableHandle(lightHandle[3], TRUE);		
		}
	}
	else if (catchEnemyNum <= 6)
	{
		// エンドイベントフラッグが立っていたらおろさせる
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 7)
	{
		// イベントが何も起きていなかったら
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 9.0f;			// 光源範囲を広げるスピードを変更
			lightRangePreMax = 1700.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}
	}
	else if (catchEnemyNum >= 8 && catchEnemyNum <= 11)
	{
		// 前回起きるイベントが起きていなかったら
		if (!(lightRangePreMax >= 1699.9f && lightRangePreMax <= 1700.1f))
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 9.0f;			// 光源範囲を広げるスピードを変更
			lightRangePreMax = 1700.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// エンドイベントフラッグが立っていたらおろさせる
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 12)
	{
		// イベントが何も起きていなかったら
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 11.0f;		// 光源範囲を広げるスピードを変更
			lightRangePreMax = 2600.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// イベント中だったら
		if (lightEventStart)
		{
			// 背景色を明るくする
			backgroundColor = GetColor(lightEventCount, lightEventCount, lightEventCount);
		}
	}
	else if (catchEnemyNum >= 13 && catchEnemyNum <= 18)
	{
		// 前回起きるイベントが起きていなかったら
		if (!(lightRangePreMax >= 2599.9f && lightRangePreMax <= 2600.1f))
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 11.0f;		// 光源範囲を広げるスピードを変更
			lightRangePreMax = 2600.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// エンドイベントフラッグが立っていたらおろさせる
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 19)
	{
		// イベントが何も起きていなかったら
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 14.0f;		// 光源範囲を広げるスピードを変更
			lightRangePreMax = 3700.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// イベント中だったら
		if (lightEventStart)
		{
			// それぞれのZ軸の光源を広げる
			lightArea[0].z = -630.0f + lightEventCount * 5;
			lightArea[1].z = -630.0f + lightEventCount * 4;
			lightArea[2].z = -630.0f + lightEventCount * 3;
			lightArea[3].z = -630.0f + lightEventCount * 2;

			// 背景色を明るくする
			backgroundColor = GetColor(lightEventCount / 2 + 100, lightEventCount / 2 + 100, lightEventCount / 2 + 100);
		}
	}
	else if (catchEnemyNum >= 20 && catchEnemyNum <= 28)
	{
		// 前回起きるイベントが起きていなかったら
		if (!(lightRangePreMax >= 3699.9f && lightRangePreMax <= 3700.1f))
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 14.0f;		// 光源範囲を広げるスピードを変更
			lightRangePreMax = 3700.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// エンドイベントフラッグが立っていたらおろさせる
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 29)
	{
		// イベントが何も起きていなかったら
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// イベントのカウントを初期化
			lightRangeSpeed = 20.0f;		// 光源範囲を広げるスピードを変更
			lightRangePreMax = 5100.0f;		// 直前の光源範囲の最大値を変更
			lightEventStart = true;			// イベントスタートが開始されたフラッグを立てる
		}


		// イベント中だったら
		if (lightEventStart)
		{
			// 背景色を明るくする
			backgroundColor = GetColor(lightEventCount / 2 + 150, lightEventCount / 2 + 150, lightEventCount / 2 + 150);
		}
	}
	else if (catchEnemyNum == 30)
	{
		// 終了フラッグで終わらせる
		if (!lightEnd)
		{
			lightEventCount = 0;
			lightEventStart = true;
			lightEnd = true;
		}


		// イベント中だったら
		if (lightEventStart)
		{
			// 背景色を明るくする
			backgroundColor = GetColor(lightEventCount + 155, lightEventCount + 155, lightEventCount + 155);


			// フェードアウトの処理をさせてまぶしくする
			if (lightEventCount < 50)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (lightEventCount * 2));
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(255, 255, 255), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
			else		// フェードインの処理をさせて戻す
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 + ((lightEventCount - 50) * 2));
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(255, 255, 255), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
		}
	}


	// イベントを開始する
	if (lightEventStart)
	{
		lightEventCount++;		// カウントを続ける


		// 光源の明るさを広げる
		lightRange[0] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[1] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[2] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[3] = lightRangePreMax + lightEventCount * lightRangeSpeed;


		// カウントが規定以上になったら
		if (lightEventCount >= 100)
		{
			lightEventStart = false;		// イベントの開始のフラグを倒す
			lightEventEnd = true;			// イベントの終了のフラグを上げる


			// 全ての玉を手に入れたら
			if (catchEnemyNum == 30)
			{
				for (int i = 0; i != lightNum; ++i)
				{
					LIGHT_RELEASE(lightHandle[i]);			// 光源を消す
				}
				SetLightEnable(TRUE);					// 自然光源を有効にする
				p_character->PositionReset();			// キャラクターのポジションを元に戻す
			}
		}
	} /// if (lightEventStart)
} /// void MainMove1::LightProcess()


/// ---------------------------------------------------------------------------------------------
void MainMove1::MoveSoundProcess()
{
	/// 状況に応じてBGMの音量を調整----------------------------------------------------------
	switch (catchEnemyNum)
	{
	case 1:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 50, 50);
		break;
	case 2:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 100, 100);
		break;
	case 3:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 150, 150);
		break;
	case 4:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 170, 170);
		break;
	case 5:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 190, 190);
		break;
	case 6:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 210, 210);
		break;
	case 7:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 230, 230);
		break;
	case 8:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 255, 255);
		break;

	case 30:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 0, 0);
		break;
	default:
		break;
	} /// switch (++catchEnemyNum)
	/// ---------------------------------------------------------------------------------------


	/// SEの再生をランダムにする----------------------------------------------------
	std::random_device rnd;     // 非決定的な乱数生成器を生成
	std::mt19937 mt(rnd());     // メルセンヌ・ツイスタの32ビット版
	std::uniform_int_distribution<> randPawnSE(0, 1);        // 乱数


	if (randPawnSE(mt) == 0)
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
	}
	else
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawn);
	}
	/// ----------------------------------------------------------------------------

}


/// ---------------------------------------------------------------------------------------------
MainMove1::MainMove1(const std::vector<int> v_file)
{	
	// 自然光源を一切遮断
	SetLightEnable(FALSE);	
	// フォグを有効にする
	SetFogEnable(FALSE);
	// 背景色に関する
	backgroundColor = GetColor(0, 0, 0);


	// ポインタNULL初期化
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_dropItem = nullptr;
	for (int i = 0; i != enemyNum; ++i)
	{
		s_lightBall[i].p_enemyMove = nullptr;
	}


	// ムーブ説明
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 400;


	// ステージ初期化
	p_stage = new Stage(v_file[EFILE::drawStage]);	


	// キャラクター初期化
	p_character = new Character(v_file[EFILE::character], v_file[EFILE::collStage]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1]
		, v_file[EFILE::charaTex2], v_file[EFILE::charaTex3]);		
	

	// カメラ初期化
	p_camera = new Camera(p_character->GetArea());
	

	// 落ちてる剣初期化
	p_dropItem = new DropItemMove1(v_file[EFILE::sword], v_file[EFILE::swordTex0]);

	
	/// 玉生成に関する初期化---------------------------------------------------------------
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randInX(-3000, 3000);        // X座標用乱数
	std::uniform_int_distribution<> randInZ(-3000, 3000);        // Z座標用乱数
	std::uniform_int_distribution<> color(1, 100);				 // 色用の乱数
	for (int i = 0; i != enemyNum; ++i)
	{
		// 玉のX座標設定
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 400.0f && tempX >= 0.0f)
		{
			tempX += 400.0f;
		}
		if (tempX >= -400.0f && tempX <= 0.0f)
		{
			tempX -= 400.0f;
		}
		// 玉のY座標設定
		float tempZ = static_cast<float>(randInZ(mt));
		if (tempZ <= 400.0f && tempZ >= 0.0f)
		{
			tempZ += 400.0f;
		}
		if (tempZ >= -400.0f && tempZ <= 0.0f)
		{
			tempZ -= 400.0f;
		}


		// 生きてるようにする
		s_lightBall[i].aliveNow = true;
		// 玉初期化
		s_lightBall[i].p_enemyMove = new EnemyMove1(v_file[1], tempX, tempZ, color(mt) / 100.0f);
	}
	// 玉を手に入れた数を初期化
	catchEnemyNum = 0;		


	/// ライトに関する初期化--------------------------------------------
	for (int i = 0; i != lightNum; ++i)
	{
		lightHandle[i] = -1;						// ライトハンドルを初期化
		lightArea[i] = p_character->GetArea();		// ライトの位置初期化
		lightRange[i] = 1700.0f;					// ライトの範囲を初期化
		lightArea[0].y = -200.0f;					// ライトの0番目だけY座標を下に初期化
		lightArea[i].z = -630.0f;					// ライトのZ軸初期化

		// ライトを生成
		lightHandle[i] = CreatePointLightHandle(lightArea[i], lightRange[i]
			, 0.0f, 0.002f, 0.0f);

		// ライトを無効にする
		SetLightEnableHandle(lightHandle[i], FALSE);
	}
	lightEventStart = false;
	lightEventEnd = false;
	lightEventCount = 0;
	lightRangePreMax = 0.0f;
	lightRangeSpeed = 0.0f;
	lightEnd = false;

	
	/// 説明に関する初期化---------------------------------------
	//  左スティック操作の説明の初期化
	stickLeftDraw = -1;
	stickLeftDraw = v_file[EFILE::explanationLeftStick];
	// 右スティック操作の説明の初期化
	stickRightDraw = -1;
	stickRightDraw = v_file[EFILE::explanationRightStick];
	// フェードカウントの初期化
	explanationDrawFeed = 255;
	nextExplanationDrawFeed = 255;


	/// サウンドの初期化------------------------------------------------------------------------
	SoundProcess::Load(v_file[EFILE::sound]		, SoundProcess::ESOUNDNAME_BGM::titleMusicBox);
	SoundProcess::Load(v_file[EFILE::seBallHigh], SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
	SoundProcess::Load(v_file[EFILE::seBall]	, SoundProcess::ESOUNDNAME_SE::ballPawn);


	// エフェクト読み込み
	effeckBack = LoadEffekseerEffect("media\\こっち\\media\\Effect\\moveOneBack.efk");
	playingEfBack = -1;
} /// MainMove1::MainMove1(const std::vector<int> v_file)


/// ---------------------------------------------------------------------------------------------
MainMove1::~MainMove1()
{
	// エフェクト開放
	StopEffekseer2DEffect(playingEfBack);
	DeleteEffekseerEffect(effeckBack);


	// 光源開放
	for (int i = 0; i != lightNum; ++i)
	{
		LIGHT_RELEASE(lightHandle[i]);
	}


	// 敵開放
	for (int i = 0; i < enemyNum; ++i)
	{
		POINTER_RELEASE(s_lightBall[i].p_enemyMove);
	}


	// ドロップアイテム(剣)開放
	POINTER_RELEASE(p_dropItem);


	// カメラ開放
	POINTER_RELEASE(p_camera);

	
	// キャラクター開放
	POINTER_RELEASE(p_character);


	// ステージ開放
	POINTER_RELEASE(p_stage);


	// 説明画像解放
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove1::~MainMove1() /// MainMove1::~MainMove1()


/// ---------------------------------------------------------------------------------------------
void MainMove1::Draw()
{
	// 背景を描画
	DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, backgroundColor, true);


	// ステージを描画
	p_stage->Draw();					


	// キャラクターを描画
	p_character->ModelDraw();
	p_character->Draw();


	for (int i = 0; i < enemyNum; ++i)
	{
		// 玉が生存していたら
		if (s_lightBall[i].aliveNow)
		{
			// 玉を描画
			s_lightBall[i].p_enemyMove->Draw();
		}
	}


	// 玉をすべて手に入れエンドイベントが終わったら
	if (catchEnemyNum == 30 && lightEventCount >= 100)
	{
		// 剣を描画
		p_dropItem->ModelDraw();				
	}


	// 説明画像の光度が0以上だったら
	if (explanationDrawFeed >= 0)
	{
		// 最大光度から減っていたら減らすようにする
		if (explanationDrawFeed != nextExplanationDrawFeed) explanationDrawFeed--;


		/// ブレンドする----------------------------------------------
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, explanationDrawFeed);

		// 左スティック説明画像
		DrawGraph(100, 100, stickLeftDraw, true);
		// 右スティック説明画像
		DrawGraph(1200, 100, stickRightDraw, true);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}


	// エフェクトが再生されていなかったら
	if (IsEffekseer2DEffectPlaying(playingEfBack) != 0)
	{
		// エフェクトを再生する。
		playingEfBack = PlayEffekseer2DEffect(effeckBack);
		SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
	}


	// ムーブ説明をする
	if (moveDescriptionFrame-- > 0)
	{
		if(moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 196, 540 - 143, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}


#ifdef _DEBUG
	p_dropItem->Draw();
	if (MyDebug::moveOneDrawFlag)
	{
		for (int i = 0; i < enemyNum; ++i)
		{
			if (BaseMove::GetDistance<int>(p_character->GetArea(), s_lightBall[i].p_enemyMove->GetArea()) <= 500)
			{
				DrawLine3D(VAdd(p_character->GetArea(), VGet(0.0f, 80.0f, 0.0f))
					, VAdd(s_lightBall[i].p_enemyMove->GetArea(), VGet(0.0f, 60.0f, 0.0f)), GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG

} /// void MainMove1::Draw()


/// ---------------------------------------------------------------------------------------------
void MainMove1::Process()
{
	// キャラクターのプロセスを呼ぶ
	p_character->Process(p_camera->GetAngle());		


	// カメラのプロセスを呼ぶ
	p_camera->Process(p_character->GetArea());		


	for (int i = 0; i < enemyNum; ++i)
	{
		// 生きていたら
		if (s_lightBall[i].aliveNow)
		{
			// 玉のプロセスを呼ぶ
			s_lightBall[i].p_enemyMove->Process();
		}
	}


	// アクターごとのあたり判定を呼ぶ
	ActorHit();		


	// ライトのプロセスを呼ぶ
	LightProcess();		
} /// void MainMove1::Process()


/// ---------------------------------------------------------------------------------------------
void MainMove1::CameraProcess()
{
	p_camera->SetUp();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModel()
{
	p_character->OptionActorDraw();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
