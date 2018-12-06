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
	bool GetDeath() { return deathNow; }

	// 存在を許されてないかどうか渡す
	bool GetAlive() { return aliveNow; }
};

