#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	BaseMove* p_baseMove;			// シーンの基底クラス
	LoadThread* p_loadThread;		// ロードのクラス


	void SceneChange();				// シーンを切り替える


	// ムーブ１に関する
	const int max1 = 7;
	std::string move1str[7];
	ELOADFILE load1[7];


	// ムーブ２に関する
	const int max2 = 9;
	std::string move2str[9];
	ELOADFILE load2[9];


	int antiAliasScreen;

	int feedCount;

public:
	Manager();			// コンストラクタ
	~Manager();			// デストラクタ

	void Update();		// メインプロセス
};