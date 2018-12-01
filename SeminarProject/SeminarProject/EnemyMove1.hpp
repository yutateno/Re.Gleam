#pragma once
#include "BasicCreature.hpp"


class EnemyMove1 : public BasicCreature
{
private:
	/// �����Ɋւ���

	// ���オ�蒆���ǂ���
	bool upNow;

	// �㉺�̃X�s�[�h
	float flyMove;

	// �㉺�����̃v���Z�X
	void MoveProcess();

	// �}�e���A���𒲐��ێ�
	MATERIALPARAM material;


public:
	// �R���X�g���N�^
	EnemyMove1(const int collStageHandle, const float areaX, const float areaZ, const float color);

	// �f�X�g���N�^
	~EnemyMove1();


	// �`��
	void Draw();

	// �v���Z�X
	void Process();

	// �L�����N�^�[���߂Â�����
	void StolenChara(const VECTOR characterArea);
};
