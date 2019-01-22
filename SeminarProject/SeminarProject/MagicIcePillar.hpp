#pragma once
#include "Basic.hpp"


/*
ラスボスが放つ氷の柱
*/
class MagicIcePillar
{
private:
	// 出現中のエフェクト
	int effectAppear;
	int playingEfAppear;

	// 攻撃時のエフェクト
	int effectAttack;
	int playingEfAttack;

	// 座標
	VECTOR area;

	// 生存フレーム
	const int aliveTime = 100;
	int nowTime;

	// 開始するかどうか
	bool playEffect;


public:
	// コンストラクタ
	MagicIcePillar();

	// デストラクタ
	~MagicIcePillar();


	// プロセス
	void Process();

	// アクティブにする
	void Active(VECTOR area);

	// アクティブ中か渡す
	const bool GetActive() const { return playEffect; }
};

