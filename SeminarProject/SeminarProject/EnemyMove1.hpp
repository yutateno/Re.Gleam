#pragma once
#include "BasicCreature.hpp"


/*
ムーブ１に出てくる光の玉のクラス
*/
class EnemyMove1 : public BasicCreature
{
private:
	// 今上がり中かどうか
	bool upNow;

	// 上下のスピード
	float flyMove;

	// 上下動きのプロセス
	void MoveProcess();

	// マテリアルを調整保持
	MATERIALPARAM material;


public:
	// コンストラクタ
	EnemyMove1(const int collStageHandle, const float areaX, const float areaZ
		, const float color);

	// デストラクタ
	~EnemyMove1();


	// 描画
	void Draw();

	// プロセス
	void Process();


	// キャラクターが近づいたら
	void NearChara(const VECTOR characterArea);
};
