#pragma once
#include "Basic.hpp"


/*
ラスボスが放つブロック
*/
class ChaseBlock
{
private:
	// 座標
	VECTOR area;

	// 追いかけるプレイヤーの座標
	VECTOR chaseArea;

	// 追い越してから消えるまでのフレーム
	int disappearFrame;

	// アクティブちゅうかどうか
	bool activeNow;

	// 移動速度
	VECTOR speed;


public:
	// コンストラクタ
	ChaseBlock();

	// デストラクタ
	~ChaseBlock();


	// プロセス
	void Process();

	// 描画
	void Draw();

	// アクティブにする
	void Active(VECTOR chaseArea);

	// アクティブ中華渡す
	const bool GetActive() const { return activeNow; }
};

