#pragma once
#include "BasicObject.hpp"
#include "SoundProcess.hpp"


class BasicCreature : public BasicObject
{
protected:
	/// �ʒu�ɂ���------------------------

	// �ړ��O�̒��O�̃L�����ʒu
	VECTOR preArea;	

	// �L�����N�^�[�̌����Ă���A���O��
	float angle;	

	// �ړ���̒��O�̃L�����ʒu
	VECTOR nextArea;


	/// �����Ɋւ���------------------------------------

	// �ړ��X�s�[�h
	float walkSpeed;	

	// ���[�V�����X�s�[�h
	float animSpeed;	

	// �����蔻�胂�f���S�Ă��痎���Ă��邩�ǂ���
	int fallCount;		

	// ���ł��邩�ǂ���
	bool jumpNow;		

	// ��ɔ��ł���
	bool jumpUpNow;		

	// �W�����v��
	float jumpPower;	


	/// ���f���Ɋւ���--------------------

	// ���f���̉���
	float modelWigth;	


	/// ���[�V�����Ɋւ���-------------------

	// ���[�V�����̃A�^�b�`
	int attachMotion;			

	// ���݂̃��[�V�����ԍ�
	int attachNum;				

	// ���[�V�����̑�������
	float totalTime;			

	// ���[�V�����ύX
	void Player_PlayAnim(int attach);		

	// ���[�V��������
	void Player_AnimProcess();				


	/// �����蔻��-----------------------------

	// �����Ă��邩�ǂ���
	bool moveFlag;						

	// �����蔻����s��
	void StageHit();					

	// �����蔻����s��
	void ActorHit(int stageHandle);		


	/// �U�����󂯂����Ɋւ���-----------

	// �_���[�W���󂯂����ǂ���
	bool damageHit;

	// �|�ꂽ���ǂ���
	bool deathFlag;

	// �`�悩��������ǂ���
	bool eraseExistence;

	// ���߃u�����h�̃J�E���g
	int blendCount;


private:
	/// ���[�V�����Ɋւ���-------------

	// ���[�V�����̌��݂̎���
	float nowPlayTime;			

	// �u�����h����
	float motionBlendTime;		

	// ���O�̃��[�V�����A�^�b�`
	int preAttach;				

	// ���O�̃��[�V��������
	float preMotionPlayTime;	


	/// �����蔻��-------------------------------------------

	// �X�e�[�W�n���h��
	int stageHandle;					

	// ���肷��ǂ̐�
	int wallNum;						

	// ���肷�鏰�̐�
	int floorNum;						

	// �������Ă��邩�ǂ���
	bool hitFlag;						

	// �������Ă���Y���W�̍ő�
	float maxYHit;						

	// �������Ă���Y���W�̍ŏ�
	float minYHit;						

	// ���͂̃|���S����������\����
	MV1_COLL_RESULT_POLY_DIM m_hitDim;			

	// �Ǘp�̃|���S���̍\����
	MV1_COLL_RESULT_POLY* wallPoly[2048];		

	// ���p�̃|���S���̍\����
	MV1_COLL_RESULT_POLY* floorPoly[2048];		

	// �|���S���̍\���̂ɃA�N�Z�X����\����
	MV1_COLL_RESULT_POLY* mainPoly;			

	// �����Ƃ̔����������\����
	HITRESULT_LINE lineResult;
	/// ----------------------------------------------------


public:
	// �R���X�g���N�^
	BasicCreature();

	// �R�s�[�R���X�g���N�^
	BasicCreature(const int collStageHandle);

	// �f�X�g���N�^
	virtual ~BasicCreature();


	// ���O�̍��W�ɖ߂�
	void SetAreaReturn();

	// ���������牟���o���悤�ɂ���
	void HitCircleReturn(VECTOR hitUnderArea, VECTOR hitTopArea);

	// ����̐����������Ă��邩�ǂ���
	void HitLineReturn(VECTOR hitOneArea, VECTOR hitTwoArea);


	/// �Q�b�^�[�Z�b�^�[
	   
	// �U������Ƃ��̃��f���̃t���[���̐�[
	VECTOR GetAttackFirstFrameArea() {};		

	// �U������Ƃ��̃��f���̃t���[���̌�[
	VECTOR GetAttackEndFrameArea() {};

	// ���񂾂��ǂ���
	bool GetDeathFlag() { return deathFlag; }

	// �`�悩��������ǂ���
	bool GetEraseExistence() { return eraseExistence; }
};