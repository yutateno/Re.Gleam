#include "EnemyMove4.hpp"



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::MotionProcess()
{
	// ����ł��Ȃ�������
	if (!deathFlag)
	{
		// �T�C�Y���傫���Ƃ���������
		if (damageCount <= bigBodyChangeDamage)
		{
			Player_PlayAnim(MOTION::idle);
		}
		// �T�C�Y���������Ȃ�����
		else
		{
			// �v���C���[�Ƃ̋������U���͈͓��ŃL�����N�^�[�����F���Ă�����
			if (playerCharaDistance <= 200)
			{
				// �_���[�W���󂯂Ă���Ƃ�
				if (damageHit)
				{
					Player_PlayAnim(MOTION::damage);
				}
				// �_���[�W���󂯂Ă��Ȃ��Ƃ�
				else
				{
					Player_PlayAnim(MOTION::attack);


					attackFrame += animSpeed;
					
					
					// �U�����I�������
					if (attackFrame >= MV1GetAnimTotalTime(modelHandle, MOTION::attack))
					{
						// �t���[�������������A�_���[�W�𔽉f������
						attackDamageNow = true;
						attackFrame = 0.0f;
					}
					// �U������������
					else
					{
						// �_���[�W�𔽉f�����Ȃ�
						attackDamageNow = false;
					}
				}
			}
			// �v���C���[�ƍ����ւ�����������
			else
			{
				Player_PlayAnim(MOTION::dash);
			}
		}
	}
	// ����ł�����
	else
	{
		Player_PlayAnim(MOTION::death);
	}
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::ChaseMoveProcess()
{
	// �L�����N�^�[�ɋ߂Â�
	walkSpeed = 14.0f;
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



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::FallProcess()
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
		animSpeed = 1.0f;
		jumpPower -= gravity;			// �����d�͂�����������
		area.y += jumpPower;			// Y���W�ɉ���������


		// ����������
		area.y -= 10.5f;
	}


	// ���n���Ă���Ƃ�
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
} /// void EnemyMove4::FallProcess()



/// ------------------------------------------------------------------------------------------------
EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle
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
	MV1SetScale(this->modelHandle, VGet(static_cast<float>(bigBodyChangeDamage)
		, static_cast<float>(bigBodyChangeDamage)
		, static_cast<float>(bigBodyChangeDamage)));

	// �e�N�X�`���̓K��
	blendCount = 255;
	textureHandle0 = -1;
	textureHandle0 = tex0;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);


	// 3D���f���̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::dash;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 130.0f * bigBodyChangeDamage;
	modelWidth = 70.0f *  bigBodyChangeDamage / 4;


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
	shadowHeight = 1.0f;
	shadowSize = 35.0f * bigBodyChangeDamage;


	// ���ꂼ��̑��x
	walkSpeed = 14.0f;
	animSpeed = 0.5f;
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


		// �R���W�������̐ݒ�
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


		// �R���W�������̐ݒ�
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
	MV1SetPosition(this->modelHandle, this->area);


	// �����蔻��̃Z�b�g�A�b�v
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyMove4::EnemyMove4(const int modelHandle, const int collStageHandle



/// ------------------------------------------------------------------------------------------------
EnemyMove4::~EnemyMove4()
{
	// �e�N�X�`�����
	GRAPHIC_RELEASE(textureHandle0);


	// �K�i�Ə��J��
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


	// ���e�p�X�e�[�W�J��
	MODEL_RELEASE(shadowStageHandle);


	// �����蔻��p�X�e�[�W�J��
	MODEL_RELEASE(stageHandle);
} /// EnemyMove4::~EnemyMove4()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::Draw()
{
	BasicObject::ShadowFoot(shadowStageHandle);


#ifdef _DEBUG
	if (MyDebug::enemyFourEnemyDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}

	if (MyDebug::enemyFourEnemySearchLineDrawFlag)
	{
		if (playerCharaDistance <= 1500)
		{
			DrawLine3D(playerCharaArea, area, GetColor(0, 0, 255));
		}
	}
#endif // _DEBUG
} /// void EnemyMove4::Draw()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::UniqueModelDraw()
{
	MV1DrawModel(modelHandle);
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::Process()
{
	// ���ł��Ă�����
	if (eraseExistence) return;


	// ���񂾂Ƃ�
	if (deathFlag)
	{
		MotionProcess();			// ���[�V�����v���Z�X


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
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
		return;
	}


	// ���O�̍��W
	preArea = area;


	// �T�C�Y��������������
	if (damageCount > bigBodyChangeDamage)
	{
		ChaseMoveProcess();		// �v���C���[��ǂ�
	}


	MotionProcess();			// ���[�V�����v���Z�X


	Player_AnimProcess();		// ���[�V��������


	// ����ł��Ȃ����_���[�W���󂯂���
	if (damageHit && !deathFlag)
	{
		damageHit = false;
		walkSpeed = -28.0f;


		// ���f���̑傫���Ƃ���ɔ��������蔻��̍X�V
		if (damageCount <= bigBodyChangeDamage)
		{
			shadowHeight = 65.0f * (1 + bigBodyChangeDamage - damageCount);
			shadowSize = 35.0f * (1 + bigBodyChangeDamage - damageCount);
			MV1SetScale(modelHandle, VGet(static_cast<float>((1 + bigBodyChangeDamage - damageCount))
				, static_cast<float>(1 + (bigBodyChangeDamage - damageCount)), static_cast<float>((1 + bigBodyChangeDamage - damageCount))));
			modelHeight = 130.0f * (1 + bigBodyChangeDamage - damageCount);
			modelWidth = 70.0f * (1 + (bigBodyChangeDamage / 4) - (damageCount / 4));
			MV1RefreshCollInfo(modelHandle, -1);
		}


		// ���ʂ��炢�_���[�W���󂯂���
		if (++damageCount >= 50)
		{
			deathFlag = true;
		}
	}


	int setCollHitNum = 0;		// �����蔻��̌�����


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


	ActorHit(stageHandle);	// �X�e�[�W�̂����蔻��


	FallProcess();	// �����̃v���Z�X


	// �v���C���[����Ɏ��F���ă��f����z�u
	charaLookAtAngle = atan2(VSub(area, playerCharaArea).x, VSub(area, playerCharaArea).z);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, charaLookAtAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
} /// void EnemyMove4::Process()



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);


	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\D\\D.pyn", textureHandle0, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\P\\P.pyn", textureHandle0, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\normal\\normal.pyn", textureHandle0, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle0, true);
}



/// ------------------------------------------------------------------------------------------------
void EnemyMove4::SetCharacterArea(const VECTOR characterArea, const int distance)
{
	playerCharaArea = characterArea;
	playerCharaDistance = distance;
}
