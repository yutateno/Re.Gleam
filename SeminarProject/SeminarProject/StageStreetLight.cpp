#include "StageStreetLight.hpp"


// �R���X�g���N�^
StageStreetLight::StageStreetLight(const int draw, const VECTOR area
	, const int tex0, const int tex1, const float angle) : BasicObject()
{
	// ���W�Ɗp�x�̏�����
	this->area = area;
	this->angle = angle;


	// ���f���f�[�^��ǂݍ���
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
	MV1SetPosition(this->modelHandle, this->area);
}


// �f�X�g���N�^
StageStreetLight::~StageStreetLight()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);


	// ���f���J��
	MODEL_RELEASE(modelHandle);
}


// �e�N�X�`�������ւ�
void StageStreetLight::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\�X��\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\�X��\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�X��\\D\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\�X��\\D\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�X��\\P\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\�X��\\P\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\�X��\\normal\\body_col.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\�X��\\normal\\lamp_COLandems.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}
