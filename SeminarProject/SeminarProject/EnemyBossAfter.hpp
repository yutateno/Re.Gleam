#pragma once
#include "BasicCreature.hpp"
#include "MagicIcePillar.hpp"
#include "ChaseBlock.hpp"
#include <random>


// �{�X�̍U���̃p�^�[��ID
enum class EAttackPattern { hand, icePillar, magicBlock };


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

	// ���������߂�J�E���g���l
	const int moveDoCount = 600;

	// �����̃J�E���g
	int moveCount;

	// �U���̃t���[��
	float attackFrame;

	// �U���ɂ�邠����������邩�ǂ���
	bool attackDamageNow;

	// �ǂ̍U�����s����
	EAttackPattern e_attackPattern;

	// �U�����J�n�����u��
	bool attackStartNow;

	// �����U����A�����čs�킹�Ȃ�
	EAttackPattern e_preAttackPattern;

	
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

	// �ǂ̍U�����s�������n��
	const EAttackPattern GetAttackPattern() { return e_attackPattern; }

	// �U�����s�����u�Ԃ��ǂ���
	const bool GetAttackStartNow() { return attackStartNow; }
};

