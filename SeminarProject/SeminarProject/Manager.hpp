#pragma once
#include "BaseMove.hpp"
#include "LoadThread.hpp"
#include "FileSaveLoad.hpp"

#include "MainMove1.hpp"
#include "MainMove2.hpp"
#include "MainMove3.hpp"
#include "MainMove4.hpp"
#include "MainMove5.hpp"
#include "MainMove6.hpp"


class Manager
{
private:
	/// �e�V�[���Ɋւ���--------------------------
	// �V�[���̊��N���X
	BaseMove* p_baseMove;

	// ���[�h�̃N���X
	LoadThread* p_loadThread;

	// �V�[����؂�ւ���
	void SceneChange();

	// ���O�̃V�[�������[�h���Q�[�����ǂ���
	bool preLoadScene;

	// ���[�h�̃t�@�C��
	std::vector<std::string> moveStr;

	// ���[�h�̎��
	std::vector<ELOADFILE> loadType;

	// �A���`�G�C���A�X�̉摜
	int antiAliasScreen;

	// �V�[���؂�ւ��̃t�F�[�h�J�E���g
	int feedCount;

	// �t�F�[�h�̐F
	int feedDraw;


	/// �Q�[���Ɋւ���------------

	// �Q�[���N�����ォ�ǂ���
	bool gameFirstStarting;

	// �Q�[�����I������
	bool gameEnd;


	/// �Q�[���^�C�g���Ɋւ���-----------------------------------------

	// �Z�[�u�f�[�^���������Ƃ��̃^�C�g��UI�摜
	enum class ETitleDraw {
		firstGame, load, gameEnd, bonus, bonusMove2, bonusMove3
		, bonusMove4, bonusMove5, bonusMove6
	};

	// �Z�[�u�f�[�^���������Ƃ��̃^�C�g��UI�摜�ێ�
	int titleUIDraw[9];

	// �Z�[�u�f�[�^�������Ƃ��̃^�C�g��UI�摜�̌�
	const int titleUINum = 9;

	// �Z�[�u�f�[�^���������Ƃ��̃^�C�g���v���Z�X
	void TitleProcess();

	// �Z�[�u�f�[�^���������Ƃ��̃^�C�g���`��
	void TitleDraw();

	// ���܂��R�}���h��ł������ǂ���
	bool playBonus;


	/// ���[�u�P�Ɋւ���----------------

	// ���[�u1�̃��[�h��
	const int max1 = 15;

	// ���[�u1�̃��[�h�̏�����
	void InitMove1Load();


	/// ���[�u�Q�Ɋւ���--------------

	// ���[�u2�̃��[�h��
	const int max2 = 49;

	// ���[�u2�̃��[�h�̏�����
	void InitMove2Load();


	/// ���[�u3�Ɋւ���--------------

	// ���[�u3�̃��[�h��
	const int max3 = 65;

	// ���[�u3�̃��[�h�̏�����
	void InitMove3Load();


	/// ���[�u4�Ɋւ���--------------

	// ���[�u4�̃��[�h��
	const int max4 = 54;

	// ���[�u4�̃��[�h�̏�����
	void InitMove4Load();

	// ���[�u4�Ń��[�h����e�N�X�`������������ύX����
	void Move4TextureReload();


	/// ���[�u5�Ɋւ���--------------

	// ���[�u5�̃��[�h��
	const int max5 = 40;

	// ���[�u5�̃��[�h�̏�����
	void InitMove5Load();

	// ���[�u5�Ń��[�h����e�N�X�`������������ύX����
	void Move5TextureReload();


	/// ���[�u6�Ɋւ���

	// ���[�u6�̃��[�h��
	const int max6 = 39;

	// ���[�u6�̃��[�h�̏�����
	void InitMove6Load();

	// ���[�u6�̃��[�h����e�N�X�`������������ύX����
	void Move6TextureReload();


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
	enum class EOptionSelectButton { Sound, ColorSelect, Camera, DataSave, GameEnd, BGM, SE, ColorNormal, ColorP, ColorD
		, BGMSelect, SESelect, CameraPerspective, CameraOrtho, CameraHReturn, CameraVReturn, SaveYes, SaveNo, GameEndYes, GameEndNo };

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
		, ColorNormal, HorizonReturn, VerticalReturn, nextPage, prevPage, optionEnd, gameEnd, dataSave, yes, no };

	// �I�v�V�����p�摜
	int optionDrawMedia[19];

	// �I�v�V�����p�摜��
	const int optionDrawNum = 19;

	// �I�v�V�����̃y�[�W��
	int optionPageNowNumber;

	// �I�v�V�����ł̃Z�[�u��SE
	int se_save;


public:
	// �R���X�g���N�^
	Manager();

	// �f�X�g���N�^
	~Manager();


	// ���C���v���Z�X
	void Update();

	// �Q�[�����I�����邩�ǂ���
	const bool GetEnd() const { return gameEnd; }
};
