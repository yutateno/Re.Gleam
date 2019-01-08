#pragma once
#include "BasicCreature.hpp"


class EnemyMove2 : public BasicCreature
{
public:
	// コンストラクタ
	EnemyMove2(const VECTOR area, const int modelHandle, const int tex0);

	// デストラクタ
	~EnemyMove2();

	
	// 描画
	void Draw();

	// プロセス
	void Process();

	
	/// ゲッターセッター

	// 座標を設定する
	void SetArea(const VECTOR area) { this->area = area; }
};

