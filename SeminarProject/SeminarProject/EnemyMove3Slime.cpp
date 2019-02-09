#include "EnemyMove3Slime.hpp"



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::MotionProcess()
{
	// �v���C���[�Ƃ̋������U���͈͂�������
	if (playerCharaDistance <= 250)
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::attack);
		attackFrame += animSpeed;


		// �U�����[�V��������������
		if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attack))
		{
			attackDamageNow = true;
			attackFrame = 0.0f;
		}
		else
		{
			attackDamageNow = false;
		}
	}
	// �v���C���[�Ƃ̋������U���͈͊O��������
	else
	{
		if (attackDamageNow) attackDamageNow = false;
		Player_PlayAnim(MOTION::idle);
	}
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::AutoMoveProcess()
{
	// ����������������
	if (direXAngle == 0.0f)
	{
		// �ړ����x���ő�l��菬����������
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
		// �ړ����x���ő�l��菬����������
		if (walkSpeed < 3.0f)
		{
			walkSpeed += 1.0f;
		}
		else
		{
			walkSpeed = 3.0f;
		}
	}


	// �ړ������J�E���g��400�ȏゾ������
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	// �ړ������J�E���g��100��������
	else if (moveCount == 100)
	{
		// �����_�����l�擾
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-200, 200);			// X���W�p����
		std::uniform_int_distribution<> moveTurn(-200, 200);		// Z���W�p����


		// �ړ�����X�V����
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
		
	}


	// �ړ�������ƈقȂ��Ă�����
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


	// �ړ�������
	moveCount++;		// �ړ��J�E���g�����Z
	float tempX = area.x + sinf(direXAngle + direZAngle) * -walkSpeed;
	float tempZ = area.z + cosf(direXAngle + direZAngle) * -walkSpeed;


	// �ǂ����悤���Ȃ��Ȃ����珉���l�ɖ߂�
	if (area.y < -10)
	{
		area = VGet(0, 0, 0);
		moveCount = 100;
		return;
	}


	// �X�e�[�W�O�ɍs������
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randInX(-4000, 4000);        // X���W�p����
		std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z���W�p����
		// X���W�ݒ�
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 200.0f && tempX >= 0.0f)
		{
			tempX += 200.0f;
		}
		if (tempX >= -200.0f && tempX <= 0.0f)
		{
			tempX -= 200.0f;
		}
		// Y���W�ݒ�
		float tempZ = static_cast<float>(randInZ(mt));
		if (tempZ <= 200.0f && tempZ >= 0.0f)
		{
			tempZ += 200.0f;
		}
		if (tempZ >= -200.0f && tempZ <= 0.0f)
		{
			tempZ -= 200.0f;
		}
		area = VGet(tempX, 0, tempZ);
		moveCount = 100;
		return;
	}
	area.x += sinf(direXAngle + direZAngle) * -walkSpeed;
	area.z += cosf(direXAngle + direZAngle) * -walkSpeed;
} /// void EnemyMove3Slime::AutoMoveProcess()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::ChaseMoveProcess()
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



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::DamageProcess()
{
	// ����ł��Ȃ����_���[�W���󂯂���
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -3.0f;


		// ���ʂ��炢�_���[�W���󂯂���
		if (++damageCount >= 3)
		{
			deathFlag = true;
		}
	}
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::FallProcess()
{
	// �����ɉ����Ȃ�������
	if (fallCount > 1)
	{
		// �����Ă��Ȃ�������
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
} /// void EnemyMove3Slime::FallProcess()



/// --------------------------------------------------------------------------------------
EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle
	, const int stairsHandle, const int stairsRoadHandle, const int tex0
	, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// �����蔻��p�X�e�[�W�̃R���W�������̐ݒ�
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(stageHandle, -1);
	MV1SetFrameVisible(stageHandle, -1, false);
	MV1RefreshCollInfo(stageHandle, -1);


	// ���e�p�X�e�[�W�̃R���W�������̐ݒ�
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));
	MV1SetupCollInfo(shadowStageHandle, -1);
	MV1SetFrameVisible(shadowStageHandle, -1, false);
	MV1RefreshCollInfo(shadowStageHandle, -1);


	// 3D���f���̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// �e�N�X�`���̓K��
	blendCount = 255;
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);


	// 3D���f���̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 50.0f;
	modelWidth = 140.0f;


	// ���f���̌����ƈʒu
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireXAngle = 0.0f;
	nextDireZAngle = 0.0f;
	playerCharaArea = VGet(0, 0, 0);
	playerCharaDistance = 0;
	moveCount = 0;
	

	// �����̉e�Ɋւ���
	shadowHeight = 1.0f;
	shadowSize = 140.0f;


	// ���ꂼ��̑��x
	walkSpeed = 6.0f;
	animSpeed = 0.45f;
	jumpUpNow = false;


	// �U��
	attackFrame = 0.0f;
	attackDamageNow = false;
	damageCount = 0;


	// �K�i
	v_stairsHandle.clear();
	if (BASICPARAM::stairsNum != 0)
	{
		v_stairsHandle.resize(BASICPARAM::stairsNum);


		// �K�i�̃R���W��������ݒ�
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			v_stairsHandle[i] = MV1DuplicateModel(stairsHandle);
			MV1SetRotationXYZ(v_stairsHandle[i], VGet(0.0f, BASICPARAM::v_stairsAngle[i], 0.0f));
			MV1SetPosition(v_stairsHandle[i], BASICPARAM::v_stairsArea[i]);
			MV1SetupCollInfo(v_stairsHandle[i], -1);
			MV1SetFrameVisible(v_stairsHandle[i], -1, false);
			MV1RefreshCollInfo(v_stairsHandle[i], -1);
		}
	}


	// �K�i�Ə�
	v_stairsRoadHandle.clear();
	if (BASICPARAM::stairsRoadNum != 0)
	{
		v_stairsRoadHandle.resize(BASICPARAM::stairsRoadNum);


		// �K�i�Ə��̃R���W��������ݒ�
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			v_stairsRoadHandle[i] = MV1DuplicateModel(stairsRoadHandle);
			MV1SetRotationXYZ(v_stairsRoadHandle[i], VGet(0.0f, BASICPARAM::v_stairsRoadAngle[i], 0.0f));
			MV1SetPosition(v_stairsRoadHandle[i], BASICPARAM::v_stairsRoadArea[i]);
			MV1SetupCollInfo(v_stairsRoadHandle[i], -1);
			MV1SetFrameVisible(v_stairsRoadHandle[i], -1, false);
			MV1RefreshCollInfo(v_stairsRoadHandle[i], -1);
		}
	}


	// ���f���̍��W���X�V
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, rotationY, 0.0f));
	MV1SetPosition(this->modelHandle, this->area);


	// �R���W�������̃Z�b�g�A�b�v
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove3Slime::EnemyMove3Slime(const int modelHandle, const int collStageHandle



/// --------------------------------------------------------------------------------------
EnemyMove3Slime::~EnemyMove3Slime()
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


	// ���f���̉��
	MODEL_RELEASE(modelHandle);


	// ���e�p�X�e�[�W�̉��
	MODEL_RELEASE(shadowStageHandle);


	// �����蔻��p�X�e�[�W�̉��
	MODEL_RELEASE(stageHandle);
} /// EnemyMove3Slime::~EnemyMove3Slime()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::Draw()
{
	// ����ł��邩���݂�������Ă��Ȃ�������
	if (deathFlag || eraseExistence) return;


	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if (MyDebug::enemyThreeSlimeDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
	if (MyDebug::enemyThreeSlimeSearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
			if (playerCharaDistance <= 250)
			{
				DrawLine3D(playerCharaArea, area, GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::Process()
{
	if (eraseExistence) return;


	// ���񂾂Ƃ�
	if (deathFlag)
	{	
		// ���ߒl��0�ȏゾ������
		if (blendCount >= 0)
		{
			blendCount -= 5;
		}
		// ����������
		else
		{
			eraseExistence = true;
		}


		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		return;
	}


	// ��ʊO�������珈�������Ȃ�
	if (notViewCount > 3) return;


	// ���O�̍��W
	preArea = area;


	// �v���C���[�̍��G�͈͊O��������
	if (playerCharaDistance > 1500)
	{
		AutoMoveProcess();
	}
	// �v���C���[�̍��G�͈͓���������
	else
	{
		ChaseMoveProcess();
	}

	MotionProcess();	// ���[�V�����v���Z�X


	Player_AnimProcess();		// ���[�V�����̎���

	
	DamageProcess();		// �_���[�W�̃v���Z�X


	int setCollHitNum = 0;		// �����蔻������擾


	// �K�i�Ə��̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// �ǂ��ɂ��Ԃ����Ă��Ȃ�������
	if (setCollHitNum == 0)
	{
		// �K�i�̂����蔻��
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	ActorHit(stageHandle);	// �X�e�[�W�̂����蔻��


	FallProcess();	// �����̃v���Z�X


	// �w��ʒu�Ƀ��f����z�u
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove3Slime::Process()



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\D\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\P\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}



/// --------------------------------------------------------------------------------------
std::thread EnemyMove3Slime::ThsTextureReload()
{
	return std::thread(&EnemyMove3Slime::TextureReload, this);
}



/// --------------------------------------------------------------------------------------
void EnemyMove3Slime::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	// ��ʊO�ɂ����珈�������Ȃ�
	if (notViewCount > 3) return;


	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
