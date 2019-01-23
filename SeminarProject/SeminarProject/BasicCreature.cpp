#include "BasicCreature.hpp"



/// -------------------------------------------------------------------------
void BasicCreature::Player_PlayAnim(int attach)
{
	// 今のモーションが違うものだったら
	if (attachNum != attach)
	{
		// 直前のモーションが有効だったらデタッチする
		if (preAttach != -1 && motionBlendTime < 1.0f)
		{
			MV1DetachAnim(modelHandle, preAttach);
			preAttach = -1;
		}


		// 今のモーションを過去とする
		preAttach = attachMotion;
		preMotionPlayTime = nowPlayTime;


		// 新しいモーションをアタッチする
		attachNum = attach;
		attachMotion = MV1AttachAnim(modelHandle, attachNum, -1, false);
		nowPlayTime = 0.0f;


		// 再生中のモーションを１００％の状態 にする
		if (preMotionPlayTime == -1)
		{
			motionBlendTime = 1.0f;
		}
		else
		{
			motionBlendTime = 0.0f;
		}
	} /// if (attachNum != attach)
} /// void BasicCreature::Player_PlayAnim(int attach)



/// -------------------------------------------------------------------------
void BasicCreature::Player_AnimProcess()
{
	// ブレンド率が１以下の場合は１に近づける
	if (motionBlendTime < 1.0)
	{
		motionBlendTime += 0.075f;
		if (motionBlendTime >= 1.0f)
		{
			motionBlendTime = 1.0f;
		}
	}


	// 再生している現在のモーションの処理
	if (attachMotion != -1)
	{
		// モーションの総時間を取得
		totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachMotion);


		// 再生時間を進める
		nowPlayTime += animSpeed;


		// 再生時間が総時間に到達していたらループさせる
		if (nowPlayTime >= totalTime)
		{
			nowPlayTime = fmodf(nowPlayTime, totalTime);
		}


		// 変更した再生時間をモデルに反映させる
		MV1SetAttachAnimTime(modelHandle, attachMotion, nowPlayTime);


		// アニメーション１のモデルに対する反映率をセット
		MV1SetAttachAnimBlendRate(modelHandle, attachMotion, motionBlendTime);
	}


	// 再生している直前のモーションの処理
	if (preAttach != -1)
	{
		// アニメーションの総時間を取得
		totalTime = MV1GetAttachAnimTotalTime(modelHandle, preAttach);


		// 再生時間を進める
		preMotionPlayTime += animSpeed;


		// 再生時間が総時間に到達していたら再生時間をループさせる
		if (preMotionPlayTime > totalTime)
		{
			preMotionPlayTime = fmodf(preMotionPlayTime, totalTime);
		}


		// 変更した再生時間をモデルに反映させる
		MV1SetAttachAnimTime(modelHandle, preAttach, preMotionPlayTime);


		// アニメーション２のモデルに対する反映率をセット
		MV1SetAttachAnimBlendRate(modelHandle, preAttach, (1.0f - motionBlendTime));
	}
} /// void BasicCreature::Player_AnimProcess()



/// -------------------------------------------------------------------------
bool BasicCreature::ActorHit(int stageHandle)
{
	// プレイヤーをカプセルとしてステージとのコリジョン情報を調べる(OBB形式)
	m_hitDim = MV1CollCheck_Capsule(stageHandle, -1, area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth);


	// ポリゴンの数を再初期化
	wallNum = 0;
	floorNum = 0;

	hitDimNum += m_hitDim.HitNum;


	// 検出された数だけ調べる
	for (int i = 0, n = m_hitDim.HitNum; i != n; ++i)
	{
		// 壁かどうか判断するため、XZ軸に垂直かどうかを法線が０に近いかどうかで調べる
		if (m_hitDim.Dim[i].Normal.y < 0.001f && m_hitDim.Dim[i].Normal.y > -0.001f)
		{
			// 壁だとしてもキャラクターの足より少し上を調べる
			if (m_hitDim.Dim[i].Position[0].y > area.y + 5.0f
				|| m_hitDim.Dim[i].Position[1].y > area.y + 5.0f
				|| m_hitDim.Dim[i].Position[2].y > area.y + 5.0f)
			{
				// 最大になるまで保存する
				if (wallNum < 64)
				{
					// ヒットしたポリゴン情報を保存
					wallPoly[wallNum] = &m_hitDim.Dim[i];
					wallNum++;
				}
			}
		}
		else
		{
			// 最大になるまで保存
			if (floorNum < 64)
			{
				// ヒットしたポリゴン情報を保存
				floorPoly[floorNum] = &m_hitDim.Dim[i];
				floorNum++;
			}
		}
	}


	// どこにもあたっていなかったら
	if (floorNum == 0 && wallNum == 0)
	{
		// 検出した情報を解放する
		MV1CollResultPolyDimTerminate(m_hitDim);

		return false;
	}


	// 床判定
	if (floorNum != 0)
	{
		fallCount++;			// 浮いているとする


		// 落下中だった
		if (!jumpUpNow)
		{
			hitFlag = false;		// 当たってないとする

			maxYHit = 0.0f;			// 初期化する


			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// 今調べるポリゴン情報を渡す


				// 飛んでいたら
				if (jumpNow)
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, -5.0f, 0.0f))
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}
				// 飛んでいなかったら
				else
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, -20.0f, 0.0f))
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}


				// 当たってなかったら何もしない
				if (lineResult.HitFlag == 0) continue;


				// 既に当たったポリゴンがあって今まで検出したものより低かったら何もしない
				if (hitFlag && maxYHit > lineResult.Position.y) continue;


				// 接触したY座標を保持する
				maxYHit = lineResult.Position.y;
				hitFlag = true;
			} /// for (int i = 0; i != floorNum; ++i)


			// 床に当たったかどうかで処理
			if (hitFlag)
			{
				// 現在地として落下の処理をやめる
				area.y = maxYHit;
				fallCount = 0;
				jumpNow = false;
			}
		} /// if (!jumpUpNow)
		// 上昇中だったら
		else
		{
			minYHit = 0.0f;

			hitFlag = false;

			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// 今調べるポリゴン情報を渡す
				lineResult = HitCheck_Line_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);


				// 当たってなかったら何もしない
				if (lineResult.HitFlag == 0) continue;


				// 既に当たったポリゴンがあって今まで検出したものより低かったら何もしない
				if (hitFlag && minYHit < lineResult.Position.y) continue;


				// 接触したY座標を保持する
				minYHit = lineResult.Position.y;
				hitFlag = true;
			}


			// 床に当たったかどうかで処理
			if (hitFlag)
			{
				area.y = minYHit - modelHeight;

				jumpPower = 0.0f;

				jumpUpNow = false;
			}
		} /// else(!if (!jumpUpNow))
	} /// if (floorNum != 0)


	// 壁判定
	if (wallNum != 0)
	{
		hitFlag = false;	// 壁には当たってないとする


		// 移動しているとき
		if (moveFlag)
		{
			for (int i = 0; i != wallNum; ++i)
			{
				int j;						// 判定をするためループ外で宣言


				mainPoly = wallPoly[i];		// 今の調べるポリゴン情報を渡す


				// 当たっているかどうかを調べる
				if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == 0)
				{
					continue;					// 当たっていないので次！
				}


				hitFlag = true;				// 当たっているとする


				// 移動しているので次の座標で当たっていないか判定
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];		// 今の調べるポリゴン情報を渡す

					// 当たっているかどうかを調べる
					if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
					{
						jumpUpNow = false;
						break;						// 当たっていたので抜ける
					}
				}


				// 移動先で当たらなかったので判定を消す
				if (j == wallNum)
				{
					hitFlag = false;
					break;
				}
			}
		} /// if (moveFlag)
		// 移動していないとき
		else
		{
			for (int i = 0; i != wallNum; ++i)
			{
				mainPoly = wallPoly[i];			// 今の調べるポリゴン情報を渡す


				// 当たっているかどうかを調べる
				if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
					, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
				{
					hitFlag = true;
					break;							// 当たっていたので抜ける
				}
			}
		}


		// 当たっていたので押し出す
		if (hitFlag)
		{
			int j, k;


			// 判定数だけ調べる
			for (int i = 0; i != 64; ++i)
			{
				// 壁ポリゴンの数だけ繰り返し
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];


					// 当たっているかどうかを調べる
					if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == 0)
					{
						continue;
					}


					VECTOR slideVec = VCross(VSub(area, preArea), mainPoly->Normal);
					slideVec = VCross(mainPoly->Normal, slideVec);
					area = VAdd(preArea, slideVec);


					for (k = 0; k != wallNum; ++k)
					{
						// 当たっていたらループを抜ける
						mainPoly = wallPoly[k];


						if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
							, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
						{
							break;
						}
					}

					// 全てのポリゴンと当たっていなかったので抜ける
					if (k == wallNum) break;
				} /// for (j = 0; j != wallNum; ++j)


				// 判定を調べる前に全てのポリゴンと当たっていなかったので抜ける
				if (j != wallNum) break;
			} /// for (int i = 0; i != 64; ++i)
		} /// if (hitFlag)
	} /// if (wallNum != 0)


	// 検出した情報を解放する
	MV1CollResultPolyDimTerminate(m_hitDim);
	return true;
} /// bool BasicCreature::ActorHit(int stageHandle)



/// -------------------------------------------------------------------------
BasicCreature::BasicCreature() :BasicObject()
{
	// 当たり判定に関する
	wallNum = 0;
	floorNum = 0;
	hitFlag = false;
	maxYHit = 0.0f;
	minYHit = 0.0f;
	moveFlag = false;


	// モーション関連
	nowPlayTime = 0.0f;
	motionBlendTime = 0.0f;
	preAttach = -1;
	preMotionPlayTime = 0.0f;


	// 初期化
	fallCount = 0;
	angle = 0.0f;
	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
} /// BasicCreature::BasicCreature() :BasicObject()



/// -------------------------------------------------------------------------
BasicCreature::BasicCreature(bool shadowDo) :BasicObject(shadowDo)
{
	// 当たり判定に関する
	wallNum = 0;
	floorNum = 0;
	hitFlag = false;
	maxYHit = 0.0f;
	minYHit = 0.0f;
	moveFlag = false;


	// モーション関連
	nowPlayTime = 0.0f;
	motionBlendTime = 0.0f;
	preAttach = -1;
	preMotionPlayTime = 0.0f;


	// 初期化
	fallCount = 0;
	angle = 0.0f;
	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
} /// BasicCreature::BasicCreature(bool shadowDo) :BasicObject(shadowDo)



/// -------------------------------------------------------------------------
BasicCreature::~BasicCreature()
{
}



/// -------------------------------------------------------------------------
bool BasicCreature::HitCircleReturn(VECTOR hitOneArea, float width)
{
	VECTOR subVec;
	float length;
	VECTOR pushVec;


	subVec = VSub(area, hitOneArea);				// ベクトル差を算出
	subVec.y = 0.0f;								// Ｙ軸は見ない
	length = VSize(subVec);							// 二人の距離を算出
	pushVec = VScale(subVec, 1.0f / length);		// ベクトル差を正規化


	// 二人の距離が相手の幅より小さかったら押し出す処理をする
	if (length - width < 0)
	{
		float tempY = 0.0f;
		tempY = area.y;
		area = VAdd(hitOneArea, VScale(pushVec, width));
		area.y = tempY;
		return true;
	}
	else
	{
		return false;
	}
} /// void BasicCreature::HitCircleReturn(VECTOR hitOneArea, float width)



/// -------------------------------------------------------------------------
void BasicCreature::HitLineReturn(VECTOR hitOneArea, VECTOR hitTwoArea)
{
	// コリジョン情報を更新して当たっているか調べる
	MV1_COLL_RESULT_POLY HitPoly;
	MV1RefreshCollInfo(modelHandle, -1);
	HitPoly = MV1CollCheck_Line(modelHandle, -1, hitOneArea, hitTwoArea);
	

	// 当たっていた場合
	if (HitPoly.HitFlag == 1 && !damageHit)
	{
		damageHit = true;
	}
}
