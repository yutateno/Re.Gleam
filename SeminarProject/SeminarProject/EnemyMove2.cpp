#include "EnemyMove2.hpp"


EnemyMove2::EnemyMove2(const VECTOR area, const int modelHandle, const int tex0) : BasicCreature()
{
	// ���W��ݒ�
	this->area = VAdd(area, VGet(0.0f, 10.0f, 0.0f));


	// �T�C�Y��ݒ�
	modelHeight = 100.0f;
	modelWigth = 50.0f;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// �e�N�X�`���K��
	textureHandle = -1;
	textureHandle = tex0;
	/*switch (BASICPARAM::e_TextureColor)
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
	}*/

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
	if (eraseExistence) return;

	/*if (!deathFlag)
	{
		BasicObject::ShadowFoot();
	}*/

	BasicObject::Draw();



#ifdef _DEBUG
	if (MyDebug::enemyTwoDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWigth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}

void EnemyMove2::Process()
{
	if (eraseExistence) return;
	// �X�e�[�W�̂����蔻��
	//StageHit();


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
			blendCount -= 5;
		}
		else
		{
			eraseExistence = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	}

	MV1SetPosition(this->modelHandle, area);
}

void EnemyMove2::TextureReload()
{
	if (eraseExistence) return;
	GRAPHIC_RELEASE(textureHandle);

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
}
