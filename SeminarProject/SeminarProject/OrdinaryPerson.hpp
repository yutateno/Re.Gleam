#pragma once
#include "BasicCreature.hpp"
#include <random>


class OrdinaryPerson : public BasicCreature
{
private:
	/// それぞれの位置に関して---------------

	// 前後のキャラ向きを扱う変数
	float direZAngle;		

	// 左右のキャラ向きを扱う変数
	float direXAngle;		

	// 次の前後のキャラ向きを扱う変数
	float nextDireZAngle;

	// 次の左右のキャラ向きを扱う変数
	float nextDireXAngle;


	/// モーションに関して--------------------

	// モーションのID
	enum MOTION { run, idle, walk };


	/// 動きに関して-----------

	// 動きのプロセス
	void MoveProcess();

	// 動きのカウント
	int moveCount;


public:
	// コンストラクタ
	OrdinaryPerson(const int modelHandle, const int collStageHandle, const VECTOR area);

	// デストラクタ
	~OrdinaryPerson();


	// 描画
	void Draw();

	// プロセス
	void Process();
};

