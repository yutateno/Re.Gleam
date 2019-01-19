#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"
#include "FileSaveLoad.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"
#include "MainMove3.hpp"
#include "MainMove4.hpp"
#include "MainMove5.hpp"
#include "MainMove6.hpp"


class Manager
{
private:
	/// 各シーンに関する--------------------------
	// シーンの基底クラス
	BaseMove* p_baseMove;

	// ロードのクラス
	LoadThread* p_loadThread;

	// シーンを切り替える
	void SceneChange();

	// 直前のシーンがロードかゲームかどうか
	bool preLoadScene;

	// ロードのファイル
	std::vector<std::string> moveStr;

	// ロードの種類
	std::vector<ELOADFILE> loadType;

	// アンチエイリアスの画像
	int antiAliasScreen;

	// シーン切り替えのフェードカウント
	int feedCount;

	// フェードの色
	int feedDraw;


	/// ゲームに関する------------

	// ゲーム起動直後かどうか
	bool gameFirstStarting;

	// ゲームを終了する
	bool gameEnd;


	/// ゲームタイトルに関する-----------------------------------------

	// セーブデータがあったときのタイトルUI画像
	enum class ETitleDraw {
		firstGame, load, gameEnd, bonus, bonusMove2, bonusMove3
		, bonusMove4, bonusMove5, bonusMove6
	};

	// セーブデータがあったときのタイトルUI画像保持
	int titleUIDraw[9];

	// セーブデータがったときのタイトルUI画像の個数
	const int titleUINum = 9;

	// セーブデータがあったときのタイトルプロセス
	void TitleProcess();

	// セーブデータがあったときのタイトル描画
	void TitleDraw();

	// おまけコマンドを打ったかどうか
	bool playBonus;


	/// ムーブ１に関する----------------

	// ムーブ1のロード数
	const int max1 = 15;

	// ムーブ1のロードの初期化
	void InitMove1Load();


	/// ムーブ２に関する--------------

	// ムーブ2のロード数
	const int max2 = 49;

	// ムーブ2のロードの初期化
	void InitMove2Load();


	/// ムーブ3に関する--------------

	// ムーブ3のロード数
	const int max3 = 65;

	// ムーブ3のロードの初期化
	void InitMove3Load();


	/// ムーブ4に関する--------------

	// ムーブ4のロード数
	const int max4 = 54;

	// ムーブ4のロードの初期化
	void InitMove4Load();

	// ムーブ4でロードするテクスチャを初期から変更する
	void Move4TextureReload();


	/// ムーブ5に関する--------------

	// ムーブ5のロード数
	const int max5 = 40;

	// ムーブ5のロードの初期化
	void InitMove5Load();

	// ムーブ5でロードするテクスチャを初期から変更する
	void Move5TextureReload();


	/// ムーブ6に関する

	// ムーブ6のロード数
	const int max6 = 39;

	// ムーブ6のロードの初期化
	void InitMove6Load();

	// ムーブ6のロードするテクスチャを初期から変更する
	void Move6TextureReload();


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
	enum class EOptionSelectButton { Sound, ColorSelect, Camera, DataSave, GameEnd, BGM, SE, ColorNormal, ColorP, ColorD
		, BGMSelect, SESelect, CameraPerspective, CameraOrtho, CameraHReturn, CameraVReturn, SaveYes, SaveNo, GameEndYes, GameEndNo };

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
		, ColorNormal, HorizonReturn, VerticalReturn, nextPage, prevPage, optionEnd, gameEnd, dataSave, yes, no };

	// オプション用画像
	int optionDrawMedia[19];

	// オプション用画像個数
	const int optionDrawNum = 19;

	// オプションのページ目
	int optionPageNowNumber;

	// オプションでのセーブをSE
	int se_save;


public:
	// コンストラクタ
	Manager();

	// デストラクタ
	~Manager();


	// メインプロセス
	void Update();

	// ゲームを終了するかどうか
	const bool GetEnd() const { return gameEnd; }
};
