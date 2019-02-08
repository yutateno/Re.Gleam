#include "DropItemMove3.hpp"



/// --------------------------------------------------------------------------------------------------
DropItemMove3::DropItemMove3(const int draw, VECTOR area, const int tex0) : BasicObject()
{
	// �����ʒu��ݒ�
	this->area = area;


	// �ړI�ʒu��ݒ�
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randInX(-250, 250);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-250, 250);        // Z���W�p����
	nextAreaX = static_cast<float>(randInX(mt));
	nextAreaZ = static_cast<float>(randInZ(mt));
	moveAreaY = 0;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);


	// ��񏉊���
	rotationY = 0;
	flyAroundFrame = 0;
	deathNow = false;
	aliveNow = false;


	// �e�N�X�`���K��
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, true);


	// ���f���̃T�C�Y��ύX
	MV1SetScale(this->modelHandle, VGet(0.1f, 0.1f, 0.1f));
	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);
} /// DropItemMove3::DropItemMove3(const int draw, VECTOR area, const int tex0) : BasicObject()



/// --------------------------------------------------------------------------------------------------
DropItemMove3::~DropItemMove3()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle);


	// ���f���J��
	MODEL_RELEASE(modelHandle);
}



/// --------------------------------------------------------------------------------------------------
void DropItemMove3::Process()
{
	// �����Ă��Ȃ�������ł��邩
	if (deathNow || !aliveNow) return;

	
	// ��ɉ�]������
	if (++rotationY >= 180) rotationY = 0;


	// ��юU�鏈��
	if (flyAroundFrame++ < 60)
	{
		area.x += nextAreaX / 60.0f;
		area.z += nextAreaZ / 60.0f;

		moveAreaY = (sin(-DX_PI_F / 2 + DX_PI_F / 30 * flyAroundFrame) + 1) / 2 * 120;
	}


	// ��]�ƍ��W���X�V
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotationY * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(this->modelHandle, VGet(area.x, area.y + moveAreaY, area.z));
}



/// --------------------------------------------------------------------------------------------------
void DropItemMove3::ChaseActor(const VECTOR chaseArea)
{
	if (deathNow || !aliveNow) return;

	// �v���C���[�ɂ��������
	if (chaseArea.x < area.x - 20.0f)
	{
		area.x -= 10.0f;
	}
	else if (chaseArea.x > area.x + 20.0f)
	{
		area.x += 10.0f;
	}
	if (chaseArea.z < area.z - 20.0f)
	{
		area.z -= 10.0f;
	}
	else if (chaseArea.z > area.z + 20.0f)
	{
		area.z += 10.0f;
	}
	if ((chaseArea.y + 80.0f) < area.y - 4.0f)
	{
		area.y -= 2.0f;
	}
	else if ((chaseArea.y + 80.0f) > area.y + 4.0f)
	{
		area.y += 2.0f;
	}
}



/// --------------------------------------------------------------------------------------------------
void DropItemMove3::TextureReload()
{
	if (deathNow) return;

	
	GRAPHIC_RELEASE(textureHandle);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\move3\\�C���N�I��\\correction\\normal\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\move3\\�C���N�I��\\correction\\D\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\move3\\�C���N�I��\\correction\\P\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\move3\\�C���N�I��\\correction\\normal\\ink.pyn", textureHandle, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, false);
}



/// --------------------------------------------------------------------------------------------------
std::thread DropItemMove3::ThsTextureReload()
{
	return std::thread(&DropItemMove3::TextureReload, this);
}



/// --------------------------------------------------------------------------------------------------
void DropItemMove3::SetAlive(VECTOR dropArea, bool alive)
{
	aliveNow = alive;
	area = dropArea;
	MV1SetPosition(this->modelHandle, area);
}
