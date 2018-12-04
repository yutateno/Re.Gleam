#pragma once
#include "BasicCreature.hpp"


class EnemyMove2 : public BasicCreature
{
private:
	// �e�N�X�`��
	int textureHandle;
	int outTextureHandle;


public:
	// �R���X�g���N�^
	EnemyMove2(const int collStageHandle, const VECTOR area, const int modelHandle);

	// �f�X�g���N�^
	~EnemyMove2();

	
	// �`��
	void Draw();

	// �v���Z�X
	void Process();

	
	/// �Q�b�^�[�Z�b�^�[

	// ���W��ݒ肷��
	void SetArea(const VECTOR area);
};

