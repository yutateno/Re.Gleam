#pragma once
#include "Basic.hpp"
#include "LoadFile.hpp"


/*
ムーブの大本
*/
class BaseMove
{
private:
	/// 影に関して-------------------------------------------------------

	// キャラクターの影のハンドル
	int shadowMapCharaHandle;

	// キャラクター以外の動くアクターのハンドル
	int shadowMapAnotherCharaHandle;

	// 全く動かないやつのハンドル
	int shadowMapNoMoveHandle;

	// キャラクターの影のマイナス範囲
	VECTOR shadowCharaLowArea;

	// キャラクターの影のプラス範囲
	VECTOR shadowCharaHighArea;

	// キャラクター以外動くやつの影のマイナス範囲
	VECTOR shadowAnotherCharaLowArea;

	// キャラクター以外動くやつの影のプラス範囲
	VECTOR shadowAnotherCharaHighArea;

	// 全く動かないやつの影のマイナス範囲
	VECTOR shadowNoMoveLowArea;

	// 全く動かないやつの影のプラス範囲
	VECTOR shadowNoMoveHighArea;

	// ライトのディレクション方向
	VECTOR lightDire;


	/// スカイボックスに関して--------------------------------------------

	// スカイボックスのハンドル
	int skyBoxUp, skyBoxUnder;


	/// テクスチャに関して-----------------------------------------------

	// テクスチャ
	int textureHandle;


protected:
	// シーンの終了フラッグ
	static bool endFlag;

	// 現在のシーン
	static ESceneNumber scene;


	/// ムーブ毎の説明画像-----------------------------------------------

	// ムーブ説明の画像
	int moveDescriptionDraw;

	// ムーブ説明のフレーム
	int moveDescriptionFrame;


	/// 影に関して-------------------------------------------------------
	/// 設定する-----------------------------------------

	// 設定シャドウマップ０番：主人公
	void ShadowCharaSetUpBefore();

	// 設定シャドウマップ１番：主人公以外
	void ShadowAnotherCharaSetUpBefore();

	// 設定シャドウマップ２番：動かないもの
	void ShadowNoMoveSetUpBefore();

	// シャドウマップの描画終了
	void ShadowSetUpAfter();


	/// 描画へ使用する----------------------------------

	// 描画シャドウマップ０番：主人公
	void ShadowCharaDrawBefore();
	void ShadowCharaDrawAfter();

	// 描画シャドウマップ１番：主人公以外
	void ShadowAnotherCharaDrawBefore();
	void ShadowAnotherCharaDrawAfter();

	// 描画シャドウマップ２番：動かないもの
	void ShadowNoMoveDrawBefore();
	void ShadowNoMoveDrawAfter();

	// 座標を更新し続ける
	void ShadowArea(const VECTOR charaArea);


	/// アクターごとに関して----------------------------------------------

	// 二つのモデルの距離
	template<class T>
	T GetDistance(const VECTOR alpha, const VECTOR beta)
	{
		return static_cast<T>(sqrt((alpha.x - beta.x) * (alpha.x - beta.x)
			+ (alpha.z - beta.z) * (alpha.z - beta.z)));
	}


	/// スカイボックスに関して------------------------------------------

	// スカイボックスの描画
	void SkyBoxDraw();

	// スカイボックスのプロセス
	void SkyBoxProcess(const VECTOR characterArea);

	// スカイボックスの初期化
	void SetInitSkyBox(const int skyBoxUp, const int tex0);

	// スカイボックスのテクスチャ変更
	void SkyTextureReload();


	/// テクスチャに関して-----------------------------------------------

	// 非同期用変数
	std::thread ths;


public:
	// コンストラクタ
	BaseMove();

	// デストラクタ
	virtual ~BaseMove();

	// 描画
	virtual void Draw() = 0;

	// プロセス
	virtual void Process() = 0;

	// カメラのプロセス
	virtual void CameraProcess() = 0;

	// テクスチャの切り替え
	virtual void TextureReload() = 0;

	// 非同期テクスチャの切り替え
	virtual void ThsTextureReload() = 0;

	// オプション画面でのモデル表示
	virtual void OptionActorModel() = 0;

	// オプション画面でのモデル表示の準備
	virtual void OptionActorModelBefore() = 0;

	// オプション画面でのモデル表示の後始末
	virtual void OptionActorModelAfter() = 0;


	/// ゲッターセッター-------------------------------------------------

	// 終了かどうかを渡す
	static const bool GetEndFlag() { return endFlag; }

	// 今のシーンを渡す
	static const ESceneNumber GetScene() { return scene; }

	// 今のシーンを得る
	void SetScene(const ESceneNumber scene) { this->scene = scene; }
};

