#include "EnemyBossBefore.hpp"



/// ------------------------------------------------------------------------------------------------
EnemyBossBefore::EnemyBossBefore() : BasicCreature()
{
	// 3Dモデルの読み込み
	this->modelHandle = -1;
	LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.myn", modelHandle, ELOADFILE::mv1model);


	// 初期化
	modelHeight = 100.0f;
	modelWidth = 100.0f;
	shadowHeight = 100.0f;
	shadowSize = 100.0f;
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	jumpUpNow = false;


	// 乱数生成
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> modelView(0, 1);	// モデルの実態を描画するかどうか
	// モデルを描画しない場合
	if (modelView(mt) == 0)
	{
		std::uniform_int_distribution<> areaX(-4500, 4500);        // X軸のどこに配置するか
		std::uniform_int_distribution<> areaZ(-4500, 4500);        // Z軸のどこに配置するか


		// 座標を設定する
		area.x = static_cast<float>(areaX(mt));
		area.y = 0.0f;
		area.z = static_cast<float>(areaZ(mt));


		// テクスチャ適応
		int tempTex0 = -1;
		int tempTex1 = -1;
		int tempTex2 = -1;
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\whiteblack.pyn", tempTex0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\whiteblack.pyn", tempTex1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\whiteblack.pyn", tempTex2, ELOADFILE::graph);
		MV1SetTextureGraphHandle(this->modelHandle, 0, tempTex0, false);
		MV1SetTextureGraphHandle(this->modelHandle, 1, tempTex1, false);
		MV1SetTextureGraphHandle(this->modelHandle, 2, tempTex2, true);
		GRAPHIC_RELEASE(tempTex0);
		GRAPHIC_RELEASE(tempTex1);
		GRAPHIC_RELEASE(tempTex2);
	} /// if (modelView(mt) == 0)
	// モデルを描画する場合
	else
	{
		std::uniform_int_distribution<> texture(0, 3);        // どのテクスチャを適応するか
		std::uniform_int_distribution<> setArea(0, 5);        // どこに配置するか

		/// テクスチャの適応---------------------------------------------------------------------------------------------------------------------------

		int tempTex0 = -1;
		int tempTex1 = -1;
		int tempTex2 = -1;
		switch (texture(mt))
		{
			// 白黒にする
		case 0:
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\whiteblack.pyn", tempTex0, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\whiteblack.pyn", tempTex1, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\whiteblack.pyn", tempTex2, ELOADFILE::graph);
			break;
			// 通常色にする
		case 1:
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\normal.pyn", tempTex0, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\normal.pyn", tempTex1, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\normal.pyn", tempTex2, ELOADFILE::graph);
			break;
			// D型補正にする
		case 2:
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\D.pyn", tempTex0, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\D.pyn", tempTex1, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\D.pyn", tempTex2, ELOADFILE::graph);
			break;
			// P型補正にする
		case 3:
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\wing\\P.pyn", tempTex0, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\body\\P.pyn", tempTex1, ELOADFILE::graph);
			LoadFile::MyLoad("media\\ラスボス＿光\\モーション\\motion_Boss1.fbm\\head\\P.pyn", tempTex2, ELOADFILE::graph);
			break;
		default:
			break;
		}
		MV1SetTextureGraphHandle(this->modelHandle, 0, tempTex0, false);
		MV1SetTextureGraphHandle(this->modelHandle, 1, tempTex1, false);
		MV1SetTextureGraphHandle(this->modelHandle, 2, tempTex2, true);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, 50);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, 50);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 2, 50);
		/// テクスチャの適応---------------------------------------------------------------------------------------------------------------------------


		// 座標を決める
		switch (setArea(mt))
		{
		case 0:
			area = VGet(5000, 0, 0);
			break;
		case 1:
			area = VGet(500.0f * 6, 300.0f * 6, 100.0f * 6);
			break;
		case 2:
			area = VGet(0, 3000, 0);
			break;
		case 3:
			area = VGet(-5000, 0, 0);
			break;
		case 4:
			area = VGet(0, 0, 5000);
			break;
		case 5:
			area = VGet(0, 0, -5000);
			break;
		default:
			break;
		}
	} /// else(!if (modelView(mt) == 0))
	

	// ３Ｄモデルのアニメーションをアタッチする
	attachMotion = MV1AttachAnim(this->modelHandle, 1, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// モデルの座標を設定
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, 0.0f, 0.0f));
	preArea = area;
	MV1SetPosition(this->modelHandle, area);
} /// EnemyBossBefore::EnemyBossBefore() : BasicCreature(true)



/// ------------------------------------------------------------------------------------------------
EnemyBossBefore::EnemyBossBefore(const int modelHandle, const int modelTex0
	, const int modeltex1, const int modelTex2)
{
	// 3Dモデルの読み込み
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// 初期化
	modelHeight = 100.0f;
	modelWidth = 100.0f;
	shadowHeight = 100.0f;
	shadowSize = 100.0f;
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	jumpUpNow = false;
	area = VGet(4000.0f, 200.0f, 0.0f);
	angle = -DX_PI_F / 2.0f;


	// テクスチャの適応
	MV1SetTextureGraphHandle(this->modelHandle, 0, modelTex0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, modeltex1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, modelTex2, false);


	// ３Ｄモデルの0番目のアニメーションをアタッチする
	attachMotion = MV1AttachAnim(this->modelHandle, 1, -1, FALSE);


	// アタッチしたアニメーションの総再生時間を取得する
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// 第二引数の回転角度をセット
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, angle, 0.0f));
	// モデルの座標を更新
	preArea = area;
	MV1SetPosition(this->modelHandle, area);
} /// EnemyBossBefore::EnemyBossBefore(const int modelHandle, const int modelTex0



/// ------------------------------------------------------------------------------------------------
EnemyBossBefore::~EnemyBossBefore()
{
	// モデル開放
	MODEL_RELEASE(modelHandle);
}



/// ------------------------------------------------------------------------------------------------
void EnemyBossBefore::Process()
{
	// モーションの実態
	Player_AnimProcess();
}



/// ------------------------------------------------------------------------------------------------
void EnemyBossBefore::MoveReturn()
{
	// 向きを回転させる
	if (angle <= DX_PI_F / 2.0f) angle += DX_PI_F / 90.0f;
	else Player_PlayAnim(0);
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, angle, 0.0f));
}



/// ------------------------------------------------------------------------------------------------
void EnemyBossBefore::AreaSetDown()
{
	// 地面に埋まらせる
	area.y -= 2.0f;
	MV1SetPosition(modelHandle, this->area);
}
