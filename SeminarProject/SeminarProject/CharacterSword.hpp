#pragma once
#include "BasicCreature.hpp"


class CharacterSword : public BasicCreature
{
private:
	/// それぞれの位置に関して-----------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;


	/// モーションに関して--------------------------------------------------------------------------------------

	// 動きのID
	enum MOTION { idle, action1, action2, action3, skyAction1, skyAction2, skyAction3, dash, walk, jump, fall
				, damage, death, gunAction, gunActionWalk, nagiharai, handUp};



	/// 階段に関して----------------------

	// 階段のモデル
	int stairsHandle[10];

	// 階段の位置
	VECTOR stairsArea[10];


	/// パネルに関して------------------------
	
	// パネルのモデル
	int paneruHandle[10];

	// パネルの位置
	VECTOR paneruArea[10];


	/// 動きに関して------------------------------

	// それぞれの向きID
	enum DIRECTION { left, down, right, up };

	// 向いているかどうか
	bool m_direction[4];

	// 歩ているかどうか
	bool walkNow;

	// 動きのプロセス
	void MoveProcess();


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

	// 攻撃のプロセス
	void AttackProcess();


	/// ジャンプに関して------------------

	// 重力
	float gravity;

	// ジャンプ力
	float flyJumpPower;

	// 浮いているときにY軸に与える力
	float fallJumpPower;

	// ジャンププロセス
	void JumpProcess();


	// 行動によってアニメーションの管理
	void AnimProcess();
	

	/// テクスチャに関して------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;
	int textureHandle4;


public:
	// コンストラクタ
	CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle
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
	void SetStairsArea(const VECTOR stairsArea, const int num);

	// パネルの座標を設定する
	void SetPaneruArea(const VECTOR paneruArea, const int num);

	// 直前のエリアを渡す
	const VECTOR GetPreArea() const { return preArea; }

	// 攻撃しているかを渡す
	bool GetAttackNow() { return attackNow; }

	// 攻撃の武器の初めの座標を渡す
	VECTOR GetAttackFirstFrameArea() { return MV1GetFramePosition(modelHandle, 66); }

	// 攻撃の武器の最後の座標を渡す
	VECTOR GetAttackEndFrameArea() { return MV1GetFramePosition(modelHandle, 67); }
};

