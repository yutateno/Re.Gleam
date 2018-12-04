#include "EnemyMove2.hpp"


EnemyMove2::EnemyMove2(const int collStageHandle, const VECTOR area, const int modelHandle) : BasicCreature(collStageHandle)
{
	// ���W��ݒ�
	this->area = VAdd(area, VGet(0.0f, 10.0f, 0.0f));


	// �T�C�Y��ݒ�
	modelHeight = 100.0f;
	modelWigth = 50.0f;

	shadowHeight = 10.0f;
	shadowSize = 15.0f;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// �e�N�X�`���K��
	textureHandle = -1;
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\������\\media\\�u���b�N\\whiteblack\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\�u���b�N\\normal\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�u���b�N\\D\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�u���b�N\\P\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\�u���b�N\\normal\\tex.pyn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);

	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);

	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// ���W�Ƀ��f����z�u
	MV1SetPosition(this->modelHandle, area);
}

EnemyMove2::~EnemyMove2()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void EnemyMove2::Draw()
{
	if (!deathFlag)
	{
		BasicObject::ShadowFoot();
	}

	BasicObject::Draw();



#ifdef _ENEMY2_DEBUG
	DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWigth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
#endif // _ENEMY2_DEBUG
}

void EnemyMove2::Process()
{
	// �X�e�[�W�̂����蔻��
	StageHit();


	// �_���[�W�󂯂���
	if (damageHit)
	{
		deathFlag = true;
	}

	// ���񂾂Ƃ�
	if (deathFlag)
	{
		if (blendCount >= 0)
		{
			blendCount--;
		}
		else
		{
			viewDrawFlag = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	}

	MV1SetPosition(this->modelHandle, area);
}

void EnemyMove2::SetArea(const VECTOR area)
{
	this->area = area;
}
