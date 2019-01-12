#pragma once
#include "Basic.hpp"
#include "SoundProcess.hpp"


class Camera
{
private:
	// カメラの位置
	VECTOR cameraPerspectiveArea;		// 遠近法カメラ
	VECTOR cameraOrthoArea;				// 正射影カメラ

	// 注視する方向
	VECTOR perspesctiveViewArea;		// 遠近法カメラ
	VECTOR orthoViewArea;				// 正射影カメラ

	// キャラ位置
	VECTOR charaArea;

	// キャラクターのアングル
	float angle;

	// 正射影カメラ用の座標
	float orthoArea;

	// 回転スピード
	float speed;

	// 回転を行う関数
	void RLrotate(const float speed, float& axisOne, float& axisTwo);

	// 上下回転用
	VECTOR zRota;


public:
	// キャラの位置を引数に取ったコンストラクタ
	Camera(const VECTOR charaarea);

	// デストラクタ
	~Camera();


	// キャラの位置を引数に取ったプロセス
	void Process(const VECTOR charaarea);		

	// カメラのセットアップ
	void SetUp();

	// キャラクターのアングル
	const float GetAngle() const { return angle; }

	// カメラの座標
	const VECTOR GetArea();
};