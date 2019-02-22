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
	int moveDoCount;

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

	// ダメージを受けた数値
	int damageCount;

	
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

	// 死んだので実体を消していく
	bool SetDeathBlendDraw();


	// テクスチャの切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();


	// 攻撃をダメージに反映するかどうか
	const bool GetAttackDamage() const { return attackDamageNow; }

	// どの攻撃を行ったか渡す
	const EAttackPattern GetAttackPattern() const { return e_attackPattern; }

	// 攻撃を行った瞬間かどうか
	const bool GetAttackStartNow() const { return attackStartNow; }

	// 攻撃中中か渡す
	const bool GetAttackNow() const { return attackMotionNow; }

	// 手を振りかざす攻撃の肩から肘の中間の座標を渡す
	const VECTOR GetAttackFlameOneArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 15), MV1GetFramePosition(modelHandle, 14)), 0.5); }

	// 手を振りかざす攻撃の肩から肘までのカプセルの横幅を渡す
	const float GetAttackFlameOneWidth() const { return 350.0f; }

	// 手を振りかざす攻撃の肩から肘までのカプセルの縦幅を渡す
	const float GetAttackFlameOneHeight() const { return 20.0f; }

	// 手を振りかざす攻撃の肘から手首の中間の座標を渡す
	const VECTOR GetAttackFlameTwoArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 16), MV1GetFramePosition(modelHandle, 15)), 0.5); }

	// 手を振りかざす攻撃の肘から手首までのカプセルの横幅を渡す
	const float GetAttackFlameTwoWidth() const { return 460.0f; }

	// 手を振りかざす攻撃の肘から手首までのカプセルの縦幅を渡す
	const float GetAttackFlameTwoHeight() const { return 50.0f; }

	// 手を振りかざす攻撃の手首から手先の中間の座標を渡す
	const VECTOR GetAttackFlameThreeArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 17), MV1GetFramePosition(modelHandle, 16)), 0.5); }

	// 手を振りかざす攻撃の手首から手先までのカプセルの横幅を渡す
	const float GetAttackFlameThreeWidth() const { return 360.0f; }

	// 手を振りかざす攻撃の手首から手先までのカプセルの縦幅を渡す
	const float GetAttackFlameThreeHeight() const { return 50.0f; }
};

