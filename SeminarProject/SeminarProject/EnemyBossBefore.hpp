#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
ムーブ１からボス戦までに出てくるボスのクラス
*/
class EnemyBossBefore : public BasicCreature
{
private:
	/// 乱数値----------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	EnemyBossBefore();

	// コピーコンストラクタ
	EnemyBossBefore(const int modelHandle, const int modelTex0, const int modeltex1, const int modelTex2);

	// デストラクタ
	~EnemyBossBefore();


	// プロセス
	void Process();

	// ムーブ6にてのみ体の向きを変える
	void MoveReturn();

	// 体を地面に埋まらせる(ムーブ6のみ
	void AreaSetDown();
};
