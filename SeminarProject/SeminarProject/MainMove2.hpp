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
#include "StageStairsRoad.hpp"

#include <random>

/*
オブジェクトを集めるシーン
箱を壊してドロップアイテムを得る、得たらフィールドの特定の地点で使用してオブジェクトを生成する。
*/
class MainMove2 : public BaseMove
{
private:
	// ロードで渡されるファイル
	enum EFILE {
		stage, characterAttack, paneru, stairs, stairsColl, streetLight, skyBox, block, drawStage
		, charaTex0, charaTex1, charaTex2, charaTex3, charaTex4, stairTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, blockTex0, se_ballPickUp, terminal, terminalTex0, terminalTex1, terminalDescription
		, stairsRoad, stairsRoadTex0, stairsRoadTex1, stairsRoadColl
		, block2D, character2D, streetLight2D, stairs2D, terminal2D, stairsRoad2D
		, jump3DSE, footCorridor3DSE, foot3DSE, landing3DSE, landingSecond3DSE
		, charaAttackOne3DSE, charaAttackTwo3DSE, charaAttackThree3DSE
		, se_ballPickUp2, nextStageBGM, attackUI, jumpUI, fastSpeedUI, optionUI
	};


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

	// 階段と床のハンドル
	int stairsRoadHandle;

	// 階段と床のテクスチャ
	int stairsRoadTexture0;
	int stairsRoadTexture1;

	// 階段と床のポインタ
	std::vector<StageStairsRoad*> vp_stageStairsRoad;
	

	/// キャラクター----------------------

	// キャラクターのポインタ
	CharacterSword* p_character;

	// 操作の説明画像
	enum class EOPERATION_UI { attack, jump, fastSpeed, option };
	int operationUIDraw[4];
	int operationUIFeed[4];
	int nextOperationUIFeed[4];
	bool opeFastOptionEnd;


	/// 敵---------------------

	// 敵の数
	const int enemyNum = 50;

	// 敵のポインタ
	EnemyMove2* p_enemy[50];

	// ドロップアイテム（１体に対して５個
	DropItemMove2* p_dropItem[250];

	int dropItemSE;

	// 何個のドロップアイテムを手に持ったか
	int catchDropItemNum;

	// 一番キャラクターに近い敵
	int mostNearEnemyDistance;
	VECTOR mostNearEnemyScreenArea;
	int lockONNowEnemyID;


	/// 精算機械-----------------------------------------------------------------------

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
	enum class AdjustmentObject { Stairs, StairsRoad, StreetLight};

	// 精密機械からオブジェクト生成
	void AdjuctmentCreate(VECTOR area, AdjustmentObject obujectID, float direction);

	// 精密機械のシーンへのフェード
	int adjustmentSceneFeed;

	// 精密機械のフェードが終了したかどうか
	bool adjustmentFeedNow;

	// 精密機械の方に移るフェードかどうか
	bool adjustmentStartFeed;

	// 精密機械に移るときの画像
	int adjustmentDrawScreen;

	// 精密機械中に映る2Dの画像
	int adjustment2DDraw[6];

	// 精密機械にて配置するオブジェクトを決定したかどうか
	bool adjustmentSelectObject;

	// どのオブジェクトを配置するかどうか
	AdjustmentObject adjustmentSelectObjectNumber;

	// 配置するオブジェクトの座標
	VECTOR adjustmentArrangementArea;

	// 配置するオブジェクトの向き
	float adjustmentArrangementDire;

	// スティックの押し倒しかどうかを調べる(DLLXinputでやるべきなんだろうかとりあえず
	int adjustmentControllStick[2];
	/// -------------------------------------------------------------------------------


	/// カメラ-----------------------
	
	// カメラのポインタ
	Camera* p_camera;


	// 影の描画
	void ShadowDraw();

	// 攻撃のプロセス
	void AttackProcess();


	// 非同期テクスチャ切り替え
	void ThsTextureReload() override {};


	/// Effekseer関連-----------------------
	int effectAttack;
	int playingEfAttack;


	// BGMの音量変更を一度だけ呼ぶように
	int bgmOnceVolumeChange;


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
	void TextureReload() override {}

	// オプション画面でのモデル表示
	void OptionActorModel() override;

	// オプション画面でのモデル表示の準備
	void OptionActorModelBefore() override;

	// オプション画面でのモデル表示の後始末
	void OptionActorModelAfter() override;
};

