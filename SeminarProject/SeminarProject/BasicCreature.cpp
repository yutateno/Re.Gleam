#include "BasicCreature.hpp"

// 使うアニメーション管理
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
		// 今のモーションを入れる
		preAttach = attachMotion;
		preMotionPlayTime = nowPlayTime;

		// 引数を今のモーション番号に入れる
		attachNum = attach;

		// 新たに指定のモーションをモデルにアタッチする
		attachMotion = MV1AttachAnim(modelHandle, attachNum, -1, false);

		// 動作時間を初期化する
		nowPlayTime = 0.0f;

		// ブレンド率は直前のモーションが有効ではない場合は１．０ｆ( 再生中のモーション１が１００％の状態 )にする
		if (preMotionPlayTime == -1)
		{
			motionBlendTime = 1.0f;
		}
		else
		{
			motionBlendTime = 0.0f;
		}
	}
}

// 全てのアニメーションの管理
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
}


// ステージのあたり判定処理
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
					wallPoly[wallNum] = &m_hitDim.Dim[i];		// ヒットしたポリゴン情報を保存
					wallNum++;
				}
			}
		}
		else
		{
			// 最大になるまで保存
			if (floorNum < 64)
			{
				floorPoly[floorNum] = &m_hitDim.Dim[i];		// ヒットしたポリゴン情報を保存
				floorNum++;
			}
		}
	}

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

		if (!jumpUpNow)
		{
			hitFlag = false;		// 当たってないとする

			maxYHit = 0.0f;			// 初期化する

			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// 今調べるポリゴン情報を渡す

				if (jumpNow)
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f)), VAdd(area, VGet(0.0f, -5.0f, 0.0f)), mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}
				else
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f)), VAdd(area, VGet(0.0f, -20.0f, 0.0f)), mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}

				// 当たってなかったら何もしない
				if (!lineResult.HitFlag)
				{
					continue;
				}

				// 既に当たったポリゴンがあって今まで検出したものより低かったら何もしない
				if (hitFlag && maxYHit > lineResult.Position.y)
				{
					continue;
				}

				// 接触したY座標を保持する
				maxYHit = lineResult.Position.y;
				hitFlag = true;
			}

			// 床に当たったかどうかで処理
			if (hitFlag)
			{
				area.y = maxYHit;

				fallCount = 0;

				jumpNow = false;
			}
		}
		else
		{
			minYHit = 0.0f;

			hitFlag = false;

			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// 今調べるポリゴン情報を渡す

				lineResult = HitCheck_Line_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);

				// 当たってなかったら何もしない
				if (!lineResult.HitFlag)
				{
					continue;
				}

				// 既に当たったポリゴンがあって今まで検出したものより低かったら何もしない
				if (hitFlag && minYHit < lineResult.Position.y)
				{
					continue;
				}

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
		}
	}
	//else	// 床に触れていない
	//{
	//	area.y -= 0.75f;
	//}

	// 壁判定
	if (wallNum != 0)
	{
		hitFlag = false;	// 壁には当たってないとする

		// 移動しているかどうかで判断を変える
		if (moveFlag)
		{
			for (int i = 0; i != wallNum; ++i)
			{
				int j;		// 判定をするためループ外で宣言

				mainPoly = wallPoly[i];			// 今の調べるポリゴン情報を渡す

				// 当たっているかどうかを調べる
				if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f)), VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == false)
				{
					continue;			// 当たっていないので次！
				}

				hitFlag = true;			// 当たっているとする

				// 移動しているので次の座標で当たっていないか判定
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];			// 今の調べるポリゴン情報を渡す

					// 当たっているかどうかを調べる
					if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f)), VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == TRUE)
					{
						jumpUpNow = false;
						break;			// 当たっていたので抜ける
					}
				}

				// 移動先で当たらなかったので判定を消す
				if (j == wallNum)
				{
					hitFlag = false;
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i != wallNum; ++i)
			{
				mainPoly = wallPoly[i];			// 今の調べるポリゴン情報を渡す

				// 当たっているかどうかを調べる
				if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == TRUE)
				{
					hitFlag = true;
					break;			// 当たっていたので抜ける
				}
			}
		}

		// 当たっていたので押し出す
		if (hitFlag)
		{
			int j, k;
			// 判定数を32とする
			for (int i = 0; i != 64; ++i)
			{
				// 壁ポリゴンの数だけ繰り返し
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];

					// 当たっているかどうかを調べる
					if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == false)
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
						if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == TRUE)
						{
							break;
						}
					}

					// 全てのポリゴンと当たっていなかったので抜ける
					if (k == wallNum)
					{
						break;
					}
				}

				// 判定を調べる前に全てのポリゴンと当たっていなかったので抜ける
				if (j != wallNum)
				{
					break;
				}
			}
		}
	}

	// 検出した情報を解放する
	MV1CollResultPolyDimTerminate(m_hitDim);

	return true;
}


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

	fallCount = 0;

	angle = 0.0f;

	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;


	// 初期化
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
}

// コンストラクタ
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

	fallCount = 0;

	angle = 0.0f;

	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;


	// 初期化
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
}

// デストラクタ
BasicCreature::~BasicCreature()
{
}


void BasicCreature::SetAreaReturn()
{
	area = preArea;
}


void BasicCreature::HitCircleReturn(VECTOR hitOneArea, float width)
{
	//VECTOR v01, v02, outv;

	//// 頂点０から頂点１へのベクトルを算出
	//v01 = VGet(hitOneArea.x + (hitOneArea.x - area.x) - hitOneArea.x, hitTwoArea.y / 2.0f - hitOneArea.y, hitOneArea.z - (hitOneArea.z - area.z) - hitOneArea.z);

	//// 頂点０から頂点２へのベクトルを算出
	//v02 = VGet(hitOneArea.x - (hitOneArea.x - area.x) - hitOneArea.x, hitTwoArea.y / 2.0f - hitOneArea.y, hitOneArea.z + (hitOneArea.z - area.z) - hitOneArea.z);

	//// 二つのベクトルの外積を計算( 二つのベクトルに垂直なベクトルの算出 )
	//// outv.x = v01.y * v02.z - v01.z * v02.y ;
	//// outv.y = v01.z * v02.x - v01.x * v02.z ;
	//// outv.z = v01.x * v02.y - v01.y * v02.x ;
	//outv = VCross(v01, v02);

	//// 外積の値が長さ１とは限らないので、正規化( 長さを１にする )、これが法線です
	//// float r = sqrt( outv.x * outv.x + outv.y * outv.y + outv.z * outv.z ) ;
	//// outv.x /= r ;
	//// outv.y /= r ;
	//// outv.z /= r ;
	//outv = VNorm(outv);

	////printfDx("%f\t%f\t%f\n", outv.x, outv.y, outv.z);

	//VECTOR slideVec = VCross(VSub(area, preArea), outv);
	//slideVec = VCross(outv, slideVec);
	//area = VAdd(preArea, slideVec);

	// 当たっていたら ch が chk から離れる処理をする

	VECTOR ChkChToChVec;
	float Length;
	VECTOR PushVec;

		// chk_ch から ch へのベクトルを算出
	ChkChToChVec = VSub(area, hitOneArea);

	// Ｙ軸は見ない
	ChkChToChVec.y = 0.0f;

	// 二人の距離を算出
	Length = VSize(ChkChToChVec);

	// chk_ch から ch へのベクトルを正規化( ベクトルの長さを 1.0f にする )
	PushVec = VScale(ChkChToChVec, 1.0f / Length);

	// 押し出す距離を算出、もし二人の距離から二人の大きさを引いた値に押し出し力を足して離れてしまう場合は、ぴったりくっつく距離に移動する
	if (Length - width < 0)
	{
		float TempY;

		TempY = area.y;
		area = VAdd(hitOneArea, VScale(PushVec, width));

		// Ｙ座標は変化させない
		area.y = TempY;
	}
	//else
	//{
	//	// 押し出し
	//	area = VAdd(area, VScale(PushVec, power));
	//}
	//area = VSub(area, tempArea);
}


void BasicCreature::HitLineReturn(VECTOR hitOneArea, VECTOR hitTwoArea)
{
	MV1_COLL_RESULT_POLY HitPoly;

	MV1RefreshCollInfo(modelHandle, -1);

	HitPoly = MV1CollCheck_Line(modelHandle, -1, hitOneArea, hitTwoArea);
	
	// 当たったかどうかで処理を分岐
	if (HitPoly.HitFlag == 1 && !damageHit)
	{
		damageHit = true;
	}
}
