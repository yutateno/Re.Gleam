#include "CharacterSword.hpp"


// �����̃v���Z�X
void CharacterSword::MoveProcess()
{
	// �����Ă�����
	if (moveFlag)
	{
		// �W�����v�����Ă��Ȃ�������
		if (!jumpNow)
		{
			// ���[�V�������x���ʏ��葁�������牺����
			if (animSpeed > 0.75f)
			{
				animSpeed -= 0.02f;
			}
			// ���[�V�������x���ʏ킾������
			else
			{
				animSpeed = 0.75f;
			}


			// �ړ����x���ʏ���x��������グ��
			if (walkSpeed < maxWalkSpeedNormal - 1.0f)
			{
				walkSpeed += 5.0f;
			}
			// �ړ����x���ʏ��葁�������牺����
			else if (walkSpeed > maxWalkSpeedNormal + 1.0f)
			{
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
			}
			// �ړ����x���ʏ킾������
			else
			{
				walkSpeed = maxWalkSpeedNormal;
				modelWidth = 50.0f;
			}


			// ���ł���J�E���g��10�ȉ���������0�ɂ���
			if (flyCount <= 10) flyCount = 0;

			
			underWalkCount++;			// �n�ʂ�����Ă���J�E���g�����Z����


			// �������n�ʂɒ����ʒu�ɗ�����
			if (leftFootArea <= MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y + 1.0f
				&& leftFootArea >= MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y - 1.0f)
			{
				underWalkCount = 2;		// �����Ă���J�E���g��2�ɂ���


				// y���W��10�ȏ�A�܂�I�u�W�F�N�g�̏�ɂ�����
				if (area.y >= 10.0f)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
				}
				// ���n�ɂ�����
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
				}
			}


			// �n�ʂ�����n�߂���
			if (underWalkCount == 1)
			{
				leftFootArea = MV1GetFramePosition(modelHandle, 0).y - MV1GetFramePosition(modelHandle, 5).y;		// �����̈ʒu���擾


				// y���W��10�ȏ�A�܂�I�u�W�F�N�g�̏�ɂ�����
				if (area.y >= 10.0f)
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::footFloor, area);
				}
				// ���n�ɂ�����
				else
				{
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::foot, area);
				}
			}


			// �����J�E���g����0�ł͂Ȃ�14�Ŋ���؂�鐔��������(����������肷���銴
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
		} /// if (!jumpNow)
		// ���ł�����
		else
		{
			// ���[�V�������x�����������牺����
			if (animSpeed > 1.0f)
			{
				animSpeed -= 0.02f;
			}
			// ���[�V�������x���ʏ킾������
			else
			{
				animSpeed = 1.0f;
			}


			// �ړ����x���x��������
			if (walkSpeed < maxWalkSpeedFly - 1.0f)
			{
				walkSpeed += 5.0f;
			}
			// �ړ����x������������
			else if (walkSpeed > maxWalkSpeedFly + 1.0f)
			{
				walkSpeed -= 5.0f;
				modelWidth -= 3.6f;
			}
			// �ړ����x���ʏ킾������
			else
			{
				walkSpeed = maxWalkSpeedFly;
				modelWidth = 50.0f;
			}
		} /// else(!if (!jumpNow))
	} /// if (moveFlag)
	// �����Ă��Ȃ�������
	else
	{
		animSpeed = 0.5f;		// ���[�V�������x�����߂�


		// �������~�܂�悤�ɏ���
		if (walkSpeed > 0.0f)
		{
			walkSpeed -= 5.0f;
		}
		else
		{
			underWalkCount = 0;
			walkSpeed = 0.0f;
		}
	}


	// �u�Ԉړ��̑ҋ@���Ԃ�0����Ȃ������猸�炷
	if (moveFastWaitCount > 0)
	{
		moveFastWaitCount--;
	}


	// �W�����v���Ă��Ȃ��ďu�Ԉړ��̑ҋ@���Ԃ��c���Ă��������
	if (!jumpNow && moveFastWaitCount > maxFastMoveWaitCount)
	{
		moveFastWaitCount = 0;
	}


	// �ړ����x���ʏ�ōő�̂Ƃ���RB����������ړ��𑁂�����
	if (((walkSpeed >= maxWalkSpeedNormal - 1.0f && walkSpeed <= maxWalkSpeedNormal + 1.0f)
		|| (jumpNow && walkSpeed >= maxWalkSpeedFly - 1.0f && walkSpeed <= maxWalkSpeedFly + 1.0f))
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
		&& moveFastWaitCount == 0)
	{
		// �W�����v���Ă�����
		if (jumpNow)
		{
			jumpPower = 0.0f;
			jumpUpNow = false;
			moveFastWaitCount = maxFastMoveWaitCount * 3;		// �W�����v���ɓ��ȏコ���Ȃ����߂ɑ��߂ɂƂ�
			walkSpeed = maxWalkSpeedFlyFast;
			modelWidth = maxWalkSpeedFlyFast * 1.5f;;
		}
		// �W�����v���Ă��Ȃ�������
		else
		{
			moveFastWaitCount = maxFastMoveWaitCount;
			walkSpeed = maxWalkSpeedFast;
			modelWidth = maxWalkSpeedFast * 1.5f;
		}


		// �c���̂���
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
	// ���X�e�B�b�N���O�ɉ�����Ă��Ȃ�������
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
	// ���X�e�B�b�N�����ɉ�����Ă��Ȃ�������
	else
	{
		m_direction[DIRECTION::down] = false;
	}


	// ���X�e�B�b�N�����ɉ����ꂽ�獶�Ɉړ�����
	if (0 > DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X))
	{
		m_direction[DIRECTION::left] = true;
		m_direction[DIRECTION::right] = false;
		// �X�e�B�b�N�̌X���Ŕ�����
		direXAngle = ((float)DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber()
			, DLLXinput::XINPUT_PAD::STICK_LEFT_X) * (DX_PI_F / 2.0f)) / (float)DLLXinput::GetPadThumbMax(false, true, false);
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
	// ���X�e�B�b�N�����E�ǂ���ɂ�������Ă��Ȃ�������
	else
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = false;
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) == 0)
		{
			moveFlag = false;
		}
	}

	/// ����ɑ΂�������Ɠ���----------------------------------------------------------------------------------
	// ���Ɉړ�����t���b�O�������Ă�����
	if (m_direction[static_cast<int>(DIRECTION::left)])
	{
		// �����Ɉړ�����t���b�O�������Ă�����
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// ����Ɉړ�����t���b�O�������Ă�����
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// �^���Ɉړ�����Ƃ�
		else
		{
			area.x += cosf(-angle) * walkSpeed;
			area.z += sinf(-angle) * walkSpeed;
		}
	}
	// �E�Ɉړ�����t���b�O�������Ă�����
	if (m_direction[static_cast<int>(DIRECTION::right)])
	{
		// �E���Ɉړ�����t���b�O�������Ă�����
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * walkSpeed * sqrtf(2);
		}
		// �E��Ɉړ�����t���b�O�������Ă�����
		else if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed * sqrtf(2);
			area.z += cosf(angle + direXAngle) * -walkSpeed * sqrtf(2);
		}
		// �^�E�Ɉړ�����Ƃ�
		else
		{
			area.x += cosf(-angle) * -walkSpeed;
			area.z += sinf(-angle) * -walkSpeed;
		}
	}
	// ���E�ǂ���ɂ��ړ����Ȃ��Ƃ�
	if (!m_direction[static_cast<int>(DIRECTION::right)] && !m_direction[static_cast<int>(DIRECTION::left)])
	{
		// ���Ɉړ�����Ƃ�
		if (m_direction[static_cast<int>(DIRECTION::down)])
		{
			area.x += sinf(angle + direXAngle) * walkSpeed;
			area.z += cosf(angle + direXAngle) * walkSpeed;
		}
		// ��Ɉړ�����Ƃ�
		if (m_direction[static_cast<int>(DIRECTION::up)])
		{
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;
		}
	}
	/// -----------------------------------------------------------------------------------------------------------
} /// void CharacterSword::MoveProcess()


// �U���Ɋւ���v���Z�X
void CharacterSword::AttackProcess()
{
	// �U���̃R�}���h����������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)
	{
		// �ŏ��̍U���̂Ƃ�
		if (attackFrame == 0)
		{
			// �W�����v�����Ă�����
			if (jumpNow)
			{
				// �W�����v�U�������Ă��Ȃ�������
				if (!jumpAttackDo)
				{
					jumpPower = 0.0f;
					jumpUpNow = false;
					attackNumber = MOTION::skyAction1;		// �U���R�}���h�ԍ���1�Ԃɂ���
					jumpAttackDo = true;
				}
				// �W�����v�U�������Ă��Ȃ�������
				else
				{
					// �^���󒆕��V�񂠂�̂œ�x�ȏ�W�����v�ōU�����n�߂����Ȃ�
					return;
				}
			}
			// �W�����v�����Ă��Ȃ�������
			else
			{
				attackNumber = MOTION::action1;		// �U���R�}���h�ԍ���1�Ԃɂ���
			}
			animSpeed = 0.4f;									// �A�j���[�V�������x��ύX


			// �ړ��v���Z�X���痬�p���đO���Ɉړ�������
			area.x += sinf(angle + direXAngle) * -walkSpeed;
			area.z += cosf(angle + direXAngle) * -walkSpeed;


			attackNow = true;					// �U�����Ă���t���b�O�𗧂Ă�
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::pianoAttack1, MV1GetFramePosition(modelHandle, 67));		// ����ōU�������o��
		} /// if (attackFrame == 0)
		// ���ڈȍ~�̍U����
		else if (attackFrame < 10.0f)
		{
			attackNext = true;			// ���̍U�����[�V�����Ɉڍs����Ƃ����t���b�O�𗧂Ă�
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_X) == 1)


	// �U�����I�����ăW�����v���Ă��Ȃ�������W�����v�U���̎n��������
	if (attackFrame == 0 && !jumpNow) jumpAttackDo = false;



	// �U����������
	if (attackNow)
	{
		attackMotionEnd = false;		// �U�����[�V�����I���t���b�O������


		// �U���̍ő呬�x�܂ňړ����x���グ�鏈��
		if (walkSpeed < maxWalkSpeedAttack)
		{
			walkSpeed += 20.0f;
		}
		else
		{
			walkSpeed = maxWalkSpeedAttack;
		}

		// �U���t���[�����A�j���[�V��������������������(�U�����ɑ̂̌�����ς������Ȃ�����
		if (attackFrame < animSpeed)
		{
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
		} /// if (attackFrame < animSpeed)
		attackFrame += animSpeed;
	} /// if (attackNow)


	// �U�����[�V�����̏I�Փ�����Ŏ��̍s�������߂�
	if (attackFrame >= 9.0f)
	{
		attackMotionEnd = true;		// �U���̃��[�V�������I�������t���b�O���ЂƂ܂����Ă�


		// ���̍U���ֈڍs����ƃt���b�O�������Ă�����
		if (attackNext)
		{
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
				attackNow = false;					// ���̃R���{���Ȃ��̂ōU�����I��������
				attackNumber = MOTION::action1;
				preAttackNumber = attackNumber;
				walkSpeed = 0.0f;
				break;


			default:
				break;
			}


			attackFrame = 0;		// �U���̃t���[��������
			attackNext = false;		// ���̍U�����邩�ǂ�����|��


			// �O���Ɉړ�����
			area.x += sinf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));
			area.z += cosf(angle + direXAngle) * -walkSpeed * (1 + (-2 * (direZAngle / DX_PI_F)));
		} /// if (attackNext)
		// ���̍U�������Ȃ�
		else
		{
			walkSpeed = 0.0f;
			attackNow = false;					// �U���t���b�O��|��
			attackFrame = 0;
			attackNumber = MOTION::action1;
			preAttackNumber = attackNumber;
		}
	} /// if (attackFrame >= 9.0f)
} /// void CharacterSword::AttackProcess()


// �W�����v�Ɋւ���v���Z�X
void CharacterSword::JumpProcess()
{
	// �W�����v�U��������������Ȃ�
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
		// ��ԃR�}���h�Ŕ��ł��Ȃ������痎��������
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
		jumpPower -= gravity;			// �����d�͂�����������
		area.y += jumpPower;			// Y���W�ɉ���������
		
		
		// �W�����v�ɂčŒ��_�ɓ��B������
		if (jumpPower <= flyJumpPower / 2.0f) jumpUpNow = false;			// �����ɐ؂�ւ���


		// ����������
		area.y -= 10.5f;
	} /// if (jumpNow)


	// ���n������
	if (!jumpNow && preJumpNow && flyCount > 10)
	{
		flyCount = 0;
		preJumpNow = false;


		// �v���C���[�̍����ɉ����ăI�u�W�F�N�g�ɏ�����Ɣ��f������ς���
		if (area.y >= 10.0f)
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing, area);
		}
		else
		{
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::landing2, area);
		}
	}


	// �����Ȍ덷����I�u�W�F�N�g�ɏ���Ă���Ɣ��f���邪���ۂ͋󒆂�����Ă����Ƃ�
	if (hitDimNum == 0 && area.y >= 10.0f)
	{
		// ���ł��Ȃ�������
		if (!jumpNow)
		{
			jumpNow = true;				// ���ł���

			jumpPower = fallJumpPower;	// �������x��������
		}
	}
} /// void CharacterSword::JumpProcess()


// �A�j���[�V�����̃v���Z�X
void CharacterSword::AnimProcess()
{
	// ���ł���Ƃ�
	if (jumpNow)
	{
		// �U�����Ă���Ƃ�
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		// �U�����Ă��Ȃ��Ƃ�
		else
		{
			// �㏸���Ă���Ƃ�
			if (jumpUpNow)
			{
				Player_PlayAnim(MOTION::jump);
			}
			// �������Ă���Ƃ�
			else
			{
				Player_PlayAnim(MOTION::fall);
			}
		}
	} /// if (jumpNow)
	// ���ł��Ȃ��Ƃ�
	else
	{
		// �U�����Ă���
		if (attackNow)
		{
			Player_PlayAnim(attackNumber);
		}
		// �U�����Ă��Ȃ��Ƃ�
		else
		{
			// �_���[�W���󂯂Ă���Ƃ�
			if (damageFlag)
			{
				Player_PlayAnim(MOTION::damage);
				damageFlag = false;
			}
			// �_���[�W���󂯂Ă��Ȃ��Ƃ�
			else
			{
				// �����Ă���Ƃ�
				if (moveFlag)
				{
					Player_PlayAnim(MOTION::dash);
				}
				// �~�܂��Ă���Ƃ�
				else
				{
					Player_PlayAnim(MOTION::idle);
				}
			}
		}
	} /// else(1if (jumpNow))
} /// void CharacterSword::AnimProcess()


CharacterSword::CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle, const int stairsRoadHandle
	, const int tex0, const int tex1, const int tex2, const int tex3, const int tex4) : BasicCreature(true)
{
	// �����蔻��̃X�e�[�W�̃R���W�������̍X�V
	stageHandle = -1;
	stageHandle = MV1DuplicateModel(collStageHandle);
	MV1SetScale(stageHandle, VGet(0.7f, 0.7f, 0.7f));
	MV1SetPosition(stageHandle, VGet(0.0f, 0.0f, 0.0f));				// �X�e�[�W�̍��W���X�V
	MV1SetupCollInfo(stageHandle, -1);									// ���f���̃R���W���������Z�b�g�A�b�v(-1�ɂ��S�̃t���[��)
	MV1SetFrameVisible(stageHandle, -1, false);							// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j
	MV1RefreshCollInfo(stageHandle, -1);								// �X�e�[�W��`�悳���Ȃ��i�ł��ǂ���Draw�Ă΂Ȃ����炱��Ӗ��Ȃ��C������j

	// �����e����p�̃X�e�[�W�̃R���W�������̍X�V
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
	moveFastWaitCount = 0;


	// ���f���̌����ƈʒu
	area = VGet(0.0f, 50.0f, 0.0f);
	preArea = area;
	preDrawArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;
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
	attackMotionEnd = true;
	mostNearEnemyArea = VGet(0, -1000, 0);


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

	
	// 3D�T�E���h�̃v���C���[�̈ʒu���X�V
	SoundProcess::SetCharaArea(area);

	
	// �A�N�^�[���m�̂����蔻��p�̏����̃Z�b�g�A�b�v
	MV1SetupCollInfo(this->modelHandle, -1);
} /// CharacterSword::CharacterSword(const int modelHandle, const int collStageHandle, const int stairsHandle, const int paneruHandle, const int stairsRoadHandle
/// , const int tex0, const int tex1, const int tex2, const int tex3, const int tex4) : BasicCreature(true)


CharacterSword::~CharacterSword()
{
	// �e�N�X�`�������
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);
	

	// �p�l�������
	for (int i = 0; i != 10; ++i)
	{
		MODEL_RELEASE(paneruHandle[i]);
	}


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


	// ���f�������
	MODEL_RELEASE(modelHandle);


	// �e�p�X�e�[�W�n���h���̉��
	MODEL_RELEASE(shadowStageHandle);

	
	// �����蔻��p�X�e�[�W�n���h���̉��
	MODEL_RELEASE(stageHandle);
} /// CharacterSword::~CharacterSword()


// �K�i�̃R���W�����Z�b�g�A�b�v
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


// �p�l���̃R���W�����Z�b�g�A�b�v
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


// �K�i�Ə��̃R���W�����Z�b�g�A�b�v
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


// �_���[�W���󂯂��Ƃ��Ă΂��
void CharacterSword::SetDamage()
{
	damageFlag = true;
}


// ���C���v���Z�X
void CharacterSword::Process(const float getAngle)
{
	preArea = area;		// ���O�̍��W


	SoundProcess::SetCharaArea(area);		// 3D�T�E���h�̃v���C���[�̈ʒu���X�V


	// �����Ă���������͍U�����Ă���Ƃ�
	if (moveFlag || attackNow)
	{
		angle = getAngle;	// �J���������̃A���O��
	}


	// �G���߂��ɂ��ē����Ă��Ȃ���ԂōU����������
	if (!moveFlag && attackNow && !(mostNearEnemyArea.y >= -1001.0f && mostNearEnemyArea.y <= -999.0f))
	{
		// �G�̕��Ɍ����悤�ɂ���
		mostNearEnemyDire = atan2(VSub(area, mostNearEnemyArea).x, VSub(area, mostNearEnemyArea).z);
		direXAngle = mostNearEnemyDire;
		direZAngle = 0.0f;
		angle = 0.0f;
	}


	// �U�������Ă��Ȃ�������
	if (!attackNow)
	{
		MoveProcess();		// �����̃v���Z�X���Ă�
	}


	// �U���̃v���Z�X
	AttackProcess();

	
	// ���[�V�����̃V�X�e��
	Player_AnimProcess();


	// ���[�V�����̃v���Z�X
	AnimProcess();


	// �ǂ��ɂ��������Ă��Ȃ��Ƃ���
	hitDimNum = 0;


	int setCollHitNum = 0;	// �ǂ����̃I�u�W�F�N�g�Ƃ����������m�F���鐔�l


	// �p�l���̂����蔻��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setCollHitNum += ActorHit(paneruHandle[i]);
		}
	}


	// �����蔻�肪�����Ă��Ȃ�������
	if (setCollHitNum == 0)
	{
		// �K�i�Ə��̂����蔻��
		for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
		{
			setCollHitNum += ActorHit(v_stairsRoadHandle[i]);
		}
	}


	// �����蔻�肪�����Ă��Ȃ�������
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


	// �u�Ԉړ������Ă��Ȃ��������͏u�Ԉړ������Ă��炠���莞�Ԍo�߂�����(�󒆂ŕ��s�ړ��������邽��
	if (moveFastWaitCount < (maxFastMoveWaitCount * 3) - 9)
	{
		JumpProcess();		// �W�����v�v���Z�X���Ă�
	}


	// �v��Ȃ����Ǖs���Ȃ̂ňꉞ
	if (area.y < 0.0f)
	{
		area.y = 0.5f;
	}
	if (area.x >= 4900.0f || area.x <= -4900.0f
		|| area.z >= 4900.0f || area.z <= -4900.0f)
	{
		area = VGet(0, 0, 0);
	}


	// �����Ă��Ȃ���ԂŃ��b�N�I�������G���߂��ɂ��čU�������Ƃ�
	if (!moveFlag && attackNow && !(mostNearEnemyArea.y >= -1001.0f && mostNearEnemyArea.y <= -999.0f))
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f,mostNearEnemyDire, 0.0f));		// �̂̌��������߂�
	}
	// �ʏ�̎�
	else
	{
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));		// �̂̌��������߂�
	}


	// �ʏ�̈ړ����x�̎�
	if (walkSpeed != maxWalkSpeedFast)
	{
		// �w��ʒu�Ƀ��f����z�u
		MV1SetPosition(modelHandle, area);
	}
} /// void CharacterSword::Process(const float getAngle)


// �|�W�V���������Z�b�g����
void CharacterSword::PositionReset()
{
	area = VGet(0.0f, 50.0f, 0.0f);
}


// �e�N�X�`���������ւ���
void CharacterSword::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);
	GRAPHIC_RELEASE(textureHandle4);

	switch (BASICPARAM::e_TextureColor)
	{
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
} /// void CharacterSword::TextureReload()


// �`��
void CharacterSword::Draw()
{
	int setShadowNum = 0;		// ���̉e�𐶐��������ǂ����̌����擾����


	// �u�Ԉړ������Ƃ��̎c���������Ă��Ȃ�������
	if (blendCount != 0)
	{
		// �c���̈ʒu��ۑ�����
		if (moveFastWaitCount == maxFastMoveWaitCount * 3 || walkSpeed == maxWalkSpeedFast)
		{
			preDrawArea = preArea;
		}


		// ���[�u5�ȍ~�̎��̂Ɋւ���Ƃ��Ŏ��̂����߂��Ă��Ȃ�������A�Ɋ֌W���Ă��Ȃ��Ƃ�
		if (!(BASICPARAM::e_nowScene >= ESceneNumber::FIFTHLOAD && !BASICPARAM::lastCharaView))
		{
			// �c�����f���̕`��
			MV1SetPosition(modelHandle, preDrawArea);
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
		}


		// �ʏ탂�f���̕`��
		MV1SetPosition(modelHandle, area);
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
		blendCount -= 10;
	}


	// �p�l���ł̑��e
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			setShadowNum += BasicObject::ShadowFoot(paneruHandle[i]);
		}
	}


	// ���e����������Ă�����
	if (setShadowNum != 0) return;
	// �K�i�ł̑��e
	for (int i = 0; i != BASICPARAM::stairsNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsHandle[i]);
	}


	// ���e����������Ă�����
	if (setShadowNum != 0) return;
	// �K�i�Ə��ł̑��e
	for (int i = 0; i != BASICPARAM::stairsRoadNum; ++i)
	{
		setShadowNum += BasicObject::ShadowFoot(v_stairsRoadHandle[i]);
	}


	// ���e����������Ă�����
	if (setShadowNum != 0) return;
	// �X�e�[�W�ł̑��e
	BasicObject::ShadowFoot(shadowStageHandle);

#ifdef _DEBUG
	if(MyDebug::characterSwordDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
} /// void CharacterSword::Draw()


// �I�v�V������ʃ��f���̌㏈��
void CharacterSword::OptionActorDrawAfter()
{
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + direXAngle + direZAngle, 0.0f));
	MV1SetPosition(modelHandle, area);
}