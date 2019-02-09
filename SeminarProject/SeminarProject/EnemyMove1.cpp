#include "EnemyMove1.hpp"



/// ---------------------------------------------------------------------------------------------------------
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



/// ---------------------------------------------------------------------------------------------------------
EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ
	, const float color) : BasicCreature(true)
{
	// �����蔻��̃X�e�[�W�̃R���W�������
	stageHandle = -1;


	// ���e����p�̃X�e�[�W�̃R���W�������̐ݒ�
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(shadowStageHandle, -1);
	MV1SetFrameVisible(shadowStageHandle, -1, false);
	MV1RefreshCollInfo(shadowStageHandle, -1);


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
} /// EnemyMove1::EnemyMove1(const int collStageHandle, const float areaX, const float areaZ



/// ---------------------------------------------------------------------------------------------------------
EnemyMove1::~EnemyMove1()
{
	MODEL_RELEASE(shadowStageHandle);
}



/// ---------------------------------------------------------------------------------------------------------
void EnemyMove1::Draw()
{
	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	BasicObject::ShadowFoot(shadowStageHandle);


	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetMaterialParam(material);
	DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth, 16, GetColor(68, 178, 227), GetColor(255, 255, 255), TRUE);
	SetWriteZBuffer3D(FALSE);
	SetUseZBuffer3D(FALSE);


#ifdef _DEBUG
	if (MyDebug::enemyOneDrawFlag)
	{
		DrawSphere3D(VAdd(area, VGet(0.0f, 60.0f, 0.0f)), modelWidth + 3, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}



/// ---------------------------------------------------------------------------------------------------------
void EnemyMove1::Process()
{
	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	// �����̃v���Z�X
	MoveProcess();
}



/// ---------------------------------------------------------------------------------------------------------
void EnemyMove1::NearChara(const VECTOR characterArea)
{
	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	// �v���C���[�ɋ߂Â�
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
