#pragma once
#include "BasicCreature.hpp"
#include <random>


/*
���[�u�S�ȍ~�ŏo�Ă����ʐl�̃N���X
*/
class OrdinaryPerson : public BasicCreature
{
private:
	/// ���f���Ɋւ���---------------------------------

	// �����������ꂽ��
	bool alive;

	// ���ߒl��ۑ�����
	int aliveBlendCount;


	/// ���ꂼ��̈ʒu�Ɋւ���-------------------------

	// �O��̃L���������������ϐ�
	float direZAngle;		

	// ���E�̃L���������������ϐ�
	float direXAngle;		

	// ���̑O��̃L���������������ϐ�
	float nextDireZAngle;

	// ���̍��E�̃L���������������ϐ�
	float nextDireXAngle;


	/// ���[�V�����Ɋւ���------------------------------

	// ���[�V������ID
	enum MOTION { walk };


	/// �K�i�Ɋւ���-----------------------------------

	// �K�i�̃��f��
	std::vector<int> v_stairsHandle;


	/// �K�i�Ə��Ɋւ���-------------------------------

	// �K�i�Ə��̃��f��
	std::vector<int> v_stairsRoadHandle;


	/// �����Ɋւ���-----------------------------------

	// �����̃v���Z�X
	void MoveProcess();

	// �����̃J�E���g
	int moveCount;


	/// �����Ɋւ���----------------------------------

	// �d��
	float gravity;

	// �W�����v��
	float flyJumpPower;

	// �����Ă���Ƃ���Y���ɗ^�����
	float fallJumpPower;

	// �W�����v�v���Z�X
	void FallProcess();

	// �W�����v���珰�ɂ������ǂ���
	bool preJumpNow;

	// �����Ă���t���[����
	int flyCount;


	/// �e�N�X�`���Ɋւ���----------------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;

	
	/// �����l----------------------------------------

	std::random_device rnd;


public:
	// �R���X�g���N�^
	OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
		, const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY);

	// �f�X�g���N�^
	~OrdinaryPerson();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}

	// �����������ꂽ����W��ݒ肵�Đ���
	void SetAlive(VECTOR area, bool alive = true);

	// �������Ă��邩�ǂ�����n��
	const bool GetAlive() const { return alive; }
};

