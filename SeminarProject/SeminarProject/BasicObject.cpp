#include "BasicObject.hpp"
#include <typeinfo.h>

// ���̉e
bool BasicObject::ShadowFoot(int shadowModel)
{
	// �v���C���[�̒����ɑ��݂���n�ʂ̃|���S�����擾
	ShadowHitResDim = MV1CollCheck_Capsule(shadowModel, -1, area, VAdd(area, VGet(0.0f, -shadowHeight, 0.0f)), shadowSize);

	// ���_�f�[�^�ŕω��������������Z�b�g
	ShadowVertex[0].dif = GetColorU8(255, 255, 255, 255);
	ShadowVertex[0].spc = GetColorU8(0, 0, 0, 0);
	ShadowVertex[0].su = 0.0f;
	ShadowVertex[0].sv = 0.0f;
	ShadowVertex[1] = ShadowVertex[0];
	ShadowVertex[2] = ShadowVertex[0];

	// ���̒����ɑ��݂���|���S���̐������J��Ԃ�
	ShadowHitRes = ShadowHitResDim.Dim;
	if (ShadowHitResDim.HitNum == 0) return false;

	// ���C�e�B���O�𖳌��ɂ���
	SetUseLighting(FALSE);

	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �e�N�X�`���A�h���X���[�h�� CLAMP �ɂ���( �e�N�X�`���̒[����͒[�̃h�b�g�����X���� )
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);
	for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)
	{
		// �|���S���̍��W�͒n�ʃ|���S���̍��W
		ShadowVertex[0].pos = ShadowHitRes->Position[0];
		ShadowVertex[1].pos = ShadowHitRes->Position[1];
		ShadowVertex[2].pos = ShadowHitRes->Position[2];

		// ������Ǝ����グ�ďd�Ȃ�Ȃ��悤�ɂ���
		ShadowSlideVec = VScale(ShadowHitRes->Normal, 0.5f);
		ShadowVertex[0].pos = VAdd(ShadowVertex[0].pos, ShadowSlideVec);
		ShadowVertex[1].pos = VAdd(ShadowVertex[1].pos, ShadowSlideVec);
		ShadowVertex[2].pos = VAdd(ShadowVertex[2].pos, ShadowSlideVec);

		// �|���S���̕s�����x��ݒ肷��
		ShadowVertex[0].dif.a = 0;
		ShadowVertex[1].dif.a = 0;
		ShadowVertex[2].dif.a = 0;
		if (ShadowHitRes->Position[0].y > area.y - shadowHeight)
		{
			ShadowVertex[0].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[0].y - area.y) / shadowHeight));
		}

		if (ShadowHitRes->Position[1].y > area.y - shadowHeight)
		{
			ShadowVertex[1].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[1].y - area.y) / shadowHeight));
		}

		if (ShadowHitRes->Position[2].y > area.y - shadowHeight)
		{
			ShadowVertex[2].dif.a = (BYTE)(128 * (1.0f - fabs(ShadowHitRes->Position[2].y - area.y) / shadowHeight));
		}

		// �t�u�l�͒n�ʃ|���S���ƃv���C���[�̑��΍��W���犄��o��
		ShadowVertex[0].u = (ShadowHitRes->Position[0].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[0].v = (ShadowHitRes->Position[0].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[1].u = (ShadowHitRes->Position[1].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[1].v = (ShadowHitRes->Position[1].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[2].u = (ShadowHitRes->Position[2].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		ShadowVertex[2].v = (ShadowHitRes->Position[2].z - area.z) / (shadowSize * 2.0f) + 0.5f;

		// �e�|���S����`��
		DrawPolygon3D(ShadowVertex, 1, shadowHandle, TRUE);
	}

	// ���o�����n�ʃ|���S�����̌�n��
	MV1CollResultPolyDimTerminate(ShadowHitResDim);

	// ���C�e�B���O��L���ɂ���
	SetUseLighting(TRUE);

	// �y�o�b�t�@�𖳌��ɂ���
	SetUseZBuffer3D(FALSE);

	return true;
}



BasicObject::BasicObject()
{
	shadowHandle = -1;

	notViewCount = 0;

	optionRotaCount = 0;


	// ������
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
}

BasicObject::BasicObject(bool shadowDo)
{
	shadowHandle = -1;

	// �e�̓ǂݍ���
	LoadFile::MyLoad("media\\������\\media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);

	notViewCount = 0;

	optionRotaCount = 0;


	// ������
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
}


BasicObject::~BasicObject()
{
	GRAPHIC_RELEASE(shadowHandle);
}

// �`��
void BasicObject::ModelDraw()
{
	if (!CheckCameraViewClip(area) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight, 0.0f))) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight / 2.0f, 0.0f))))
	{
		MV1DrawModel(modelHandle);
		if (notViewCount != 0)
		{
			notViewCount = 0;
		}
	}
	else
	{
		if (++notViewCount <= 6)
		{
			MV1DrawModel(modelHandle);
		}
	}
}

void BasicObject::OptionActorDraw()
{
	if (++optionRotaCount > 360) optionRotaCount = 0;
	if (optionModelDrawCount++ > 10) MV1DrawModel(modelHandle);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, optionRotaCount * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, VGet(150.0f, -110.0f, -370.0f));
}

void BasicObject::OptionActorDrawBefore()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// �J�����̕`��͈͂��w��
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -650.0f), VGet(0.0f, 0.0f, 0.0f));
	optionModelDrawCount = 0;
}
