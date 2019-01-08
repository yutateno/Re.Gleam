#pragma once
#include "BasicCreature.hpp"

#include <random>

class CharacterSword : public BasicCreature
{
private:
	/// それぞれの位置に関して-----------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;

	// 残像用描画
	VECTOR preDrawArea;


	/// モーションに関して--------------------------------------------------------------------------------------

	// 動きのID
	enum MOTION { idle, action1, action2, action3, skyAction1, skyAction2, skyAction3, dash, walk, jump, fall
				, damage, death, gunAction, gunActionWalk, nagiharai, handUp};

	// 瞬間的に早くできるとき
	int moveFastWaitCount;



	/// 階段に関して----------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// パネルに関して------------------------
	
	// パネルのモデル
	int paneruHandle[10];


	/// 動きに関して------------------------------

	// それぞれの向きID
	enum DIRECTION { left, down, right, up };

	// 向いているかどうか
	bool m_direction[4];

	// 歩ているかどうか
	bool walkNow;

	// 動きのプロセス
	void MoveProcess();

	// 左足の位置
	float leftFootArea;

	// 動いているフレーム数
	int underWalkCount;

	// 片足が床に触れるフレーム数
	int leftUnderTouchFrame;


	/// 攻撃に関して-----------------------

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

	// ダメージカウント
	int damageCount;

	// 直前のダメージカウント
	int preDamageCount;

	// ダメージのブレンド数値
	int damageBlend[10];

	// ダメージ表示画像
	int damageDraw[3];

	// ダメージを受けていないカウント
	int notDamegaCount;

	// ダメージ表示画像のフレーム
	int damageDrawFrame;

	// ダメージ画像のID
	int damageDrawID;


	/// ジャンプに関して------------------

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
	

	/// テクスチャに関して------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;
	int textureHandle4;


	/// エフェクトに関して
	int effeckBack[10];
	int playingEfBack;


public:
	// コンストラクタ
	CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle, const int stairsRoadHandle
	, const int tex0, const int tex1, const int tex2, const int tex3, const int tex4);

	// デストラクタ
	~CharacterSword();


	// 描画
	void Draw();
	
	// プロセス
	void Process(const float getAngle);

	// ポジションを初期化する
	void PositionReset();

	// テクスチャの切り替え
	void TextureReload();


	/// ゲッターセッター--------------------

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

	// 攻撃を受けている
	void SetDamage();
};

