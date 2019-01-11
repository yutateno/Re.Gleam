#include "EnemyMove1.hpp"


// �����̃v���Z�X
void EnemyMove1::MoveProcess()
{
	// �㏸���̂Ƃ�
	if (upNow)
	{
		// �㏸��
		if (60.0f > area.y)
		{
			area.y += flyMove;
			shadowSize -= flyMove;
		}
		// �㏸����������
		else
		{
			upNow = false;
			flyMove = -0.1f;
			shadowSize = 60.0f;
		}
	}
	// ���~���̂̂Ƃ�
	else
	{
		// ���~��
		if (area.y > 30.0f)
		{
			area.y -= flyMove;
			shadowSize += flyMove;;
		}
		// ���~����������
		else
		{
			upNow = true;
			flyMove = -0.1f;
			shadowSize = 90.0f;
		}
	}


	// �n����������肳����
	if (flyMove < 0.5f)
	{
		flyMove += 0.05f;
	}
} /// void EnemyMove1::MoveProcess()


// �R���X�g���N�^
EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ, const float color) : BasicCreature(true)
{
	// �����蔻��̃X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;


	// ���e����p�̃X�e�[�W�̃R���W�������̍X�V
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(shadowStageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(shadowStageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j


	// ���f���̌����ƈʒu
	this->area = VGet(areaX, 40.0f, areaZ);


	// �}�e���A��
	material.Diffuse = GetColorF(0.0f, 0.0f, 1.0f, 0.0f);
	material.Specular = GetColorF(0.0f, 0.0f, 0.0f, 0.0f);
	material.Ambient = GetColorF(1.0f, 1.0f, 1.0f, 0.0f);
	material.Emissive = GetColorF(color, color, 1.0f, 0.0f);
	material.Power = 10.0f;


	// ���f���̊�{���
	modelHeight = 10.0f;
	modelWidth = 10.0f;

	
	// �����̉e�Ɋւ���
	shadowHeight = 70.0f;
	shadowSize = 90.0f;


	// �����Ɋւ���
	upNow = true;
	flyMove = 0.0f;
} /// EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ, const float color) : BasicCreature(true)


// �f�X�g���N�^
EnemyMove1::~EnemyMove1()
{
	MODEL_RELEASE(shadowStageHandle);
}


// �`��
void EnemyMove1::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);
	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);
	SetMaterialParam(material);
	DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth, 16, GetColor(68, 178, 227), GetColor(255, 255, 255), TRUE);
	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(FALSE);
	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(FALSE);


#ifdef _DEBUG
	if (MyDebug::enemyOneDrawFlag)
	{
		VECTOR viewArea = VAdd(area, VGet(0.0f, 60.0f, 0.0f));		// ���f���̏���Y���W�������Ă���̂Œ���

		DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth + 3, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}


// ���C���v���Z�X
void EnemyMove1::Process()
{
	// �����̃v���Z�X
	MoveProcess();
}


// �v���C���[���߂Â�����
void EnemyMove1::NearChara(const VECTOR characterArea)
{
	// �v���C���[�ɂ��������
	if (characterArea.x < area.x - 4.0f)
	{
		area.x -= 2.0f;
	}
	else if( characterArea.x > area.x + 4.0f)
	{
		area.x += 2.0f;
	}
	if (characterArea.z < area.z - 4.0f)
	{
		area.z -= 2.0f;
	}
	else if(characterArea.z > area.z + 4.0f)
	{
		area.z += 2.0f;
	}
}
