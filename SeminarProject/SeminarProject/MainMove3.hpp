#pragma once
#include "BaseMove.hpp"

class MainMove3 : public BaseMove
{
private:
	// 非同期テクスチャ切り替え
	void ThsTextureReload() override;


public:
	MainMove3(const std::vector<int> v_file);
	~MainMove3();

	// 描画
	void Draw() override;

	// プロセス
	void Process() override;

	// カメラのプロセス
	void CameraProcess() override;

	// テクスチャの切り替え
	void TextureReload() override;
};

