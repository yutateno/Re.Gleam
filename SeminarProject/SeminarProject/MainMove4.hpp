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
#include "EnemyMove4.hpp"
#include "EnemyBossBefore.hpp"

#include <random>


/*
人を集めるシーン
敵を倒して元通りに戻せ
*/
class MainMove4 : public BaseMove
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
		, bgm_Main, ordiPersonModel, ordiPersonTex0, enemyModel, enemyTex0
		, bgm_battle, moveDescription, damageDraw0, damageDraw1, damageDraw2
		, damageBlood0, damageBlood1, damageBlood2, damageBlood3, damageBlood4
		, damageBlood5, damageBlood6, damageBlood7, damageBlood8, damageBlood9
		, se_enemyDamage
	};


	/// ステージ-------------------------------------------------------------------------

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


	/// 人------------------------------------------------------------------------------

	// 人のポインタ
	OrdinaryPerson* p_ordinaryPerson[50];

	// 人の数
	const int ordinaryNum = 50;


	/// 敵-----------------------------------------------------------------------------

	// ボスのあれ
	EnemyBossBefore* p_enemyBossBefore;

	// 敵のポインタ
	EnemyMove4* p_enemyMove;

	// 敵がダメージ受けているかどうか
	bool enemyDamage;

	// 敵とプレイヤーの距離
	int enemyAndPlayerDistance;

	// 敵のスクリーン座標
	VECTOR enemyScreenArea;


	/// 精密機械-----------------------------------------------------------------------

	// 精密機械のポインタ
	AdjustmentMachine* p_adjustmentMachine;

	// 精密機械の説明補助画像
	int adjustmentDescDraw;


	/// カメラ-------------------------------------------------------------------------

	// カメラのポインタ
	Camera* p_camera;


	/// ムーブ内の動きに関して--------------------------------------------------------

	// 影の描画
	void ShadowDraw();

	// 攻撃のプロセス
	void AttackProcess();


	/// 音に関して-------------------------------------------------------------------

	// BGMの切り替えが行われたかどうか
	bool nowBattleBGM;


	/// エフェクトに関して----------------------------------------------------------

	int effeckBack[10];		// ダメージ演出の10種類
	int playingEfDamage;		// ダメージ演出用
	int effectAttack;
	int playingEfAttack;


public:
	// コンストラクタ
	MainMove4(const std::vector<int> v_file);

	// デストラクタ
	~MainMove4();


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
