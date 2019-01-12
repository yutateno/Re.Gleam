#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"
#include "MainMove3.hpp"
#include "MainMove4.hpp"
#include "MainMove5.hpp"


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
	const int max1 = 14;

	// ムーブ1のロードファイル
	std::string move1str[14];

	// ムーブ1のロードの種類
	ELOADFILE load1[14];

	// ムーブ1のロードの初期化
	void InitMove1Load();


	/// ムーブ２に関する--------------

	// ムーブ2のロード数
	const int max2 = 48;

	// ムーブ2のロードファイル
	std::string move2str[48];

	// ムーブ2のロードの種類
	ELOADFILE load2[48];

	// ムーブ2のロードの初期化
	void InitMove2Load();


	/// ムーブ3に関する--------------

	// ムーブ3のロード数
	const int max3 = 58;

	// ムーブ3のロードファイル
	std::string move3str[58];

	// ムーブ3のロードの種類
	ELOADFILE load3[58];

	// ムーブ3のロードの初期化
	void InitMove3Load();


	/// ムーブ4に関する--------------

	// ムーブ4のロード数
	const int max4 = 38;

	// ムーブ4のロードファイル
	std::string move4str[38];

	// ムーブ4のロードの種類
	ELOADFILE load4[38];

	// ムーブ4のロードの初期化
	void InitMove4Load();

	// ムーブ4でロードするテクスチャを初期から変更する
	void Move4TextureReload();


	/// ムーブ5に関する--------------

	// ムーブ5のロード数
	const int max5 = 34;

	// ムーブ5のロードファイル
	std::string move5str[34];

	// ムーブ5のロードの種類
	ELOADFILE load5[34];

	// ムーブ5のロードの初期化
	void InitMove5Load();


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

	// 左スティックのY軸押し倒しかどうかを調べる(DLLXinputでやるべきなんだろうかとりあえず
	int optionControllLeftStickY[2];

	// 現選択の最小
	int optionSelectMin;

	// 現選択の最大
	int optionSelectMax;

	// SE再生ウェイトタイマー
	int seDoWaitTimer;

	// ロード
	std::thread thsTexture;

	// オプション用画像ID
	enum class EOptionDraw { BGM, Camera, ColorD, ColorP, SE, Sound, Perspective, Color, Ortho
		, ColorNormal, HorizonReturn, VerticalReturn, nextPage, prevPage, optionEnd };

	// オプション用画像
	int optionDrawMedia[15];

	// オプション用画像個数
	const int optionDrawNum = 15;

	// オプションのページ目
	int optionPageNowNumber;


public:
	// コンストラクタ
	Manager();

	// デストラクタ
	~Manager();


	// メインプロセス
	void Update();
};
