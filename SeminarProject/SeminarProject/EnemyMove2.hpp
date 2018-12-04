#pragma once
#include "BasicCreature.hpp"


class EnemyMove2 : public BasicCreature
{
private:
	// テクスチャ
	int textureHandle;


public:
	// コンストラクタ
	EnemyMove2(const int collStageHandle, const VECTOR area, const int modelHandle);

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

