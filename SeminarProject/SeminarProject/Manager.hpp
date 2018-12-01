#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	// シーンの基底クラス
	BaseMove* p_baseMove;

	// ロードのクラス
	LoadThread* p_loadThread;


	// シーンを切り替える
	void SceneChange();


	/// ムーブ１に関する----------------

	// ムーブ1のロード数
	const int max1 = 7;

	// ムーブ1のロードファイル
	std::string move1str[7];

	// ムーブ1のロードの種類
	ELOADFILE load1[7];


	/// ムーブ２に関する--------------

	// ムーブ2のロード数
	const int max2 = 9;

	// ムーブ2のロードファイル
	std::string move2str[9];

	// ムーブ2のロードの種類
	ELOADFILE load2[9];


	// アンチエイリアスの画像
	int antiAliasScreen;

	// シーン切り替えのフェードカウント
	int feedCount;

public:
	// コンストラクタ
	Manager();

	// デストラクタ
	~Manager();


	// メインプロセス
	void Update();
};

