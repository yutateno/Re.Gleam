#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove3Slime : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���-------------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;

	// ���̑O��̃L���������������ϐ�
	float nextDireZAngle;

	// ���̍��E�̃L���������������ϐ�
	float nextDireXAngle;


	/// ���[�V�����Ɋւ���----------

	// ���[�V������ID
	enum MOTION { idle, attack };


	/// �K�i�Ɋւ���--------------

	// �K�i�̃��f��
	std::vector<int> v_stairsHandle;


	/// �K�i�Ə��Ɋւ���----------

	// �K�i�Ə��̃��f��
	std::vector<int> v_stairsRoadHandle;


	/// �����Ɋւ���------------

	// �����̃v���Z�X
	void MoveProcess();

	// �����̃J�E���g
	int moveCount;


	/// �e�N�X�`���Ɋւ���---------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;


public:
	// �R���X�g���N�^
	EnemyMove3Slime(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
		, const int tex0, const VECTOR area);

	// �f�X�g���N�^
	~EnemyMove3Slime();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();

	// �e�N�X�`���̐؂�ւ�
	void TextureReload();
};

