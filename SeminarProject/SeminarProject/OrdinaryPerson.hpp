#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
ムーブ４以降で出てくる一般人のクラス
*/
class OrdinaryPerson : public BasicCreature
{
private:
	/// モデルに関して---------------------------------

	// 生存を許されたら
	bool alive;

	// 透過値を保存する
	int aliveBlendCount;


	/// それぞれの位置に関して-------------------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;		

	// 左右のキャラ向きを扱う変数
	float direXAngle;		

	// 次の前後のキャラ向きを扱う変数
	float nextDireZAngle;

	// 次の左右のキャラ向きを扱う変数
	float nextDireXAngle;


	/// モーションに関して------------------------------

	// モーションのID
	enum MOTION { walk };


	/// 階段に関して-----------------------------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して-------------------------------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// 動きに関して-----------------------------------

	// 動きのプロセス
	void MoveProcess();

	// 動きのカウント
	int moveCount;


	/// 落下に関して----------------------------------

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


	/// テクスチャに関して----------------------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;

	
	/// 乱数値----------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
		, const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY);

	// デストラクタ
	~OrdinaryPerson();


	// 描画
	void Draw();

	// プロセス
	void Process();


	// テクスチャの切り替え
	void TextureReload();

	// オプション用モデル描画の後始末
	void OptionActorDrawAfter() override {}

	// 生存を許されたら座標を設定して生成
	void SetAlive(VECTOR area, bool alive = true);

	// 生存しているかどうかを渡す
	const bool GetAlive() const { return alive; }
};

