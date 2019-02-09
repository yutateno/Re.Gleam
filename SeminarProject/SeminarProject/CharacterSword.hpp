#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
ムーブ２以降で扱う剣を持ったキャラクターのクラス
*/
class CharacterSword : public BasicCreature
{
private:
	/// それぞれの位置に関して----------------------------------------------------------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;

	// 残像用描画
	VECTOR preDrawArea;

	// オプションでの回転数
	int optionRotaCount;

	// オプションでもモデル表示カウント
	int optionModelDrawCount;


	/// モーションに関して---------------------------------------------------------------------

	// 動きのID
	enum MOTION { idle, action1, action2, action3, skyAction1, skyAction2, skyAction3
		, dash, walk, jump, fall, damage, death, gunAction, gunActionWalk, nagiharai
		, handUp
	};

	// 瞬間的に早くできるとき
	int moveFastWaitCount;



	/// 階段に関して--------------------------------------------------------------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して----------------------------------------------------------------------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// パネルに関して------------------------------------------------------------------------
	
	// パネルのモデル
	std::vector<int> v_paneruHandle;

	// パネルの個数
	int paneruNum;


	/// 動きに関して--------------------------------------------------------------------------

	// それぞれの向きID
	enum DIRECTION { left, down, right, up };

	// 向いているかどうか
	bool m_direction[4];

	// 動きのプロセス
	void MoveProcess();

	// 操作のプロセス
	void OpeProcess();

	// 左足の音を鳴らしたかどうか
	bool leftFootSoundDo;

	// 右足の音を鳴らしたかどうか
	bool rightFootSoundDo;


	/// walkSpeedの各々の状況の最大値---------------------------------------------------------

	// 攻撃中の最大移動値
	const float maxWalkSpeedAttack = 60.0f;

	// 瞬間加速時の最大移動量
	const float maxWalkSpeedFast = 85.0f;

	// 空中で瞬間加速時の最大移動量
	const float maxWalkSpeedFlyFast = 80.0f;

	// 通常時の最大移動量
	const float maxWalkSpeedNormal = 30.0f;

	// 空中時の最大移動量
	const float maxWalkSpeedFly = 15.0f;

	// 瞬間加速時の再使用待機時間
	const int maxFastMoveWaitCount = 34;


	/// 攻撃に関して-------------------------------------------------------------------------

	// 今攻撃しているかどうか
	bool attackNow;
	
	// 次のコンボへつなげるかどうか
	bool attackNext;

	// 今の攻撃のフレーム数
	float attackFrame;

	// 攻撃の番号
	int attackNumber;

	// 直前の攻撃の番号
	int preAttackNumber;

	// ジャンプでの攻撃をしたかどうか
	bool jumpAttackDo;

	// 攻撃のプロセス
	void AttackProcess();

	// ダメージを受けているかどうか
	bool damageFlag;

	// 一つの攻撃モーションが終わったかどうか
	bool attackMotionEnd;

	// 最も近い敵
	VECTOR mostNearEnemyArea;

	// 最も近い敵をロックオンしたときの向き
	float mostNearEnemyDire;


	/// ジャンプに関して----------------------------------------------------------------------

	// 重力
	float gravity;

	// ジャンプ力
	float flyJumpPower;

	// 浮いているときにY軸に与える力
	float fallJumpPower;

	// ジャンププロセス
	void JumpProcess();

	// ジャンプから床についたかどうか
	bool preJumpNow;

	// 浮いているフレーム数
	int flyCount;

	// 行動によってアニメーションの管理
	void AnimProcess();
	

	/// テクスチャに関して---------------------------------------------------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;
	int textureHandle4;


public:
	// コンストラクタ
	CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle
		, const int paneruHandle, const int stairsRoadHandle, const int tex0, const int tex1
		, const int tex2, const int tex3, const int tex4);

	// デストラクタ
	~CharacterSword();


	// 描画
	void Draw();
	
	// プロセス
	void Process(const float getAngle);

	// 操作できないプロセス
	void NotOpeProcess(const float getAngle);

	// 床以外あたり判定をさせないプロセス
	void OnlyCollFloorProcess(const float getAngle);


	// ポジションを初期化する
	void PositionReset() { area = VGet(0.0f, 50.0f, 0.0f); }

	// テクスチャの切り替え
	void TextureReload();

	// 非同期テクスチャ差し替え
	std::thread ThsTextureReload();

	// 攻撃を受けている
	void SetDamage() { damageFlag = true; }

	// 体を地面に埋まらせる(ムーブ6のみ
	void AreaSetDown();

	// オプション用モデル描画
	void OptionActorDraw();

	// オプション用モデル描画の準備
	void OptionActorDrawBefore();

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter();

	// ムーブ6にてワープさせる
	void WarpMove6(VECTOR paneruArea) { area = VAdd(paneruArea, VGet(0, 50, 0)); }


	/// ゲッターセッター-------------------------------------------------------------------------

	// 階段の座標を設定する
	void SetStairsArea(const VECTOR stairsArea, const int num, const float angle);

	// パネルの座標を設定する
	void SetPaneruArea(const VECTOR paneruArea, const int num);

	// 階段と床の座標を設定する
	void SetStairsRoadArea(const VECTOR stairsRoadArea, const int num, const float angle);

	// 直前のエリアを渡す
	const VECTOR GetPreArea() const { return preArea; }

	// 攻撃しているかを渡す
	const bool GetAttackNow() const { return attackNow; }

	// 攻撃の武器の初めの座標を渡す
	const VECTOR GetAttackFirstFrameArea() const { return MV1GetFramePosition(modelHandle, 66); }

	// 攻撃の武器の最後の座標を渡す
	const VECTOR GetAttackEndFrameArea() const { return MV1GetFramePosition(modelHandle, 67); }

	// キャラクターの向いている方向
	const float GetAngle() const { return angle + direXAngle + direZAngle; }

	// 速度早い動きをしたかどうか
	const bool GetMoveFastWaitCount() const { return moveFastWaitCount > 0 ? true : false; }

	// 攻撃の最後のモーション
	const bool GetAttackMotionEnd() const { return attackMotionEnd; }

	// 最も近くてロックオンしている敵
	void SetMostNearEnemyArea(VECTOR enemyArea = VGet(0, -1000, 0)) { mostNearEnemyArea = enemyArea; }

	// 当たり判定を行うパネルの数を指定する
	void SetCollPaneruNum(int num) { paneruNum = num; }
};

