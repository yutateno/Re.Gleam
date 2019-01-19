#include "OrdinaryPerson.hpp"


// �����̃v���Z�X
void OrdinaryPerson::MoveProcess()
{
	animSpeed = 0.75f;			// ���[�V�����̑��x�����߂�

	
	// �ړ������i������������
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
	// �ړ����΂ߕ�����������
	else
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


	// �ړ��J�E���g��400�ȏゾ�����烊�Z�b�g����
	if (moveCount >= 400)
	{
		moveCount = 0;
	}
	//�ړ��J�E���g��100��������ړ�������߂�
	else if (moveCount == 100)
	{
		// �����_�����l�擾
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
		std::uniform_int_distribution<> randInX(-200, 200);			// X���W�p����
		std::uniform_int_distribution<> moveTurn(-200, 200);		// Z���W�p����


		// �ړ�����X�V
		nextDireZAngle = moveTurn(mt) / 100.0f;
		nextDireXAngle = randInX(mt) / 100.0f;
	}


	// �ړ���̌����ƈ������
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


	// �ړ���̌����ƈ������
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
	Player_PlayAnim(MOTION::walk);
	moveCount++;		// �ړ��J�E���g�����Z
	float tempX = area.x + sinf(direXAngle + direZAngle) * -walkSpeed;
	float tempZ = area.z + cosf(direXAngle + direZAngle) * -walkSpeed;
	// �X�e�[�W�O�Ɍ������Ă����痐�����ĈÎZ
	if (tempX >= 5000.0f || tempX <= -5000.0f || tempZ >= 5000.0f || tempZ <= -5000.0f)
	{
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
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
} /// void OrdinaryPerson::MoveProcess()


// ��������
void OrdinaryPerson::FallProcess()
{
	// �����ɉ����Ȃ�������
	if (fallCount > 1)
	{
		// ����������Ȃ�������
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


	// �덷�ŋ󒆕��V���肾������
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// ���ł��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}
} /// void OrdinaryPerson::FallProcess()


// �R���X�g���N�^
OrdinaryPerson::OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
	, const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)
{
	// �����蔻��p�̃X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.75f, 0.75f, 0.75f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(stageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(stageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(stageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j


	// ���e����p�̃X�e�[�W�̃R���W�������̍X�V
	shadowStageHandle = -1;
	shadowStageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(shadowStageHandle, VGet(0.8f, 0.8f, 0.8f));
	MV1SetPosition(shadowStageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(shadowStageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(shadowStageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(shadowStageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j


	// �R�c���f���̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	// �e�N�X�`���̓K��
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);


	// �R�c���f����0�Ԗڂ̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::walk;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 160.0f;
	modelWidth = 50.0f;
	alive = false;
	aliveBlendCount = 0;


	// ���f���̌����ƈʒu
	this->area = area;
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	nextDireZAngle = 0.0f;
	nextDireXAngle = 0.0f;


	// �����̉e�Ɋւ���
	shadowHeight = 20.0f;
	shadowSize = 50.0f;


	// ���ꂼ��̑��x
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	moveCount = 0;
	jumpUpNow = false;


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


	// �������̉�]�p�x���Z�b�g
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, rotationY, 0.0f));
	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, this->area);
} /// OrdinaryPerson::OrdinaryPerson(const int modelHandle, const int collStageHandle, const int stairsHandle
/// , const int stairsRoadHandle, const int tex0, const VECTOR area, const float rotationY) : BasicCreature(true)



// �f�X�g���N�^
OrdinaryPerson::~OrdinaryPerson()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle0);


	// �K�i�Ə����
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = v_stairsRoadHandle.size(); i != n; ++i)
		{
			MODEL_RELEASE(v_stairsRoadHandle[i]);
		}
		v_stairsRoadHandle.clear();
		v_stairsRoadHandle.shrink_to_fit();
	}


	// �K�i�J��
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


	// �e�p�X�e�[�W�n���h���J��
	MODEL_RELEASE(shadowStageHandle);


	// �����蔻��p�X�e�[�W�n���h���J��
	MODEL_RELEASE(stageHandle);
} /// OrdinaryPerson::~OrdinaryPerson()


// ���C���v���Z�X
void OrdinaryPerson::Process()
{
	// �����������ĂȂ��Ƃ�
	if (!alive) return;


	preArea = area;		// ���O�̍��W


	// �����̃v���Z�X
	MoveProcess();


	// ���[�V�����̎���
	Player_AnimProcess();


	int setCollHitNum = 0;		// �����蔻��̌���������


	// �K�i�Ə��̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
	}


	// �ǂ��ɂ��������Ă��Ȃ�������
	if (setCollHitNum == 0)
	{
		// �K�i�̂����蔻��
		for (int i = 0; i != BASICPARAM::stairsNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsHandle[i]);
		}
	}


	// �X�e�[�W�̂����蔻��
	ActorHit(stageHandle);

	
	// �����̃v���Z�X
	FallProcess();


	// �������̉�]�p�x���Z�b�g
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, direXAngle + direZAngle, 0.0f));
	// �w��ʒu�Ƀ��f����z�u
	MV1SetPosition(modelHandle, area);
} /// void OrdinaryPerson::Process()


// ��ʐl�̃e�N�X�`�������ւ�
void OrdinaryPerson::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\normal\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\D\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\P\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\normal\\human_col.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
}


// �����������ꂽ����W�����߂�
void OrdinaryPerson::SetAlive(VECTOR area, bool alive)
{
	this->area = area;
	this->alive = alive;
}


// �`��
void OrdinaryPerson::Draw()
{
	// �����������ĂȂ��Ƃ�
	if (!alive) return;


	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if(MyDebug::ordinaryDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}
