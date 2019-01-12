#include "Basic.hpp"


// extern static 変数
ESceneNumber BASICPARAM::e_preScene;		// 直前のシーン
ESceneNumber BASICPARAM::e_nowScene;		// 今のシーン
ETextureColor BASICPARAM::e_preTextureColor;	// 直前のテクスチャの色
ETextureColor BASICPARAM::e_TextureColor;	// テクスチャの色
bool BASICPARAM::nowCameraOrtho;	// 今のカメラの形式が正射影かどうか
int BASICPARAM::winWidth;
int BASICPARAM::winHeight;
int BASICPARAM::bitColor;
bool BASICPARAM::startFeedNow;
bool BASICPARAM::endFeedNow;
bool BASICPARAM::paneruDrawFlag;
int BASICPARAM::stairsNum;
std::vector<VECTOR> BASICPARAM::v_stairsArea;
std::vector<float> BASICPARAM::v_stairsAngle;
int BASICPARAM::streetLightNum;
std::vector<VECTOR> BASICPARAM::v_streetLightArea;
std::vector<float> BASICPARAM::v_streetLightAngle;
int BASICPARAM::stairsRoadNum;
std::vector<VECTOR> BASICPARAM::v_stairsRoadArea;
std::vector<float> BASICPARAM::v_stairsRoadAngle;
bool BASICPARAM::cameraHorizonReturn;
bool BASICPARAM::cameraVerticalReturn;
bool BASICPARAM::charaTextureWhiteBlack;
bool BASICPARAM::enemyTextureWhiteBlack;
bool BASICPARAM::stairsTextureWhiteBlack;
bool BASICPARAM::stairsRoadTextureWhiteBlack;
bool BASICPARAM::lightStreetTextureWhiteBlack;
bool BASICPARAM::anothreTextureWhiteBlack;



/// debug-----------------------------------------------------------------------------------------------------------------------
#ifdef _DEBUG
bool MyDebug::characterDrawFlag = false;
bool MyDebug::characterSwordDrawFlag = false;
bool MyDebug::ordinaryDrawFlag = false;
bool MyDebug::enemyOneDrawFlag = false;
bool MyDebug::enemyTwoDrawFlag = false;
bool MyDebug::adjustmentMachineDrawFlag = false;
bool MyDebug::dropItemOneDrawFlag = false;
bool MyDebug::stageDrawFlag = false;
bool MyDebug::moveOneDrawFlag = false;
bool MyDebug::enemyThreeSlimeDrawFlag = false;
bool MyDebug::enemyThreeCrayonHumanDrawFlag = false;
bool MyDebug::enemyThreeSlimeSearchLineDrawFlag = false;
bool MyDebug::enemyThreeCrayonHumanSearchLineDrawFlag = false;

void MyDebug::Init()
{
	checkFlag = false;
	characterDrawFlag = false;
	characterSwordDrawFlag = false;
	ordinaryDrawFlag = false;
	enemyOneDrawFlag = false;
	enemyTwoDrawFlag = false;
	adjustmentMachineDrawFlag = false;
	dropItemOneDrawFlag = false;
	stageDrawFlag = false;
	moveOneDrawFlag = false;
	enemyThreeSlimeDrawFlag = false;
	enemyThreeCrayonHumanDrawFlag = false;
	enemyThreeSlimeSearchLineDrawFlag = false;
	enemyThreeCrayonHumanSearchLineDrawFlag = false;
}

void MyDebug::DebugProcess()
{
	if (CheckHitKey(KEY_INPUT_LCONTROL) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
	{
		checkFlag = !checkFlag;
	}

	if (CheckHitKey(KEY_INPUT_RCONTROL) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
	{
		Init();
	}

	if (checkFlag)
	{
		DrawBox(960, 0, 1920, 540, GetColor(255, 255, 255), true);
		DrawFormatString(970, 520, GetColor(0, 0, 0), "checkFlag: LCONTROL: %s", checkFlag ? "true" : "false");
		DrawFormatString(970, 500, GetColor(0, 0, 0), "Init(): RCONTROL");
		
		DrawFormatString(970, 10, GetColor(0, 0, 0), "characterDrawFlag: A: %s", characterDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_A) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			characterDrawFlag = !characterDrawFlag;
		}

		DrawFormatString(970, 30, GetColor(0, 0, 0), "characterSwordDrawFlag: S: %s", characterSwordDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_S) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			characterSwordDrawFlag = !characterSwordDrawFlag;
		}

		DrawFormatString(970, 50, GetColor(0, 0, 0), "ordinaryDrawFlag: D: %s", ordinaryDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_D) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			ordinaryDrawFlag = !ordinaryDrawFlag;
		}

		DrawFormatString(970, 70, GetColor(0, 0, 0), "enemyOneDrawFlag: F: %s", enemyOneDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_F) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyOneDrawFlag = !enemyOneDrawFlag;
		}

		DrawFormatString(970, 90, GetColor(0, 0, 0), "enemyTwoDrawFlag: G: %s", enemyTwoDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_G) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyTwoDrawFlag = !enemyTwoDrawFlag;
		}

		DrawFormatString(970, 110, GetColor(0, 0, 0), "adjustmentMachineDrawFlag: H: %s", adjustmentMachineDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_H) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			adjustmentMachineDrawFlag = !adjustmentMachineDrawFlag;
		}

		DrawFormatString(970, 130, GetColor(0, 0, 0), "dropItemOneDrawFlag: J: %s", dropItemOneDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_J) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			dropItemOneDrawFlag = !dropItemOneDrawFlag;
		}

		DrawFormatString(970, 150, GetColor(0, 0, 0), "stageDrawFlag: K: %s", stageDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_K) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			stageDrawFlag = !stageDrawFlag;
		}

		DrawFormatString(970, 170, GetColor(0, 0, 0), "moveOneDrawFlag: L: %s", moveOneDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_L) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			moveOneDrawFlag = !moveOneDrawFlag;
		}

		DrawFormatString(970, 190, GetColor(0, 0, 0), "enemyThreeSlimeDrawFlag: Q: %s", enemyThreeSlimeDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_Q) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyThreeSlimeDrawFlag = !enemyThreeSlimeDrawFlag;
		}

		DrawFormatString(970, 210, GetColor(0, 0, 0), "enemyThreeCrayonHumanDrawFlag: W: %s", enemyThreeCrayonHumanDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_W) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyThreeCrayonHumanDrawFlag = !enemyThreeCrayonHumanDrawFlag;
		}

		DrawFormatString(970, 230, GetColor(0, 0, 0), "enemyThreeSlimeSearchLineDrawFlag: E: %s", enemyThreeSlimeSearchLineDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_E) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyThreeSlimeSearchLineDrawFlag = !enemyThreeSlimeSearchLineDrawFlag;
		}

		DrawFormatString(970, 250, GetColor(0, 0, 0), "enemyThreeCrayonHumanSearchLineDrawFlag: R: %s", enemyThreeCrayonHumanSearchLineDrawFlag ? "true" : "false");
		if (CheckHitKey(KEY_INPUT_R) == 1 && DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_BACK) == 1)
		{
			enemyThreeCrayonHumanSearchLineDrawFlag = !enemyThreeCrayonHumanSearchLineDrawFlag;
		}
	}
}
#endif // _DEBUG
/// debug-----------------------------------------------------------------------------------------------------------------------
