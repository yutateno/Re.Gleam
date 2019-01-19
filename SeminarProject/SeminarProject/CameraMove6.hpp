#pragma once
#include "Basic.hpp"


class CameraMove6
{
private:
	// カメラの位置
	VECTOR area;
	VECTOR viewArea;


public:
	// コンストラクタ
	CameraMove6();

	// デストラクタ
	~CameraMove6();


	// カメラのセットアップ
	void SetUp();

	// カメラの座標を渡す
	const VECTOR GetArea() const { return area; }

	// カメラの座標を設定する
	void SetArea(VECTOR t_area) { area = t_area; }

	// カメラの注目点を設定する
	void SetView(VECTOR t_viewArea) { viewArea = t_viewArea; }
};

