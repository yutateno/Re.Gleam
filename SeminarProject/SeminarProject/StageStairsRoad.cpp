#include "StageStairsRoad.hpp"



/// --------------------------------------------------------------------------------
StageStairsRoad::StageStairsRoad(const int draw, const VECTOR area
	, const int tex0, const int tex1, const float angle) : BasicObject()
{
	// ���W�ݒ�
	this->area = area;
	this->angle = angle;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);


	// �e�N�X�`���K��
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);


	// ���W�Ƀ��f����z�u
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, this->angle, 0.0f));
	MV1SetPosition(modelHandle, this->area);
}



/// --------------------------------------------------------------------------------
StageStairsRoad::~StageStairsRoad()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle0);


	// ���f���J��
	MODEL_RELEASE(modelHandle);
}



/// --------------------------------------------------------------------------------
void StageStairsRoad::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\�K�i�Ə�����\\normal\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\�K�i�Ə�����\\normal\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\�K�i�Ə�����\\D\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\�K�i�Ə�����\\D\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\�K�i�Ə�����\\P\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\�K�i�Ə�����\\P\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\�K�i�Ə�����\\normal\\kaidan.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\�K�i�Ə�����\\normal\\yuka.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}
