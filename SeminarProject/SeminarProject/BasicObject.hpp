#pragma once
#include "LoadFile.hpp"


class BasicObject
{
protected:
	// モデルのハンドル
	int modelHandle;

	// モデルの高さ
	float modelHeight;


	/// 足元影に関する----------------

	// 足元影の高さ
	float shadowHeight;

	// 足元影のサイズ
	float shadowSize;

	// 足元影のプロセス
	void ShadowFoot();

	// 足元影のエリア
	VECTOR area;


private:
	/// 影に関する------------------------------------

	// 周囲のポリゴンを代入する構造体
	MV1_COLL_RESULT_POLY_DIM ShadowHitResDim;

	// 影のポリゴンの構造体
	MV1_COLL_RESULT_POLY *ShadowHitRes;

	// 影の行列
	VERTEX3D ShadowVertex[3];

	// 影の座標
	VECTOR ShadowSlideVec;

	// 影のハンドル
	int shadowHandle;


	// ステージハンドル
	int stageHandle;

	// 画面外に外れて描画させなくするまでのカウント
	int notViewCount;

	// オプションでの回転数
	int optionRotaCount;

	// オプションでもモデル表示カウント
	int optionModelDrawCount;

public:
	// コンストラクタ
	BasicObject();

	// コピーコンストラクタ
	BasicObject(const int collStageHandle);

	// デストラクタ
	virtual ~BasicObject();


	// 描画
	void Draw();

	// オプション用モデル描画
	void OptionActorDraw();

	// オプション用モデル描画の準備
	void OptionActorDrawBefore();


	/// ゲッターセッター

	// 座標を渡す
	const VECTOR GetArea() const { return area; }
};

