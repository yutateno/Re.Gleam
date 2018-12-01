#pragma once
#include "Basic.hpp"

#ifndef _ME_LoadFile_HPP
#define _ME_LoadFile_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>


// �ǂݍ��ރt�@�C���̎��
enum class ELOADFILE { graph, soundmem, mv1model, soundStream, sound3DSource };


class LoadFile
{
private:
	// �����L�[
	static const int rad = 0x2546;

	// �t�@�C���ǂݍ���
	static unsigned int file_size(std::ifstream &fin);

public:
	// �R���X�g���N�^
	LoadFile() {};

	// �f�X�g���N�^
	~LoadFile() {};


	// ���f�B�A�̃��[�h���s��
	static void MyLoad(const std::string path, int& file, const ELOADFILE type);
};

#endif // !_ME_LoadFile_HPP