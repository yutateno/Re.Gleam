#include "CharacterSword.hpp"

// �����̃v���Z�X
void CharacterSword::MoveProcess()
{
	// �X���[�Y�ɓ�������
	if (moveFlag)
	{
		animSpeed = 0.75f;
		if (walkSpeed < 30.0f)
		{
			walkNow = true;
			walkSpeed += 5.0f;
		}
		else
		{
			walkNow = false;
			walkSpeed = 30.0f;
		}


		if (!jumpNow)
		{
			if (flyCount <= 10) flyCount = 0;
			underWalkCount++;
			if (underWalkCount == 1)
			{
				leftFootArea = MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y;
				if (area.y >= 10.0f)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
				}
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
				}
			}
			if (leftFootArea < MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y + 1.0f
				&& leftFootArea > MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y - 1.0f)
			{
				underWalkCount = 2;
				if (area.y >= 10.0f)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
				}
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
				}
			}
			if (underWalkCount % 14 == 0 && underWalkCount != 0)
			{
				if (area.y >= 10.0f)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
				}
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
				}
			}
		}
	}
	else
	{
		animSpeed = 0.5f;
		if (walkSpeed > 0.0f)
		{
			walkNow = true;
			walkSpeed -= 5.0f;
		}
		else
		{
			underWalkCount = 0;
			walkNow = false;
			walkSpeed = 0.0f;
		}
	}

	// ���X�e�B�b�N���O�ɉ����ꂽ��O�i����
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		m_direction[DIRECTION::up] = true;
		direXAngle = 0.0f;
		direZAngle = 0.0f;
		moveFlag = true;
	}
	else
	{
		m_direction[DIRECTION::up] = false;
	}
	// ���X�e�B�b�N�����ɉ����ꂽ���ނ���
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y))
	{
		m_direction[DIRECTION::down] = true;
		direXAngle = 0.0f;
		direZAngle = DX_PI_F;
		moveFlag = true;
	}
	else
	{
		m_direction[DIRECTION::down] = false;
	}
	// ���X�e�B�b�N�����ɉ����ꂽ�獶�Ɉړ�����
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X))
	{
		m_direction[DIRECTION::left] = true;
		m_direction[DIRECTION::right] = false;
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, false);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
	}
	// ���X�e�B�b�N���E�ɉ����ꂽ��E�Ɉړ�����
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = true;
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, true);
		if (direZAngle != 0.0f)
		{
			direXAngle = -direXAngle;
		}
		moveFlag = true;
	}
	// �L�����̑O��̌������C�����悭���邽��
	else
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = false;
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) == 0)
		{
			moveFlag = false;
		}
	}

	/// ����ɑ΂�������Ɠ���
	if (m_direction[static_cast<int>(DIRECTION::left)])
	{
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		else
		{
			area.x += cosf(-angle) * walkSpeed;
			area.z += sinf(-angle) * walkSpeed;
		}
	}
	if (m_direction[static_cast<int>(DIRECTION::right)])
	{
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		else
		{
			area.x += cosf(-angle) * -walkSpeed;
			area.z += sinf(-angle) * -walkSpeed;
		}
	}
	if (!m_direction[static_cast<int>(DIRECTION::right)] && !m_direction[static_cast<int>(DIRECTION::left)])
	{
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed;
			area.z += cosf(angle + direXAngle) * walkSpeed;
		}
		if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;
		}
	}
}


// �U���Ɋւ���v���Z�X
void CharacterSword::AttackProcess()
{
	// �U���̃R�}���h����������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		// �ŏ��̎�
		if (attackFrame == 0)
		{
			if (jumpNow)
			{
				if (!jumpAttackDo)
				{
					jumpPower = 0.0f;
					jumpUpNow = false;
					attackNumber = MOTION::skyAction1;		// �U���R�}���h�ԍ���1�Ԃɂ���
					jumpAttackDo = true;
				}
				else
				{
					return;
				}
			}
			else
			{
				attackNumber = MOTION::action1;		// �U���R�}���h�ԍ���1�Ԃɂ���
			}
			animSpeed = 0.4f;									// �A�j���[�V�������x��ύX


			// �ړ��v���Z�X���痬�p���đO���Ɉړ�������
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;


			attackNow = true;					// �U�����Ă���t���b�O�𗧂Ă�
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack1, MV1GetFramePosition(modelHandle, 67));
		}
		// ���ڈȍ~�̍U����
		else if (attackFrame < 10.0f)
		{
			attackNext = true;			// ���̍U�����[�V�����Ɉڍs����Ƃ����t���b�O�𗧂Ă�
		}
	}

	if (attackFrame == 0 && !jumpNow) jumpAttackDo = false;


	// �U�����[�V�����̏I�Փ�����Ŏ��̍s�������߂�
	if (attackFrame >= 9.0f)
	{
		// ���̍U���ֈڍs����ƃt���b�O�������Ă�����
		if (attackNext)
		{
			// �O���Ɉړ�����
			area.x += sinf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));
			area.z += cosf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));


			// ���O�̍U�����[�V�����Ŏ��̃��[�V���������߂�
			switch (preAttackNumber)
			{
			// �ŏ��̍U����
			case MOTION::action1:
				animSpeed = 0.4f;									// �A�j���[�V�������x��ύX
				attackNumber = MOTION::action2;
				preAttackNumber = attackNumber;
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack2, MV1GetFramePosition(modelHandle, 67));
				break;

			// ��R���{�ڂ̍U����
			case MOTION::action2:
				animSpeed = 0.4f;									// �A�j���[�V�������x��ύX
				attackNumber = MOTION::action3;
				preAttackNumber = attackNumber;
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack3, MV1GetFramePosition(modelHandle, 67));
				break;

			// �Ō�̍U����
			case MOTION::action3:
				attackNow = false;					// ���̃R���{���Ȃ��̂ōU���t���b�O��|��
				attackNumber = MOTION::action1;
				preAttackNumber = attackNumber;
				walkSpeed = 0.0f;
				break;

			// �W�����v���̍ŏ��̍U����
			case MOTION::skyAction1:
				animSpeed = 0.4f;
				attackNumber = MOTION::skyAction2;
				preAttackNumber = attackNumber;
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack2, MV1GetFramePosition(modelHandle, 67));
				break;

			// �W�����v���̓�R���{�ڂ̍U����
			case MOTION::skyAction2:
				animSpeed = 0.4f;
				attackNumber = MOTION::skyAction3;
				preAttackNumber = attackNumber;
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack2, MV1GetFramePosition(modelHandle, 67));
				break;

			// �W�����v���̍Ō�̍U����
			case MOTION::skyAction3:
				attackNow = false;
				attackNumber = MOTION::action1;
				preAttackNumber = attackNumber;
				walkSpeed = 0.0f;
				break;

			default:
				break;
			}


			attackFrame = 0;		// �U���̃t���[��������
			attackNext = false;		// ���̍U�����邩�ǂ�����|��
		}
		// ���̍U�������Ȃ�
		else
		{
			walkSpeed = 0.0f;
			attackNow = false;					// �U���t���b�O��|��
			attackFrame = 0;
			attackNumber = MOTION::action1;
			preAttackNumber = attackNumber;
		}
	}



	// �U���t���b�O����������
	if (attackNow)
	{
		if (walkSpeed < 60.0f)
		{
			walkSpeed += 20.0f;
		}
		else
		{
			walkSpeed = 60.0f;
		}


		attackFrame += animSpeed;


		// ���X�e�B�b�N���O�ɉ����ꂽ��O������
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
		{
			direXAngle = 0.0f;
			direZAngle = 0.0f;
		}
		// ���X�e�B�b�N�����ɉ����ꂽ���������
		if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y))
		{
			direXAngle = 0.0f;
			direZAngle = DX_PI_F;
		}

		// ���X�e�B�b�N�����ɉ����ꂽ�獶������
		if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X))
		{
			direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, false);
			if (direZAngle != 0.0f)
			{
				direXAngle = -direXAngle;
			}
		}
		// ���X�e�B�b�N���E�ɉ����ꂽ��E������
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, true);
			if (direZAngle != 0.0f)
			{
				direXAngle = -direXAngle;
			}
		}
	}
}


// �W�����v�Ɋւ���v���Z�X
void CharacterSword::JumpProcess()
{
	if (attackNow && jumpNow) return;

	// �����ĂȂ���ԂŃW�����v����R�}���h����������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1
		&& !jumpNow)
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::jump, area);
		jumpNow = true;					// ���ł���
		jumpUpNow = true;				// ��ɏオ���Ă���
		jumpPower = flyJumpPower;		// ��ԑ��x��������
	}


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
		underWalkCount = 0;
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
		if (area.y >= 10.0f)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing, area);
		}
		else
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing2, area);
		}
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


// �A�j���[�V�����̃v���Z�X
void CharacterSword::AnimProcess()
{
	// ���ł���
	if (jumpNow)
	{
		// �U�����Ă���
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		else
		{
			// �㏸���Ă���
			if (jumpUpNow)
			{
				Player_PlayAnim(MOTION::jump);
			}
			else
			{
				Player_PlayAnim(MOTION::fall);
			}
		}
	}
	else
	{
		// �U�����Ă���
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		else
		{
			if (damageFlag)
			{
				Player_PlayAnim(MOTION::damage);
				damageFlag = false;
			}
			else
			{
				// �����Ă���
				if (moveFlag)
				{
					// �������x�̎�
					//if (walkNow)
					//{
					//	Player_PlayAnim(MOTION::walk);
					//}
					//else
					//{
					Player_PlayAnim(MOTION::dash);
					//}
				}
				else
				{
					Player_PlayAnim(MOTION::idle);
				}
			}
		}
	}
}


CharacterSword::CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle, const int stairsRoadHandle
	, const int tex0, const int tex1, const int tex2, const int tex3, const int tex4) : BasicCreature(collStageHandle, true)
{
	// �R�c���f���̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);


	/// �e�N�X�`���Ɋւ���-------------------------------------------------------------------------------------------------------------------------

	// �e�N�X�`���K��
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle3 = -1;
	textureHandle4 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	textureHandle2 = tex2;
	textureHandle3 = tex3;
	textureHandle4 = tex4;

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);
	MV1SetTextureGraphHandle(this->modelHandle, 4, textureHandle4, true);
	/// -----------------------------------------------------------------------------------------------------------------------------------------


	// �R�c���f����0�Ԗڂ̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 160.0f;
	modelWidth = 50.0f;


	// ���f���̌����ƈʒu
	area = VGet(0.0f, 50.0f, 0.0f);
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	walkNow = false;
	leftFootArea = 0.0f;
	underWalkCount = 0;
	leftUnderTouchFrame = 13;


	// �����̉e�Ɋւ���
	shadowHeight = 20.0f;
	shadowSize = 50.0f;


	// ���ꂼ��̑��x
	walkSpeed = 0.0f;
	animSpeed = 0.25f;
	ZeroMemory(m_direction, sizeof(m_direction));


	// �U���Ɋւ���
	attackNow = false;
	attackNext = false;
	attackFrame = 0;
	attackNumber = MOTION::action1;
	preAttackNumber = MOTION::action1;
	jumpAttackDo = false;


	// �W�����v�Ɋւ���
	jumpNow = false;
	jumpUpNow = false;
	jumpPower = 0.0f;
	gravity = 0.75f;
	flyJumpPower = 50.0f;
	fallJumpPower = 3.0f;
	preJumpNow = false;
	flyCount = 0;


	// �K�i
	v_stairsHandle.clear();
	this->v_stairsHandle.push_back(MV1DuplicateModel(stairsHandle));

	// �p�l��
	this->paneruHandle[0] = MV1DuplicateModel(paneruHandle);
	MV1SetScale(this->paneruHandle[0], VGet(50.0f, 50.0f, 50.0f));

	// �K�i�Ə�
	v_stairsRoadHandle.clear();
	this->v_stairsRoadHandle.push_back(MV1DuplicateModel(stairsRoadHandle));


	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, area);

	SoundProcess::SetCharaArea(area);
}


CharacterSword::~CharacterSword()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);
	
	for (int i = 0; i != 10; ++i)
	{
		MODEL_RELEASE(paneruHandle[i]);
	}

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
}

void CharacterSword::SetStairsArea(const VECTOR stairsArea, const int num, const float angle)
{
	// �X�e�[�W�̃R���W�������̍X�V
	if (num != 0)
	{
		v_stairsHandle.push_back(MV1DuplicateModel(v_stairsHandle[0]));
	}
	MV1SetRotationXYZ(v_stairsHandle[num], VGet(0.0f, angle, 0.0f));
	MV1SetPosition(v_stairsHandle[num], stairsArea);				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(v_stairsHandle[num], -1);						// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(v_stairsHandle[num], -1, false);				// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(v_stairsHandle[num], -1);
}

void CharacterSword::SetPaneruArea(const VECTOR paneruArea, const int num)
{
	// �X�e�[�W�̃R���W�������̍X�V
	if (num != 0)
	{
		paneruHandle[num] = MV1DuplicateModel(paneruHandle[0]);
		MV1SetScale(this->paneruHandle[num], VGet(50.0f, 50.0f, 50.0f));
	}
	MV1SetPosition(paneruHandle[num], paneruArea);					// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(paneruHandle[num], -1);						// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(paneruHandle[num], -1, false);				// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(paneruHandle[num], -1);
}

void CharacterSword::SetStairsRoadArea(const VECTOR stairsRoadArea, const int num, const float angle)
{
	// �X�e�[�W�̃R���W�������̍X�V
	if (num != 0)
	{
		v_stairsRoadHandle.push_back(MV1DuplicateModel(v_stairsRoadHandle[0]));
	}
	MV1SetRotationXYZ(v_stairsRoadHandle[num], VGet(0.0f, angle, 0.0f));
	MV1SetPosition(v_stairsRoadHandle[num], stairsRoadArea);		// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(v_stairsRoadHandle[num], -1);					// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(v_stairsRoadHandle[num], -1, false);			// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(v_stairsRoadHandle[num], -1);				// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
}

void CharacterSword::SetDamage()
{
	damageFlag = true;
}


// ���C���v���Z�X
void CharacterSword::Process(const float getAngle)
{
	preArea = area;		// ���O�̍��W

	SoundProcess::SetCharaArea(area);

	if (moveFlag || attackNow)
	{
		angle = getAngle;	// �J���������̃A���O��
	}

	// �����̃v���Z�X
	if (!attackNow)
	{
		MoveProcess();
	}

	// �U���̃v���Z�X
	AttackProcess();

	
	// ���[�V�����̎���
	Player_AnimProcess();


	// ���[�V�����̃v���Z�X
	AnimProcess();

	hitDimNum = 0;

	// �K�i�̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsNum; ++i)
	{
		ActorHit(v_stairsHandle[i]);
	}

	// �K�i�Ə��̂����蔻��
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		ActorHit(v_stairsRoadHandle[i]);
	}

	// �p�l���̂����蔻��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			ActorHit(paneruHandle[i]);
		}
	}

	// �W�����v�̃v���Z�X
	JumpProcess();

	// �X�e�[�W�̂����蔻��
	StageHit();


	// �v��Ȃ����Ǖs���Ȃ̂ňꉞ
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}


	// �������̉�]�p�x���Z�b�g
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	// �w��ʒu�Ƀ��f����z�u
	MV1SetPosition(modelHandle, area);
}


void CharacterSword::PositionReset()
{
	area = VGet(0.0f, 0.0f, 0.0f);
}

void CharacterSword::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::WHITEBLACK:
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn", textureHandle2, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn", textureHandle3, ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn", textureHandle4, ELOADFILE::graph);
		break;
	}

	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);
	MV1SetTextureGraphHandle(this->modelHandle, 4, textureHandle4, true);
}



// �`��
void CharacterSword::Draw()
{
	BasicObject::Draw();		// ��{�I�Ȃ��̂����������Ă���

	BasicObject::ShadowFoot();

#ifdef _DEBUG
	if(MyDebug::characterSwordDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}
