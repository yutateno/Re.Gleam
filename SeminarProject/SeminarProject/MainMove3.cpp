#include "MainMove3.hpp"


// �_���[�W�e�N�X�`���̍����ւ�
void MainMove3::DamageTextureReload()
{
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(damageDraw[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(damageBlend[i]);
	}

	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\D.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\D.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\D.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\D.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\D.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\D.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\D.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\D.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\D.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\D.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\D.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\D.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\D.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\P.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\P.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\P.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\P.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\P.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\P.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\P.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\P.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\P.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\P.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\P.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\P.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\P.pyn", damageBlend[9], ELOADFILE::graph);
		break;

	default:
		LoadFile::MyLoad("media\\������\\media\\damage\\damage1\\normal.pyn", damageDraw[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage2\\normal.pyn", damageDraw[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\damage3\\normal.pyn", damageDraw[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl1\\normal.pyn", damageBlend[0], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl2\\normal.pyn", damageBlend[1], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl3\\normal.pyn", damageBlend[2], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl4\\normal.pyn", damageBlend[3], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl5\\normal.pyn", damageBlend[4], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl6\\normal.pyn", damageBlend[5], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl7\\normal.pyn", damageBlend[6], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl8\\normal.pyn", damageBlend[7], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl9\\normal.pyn", damageBlend[8], ELOADFILE::graph);
		LoadFile::MyLoad("media\\������\\media\\damage\\Blood\\bl10\\normal.pyn", damageBlend[9], ELOADFILE::graph);
		break;
	}
} /// void MainMove3::DamageTextureReload()


// �����@�B�̃v���Z�X
void MainMove3::AdjustmentProcess()
{
	// ����{�^������������
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// �L�[�{�[�h��1�������Ă�����
		if (CheckHitKey(KEY_INPUT_1) == 1)
		{
			// �L�����N�^�[�֌W�̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::charaTextureWhiteBlack)
			{
				// �_���[�W���o
				DamageTextureReload();


				// �L�����N�^�[
				p_character->TextureReload();
				BASICPARAM::charaTextureWhiteBlack = false;
			}
		}
		// �L�[�{�[�h��2�������Ă�����
		if (CheckHitKey(KEY_INPUT_2) == 1)
		{
			// ���̂ق��̃A�N�^�[�̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::anothreTextureWhiteBlack)
			{
				// �����@�B
				p_adjustmentMachine->TextureReload();
				BASICPARAM::anothreTextureWhiteBlack = false;
			}
		}
		// �L�[�{�[�h��3�������Ă�����
		if (CheckHitKey(KEY_INPUT_3) == 1)
		{
			// �G�̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::enemyTextureWhiteBlack)
			{
				BASICPARAM::enemyTextureWhiteBlack = false;
			}
		}
		// �L�[�{�[�h��4�������Ă�����
		if (CheckHitKey(KEY_INPUT_4) == 1)
		{
			// �X���̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::lightStreetTextureWhiteBlack)
			{
				if (BASICPARAM::streetLightNum != 0)
				{
					for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
					{
						vp_stageStreetLight[i]->TextureReload();
					}
				}
				BASICPARAM::lightStreetTextureWhiteBlack = false;
			}
		}
		// �L�[�{�[�h��5�������Ă�����
		if (CheckHitKey(KEY_INPUT_5) == 1)
		{
			// �K�i�Ə��̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::stairsRoadTextureWhiteBlack)
			{
				if (BASICPARAM::stairsRoadNum != 0)
				{
					for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
					{
						vp_stageStairsRoad[i]->TextureReload();
					}
				}
				BASICPARAM::stairsRoadTextureWhiteBlack = false;
			}
		}
		// �L�[�{�[�h��6�������Ă�����
		if (CheckHitKey(KEY_INPUT_6) == 1)
		{
			// �K�i�̃e�N�X�`���𔒍�����߂�
			if (BASICPARAM::stairsTextureWhiteBlack)
			{
				if (BASICPARAM::stairsNum != 0)
				{
					for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
					{
						vp_stageStairs[i]->TextureReload();
					}
				}
				BASICPARAM::stairsTextureWhiteBlack = false;
			}
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)


	// B�{�^���������ꂽ��
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// �����@�B����߂�
		adjustmentFeedNow = true;
		adjustmentStartFeed = false;
	}

	
	// RB�{�^���������ꂽ��p�l����`�悷��
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::SHOULDER_RB) == 1
		&& !BASICPARAM::paneruDrawFlag)
	{
		BASICPARAM::paneruDrawFlag = true;
	}
} /// void MainMove3::AdjustmentProcess()


// �����@�B�̕`��
void MainMove3::AdjustmentDraw()
{
	// �t�F�[�h���I�������
	if (adjustmentSceneFeed >= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, GetColor(247, 247, 247), true);

		DrawFormatString(50, 50, 255, "1: charaTextureWhiteBlack : %s\n", BASICPARAM::charaTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 150, 255, "3: enemyTextureWhiteBlack : %s\n", BASICPARAM::enemyTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 250, 255, "6: stairsTextureWhiteBlack : %s\n", BASICPARAM::stairsTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 350, 255, "5: stairsRoadTextureWhiteBlack : %s\n", BASICPARAM::stairsRoadTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 450, 255, "4: lightStreetTextureWhiteBlack : %s\n", BASICPARAM::lightStreetTextureWhiteBlack ? "true" : "false");
		DrawFormatString(50, 550, 255, "2: anothreTextureWhiteBlack : %s\n", BASICPARAM::anothreTextureWhiteBlack ? "true" : "false");
	}


	// �����@�B�ւ̐؂�ւ��t�F�[�h
	if (adjustmentSceneFeed <= 50)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
	if (adjustmentSceneFeed > 50 && adjustmentSceneFeed <= 100)
	{
		DrawBox(0, 0, BASICPARAM::winWidth, static_cast<int>(108 * (20 - adjustmentSceneFeed / 5)), GetColor(0, 0, 0), true);
	}
}


// �V���h�E�}�b�v�`��
void MainMove3::ShadowDraw()
{
	/// �Z�b�g�A�b�v
	BaseMove::ShadowCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag() || p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag() || p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
	}
	// �L�����N�^�[
	p_character->ModelDraw();


	/// �L�����N�^�[�ȊO�ăZ�b�g�A�b�v
	BaseMove::ShadowAnotherCharaSetUpBefore();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
	}
	BaseMove::ShadowSetUpAfter();


	/// �`��
	BaseMove::ShadowNoMoveDrawBefore();
	BaseMove::ShadowAnotherCharaDrawBefore();
	BaseMove::ShadowCharaDrawBefore();
	// �X�e�[�W
	p_stage->Draw();
	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i]->ModelDraw();
		}
	}
	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i]->ModelDraw();
		}
	}
	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i]->ModelDraw();
		}
	}
	// �p�l��
	if (BASICPARAM::paneruDrawFlag)
	{
		for (int i = 0; i != 10; ++i)
		{
			p_stagePaneru[i]->ModelDraw();
		}
	}
	// �����@�B
	p_adjustmentMachine->ModelDraw();
	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetEraseExistence()) continue;
		p_enemySlime[i]->ModelDraw();
	}
	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetEraseExistence()) continue;
		p_enemyCrayonHuman[i]->ModelDraw();
	}
	// �L�����N�^�[
	p_character->ModelDraw();
	BaseMove::ShadowNoMoveDrawAfter();
	BaseMove::ShadowAnotherCharaDrawAfter();
	BaseMove::ShadowCharaDrawAfter();
	// �L�����N�^�[
	p_character->ModelDraw();
} /// void MainMove3::ShadowDraw()


// �����蔻�菈��
void MainMove3::AttackProcess()
{
	/// �G�ւ̍U���Ɋւ���--------------------------------------------------------------------------------------------------------
	// �N�������q���[�}���Ɋւ���
	for (int i = 0, n = enemyCrayonHumanNum; i != n; ++i)
	{
		// ����ł�����
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		// �v���C���[�̍U�����[�V�������I�������
		if (p_character->GetAttackMotionEnd()) enemyCrayonHumanDamage[i] = false;


		// �_���[�W���󂯂Ă��Ȃ����v���C���[���U������������
		if (p_character->GetAttackNow() && !enemyCrayonHumanDamage[i])
		{
			p_enemyCrayonHuman[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// �U���Ń_���[�W���󂯂���
		if (p_enemyCrayonHuman[i]->GetDamageFlag())
		{
			// �퓬BGM������Ă��Ȃ�������
			if (!nowBattleBGM)
			{
				nowBattleBGM = true;
				SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
			}
			

			// �_���[�W���󂯂Ă���Ƃ���
			enemyCrayonHumanDamage[i] = true;
			// �o�C�u���[�V����������
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);


			// �G�t�F�N�g���Đ�����B
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemyCrayonHumanNum; i != n; ++i)
	// �X���C���Ɋւ���
	for (int i = 0, n = enemySlimeNum; i != n; ++i)
	{
		// ����ł�����
		if (p_enemySlime[i]->GetDeathFlag()) continue;

		
		// �v���C���[�̍U�����I�������
		if (p_character->GetAttackMotionEnd()) enemySlimeDamage[i] = false;


		// �_���[�W���󂯂Ă��Ȃ��ăv���C���[���U������������
		if (p_character->GetAttackNow() && !enemySlimeDamage[i])
		{
			p_enemySlime[i]->HitLineReturn(p_character->GetAttackFirstFrameArea(), p_character->GetAttackEndFrameArea());
		}


		// �U���Ń_���[�W���󂯂���
		if (p_enemySlime[i]->GetDamageFlag())
		{
			// �퓬BGM������Ă��Ȃ�������
			if (!nowBattleBGM)
			{
				nowBattleBGM = true;
				SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
			}


			// �_���[�W���󂯂Ă���
			enemySlimeDamage[i] = true;
			// �o�C�u���[�V����������
			DLLXinput::Vibration(DLLXinput::GetPlayerPadNumber(), 30, 7500, 7500);


			// �G�t�F�N�g���Đ�����B
			playingEfAttack = PlayEffekseer3DEffect(effectAttack);
			SetScalePlayingEffekseer3DEffect(playingEfAttack, 10, 10, 10);
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer3DEffect(playingEfAttack, p_character->GetAttackEndFrameArea().x
				, p_character->GetAttackEndFrameArea().y, p_character->GetAttackEndFrameArea().z);
		}
	} /// for (int i = 0, n = enemySlimeNum; i != n; ++i)
	/// �G�ւ̍U���Ɋւ���--------------------------------------------------------------------------------------------------------


	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------
	// �v���C���[���������Ă����Ƃ�
	if (HitCheck_Capsule_Capsule(
		p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()
		, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
	{
		// �v���C���[�������o��
		p_character->HitCircleReturn(p_adjustmentMachine->GetArea()
			, p_adjustmentMachine->GetWidth() >= p_character->GetWidth() ? p_adjustmentMachine->GetWidth() : p_character->GetWidth());
	}
	// �X���C���Ɋւ���
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// �X���C���Ƃ̋������Ԃ��鋗����������
		if (BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;


		// �X���C�����������Ă����Ƃ�
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// �X���C���������o��
			p_enemySlime[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemySlime[i]->GetWidth());
		}
	}
	// �N�������q���[�}���Ɋւ���
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// �N�������q���[�}���Ƃ̋������Ԃ��鋗����������
		if (BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_adjustmentMachine->GetArea()) > 250) continue;


		// �N�������q���[�}�����������Ă����Ƃ�
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
			, p_adjustmentMachine->GetArea(), VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, p_adjustmentMachine->GetHeight(), 0.0f)), p_adjustmentMachine->GetWidth()))
		{
			// �N�������q���[�}���������o��
			p_enemyCrayonHuman[i]->HitCircleReturn(p_adjustmentMachine->GetArea()
				, p_adjustmentMachine->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_adjustmentMachine->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
		}
	}
	// �v���C���[�Ƃ̋������߂��āA�G���{�^����������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175
		&& !p_character->GetAttackNow() && p_character->GetArea().y <= 10.0f
		&& DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// �����@�B�ւ̃V�[���փt�F�[�h����
		adjustmentFeedNow = true;
		adjustmentStartFeed = true;
		changeAdjustmentScene = true;
	}
	// �v���C���[���߂����ǂ����Ō����ڂ�ς���
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 250)
	{
		p_adjustmentMachine->ChangeDisplayTexture(true);
	}
	else
	{
		p_adjustmentMachine->ChangeDisplayTexture(false);
	}
	/// ���Z�@�B�Ɋւ���-------------------------------------------------------------------------------------------------------------------


	/// �L�����N�^�[���牟���o�����-------------------------------------------------------------------------------------------------------
	// �X���C���Ɋւ���
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// ����ł��邩�v���C���[�Ƃ̋������߂��ł͂Ȃ�������
		if (p_enemySlime[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// �v���C���[�Ɠ������Ă�����
		if (HitCheck_Capsule_Capsule(
			p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// �X���C���������o��
			p_enemySlime[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_character->GetWidth() : p_enemySlime[i]->GetWidth());
		}
	}
	// �N�������q���[�}���Ɋւ���
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// ����ł��邩�v���C���[�Ƃ̋������߂��ł͂Ȃ�������
		if (p_enemyCrayonHuman[i]->GetDeathFlag()
			|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_character->GetArea()) > 250) continue;


		// �v���C���[�Ɠ������Ă�����
		if (HitCheck_Capsule_Capsule(
			p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth(),
			p_character->GetArea(), VAdd(p_character->GetArea(), VGet(0.0f, p_character->GetHeight(), 0.0f)), p_character->GetWidth()))
		{
			// �N�������q���[�}���������o��
			p_enemyCrayonHuman[i]->HitCircleReturn(p_character->GetArea()
				, p_character->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_character->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
		}
	}
	/// �L�����N�^�[���牟���o�����-------------------------------------------------------------------------------------------------------


	/// �G���m�ŉ����o��---------------------------------------------------------------------------------------------------------------------
	// ��̂��X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// ����ł�����
		if (p_enemySlime[i]->GetDeathFlag()) continue;


		// ���肪�X���C��
		for (int j = 0; j != enemySlimeNum; ++j)
		{
			// �����Ǝ����ōs�킹�Ȃ����X���C��������ł��邩����������������
			if (i == j || p_enemySlime[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;


			// �������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth(),
				p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				// �����������o�����
				p_enemySlime[i]->HitCircleReturn(p_enemySlime[j]->GetArea(), p_enemySlime[j]->GetWidth());
			}
		} /// for (int j = 0; j != enemySlimeNum; ++j)
		

		// ���肪�N�������q���[�}��
		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			// ����ł��邩����������������
			if (p_enemyCrayonHuman[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemySlime[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;


			// �������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_enemySlime[i]->GetArea(), VAdd(p_enemySlime[i]->GetArea(), VGet(0.0f, p_enemySlime[i]->GetHeight(), 0.0f)), p_enemySlime[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[j]->GetHeight(), 0.0f)), p_enemyCrayonHuman[j]->GetWidth()))
			{
				// �����������o�����
				p_enemySlime[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea()
					, p_enemyCrayonHuman[j]->GetWidth() >= p_enemySlime[i]->GetWidth() ? p_enemyCrayonHuman[j]->GetWidth() : p_enemySlime[i]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemySlimeNum; ++i)
	// ��̂��N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// ����ł�����
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		// ���肪�N�������q���[�}��
		for (int j = 0; j != enemyCrayonHumanNum; ++j)
		{
			// �����Ǝ����ł͍s��Ȃ�������ł����炩����������������
			if (i == j || p_enemyCrayonHuman[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_enemyCrayonHuman[j]->GetArea()) > 250) continue;


			// �������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemyCrayonHuman[j]->GetArea(), VAdd(p_enemyCrayonHuman[j]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()))
			{
				// �����������o��
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemyCrayonHuman[j]->GetArea(), p_enemyCrayonHuman[i]->GetWidth());
			}
		} /// for (int j = 0; j != enemyCrayonHumanNum; ++j)
		// ���肪�X���C��
		for (int j = 0; j != enemySlimeNum; ++j)
		{
			// ����ł��邩����������������
			if (p_enemySlime[j]->GetDeathFlag()
				|| BaseMove::GetDistance<int>(p_enemyCrayonHuman[i]->GetArea(), p_enemySlime[j]->GetArea()) > 250) continue;


			// �������Ă�����
			if (HitCheck_Capsule_Capsule(
				p_enemyCrayonHuman[i]->GetArea(), VAdd(p_enemyCrayonHuman[i]->GetArea(), VGet(0.0f, p_enemyCrayonHuman[i]->GetHeight(), 0.0f)), p_enemyCrayonHuman[i]->GetWidth()
				, p_enemySlime[j]->GetArea(), VAdd(p_enemySlime[j]->GetArea(), VGet(0.0f, p_enemySlime[j]->GetHeight(), 0.0f)), p_enemySlime[j]->GetWidth()))
			{
				// �����������o��
				p_enemyCrayonHuman[i]->HitCircleReturn(p_enemySlime[j]->GetArea()
					, p_enemySlime[j]->GetWidth() >= p_enemyCrayonHuman[i]->GetWidth() ? p_enemySlime[j]->GetWidth() : p_enemyCrayonHuman[i]->GetWidth());
			}
		}
	} /// for (int i = 0; i != enemyCrayonHumanNum; ++i)
	/// �G���m�ŉ����o��---------------------------------------------------------------------------------------------------------------------


	/// �h���b�v�Ɋւ���--------------------------------------------------------------------------------------
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		// �h���b�v����ɓ�������Ԃł͂Ȃ�������
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive() || !p_dropItem[i]->GetCanCatch()) continue;


		// �v���C���[�Ƃ̋������߂Â��鋗����������
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 500)
		{
			p_dropItem[i]->ChaseActor(p_character->GetArea());
		}


		// �v���C���[���E���鋗����������
		if (BaseMove::GetDistance<int>(p_character->GetArea(), p_dropItem[i]->GetArea()) <= 75)
		{
			catchDropItemNum++;
			p_dropItem[i]->SetDeath(true);			// ���������Ȃ�


			/// SE�̍Đ��������_���ɂ���-----------------------------------------------------------------------------
			std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
			std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
			std::uniform_int_distribution<> randPawnSE(0, 1);        // ����

			if (randPawnSE(mt) == 0)
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp, p_dropItem[i]->GetArea());
			}
			else
			{
				SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPickUp2, p_dropItem[i]->GetArea());
			}
			/// -----------------------------------------------------------------------------------------------------
		}
	}
} /// void MainMove3::AttackProcess()


// �񓯊����[�h
void MainMove3::ThsTextureReload()
{
	ths = std::thread(&MainMove3::TextureReload, this);
	ths.join();
}


// �R���X�g���N�^
MainMove3::MainMove3(const std::vector<int> v_file)
{
	// �p�l�����\���ɂ���
	BASICPARAM::paneruDrawFlag = false;
	BASICPARAM::charaTextureWhiteBlack = true;
	BASICPARAM::anothreTextureWhiteBlack = true;
	BASICPARAM::enemyTextureWhiteBlack = true;
	BASICPARAM::lightStreetTextureWhiteBlack = true;
	BASICPARAM::stairsRoadTextureWhiteBlack = true;
	BASICPARAM::stairsTextureWhiteBlack = true;


	// �|�C���^NULL������
	p_camera = nullptr;
	p_character = nullptr;
	p_stage = nullptr;
	p_adjustmentMachine = nullptr;
	p_stage = nullptr;
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = nullptr;
	}
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		p_enemySlime[i] = nullptr;
	}
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		p_enemyCrayonHuman[i] = nullptr;
	}
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		p_dropItem[i] = nullptr;
	}
	vp_stageStairs.clear();
	vp_stageStairsRoad.clear();
	vp_stageStreetLight.clear();


	// ���[�u����
	moveDescriptionDraw = v_file[EFILE::moveDescription];
	moveDescriptionFrame = 750;


	// �X�e�[�W�̏�����
	p_stage = new Stage(v_file[EFILE::stageDrawModel]);


	// �L�����N�^�[�̏�����
	p_character = new CharacterSword(v_file[EFILE::charaModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel]
		, v_file[EFILE::paneruModel], v_file[EFILE::stairsRoadCollModel]
		, v_file[EFILE::charaTex0], v_file[EFILE::charaTex1], v_file[EFILE::charaTex2], v_file[EFILE::charaTex3], v_file[EFILE::charaTex4]);
	charaSomeEnemyDamageCount = 0;


	// �J�����̏�����
	p_camera = new Camera(p_character->GetArea());


	// �p�l���̏�����
	for (int i = 0; i != 10; ++i)
	{
		p_stagePaneru[i] = new StagePaneru(v_file[EFILE::paneruModel], VGet(500.0f * i, 300.0f * i, 100.0f * i));
		p_character->SetPaneruArea(p_stagePaneru[i]->GetArea(), i);
	}


	// �K�i�Ə��̏�����
	if (BASICPARAM::stairsRoadNum != 0)
	{
		vp_stageStairsRoad.resize(BASICPARAM::stairsRoadNum + 1);
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			vp_stageStairsRoad[i] = nullptr;
			vp_stageStairsRoad[i] = new StageStairsRoad(v_file[EFILE::stairsRoadDrawModel], BASICPARAM::v_stairsRoadArea[i]
				, v_file[EFILE::stairsRoadTex0], v_file[EFILE::stairsRoadTex1], BASICPARAM::v_stairsRoadAngle[i]);
			p_character->SetStairsRoadArea(vp_stageStairsRoad[i]->GetArea(), i, BASICPARAM::v_stairsRoadAngle[i]);
		}
	}


	// �X���̏�����
	if (BASICPARAM::streetLightNum != 0)
	{
		vp_stageStreetLight.resize(BASICPARAM::streetLightNum + 1);
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			vp_stageStreetLight[i] = nullptr;
			vp_stageStreetLight[i] = new StageStreetLight(v_file[EFILE::streetLightModel], BASICPARAM::v_streetLightArea[i]
				, v_file[EFILE::streetLightTex0], v_file[EFILE::streetLightTex1], BASICPARAM::v_streetLightAngle[i]);
		}
	}


	// �K�i�̏�����
	if (BASICPARAM::stairsNum != 0)
	{
		vp_stageStairs.resize(BASICPARAM::stairsNum + 1);
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			vp_stageStairs[i] = nullptr;
			vp_stageStairs[i] = new StageStairs(v_file[EFILE::stairsDrawModel], BASICPARAM::v_stairsArea[i], v_file[EFILE::stairsTex0], BASICPARAM::v_stairsAngle[i]);
			p_character->SetStairsArea(vp_stageStairs[i]->GetArea(), i, BASICPARAM::v_stairsAngle[i]);
		}
	}


	// �����@�B�̏�����
	p_adjustmentMachine = new AdjustmentMachine(v_file[EFILE::terminalModel], VGet(-1000.0f, 0.0f, -500.0f), v_file[EFILE::terminalTex0], v_file[EFILE::terminalTex1]);
	for (int i = 0; i != 15; ++i)
	{
		p_adjustmentMachine->CatchDropItem();
	}
	adjustmentDescDraw = v_file[EFILE::terminalDesc];
	changeAdjustmentScene = false;
	adjustmentSceneFeed = 0;
	adjustmentFeedNow = false;


	// �G�X���C���̏�����
	std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
	std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
	std::uniform_int_distribution<> randInX(-4000, 4000);        // X���W�p����
	std::uniform_int_distribution<> randInZ(-4000, 4000);        // Z���W�p����
	for (int i = 0; i != enemySlimeNum; ++i)
	{
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
		p_enemySlime[i] = new EnemyMove3Slime(v_file[EFILE::slimeModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::slimeTex0], VGet(tempX, 0.0f, tempZ), 0.0f);
		enemySlimeDamage[i] = false;
	}

	// �G�N�������q���[�}���̏�����
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
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
		p_enemyCrayonHuman[i] = new EnemyMove3CrayonHuman(v_file[EFILE::crayonHumanModel], v_file[EFILE::stageCollModel], v_file[EFILE::stairsCollModel], v_file[EFILE::stairsRoadCollModel]
			, v_file[EFILE::crayonHumanTex0], VGet(tempX, 0.0f, tempZ), 0.0f);
		enemyCrayonHumanDamage[i] = false;
	}
	mostNearEnemyDistance = 10000;
	lockONNowEnemyID = 0;
	lockOnEnemySlime = false;


	// �h���b�v�A�C�e���̏�����
	catchDropItemNum = 0;
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		p_dropItem[i] = new DropItemMove3(v_file[EFILE::dropItemModel], p_character->GetArea(), v_file[EFILE::dropItemTex0]);
	}


	// �X�J�C�{�b�N�X
	BaseMove::SetInitSkyBox(v_file[EFILE::skyBoxModel], v_file[EFILE::skyBoxTex0]);


	// �X�e�[�W�̏�
	BaseMove::ShadowNoMoveSetUpBefore();
	p_stage->Draw();
	BaseMove::ShadowSetUpAfter();


	// �T�E���h�̃��[�h
	nowBattleBGM = false;
	SoundProcess::Load(v_file[EFILE::se_attackOne], SoundProcess::ESOUNDNAME_SE::pianoAttack1);
	SoundProcess::Load(v_file[EFILE::se_attackThrid], SoundProcess::ESOUNDNAME_SE::pianoAttack3);
	SoundProcess::Load(v_file[EFILE::se_attackTwo], SoundProcess::ESOUNDNAME_SE::pianoAttack2);
	SoundProcess::Load(v_file[EFILE::se_ballPickUp], SoundProcess::ESOUNDNAME_SE::ballPickUp);
	SoundProcess::Load(v_file[EFILE::se_ballPickUp2], SoundProcess::ESOUNDNAME_SE::ballPickUp2);
	SoundProcess::Load(v_file[EFILE::se_foot], SoundProcess::ESOUNDNAME_SE::foot);
	SoundProcess::Load(v_file[EFILE::se_footCorridor], SoundProcess::ESOUNDNAME_SE::footFloor);
	SoundProcess::Load(v_file[EFILE::se_jump], SoundProcess::ESOUNDNAME_SE::jump);
	SoundProcess::Load(v_file[EFILE::se_landing], SoundProcess::ESOUNDNAME_SE::landing);
	SoundProcess::Load(v_file[EFILE::se_landingSecond], SoundProcess::ESOUNDNAME_SE::landing2);
	SoundProcess::Load(v_file[EFILE::bgm_Main], SoundProcess::ESOUNDNAME_BGM::normalBGM);
	SoundProcess::Load(v_file[EFILE::enemyAttackSE], SoundProcess::ESOUNDNAME_SE::strikeBomb);
	SoundProcess::Load(v_file[EFILE::crayonDeadSE], SoundProcess::ESOUNDNAME_SE::crayonDie);
	SoundProcess::Load(v_file[EFILE::fightBGM], SoundProcess::ESOUNDNAME_BGM::battleBGM);

	//SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::battleBGM, 0, 0);
	SoundProcess::SetBGMVolume(SoundProcess::ESOUNDNAME_BGM::normalBGM, 255, 255);


	// �_���[�W���o
	damageCount = 0;
	preDamageCount = damageCount;
	notDamageCount = 101;
	damageDrawFrame = 0;
	damageDrawID = 0;
	damageDraw[0] = v_file[EFILE::damageDraw0];
	damageDraw[1] = v_file[EFILE::damageDraw1];
	damageDraw[2] = v_file[EFILE::damageDraw2];
	damageBlend[0] = v_file[EFILE::damageBlood0];
	damageBlend[1] = v_file[EFILE::damageBlood1];
	damageBlend[2] = v_file[EFILE::damageBlood2];
	damageBlend[3] = v_file[EFILE::damageBlood3];
	damageBlend[4] = v_file[EFILE::damageBlood4];
	damageBlend[5] = v_file[EFILE::damageBlood5];
	damageBlend[6] = v_file[EFILE::damageBlood6];
	damageBlend[7] = v_file[EFILE::damageBlood7];
	damageBlend[8] = v_file[EFILE::damageBlood8];
	damageBlend[9] = v_file[EFILE::damageBlood9];


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
	playingEfDamage = -1;
	effectAttack = LoadEffekseerEffect("media\\������\\media\\Effect\\characterAttack.efk");
	playingEfAttack = -1;
} /// MainMove3::MainMove3(const std::vector<int> v_file)


// �f�X�g���N�^
MainMove3::~MainMove3()
{
	// �G�t�F�N�g�J��
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);


	// �_���[�W���o
	StopEffekseer2DEffect(playingEfDamage);
	for (int i = 0; i != 10; ++i)
	{
		DeleteEffekseerEffect(effeckBack[i]);
	}
	for (int i = 0; i != 3; ++i)
	{
		GRAPHIC_RELEASE(damageDraw[i]);
	}
	for (int i = 0; i != 10; ++i)
	{
		GRAPHIC_RELEASE(damageBlend[i]);
	}


	// �h���b�v�A�C�e��
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		POINTER_RELEASE(p_dropItem[i]);
	}


	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		POINTER_RELEASE(p_enemyCrayonHuman[i]);
	}


	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		POINTER_RELEASE(p_enemySlime[i]);
	}


	// �����@�B
	GRAPHIC_RELEASE(adjustmentDescDraw);
	POINTER_RELEASE(p_adjustmentMachine);


	// �K�i
	if (BASICPARAM::stairsNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairs[i]);
		}
		vp_stageStairs.clear();
		vp_stageStairs.shrink_to_fit();
	}


	// �X��
	if (BASICPARAM::streetLightNum != 0)
	{
		for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStreetLight[i]);
		}
		vp_stageStreetLight.clear();
		vp_stageStreetLight.shrink_to_fit();
	}


	// �K�i�Ə�
	if (BASICPARAM::stairsRoadNum != 0)
	{
		for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
		{
			POINTER_RELEASE(vp_stageStairsRoad[i]);
		}
		vp_stageStairsRoad.clear();
		vp_stageStairsRoad.shrink_to_fit();
	}


	// �p�l��
	for (int i = 0; i != 10; ++i)
	{
		POINTER_RELEASE(p_stagePaneru[i]);
	}


	// �J����
	POINTER_RELEASE(p_camera);


	// �L�����N�^�[
	POINTER_RELEASE(p_character);


	// �X�e�[�W
	POINTER_RELEASE(p_stage);


	/// �����摜���
	GRAPHIC_RELEASE(moveDescriptionDraw);
} /// MainMove3::~MainMove3()


// �`��
void MainMove3::Draw()
{
	BaseMove::SkyBoxDraw();		// �X�J�C�{�b�N�X�̕`��


	ShadowDraw();		// �V���h�E�}�b�v�̕`��


	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		// ����ł�����
		if (p_enemySlime[i]->GetDeathFlag()) continue;


		p_enemySlime[i]->Draw();
	}


	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		// ����ł�����
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


		p_enemyCrayonHuman[i]->Draw();
	}


	// �h���b�v�A�C�e��
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		// ��ɓ�������Ԃ���Ȃ�������
		if (p_dropItem[i]->GetDeath() || !p_dropItem[i]->GetAlive()) continue;


		p_dropItem[i]->ModelDraw();
	}


	// �L�����N�^�[
	p_character->Draw();


	// �����@�B�Ƌ������߂�������
	if (BaseMove::GetDistance<int>(p_character->GetArea(), p_adjustmentMachine->GetArea()) <= 175)
	{
		// �����@�B�̐����摜
		DrawBillboard3D(VAdd(p_adjustmentMachine->GetArea(), VGet(0.0f, 200.0f, 0.0f)), 0.5f, 0.5f, 300.0f, 0.0f, adjustmentDescDraw, false);
	}


	/// ���b�N�I���Ɋւ���------------------------------------------------------------------------------------------------------------
	// �v���C���[�Ƌ߂��G�Ƀ��b�N�I���̕`�������
	if (mostNearEnemyDistance <= 1000)
	{
		// ���b�N�I���Ώۂ��X���C����������
		if (lockOnEnemySlime)
		{
			// ���݂��Ă�����
			if (!p_enemySlime[lockONNowEnemyID]->GetEraseExistence())
			{
				// �U���͈͓���������
				if (mostNearEnemyDistance < 250)
				{
					// ���_
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
					// �c�_
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
				}
				// �U���͈͊O��������
				else
				{
					// ���_
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f)
						, static_cast<int>(mostNearEnemyScreenArea.y - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
					// �c�_
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x)
						, static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemySlime[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
				}
			}
		} /// if (lockOnEnemySlime)
		// ���b�N�I���Ώۂ��N�������q���[�}����������
		else
		{
			// ���݂��Ă�����
			if (!p_enemyCrayonHuman[lockONNowEnemyID]->GetEraseExistence())
			{
				// �U���͈͓���������
				if (mostNearEnemyDistance < 250)
				{
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(255, 255, 255), false);
				}
				// �U���͈͊O��������
				else
				{
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x - 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x + 20.0f), static_cast<int>(mostNearEnemyScreenArea.y - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
					DrawBox(static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y - 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f)
						, static_cast<int>(mostNearEnemyScreenArea.x), static_cast<int>(mostNearEnemyScreenArea.y + 20.0f - p_enemyCrayonHuman[lockONNowEnemyID]->GetHeight() / 2.0f), GetColor(125, 125, 125), false);
				}
			}
		} /// else(!if (lockOnEnemySlime))
	} /// if (mostNearEnemyDistance <= 1000)
	/// ���b�N�I���Ɋւ���------------------------------------------------------------------------------------------------------------


	/// �_���[�W�Ɋւ���-----------------------------------------------------------------------------------------------------------
	/// �G�t�F�N�g���Đ�����-------------------------------------------------------------------------------
	if (preDamageCount != damageCount / 10)
	{
		// �_���[�W�J�E���g��10�̔{���Ŏ����O�̃G�t�F�N�g�ɐ؂�ւ���
		preDamageCount = damageCount / 10;


		// �G�t�F�N�g���Đ�����������
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);


		// �G�t�F�N�g���Đ�����
		playingEfDamage = PlayEffekseer2DEffect(effeckBack[preDamageCount - 1]);
		SetScalePlayingEffekseer2DEffect(playingEfDamage, 100, 100, 100);
		SetPosPlayingEffekseer2DEffect(playingEfDamage, 960, 540, 0);
	}
	// �_���[�W���󂯂Ă��Ȃ�������
	if (damageCount == 0)
	{
		// �G�t�F�N�g���~�߂�
		if (IsEffekseer2DEffectPlaying(playingEfDamage) == 0) StopEffekseer2DEffect(playingEfDamage);
	}
	/// �G�t�F�N�g���Đ�����-------------------------------------------------------------------------------


	/// �_���[�W�̉��o
	if (damageDrawFrame > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageDrawFrame * 25.5));
		DrawGraph(0, 0, damageDraw[damageDrawID], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}


	/// �_���[�W�̒~�ςŉ�ʂ𖄂ߐs��������-----------------------------------------------
	if (damageCount > 0)
	{
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(damageCount * 25.5));
		DrawGraph(0, 0, damageBlend[0], true);
		if (damageCount <= 10) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 10)
	{
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 10) * 25.5));
		DrawGraph(0, 0, damageBlend[1], true);
		if (damageCount <= 20) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 20)
	{
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 20) * 25.5));
		DrawGraph(0, 0, damageBlend[2], true);
		if (damageCount <= 30) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 30)
	{
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 30) * 25.5));
		DrawGraph(0, 0, damageBlend[3], true);
		if (damageCount <= 40) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 40)
	{
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 40) * 25.5));
		DrawGraph(0, 0, damageBlend[4], true);
		if (damageCount <= 50) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 50)
	{
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 50) * 25.5));
		DrawGraph(0, 0, damageBlend[5], true);
		if (damageCount <= 60) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 60)
	{
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 60) * 25.5));
		DrawGraph(0, 0, damageBlend[6], true);
		if (damageCount <= 70) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 70)
	{
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 70) * 25.5));
		DrawGraph(0, 0, damageBlend[7], true);
		if (damageCount <= 80) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 80)
	{
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 80) * 25.5));
		DrawGraph(0, 0, damageBlend[8], true);
		if (damageCount <= 90) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (damageCount > 90)
	{
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>((damageCount - 90) * 25.5));
		DrawGraph(0, 0, damageBlend[9], true);
		if (damageCount <= 100) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	/// �_���[�W�̒~�ςŉ�ʂ𖄂ߐs��������-----------------------------------------------
	/// �_���[�W�Ɋւ���-----------------------------------------------------------------------------------------------------------



	DrawFormatString(1020, 20, GetColor(0, 0, 0), "��ɓ��ꂽ�h���b�v�A�C�e���̐�: %d", catchDropItemNum);


	AdjustmentDraw();		// �����@�B�̕`��


	// ���[�u����������
	if (moveDescriptionFrame-- > 0)
	{
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_ALPHA, moveDescriptionFrame);
		DrawGraph(960 - 268, 540 - 146 - 73, moveDescriptionDraw, true);
		if (moveDescriptionFrame < 255) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
} /// void MainMove3::Draw()


// �v���Z�X
void MainMove3::Process()
{
	// �����@�B�̃V�[������Ȃ�������
	if (!changeAdjustmentScene)
	{
		// �L�����N�^�[�̃v���Z�X
		p_character->Process(p_camera->GetAngle());
		charaSomeEnemyDamageCount = 0;					// ���̂̓G���瓯���Ƀ_���[�W���󂯂Ă��邩�擾���鐔�l


		/// �_���[�W���󂯂Ă��Ȃ��J�E���g���ŏ���---------------------------------------------------------
		notDamageCount++;


		// �_���[�W���󂯂Ă��Ȃ�������񕜂�����
		if (notDamageCount > 100 && damageCount > 0 && (notDamageCount - 100) % 10 == 0) damageCount--;

		
		// �_���[�W���o�摜���c���Ă����炾�񂾂����
		if (damageDrawFrame > 0) damageDrawFrame--;


		// �퓬BGM��������ʏ�BGM�ɐ؂�ւ���
		if (notDamageCount > 100 && nowBattleBGM)
		{
			nowBattleBGM = false;
			SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::normalBGM);
		}
		/// �_���[�W���󂯂Ă��Ȃ��J�E���g���ŏ���---------------------------------------------------------


		// �J�����̃v���Z�X
		p_camera->Process(p_character->GetArea());


		// �h���b�v�A�C�e��
		for (int i = 0, n = dropItemNum; i != n; ++i)
		{
			// ����ł�����
			if (p_dropItem[i]->GetDeath()) continue;
			p_dropItem[i]->Process();
		}


		/// �X���C���̃v���Z�X�Ɋւ���-------------------------------------------------------------------------------------------------------------------------------
		// �G�X���C���̃v���Z�X
		for (int i = 0; i != enemySlimeNum; ++i)
		{
			// ���ł�����
			if (p_enemySlime[i]->GetEraseExistence())
			{
				// ���b�N�I���Ώۂ�������
				if (i == lockONNowEnemyID && lockOnEnemySlime)
				{
					// ���b�N�I�����珜�O����
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// �h���b�v�A�C�e���𗎂Ƃ�
				if (!p_dropItem[(i * 5)]->GetDeath() && !p_dropItem[(i * 5)]->GetAlive()) p_dropItem[(i * 5)]->SetAlive(p_enemySlime[i]->GetArea());
				else continue;
				if (!p_dropItem[(i * 5) + 1]->GetDeath() && !p_dropItem[(i * 5) + 1]->GetAlive()) p_dropItem[(i * 5) + 1]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 2]->GetDeath() && !p_dropItem[(i * 5) + 2]->GetAlive()) p_dropItem[(i * 5) + 2]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 3]->GetDeath() && !p_dropItem[(i * 5) + 3]->GetAlive()) p_dropItem[(i * 5) + 3]->SetAlive(p_enemySlime[i]->GetArea());
				if (!p_dropItem[(i * 5) + 4]->GetDeath() && !p_dropItem[(i * 5) + 4]->GetAlive()) p_dropItem[(i * 5) + 4]->SetAlive(p_enemySlime[i]->GetArea());
				continue;
			}


			// �v���Z�X���Ă�
			p_enemySlime[i]->Process();


			// ����ł�����
			if (p_enemySlime[i]->GetDeathFlag()) continue;


			// ���b�N�I���Ώۂ��X���C����������
			if (lockOnEnemySlime)
			{
				// ���݂̃��b�N�I���Ώۂ��߂�������
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()))
				{
					// ���b�N�I���Ώۂ����̃X���C���ɍX�V����
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemySlime[i]->GetArea());
					lockONNowEnemyID = i;


					// �X�V�����Ώۂ��v���C���[���王�F�ł���͈͂�������
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemySlime[i]->GetArea());
					}
					// �X�V�����Ώۂ��v���C���[���王�F�ł��Ȃ��͈͂�������
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}
			// ���b�N�I���Ώۂ��N�������q���[�}����������
			else
			{
				// ���݂̃��b�N�I���Ώۂ��߂�������
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()))
				{
					// ���b�N�I���Ώۂ��X�V����
					lockOnEnemySlime = true;
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemySlime[i]->GetArea());
					lockONNowEnemyID = i;


					// �X�V�����Ώۂ��v���C���[���王�F�ł���͈͂�������
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemySlime[i]->GetArea());
					}
					// �X�V�����Ώۂ��v���C���[���王�F�ł��Ȃ��͈͂�������
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}


			// �v���C���[�̏ꏊ�Ƌ������X�V����
			p_enemySlime[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[i]->GetArea()));


			// �v���C���[���U���o������
			if (p_enemySlime[i]->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemySlime[i]->GetArea().y + p_enemySlime[i]->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemySlime[i]->GetArea().y)
			{
				// �퓬BGM����Ȃ�������
				if (!nowBattleBGM)
				{
					// �퓬BGM�𗬂�
					nowBattleBGM = true;
					SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
				}


				// �v���C���[���U�����Ă���̐���2�ȉ���������
				if (charaSomeEnemyDamageCount++ < 2)
				{
					// �U��SE�𗬂�
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemySlime[i]->GetArea(), 180);


					p_character->SetDamage();					// �v���C���[�Ƀ_���[�W���󂯂�����


					// �v���C���[�̃_���[�W���󂯂Ă��Ȃ��J�E���g��0����Ȃ�������
					if(notDamageCount != 0) notDamageCount = 0;


					// �v���C���[�̃_���[�W���l��100�ȉ���������
					if (damageCount < 100)	damageCount++;


					// �_���[�W���o�摜���o�Ă��Ȃ�������
					if (damageDrawFrame == 0)
					{
						std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
						std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
						std::uniform_int_distribution<> blood(0, 2);        // X���W�p����
						damageDrawID = blood(mt);		// ��������摜��I��
						damageDrawFrame = 10;			// 10�t���[���o���悤�ɂ���
					}
				}
			}
		} /// for (int i = 0; i != enemySlimeNum; ++i)
		/// �X���C���̃v���Z�X�Ɋւ���-------------------------------------------------------------------------------------------------------------------------------


		/// �N�������q���[�}���̃v���Z�X�Ɋւ���--------------------------------------------------------------------------------------------------------------------
		// �G�N�������q���[�}���̃v���Z�X
		for (int i = 0; i != enemyCrayonHumanNum; ++i)
		{
			// ���ł��Ă�����
			if (p_enemyCrayonHuman[i]->GetEraseExistence())
			{
				// ���b�N�I���Ώۂ�������
				if (i == lockONNowEnemyID && !lockOnEnemySlime)
				{
					// ���O����
					mostNearEnemyDistance = 10000;
					lockONNowEnemyID = 0;
					p_character->SetMostNearEnemyArea();
				}


				// �h���b�v�A�C�e�����o��
				int temp = enemySlimeNum * 5;
				if (!p_dropItem[(i * 5) + temp]->GetDeath() && !p_dropItem[(i * 5) + temp]->GetAlive()) p_dropItem[(i * 5) + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				else continue;
				if (!p_dropItem[(i * 5) + 1 + temp]->GetDeath() && !p_dropItem[(i * 5) + 1 + temp]->GetAlive()) p_dropItem[(i * 5) + 1 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 2 + temp]->GetDeath() && !p_dropItem[(i * 5) + 2 + temp]->GetAlive()) p_dropItem[(i * 5) + 2 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 3 + temp]->GetDeath() && !p_dropItem[(i * 5) + 3 + temp]->GetAlive()) p_dropItem[(i * 5) + 3 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				if (!p_dropItem[(i * 5) + 4 + temp]->GetDeath() && !p_dropItem[(i * 5) + 4 + temp]->GetAlive()) p_dropItem[(i * 5) + 4 + temp]->SetAlive(p_enemyCrayonHuman[i]->GetArea());
				continue;
			}


			p_enemyCrayonHuman[i]->Process();		// �N�������q���[�}���̃v���Z�X

			
			// ����ł�����
			if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;


			// ���b�N�I���Ώۂ��X���C����������
			if (lockOnEnemySlime)
			{
				// ���݂̃��b�N�I���Ώۂ��߂�������
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemySlime[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()))
				{
					// ���b�N�I���Ώۂ��X�V����
					lockOnEnemySlime = false;
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemyCrayonHuman[i]->GetArea());
					lockONNowEnemyID = i;


					// �X�V�����Ώۂ��v���C���[�̎��F����������
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemyCrayonHuman[i]->GetArea());
					}
					// �X�V�����Ώۂ��v���C���[�̎��F�O��������
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}
			// ���b�N�I���Ώۂ��N�������q���[�}����������
			else
			{
				// ���݂̃��b�N�I���Ώۂ��߂�������
				if (BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[lockONNowEnemyID]->GetArea())
					>= BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()))
				{
					// ���b�N�I���Ώۂ��X�V����
					mostNearEnemyDistance = BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea());
					mostNearEnemyScreenArea = ConvWorldPosToScreenPos(p_enemyCrayonHuman[i]->GetArea());
					lockONNowEnemyID = i;


					// �X�V�����Ώۂ��v���C���[�̎��F����������
					if (mostNearEnemyDistance < 250)
					{
						p_character->SetMostNearEnemyArea(p_enemyCrayonHuman[i]->GetArea());
					}
					// �X�V�����Ώۂ��v���C���[�̎��F�O��������
					else
					{
						p_character->SetMostNearEnemyArea();
					}
				}
			}


			// �v���C���[�̈ʒu�Ƌ������擾����
			p_enemyCrayonHuman[i]->SetCharacterArea(p_character->GetArea(), BaseMove::GetDistance<int>(p_character->GetArea(), p_enemyCrayonHuman[i]->GetArea()));


			// �v���C���[�ɑ΂��čU���o������
			if (p_enemyCrayonHuman[i]->GetAttackDamage()
				&& p_character->GetArea().y <= p_enemyCrayonHuman[i]->GetArea().y + p_enemyCrayonHuman[i]->GetHeight()
				&& p_character->GetArea().y + p_character->GetHeight() >= p_enemyCrayonHuman[i]->GetArea().y)
			{
				// �퓬BGM����Ȃ�������
				if (!nowBattleBGM)
				{
					// �퓬BGM�ɐ؂�ւ���
					nowBattleBGM = true;
					SoundProcess::BGMTrans(SoundProcess::ESOUNDNAME_BGM::battleBGM);
				}


				// �v���C���[���U�����Ă���̐���2�ȉ���������
				if (charaSomeEnemyDamageCount++ < 2)
				{
					// �U��SE�𗬂�
					SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::strikeBomb, p_enemyCrayonHuman[i]->GetArea(), 180);


					p_character->SetDamage();		// �v���C���[�Ƀ_���[�W��^����


					// �_���[�W���󂯂Ă��Ȃ��J�E���g��0����Ȃ�������
					if(notDamageCount != 0) notDamageCount = 0;


					// �_���[�W���l��100�ȉ���������
					if (damageCount < 100)	damageCount++;


					// �_���[�W���o�摜���o�Ă��Ȃ�������
					if (damageDrawFrame == 0)
					{
						std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
						std::mt19937 mt(rnd());     // �����Z���k�E�c�C�X�^��32�r�b�g��
						std::uniform_int_distribution<> blood(0, 2);        // X���W�p����
						damageDrawID = blood(mt);		// �����_���Ń_���[�W�摜��\������
						damageDrawFrame = 10;			// 10�t���[�������\������悤�ɂ���
					}
				}
			}
		} /// for (int i = 0; i != enemyCrayonHumanNum; ++i)
		/// �N�������q���[�}���̃v���Z�X�Ɋւ���--------------------------------------------------------------------------------------------------------------------


		BaseMove::ShadowArea(p_character->GetArea());		// �V���h�E�}�b�v�̈ʒu���X�V����


		AttackProcess();		// �����蔻�菈��


		BaseMove::SkyBoxProcess(p_character->GetArea());	// �X�J�C�{�b�N�X�̈ʒu���X�V����


		// ���̃V�[���ֈڍs����ꏊ�ɋ�����
		if (p_character->GetArea().y >= 3550.0f)
		{
			BASICPARAM::endFeedNow = true;
			BaseMove::SetScene(ESceneNumber::FOURTHLOAD);
		}
	} /// if (!changeAdjustmentScene)
	// �����@�B�̃V�[����������
	else
	{
		// �����@�B�ւ̈ڍs�V�[����������
		if (adjustmentStartFeed)
		{
			if (adjustmentSceneFeed <= 100)
			{
				adjustmentSceneFeed++;
			}
			else
			{
				adjustmentFeedNow = false;
			}
		}
		// �����@�B����̈ڍs�V�[����������
		else
		{
			if (adjustmentSceneFeed >= 0)
			{
				adjustmentSceneFeed--;
			}
			else
			{
				changeAdjustmentScene = false;
				adjustmentFeedNow = false;
			}
		}


		// �����@�B�̃t�F�[�h������Ȃ�������
		if (!adjustmentFeedNow)
		{
			AdjustmentProcess();
		}
	} /// else(!if (!changeAdjustmentScene))


#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BASICPARAM::endFeedNow = true;
		BaseMove::SetScene(ESceneNumber::FOURTHLOAD);
	}
#endif
} /// void MainMove3::Process()


// �J�����̍ăZ�b�g�A�b�v
void MainMove3::CameraProcess()
{
	p_camera->SetUp();
}


// �e�N�X�`���̍ēǂݍ���
void MainMove3::TextureReload()
{
	// �L�����N�^�[�̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::charaTextureWhiteBlack)
	{
		// �_���[�W���o
		DamageTextureReload();

		// �L�����N�^�[
		p_character->TextureReload();
	}
	

	// ���̑��̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::anothreTextureWhiteBlack)
	{
		// �����@�B
		p_adjustmentMachine->TextureReload();
	}


	// �K�i�̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::stairsTextureWhiteBlack)
	{
		if (BASICPARAM::stairsNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsNum; i != n; ++i)
			{
				vp_stageStairs[i]->TextureReload();
			}
		}
	}


	// �X���̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::lightStreetTextureWhiteBlack)
	{
		if (BASICPARAM::streetLightNum != 0)
		{
			for (int i = 0, n = BASICPARAM::streetLightNum; i != n; ++i)
			{
				vp_stageStreetLight[i]->TextureReload();
			}
		}
	}


	// �K�i�Ə��̃e�N�X�`���������w�肶��Ȃ�������
	if (!BASICPARAM::stairsRoadTextureWhiteBlack)
	{
		if (BASICPARAM::stairsRoadNum != 0)
		{
			for (int i = 0, n = BASICPARAM::stairsRoadNum; i != n; ++i)
			{
				vp_stageStairsRoad[i]->TextureReload();
			}
		}
	}


	// �G�X���C��
	for (int i = 0; i != enemySlimeNum; ++i)
	{
		if (p_enemySlime[i]->GetDeathFlag()) continue;
		p_enemySlime[i]->TextureReload();
	}


	// �G�N�������q���[�}��
	for (int i = 0; i != enemyCrayonHumanNum; ++i)
	{
		if (p_enemyCrayonHuman[i]->GetDeathFlag()) continue;
		p_enemyCrayonHuman[i]->TextureReload();
	}


	// �h���b�v�A�C�e���̃e�N�X�`���������w�肶��Ȃ�������
	for (int i = 0, n = dropItemNum; i != n; ++i)
	{
		if (p_dropItem[i]->GetDeath()) continue;
		p_dropItem[i]->TextureReload();
	}
} /// void MainMove3::TextureReload()


// �I�v�V������ʃ��f���̕`��
void MainMove3::OptionActorModel()
{
	p_character->OptionActorDraw();
}


// �I�v�V������ʃ��f���̕`��̏���
void MainMove3::OptionActorModelBefore()
{
	p_character->OptionActorDrawBefore();
}


// �I�v�V������ʃ��f���̕`��̌㏈��
void MainMove3::OptionActorModelAfter()
{
	p_character->OptionActorDrawAfter();
}
