#include "StageStairs.hpp"


StageStairs::StageStairs(const int draw, const int collStageHandle, const VECTOR area, const int tex0) : BasicObject(collStageHandle)
{
	// ���W�ݒ�
	this->area = area;


	// �e�̐ݒ�
	shadowHeight = 10.0f;
	shadowSize = 5.0f;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// �e�N�X�`���K��
	textureHandle = -1;

	textureHandle = tex0;
	/*switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}*/

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);


	// ���W�Ƀ��f����z�u
	MV1SetPosition(modelHandle, area);
}

StageStairs::~StageStairs()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void StageStairs::Draw()
{
	BasicObject::ShadowFoot();


	BasicObject::Draw();
}

void StageStairs::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
