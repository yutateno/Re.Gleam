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

	// 横幅を渡す
	const float GetWidth() const { return 50.0f; }

	// 縦幅を渡す
	const float GetHeight() const { return 200.0f; }

	// 今の座標を渡す
	const VECTOR GetArea() const { return area; }
};

