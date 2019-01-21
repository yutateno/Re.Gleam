#include "BasicObject.hpp"
#include <typeinfo.h>



/// --------------------------------------------------------------------------------
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


	SetUseLighting(FALSE);	// ���C�e�B���O�𖳌��ɂ���
	SetUseZBuffer3D(TRUE);	// �y�o�b�t�@��L���ɂ���


	// �e�N�X�`���A�h���X���[�h�� CLAMP �ɂ���
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
	} /// for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)


	// ���o�����n�ʃ|���S�����̌�n��
	MV1CollResultPolyDimTerminate(ShadowHitResDim);


	SetUseLighting(TRUE);	// ���C�e�B���O��L���ɂ���
	SetUseZBuffer3D(FALSE);	// �y�o�b�t�@�𖳌��ɂ���
	return true;
} /// bool BasicObject::ShadowFoot(int shadowModel)



/// --------------------------------------------------------------------------------
BasicObject::BasicObject()
{
	// ��񏉊���
	shadowHandle = -1;
	notViewCount = 0;
	optionRotaCount = 0;
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
	move6_circle = 0;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::BasicObject(bool shadowDo)
{
	// �e�̓ǂݍ���
	shadowHandle = -1;
	LoadFile::MyLoad("media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);


	// ��񏉊���
	notViewCount = 0;
	optionRotaCount = 0;
	modelHeight = 0;
	modelHandle = -1;
	shadowHeight = 0;
	shadowSize = 0;
	area = VGet(0, 0, 0);
	ShadowHitResDim;
	ShadowHitRes = nullptr;
	ZeroMemory(ShadowVertex, sizeof(ShadowVertex));
	move6_circle = 0;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::~BasicObject()
{
	// �e�n���h���J��
	GRAPHIC_RELEASE(shadowHandle);
}



/// --------------------------------------------------------------------------------
void BasicObject::ModelDraw()
{
	// �X�N���[�����W���ɂ�����
	if (!CheckCameraViewClip(area) && !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight, 0.0f)))
		&& !CheckCameraViewClip(VAdd(area, VGet(0.0f, modelHeight / 2.0f, 0.0f))))
	{
		// ���f����`��
		MV1DrawModel(modelHandle);


		// �����Ă��Ȃ��J�E���g����0��
		if (notViewCount != 0) notViewCount = 0;
	}
	// �X�N���[�����W�O�ɂ�����
	else
	{
		// �����Ă��Ȃ��J�E���g��6�ȉ���������
		if (++notViewCount <= 6)
		{
			// ���f����`��
			MV1DrawModel(modelHandle);
		}
	}
}



/// --------------------------------------------------------------------------------
void BasicObject::OptionActorDraw()
{
	// ��]���ĕ`�悳����
	if (++optionRotaCount > 360) optionRotaCount = 0;
	if (optionModelDrawCount++ > 10) MV1DrawModel(modelHandle);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, optionRotaCount * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, VGet(150.0f, -110.0f, -370.0f));
}



/// --------------------------------------------------------------------------------
void BasicObject::OptionActorDrawBefore()
{
	SetupCamera_Perspective(60.0f * DX_PI_F / 180.0f);
	SetCameraNearFar(100.0f, 10000.0f);	// �J�����̕`��͈͂��w��
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -650.0f), VGet(0.0f, 0.0f, 0.0f));
	optionModelDrawCount = 0;
}



/// --------------------------------------------------------------------------------
void BasicObject::Move6SetDownArea()
{
	// ��������{�X�̂Ƃ��܂ŐL�΂��Ă�������܂����B���Ă��Ȃ�������
	if (move6_line <= 200.0f)
	{
		// �����ۂ��~�̔��a��傫������
		if (move6_circle <= 100.0f) move6_circle++;
		DrawCone3D(VGet(area.x, 50.0, area.z), VGet(area.x, 0, area.z), move6_circle, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);


		// ��������{�X�̂Ƃ��܂Ő�������
		DrawLine3D(VGet(area.x, 50.0, area.z), VGet(area.x + ((4000.0f - area.x) * (move6_line / 200.0f)), 50.0f, 0.0f), GetColor(0, 0, 0));
	}
	// �{�X�̂Ƃ��܂Ő������B���Ă�����
	else if (move6_line <= 400.0f)
	{
		// �����ۂ��~�̔��a�����������Ă���
		if (move6_circle >= 0.0f) move6_circle--;
		DrawCone3D(VGet(area.x, 50.0, area.z), VGet(area.x, 0, area.z), move6_circle, 16, GetColor(0, 0, 0), GetColor(0, 0, 0), true);


		// ��������{�X�̂Ƃ��܂Ő�������
		DrawLine3D(VGet(area.x, 50.0, area.z), VGet(4000.0f, 50.0f, 0.0f), GetColor(0, 0, 0));
	}
	move6_line++;


	// ���܂���
	area.y -= 2.0f;
	MV1SetPosition(modelHandle, this->area);
} /// void BasicObject::Move6SetDownArea()
