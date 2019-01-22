#pragma once
#include "BasicCreature.hpp"
#include "MagicIcePillar.hpp"
#include "ChaseBlock.hpp"
#include <random>


// ボスの攻撃のパターンID
enum class EAttackPattern { hand, icePillar, magicBlock };


/*
ムーブ6で出てくるラスボスの戦闘用クラス
*/
class EnemyBossAfter : public BasicCreature
{
private:
	/// モーションに関して----------------------------------------------------

	// モーションのID
	enum MOTION{
		idleDevile, idleNormal, move, attack, attackMagic, attackMagic2
	};

	// モーションのプロセス
	void MotionProcess();

	// 攻撃中かどうか
	bool attackMotionNow;


	/// 攻撃に関して----------------------------------------------------------

	// 動きのプロセス
	void MoveProcess();

	// 動きを決めるカウント数値
	const int moveDoCount = 600;

	// 動きのカウント
	int moveCount;

	// 攻撃のフレーム
	float attackFrame;

	// 攻撃によるあたりをさせるかどうか
	bool attackDamageNow;

	// どの攻撃を行うか
	EAttackPattern e_attackPattern;

	// 攻撃を開始した瞬間
	bool attackStartNow;

	// 同じ攻撃を連続して行わせない
	EAttackPattern e_preAttackPattern;

	
	/// テクスチャに関して---------------------------------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;


	/// 乱数値---------------------------------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	EnemyBossAfter(const int modelHandle, const int modelTex0, const int modeltex1, const int modelTex2);

	// デストラクタ
	~EnemyBossAfter();


	// 描画
	void Draw();

	// モデル描画
	void DrawWhile();

	// プロセス
	void Process();


	// テクスチャの切り替え
	void TextureReload();

	// 攻撃をダメージに反映するかどうか
	const bool GetAttackDamage() const { return attackDamageNow; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}

	// どの攻撃を行ったか渡す
	const EAttackPattern GetAttackPattern() { return e_attackPattern; }

	// 攻撃を行った瞬間かどうか
	const bool GetAttackStartNow() { return attackStartNow; }
};

