#include "FileSaveLoad.hpp"


namespace FileSaveLoad
{
	// CSV�ɏo�͂���
	bool Save()
	{
		std::ofstream saveFile;

		saveFile.open("media\\������\\media\\Save.cyn");

		// �t�@�C���ǂݍ��ݎ��s
		if (saveFile.fail())
		{
			std::cerr << "SaveError" << std::endl;
			return false;
		}
		else
		{
			//// �ǂݍ��ݐ���
			//for (int i = 0, n = static_cast<int>(v_className.size()); i < n; i++)
			//{
			//	saveFile << v_className[i] << "," << v_areaX[i] << "," << v_areaY[i] << "," << v_areaZ[i] << "," << v_direction[i];
			//	saveFile << std::endl;
			//}
			saveFile << static_cast<int>(BASICPARAM::e_nowScene) << std::endl;
		}

		// �t�@�C�������
		saveFile.close();

		return true;
	}


	// CSV����ǂݍ���
	bool Load()
	{
		std::ifstream ifs;
		std::vector<std::vector<std::string>> mapdata;
		ifs.open("media\\������\\media\\Save.cyn");
		// �}�b�v�f�[�^�ǂݍ��ݎ��s
		if (ifs.fail())
		{
			std::cerr << "LoadError" << std::endl;
			return false;
		}

		// ���u��
		std::string str;
		int count = 0;

		while (getline(ifs, str))
		{
			// ���u��
			std::string token;
			std::istringstream stream(str);

			// �������m��
			mapdata.resize(count + 1);

			while (getline(stream, token, ','))
			{
				mapdata[count].push_back(token);
			}
			// �J�E���g�A�b�v
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
