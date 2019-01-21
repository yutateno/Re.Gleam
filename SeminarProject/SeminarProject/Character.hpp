#pragma once
#include "BasicCreature.hpp"


class Character : public BasicCreature
{
private:
	/// それぞれの位置に関して----------------------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;


	/// モーションに関して--------------------------------
	enum MOTION { run, idle, walk };


	/// 動きに関して--------------------------------------

	// 動きの向き
	enum DIRECTION { left, down, right, up };

	// 向いているかどうか
	bool m_direction[4];

	// 動きのプロセス
	void MoveProcess();

	// 操作のプロセス
	void OpeProcess();


	/// テクスチャに関して--------------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;


public:
	// コンストラクタ
	Character(const int modelHandle, const int collStageHandle
		, const int tex0, const int tex1, const int tex2, const int tex3);

	// デストラクタ
	~Character();


	// 描画
	void Draw();

	// プロセス
	void Process(const float getAngle);


	// 位置を初期化
	void PositionReset() { area = VGet(0.0f, 0.0f, 0.0f); }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override;
};