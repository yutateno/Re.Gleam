#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Basic.hpp"

namespace FileSaveLoad
{
	// CSVに出力する
	bool Save();


	// CSVから読み込む
	bool Load();
}