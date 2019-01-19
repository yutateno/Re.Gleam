#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyBossBefore : public BasicCreature
{
public:
	// コンストラクタ
	EnemyBossBefore();

	// コピーコンストラクタ
	EnemyBossBefore(const int modelHandle, const int modelTex0, const int modeltex1, const int modelTex2);

	// デストラクタ
	~EnemyBossBefore();


	// プロセス
	void Process();

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};
