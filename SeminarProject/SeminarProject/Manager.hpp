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

	// 直前のシーンがロードかゲームかどうか
	bool preLoadScene;


	/// ムーブ１に関する----------------

	// ムーブ1のロード数
	const int max1 = 26;

	// ムーブ1のロードファイル
	std::string move1str[26];

	// ムーブ1のロードの種類
	ELOADFILE load1[26];


	/// ムーブ２に関する--------------

	// ムーブ2のロード数
	const int max2 = 43;

	// ムーブ2のロードファイル
	std::string move2str[43];

	// ムーブ2のロードの種類
	ELOADFILE load2[43];


	// アンチエイリアスの画像
	int antiAliasScreen;

	// シーン切り替えのフェードカウント
	int feedCount;

	// フェード用画像
	int feedDraw;


	/// オプション画面に関する---------------

	// ガウスフィルタの画像
	int gaussianScreen;

	// オプション画面にいるかどうか
	bool optionMenuNow;

	// オプション画面のプロセス
	void OptionProcess();

	// オプション画面の描画
	void OptionDraw();

	// オプション画面のID
	enum class EOptionSelectButton { Sound, ColorSelect, Camera, BGM, SE, ColorNormal, ColorP, ColorD
		, BGMSelect, SESelect, CameraPerspective, CameraOrtho, CameraHReturn, CameraVReturn };

	// オプション画面の選択ボタン
	EOptionSelectButton optionSelectButtonNum;

	// スティックの押し倒しかどうかを調べる(DLLXinputでやるべきなんだろうかとりあえず
	int optionControllStick[2];

	// 現選択の最小
	int optionSelectMin;

	// 現選択の最大
	int optionSelectMax;

	// SE再生ウェイトタイマー
	int seDoWaitTimer;

	// ロード
	std::thread thsTexture;

	// オプション用画像ID
	enum class EOptionDraw { BGM, Camera, ColorD, ColorP, SE, Sound, Perspective, Color, Ortho, ColorNormal, HorizonReturn, VerticalReturn };

	// オプション用画像
	int optionDrawMedia[12];

	// オプション用画像個数
	const int optionDrawNum = 12;



public:
	// コンストラクタ
	Manager();

	// デストラクタ
	~Manager();


	// メインプロセス
	void Update();
};

