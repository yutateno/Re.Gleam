#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	BaseMove* p_baseMove;			// �V�[���̊��N���X
	LoadThread* p_loadThread;		// ���[�h�̃N���X


	void SceneChange();				// �V�[����؂�ւ���


	// ���[�u�P�Ɋւ���
	const int max1 = 5;
	std::string move1str[5];
	ELOADFILE load1[5];


	// ���[�u�Q�Ɋւ���
	const int max2 = 9;
	std::string move2str[9];
	ELOADFILE load2[9];


	int antiAliasScreen;

public:
	Manager();			// �R���X�g���N�^
	~Manager();			// �f�X�g���N�^

	void Update();		// ���C���v���Z�X
};