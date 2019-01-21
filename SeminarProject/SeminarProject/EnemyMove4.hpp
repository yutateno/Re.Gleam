#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove4 : public BasicCreature
{
private:
	/// それぞれの位置に関して------------------------------------------------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;

	// 次の前後のキャラ向きを扱う変数
	float nextDireZAngle;

	// 次の左右のキャラ向きを扱う変数
	float nextDireXAngle;

	// キャラクターの位置
	VECTOR playerCharaArea;

	// キャラクターとの距離
	int playerCharaDistance;

	// キャラクターを向いている場合の向き
	float charaLookAtAngle;

	// サイズが等身になるまでのダメージ数
	const int bigBodyChangeDamage = 15;


	/// モーションに関して---------------------------------------------------------

	// モーションのID
	enum MOTION { idle, walk, dash, attack, attack2, attack3, damage, death };

	// モーションのプロセス
	void MotionProcess();


	/// 階段に関して---------------------------------------------------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して-----------------------------------------------------------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// 動きに関して---------------------------------------------------------------

	// 追うプロセス
	void ChaseMoveProcess();

	// 動きのカウント
	int moveCount;


	/// 攻撃に関して---------------------------------------------------------------

	// 攻撃のフレーム
	float attackFrame;

	// 攻撃によるあたりをさせるかどうか
	bool attackDamageNow;

	// ダメージの数値
	int damageCount;


	/// 落下に関して---------------------------------------------------------------

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


	/// テクスチャに関して---------------------------------------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;


public:
	// コンストラクタ
	EnemyMove4(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
		, const int tex0, const VECTOR area, const float rotationY);

	// デストラクタ
	~EnemyMove4();


	// 描画
	void Draw();

	// モデル描画
	void UniqueModelDraw();

	// プロセス
	void Process();


	// テクスチャの切り替え
	void TextureReload();

	// キャラクターの座標と距離を把握する
	void SetCharacterArea(const VECTOR characterArea, const int distance);

	// 攻撃をダメージに反映するかどうか
	const bool GetAttackDamage() const { return attackDamageNow; }

	// サイズでかいときかどうか
	const bool GetBigNow() const { return damageCount <= bigBodyChangeDamage ? true : false; }

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}
};

