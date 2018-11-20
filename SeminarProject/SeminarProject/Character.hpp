#pragma once
#include "BasicCreature.hpp"


class Character : public BasicCreature
{
private:
	// それぞれの位置に関して
	float direZAngle;		// 前後のキャラ向きを扱う変数
	float direXAngle;		// 左右のキャラ向きを扱う変数


	// モーションに関して
	enum MOTION { run, idle, walk };


	// 動きに関して
	enum DIRECTION { left, down, right, up };
	bool m_direction[4];
	void MoveProcess();


public:
	Character(const int modelHandle, const int collStageHandle);	// コンストラクタ
	~Character();					// デストラクタ


	void Draw();
	void Process(const float getAngle);


	void PositionReset();
};