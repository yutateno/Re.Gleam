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
#include "EnemyMove3Slime.hpp"
#include "EnemyMove3CrayonHuman.hpp"
#include "DropItemMove3.hpp"
#include "EnemyBossBefore.hpp"

#include <random>


/*
色を集めるシーン
敵を倒して色を取り戻す
*/
class MainMove3 : public BaseMove
{
private:
	// ロードで渡されるファイル
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, se_ballPickUp, terminalModel, terminalTex0, terminalTex1
		, terminalDesc, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, se_ballPickUp2, bgm_Main, slimeModel, slimeTex0, crayonHumanModel
		, crayonHumanTex0, dropItemModel, dropItemTex0
		, damageDraw0, damageDraw1, damageDraw2, damageBlood0, damageBlood1
		, damageBlood2, damageBlood3, damageBlood4, damageBlood5, damageBlood6
		, damageBlood7, damageBlood8, damageBlood9, enemyAttackSE, crayonDeadSE
		, fightBGM, moveDescription, adjustAnother, adjustChara, adjustEnemy
		, adjustStairs, adjustStairsRoad, adjustStreetLight
	};


	/// ステージ------------------------------------------------------------------------

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


	/// キャラクター--------------------------------------------------------------------

	// キャラクターのポインタ
	CharacterSword* p_character;

	// 多くの敵にダメージ受けた時に代表二体のみ受けるようにするカウント
	int charaSomeEnemyDamageCount;

	// ダメージ数値
	int damageCount;

	// 直前のダメージカウント
	int preDamageCount;

	// ダメージのブレンド数値
	int damageBlend[10];

	// ダメージ表示画像
	int damageDraw[3];

	// ダメージを受けていないカウント
	int notDamageCount;

	// ダメージ表示画像のフレーム
	int damageDrawFrame;

	// ダメージ画像のID
	int damageDrawID;

	// ダメージ画像の色覚差し替え
	void DamageTextureReload();


	/// 敵------------------------------------------------------------------------------

	// ボスのあれ
	EnemyBossBefore* p_enemyBossBefore;

	// スライムのポインタ
	EnemyMove3Slime* p_enemySlime[10];

	// スライムのダメージ瞬間
	bool enemySlimeDamage[10];

	// スライムの数
	const int enemySlimeNum = 10;

	// クレヨンヒューマンのポインタ
	EnemyMove3CrayonHuman* p_enemyCrayonHuman[10];

	// スライムがダメージ受けているかどうか
	bool enemyCrayonHumanDamage[10];

	// クレヨンヒューマンの数
	const int enemyCrayonHumanNum = 10;

	// ドロップアイテムの数
	const int dropItemNum = 100;

	// ドロップアイテム
	DropItemMove3* p_dropItem[100];

	// 何個のドロップアイテムを手に持ったか
	int catchDropItemNum;

	// 一番プレイヤーに近い敵の距離
	int mostNearEnemyDistance;

	// 一番プレイヤーに近い敵のスクリーン座標
	VECTOR mostNearEnemyScreenArea;

	// ロックオンしている敵のID
	int lockONNowEnemyID;

	// ロックオンしている敵がスライムかどうか
	bool lockOnEnemySlime;


	/// 精密機械------------------------------------------------------------------------

	// 精密機械のポインタ
	AdjustmentMachine* p_adjustmentMachine;

	// 精密機械の説明補助画像
	int adjustmentDescDraw;

	// 精密機械のシーンに移行
	bool changeAdjustmentScene;

	// 精密機械のプロセス
	void AdjustmentProcess();

	// 精密機械の描画
	void AdjustmentDraw();

	// 精密機械のシーンへのフェード
	int adjustmentSceneFeed;

	// 精密機械のフェードが終了したかどうか
	bool adjustmentFeedNow;

	// 精密機械の方に移るフェードかどうか
	bool adjustmentStartFeed;

	// 精密機械から色を戻すするID
	enum class AdjustmentSelect { 
		chara, anotherActor, enemy
		, streetLight, stairsRoad, stairs
	};

	// どのオブジェクトの色を取り戻すかどうか
	AdjustmentSelect adjustmentSelectTexChange;
	
	// スティックの押し倒しかどうかを調べる
	int adjustmentControllStick[2];

	// どのオブジェとの色を取り戻すか選択する画像
	int adjustmentSelectTexDraw[6];


	/// カメラ-------------------------------------------------------------------------

	// カメラのポインタ
	Camera* p_camera;


	/// ムーブ内の動きに関して--------------------------------------------------------

	// 影の描画
	void ShadowDraw();

	// 攻撃のプロセス
	void AttackProcess();


	/// エフェクトに関して------------------------------------------------------------
	
	int effeckBack[10];		// ダメージ演出の10種類
	int playingEfDamage;		// ダメージ演出用
	int effectAttack;
	int playingEfAttack;

	
	/// 音に関して--------------------------------------------------------------------

	// BGMの切り替えが行われたかどうか
	bool nowBattleBGM;


	/// 乱数値------------------------------------------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	MainMove3(const std::vector<int> v_file);

	// デストラクタ
	~MainMove3();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;


	// カメラのプロセス
	void CameraProcess() override;

	// 非同期テクスチャ切り替え
	void ThsTextureReload() override;

	// オプション画面でのモデル表示
	void OptionActorModel() override;

	// オプション画面でのモデル表示の準備
	void OptionActorModelBefore() override;

	// オプション画面でのモデル表示の後始末
	void OptionActorModelAfter() override;
};
