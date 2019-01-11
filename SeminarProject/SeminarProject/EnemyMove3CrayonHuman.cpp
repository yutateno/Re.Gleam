#include "EnemyMove3CrayonHuman.hpp"


void EnemyMove3CrayonHuman::MotionProcess()
{
	if (!deathFlag)
	{
		if (playerCharaDistance <= 200 && charaLookAt)
		{
			Player_PlayAnim(MOTION::damage);
			attackFrame += animSpeed;
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::damage))
			{
				attackDamageNow = true;
				attackFrame = 0.0f;
			}
			else
			{
				attackDamageNow = false;
			}
		}
		else
		{
			if (attackDamageNow) attackDamageNow = false;
			Player_PlayAnim(MOTION::idle);
		}
	}
	else
	{
		Player_PlayAnim(MOTION::death);
	}
}

void EnemyMove3CrayonHuman::AutoMoveProcess()
{
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-200, 200);			// X���W�p����
	std::uniform_int_distribution<> moveTurn(0, 314);				// Z���W�p����

	moveCount++;

	// �X���[�Y�ɓ�������
	if (direXAngle == 0.0f)
	{
		if (walkSpeed < 6.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 6.0f;
		}
	}
	else	// �΂ߕ���
	{
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	else if (moveCount == 100)
	{
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		if (nextDireZAngle != 0.0f)
		{
			nextDireXAngle = -nextDireXAngle;
		}

	}

	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;

	if (nextDireXAngle != direXAngle)
	{
		if (direXAngle > nextDireXAngle)
		{
			direXAngle -= 0.01f;
		}
		else
		{
			direXAngle += 0.01f;
		}
	}
	if (nextDireZAngle != direZAngle)
	{
		if (direZAngle > nextDireZAngle)
		{
			direZAngle -= 0.01f;
		}
		else
		{
			direZAngle += 0.01f;
		}
	}
}

void EnemyMove3CrayonHuman::ChaseMoveProcess()
{
	walkSpeed = 7.0f;
	// �L�����N�^�[�ɋ߂Â�
	if (playerCharaArea.x < area.x - walkSpeed + 2.0f)
	{
		area.x -= walkSpeed;
	}
	else if (playerCharaArea.x > area.x + walkSpeed + 2.0f)
	{
		area.x += walkSpeed;
	}
	if (playerCharaArea.z < area.z - walkSpeed + 2.0f)
	{
		area.z -= walkSpeed;
	}
	else if (playerCharaArea.z > area.z + walkSpeed + 2.0f)
	{
		area.z += walkSpeed;
	}
}


void EnemyMove3CrayonHuman::FallProcess()
{
	// �����ɉ����Ȃ�������
	if (fallCount > 1)
	{
		// ��ԃR�}���h�Ŕ��ł��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}


	// ���ł���
	if (jumpNow)
	{
		flyCount++;
		preJumpNow = true;
		walkSpeed = 10.0f;
		animSpeed = 1.0f;
		jumpPower -= gravity;			// �����d�͂�����������
		area.y += jumpPower;			// Y���W�ɉ���������


		// �W�����v�ɂčŒ��_�ɓ��B������
		if (jumpPower <= flyJumpPower / 2.0f)
		{
			jumpUpNow = false;			// �����ɐ؂�ւ���

			//// �n�ʂɐG�ꂽ��
			//if (fallCount <= 1)
			//{
			//	if (CheckHitKey(KEY_INPUT_G) >= 1)
			//	{
			//		printfDx("asdas\n");
			//	}
			//	jumpPower = 0.0f;
			//	jumpUpNow = false;
			//}
		}


		area.y -= 10.5f;
	}


	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;
	}


	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// ��ԃR�}���h�Ŕ��ł��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}
}


EnemyMove3CrayonHuman::EnemyMove3CrayonHuman(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
	, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// �X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(stageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(stageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(stageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j

	// �X�e�[�W�̃R���W�������̍X�V
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(shadowStageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(shadowStageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j

	// 3D���f���̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);

	// �e�N�X�`���̓K��
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);

	// 3D���f���̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);

	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 130.0f;
	modelWidth = 70.0f;

	// ���f���̌����ƈʒu
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireXAngle = 0.0f;
	nextDireZAngle = 0.0f;
	playerCharaArea = VGet(0, 0, 0);
	playerCharaDistance = 3000;
	moveCount = 0;

	// �����̉e�Ɋւ���
	shadowHeight = 20.0f;
	shadowSize = 70.0f;

	// ���ꂼ��̑��x
	walkSpeed = 6.0f;
	animSpeed = 0.75f;

	// �U��
	attackFrame = 0;
	attackDamageNow = false;
	damageCount = 0;

	// �K�i
	v_stairsHandle.clear();
	if (BASICPARAM::stairsNum != 0)
	{
		v_stairsHandle.resize(BASICPARAM::stairsNum);
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			v_stairsHandle[i] = MV1DuplicateModel(stairsHandle);
			MV1SetRotationXYZ(v_stairsHandle[i], VGet(0.0f, BASICPARAM::v_stairsAngle[i], 0.0f));
			MV1SetPosition(v_stairsHandle[i], BASICPARAM::v_stairsArea[i]);				// �X�e�[�W�̍��W���X�V
			MV1SetupCollInfo(v_stairsHandle[i], -1);						// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
			MV1SetFrameVisible(v_stairsHandle[i], -1, false);				// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
			MV1RefreshCollInfo(v_stairsHandle[i], -1);
		}
	}

	// �K�i�Ə�
	v_stairsRoadHandle.clear();
	if (BASICPARAM::stairsRoadNum != 0)
	{
		v_stairsRoadHandle.resize(BASICPARAM::stairsRoadNum);
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			v_stairsRoadHandle[i] = MV1DuplicateModel(stairsRoadHandle);
			MV1SetRotationXYZ(v_stairsRoadHandle[i], VGet(0.0f, BASICPARAM::v_stairsRoadAngle[i], 0.0f));
			MV1SetPosition(v_stairsRoadHandle[i], BASICPARAM::v_stairsRoadArea[i]);				// �X�e�[�W�̍��W���X�V
			MV1SetupCollInfo(v_stairsRoadHandle[i], -1);						// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
			MV1SetFrameVisible(v_stairsRoadHandle[i], -1, false);				// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
			MV1RefreshCollInfo(v_stairsRoadHandle[i], -1);
		}
	}

	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);

	MV1SetupCollInfo(this->modelHandle, -1);
}

EnemyMove3CrayonHuman::~EnemyMove3CrayonHuman()
{
	GRAPHIC_RELEASE(textureHandle0);

	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}

	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}

	MODEL_RELEASE(modelHandle);
	MODEL_RELEASE(shadowStageHandle);
	MODEL_RELEASE(stageHandle);
}

void EnemyMove3CrayonHuman::Draw()
{
	if (deathFlag || eraseExistence) return;

	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if (MyDebug::enemyThreeCrayonHumanDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}

	if (MyDebug::enemyThreeCrayonHumanSearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
			if (charaLookAt)
			{
				DrawLine3D(playerCharaArea, area, GetColor(0, 255, 0));
			}
			if (playerCharaDistance <= 200)
			{
				DrawLine3D(playerCharaArea, area, GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG
}

void EnemyMove3CrayonHuman::Process()
{
	if (eraseExistence) return;

	// ���񂾂Ƃ�
	if (deathFlag)
	{
		MotionProcess();

		// ���[�V����
		Player_AnimProcess();

		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		else
		{
			eraseExistence = true;
		}

		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);

		return;
	}


	if (notViewCount > 3) return;

	// ���O�̍��W
	preArea = area;

	// �����̃v���Z�X
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();
	}
	else
	{
		if (charaLookAt)
		{
			ChaseMoveProcess();
		}
		else
		{
			AutoMoveProcess();
		}
	}

	MotionProcess();

	// ���[�V����
	Player_AnimProcess();

	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -3.0f;
		if (++damageCount >= 3.0f)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::crayonDie, area);
			deathFlag = true;
		}
	}

	int setCollHitNum = 0;

	// �K�i�Ə��̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}

	// �K�i�̂����蔻��
	if (setCollHitNum == 0)
	{
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}

	// �X�e�[�W�̂����蔻��
	ActorHit(stageHandle);

	// �����̃v���Z�X
	FallProcess();

	// �v��Ȃ����Ǖs���Ȃ̂ňꉞ
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}

	// atan2 ���g�p���Ċp�x���擾
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);

	if (fabsf(charaLookAtAngle) + (DX_PI_F / 6) > fabsf(direXAngle + direZAngle)
		&& fabsf(charaLookAtAngle) - (DX_PI_F / 6) < fabsf(direXAngle + direZAngle)
		&& playerCharaDistance <= 1500)
	{
		direXAngle = 0.0f;
		direZAngle = charaLookAtAngle;
		charaLookAt = true;
	}
	else
	{
		charaLookAt = false;
	}
	
	// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F )��
	// �������l���R�c���f���� Y����]�l�Ƃ��Đݒ�
	//MV1SetRotationXYZ(ModelHandle2, VGet(0.0f, charaLookAngle + DX_PI_F, 0.0f));

	// �������̉�]�p�x���Z�b�g
	if (charaLookAt)
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle, 0.0f));
	}
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	}
	// �w��ʒu�Ƀ��f����z�u
	MV1SetPosition(modelHandle, area);
}

void EnemyMove3CrayonHuman::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\normal\\kre.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\D\\kre.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\P\\kre.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\normal\\kre.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}

void EnemyMove3CrayonHuman::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
