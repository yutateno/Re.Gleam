#include "EnemyMove2.hpp"


/// -------------------------------------------------------------------------------------------------
EnemyMove2::EnemyMove2(const VECTOR area, const int modelHandle, const int tex0) : BasicCreature()
{
	// �ϐ��̏�����
	shadowStageHandle = -1;
	stageHandle = -1;


	// ���W��ݒ�
	this->area = VAdd(area, VGet(0.0f, 10.0f, 0.0f));


	// �T�C�Y��ݒ�
	modelHeight = 100.0f;
	modelWidth = 100.0f;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// �e�N�X�`���K��
	MV1SetTextureGraphHandle(this->modelHandle, 0, tex0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// ���W�Ƀ��f����z�u
	MV1SetPosition(this->modelHandle, area);


	// �R���W��������ݒ�
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove2::EnemyMove2(const VECTOR area, const int modelHandle, const int tex0) : BasicCreature()


/// -------------------------------------------------------------------------------------------------
EnemyMove2::~EnemyMove2()
{
	MODEL_RELEASE(modelHandle);
}


/// -------------------------------------------------------------------------------------------------
void EnemyMove2::Draw()
{
#ifdef _DEBUG
	if (MyDebug::enemyTwoDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
			, modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}


// �v���Z�X
void EnemyMove2::Process()
{
	if (eraseExistence) return;


	// �_���[�W�󂯂���
	if (damageHit)
	{
		deathFlag = true;

		damageHit = false;
	}


	// ���񂾂Ƃ�
	if (deathFlag)
	{
		// ���f���̓��ߒl��0�ȏゾ������
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		// ���f�������߂�����
		else
		{
			// ���݂����������Ƃɂ���
			eraseExistence = true;
		}


		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	}


	MV1SetPosition(this->modelHandle, area);
} /// void EnemyMove2::Process()
