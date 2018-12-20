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
	VECTOR viewArea;

	// キャラ位置
	VECTOR charaArea;

	// キャラクターのアングル
	float angle;

	// 当たり判定用ステージ
	int stageHandle;

	// 正射影カメラ用の座標
	float orthoArea;

	// 回転スピード
	float speed;

	// 回転を行う関数
	void RLrotate(const float speed, VECTOR& p_cameraArea);


public:
	// キャラの位置を引数に取ったコンストラクタ
	Camera(const VECTOR charaarea, const int collStageHandle);

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