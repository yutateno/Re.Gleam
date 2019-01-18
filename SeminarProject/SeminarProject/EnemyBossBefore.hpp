#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyBossBefore : public BasicCreature
{
public:
	// コンストラクタ
	EnemyBossBefore();

	// デストラクタ
	~EnemyBossBefore();


	// プロセス
	void Process();

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};
