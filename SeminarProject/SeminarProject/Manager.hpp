#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"


class Manager
{
private:
	// �V�[���̊��N���X
	BaseMove* p_baseMove;

	// ���[�h�̃N���X
	LoadThread* p_loadThread;


	// �V�[����؂�ւ���
	void SceneChange();


	/// ���[�u�P�Ɋւ���----------------

	// ���[�u1�̃��[�h��
	const int max1 = 7;

	// ���[�u1�̃��[�h�t�@�C��
	std::string move1str[7];

	// ���[�u1�̃��[�h�̎��
	ELOADFILE load1[7];


	/// ���[�u�Q�Ɋւ���--------------

	// ���[�u2�̃��[�h��
	const int max2 = 9;

	// ���[�u2�̃��[�h�t�@�C��
	std::string move2str[9];

	// ���[�u2�̃��[�h�̎��
	ELOADFILE load2[9];


	// �A���`�G�C���A�X�̉摜
	int antiAliasScreen;

	// �V�[���؂�ւ��̃t�F�[�h�J�E���g
	int feedCount;


	/// �I�v�V������ʂɊւ���---------------

	// �K�E�X�t�B���^�̉摜
	int gaussianScreen;

	// �I�v�V������ʂɂ��邩�ǂ���
	bool optionMenuNow;

	// �I�v�V������ʂ̃v���Z�X
	void OptionProcess();

	// �I�v�V������ʂ̕`��
	void OptionDraw();

	// �I�v�V������ʂ�ID
	enum class EOptionSelectButton { BGM, SE, ColorNormal, ColorP, ColorD, Back };

	// �I�v�V������ʂ̑I���{�^��
	EOptionSelectButton optionSelectButtonNum;

	// �X�e�B�b�N�̉����|�����ǂ����𒲂ׂ�(DLLXinput�ł��ׂ��Ȃ񂾂낤���Ƃ肠����
	int optionControllStick[2];


public:
	// �R���X�g���N�^
	Manager();

	// �f�X�g���N�^
	~Manager();


	// ���C���v���Z�X
	void Update();
};

