#include "EnemyMove3CrayonHuman.hpp"


// ���[�V�����̃v���Z�X
void EnemyMove3CrayonHuman::MotionProcess()
{
	// ����ł��Ȃ�������
	if (!deathFlag)
	{
		// �v���C���[�Ƃ̋������߂��ăv���C���[�����F���Ă�����
		if (playerCharaDistance <= 200 && charaLookAt)
		{
			// �U���̏���������
			Player_PlayAnim(MOTION::damage);
			attackFrame += animSpeed;


			// ���[�V�����̏I��
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
		// �v���C���[�����F���Ă��Ȃ�������
		else
		{
			if (attackDamageNow) attackDamageNow = false;
			Player_PlayAnim(MOTION::idle);
		}
	}
	// ���񂾂�
	else
	{
		Player_PlayAnim(MOTION::death);
	}
} /// void EnemyMove3CrayonHuman::MotionProcess()


// �����I�ȓ����v���Z�X
void EnemyMove3CrayonHuman::AutoMoveProcess()
{
	// ���O������������
	if (direXAngle == 0.0f)
	{
		// �ړ����x�ő�l���Ⴉ������
		if (walkSpeed < 6.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 6.0f;
		}
	}
	// �΂ߕ�����������
	else
	{
		// �ړ����x�ő�l���Ⴉ������
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	// �����Ă���J�E���g��400�ȏゾ������
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	// �����Ă���J�E���g��100��������
	else if (moveCount == 100)
	{
		// �����l�擾
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
		std::uniform_int_distribution<> randInX(-200, 200);			// X���W�p����
		std::uniform_int_distribution<> moveTurn(-200, 200);				// Z���W�p����


		// ���̈ړ��������
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		/*if (nextDireZAngle != 0.0f)
		{
			nextDireXAngle = -nextDireXAngle;
		}*/
	}


	// ���̈ړ���ƍ��̒l���������
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


	// �ړ������ɓ�����
	moveCount++;		// �ړ��J�E���g�����Z
	float tempX = area.x + sinf(direXAngle + direZAngle) * -walkSpeed;
	float tempZ = area.z + cosf(direXAngle + direZAngle) * -walkSpeed;
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		area.x += sinf(direXAngle + direZAngle) * walkSpeed * 2.0f;
		area.z += cosf(direXAngle + direZAngle) * walkSpeed * 2.0f;
		moveCount = 100;
		return;
	}
	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;
} /// void EnemyMove3CrayonHuman::AutoMoveProcess()


// �v���C���[��ǂ�������v���Z�X
void EnemyMove3CrayonHuman::ChaseMoveProcess()
{
	walkSpeed = 7.0f;		// �ړ����x�𑁂߂ɐݒ�


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
} /// void EnemyMove3CrayonHuman::ChaseMoveProcess()


// ��������
void EnemyMove3CrayonHuman::FallProcess()
{
	// �����ɉ����Ȃ�������
	if (fallCount > 1)
	{
		// �������Ă��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}


	// �������Ă���
	if (jumpNow)
	{
		flyCount++;
		preJumpNow = true;
		walkSpeed = 10.0f;
		animSpeed = 1.0f;
		jumpPower -= gravity;			// �����d�͂�����������
		area.y += jumpPower;			// Y���W�ɉ���������


		area.y -= 10.5f;
	}


	// ���n���Ă�����
	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;
	}

	// �덷�ŋ󒆕��V���Ă�����
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// �������Ă��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}
} /// void EnemyMove3CrayonHuman::FallProcess()


// �R���X�g���N�^
EnemyMove3CrayonHuman::EnemyMove3CrayonHuman(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
	, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// �����蔻��p�X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(stageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(stageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(stageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j


	// ���e�p�X�e�[�W�̃R���W�������̍X�V
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
	jumpUpNow = false;


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


	// �A�N�^�[���m�̂����蔻��̃Z�b�g�A�b�v
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove3CrayonHuman::EnemyMove3CrayonHuman(const int modelHandle, const int collStageHandle, const int stairsHandle, const int stairsRoadHandle
/// , const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)


// �f�X�g���N�^
EnemyMove3CrayonHuman::~EnemyMove3CrayonHuman()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle0);


	// �K�i�Ə��̉��
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}

	
	// �K�i�̉��
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = v_stairsHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsHandle[i]);
		}
		v_stairsHandle.clear();
		v_stairsHandle.shrink_to_fit();
	}


	// ���f���J��
	MODEL_RELEASE(modelHandle);


	// ���e�p�X�e�[�W�n���h���J��
	MODEL_RELEASE(shadowStageHandle);


	// �����蔻��X�e�[�W�n���h���J��
	MODEL_RELEASE(stageHandle);
} /// EnemyMove3CrayonHuman::~EnemyMove3CrayonHuman()


// �`��
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


// �v���Z�X
void EnemyMove3CrayonHuman::Process()
{
	// ���ł��Ă�����
	if (eraseExistence) return;


	// ���񂾂Ƃ�
	if (deathFlag)
	{
		MotionProcess();	// ���[�V�����v���Z�X


		Player_AnimProcess();		// ���[�V�����̎���


		// ���ߒl��0�ȏゾ������
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


	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	// ���O�̍��W
	preArea = area;


	// �v���C���[�Ƃ̋��������G�O��������
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();		// �����I�ɓ�����
	}
	// �v���C���[�Ƃ̋��������G����������
	else
	{
		// �v���C���[�����F�ł��Ă�����
		if (charaLookAt)
		{
			ChaseMoveProcess();		// �v���C���[��ǂ�������
		}
		// �v���C���[�����F�ł��Ă��Ȃ�������
		else
		{
			AutoMoveProcess();		// �����I�ɓ���
		}
	}


	MotionProcess();		// ���[�V�����̃v���Z�X


	Player_AnimProcess();		// ���[�V�����̎���


	// �_���[�W���󂯂Ď���ł��Ȃ��Ƃ�
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -3.0f;

		
		// �_���[�W�̐��l�����ʒl�ɂȂ�����
		if (++damageCount >= 3.0f)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::crayonDie, area);
			deathFlag = true;
		}
	}


	int setCollHitNum = 0;		// �����蔻��̌��𓾂�


	// �K�i�Ə��̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// �ǂ��ɂ��������Ă��Ȃ�������
	if (setCollHitNum == 0)
	{
		// �K�i�̂����蔻�菈��
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	ActorHit(stageHandle);	// �X�e�[�W�̂����蔻��


	FallProcess();	// �����̃v���Z�X


	// �v��Ȃ����Ǖs���Ȃ̂ňꉞ
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}


	// �v���C���[�����F�ł���p�x
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);


	// �v���C���[�����F�o������
	if (fabsf(charaLookAtAngle) + (DX_PI_F / 6) > fabsf(direXAngle + direZAngle)
		&& fabsf(charaLookAtAngle) - (DX_PI_F / 6) < fabsf(direXAngle + direZAngle)
		&& playerCharaDistance <= 1500)
	{
		direXAngle = 0.0f;
		direZAngle = charaLookAtAngle;
		charaLookAt = true;
	}
	// �v���C���[�����F�ł��Ȃ�������
	else
	{
		charaLookAt = false;
	}


	// �v���C���[�����F���Ă�����
	if (charaLookAt)
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle, 0.0f));			// �v���C���[���������ɉ�]������
	}
	// �v���C���[�����F�ł��Ȃ�������
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	}


	// �w��ʒu�Ƀ��f����z�u
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove3CrayonHuman::Process()


// �e�N�X�`���������ւ���
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
}/// void EnemyMove3CrayonHuman::TextureReload()


// �v���C���[�̈ʒu�Ƌ������擾����
void EnemyMove3CrayonHuman::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
