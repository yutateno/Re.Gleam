#pragma once
#include "BasicObject.hpp"

#include <random>

class DropItemMove2 : public BasicObject
{
private:
	// テクスチャ
	int textureHandle;

	// 回転用変数
	int rotationY;

	// 死んだかどうか
	bool deathNow;

	// 存在を許されたかどうか
	bool aliveNow;

	// 飛び散るフレーム
	int flyAroundFrame;

	// 飛び散った先の座標
	float nextAreaX;
	float nextAreaZ;

public:
	DropItemMove2(const int draw, VECTOR area, const int tex0);
	~DropItemMove2();


	// 描画
	void Draw();

	// プロセス
	void Process();

	// キャラクターが近づいたら
	void StolenChara(const VECTOR characterArea);

	// テクスチャ切り替え
	void TextureReload();

	// 存在を一生消す
	void SetDeath(bool death) { deathNow = death; }

	// 存在を許されたかどうか
	void SetAlive(bool alive) { aliveNow = alive; }

	// 存在を一生消しているかどうか渡す
	const bool GetDeath() { return deathNow; }

	// 存在を許されてないかどうか渡す
	const bool GetAlive() { return aliveNow; }

	// 目的の座標に達したことでキャラクターが手に入れられるかどうか
	const bool GetCanCatch() { return flyAroundFrame >= 120 ? true : false; }
};

