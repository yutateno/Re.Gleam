#pragma once
#include "BasicCreature.hpp"
#include "MagicIcePillar.hpp"
#include "ChaseBlock.hpp"
#include <random>


/*
���[�u6�ŏo�Ă��郉�X�{�X�̐퓬�p�N���X
*/
class EnemyBossAfter : public BasicCreature
{
private:
	/// ���[�V�����Ɋւ���----------------------------------------------------

	// ���[�V������ID
	enum MOTION{
		idleDevile, idleNormal, move, attack, attackMagic, attackMagic2
	};

	// ���[�V�����̃v���Z�X
	void MotionProcess();

	// �U�������ǂ���
	bool attackMotionNow;


	/// �U���Ɋւ���----------------------------------------------------------

	// �����̃v���Z�X
	void MoveProcess();

	// �����̃J�E���g
	int moveCount;

	// �U���̃t���[��
	float attackFrame;

	// �U���ɂ�邠����������邩�ǂ���
	bool attackDamageNow;

	// �X���̃|�C���^
	MagicIcePillar* p_magicIcePillar[2];

	// �U���̃p�^�[��ID
	enum EAttackPattern { hand, icePillar, magicBlock };

	// �ǂ̍U�����s����
	EAttackPattern e_attackPattern;

	// �ǔ����̃|�C���^
	ChaseBlock* p_chaseBlock[2];

	// �v���C���[�̍��W
	VECTOR playerArea;

	
	/// �e�N�X�`���Ɋւ���---------------------------------------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;
	int textureHandle1;
	int textureHandle2;


	/// �����l---------------------------------------------------------------

	std::random_device rnd;


public:
	// �R���X�g���N�^
	EnemyBossAfter(const int modelHandle, const int modelTex0, const int modeltex1, const int modelTex2);

	// �f�X�g���N�^
	~EnemyBossAfter();


	// �`��
	void Draw();

	// ���f���`��
	void DrawWhile();

	// �v���Z�X
	void Process();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �U�����_���[�W�ɔ��f���邩�ǂ���
	const bool GetAttackDamage() const { return attackDamageNow; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}

	// �v���C���[�̍��W�𓾂�
	void SetPlayerArea(VECTOR player) { playerArea = player; }
};

