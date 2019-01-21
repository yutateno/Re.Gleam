#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Basic.hpp"


/*
セーブデータをセーブするのとロードする役割
*/
namespace FileSaveLoad
{
	// CSVに出力する
	bool Save();


	// CSVから読み込む
	bool Load();
}