#include "DropItemMove2.hpp"


DropItemMove2::DropItemMove2(const int draw, VECTOR area, const int tex0) : BasicObject()
{
	// �����ʒu��ݒ�
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-20, 20);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-20, 20);        // Z���W�p����
	this->area = VAdd(area, VGet(static_cast<float>(randInX(mt)), 0.0f, static_cast<float>(randInZ(mt))));

	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);

	rotationY = 0;

	deathNow = false;

	aliveNow = false;


	// �e�N�X�`���K��
	textureHandle = -1;

	textureHandle = tex0;

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, true);


	// ���f���̃T�C�Y��ύX
	MV1SetScale(this->modelHandle, VGet(0.2f, 0.2f, 0.2f));

	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);
}


DropItemMove2::~DropItemMove2()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}

void DropItemMove2::Draw()
{
	if (deathNow || !aliveNow) return;

	BasicObject::Draw();
}


void DropItemMove2::Process()
{
	if (deathNow || !aliveNow) return;

	if (++rotationY >= 180) rotationY = 0;

	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotationY * DX_PI_F / 180.0f, 0.0f));
}


void DropItemMove2::StolenChara(const VECTOR characterArea)
{
	if (deathNow || !aliveNow) return;

	if (characterArea.x <= area.x)
	{
		area.x -= 5.0f;
	}
	else
	{
		area.x += 5.0f;
	}
	if (characterArea.z <= area.z)
	{
		area.z -= 5.0f;
	}
	else
	{
		area.z += 5.0f;
	}

	if (characterArea.y <= area.y)
	{
		area.y -= 2.0f;
	}
	else
	{
		area.y += 2.0f;
	}

	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);
}


void DropItemMove2::TextureReload()
{
	if (deathNow) return;

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
