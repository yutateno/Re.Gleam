#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove5 : public BasicCreature
{
private:
	/// それぞれの位置に関して---------------------

	// 前後の向きを扱う変数
	float direZAngle;

	// 左右の向きを扱う変数
	float direXAngle;

	// 次の前後の向きを扱う変数
	float nextDireZAngle;

	// 次の左右の向きを扱う変数
	float nextDireXAngle;

	// キャラクターの位置
	VECTOR playerCharaArea;

	// キャラクターとの距離
	int playerCharaDistance;

	// キャラクターを向いている場合の向き
	float charaLookAtAngle;

	// キャラクターを視認できたかどうか
	bool charaLookAt;

	// 逃げるフレーム数
	int escapeFrame;


	/// モーションに関して-------------------------

	// モーションのID
	enum MOTION { dash, idle, death };

	// モーションのプロセス
	void MotionProcess();


	/// 階段に関して-------------------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して---------------------------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// 動きに関して--------------------------------

	// 動きのプロセス
	void AutoMoveProcess();

	// 追うプロセス
	void EscapeMoveProcess();

	// 動きのカウント
	int moveCount;


	/// 攻撃に関して-------------------------------

	// 攻撃のフレーム
	float attackFrame;

	// 攻撃を受けた数値
	int damageCount;


	/// 落下に関して-------------------------------

	// 重力
	float gravity;

	// ジャンプ力
	float flyJumpPower;

	// 浮いているときにY軸に与える力
	float fallJumpPower;

	// ジャンププロセス
	void FallProcess();

	// ジャンプから床についたかどうか
	bool preJumpNow;

	// 浮いているフレーム数
	int flyCount;


	/// テクスチャに関して-------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;


public:
	// コンストラクタ
	EnemyMove5(const int modelHandle, const int collStageHandle, const int stairsHandle
		, const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY);

	// デストラクタ
	~EnemyMove5();


	// 描画
	void Draw();

	// プロセス
	void Process();


	// テクスチャの切り替え
	void TextureReload();

	// キャラクターの座標と距離を把握する
	void SetCharacterArea(const VECTOR characterArea, const int distance);

	// 死んだかどうか
	void SetDie() { this->damageHit = true; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};
