#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove3Slime : public BasicCreature
{
private:
	/// それぞれの位置に関して-------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;

	// 左右のキャラ向きを扱う変数
	float direXAngle;

	// 次の前後のキャラ向きを扱う変数
	float nextDireZAngle;

	// 次の左右のキャラ向きを扱う変数
	float nextDireXAngle;


	/// モーションに関して----------

	// モーションのID
	enum MOTION { idle, attack };


	/// 階段に関して--------------

	// 階段のモデル
	std::vector<int> v_stairsHandle;


	/// 階段と床に関して----------

	// 階段と床のモデル
	std::vector<int> v_stairsRoadHandle;


	/// 動きに関して------------

	// 動きのプロセス
	void MoveProcess();

	// 動きのカウント
	int moveCount;


	/// テクスチャに関して---------------

	// テクスチャの相対IDを後ろにつけて
	int textureHandle0;


public:
	// コンストラクタ
	EnemyMove3Slime(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
		, const int tex0, const VECTOR area);

	// デストラクタ
	~EnemyMove3Slime();


	// 描画
	void Draw();

	// プロセス
	void Process();

	// テクスチャの切り替え
	void TextureReload();
};

