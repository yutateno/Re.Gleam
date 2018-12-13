#include "Basic.hpp"

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
int BASICPARAM::streetLightNum;
std::vector<VECTOR> BASICPARAM::v_streetLightArea;