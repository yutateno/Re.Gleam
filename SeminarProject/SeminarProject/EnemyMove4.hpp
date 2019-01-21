#pragma once
#include "BasicCreature.hpp"
#include <random>


class EnemyMove4 : public BasicCreature
{
private:
	/// ���ꂼ��̈ʒu�Ɋւ���------------------------------------------------------

	// �O��̃L���������������ϐ�
	float direZAngle;

	// ���E�̃L���������������ϐ�
	float direXAngle;

	// ���̑O��̃L���������������ϐ�
	float nextDireZAngle;

	// ���̍��E�̃L���������������ϐ�
	float nextDireXAngle;

	// �L�����N�^�[�̈ʒu
	VECTOR playerCharaArea;

	// �L�����N�^�[�Ƃ̋���
	int playerCharaDistance;

	// �L�����N�^�[�������Ă���ꍇ�̌���
	float charaLookAtAngle;

	// �T�C�Y�����g�ɂȂ�܂ł̃_���[�W��
	const int bigBodyChangeDamage = 15;


	/// ���[�V�����Ɋւ���---------------------------------------------------------

	// ���[�V������ID
	enum MOTION { idle, walk, dash, attack, attack2, attack3, damage, death };

	// ���[�V�����̃v���Z�X
	void MotionProcess();


	/// �K�i�Ɋւ���---------------------------------------------------------------

	// �K�i�̃��f��
	std::vector<int> v_stairsHandle;


	/// �K�i�Ə��Ɋւ���-----------------------------------------------------------

	// �K�i�Ə��̃��f��
	std::vector<int> v_stairsRoadHandle;


	/// �����Ɋւ���---------------------------------------------------------------

	// �ǂ��v���Z�X
	void ChaseMoveProcess();

	// �����̃J�E���g
	int moveCount;


	/// �U���Ɋւ���---------------------------------------------------------------

	// �U���̃t���[��
	float attackFrame;

	// �U���ɂ�邠����������邩�ǂ���
	bool attackDamageNow;

	// �_���[�W�̐��l
	int damageCount;


	/// �����Ɋւ���---------------------------------------------------------------

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


	/// �e�N�X�`���Ɋւ���---------------------------------------------------------

	// �e�N�X�`���̑���ID�����ɂ���
	int textureHandle0;


public:
	// �R���X�g���N�^
	EnemyMove4(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
		, const int tex0, const VECTOR area, const float rotationY);

	// �f�X�g���N�^
	~EnemyMove4();


	// �`��
	void Draw();

	// ���f���`��
	void UniqueModelDraw();

	// �v���Z�X
	void Process();


	// �e�N�X�`���̐؂�ւ�
	void TextureReload();

	// �L�����N�^�[�̍��W�Ƌ�����c������
	void SetCharacterArea(const VECTOR characterArea, const int distance);

	// �U�����_���[�W�ɔ��f���邩�ǂ���
	const bool GetAttackDamage() const { return attackDamageNow; }

	// �T�C�Y�ł����Ƃ����ǂ���
	const bool GetBigNow() const { return damageCount <= bigBodyChangeDamage ? true : false; }

	// �I�v�V�����p���f���`��̌�n��
	void OptionActorDrawAfter() override {}
};

