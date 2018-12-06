#pragma once
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "EnemyMove2.hpp"

#include <random>

/*
オブジェクトを集めるシーン
箱を壊してドロップアイテムを得る、得たらフィールドの特定の地点で使用してオブジェクトを生成する。
*/
class MainMove2 : public BaseMove
{
private:
	// ロードで渡されるファイル
	enum EFILE { stage, characterAttack, paneru, stairs, stairsColl, streetLight, skyBox, block, drawStage
	, charaTex0, charaTex1, charaTex2, charaTex3, charaTex4, stairTex0, streetLightTex0, streetLightTex1
	, skyBoxTex0, blockTex0 };


	/// ステージ-------------------------------------
	
	// ステージのポインタ
	Stage* p_stage;

	// 階段のポインタ
	StageStairs* p_stageStairs[10];

	// 街灯のポインタ
	StageStreetLight* p_stageStreetLight[30];

	// パネルのポインタ
	StagePaneru* p_stagePaneru[10];


	/// キャラクター----------------------

	// キャラクターのポインタ
	CharacterSword* p_character;


	/// 敵---------------------

	// 敵のポインタ
	EnemyMove2* p_enemy;


	/// カメラ-----------------------
	// カメラのポインタ
	Camera* p_camera;


	// 影の描画
	void ShadowDraw();

	// 攻撃のプロセス
	void AttackProcess();


	// 非同期テクスチャ切り替え
	void ThsTextureReload() override;


public:
	// コンストラクタ
	MainMove2(const std::vector<int> v_file);

	// デストラクタ
	~MainMove2();

	
	// 描画
	void Draw() override;

	// プロセス
	void Process() override;

	// カメラのプロセス
	void CameraProcess() override;

	// テクスチャの切り替え
	void TextureReload() override;
};

