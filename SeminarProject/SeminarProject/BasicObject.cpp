#include "BasicObject.hpp"
#include <typeinfo.h>



/// --------------------------------------------------------------------------------
bool BasicObject::ShadowFoot(int shadowModel)
{
	// �v���C���[�̒����ɑ��݂���n�ʂ̃|���S�����擾
	shadowHitResDim = MV1CollCheck_Capsule(shadowModel, -1, area, VAdd(area, VGet(0.0f, -shadowHeight, 0.0f)), shadowSize);


	// ���_�f�[�^�ŕω��������������Z�b�g
	shadowVertex[0].dif = GetColorU8(255, 255, 255, 255);
	shadowVertex[0].spc = GetColorU8(0, 0, 0, 0);
	shadowVertex[0].su = 0.0f;
	shadowVertex[0].sv = 0.0f;
	shadowVertex[1] = shadowVertex[0];
	shadowVertex[2] = shadowVertex[0];


	// ���̒����ɑ��݂���|���S���̐������J��Ԃ�
	shadowHitRes = shadowHitResDim.Dim;
	if (shadowHitResDim.HitNum == 0) return false;


	SetUseLighting(FALSE);	// ���C�e�B���O�𖳌��ɂ���
	SetUseZBuffer3D(TRUE);	// �y�o�b�t�@��L���ɂ���


	// �e�N�X�`���A�h���X���[�h�� CLAMP �ɂ���
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);
	for (int i = 0; i != shadowHitResDim.HitNum; ++i, ++shadowHitRes)
	{
		// �|���S���̍��W�͒n�ʃ|���S���̍��W
		shadowVertex[0].pos = shadowHitRes->Position[0];
		shadowVertex[1].pos = shadowHitRes->Position[1];
		shadowVertex[2].pos = shadowHitRes->Position[2];


		// ������Ǝ����グ�ďd�Ȃ�Ȃ��悤�ɂ���
		shadowSlideVec = VScale(shadowHitRes->Normal, 0.5f);
		shadowVertex[0].pos = VAdd(shadowVertex[0].pos, shadowSlideVec);
		shadowVertex[1].pos = VAdd(shadowVertex[1].pos, shadowSlideVec);
		shadowVertex[2].pos = VAdd(shadowVertex[2].pos, shadowSlideVec);


		// �|���S���̕s�����x��ݒ肷��
		shadowVertex[0].dif.a = 0;
		shadowVertex[1].dif.a = 0;
		shadowVertex[2].dif.a = 0;
		if (shadowHitRes->Position[0].y > area.y - shadowHeight)
		{
			shadowVertex[0].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[0].y - area.y) / shadowHeight));
		}

		if (shadowHitRes->Position[1].y > area.y - shadowHeight)
		{
			shadowVertex[1].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[1].y - area.y) / shadowHeight));
		}

		if (shadowHitRes->Position[2].y > area.y - shadowHeight)
		{
			shadowVertex[2].dif.a = (BYTE)(128 * (1.0f - fabs(shadowHitRes->Position[2].y - area.y) / shadowHeight));
		}


		// �t�u�l�͒n�ʃ|���S���ƃv���C���[�̑��΍��W���犄��o��
		shadowVertex[0].u = (shadowHitRes->Position[0].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[0].v = (shadowHitRes->Position[0].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[1].u = (shadowHitRes->Position[1].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[1].v = (shadowHitRes->Position[1].z - area.z) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[2].u = (shadowHitRes->Position[2].x - area.x) / (shadowSize * 2.0f) + 0.5f;
		shadowVertex[2].v = (shadowHitRes->Position[2].z - area.z) / (shadowSize * 2.0f) + 0.5f;


		// �e�|���S����`��
		DrawPolygon3D(shadowVertex, 1, shadowHandle, TRUE);
	} /// for (int i = 0; i != ShadowHitResDim.HitNum; ++i, ++ShadowHitRes)


	// ���o�����n�ʃ|���S�����̌�n��
	MV1CollResultPolyDimTerminate(shadowHitResDim);


	SetUseLighting(TRUE);	// ���C�e�B���O��L���ɂ���
	SetUseZBuffer3D(FALSE);	// �y�o�b�t�@�𖳌��ɂ���
	return true;
} /// bool BasicObject::ShadowFoot(int shadowModel)



/// --------------------------------------------------------------------------------
BasicObject::BasicObject()
{
	// ��񏉊���
	modelHandle = -1;
	modelHeight = 0.0f;
	modelWidth = 0.0f;
	notViewCount = 0;
	shadowHeight = 0.0f;
	shadowSize = 0.0f;
	area = VGet(0.0f, 0.0f, 0.0f);
	shadowHitRes = nullptr;
	ZeroMemory(shadowVertex, sizeof(shadowVertex));
	shadowSlideVec = VGet(0.0f, 0.0f, 0.0f);
	shadowHandle = -1;
	move6_circle = 0.0f;
	move6_line = 0.0f;
}



/// --------------------------------------------------------------------------------
BasicObject::BasicObject(bool shadowDo)
{
	// �e�̓ǂݍ���
	shadowHandle = -1;
	if (shadowDo)
	{
		LoadFile::MyLoad("media\\Shadow.tyn", shadowHandle, ELOADFILE::graph);
	}


	// ��񏉊���
	modelHandle = -1;
	modelHeight = 0.0f;
	modelWidth = 0.0f;
	notViewCount = 0;
	shadowHeight = 0.0f;
	shadowSize = 0.0f;
	area = VGet(0, 0, 0);
	shadowHitRes = nullptr;
	ZeroMemory(shadowVertex, sizeof(shadowVertex));
	shadowSlideVec = VGet(0.0f, 0.0f, 0.0f);
	move6_circle = 0.0f;
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
