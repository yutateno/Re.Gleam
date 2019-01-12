#include "BaseMove.hpp"

bool BaseMove::endFlag;		// �I���t���b�O
ESceneNumber BaseMove::scene;	// ���݂̃V�[��


// �v���C���[�̃V���h�E�}�b�v�ւ̏���
void BaseMove::ShadowCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapCharaHandle);
}


// �v���C���[�ȊO�̃V���h�E�}�b�v�ւ̏���
void BaseMove::ShadowAnotherCharaSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapAnotherCharaHandle);
}


// �X�e�[�W�̃V���h�E�}�b�v�ւ̕`��̏���
void BaseMove::ShadowNoMoveSetUpBefore()
{
	ShadowMap_DrawSetup(shadowMapNoMoveHandle);
}


// �V���h�E�}�b�v�̏I��
void BaseMove::ShadowSetUpAfter()
{
	ShadowMap_DrawEnd();
}


// �v���C���[�̕`��Ɏg�p����V���h�E�}�b�v��ݒ�
void BaseMove::ShadowCharaDrawBefore()
{
	SetUseShadowMap(0, shadowMapCharaHandle);
}


// �v���C���[�̕`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
void BaseMove::ShadowCharaDrawAfter()
{
	SetUseShadowMap(0, -1);
}


// �v���C���[�ȊO�̕`��Ɏg�p����V���h�E�}�b�v��ݒ�
void BaseMove::ShadowAnotherCharaDrawBefore()
{
	SetUseShadowMap(1, shadowMapAnotherCharaHandle);
}


// �v���C���[�ȊO�̕`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
void BaseMove::ShadowAnotherCharaDrawAfter()
{
	SetUseShadowMap(1, -1);
}


// �X�e�[�W�̕`��Ɏg�p����V���h�E�}�b�v��ݒ�
void BaseMove::ShadowNoMoveDrawBefore()
{
	SetUseShadowMap(2, shadowMapNoMoveHandle);
}


// �X�e�[�W�̕`��Ɏg�p����V���h�E�}�b�v�̐ݒ������
void BaseMove::ShadowNoMoveDrawAfter()
{
	SetUseShadowMap(2, -1);
}


// �V���h�E�}�b�v�̒��S���W���v���C���[�ɍX�V
void BaseMove::ShadowArea(const VECTOR charaArea)
{
	SetShadowMapDrawArea(shadowMapCharaHandle, VAdd(charaArea, shadowCharaLowArea), VAdd(charaArea, shadowCharaHighArea));
	SetShadowMapDrawArea(shadowMapAnotherCharaHandle, VAdd(charaArea, shadowAnotherCharaLowArea), VAdd(charaArea, shadowAnotherCharaHighArea));
}


// �X�J�C�{�b�N�X�̕`��
void BaseMove::SkyBoxDraw()
{
	// ���C�e�B���O�𖳌��ɂ���
	SetUseLighting(FALSE);
	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);
	MV1DrawModel(skyBoxUp);
	MV1DrawModel(skyBoxUnder);
	// ���C�e�B���O��L���ɂ���
	SetUseLighting(TRUE);
	// �y�o�b�t�@�𖳌��ɂ���
	SetUseZBuffer3D(FALSE);
}


// �X�J�C�{�b�N�X�̃v���Z�X
void BaseMove::SkyBoxProcess(const VECTOR characterArea)
{
	// �|�W�V�������v���C���[���S�ɂ���
	MV1SetPosition(skyBoxUp, characterArea);
	MV1SetPosition(skyBoxUnder, characterArea);
}


// �X�J�C�{�b�N�X�̏�����
void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)
{
	/// �X�J�C�{�b�N�X�̏�Ɋւ���-----------------------------------------
	// ���f���ǂݍ���
	this->skyBoxUp = MV1DuplicateModel(skyBoxUp);
	

	// �e�N�X�`���K��
	textureHandle = -1;
	textureHandle = tex0;
	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);


	// �X�P�[���ύX
	MV1SetScale(this->skyBoxUp, VGet(170.0f, 170.0f, 170.0f));


	/// �X�J�C�{�b�N�X�̉��Ɋւ���-------------------------------------------
	// ���f���ǂݍ���
	this->skyBoxUnder = MV1DuplicateModel(this->skyBoxUp);


	// �e�N�X�`���K��
	MV1SetTextureGraphHandle(this->skyBoxUnder, 0, textureHandle, false);


	// �X�P�[���ύX
	MV1SetScale(this->skyBoxUnder, VGet(170.0f, 170.0f, 170.0f));


	// ���P�[�V�����ύX
	MV1SetRotationXYZ(this->skyBoxUnder, VGet(DX_PI_F, 0.0f, 0.0f));
} /// void BaseMove::SetInitSkyBox(const int skyBoxUp, const int tex0)


// �X�J�C�{�b�N�X�̃e�N�X�`�������ւ�
void BaseMove::SkyTextureReload()
{
	GRAPHIC_RELEASE(textureHandle);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\�X�J�C�{�b�N�X\\normal\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�X�J�C�{�b�N�X\\D\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\�X�J�C�{�b�N�X\\P\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\�X�J�C�{�b�N�X\\normal\\BlueSky.byn", textureHandle, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->skyBoxUp, 0, textureHandle, false);
}


// �R���X�g���N�^
BaseMove::BaseMove()
{
	SetLightEnable(TRUE);	// ������L���ɂ���


	// �t�H�O�Ɋւ���
	SetFogEnable(TRUE);					// �t�H�O��L���ɂ���
	SetFogColor(128, 128, 128);			// �t�H�O�̐F�ɂ���
	SetFogStartEnd(3500.0f, 6000.0f);	// �t�H�O�̊J�n����


	// �V���h�E�}�b�v�n���h���̍쐬
	shadowMapCharaHandle = MakeShadowMap(2048, 2048);
	shadowMapAnotherCharaHandle = MakeShadowMap(512, 512);
	shadowMapNoMoveHandle = MakeShadowMap(256, 256);


	// �V���h�E�}�b�v�ɕ`�悷��͈͂�ݒ�
	shadowCharaLowArea = VGet(-500.0f, -1.0f, -500.0f);
	shadowCharaHighArea = VGet(500.0f, 10.0f, 500.0f);

	shadowAnotherCharaLowArea = VGet(-2000.0f, -1.0f, -2000.0f);
	shadowAnotherCharaHighArea = VGet(2000.0f, 100.0f, 2000.0f);

	shadowNoMoveLowArea = VGet(-2000.0f, -1.0f, -2000.0f);
	shadowNoMoveHighArea = VGet(2000.0f, 1000.0f, 2000.0f);

	SetShadowMapDrawArea(shadowMapCharaHandle, shadowCharaLowArea, shadowCharaHighArea);
	SetShadowMapDrawArea(shadowMapAnotherCharaHandle, shadowAnotherCharaLowArea, shadowAnotherCharaHighArea);
	SetShadowMapDrawArea(shadowMapNoMoveHandle, shadowNoMoveLowArea, shadowNoMoveHighArea);


	// ���C�g�̕�����ݒ�
	lightDire = VGet(-0.5f, -0.7f, 0.5f);
	SetLightDirection(lightDire);


	// �V���h�E�}�b�v���z�肷�郉�C�g�̕������Z�b�g
	SetShadowMapLightDirection(shadowMapCharaHandle, lightDire);
	SetShadowMapLightDirection(shadowMapAnotherCharaHandle, lightDire);
	SetShadowMapLightDirection(shadowMapNoMoveHandle, lightDire);


	// �X�J�C�{�b�N�X�Ɋւ���
	skyBoxUnder = -1;
	skyBoxUp = -1;
	textureHandle = -1;
}


// �f�X�g���N�^
BaseMove::~BaseMove()
{
	// �V���h�E�}�b�v�̍폜
	SHADOW_MAP_RELEASE(shadowMapNoMoveHandle);
	SHADOW_MAP_RELEASE(shadowMapAnotherCharaHandle);
	SHADOW_MAP_RELEASE(shadowMapCharaHandle);

	// �X�J�C�{�b�N�X�̍폜
	MODEL_RELEASE(skyBoxUnder);
	MODEL_RELEASE(skyBoxUp);
	GRAPHIC_RELEASE(textureHandle);
}
