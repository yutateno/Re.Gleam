#pragma once
#include "LoadFile.hpp"


class LoadScreen
{
private:
	// ���[�h���
	int draw;

	// ���[�h�I��
	int endDraw;


public:
	// �R���X�g���N�^
	LoadScreen();

	// �f�X�g���N�^
	~LoadScreen();


	// �񓯊��ōs�����\�b�h
	void Process(const int num, const int max);
};

