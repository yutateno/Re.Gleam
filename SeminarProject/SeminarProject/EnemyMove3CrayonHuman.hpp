#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
ムーブ３で出てくるクレヨン人間のクラス
*/
class EnemyMove3CrayonHuman : public BasicCreature
{
private:
	/// それぞれの位置に関して---------------------------

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


	/// モーションに関して-------------------------------

	// モーションのID
	enum MOTION { walk, idle, damage, death };

	// モーションのプロセス
	void MotionProcess();


	/// 階段に関して-------------------------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して---------------------------------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// 動きに関して-------------------------------------

	// 動きのプロセス
	void AutoMoveProcess();

	// 追うプロセス
	void ChaseMoveProcess();

	// 動きのカウント
	int moveCount;
	
	
	/// 攻撃に関して-------------------------------------

	// 攻撃のフレーム
	float attackFrame;

	// 攻撃によるあたりをさせるかどうか
	bool attackDamageNow;

	// 攻撃を受けた数値
	int damageCount;

	// ダメージのプロセス
	void DamageProcess();


	/// 落下に関して-------------------------------------

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


	/// テクスチャに関して-------------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;


	/// 乱数値---------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	EnemyMove3CrayonHuman(const int modelHandle, const int collStageHandle
		, const int stairsHandle, const int stairsRoadHandle, const int tex0
		, const VECTOR area, const float rotationY);

	// デストラクタ
	~EnemyMove3CrayonHuman();


	// 描画
	void Draw();

	// プロセス
	void Process();


	// テクスチャの切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();

	// キャラクターの座標と距離を把握する
	void SetCharacterArea(const VECTOR characterArea, const int distance);

	// 攻撃をダメージに反映するかどうか
	const bool GetAttackDamage() const { return attackDamageNow; }
};

