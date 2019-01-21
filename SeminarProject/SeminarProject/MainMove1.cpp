#include "MainMove1.hpp"


/// -----------------------------------------------------------------------------------------------------
void MainMove1::ActorHit()
{
	for (int i = 0; i < enemyNum; ++i)
	{
		// �������Ă�����
		if (s_lightBall[i].aliveNow)
		{
			// �v���C���[�Ƌʂ��ڐG������
			if (BaseMove::GetDistance<int>(p_character->GetArea()
				, s_lightBall[i].p_enemyMove->GetArea()) <= 60)
			{
				// ���������Ȃ�
				s_lightBall[i].aliveNow = false;
				POINTER_RELEASE(s_lightBall[i].p_enemyMove);
				catchEnemyNum++;


				// ���𗬂��^�C�~���O�������Ȃ̂ł����ŉ�����Ă�
				MoveSoundProcess();
				

				/// ��������Ɋւ���-----------------------------
				if (catchEnemyNum == 1)
				{
					// �u�����h��200�ɂȂ�悤�ɂ���
					nextExplanationDrawFeed = 200;
				}
				else if (catchEnemyNum == 2)
				{
					// �u�����h��150�ɂȂ�悤�ɂ���
					nextExplanationDrawFeed = 150;
				}
				else if (catchEnemyNum == 3)
				{
					// �u�����h��50�ɂȂ�悤�ɂ���
					nextExplanationDrawFeed = 50;
				}
				else if (catchEnemyNum == 4)
				{
					// �u�����h��0�ɂȂ�悤�ɂ���
					nextExplanationDrawFeed = 0;
				}
			} /// if (BaseMove::GetDistance<int>(p_character->GetArea()
			// �v���C���[�ƋʂƂ̋�����������x�߂��Ȃ�����
			else if (BaseMove::GetDistance<int>(p_character->GetArea()
				, s_lightBall[i].p_enemyMove->GetArea()) <= 300)
			{
				// �ʂ��v���C���[�ɋ߂Â��悤�ɂ���
				s_lightBall[i].p_enemyMove->NearChara(p_character->GetArea());
			}
		}
	} /// for (int i = 0; i < enemyNum; ++i)

	
	// �ʂ����ׂĎ�ɓ���A�G���h�C�x���g���I����Ă����ɐG�ꂽ�玟�̃V�[���Ɉڍs������
	if (catchEnemyNum==30 && lightEventCount >= 100
		&& BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem->GetArea()) <= 60)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SECONDLOAD);
	}


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::SECONDLOAD);
	}
#endif
} /// void MainMove1::ActorHit()


/// ---------------------------------------------------------------------------------------------
void MainMove1::LightProcess()
{
	// �����̏����X�V������
	for (int i = 0; i != lightNum; ++i)
	{
		// �����̍L�����X�V
		SetLightRangeAttenHandle(lightHandle[i], lightRange[i], 0.0f, 0.002f, 0.0f);		

		// �����̈ʒu���X�V
		SetLightPositionHandle(lightHandle[i], lightArea[i]);								
	}


	/// �ʂ̌��Ń��C�g�̏󋵂�ω������閽�߂�����-----------------------------
	if (catchEnemyNum == 1)
	{
		// ���C�g����L���ɂ���
		SetLightEnableHandle(lightHandle[0], TRUE);
	}
	else if (catchEnemyNum == 2)
	{
		// ���C�g�����v��L���ɂ���
		SetLightEnableHandle(lightHandle[1], TRUE);
	}
	else if (catchEnemyNum == 3)
	{
		// ���C�g�����v�O�L���ɂ���
		SetLightEnableHandle(lightHandle[2], TRUE);
	}
	else if (catchEnemyNum >= 4 && catchEnemyNum <= 5)
	{
		// �C�x���g�������N���Ă��Ȃ�������
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 7.0f;			// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 1000.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �C�x���g�J�E���g��10�ȏゾ������
		if (lightEventCount >= 10)
		{
			// �l�ڂ̌������o��
			SetLightEnableHandle(lightHandle[3], TRUE);		
		}
	}
	else if (catchEnemyNum <= 6)
	{
		// �G���h�C�x���g�t���b�O�������Ă����炨�낳����
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 7)
	{
		// �C�x���g�������N���Ă��Ȃ�������
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 9.0f;			// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 1700.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}
	}
	else if (catchEnemyNum >= 8 && catchEnemyNum <= 11)
	{
		// �O��N����C�x���g���N���Ă��Ȃ�������
		if (!(lightRangePreMax >= 1699.9f && lightRangePreMax <= 1700.1f))
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 9.0f;			// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 1700.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �G���h�C�x���g�t���b�O�������Ă����炨�낳����
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 12)
	{
		// �C�x���g�������N���Ă��Ȃ�������
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 11.0f;		// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 2600.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �C�x���g����������
		if (lightEventStart)
		{
			// �w�i�F�𖾂邭����
			backgroundColor = GetColor(lightEventCount, lightEventCount, lightEventCount);
		}
	}
	else if (catchEnemyNum >= 13 && catchEnemyNum <= 18)
	{
		// �O��N����C�x���g���N���Ă��Ȃ�������
		if (!(lightRangePreMax >= 2599.9f && lightRangePreMax <= 2600.1f))
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 11.0f;		// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 2600.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �G���h�C�x���g�t���b�O�������Ă����炨�낳����
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 19)
	{
		// �C�x���g�������N���Ă��Ȃ�������
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 14.0f;		// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 3700.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �C�x���g����������
		if (lightEventStart)
		{
			// ���ꂼ���Z���̌������L����
			lightArea[0].z = -630.0f + lightEventCount * 5;
			lightArea[1].z = -630.0f + lightEventCount * 4;
			lightArea[2].z = -630.0f + lightEventCount * 3;
			lightArea[3].z = -630.0f + lightEventCount * 2;

			// �w�i�F�𖾂邭����
			backgroundColor = GetColor(lightEventCount / 2 + 100, lightEventCount / 2 + 100, lightEventCount / 2 + 100);
		}
	}
	else if (catchEnemyNum >= 20 && catchEnemyNum <= 28)
	{
		// �O��N����C�x���g���N���Ă��Ȃ�������
		if (!(lightRangePreMax >= 3699.9f && lightRangePreMax <= 3700.1f))
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 14.0f;		// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 3700.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �G���h�C�x���g�t���b�O�������Ă����炨�낳����
		if (lightEventEnd) lightEventEnd = false;
	}
	else if (catchEnemyNum == 29)
	{
		// �C�x���g�������N���Ă��Ȃ�������
		if (!lightEventStart && !lightEventEnd)
		{
			lightEventCount = 0;			// �C�x���g�̃J�E���g��������
			lightRangeSpeed = 20.0f;		// �����͈͂��L����X�s�[�h��ύX
			lightRangePreMax = 5100.0f;		// ���O�̌����͈͂̍ő�l��ύX
			lightEventStart = true;			// �C�x���g�X�^�[�g���J�n���ꂽ�t���b�O�𗧂Ă�
		}


		// �C�x���g����������
		if (lightEventStart)
		{
			// �w�i�F�𖾂邭����
			backgroundColor = GetColor(lightEventCount / 2 + 150, lightEventCount / 2 + 150, lightEventCount / 2 + 150);
		}
	}
	else if (catchEnemyNum == 30)
	{
		// �I���t���b�O�ŏI��点��
		if (!lightEnd)
		{
			lightEventCount = 0;
			lightEventStart = true;
			lightEnd = true;
		}


		// �C�x���g����������
		if (lightEventStart)
		{
			// �w�i�F�𖾂邭����
			backgroundColor = GetColor(lightEventCount + 155, lightEventCount + 155, lightEventCount + 155);


			// �t�F�[�h�A�E�g�̏����������Ă܂Ԃ�������
			if (lightEventCount < 50)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - (lightEventCount * 2));
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(255, 255, 255), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
			else		// �t�F�[�h�C���̏����������Ė߂�
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 + ((lightEventCount - 50) * 2));
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(255, 255, 255), true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
			}
		}
	}


	// �C�x���g���J�n����
	if (lightEventStart)
	{
		lightEventCount++;		// �J�E���g�𑱂���


		// �����̖��邳���L����
		lightRange[0] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[1] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[2] = lightRangePreMax + lightEventCount * lightRangeSpeed;
		lightRange[3] = lightRangePreMax + lightEventCount * lightRangeSpeed;


		// �J�E���g���K��ȏ�ɂȂ�����
		if (lightEventCount >= 100)
		{
			lightEventStart = false;		// �C�x���g�̊J�n�̃t���O��|��
			lightEventEnd = true;			// �C�x���g�̏I���̃t���O���グ��


			// �S�Ă̋ʂ���ɓ��ꂽ��
			if (catchEnemyNum == 30)
			{
				for (int i = 0; i != lightNum; ++i)
				{
					LIGHT_RELEASE(lightHandle[i]);			// ����������
				}
				SetLightEnable(TRUE);					// ���R������L���ɂ���
				p_character->PositionReset();			// �L�����N�^�[�̃|�W�V���������ɖ߂�
			}
		}
	} /// if (lightEventStart)
} /// void MainMove1::LightProcess()


/// ---------------------------------------------------------------------------------------------
void MainMove1::MoveSoundProcess()
{
	/// �󋵂ɉ�����BGM�̉��ʂ𒲐�----------------------------------------------------------
	switch (catchEnemyNum)
	{
	case 1:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 50, 50);
		break;
	case 2:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 100, 100);
		break;
	case 3:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 150, 150);
		break;
	case 4:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 170, 170);
		break;
	case 5:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 190, 190);
		break;
	case 6:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 210, 210);
		break;
	case 7:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 230, 230);
		break;
	case 8:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 255, 255);
		break;

	case 30:
		SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::titleMusicBox, 0, 0);
		break;
	default:
		break;
	} /// switch (++catchEnemyNum)
	/// ---------------------------------------------------------------------------------------


	/// SE�̍Đ��������_���ɂ���----------------------------------------------------
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randPawnSE(0, 1);        // ����


	if (randPawnSE(mt) == 0)
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
	}
	else
	{
		SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawn);
	}
	/// ----------------------------------------------------------------------------

}


/// ---------------------------------------------------------------------------------------------
MainMove1::MainMove1(const std::vector<int> v_file)
{	
	// ���R��������؎Ւf
	SetLightEnable(FALSE);	
	// �t�H�O��L���ɂ���
	SetFogEnable(FALSE);
	// �w�i�F�Ɋւ���
	backgroundColor = GetColor(0, 0, 0);


	// �|�C���^NULL������
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_dropItem = nullptr;
	for (int i = 0; i != enemyNum; ++i)
	{
		s_lightBall[i].p_enemyMove = nullptr;
	}


	// ���[�u����
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 400;


	// �X�e�[�W������
	p_stage = new Stage(v_file[EFILE::drawStage]);	


	// �L�����N�^�[������
	p_character = new Character(v_file[EFILE::character], v_file[EFILE::collStage]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1]
		, v_file[EFILE::charaTex2], v_file[EFILE::charaTex3]);		
	

	// �J����������
	p_camera = new Camera(p_character->GetArea());
	

	// �����Ă錕������
	p_dropItem = new DropItemMove1(v_file[EFILE::sword], v_file[EFILE::swordTex0]);

	
	/// �ʐ����Ɋւ��鏉����---------------------------------------------------------------
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randInX(-3000, 3000);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-3000, 3000);        // Z���W�p����
	std::uniform_int_distribution<> color(1, 100);				 // �F�p�̗���
	for (int i = 0; i != enemyNum; ++i)
	{
		// �ʂ�X���W�ݒ�
		float tempX = static_cast<float>(randInX(mt));
		if (tempX <= 400.0f && tempX >= 0.0f)
		{
			tempX += 400.0f;
		}
		if (tempX >= -400.0f && tempX <= 0.0f)
		{
			tempX -= 400.0f;
		}
		// �ʂ�Y���W�ݒ�
		float tempZ = static_cast<float>(randInZ(mt));
		if (tempZ <= 400.0f && tempZ >= 0.0f)
		{
			tempZ += 400.0f;
		}
		if (tempZ >= -400.0f && tempZ <= 0.0f)
		{
			tempZ -= 400.0f;
		}


		// �����Ă�悤�ɂ���
		s_lightBall[i].aliveNow = true;
		// �ʏ�����
		s_lightBall[i].p_enemyMove = new EnemyMove1(v_file[1], tempX, tempZ, color(mt) / 100.0f);
	}
	// �ʂ���ɓ��ꂽ����������
	catchEnemyNum = 0;		


	/// ���C�g�Ɋւ��鏉����--------------------------------------------
	for (int i = 0; i != lightNum; ++i)
	{
		lightHandle[i] = -1;						// ���C�g�n���h����������
		lightArea[i] = p_character->GetArea();		// ���C�g�̈ʒu������
		lightRange[i] = 1700.0f;					// ���C�g�͈̔͂�������
		lightArea[0].y = -200.0f;					// ���C�g��0�Ԗڂ���Y���W�����ɏ�����
		lightArea[i].z = -630.0f;					// ���C�g��Z��������

		// ���C�g�𐶐�
		lightHandle[i] = CreatePointLightHandle(lightArea[i], lightRange[i]
			, 0.0f, 0.002f, 0.0f);

		// ���C�g�𖳌��ɂ���
		SetLightEnableHandle(lightHandle[i], FALSE);
	}
	lightEventStart = false;
	lightEventEnd = false;
	lightEventCount = 0;
	lightRangePreMax = 0.0f;
	lightRangeSpeed = 0.0f;
	lightEnd = false;

	
	/// �����Ɋւ��鏉����---------------------------------------
	//  ���X�e�B�b�N����̐����̏�����
	stickLeftDraw = -1;
	stickLeftDraw = v_file[EFILE::explanationLeftStick];
	// �E�X�e�B�b�N����̐����̏�����
	stickRightDraw = -1;
	stickRightDraw = v_file[EFILE::explanationRightStick];
	// �t�F�[�h�J�E���g�̏�����
	explanationDrawFeed = 255;
	nextExplanationDrawFeed = 255;


	/// �T�E���h�̏�����------------------------------------------------------------------------
	SoundProcess::Load(v_file[EFILE::sound]		, SoundProcess::ESOUNDNAME_BGM::titleMusicBox);
	SoundProcess::Load(v_file[EFILE::seBallHigh], SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
	SoundProcess::Load(v_file[EFILE::seBall]	, SoundProcess::ESOUNDNAME_SE::ballPawn);


	// �G�t�F�N�g�ǂݍ���
	effeckBack = LoadEffekseerEffect("media\\������\\media\\Effect\\moveOneBack.efk");
	playingEfBack = -1;
} /// MainMove1::MainMove1(const std::vector<int> v_file)


/// ---------------------------------------------------------------------------------------------
MainMove1::~MainMove1()
{
	// �G�t�F�N�g�J��
	StopEffekseer2DEffect(playingEfBack);
	DeleteEffekseerEffect(effeckBack);


	// �����J��
	for (int i = 0; i != lightNum; ++i)
	{
		LIGHT_RELEASE(lightHandle[i]);
	}


	// �G�J��
	for (int i = 0; i < enemyNum; ++i)
	{
		POINTER_RELEASE(s_lightBall[i].p_enemyMove);
	}


	// �h���b�v�A�C�e��(��)�J��
	POINTER_RELEASE(p_dropItem);


	// �J�����J��
	POINTER_RELEASE(p_camera);

	
	// �L�����N�^�[�J��
	POINTER_RELEASE(p_character);


	// �X�e�[�W�J��
	POINTER_RELEASE(p_stage);


	// �����摜���
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove1::~MainMove1() /// MainMove1::~MainMove1()


/// ---------------------------------------------------------------------------------------------
void MainMove1::Draw()
{
	// �w�i��`��
	DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, backgroundColor, true);


	// �X�e�[�W��`��
	p_stage->Draw();					


	// �L�����N�^�[��`��
	p_character->ModelDraw();
	p_character->Draw();


	for (int i = 0; i < enemyNum; ++i)
	{
		// �ʂ��������Ă�����
		if (s_lightBall[i].aliveNow)
		{
			// �ʂ�`��
			s_lightBall[i].p_enemyMove->Draw();
		}
	}


	// �ʂ����ׂĎ�ɓ���G���h�C�x���g���I�������
	if (catchEnemyNum == 30 && lightEventCount >= 100)
	{
		// ����`��
		p_dropItem->ModelDraw();				
	}


	// �����摜�̌��x��0�ȏゾ������
	if (explanationDrawFeed >= 0)
	{
		// �ő���x���猸���Ă����猸�炷�悤�ɂ���
		if (explanationDrawFeed != nextExplanationDrawFeed) explanationDrawFeed--;


		/// �u�����h����----------------------------------------------
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, explanationDrawFeed);

		// ���X�e�B�b�N�����摜
		DrawGraph(100, 100, stickLeftDraw, true);
		// �E�X�e�B�b�N�����摜
		DrawGraph(1200, 100, stickRightDraw, true);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}


	// �G�t�F�N�g���Đ�����Ă��Ȃ�������
	if (IsEffekseer2DEffectPlaying(playingEfBack) != 0)
	{
		// �G�t�F�N�g���Đ�����B
		playingEfBack = PlayEffekseer2DEffect(effeckBack);
		SetScalePlayingEffekseer2DEffect(playingEfBack, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfBack, 960, 540, 0);
	}


	// ���[�u����������
	if (moveDescriptionFrame-- > 0)
	{
		if(moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 196, 540 - 143, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}


#ifdef _DEBUG
	p_dropItem->Draw();
	if (MyDebug::moveOneDrawFlag)
	{
		for (int i = 0; i < enemyNum; ++i)
		{
			if (BaseMove::GetDistance<int>(p_character->GetArea(), s_lightBall[i].p_enemyMove->GetArea()) <= 500)
			{
				DrawLine3D(VAdd(p_character->GetArea(), VGet(0.0f, 80.0f, 0.0f))
					, VAdd(s_lightBall[i].p_enemyMove->GetArea(), VGet(0.0f, 60.0f, 0.0f)), GetColor(255, 0, 0));
			}
		}
	}
#endif // _DEBUG

} /// void MainMove1::Draw()


/// ---------------------------------------------------------------------------------------------
void MainMove1::Process()
{
	// �L�����N�^�[�̃v���Z�X���Ă�
	p_character->Process(p_camera->GetAngle());		


	// �J�����̃v���Z�X���Ă�
	p_camera->Process(p_character->GetArea());		


	for (int i = 0; i < enemyNum; ++i)
	{
		// �����Ă�����
		if (s_lightBall[i].aliveNow)
		{
			// �ʂ̃v���Z�X���Ă�
			s_lightBall[i].p_enemyMove->Process();
		}
	}


	// �A�N�^�[���Ƃ̂����蔻����Ă�
	ActorHit();		


	// ���C�g�̃v���Z�X���Ă�
	LightProcess();		
} /// void MainMove1::Process()


/// ---------------------------------------------------------------------------------------------
void MainMove1::CameraProcess()
{
	p_camera->SetUp();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModel()
{
	p_character->OptionActorDraw();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


/// ---------------------------------------------------------------------------------------------
void MainMove1::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
