#pragma once
#include "Basic.hpp"


class BaseMove
{
private:
	/// 影に関して-----------------------------------------------

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
	/// ---------------------------------------------------------


	/// スカイボックスに関して

	// スカイボックスのハンドル
	int skyBoxUp, skyBoxUnder;


protected:
	// シーンの終了フラッグ
	static bool endFlag;

	// 現在のシーン
	static ESceneNumber scene;


	/// 影に関して-----------------------------------------------

	/// 設定する

	// 設定シャドウマップ０番：主人公
	void ShadowCharaSetUpBefore();
	void ShadowCharaSetUpAfter();

	// 設定シャドウマップ１番：主人公以外
	void ShadowAnotherCharaSetUpBefore();
	void ShadowAnotherCharaSetUpAfter();

	// 設定シャドウマップ２番：動かないもの
	void ShadowNoMoveSetUpBefore();
	void ShadowNoMoveSetUpAfter();

	/// 描画へ使用する

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
	/// ---------------------------------------------------------


	// 二つのモデルの距離
	int GetDistance(const VECTOR alpha, const VECTOR beta);


	/// スカイボックスに関して-----------------------------

	// スカイボックスの描画
	void SkyBoxDraw();

	// スカイボックスのプロセス
	void SkyBoxProcess(const VECTOR characterArea);

	// スカイボックスの初期化
	void SetInitSkyBox(const int skyBoxUp);


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


	/// ゲッターセッター------------------------------

	// 終了かどうかを渡す
	static const bool GetEndFlag();

	// 今のシーンを渡す
	static const ESceneNumber GetScene();

	// 今のシーンを得る
	void SetScene(const ESceneNumber scene);
};

