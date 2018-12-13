#pragma once
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "BaseMove.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "EnemyMove2.hpp"
#include "DropItemMove2.hpp"
#include "AdjustmentMachine.hpp"

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
	, skyBoxTex0, blockTex0, se_ballPickUp, terminal, terminalTex0, terminalTex1, terminalDescription };


	/// ステージ-------------------------------------
	
	// ステージのポインタ
	Stage* p_stage;

	// 階段のハンドル
	int stairsHandle;
	
	// 階段のテクスチャ
	int stairsTexture0;

	// 階段のポインタ
	std::vector<StageStairs*> vp_stageStairs;

	// 街灯のハンドル
	int streetLightHandle;

	// 街灯のテクスチャ
	int streetLightTexture0;
	int streetLightTexture1;

	// 街灯のポインタ
	std::vector<StageStreetLight*> vp_stageStreetLight;

	// パネルのポインタ
	StagePaneru* p_stagePaneru[10];
	

	/// キャラクター----------------------

	// キャラクターのポインタ
	CharacterSword* p_character;


	/// 敵---------------------

	// 敵の数
	const int enemyNum = 5;

	// 敵のポインタ
	EnemyMove2* p_enemy[5];

	// ドロップアイテム（１体に対して５個
	DropItemMove2* p_dropItem[25];

	int dropItemSE;

	// 何個のドロップアイテムを手に持ったか
	int catchDropItemNum;


	/// 精算機械-------------

	// 精算機械のポインタ
	AdjustmentMachine* p_adjustmentMachine;

	// 精密機械のシーンに移行
	bool changeAdjustmentScene;

	// 精密機械の補助説明画像
	int adjustmentDescriptionDraw;

	// 精密機械のプロセス
	void AdjustmentProcess();

	// 精密機械の描画
	void AdjustmentDraw();

	// 精密機械からオブジェクト生成するID
	enum class AdjustmentObject { Stairs, StreetLight };

	// 精密機械からオブジェクト生成
	void AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID);

	// 精密機械のシーンへのフェード
	int adjustmentSceneFeed;

	// 精密機械のフェードが終了したかどうか
	bool adjustmentFeedNow;

	// 精密機械の方に移るフェードかどうか
	bool adjustmentStartFeed;

	// 精密機械に移るときの画像
	int adjustmentDrawScreen;


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

