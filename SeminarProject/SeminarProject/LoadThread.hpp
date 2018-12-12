#pragma once
#include "LoadScreen.hpp"


class LoadThread
{
private:
	// 非同期を行う
	std::thread ths;

	// ロードした個数
	int num;

	// 最大ロード個数
	int maxNum;

	// ロードしたもの
	std::vector<int> fileName;

	// ロード画面のポインタ
	LoadScreen* p_loadScreen;


	// 非同期を行うメソッド
	void MyNextLoad(const std::string path, int& file, const ELOADFILE type);

	   
public:
	// コンストラクタ
	LoadThread();

	// デストラクタ
	~LoadThread();


	// 行う
	void Process(const int max, const std::string* path, const ELOADFILE* type);

	// 描画
	void Draw();


	/// ゲッターセッター
	
	// ロードしたものを渡す
	const std::vector<int> GetFile() const { return fileName; }

	// ロードを終えた数
	const int GetNum() const { return num; };
};