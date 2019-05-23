#include "LoadFile.hpp"

using namespace std;



/// ------------------------------------------------------------------------------------
unsigned int LoadFile::file_size(ifstream &fin)
{
	// ���݈ʒu�ۑ�
	unsigned int pos = static_cast<unsigned int>(fin.tellg());


	// �Ō�ɃV�[�N���Ĉʒu�擾����T�C�Y�𓾂�
	unsigned int size = static_cast<unsigned int>(fin.seekg(0, ios::end).tellg());


	fin.seekg(pos);		// ���̈ʒu�ɖ߂�


	return size;		// �T�C�Y��Ԃ�
}



/// ------------------------------------------------------------------------------------
void LoadFile::MyLoad(const string path, int& file, const ELOADFILE type)
{
	vector<BYTE> data;  // �t�@�C���f�[�^
	UINT size;          // �t�@�C���T�C�Y
	string outstr;		// �o�͂���t�@�C����


	// ���f���f�[�^�ł͂Ȃ��Ƃ�
	if (type != ELOADFILE::mv1model)
	{
		// �t�@�C���̓ǂݍ���
		ifstream fin(path.c_str(), ios::binary);	// �t�@�C���I�[�v��
		size = file_size(fin);						// �t�@�C���T�C�Y�擾
		data.resize(size);							// �������m��
		fin.read((char*)& data[0], size);			// �ǂݍ���
		fin.close();


		// ���
		for (UINT i = 0; i < size; i += 5)
		{
			data[i] = (data[i] ^ rad);
		}
	}


	// ���[�h����
	switch (type)
	{
	// UI�֌W�̉摜�̂Ƃ�
	case ELOADFILE::graph:
		file = CreateGraphFromMem((char*)&data[0], size);
		break;


	// 2D�nSE�̂Ƃ�
	case ELOADFILE::soundmem:
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		break;


	// ���f���f�[�^�̂Ƃ�
	case ELOADFILE::mv1model:
		file = MV1LoadModel(path.c_str());
		break;


	// BGM�̂Ƃ�
	case ELOADFILE::soundStream:
		SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);
		break;


	// 3D�T�E���h�̂Ƃ�
	case ELOADFILE::sound3DSource:
		SetCreate3DSoundFlag(TRUE);
		file = LoadSoundMemByMemImage((char*)&data[0], size);
		SetCreate3DSoundFlag(FALSE);
		break;


	default:
		break;
	} /// switch (type)
} /// void LoadFile::MyLoad(const string path, int& file, const ELOADFILE type)
