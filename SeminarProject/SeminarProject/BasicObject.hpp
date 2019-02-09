#pragma once
#include "LoadFile.hpp"


/*
全アクターの必要な要素を持ったクラス
*/
class BasicObject
{
protected:
	/// モデルに関する---------------------------------------

	// モデルのハンドル
	int modelHandle;

	// モデルの高さ
	float modelHeight;

	// モデルの横幅
	float modelWidth;

	// 画面外に外れて描画させなくするまでのカウント
	int notViewCount;


	/// 足元影に関する----------------------------------------

	// 足元影の高さ
	float shadowHeight;

	// 足元影のサイズ
	float shadowSize;

	// 足元影のプロセス
	bool ShadowFoot(int shadowModel);

	// 足元影のエリア
	VECTOR area;


private:
	/// 影に関する--------------------------------------------

	// 周囲のポリゴンを代入する構造体
	MV1_COLL_RESULT_POLY_DIM shadowHitResDim;

	// 影のポリゴンの構造体
	MV1_COLL_RESULT_POLY *shadowHitRes;

	// 影の行列
	VERTEX3D shadowVertex[3];

	// 影の座標
	VECTOR shadowSlideVec;

	// 影のハンドル
	int shadowHandle;


	/// ムーブ6のみに関する変数-------------------------------

	// 円の半径
	float move6_circle;

	// 線の動き
	float move6_line;


public:
	// コンストラクタ
	BasicObject();

	// コピーコンストラクタ
	BasicObject(bool shadowDo);

	// デストラクタ
	virtual ~BasicObject();


	// 描画
	void ModelDraw();

	// ムーブ6にて地面に沈める
	void Move6SetDownArea();


	/// ゲッターセッター--------------------------------------

	// 座標を渡す
	const VECTOR GetArea() const { return area; }

	// 縦幅を渡す
	const float GetHeight() const { return modelHeight; }

	// 横幅を渡す
	const float GetWidth() const { return modelWidth; }
};

