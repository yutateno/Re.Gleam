#include "LoadFile.hpp"

using namespace std;



/// ------------------------------------------------------------------------------------
unsigned int LoadFile::file_size(ifstream &fin)
{
	// 現在位置保存
	unsigned int pos = static_cast<unsigned int>(fin.tellg());


	// 最後にシークして位置取得からサイズを得る
	unsigned int size = static_cast<unsigned int>(fin.seekg(0, ios::end).tellg());


	fin.seekg(pos);		// 元の位置に戻す


	return size;		// サイズを返す
}



/// ------------------------------------------------------------------------------------
void LoadFile::MyLoad(const string path, int& file, const ELOADFILE type)
{
	vector<BYTE> data;  // ファイルデータ
	UINT size;          // ファイルサイズ
	string outstr;		// 出力するファイル名


	// モデルデータではないとき
	if (type != ELOADFILE::mv1model)
	{
		// ファイルの読み込み
		ifstream fin(path.c_str(), ios::binary);	// ファイルオープン
		size = file_size(fin);						// ファイルサイズ取得
		data.resize(size);							// メモリ確保
		fin.read((char*)& data[0], size);			// 読み込み
		fin.close();


		// 解読
		for (UINT i = 0; i < size; i += 5)
		{
			data[i] = (data[i] ^ rad);
		}
	}


	// ロードする
	switch (type)
	{
	// UI関係の画像のとき
	case ELOADFILE::graph:
		file = CreateGraphFromMem((char*)&data[0], size);
		break;


	// 2D系SEのとき
	case ELOADFILE::soundmem:
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		break;


	// モデルデータのとき
	case ELOADFILE::mv1model:
		file = MV1LoadModel(path.c_str());
		break;


	// BGMのとき
	case ELOADFILE::soundStream:
		SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);
		break;


	// 3Dサウンドのとき
	case ELOADFILE::sound3DSource:
		SetCreate3DSoundFlag(TRUE);
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		SetCreate3DSoundFlag(FALSE);
		break;


	default:
		break;
	} /// switch (type)
} /// void LoadFile::MyLoad(const string path, int& file, const ELOADFILE type)
