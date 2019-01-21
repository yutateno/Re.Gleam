#pragma once
#include "BasicCreature.hpp"


class Character : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���----------------------------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;


	/// ���[�V�����Ɋւ���--------------------------------
	enum MOTION { run, idle, walk };


	/// �����Ɋւ���--------------------------------------

	// �����̌���
	enum DIRECTION { left, down, right, up };

	// �����Ă��邩�ǂ���
	bool m_direction[4];

	// �����̃v���Z�X
	void MoveProcess();

	// ����̃v���Z�X
	void OpeProcess();


	/// �e�N�X�`���Ɋւ���--------------------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;
	int textureHandle3;


public:
	// �R���X�g���N�^
	Character(const int modelHandle, const int collStageHandle
		, const int tex0, const int tex1, const int tex2, const int tex3);

	// �f�X�g���N�^
	~Character();


	// �`��
	void Draw();

	// �v���Z�X
	void Process(const float getAngle);


	// �ʒu��������
	void PositionReset() { area = VGet(0.0f, 0.0f, 0.0f); }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override;
};