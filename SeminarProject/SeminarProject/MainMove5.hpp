#pragma once
#include "BaseMove.hpp"
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "AdjustmentMachine.hpp"
#include "StageStairsRoad.hpp"
#include "OrdinaryPerson.hpp"
#include "EnemyMove5.hpp"
#include "EnemyBossBefore.hpp"

#include <random>


/*
明かりを取り戻すシーン
子供を追いかけまわす
*/
class MainMove5 : public BaseMove
{
private:
	// ロードで渡されるファイル
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, terminalModel, terminalTex0, terminalTex1, terminalDesc
		, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, bgm_Main, enemyModel, enemyTex0, ordinaryModel, ordinaryTex0
		, moveDescription, se_saveOn
	};


	/// ステージ-----------------------------------------

	// ステージのポインタ
	Stage* p_stage;

	// 階段のポインタ
	std::vector<StageStairs*> vp_stageStairs;

	// 街灯のポインタ
	std::vector<StageStreetLight*> vp_stageStreetLight;

	// パネルのポインタ
	StagePaneru* p_stagePaneru[10];

	// 階段と床のポインタ
	std::vector<StageStairsRoad*> vp_stageStairsRoad;


	/// キャラクター-------------------

	// キャラクターのポインタ
	CharacterSword* p_character;


	/// 敵---------------------

	// ボスのあれ
	EnemyBossBefore* p_enemyBossBefore;

	// 敵のポインタ
	EnemyMove5* p_enemyMove[50];

	// 敵の数
	const int enemyNum = 50;

	// 敵を手に入れた数
	int enemyCatchNum;

	// 一定数手に入れたときにSEを流す
	bool certainCatchSEDo;


	/// 一般人------------------

	// 一般人のポインタ
	std::vector<OrdinaryPerson*> vp_ordinaryPerson;


	/// 精密機械------------------------------

	// 精密機械のポインタ
	AdjustmentMachine* p_adjustmentMachine;

	// 精密機械の説明補助画像
	int adjustmentDescDraw;


	/// カメラ------------------

	// カメラのポインタ
	Camera* p_camera;


	// 影の描画
	void ShadowDraw();

	// 攻撃のプロセス
	void AttackProcess();


public:
	// コンストラクタ
	MainMove5(const std::vector<int> v_file);

	// デストラクタ
	~MainMove5();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;


	// カメラのプロセス
	void CameraProcess() override;

	// テクスチャの切り替え
	void TextureReload() override;

	// 非同期テクスチャ切り替え
	void ThsTextureReload() override;

	// オプション画面でのモデル表示
	void OptionActorModel() override;

	// オプション画面でのモデル表示の準備
	void OptionActorModelBefore() override;

	// オプション画面でのモデル表示の後始末
	void OptionActorModelAfter() override;
};
