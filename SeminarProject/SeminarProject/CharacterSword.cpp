#include "CharacterSword.hpp"

// �����̃v���Z�X
void CharacterSword::MoveProcess()
{
	// �X���[�Y�ɓ�������
	if (moveFlag)
	{
		if (!jumpNow)
		{
			if (animSpeed > 0.75f)
			{
				animSpeed -= 0.02f;
			}
			else
			{
				animSpeed = 0.75f;
			}
			if (walkSpeed < 29.0f)
			{
				walkNow = true;
				walkSpeed += 5.0f;
			}
			else if (walkSpeed > 31.0f)
			{
				walkNow = true;
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
				blendCount -= 10;
			}
			else
			{
				walkNow = true;
				walkSpeed = 30.0f;
				modelWidth = 50.0f;
				blendCount = 0;
			}

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
		else
		{
			if (animSpeed > 1.0f)
			{
				animSpeed -= 0.02f;
			}
			else
			{
				animSpeed = 1.0f;
			}
			if (walkSpeed < 14.0f)
			{
				walkNow = true;
				walkSpeed += 5.0f;
			}
			else if (walkSpeed > 16.0f)
			{
				walkNow = true;
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
				blendCount -= 10;
			}
			else
			{
				walkNow = true;
				walkSpeed = 16.0f;
				modelWidth = 50.0f;
				blendCount = 0;
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


	if (moveFastWaitCount > 0)
	{
		moveFastWaitCount--;
	}
	if (!jumpNow && moveFastWaitCount > 34)
	{
		moveFastWaitCount = 0;
	}

	// �ړ����x���ő��RB���������Ƃ��ɑ�������
	if (((walkSpeed >= 29.0f && walkSpeed <= 31.0f) || (jumpNow && walkSpeed >= 14.0f && walkSpeed <= 16.0f))
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
		&& moveFastWaitCount == 0)
	{
		if (jumpNow)
		{
			jumpPower = 0.0f;
			jumpUpNow = false;
			moveFastWaitCount = 99;
			walkSpeed = 85.0f;
			modelWidth = 85.0f;
		}
		else
		{
			moveFastWaitCount = 34;
			walkSpeed = 100.0f;
			modelWidth = 100.0f;
		}
		blendCount = 140;
		animSpeed = 1.0f;
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
		//walkSpeed = 10.0f;
		//animSpeed = 1.0f;
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
	, const int tex0, const int tex1, const int tex2, const int tex3, const int tex4) : BasicCreature(true)
{
	// �X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.73f, 0.73f, 0.73f));
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
	blendCount = 0;
	notDamegaCount = 0;
	moveFastWaitCount = 0;


	// ���f���̌����ƈʒu
	area = VGet(0.0f, 50.0f, 0.0f);
	preArea = area;
	preDrawArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
	walkNow = false;
	leftFootArea = 0.0f;
	underWalkCount = 0;
	leftUnderTouchFrame = 13;


	// �����̉e�Ɋւ���
	shadowHeight = 750.0f;
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
	damageCount = 0;
	preDamageCount = damageCount;
	notDamegaCount = 0;
	damageDrawFrame = 0;
	damageDrawID = 0;


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

	// �G�t�F�N�g�ǂݍ���
	effeckBack[0] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\one.efk");
	effeckBack[1] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\two.efk");
	effeckBack[2] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\three.efk");
	effeckBack[3] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\four.efk");
	effeckBack[4] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\five.efk");
	effeckBack[5] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\six.efk");
	effeckBack[6] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\seven.efk");
	effeckBack[7] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\eight.efk");
	effeckBack[8] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\nine.efk");
	effeckBack[9] = LoadEffekseerEffect("media\\������\\media\\Effect\\damagePerticle\\ten.efk");
	playingEfBack = -1;
	damageDraw[0] = LoadGraph("media\\������\\media\\damage\\damage1.png");
	damageDraw[1] = LoadGraph("media\\������\\media\\damage\\damage2.png");
	damageDraw[2] = LoadGraph("media\\������\\media\\damage\\damage3.png");
	damageBlend[0] = LoadGraph("media\\������\\media\\damage\\Blood\\bl1.png");
	damageBlend[1] = LoadGraph("media\\������\\media\\damage\\Blood\\bl2.png");
	damageBlend[2] = LoadGraph("media\\������\\media\\damage\\Blood\\bl3.png");
	damageBlend[3] = LoadGraph("media\\������\\media\\damage\\Blood\\bl4.png");
	damageBlend[4] = LoadGraph("media\\������\\media\\damage\\Blood\\bl5.png");
	damageBlend[5] = LoadGraph("media\\������\\media\\damage\\Blood\\bl6.png");
	damageBlend[6] = LoadGraph("media\\������\\media\\damage\\Blood\\bl7.png");
	damageBlend[7] = LoadGraph("media\\������\\media\\damage\\Blood\\bl8.png");
	damageBlend[8] = LoadGraph("media\\������\\media\\damage\\Blood\\bl9.png");
	damageBlend[9] = LoadGraph("media\\������\\media\\damage\\Blood\\bl10.png");
}


CharacterSword::~CharacterSword()
{
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(damageDraw[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(damageBlend[i]);
	}
	StopEffekseer2DEffect(playingEfBack);
	for (int i = 0; i != 10; ++i)
	{
		DeleteEffekseerEffect(effeckBack[i]);
	}

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
	MODEL_RELEASE(shadowStageHandle);
	MODEL_RELEASE(stageHandle);
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
	notDamegaCount = 0;
	if (damageCount < 100)	damageCount++;
	damageFlag = true;

	if (damageDrawFrame == 0)
	{
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
		std::uniform_int_distribution<> blood(0, 2);        // X���W�p����
		damageDrawID = blood(mt);
		damageDrawFrame = 10;
	}
}


// ���C���v���Z�X
void CharacterSword::Process(const float getAngle)
{
	/*notDamegaCount++;
	if (notDamegaCount > 25 && damageCount > 0) damageCount--;*/

	if (damageDrawFrame > 0) damageDrawFrame--;

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

	int setCollHitNum = 0;

	// �p�l���̂����蔻��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setCollHitNum += ActorHit(paneruHandle[i]);
		}
	}

	// �K�i�Ə��̂����蔻��
	if (setCollHitNum == 0)
	{
		for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
		}
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

	// �W�����v�̃v���Z�X
	if (moveFastWaitCount < 90)
	{
		JumpProcess();
	}


	// �v��Ȃ����Ǖs���Ȃ̂ňꉞ
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}


	// �������̉�]�p�x���Z�b�g
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	if (walkSpeed != 100.0f)
	{
		// �w��ʒu�Ƀ��f����z�u
		MV1SetPosition(modelHandle, area);
	}
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
	int setShadowNum = 0;

	if (blendCount != 0)
	{
		VECTOR temp = area;
		if (moveFastWaitCount == 99 || walkSpeed == 100.0f)
		{
			preDrawArea = preArea;
		}
		area = preDrawArea;
		// �w��ʒu�Ƀ��f����z�u
		MV1SetPosition(modelHandle, area);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 3, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 4, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 2, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 3, blendCount);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 4, blendCount);
		MV1DrawModel(modelHandle);
		area = temp;
		MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 3, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendMode(this->modelHandle, 4, DX_BLENDMODE_ALPHA);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 0, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 1, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 2, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 3, 255);
		MV1SetMaterialDrawBlendParam(this->modelHandle, 4, 255);
		// �w��ʒu�Ƀ��f����z�u
		MV1SetPosition(modelHandle, area);
	}

	BasicObject::Draw();		// ��{�I�Ȃ��̂����������Ă���



	//if (IsEffekseer2DEffectPlaying(playingEfBack) != 0)
	//{
		// �G�t�F�N�g���Đ�����B
	if (preDamageCount != damageCount / 10)
	{
		preDamageCount = damageCount / 10;
		switch (damageCount)
		{
		case 1:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[0]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 2:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[1]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 3:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[2]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 4:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[3]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 5:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[4]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 6:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[5]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 7:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[6]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 8:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[7]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 9:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[8]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;

		case 10:
			if (IsEffekseer2DEffectPlaying(playingEfBack) == 0) StopEffekseer2DEffect(playingEfBack);
			playingEfBack = PlayEffekseer2DEffect(effeckBack[9]);
			SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
			break;
		}
	}
	//}

	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//�u�����h���[�h����(128/255)�ɐݒ�
	//if (damageCount >= 0)
	//{
	//	DrawBox(0, 0, static_cast<int>(damageCount * (1920 / 200)), static_cast<int>(1080 - damageCount * (1080 / 200)), GetColor(237, 29, 55), true);	// ��
	//	DrawBox(static_cast<int>(damageCount * (1920 / 200)), 0, 1920, static_cast<int>(damageCount * (1080 / 200)), GetColor(237, 29, 55), true);	// ��
	//	DrawBox(1920, static_cast<int>(damageCount * (1080 / 200)), static_cast<int>(1920 - damageCount * (1920 / 200)), 1080, GetColor(237, 29, 55), true);	// �E
	//	DrawBox(0, 1080, static_cast<int>(1920 - damageCount * (1920 / 200)), static_cast<int>(1080 - damageCount * (1080 / 200)), GetColor(237, 29, 55), true);	// ��
	//}
	//DrawExtendGraph(static_cast<int>(0 + damageCount * (1920 / 200)), static_cast<int>(0 + damageCount * (1080 / 200))
	//	, static_cast<int>(1920 - damageCount * (1920 / 200)), static_cast<int>(1080 - damageCount * (1080 / 200)), damageBlend, TRUE); //�摜�̕`��
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t

	if(damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}

	printfDx("%d\n", damageCount);
	if (damageCount > 0)
	{
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageCount * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[0], true);
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 10)
	{
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 10) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[1], true);
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 20)
	{
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 20) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[2], true);
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 30)
	{
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 30) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[3], true);
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 40)
	{
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 40) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[4], true);
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 50)
	{
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 50) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[5], true);
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 60)
	{
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 60) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[6], true);
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 70)
	{
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 70) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[7], true);
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 80)
	{
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 80) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[8], true);
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}
	if (damageCount > 90)
	{
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 90) * 25.5));		//�u�����h���[�h����(128/255)�ɐݒ�
		DrawGraph(0, 0, damageBlend[9], true);
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t
	}


	// �p�l���ł̑��e
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setShadowNum += BasicObject::ShadowFoot(paneruHandle[i]);
		}
	}

	// �K�i�ł̑��e
	if (setShadowNum != 0) return;
	for (int i = 0; i != BASICPARAM::stairsNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsHandle[i]);
	}

	// �K�i�Ə��ł̑��e
	if (setShadowNum != 0) return;
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsRoadHandle[i]);
	}

	// �X�e�[�W�̑��e
	if (setShadowNum != 0) return;
	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if(MyDebug::characterSwordDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}
