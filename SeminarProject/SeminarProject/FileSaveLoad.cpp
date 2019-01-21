#include "FileSaveLoad.hpp"


namespace FileSaveLoad
{
	/// --------------------------------------------------------------------------------------------------
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
		// ファイル読み込み成功
		else
		{
			//// 読み込み成功
			//for (int i = 0, n = static_cast<int>(v_className.size()); i < n; i++)
			//{
			//	saveFile << v_className[i] << "," << v_areaX[i] << "," << v_areaY[i] << "," << v_areaZ[i] << "," << v_direction[i];
			//	saveFile << std::endl;
			//}
			saveFile << static_cast<int>(BASICPARAM::e_nowScene) << std::endl;
			if (BASICPARAM::e_nowScene >= ESceneNumber::THIRDMOVE)
			{
				saveFile << BASICPARAM::stairsNum << std::endl;
				for (int i = 0; i != BASICPARAM::stairsNum; ++i)
				{
					saveFile << BASICPARAM::v_stairsArea[i].x << "," << BASICPARAM::v_stairsArea[i].y
						<< "," << BASICPARAM::v_stairsArea[i].z << "," << BASICPARAM::v_stairsAngle[i] << std::endl;
				}
				saveFile << BASICPARAM::streetLightNum << std::endl;
				for (int i = 0; i != BASICPARAM::streetLightNum; ++i)
				{
					saveFile << BASICPARAM::v_streetLightArea[i].x << "," << BASICPARAM::v_streetLightArea[i].y
						<< "," << BASICPARAM::v_streetLightArea[i].z << "," << BASICPARAM::v_streetLightAngle[i] << std::endl;
				}
				saveFile << BASICPARAM::stairsRoadNum << std::endl;
				for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
				{
					saveFile << BASICPARAM::v_stairsRoadArea[i].x << "," << BASICPARAM::v_stairsRoadArea[i].y
						<< "," << BASICPARAM::v_stairsRoadArea[i].z << "," << BASICPARAM::v_stairsRoadAngle[i] << std::endl;
				}
			}
			if (BASICPARAM::e_nowScene >= ESceneNumber::FOURTHMOVE)
			{
				saveFile << BASICPARAM::charaTextureWhiteBlack << "," << BASICPARAM::anothreTextureWhiteBlack
					<< "," << BASICPARAM::enemyTextureWhiteBlack << "," << BASICPARAM::lightStreetTextureWhiteBlack
					<< "," << BASICPARAM::stairsRoadTextureWhiteBlack << "," << BASICPARAM::stairsTextureWhiteBlack << std::endl;
			}
			if (BASICPARAM::e_nowScene >= ESceneNumber::FIFTHMOVE)
			{
				saveFile << BASICPARAM::ordinaryPeopleNum << std::endl;
			}
			if (BASICPARAM::e_nowScene >= ESceneNumber::SIXMOVE)
			{
				saveFile << BASICPARAM::lastCharaView << "," << BASICPARAM::lastOrdinaryView
					<< "," << BASICPARAM::lastPaneruView << "," << BASICPARAM::lastStairsRoadView
					<< "," << BASICPARAM::lastStairsView << "," << BASICPARAM::lastStreetLightView << std::endl;
			}
		} /// else(!if (saveFile.fail()))

		// ファイルを閉じる
		saveFile.close();

		return true;
	}



	/// --------------------------------------------------------------------------------------------------
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

		if (BASICPARAM::e_nowScene >= ESceneNumber::THIRDLOAD)
		{
			BASICPARAM::stairsNum = std::stoi(mapdata[1][0]);
			BASICPARAM::v_stairsArea.resize(BASICPARAM::stairsNum + 1);
			BASICPARAM::v_stairsAngle.resize(BASICPARAM::stairsNum + 1);
			for (int i = 0; i != BASICPARAM::stairsNum; ++i)
			{
				BASICPARAM::v_stairsArea[i].x = std::stof(mapdata[i + 2][0]);
				BASICPARAM::v_stairsArea[i].y = std::stof(mapdata[i + 2][1]);
				BASICPARAM::v_stairsArea[i].z = std::stof(mapdata[i + 2][2]);
				BASICPARAM::v_stairsAngle[i] = std::stof(mapdata[i + 2][3]);
			}


			BASICPARAM::streetLightNum = std::stoi(mapdata[2 + BASICPARAM::stairsNum][0]);
			BASICPARAM::v_streetLightArea.resize(BASICPARAM::streetLightNum + 1);
			BASICPARAM::v_streetLightAngle.resize(BASICPARAM::streetLightNum + 1);
			for (int i = 0; i != BASICPARAM::streetLightNum; ++i)
			{
				BASICPARAM::v_streetLightArea[i].x = std::stof(mapdata[i + 3 + BASICPARAM::stairsNum][0]);
				BASICPARAM::v_streetLightArea[i].y = std::stof(mapdata[i + 3 + BASICPARAM::stairsNum][1]);
				BASICPARAM::v_streetLightArea[i].z = std::stof(mapdata[i + 3 + BASICPARAM::stairsNum][2]);
				BASICPARAM::v_streetLightAngle[i] = std::stof(mapdata[i + 3 + BASICPARAM::stairsNum][3]);
			}


			BASICPARAM::stairsRoadNum = std::stoi(mapdata[3 + BASICPARAM::stairsNum + BASICPARAM::streetLightNum][0]);
			BASICPARAM::v_stairsRoadArea.resize(BASICPARAM::stairsRoadNum + 1);
			BASICPARAM::v_stairsRoadAngle.resize(BASICPARAM::stairsRoadNum + 1);
			for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
			{
				BASICPARAM::v_stairsRoadArea[i].x = std::stof(mapdata[i + 4 + BASICPARAM::stairsNum + BASICPARAM::streetLightNum][0]);
				BASICPARAM::v_stairsRoadArea[i].y = std::stof(mapdata[i + 4 + BASICPARAM::stairsNum + BASICPARAM::streetLightNum][1]);
				BASICPARAM::v_stairsRoadArea[i].z = std::stof(mapdata[i + 4 + BASICPARAM::stairsNum + BASICPARAM::streetLightNum][2]);
				BASICPARAM::v_stairsRoadAngle[i] = std::stof(mapdata[i + 4 + BASICPARAM::stairsNum + BASICPARAM::streetLightNum][3]);
			}
		}
		if (BASICPARAM::e_nowScene >= ESceneNumber::FOURTHLOAD)
		{
			BASICPARAM::charaTextureWhiteBlack		 = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][0]);
			BASICPARAM::anothreTextureWhiteBlack	 = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][1]);
			BASICPARAM::enemyTextureWhiteBlack		 = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][2]);
			BASICPARAM::lightStreetTextureWhiteBlack = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][3]);
			BASICPARAM::stairsRoadTextureWhiteBlack	 = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][4]);
			BASICPARAM::stairsTextureWhiteBlack		 = std::stoi(mapdata[4 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][5]);
		}
		if (BASICPARAM::e_nowScene >= ESceneNumber::FIFTHLOAD)
		{
			BASICPARAM::ordinaryPeopleNum = std::stoi(mapdata[5 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][0]);
		}
		if (BASICPARAM::e_nowScene >= ESceneNumber::SIXLOAD)
		{
			BASICPARAM::lastCharaView		 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][0]); 
			BASICPARAM::lastOrdinaryView	 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][1]);
			BASICPARAM::lastPaneruView		 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][2]); 
			BASICPARAM::lastStairsRoadView	 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][3]);
			BASICPARAM::lastStairsView		 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][4]); 
			BASICPARAM::lastStreetLightView	 = std::stoi(mapdata[6 + +BASICPARAM::stairsNum + BASICPARAM::streetLightNum + BASICPARAM::stairsRoadNum][5]);
		}

		return true;
	} /// void Load()
} /// namespace FileSaveLoad
