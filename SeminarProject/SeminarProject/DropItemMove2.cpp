#include "DropItemMove2.hpp"


DropItemMove2::DropItemMove2(const int draw, VECTOR area, const int tex0) : BasicObject()
{
	// �����ʒu��ݒ�
	this->area = area;


	// �ړI�ʒu��ݒ�
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-250, 250);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-250, 250);        // Z���W�p����
	nextAreaX = static_cast<float>(randInX(mt));
	nextAreaZ = static_cast<float>(randInZ(mt));
	moveAreaY = 0;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);

	rotationY = 0;

	flyAroundFrame = 0;

	deathNow = false;

	aliveNow = false;


	// �e�N�X�`���K��
	MV1SetTextureGraphHandle(this->modelHandle, 0, tex0, true);


	// ���f���̃T�C�Y��ύX
	MV1SetScale(this->modelHandle, VGet(0.2f, 0.2f, 0.2f));

	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);
}


DropItemMove2::~DropItemMove2()
{
	MODEL_RELEASE(modelHandle);
}


void DropItemMove2::Process()
{
	if (deathNow || !aliveNow) return;

	if (++rotationY >= 180) rotationY = 0;

	if (flyAroundFrame++ < 60)
	{
		area.x += nextAreaX / 60.0f;
		area.z += nextAreaZ / 60.0f;

		moveAreaY = (sin(-DX_PI_F / 2 + DX_PI_F / 30 * flyAroundFrame) + 1) / 2 * 120;
	}

	MV1SetRotationXYZ(modelHandle, VGet(0.0f, rotationY * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(this->modelHandle, VGet(area.x, area.y + moveAreaY, area.z));
}


void DropItemMove2::StolenChara(const VECTOR characterArea)
{
	if (deathNow || !aliveNow) return;

	// �v���C���[�ɂ��������
	if (characterArea.x < area.x - 20.0f)
	{
		area.x -= 10.0f;
	}
	else if (characterArea.x > area.x + 20.0f)
	{
		area.x += 10.0f;
	}
	if (characterArea.z < area.z - 20.0f)
	{
		area.z -= 10.0f;
	}
	else if (characterArea.z > area.z + 20.0f)
	{
		area.z += 10.0f;
	}
	if ((characterArea.y + 80.0f) < area.y - 4.0f)
	{
		area.y -= 2.0f;
	}
	else if ((characterArea.y + 80.0f) > area.y + 4.0f)
	{
		area.y += 2.0f;
	}
}
