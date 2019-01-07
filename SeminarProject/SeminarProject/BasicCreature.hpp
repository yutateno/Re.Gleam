#pragma once
#include "BasicObject.hpp"
#include "SoundProcess.hpp"


class BasicCreature : public BasicObject
{
protected:
	/// 位置について------------------------

	// 移動前の直前のキャラ位置
	VECTOR preArea;	

	// キャラクターの向いているアングル
	float angle;	

	// 移動後の直前のキャラ位置
	VECTOR nextArea;


	/// 動きに関して------------------------------------

	// 移動スピード
	float walkSpeed;	

	// モーションスピード
	float animSpeed;	

	// 当たり判定モデル全てから落ちているかどうか
	int fallCount;		

	// 飛んでいるかどうか
	bool jumpNow;		

	// 上に飛んでいる
	bool jumpUpNow;		

	// ジャンプ力
	float jumpPower;

	// 判定する床の数
	int floorNum;


	/// モーションに関して-------------------

	// モーションのアタッチ
	int attachMotion;			

	// 現在のモーション番号
	int attachNum;				

	// モーションの総合時間
	float totalTime;			

	// モーション変更
	void Player_PlayAnim(int attach);		

	// モーション動作
	void Player_AnimProcess();				


	/// 当たり判定-----------------------------

	// ステージハンドル
	int stageHandle;

	// 影用ステージハンドル
	int shadowStageHandle;

	// 動いているかどうか
	bool moveFlag;

	// 当たり判定を行う
	bool ActorHit(int stageHandle);	

	// ポリゴン検知している数
	int hitDimNum;


	/// 攻撃を受けた時に関する-----------

	// ダメージを受けたかどうか
	bool damageHit;

	// 倒れたかどうか
	bool deathFlag;

	// 描画から消すかどうか
	bool eraseExistence;

	// 透過ブレンドのカウント
	int blendCount;


private:
	/// モーションに関して-------------

	// モーションの現在の時間
	float nowPlayTime;			

	// ブレンド時間
	float motionBlendTime;		

	// 直前のモーションアタッチ
	int preAttach;				

	// 直前のモーション時間
	float preMotionPlayTime;	


	/// 当たり判定-------------------------------------------				

	// 判定する壁の数
	int wallNum;					

	// 当たっているかどうか
	bool hitFlag;						

	// 当たっているY座標の最大
	float maxYHit;						

	// 当たっているY座標の最小
	float minYHit;						

	// 周囲のポリゴンを代入する構造体
	MV1_COLL_RESULT_POLY_DIM m_hitDim;			

	// 壁用のポリゴンの構造体
	MV1_COLL_RESULT_POLY* wallPoly[2048];		

	// 床用のポリゴンの構造体
	MV1_COLL_RESULT_POLY* floorPoly[2048];		

	// ポリゴンの構造体にアクセスする構造体
	MV1_COLL_RESULT_POLY* mainPoly;			

	// 線分との判定を代入する構造体
	HITRESULT_LINE lineResult;
	/// ----------------------------------------------------


public:
	// コンストラクタ
	BasicCreature();

	// コピーコンストラクタ
	BasicCreature(bool shadowDo);

	// デストラクタ
	virtual ~BasicCreature();


	// 直前の座標に戻す
	void SetAreaReturn();

	// 当たったら押し出すようにする
	void HitCircleReturn(VECTOR hitUnderArea, float width);

	// 武器の線分当たっているかどうか
	void HitLineReturn(VECTOR hitOneArea, VECTOR hitTwoArea);


	/// ゲッターセッター

	// 死んだかどうか
	const bool GetDeathFlag() const { return deathFlag; }

	// ダメージを受けたかどうか
	const bool GetDamageFlag() const { return damageHit; }

	// 描画から消すかどうか
	const bool GetEraseExistence() const { return eraseExistence; }
};