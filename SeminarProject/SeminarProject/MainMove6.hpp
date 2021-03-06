#pragma once
#include "BaseMove.hpp"
#include "Stage.hpp"
#include "CharacterSword.hpp"
#include "Camera.hpp"
#include "StageStairs.hpp"
#include "StageStreetLight.hpp"
#include "StagePaneru.hpp"
#include "StageStairsRoad.hpp"
#include "OrdinaryPerson.hpp"
#include "EnemyBossAfter.hpp"
#include "EnemyBossBefore.hpp"
#include "CameraMove6.hpp"
#include "ChaseBlock.hpp"
#include "MagicIcePillar.hpp"


/*
ラスボスシーン
倒せ
*/
class MainMove6 : public BaseMove
{
private:
	// ロードで渡されるファイル
	enum EFILE {
		stageCollModel, charaModel, paneruModel, stairsDrawModel, stairsCollModel
		, streetLightModel, skyBoxModel, stageDrawModel, charaTex0, charaTex1
		, charaTex2, charaTex3, charaTex4, stairsTex0, streetLightTex0, streetLightTex1
		, skyBoxTex0, stairsRoadDrawModel, stairsRoadTex0, stairsRoadTex1
		, stairsRoadCollModel, se_jump, se_footCorridor, se_foot, se_landing
		, se_landingSecond, se_attackOne, se_attackTwo, se_attackThrid
		, bgm_Main, ordinaryModel, ordinaryTex0, approachUINear, approachUIYes
		, approachUINo, bossBeforeModel, bossBeforeTex0, bossBeforeTex1, bossBeforeTex2
		, end_Title, end_DxLib, end_Effekseer, end_Graphic, end_Program, end_Sound
		, end_Special, end_Test, end_ThanksLib, end_Youser, bgm_end, bossAfterTex0
		, bossAfterTex1, bossAfterTex2, movieSkip, charaIcon, charaIconBack
		, charaGage, charaGageBar, enemyGageBar, warpDescDraw
	};

	
	/// ステージ-----------------------------------------------------------------------

	// ステージのポインタ
	Stage* p_stage;

	// 階段のポインタ
	std::vector<StageStairs*> vp_stageStairs;

	// 街灯のポインタ
	std::vector<StageStreetLight*> vp_stageStreetLight;

	// 階段と床のポインタ
	std::vector<StageStairsRoad*> vp_stageStairsRoad;
	
	// パネルの個数
	const int paneruNum = 70;

	// パネルのポインタ
	StagePaneru* p_stagePaneru[70];

	// パネルの4点にそれぞれ到達したかどうか
	bool paneruArrival[4];


	/// キャラクター-------------------------------------------------------------------

	// キャラクター
	CharacterSword* p_character;

	// ダメージ数値
	int damageCount;

	// ワープの補助説明画像
	int warpDesc;


	/// 敵----------------------------------------------------------------------------

	// ボスのあれ
	EnemyBossBefore* p_enemyBossBefore;

	// ボスの本体
	EnemyBossAfter* p_enemyBossAfter;

	// ボスに近づいたときにあらわれるUI
	int approachBossUIDraw[3];

	//ボスに近づいたときにあらわれるUIにてどちらを選択したか
	bool approachUISelect;
	
	// スティックの押し倒しかどうかを調べる
	int adjustmentControllStick[2];

	// どの攻撃を行うか
	EAttackPattern e_attackPattern;

	// 氷柱の数
	const int icePillarNum = 10;

	// 氷柱のポインタ
	MagicIcePillar* p_magicIcePillar[10];

	// 追尾箱のポインタ
	ChaseBlock* p_chaseBlock[2];

	// 攻撃を受けたかどうか
	bool enemyHitDamage;

	// ボスのダメージカウント
	int enemyDamageCount;

	// プレイヤーの攻撃によるダメージ量
	int enemyDamageHitCount;


	/// 一般人-----------------------------------------------------------------------

	// 一般人のポインタ
	std::vector<OrdinaryPerson*> vp_ordinaryPerson;


	/// カメラ----------------------------------------------------------------------

	// カメラのポインタ
	Camera* p_camera;

	// ムービー中のカメラ
	CameraMove6* p_cameraMove;

	// ボス倒し後の画面揺れのパラメータ
	float cameraShakeParam;


	/// 影--------------------------------------------------------------------------
	
	// 影の描画
	void ShadowDraw();


	/// 攻撃及びあたり判定---------------------------------------------------------

	// 攻撃のプロセス
	void AttackProcess();


	/// シーン内での取り分け------------------------------------------------------

	// シーンのID分け
	enum class ESceneMove6 { First, Movie, Battle, Last };
	ESceneMove6 e_nowMove;

	/// 最初のシーン-------------------------------------------------

	// 最初の描画
	void FirstDraw();

	// 最初のプロセス
	void FirstProcess();

	/// ムービー中のシーン-----------------------------------------

	// ムービー中の描画
	void MovieDraw();

	// ムービー中のプロセス
	void MovieProcess();

	// ムービー中の動きをまとめる時間フレーム
	int movieFrame;

	// ムービー前が正射影カメラだったかどうか
	bool movieBeforeCameraOrtho;

	// ムービーのスキップの仕方を教える画像
	int movieSkipDraw;

	/// 戦闘のシーン-----------------------------------------------

	// 戦闘の描画
	void BattleDraw();

	// 戦闘のプロセス
	void BattleProcess();

	// 各々の体力を知らしめる画像のID
	enum class EHealDraw{
		icon, iconBack, gage, gageBar, enemyGage
	};

	// 各々の体力を知らしめる画像
	int battleHealDraw[5];

	// 戦闘UIのテクスチャ差し替え
	void BattleTextureReload();

	/// 最後のシーン----------------------------------------------

	// 最後の描画
	void LastDraw();

	// 最後のプロセス
	void LastProcess();

	// エンドロール用画像
	enum class EEndRolUI {
		title, program, graphic, sound
		, libThanks, dxlib, effekseer, specialThanks, test, youser
	};
	int endrolDraw[10];


	/// エフェクトに関して----------------------------------------

	int effectWarp;
	int playingEfWarp[4];


	/// 乱数値-----------------------------------------------------

	std::random_device rnd;


public:
	// コンストラクタ
	MainMove6(const std::vector<int> v_file);

	// デストラクタ
	~MainMove6();


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
