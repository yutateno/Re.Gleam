#include "DropItemMove1.hpp"



/// -------------------------------------------------------------------------------------------
DropItemMove1::DropItemMove1(const int draw, const int tex0) : BasicObject()
{
	// �����ʒu��ݒ�
	area = VGet(1000.0f, 0.0f, 1000.0f);


	// �e�̃T�C�Y��ݒ�
	BasicObject::shadowHeight = 10.0f;
	BasicObject::shadowSize = 5.0f;


	// ���f���f�[�^�̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(draw);

	
	// �e�N�X�`���K��
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle, true);


	// ���f���̃T�C�Y��ύX
	MV1SetScale(this->modelHandle, VGet(0.2f, 0.2f, 0.2f));
	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, area);
}



/// -------------------------------------------------------------------------------------------
DropItemMove1::~DropItemMove1()
{
	GRAPHIC_RELEASE(textureHandle);
	MODEL_RELEASE(modelHandle);
}



/// -------------------------------------------------------------------------------------------
void DropItemMove1::Draw()
{
#ifdef _DEBUG
	if (MyDebug::dropItemOneDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, 1.0f, 0.0f)), 80.0f, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}
