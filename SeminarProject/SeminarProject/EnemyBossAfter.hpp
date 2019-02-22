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
	int moveDoCount;

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

	// �_���[�W���󂯂����l
	int damageCount;

	
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

	// ���񂾂̂Ŏ��̂������Ă���
	bool SetDeathBlendDraw();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �񓯊��e�N�X�`�������ւ�
	std::thread ThsTextureReload();


	// �U�����_���[�W�ɔ��f���邩�ǂ���
	const bool GetAttackDamage() const { return attackDamageNow; }

	// �ǂ̍U�����s�������n��
	const EAttackPattern GetAttackPattern() const { return e_attackPattern; }

	// �U�����s�����u�Ԃ��ǂ���
	const bool GetAttackStartNow() const { return attackStartNow; }

	// �U���������n��
	const bool GetAttackNow() const { return attackMotionNow; }

	// ���U�肩�����U���̌�����I�̒��Ԃ̍��W��n��
	const VECTOR GetAttackFlameOneArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 15), MV1GetFramePosition(modelHandle, 14)), 0.5); }

	// ���U�肩�����U���̌�����I�܂ł̃J�v�Z���̉�����n��
	const float GetAttackFlameOneWidth() const { return 350.0f; }

	// ���U�肩�����U���̌�����I�܂ł̃J�v�Z���̏c����n��
	const float GetAttackFlameOneHeight() const { return 20.0f; }

	// ���U�肩�����U���̕I������̒��Ԃ̍��W��n��
	const VECTOR GetAttackFlameTwoArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 16), MV1GetFramePosition(modelHandle, 15)), 0.5); }

	// ���U�肩�����U���̕I������܂ł̃J�v�Z���̉�����n��
	const float GetAttackFlameTwoWidth() const { return 460.0f; }

	// ���U�肩�����U���̕I������܂ł̃J�v�Z���̏c����n��
	const float GetAttackFlameTwoHeight() const { return 50.0f; }

	// ���U�肩�����U���̎�񂩂���̒��Ԃ̍��W��n��
	const VECTOR GetAttackFlameThreeArea() const { return VScale(VAdd(MV1GetFramePosition(modelHandle, 17), MV1GetFramePosition(modelHandle, 16)), 0.5); }

	// ���U�肩�����U���̎�񂩂���܂ł̃J�v�Z���̉�����n��
	const float GetAttackFlameThreeWidth() const { return 360.0f; }

	// ���U�肩�����U���̎�񂩂���܂ł̃J�v�Z���̏c����n��
	const float GetAttackFlameThreeHeight() const { return 50.0f; }
};

