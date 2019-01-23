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

	// 横幅を渡す
	const float GetWidth() const { return 300.0f; }

	// 縦幅を渡す
	const float GetHeight() const { return 300.0f; }

	// 今の座標を渡す
	const VECTOR GetArea() const { return area; }
};

