#include "Character.hpp"

// �����̃v���Z�X
void Character::MoveProcess()
{
	// �X���[�Y�ɓ�������
	if (moveFlag)
	{
		animSpeed = 1.0f;
		if (walkSpeed < 20.0f)
		{
			walkSpeed += 2.5f;
		}
		else
		{
			walkSpeed = 20.0f;
		}
	}
	else
	{
		animSpeed = 0.5f;
		if (walkSpeed > 0.0f)
		{
			walkSpeed -= 5.0f;
		}
		else
		{
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
		Player_PlayAnim(MOTION::walk);
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
		Player_PlayAnim(MOTION::walk);
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
		Player_PlayAnim(MOTION::walk);
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
		Player_PlayAnim(MOTION::walk);
	}
	// �L�����̑O��̌������C�����悭���邽��
	else
	{
		m_direction[DIRECTION::left] = false;
		m_direction[DIRECTION::right] = false;
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) == 0)
		{
			moveFlag = false;
			Player_PlayAnim(MOTION::idle);
		}
	}


	/// ����ɑ΂�������Ɠ���--------------------------------------------------
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


// �R���X�g���N�^
Character::Character(const int modelHandle, const int collStageHandle, const int tex0, const int tex1, const int tex2, const int tex3) : BasicCreature(collStageHandle)
{
	// �R�c���f���̓ǂݍ���
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(modelHandle);
	

	// �e�N�X�`���K��
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle3 = -1;
	textureHandle0 = tex0;
	textureHandle1 = tex1;
	textureHandle2 = tex2;
	textureHandle3 = tex3;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, false);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, true);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetTextureGraphHandle(this->modelHandle, 3, textureHandle3, false);


	// �R�c���f����0�Ԗڂ̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::idle;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);


	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ���f���̊�{���
	modelHeight = 160.0f;
	modelWidth = 50.0f;


	// ���f���̌����ƈʒu
	area = VGet(0.0f, 0.0f, 0.0f);
	preArea = area;
	direXAngle = 0.0f;
	direZAngle = 0.0f;


	// �����̉e�Ɋւ���
	shadowHeight = 35.0f;
	shadowSize = 50.0f;


	// ���ꂼ��̑��x
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	ZeroMemory(m_direction, sizeof(m_direction));


	// ���f���̍��W���X�V
	MV1SetPosition(this->modelHandle, area);
}

// �f�X�g���N�^
Character::~Character()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);
	GRAPHIC_RELEASE(textureHandle3);

	MODEL_RELEASE(modelHandle);
}


// ���C���v���Z�X
void Character::Process(const float getAngle)
{
	// ���O�̍��W
	preArea = area;		

	
	// �����Ă�����
	if (moveFlag)
	{
		angle = getAngle;	// �J���������̃A���O��
	}


	// �����̃v���Z�X
	MoveProcess();


	// ���[�V�����̎���
	Player_AnimProcess();


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


// �|�W�V���������Z�b�g����
void Character::PositionReset()
{
	area = VGet(0.0f, 0.0f, 0.0f);
}


// �`��
void Character::Draw()
{
	BasicObject::Draw();


	BasicObject::ShadowFoot();

#ifdef _DEBUG
	if(MyDebug::characterDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);		// �����蔻����m�F�p�̕\���e�X�g
	}
#endif // _DEBUG
}