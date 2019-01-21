#pragma once
#include "BasicObject.hpp"
#include <random>


/*
ムーブ２で出てくるドロップアイテムのクラス
*/
class DropItemMove2 : public BasicObject
{
private:
	// 回転用変数
	int rotationY;

	// 死んだかどうか
	bool deathNow;

	// 存在を許されたかどうか
	bool aliveNow;

	// 飛び散るフレーム
	int flyAroundFrame;

	// 飛び散った先の座標
	float nextAreaX, nextAreaZ, moveAreaY;

	// 乱数値
	std::random_device rnd;


public:
	// コンストラクタ
	DropItemMove2(const int draw, VECTOR area, const int tex0);

	// デストラクタ
	~DropItemMove2();


	// プロセス
	void Process();


	// 引数の座標に近づく
	void ChaseActor(const VECTOR chaseArea);

	// 存在を一生消す
	void SetDeath(bool death) { deathNow = death; }

	// 存在を許されたかどうか
	void SetAlive(bool alive) { aliveNow = alive; }

	// 存在を一生消しているかどうか渡す
	const bool GetDeath() { return deathNow; }

	// 存在を許されてないかどうか渡す
	const bool GetAlive() { return aliveNow; }

	// 目的の座標に達したことでキャラクターが手に入れられるかどうか
	const bool GetCanCatch() { return flyAroundFrame >= 60 ? true : false; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

