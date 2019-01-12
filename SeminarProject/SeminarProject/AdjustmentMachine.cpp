#include "AdjustmentMachine.hpp"


// �R���X�g���N�^
AdjustmentMachine::AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1): BasicObject()
{
	// ���W������
	this->area = area;


	// ���f���f�[�^��ǂݍ���
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);

	
	// ��񏉊���
	modelHeight = 100.0f;
	modelWidth = 70.0f;


	// ���[�u2�p�̕ϐ�
	if (BASICPARAM::e_nowScene <= ESceneNumber::SECONDMOVE)
	{
		canTouch = false;
		blendCount = 0;
		dropCount = 0;
		nextBlendCount = 0;
	}
	else
	{
		canTouch = true;
	}


	// �e�N�X�`���K��
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandleDisplayBlack = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	LoadFile::MyLoad("media\\������\\media\\Terminal\\T_displayblack.pyn", textureHandleDisplayBlack, ELOADFILE::graph);
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandleDisplayBlack, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);


	// ���W�Ƀ��f����z�u
	MV1SetPosition(this->modelHandle, area);
} /// AdjustmentMachine::AdjustmentMachine(const int draw, const VECTOR area, const int tex0, const int tex1): BasicObject()


// �f�X�g���N�^
AdjustmentMachine::~AdjustmentMachine()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandleDisplayBlack);


	// ���f���J��
	MODEL_RELEASE(modelHandle);
}


// �`��
void AdjustmentMachine::Draw()
{
	// ���[�u2�ȉ��œ��߂��܂�����Ă�����
	if (BASICPARAM::e_nowScene <= ESceneNumber::SECONDMOVE
		&& blendCount < 255)
	{
		if (nextBlendCount > blendCount) blendCount += 3;
		nextBlendCount = dropCount * 17;

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
	}
	else
	{
		if(!canTouch) canTouch = true;
	}

#ifdef _DEBUG
	if (MyDebug::adjustmentMachineDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}


// �e�N�X�`�������ւ�
void AdjustmentMachine::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\Terminal\\normal\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\Terminal\\normal\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\Terminal\\D\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\Terminal\\D\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\Terminal\\P\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\Terminal\\P\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\Terminal\\normal\\Terminal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\Terminal\\normal\\T_display.pyn", textureHandle1, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
}


// �f�B�X�v���C�̃e�N�X�`����؂�ւ���
void AdjustmentMachine::ChangeDisplayTexture(bool touchNow)
{
	if (touchNow)
	{
		MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	}
	else
	{
		MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandleDisplayBlack, false);
	}
}
