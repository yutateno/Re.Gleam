#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"
#include "MainMove3.hpp"
#include "MainMove4.hpp"
#include "MainMove5.hpp"


class Manager
{
private:
	// �V�[���̊��N���X
	BaseMove* p_baseMove;

	// ���[�h�̃N���X
	LoadThread* p_loadThread;


	// �V�[����؂�ւ���
	void SceneChange();

	// ���O�̃V�[�������[�h���Q�[�����ǂ���
	bool preLoadScene;


	/// ���[�u�P�Ɋւ���----------------

	// ���[�u1�̃��[�h��
	const int max1 = 14;

	// ���[�u1�̃��[�h�t�@�C��
	std::string move1str[14];

	// ���[�u1�̃��[�h�̎��
	ELOADFILE load1[14];

	// ���[�u1�̃��[�h�̏�����
	void InitMove1Load();


	/// ���[�u�Q�Ɋւ���--------------

	// ���[�u2�̃��[�h��
	const int max2 = 48;

	// ���[�u2�̃��[�h�t�@�C��
	std::string move2str[48];

	// ���[�u2�̃��[�h�̎��
	ELOADFILE load2[48];

	// ���[�u2�̃��[�h�̏�����
	void InitMove2Load();


	/// ���[�u3�Ɋւ���--------------

	// ���[�u3�̃��[�h��
	const int max3 = 58;

	// ���[�u3�̃��[�h�t�@�C��
	std::string move3str[58];

	// ���[�u3�̃��[�h�̎��
	ELOADFILE load3[58];

	// ���[�u3�̃��[�h�̏�����
	void InitMove3Load();


	/// ���[�u4�Ɋւ���--------------

	// ���[�u4�̃��[�h��
	const int max4 = 38;

	// ���[�u4�̃��[�h�t�@�C��
	std::string move4str[38];

	// ���[�u4�̃��[�h�̎��
	ELOADFILE load4[38];

	// ���[�u4�̃��[�h�̏�����
	void InitMove4Load();

	// ���[�u4�Ń��[�h����e�N�X�`������������ύX����
	void Move4TextureReload();


	/// ���[�u5�Ɋւ���--------------

	// ���[�u5�̃��[�h��
	const int max5 = 34;

	// ���[�u5�̃��[�h�t�@�C��
	std::string move5str[34];

	// ���[�u5�̃��[�h�̎��
	ELOADFILE load5[34];

	// ���[�u5�̃��[�h�̏�����
	void InitMove5Load();


	// �A���`�G�C���A�X�̉摜
	int antiAliasScreen;

	// �V�[���؂�ւ��̃t�F�[�h�J�E���g
	int feedCount;

	// �t�F�[�h�p�摜
	int feedDraw;


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
	enum class EOptionSelectButton { Sound, ColorSelect, Camera, BGM, SE, ColorNormal, ColorP, ColorD
		, BGMSelect, SESelect, CameraPerspective, CameraOrtho, CameraHReturn, CameraVReturn };

	// �I�v�V������ʂ̑I���{�^��
	EOptionSelectButton optionSelectButtonNum;

	// ���X�e�B�b�N��Y�������|�����ǂ����𒲂ׂ�(DLLXinput�ł��ׂ��Ȃ񂾂낤���Ƃ肠����
	int optionControllLeftStickY[2];

	// ���I���̍ŏ�
	int optionSelectMin;

	// ���I���̍ő�
	int optionSelectMax;

	// SE�Đ��E�F�C�g�^�C�}�[
	int seDoWaitTimer;

	// ���[�h
	std::thread thsTexture;

	// �I�v�V�����p�摜ID
	enum class EOptionDraw { BGM, Camera, ColorD, ColorP, SE, Sound, Perspective, Color, Ortho
		, ColorNormal, HorizonReturn, VerticalReturn, nextPage, prevPage, optionEnd };

	// �I�v�V�����p�摜
	int optionDrawMedia[15];

	// �I�v�V�����p�摜��
	const int optionDrawNum = 15;

	// �I�v�V�����̃y�[�W��
	int optionPageNowNumber;


public:
	// �R���X�g���N�^
	Manager();

	// �f�X�g���N�^
	~Manager();


	// ���C���v���Z�X
	void Update();
};
