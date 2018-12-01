#pragma once
#include "LoadScreen.hpp"


class LoadThread
{
private:
	// 非同期を行う
	std::thread ths;

	// ロードした個数
	int num;

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


	/// ゲッターセッター
	
	// ロードしたものを渡す
	const std::vector<int> GetFile() const;

	// ロードを終えた数
	const int GetNum() const;
};