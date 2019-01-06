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

#include <random>


/*
デフォルトシーンクラス、基本部分のコピペ用
*/
class DefaultMove : public BaseMove
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
		, bgm_Main
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

	// 多くの敵にダメージ受けた時に代表二体のみ受けるようにするカウント
	int charaSonmeEnemyDamageCount;


	/// 敵---------------------


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



	// 非同期テクスチャ切り替え
	void ThsTextureReload() override;


public:
	// コンストラクタ
	DefaultMove(const std::vector<int> v_file);

	// デストラクタ
	~DefaultMove();

	// 描画
	void Draw() override;

	// プロセス
	void Process() override;

	// カメラのプロセス
	void CameraProcess() override;

	// テクスチャの切り替え
	void TextureReload() override;

	// オプション画面でのモデル表示
	void OptionActorModel() override;

	// オプション画面でのモデル表示の準備
	void OptionActorModelBefore() override;
};


///// ムーブ4のロード素材-------------------------------------------------
//	// モデルデータ
//move4str[0] = "media\\こっち\\media\\ステージモデル\\move1_hantei.myn";
//move4str[1] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.myn";			// 5
//move4str[2] = "media\\こっち\\media\\paneru\\paneru.myn";
//move4str[3] = "media\\こっち\\media\\kaidan\\kaidan.myn";						// 1
//move4str[4] = "media\\こっち\\media\\kaidan\\kaidan_hantei.myn";
//move4str[5] = "media\\こっち\\media\\街灯\\Gaitou.myn";							// 2
//move4str[6] = "media\\こっち\\media\\スカイボックス\\SkyDome.myn";				// 1
//move4str[7] = "media\\こっち\\media\\ステージモデル\\move1_graphic.myn";
//
//// キャラのテクスチャデータ
//move4str[8] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
//move4str[9] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
//move4str[10] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
//move4str[11] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
//move4str[12] = "media\\こっち\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";
//
//// 階段のテクスチャデータ
//move4str[13] = "media\\こっち\\media\\kaidan\\whiteblack\\kaidan.pyn";
//
//// 街灯のテクスチャデータ
//move4str[14] = "media\\こっち\\media\\街灯\\whiteblack\\body_col.pyn";
//move4str[15] = "media\\こっち\\media\\街灯\\whiteblack\\lamp_COLandems.pyn";
//
//// スカイボックスのテクスチャデータ
//move4str[16] = "media\\こっち\\media\\スカイボックス\\whiteblack\\BlueSky.byn";
//
//// 精算機械データ
//move4str[17] = "media\\こっち\\media\\Terminal\\terminal.myn";					// 2
//
//// 精算機械テクスチャ
//move4str[18] = "media\\こっち\\media\\Terminal\\whiteblack\\Terminal.pyn";
//move4str[19] = "media\\こっち\\media\\Terminal\\whiteblack\\T_display.pyn";
//
//// 精密機械の補助説明
//move4str[20] = "media\\こっち\\media\\Terminal\\push.pyn";
//
//// 階段とそのあとの床データ
//move4str[21] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1.myn";			// 2
//
//// 階段とそのあとの床のテクスチャデータ
//move4str[22] = "media\\こっち\\media\\階段と床合体\\whiteblack\\kaidan.pyn";
//move4str[23] = "media\\こっち\\media\\階段と床合体\\whiteblack\\yuka.pyn";
//
//// 階段と床のあたり判定データ
//move4str[24] = "media\\こっち\\media\\階段と床合体\\kaidan_yuka1_hantei.myn";
//
//// キャラクター周りの3DSE
//move4str[25] = "media\\こっち\\media\\sound\\ジャンプ.wyn";
//move4str[26] = "media\\こっち\\media\\sound\\足音（廊下っぽいの）.wyn";
//move4str[27] = "media\\こっち\\media\\sound\\足音.wyn";
//move4str[28] = "media\\こっち\\media\\sound\\着地.wyn";
//move4str[29] = "media\\こっち\\media\\sound\\着地２.wyn";
//
//// キャラクターの攻撃の音
//move4str[30] = "media\\こっち\\media\\sound\\piano攻撃音1.wyn";
//move4str[31] = "media\\こっち\\media\\sound\\piano攻撃音2.wyn";
//move4str[32] = "media\\こっち\\media\\sound\\piano攻撃音3.wyn";
//
//// BGM
//move4str[33] = "media\\こっち\\media\\sound\\通常bgm.wyn";
//
//load4[0] = ELOADFILE::mv1model;
//load4[1] = ELOADFILE::mv1model;
//load4[2] = ELOADFILE::mv1model;
//load4[3] = ELOADFILE::mv1model;
//load4[4] = ELOADFILE::mv1model;
//load4[5] = ELOADFILE::mv1model;
//load4[6] = ELOADFILE::mv1model;
//load4[7] = ELOADFILE::mv1model;
//
//load4[8] = ELOADFILE::graph;
//load4[9] = ELOADFILE::graph;
//load4[10] = ELOADFILE::graph;
//load4[11] = ELOADFILE::graph;
//load4[12] = ELOADFILE::graph;
//
//load4[13] = ELOADFILE::graph;
//
//load4[14] = ELOADFILE::graph;
//load4[15] = ELOADFILE::graph;
//
//load4[16] = ELOADFILE::graph;
//
//load4[17] = ELOADFILE::mv1model;
//
//load4[18] = ELOADFILE::graph;
//load4[19] = ELOADFILE::graph;
//
//load4[20] = ELOADFILE::graph;
//
//load4[21] = ELOADFILE::mv1model;
//
//load4[22] = ELOADFILE::graph;
//load4[23] = ELOADFILE::graph;
//
//load4[24] = ELOADFILE::mv1model;
//
//load4[25] = ELOADFILE::sound3DSource;
//load4[26] = ELOADFILE::sound3DSource;
//load4[27] = ELOADFILE::sound3DSource;
//load4[28] = ELOADFILE::sound3DSource;
//load4[29] = ELOADFILE::sound3DSource;
//
//load4[30] = ELOADFILE::sound3DSource;
//load4[31] = ELOADFILE::sound3DSource;
//load4[32] = ELOADFILE::sound3DSource;
//
//load4[33] = ELOADFILE::soundStream;
///// --------------------------------------------------------------------