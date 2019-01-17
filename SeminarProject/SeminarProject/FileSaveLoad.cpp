#include "FileSaveLoad.hpp"


namespace FileSaveLoad
{
	// CSVに出力する
	bool Save()
	{
		std::ofstream saveFile;

		saveFile.open("media\\こっち\\media\\Save.cyn");

		// ファイル読み込み失敗
		if (saveFile.fail())
		{
			std::cerr << "SaveError" << std::endl;
			return false;
		}
		else
		{
			//// 読み込み成功
			//for (int i = 0, n = static_cast<int>(v_className.size()); i < n; i++)
			//{
			//	saveFile << v_className[i] << "," << v_areaX[i] << "," << v_areaY[i] << "," << v_areaZ[i] << "," << v_direction[i];
			//	saveFile << std::endl;
			//}
			saveFile << static_cast<int>(BASICPARAM::e_nowScene) << std::endl;
		}

		// ファイルを閉じる
		saveFile.close();

		return true;
	}


	// CSVから読み込む
	bool Load()
	{
		std::ifstream ifs;
		std::vector<std::vector<std::string>> mapdata;
		ifs.open("media\\こっち\\media\\Save.cyn");
		// マップデータ読み込み失敗
		if (ifs.fail())
		{
			std::cerr << "LoadError" << std::endl;
			return false;
		}

		// 仮置き
		std::string str;
		int count = 0;

		while (getline(ifs, str))
		{
			// 仮置き
			std::string token;
			std::istringstream stream(str);

			// メモリ確保
			mapdata.resize(count + 1);

			while (getline(stream, token, ','))
			{
				mapdata[count].push_back(token);
			}
			// カウントアップ
			count++;
		}

		BASICPARAM::e_nowScene = static_cast<ESceneNumber>(std::stoi(mapdata[0][0]) - 1);
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;

		/*for (int i = 0, n = mapdata.size(); i != n; ++i)
		{
			num++;
			v_className.push_back(const_cast<char*>(mapdata[i][0].c_str()));
			v_areaX.push_back(std::stof(mapdata[i][1].c_str()));
			v_areaY.push_back(std::stof(mapdata[i][2].c_str()));
			v_areaZ.push_back(std::stof(mapdata[i][3].c_str()));
			v_direction.push_back(std::stof(mapdata[i][4].c_str()));
		}*/

		return true;
	} /// void Load()
} /// namespace FileSaveLoad
