#pragma once
#include "BasicCreature.hpp"
#include "MagicIcePillar.hpp"
#include "ChaseBlock.hpp"
#include <random>


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

	// 動きのカウント
	int moveCount;

	// 攻撃のフレーム
	float attackFrame;

	// 攻撃によるあたりをさせるかどうか
	bool attackDamageNow;

	// 氷柱のポインタ
	MagicIcePillar* p_magicIcePillar[2];

	// 攻撃のパターンID
	enum EAttackPattern { hand, icePillar, magicBlock };

	// どの攻撃を行うか
	EAttackPattern e_attackPattern;

	// 追尾箱のポインタ
	ChaseBlock* p_chaseBlock[2];

	// プレイヤーの座標
	VECTOR playerArea;

	
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

	// プレイヤーの座標を得る
	void SetPlayerArea(VECTOR player) { playerArea = player; }
};

