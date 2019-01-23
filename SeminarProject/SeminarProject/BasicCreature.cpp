#include "BasicCreature.hpp"



/// -------------------------------------------------------------------------
void BasicCreature::Player_PlayAnim(int attach)
{
	// ���̃��[�V�������Ⴄ���̂�������
	if (attachNum != attach)
	{
		// ���O�̃��[�V�������L����������f�^�b�`����
		if (preAttach != -1 && motionBlendTime < 1.0f)
		{
			MV1DetachAnim(modelHandle, preAttach);
			preAttach = -1;
		}


		// ���̃��[�V�������ߋ��Ƃ���
		preAttach = attachMotion;
		preMotionPlayTime = nowPlayTime;


		// �V�������[�V�������A�^�b�`����
		attachNum = attach;
		attachMotion = MV1AttachAnim(modelHandle, attachNum, -1, false);
		nowPlayTime = 0.0f;


		// �Đ����̃��[�V�������P�O�O���̏�� �ɂ���
		if (preMotionPlayTime == -1)
		{
			motionBlendTime = 1.0f;
		}
		else
		{
			motionBlendTime = 0.0f;
		}
	} /// if (attachNum != attach)
} /// void BasicCreature::Player_PlayAnim(int attach)



/// -------------------------------------------------------------------------
void BasicCreature::Player_AnimProcess()
{
	// �u�����h�����P�ȉ��̏ꍇ�͂P�ɋ߂Â���
	if (motionBlendTime < 1.0)
	{
		motionBlendTime += 0.075f;
		if (motionBlendTime >= 1.0f)
		{
			motionBlendTime = 1.0f;
		}
	}


	// �Đ����Ă��錻�݂̃��[�V�����̏���
	if (attachMotion != -1)
	{
		// ���[�V�����̑����Ԃ��擾
		totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachMotion);


		// �Đ����Ԃ�i�߂�
		nowPlayTime += animSpeed;


		// �Đ����Ԃ������Ԃɓ��B���Ă����烋�[�v������
		if (nowPlayTime >= totalTime)
		{
			nowPlayTime = fmodf(nowPlayTime, totalTime);
		}


		// �ύX�����Đ����Ԃ����f���ɔ��f������
		MV1SetAttachAnimTime(modelHandle, attachMotion, nowPlayTime);


		// �A�j���[�V�����P�̃��f���ɑ΂��锽�f�����Z�b�g
		MV1SetAttachAnimBlendRate(modelHandle, attachMotion, motionBlendTime);
	}


	// �Đ����Ă��钼�O�̃��[�V�����̏���
	if (preAttach != -1)
	{
		// �A�j���[�V�����̑����Ԃ��擾
		totalTime = MV1GetAttachAnimTotalTime(modelHandle, preAttach);


		// �Đ����Ԃ�i�߂�
		preMotionPlayTime += animSpeed;


		// �Đ����Ԃ������Ԃɓ��B���Ă�����Đ����Ԃ����[�v������
		if (preMotionPlayTime > totalTime)
		{
			preMotionPlayTime = fmodf(preMotionPlayTime, totalTime);
		}


		// �ύX�����Đ����Ԃ����f���ɔ��f������
		MV1SetAttachAnimTime(modelHandle, preAttach, preMotionPlayTime);


		// �A�j���[�V�����Q�̃��f���ɑ΂��锽�f�����Z�b�g
		MV1SetAttachAnimBlendRate(modelHandle, preAttach, (1.0f - motionBlendTime));
	}
} /// void BasicCreature::Player_AnimProcess()



/// -------------------------------------------------------------------------
bool BasicCreature::ActorHit(int stageHandle)
{
	// �v���C���[���J�v�Z���Ƃ��ăX�e�[�W�Ƃ̃R���W�������𒲂ׂ�(OBB�`��)
	m_hitDim = MV1CollCheck_Capsule(stageHandle, -1, area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth);


	// �|���S���̐����ď�����
	wallNum = 0;
	floorNum = 0;

	hitDimNum += m_hitDim.HitNum;


	// ���o���ꂽ���������ׂ�
	for (int i = 0, n = m_hitDim.HitNum; i != n; ++i)
	{
		// �ǂ��ǂ������f���邽�߁AXZ���ɐ������ǂ�����@�����O�ɋ߂����ǂ����Œ��ׂ�
		if (m_hitDim.Dim[i].Normal.y < 0.001f && m_hitDim.Dim[i].Normal.y > -0.001f)
		{
			// �ǂ��Ƃ��Ă��L�����N�^�[�̑���菭����𒲂ׂ�
			if (m_hitDim.Dim[i].Position[0].y > area.y + 5.0f
				|| m_hitDim.Dim[i].Position[1].y > area.y + 5.0f
				|| m_hitDim.Dim[i].Position[2].y > area.y + 5.0f)
			{
				// �ő�ɂȂ�܂ŕۑ�����
				if (wallNum < 64)
				{
					// �q�b�g�����|���S������ۑ�
					wallPoly[wallNum] = &m_hitDim.Dim[i];
					wallNum++;
				}
			}
		}
		else
		{
			// �ő�ɂȂ�܂ŕۑ�
			if (floorNum < 64)
			{
				// �q�b�g�����|���S������ۑ�
				floorPoly[floorNum] = &m_hitDim.Dim[i];
				floorNum++;
			}
		}
	}


	// �ǂ��ɂ��������Ă��Ȃ�������
	if (floorNum == 0 && wallNum == 0)
	{
		// ���o���������������
		MV1CollResultPolyDimTerminate(m_hitDim);

		return false;
	}


	// ������
	if (floorNum != 0)
	{
		fallCount++;			// �����Ă���Ƃ���


		// ������������
		if (!jumpUpNow)
		{
			hitFlag = false;		// �������ĂȂ��Ƃ���

			maxYHit = 0.0f;			// ����������


			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// �����ׂ�|���S������n��


				// ���ł�����
				if (jumpNow)
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, -5.0f, 0.0f))
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}
				// ���ł��Ȃ�������
				else
				{
					lineResult = HitCheck_Line_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, -20.0f, 0.0f))
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);
				}


				// �������ĂȂ������牽�����Ȃ�
				if (lineResult.HitFlag == 0) continue;


				// ���ɓ��������|���S���������č��܂Ō��o�������̂��Ⴉ�����牽�����Ȃ�
				if (hitFlag && maxYHit > lineResult.Position.y) continue;


				// �ڐG����Y���W��ێ�����
				maxYHit = lineResult.Position.y;
				hitFlag = true;
			} /// for (int i = 0; i != floorNum; ++i)


			// ���ɓ����������ǂ����ŏ���
			if (hitFlag)
			{
				// ���ݒn�Ƃ��ė����̏�������߂�
				area.y = maxYHit;
				fallCount = 0;
				jumpNow = false;
			}
		} /// if (!jumpUpNow)
		// �㏸����������
		else
		{
			minYHit = 0.0f;

			hitFlag = false;

			for (int i = 0; i != floorNum; ++i)
			{
				mainPoly = floorPoly[i];			// �����ׂ�|���S������n��
				lineResult = HitCheck_Line_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]);


				// �������ĂȂ������牽�����Ȃ�
				if (lineResult.HitFlag == 0) continue;


				// ���ɓ��������|���S���������č��܂Ō��o�������̂��Ⴉ�����牽�����Ȃ�
				if (hitFlag && minYHit < lineResult.Position.y) continue;


				// �ڐG����Y���W��ێ�����
				minYHit = lineResult.Position.y;
				hitFlag = true;
			}


			// ���ɓ����������ǂ����ŏ���
			if (hitFlag)
			{
				area.y = minYHit - modelHeight;

				jumpPower = 0.0f;

				jumpUpNow = false;
			}
		} /// else(!if (!jumpUpNow))
	} /// if (floorNum != 0)


	// �ǔ���
	if (wallNum != 0)
	{
		hitFlag = false;	// �ǂɂ͓������ĂȂ��Ƃ���


		// �ړ����Ă���Ƃ�
		if (moveFlag)
		{
			for (int i = 0; i != wallNum; ++i)
			{
				int j;						// ��������邽�߃��[�v�O�Ő錾


				mainPoly = wallPoly[i];		// ���̒��ׂ�|���S������n��


				// �������Ă��邩�ǂ����𒲂ׂ�
				if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
					, modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == 0)
				{
					continue;					// �������Ă��Ȃ��̂Ŏ��I
				}


				hitFlag = true;				// �������Ă���Ƃ���


				// �ړ����Ă���̂Ŏ��̍��W�œ������Ă��Ȃ�������
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];		// ���̒��ׂ�|���S������n��

					// �������Ă��邩�ǂ����𒲂ׂ�
					if (HitCheck_Capsule_Triangle(VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, VAdd(area, VGet(0.0f, modelHeight, 0.0f))
						, modelWidth, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
					{
						jumpUpNow = false;
						break;						// �������Ă����̂Ŕ�����
					}
				}


				// �ړ���œ�����Ȃ������̂Ŕ��������
				if (j == wallNum)
				{
					hitFlag = false;
					break;
				}
			}
		} /// if (moveFlag)
		// �ړ����Ă��Ȃ��Ƃ�
		else
		{
			for (int i = 0; i != wallNum; ++i)
			{
				mainPoly = wallPoly[i];			// ���̒��ׂ�|���S������n��


				// �������Ă��邩�ǂ����𒲂ׂ�
				if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
					, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
				{
					hitFlag = true;
					break;							// �������Ă����̂Ŕ�����
				}
			}
		}


		// �������Ă����̂ŉ����o��
		if (hitFlag)
		{
			int j, k;


			// ���萔�������ׂ�
			for (int i = 0; i != 64; ++i)
			{
				// �ǃ|���S���̐������J��Ԃ�
				for (j = 0; j != wallNum; ++j)
				{
					mainPoly = wallPoly[j];


					// �������Ă��邩�ǂ����𒲂ׂ�
					if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
						, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) == 0)
					{
						continue;
					}


					VECTOR slideVec = VCross(VSub(area, preArea), mainPoly->Normal);
					slideVec = VCross(mainPoly->Normal, slideVec);
					area = VAdd(preArea, slideVec);


					for (k = 0; k != wallNum; ++k)
					{
						// �������Ă����烋�[�v�𔲂���
						mainPoly = wallPoly[k];


						if (HitCheck_Capsule_Triangle(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth
							, mainPoly->Position[0], mainPoly->Position[1], mainPoly->Position[2]) != 0)
						{
							break;
						}
					}

					// �S�Ẵ|���S���Ɠ������Ă��Ȃ������̂Ŕ�����
					if (k == wallNum) break;
				} /// for (j = 0; j != wallNum; ++j)


				// ����𒲂ׂ�O�ɑS�Ẵ|���S���Ɠ������Ă��Ȃ������̂Ŕ�����
				if (j != wallNum) break;
			} /// for (int i = 0; i != 64; ++i)
		} /// if (hitFlag)
	} /// if (wallNum != 0)


	// ���o���������������
	MV1CollResultPolyDimTerminate(m_hitDim);
	return true;
} /// bool BasicCreature::ActorHit(int stageHandle)



/// -------------------------------------------------------------------------
BasicCreature::BasicCreature() :BasicObject()
{
	// �����蔻��Ɋւ���
	wallNum = 0;
	floorNum = 0;
	hitFlag = false;
	maxYHit = 0.0f;
	minYHit = 0.0f;
	moveFlag = false;


	// ���[�V�����֘A
	nowPlayTime = 0.0f;
	motionBlendTime = 0.0f;
	preAttach = -1;
	preMotionPlayTime = 0.0f;


	// ������
	fallCount = 0;
	angle = 0.0f;
	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
} /// BasicCreature::BasicCreature() :BasicObject()



/// -------------------------------------------------------------------------
BasicCreature::BasicCreature(bool shadowDo) :BasicObject(shadowDo)
{
	// �����蔻��Ɋւ���
	wallNum = 0;
	floorNum = 0;
	hitFlag = false;
	maxYHit = 0.0f;
	minYHit = 0.0f;
	moveFlag = false;


	// ���[�V�����֘A
	nowPlayTime = 0.0f;
	motionBlendTime = 0.0f;
	preAttach = -1;
	preMotionPlayTime = 0.0f;


	// ������
	fallCount = 0;
	angle = 0.0f;
	damageHit = false;
	deathFlag = false;
	eraseExistence = false;
	blendCount = 255;
	jumpNow = false;
	attachMotion = 0;
	walkSpeed = 0;
	mainPoly = nullptr;
	nextArea = VGet(0, 0, 0);
	modelWidth = 0;
	ZeroMemory(floorPoly, sizeof(floorPoly));
} /// BasicCreature::BasicCreature(bool shadowDo) :BasicObject(shadowDo)



/// -------------------------------------------------------------------------
BasicCreature::~BasicCreature()
{
}



/// -------------------------------------------------------------------------
bool BasicCreature::HitCircleReturn(VECTOR hitOneArea, float width)
{
	VECTOR subVec;
	float length;
	VECTOR pushVec;


	subVec = VSub(area, hitOneArea);				// �x�N�g�������Z�o
	subVec.y = 0.0f;								// �x���͌��Ȃ�
	length = VSize(subVec);							// ��l�̋������Z�o
	pushVec = VScale(subVec, 1.0f / length);		// �x�N�g�����𐳋K��


	// ��l�̋���������̕���菬���������牟���o������������
	if (length - width < 0)
	{
		float tempY = 0.0f;
		tempY = area.y;
		area = VAdd(hitOneArea, VScale(pushVec, width));
		area.y = tempY;
		return true;
	}
	else
	{
		return false;
	}
} /// void BasicCreature::HitCircleReturn(VECTOR hitOneArea, float width)



/// -------------------------------------------------------------------------
void BasicCreature::HitLineReturn(VECTOR hitOneArea, VECTOR hitTwoArea)
{
	// �R���W���������X�V���ē������Ă��邩���ׂ�
	MV1_COLL_RESULT_POLY HitPoly;
	MV1RefreshCollInfo(modelHandle, -1);
	HitPoly = MV1CollCheck_Line(modelHandle, -1, hitOneArea, hitTwoArea);
	

	// �������Ă����ꍇ
	if (HitPoly.HitFlag == 1 && !damageHit)
	{
		damageHit = true;
	}
}
