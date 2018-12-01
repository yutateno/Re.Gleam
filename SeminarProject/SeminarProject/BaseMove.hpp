#pragma once
#include "Basic.hpp"


class BaseMove
{
private:
	/// �e�Ɋւ���-----------------------------------------------

	// �L�����N�^�[�̉e�̃n���h��
	int shadowMapCharaHandle;

	// �L�����N�^�[�ȊO�̓����A�N�^�[�̃n���h��
	int shadowMapAnotherCharaHandle;

	// �S�������Ȃ���̃n���h��
	int shadowMapNoMoveHandle;

	// �L�����N�^�[�̉e�̃}�C�i�X�͈�
	VECTOR shadowCharaLowArea;

	// �L�����N�^�[�̉e�̃v���X�͈�
	VECTOR shadowCharaHighArea;

	// �L�����N�^�[�ȊO������̉e�̃}�C�i�X�͈�
	VECTOR shadowAnotherCharaLowArea;

	// �L�����N�^�[�ȊO������̉e�̃v���X�͈�
	VECTOR shadowAnotherCharaHighArea;

	// �S�������Ȃ���̉e�̃}�C�i�X�͈�
	VECTOR shadowNoMoveLowArea;

	// �S�������Ȃ���̉e�̃v���X�͈�
	VECTOR shadowNoMoveHighArea;

	// ���C�g�̃f�B���N�V��������
	VECTOR lightDire;
	/// ---------------------------------------------------------


	/// �X�J�C�{�b�N�X�Ɋւ���

	// �X�J�C�{�b�N�X�̃n���h��
	int skyBoxUp, skyBoxUnder;


protected:
	// �V�[���̏I���t���b�O
	static bool endFlag;

	// ���݂̃V�[��
	static ESceneNumber scene;


	/// �e�Ɋւ���-----------------------------------------------

	/// �ݒ肷��

	// �ݒ�V���h�E�}�b�v�O�ԁF��l��
	void ShadowCharaSetUpBefore();
	void ShadowCharaSetUpAfter();

	// �ݒ�V���h�E�}�b�v�P�ԁF��l���ȊO
	void ShadowAnotherCharaSetUpBefore();
	void ShadowAnotherCharaSetUpAfter();

	// �ݒ�V���h�E�}�b�v�Q�ԁF�����Ȃ�����
	void ShadowNoMoveSetUpBefore();
	void ShadowNoMoveSetUpAfter();

	/// �`��֎g�p����

	// �`��V���h�E�}�b�v�O�ԁF��l��
	void ShadowCharaDrawBefore();
	void ShadowCharaDrawAfter();

	// �`��V���h�E�}�b�v�P�ԁF��l���ȊO
	void ShadowAnotherCharaDrawBefore();
	void ShadowAnotherCharaDrawAfter();

	// �`��V���h�E�}�b�v�Q�ԁF�����Ȃ�����
	void ShadowNoMoveDrawBefore();
	void ShadowNoMoveDrawAfter();

	// ���W���X�V��������
	void ShadowArea(const VECTOR charaArea);
	/// ---------------------------------------------------------


	// ��̃��f���̋���
	int GetDistance(const VECTOR alpha, const VECTOR beta);


	/// �X�J�C�{�b�N�X�Ɋւ���-----------------------------

	// �X�J�C�{�b�N�X�̕`��
	void SkyBoxDraw();

	// �X�J�C�{�b�N�X�̃v���Z�X
	void SkyBoxProcess(const VECTOR characterArea);

	// �X�J�C�{�b�N�X�̏�����
	void SetInitSkyBox(const int skyBoxUp);


public:
	// �R���X�g���N�^
	BaseMove();

	// �f�X�g���N�^
	virtual ~BaseMove();

	// �`��
	virtual void Draw() = 0;

	// �v���Z�X
	virtual void Process() = 0;

	// �J�����̃v���Z�X
	virtual void CameraProcess() = 0;


	/// �Q�b�^�[�Z�b�^�[------------------------------

	// �I�����ǂ�����n��
	static const bool GetEndFlag();

	// ���̃V�[����n��
	static const ESceneNumber GetScene();

	// ���̃V�[���𓾂�
	void SetScene(const ESceneNumber scene);
};

