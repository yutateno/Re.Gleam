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
	const int max1 = 12;

	// ���[�u1�̃��[�h�t�@�C��
	std::string move1str[12];

	// ���[�u1�̃��[�h�̎��
	ELOADFILE load1[12];


	/// ���[�u�Q�Ɋւ���--------------

	// ���[�u2�̃��[�h��
	const int max2 = 19;

	// ���[�u2�̃��[�h�t�@�C��
	std::string move2str[19];

	// ���[�u2�̃��[�h�̎��
	ELOADFILE load2[19];


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
	enum class EOptionSelectButton { Sound, ColorSelect, Back, BGM, SE, ColorNormal, ColorP, ColorD, BGMSelect, SESelect };

	// �I�v�V������ʂ̑I���{�^��
	EOptionSelectButton optionSelectButtonNum;

	// �X�e�B�b�N�̉����|�����ǂ����𒲂ׂ�(DLLXinput�ł��ׂ��Ȃ񂾂낤���Ƃ肠����
	int optionControllStick[2];

	// ���I���̍ŏ�
	int optionSelectMin;

	// ���I���̍ő�
	int optionSelectMax;

	// SE�Đ��E�F�C�g�^�C�}�[
	int seDoWaitTimer;

	// ���[�h
	std::thread thsTexture;



public:
	// �R���X�g���N�^
	Manager();

	// �f�X�g���N�^
	~Manager();


	// ���C���v���Z�X
	void Update();
};

