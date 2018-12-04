#pragma once
#include "Stage.hpp"
#include "Character.hpp"
#include "EnemyMove1.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "DropItemMove1.hpp"

#include <random>


/*
光を集めるシーン
浮いている玉を集めて光を手に入れる
*/
class MainMove1 : public BaseMove
{
private:
	// ロードから渡されるファイルの順番
	enum EFILE { drawStage, collStage, character, sword, sound, seBallHigh, seBall };

	/// ステージ--------------
	
	// ステージのポインタ
	Stage* p_stage;


	/// キャラクター-----------------

	// キャラクターのポインタ
	Character* p_character;

	// 敵を手に入れた数
	int catchEnemyNum;


	/// 敵--------------------------------------

	// 敵の数
	const int enemyNum = 30;

	// それぞれの敵が所持するもの
	struct EnemyAggre
	{
		// 敵のポインタ
		EnemyMove1* p_enemyMove;

		// 生きているか
		bool aliveNow;
	};

	// 敵の構造体を所持
	EnemyAggre s_enemyAggre[30];


	/// カメラ-------------------

	// カメラのポインタ
	Camera* p_camera;


	/// あたり判定-----------------------

	// アクター同士のあたり判定
	void ActorHit();


	/// ライトに関する--------------------------

	// ライトハンドルの数
	const int lightNum = 4;

	// ライトハンドル情報保持
	int lightHandle[4];

	// ライトの範囲
	float lightRange[4];

	// ライトの座標
	VECTOR lightArea[4];

	// ライトに関する関数
	void LightProcess();

	// イベントを行う
	bool lightEventStart;

	// イベントの終了を確認
	bool lightEventEnd;	

	// イベントのカウント
	int lightEventCount;

	// ライトを消す
	bool lightEnd;

	// 光源の広さの直前マックス
	float lightRangePreMax;

	// 光源の広さを広げるスピード
	float lightRangeSpeed;
	/// ----------------------------------------


	// 背景色
	int backgroundColor;


	/// 落ちてる剣-----------------------------

	// 落ちるアイテム（剣）
	DropItemMove1* p_dropItem;

	// 落ちてるアイテムに触れる
	bool touchSword;


public:
	// コンストラクタ
	MainMove1(const std::vector<int> v_file);

	// デストラクタ
	~MainMove1();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;

	// カメラのプロセス
	void CameraProcess() override;
};