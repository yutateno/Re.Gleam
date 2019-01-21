#include "StageStairs.hpp"



/// --------------------------------------------------------------------------------
StageStairs::StageStairs(const int draw, const VECTOR area
	, const int tex0, const float angle) : BasicObject()
{
	// ���W�ݒ�
	this->area = area;
	this->angle = angle;
	

	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	// �e�N�X�`���K��
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);


	// ���W�Ƀ��f����z�u
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, this->angle, 0.0f));
	MV1SetPosition(modelHandle, this->area);
}



/// --------------------------------------------------------------------------------
StageStairs::~StageStairs()
{
	// �e�N�X�`�����
	GRAPHIC_RELEASE(textureHandle);

	
	// ���f���J��
	MODEL_RELEASE(modelHandle);
}



/// --------------------------------------------------------------------------------
void StageStairs::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\kaidan\\D\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\kaidan\\P\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\kaidan\\normal\\kaidan.pyn", textureHandle, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}
