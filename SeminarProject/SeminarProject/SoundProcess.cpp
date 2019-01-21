#include "SoundProcess.hpp"


namespace SoundProcess
{
	/// �Q�[���ɂ���ĕς�镔��------------------
	const int seNum = 23;			// SE�̐�
	const int bgmNum = 11;			// BGM�̐�
	const int bgmArray = 2;			// BGM�̍ő�Đ���
	const int bgmFeedValue = 90;	// BGM�̃t�F�[�h�l
	///-------------------------------------------


	/// SE�Ɋւ���------------------------

	// �ۑ�����
	int se_sound[seNum];

	// ���[�h�������ǂ���
	bool se_loadFlag[seNum];

	// �Đ����Ă��邩�ǂ���
	bool se_playFlag[seNum];

	// SE�̃��[�U�[���ʒ���
	float se_volumeAdjustment;

	// SE�̎w��ő剹��
	int se_volumeSetMaxVolume[seNum];


	/// BGM�Ɋւ���-----------------------

	// �ۑ�����
	int bgm_sound[bgmNum];

	// ���[�h�������ǂ���
	bool bgm_loadFlag[bgmNum];

	// �{�����[��
	int bgm_nowVolume[bgmArray];

	// BGM�̖��O
	ESOUNDNAME_BGM bgm_name[bgmArray];

	// �v�����ꂽBGM�̃{�����[��
	int bgm_requestVolume[bgmArray];

	// �ύX���̖ړI�{�����[��
	int bgm_nextVolume[bgmArray];

	// �t�F�[�h�J�E���g
	int bgm_feedCount[bgmArray];

	// BGM������Ă��邩�ǂ���
	bool bgm_soundFlag;

	// BGM�̍ő�w�艹��
	int bgm_maxVolume[bgmArray];

	// BGM�̃��[�U�[���ʒ���
	float bgm_volumeAdjustment;


	/// 3D�Ɋւ���-------------------------

	// �v���C���[�ʒu
	VECTOR charaArea;

	// ���X�i�[�ʒu
	VECTOR listenerArea;

	// ���X�i�[�̃r���[�ʒu
	VECTOR listenerViewArea;

	// �T�E���h�̑傫��
	float volume3DRadius;


	/// �����֐�---------------------------

	// BGM�v���Z�X
	void BGMProcess();

	// BGM�t�F�[�h
	void BGMFeed();


	/// �I�v�V�����Ɋւ���-------------

	// �I�v�V�����ɂ���ꍇ�̉��ʒ����p
	float optionNowVolume;



	/// --------------------------------------------------------------------------------------------------
	void Init()
	{
		for (int i = 0; i != seNum; ++i)
		{
			se_sound[i] = -1;
		}
		ZeroMemory(se_loadFlag, sizeof(se_loadFlag));
		ZeroMemory(se_playFlag, sizeof(se_playFlag));
		ZeroMemory(se_volumeSetMaxVolume, sizeof(se_volumeSetMaxVolume));
		for (int i = 0; i != bgmNum; ++i)
		{
			bgm_sound[i] = -1;
		}
		ZeroMemory(bgm_loadFlag, sizeof(bgm_loadFlag));
		ZeroMemory(bgm_nowVolume, sizeof(bgm_nowVolume));
		for (int i = 0; i != bgmArray; ++i)
		{
			bgm_name[i] = ESOUNDNAME_BGM::none;
		}
		ZeroMemory(bgm_requestVolume, sizeof(bgm_requestVolume));
		ZeroMemory(bgm_nextVolume, sizeof(bgm_nextVolume));
		ZeroMemory(bgm_feedCount, sizeof(bgm_feedCount));
		ZeroMemory(bgm_maxVolume, sizeof(bgm_maxVolume));

		bgm_soundFlag = false;

		se_volumeAdjustment = 1.0f;
		bgm_volumeAdjustment = 1.0f;
		optionNowVolume = 1.0f;
	} /// void Init()



	/// --------------------------------------------------------------------------------------------------
	void Load(int loadFile, ESOUNDNAME_SE name)
	{
		se_sound[static_cast<int>(name)] = loadFile;
		se_loadFlag[static_cast<int>(name)] = true;
	}



	/// --------------------------------------------------------------------------------------------------
	void Load(int loadFile, ESOUNDNAME_BGM name)
	{
		bgm_sound[static_cast<int>(name)] = loadFile;
		bgm_loadFlag[static_cast<int>(name)] = true;
	}



	/// --------------------------------------------------------------------------------------------------
	void Process()
	{
		// 3D�����̈ʒu��ݒ�
		Set3DSoundListenerPosAndFrontPos_UpVecY(VAdd(listenerArea, charaArea), VAdd(listenerViewArea, charaArea));


		int count = 0;			// ���݂̍Đ���


		// SE���Đ����Ă��邩�ǂ������f
		for (int i = 0; i != seNum; ++i)
		{
			// ��������Ă��Ȃ�������
			if (!CheckSoundMem(se_sound[i]))
			{
				se_playFlag[i] = false;
				continue;
			}


			// �Đ����Ă�����
			if (se_playFlag[i]) count++;		// �Đ��������Z
		}


		// BGM���Đ����Ă��邩�ǂ���
		if (bgm_soundFlag)
		{
			// ���N�G�X�g�̉��ʂ�0�Ԗڂ��1�Ԗڂ̕����傫��������
			if (bgm_requestVolume[0] < bgm_requestVolume[1]
				&& bgm_requestVolume[1] != bgm_maxVolume[1] - (10 * count))
			{
				// �傫������BGM�̉��ʂ𒲐�����A���̍ۂ�SE�̌��ɉ����ĉ��ʂ�������
				SetBGMVolume(bgm_name[1], bgm_maxVolume[1] - (10 * count), bgm_maxVolume[1]);
			}


			// ���N�G�X�g�̉��ʂ�1�Ԗڂ��0�Ԗڂ̕����傫��������
			if (bgm_requestVolume[0] > bgm_requestVolume[1]
				&& bgm_requestVolume[0] != bgm_maxVolume[0] - (10 * count))
			{
				// �傫������BGM�̉��ʂ𒲐�����A���̍ۂ�SE�̌��ɉ����ĉ��ʂ�������
				SetBGMVolume(bgm_name[0], bgm_maxVolume[0] - (10 * count), bgm_maxVolume[0]);
			}
			//count--;
		}


		// ������l�����炵�Ȃ���Đ����ʒ���
		for (int i = seNum - 1; i >= 0; --i)
		{
			// �Đ����Ă��Ȃ�������
			if (!se_playFlag[i]) continue;


			// �D��x�̒Ⴂ�����̂��特�ʂ�����������
			ChangeVolumeSoundMem(static_cast<int>((((255 - (10 * count))) * se_volumeAdjustment * optionNowVolume) / 255 * se_volumeSetMaxVolume[i]), se_sound[i]);


			// �Đ����Ă���SE�̉��ʒ����K�v�����܂�����
			if (count > 0)
			{
				count--;
			}
			// �Đ����Ă���SE�̉��ʒ������I�����
			else break;
		}


		BGMProcess();		// BGM�̃v���Z�X���Ă�
	} /// void Process()



	/// --------------------------------------------------------------------------------------------------
	void DoSound(ESOUNDNAME_SE name, int volume)
	{
		// ����SE�̍ő剹�ʂ����߂�
		se_volumeSetMaxVolume[static_cast<int>(name)] = volume;

		// SE������Ă��Ȃ�������
		if (!se_playFlag[static_cast<int>(name)])
		{
			// ���𗬂��ĉ��ʂ�0�ɂ���
			PlaySoundMem(se_sound[static_cast<int>(name)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(0, se_sound[static_cast<int>(name)]);
		}
		// SE�����łɗ���Ă�����
		else
		{
			// ���ʂ������čĐ����Ȃ���
			ChangeVolumeSoundMem(0, se_sound[static_cast<int>(name)]);
			PlaySoundMem(se_sound[static_cast<int>(name)], DX_PLAYTYPE_BACK);
		}


		// SE�𗬂��Ă���Ƃ���
		se_playFlag[static_cast<int>(name)] = true;
	} /// void DoSound(ESOUNDNAME_SE name, int volume)



	/// --------------------------------------------------------------------------------------------------
	void DoSound(ESOUNDNAME_SE name, VECTOR area, int volume)
	{
		// SE�̍��W�Ƒ傫����ݒ肷��
		Set3DPositionSoundMem(VAdd(area, VScale(listenerArea, 0.1f)), se_sound[static_cast<int>(name)]);
		Set3DRadiusSoundMem(volume3DRadius * 2, se_sound[static_cast<int>(name)]);


		// SE�̍ő剹�ʂ����߂�
		se_volumeSetMaxVolume[static_cast<int>(name)] = volume;


		// SE������Ă��Ȃ�������
		if (!se_playFlag[static_cast<int>(name)])
		{
			// ���𗬂��ĉ��ʂ�0�ɂ���
			PlaySoundMem(se_sound[static_cast<int>(name)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(0, se_sound[static_cast<int>(name)]);
		}
		// SE�����łɗ���Ă�����
		else
		{
			// ���ʂ�0�ɂ��čĐ�����
			ChangeVolumeSoundMem(0, se_sound[static_cast<int>(name)]);
			PlaySoundMem(se_sound[static_cast<int>(name)], DX_PLAYTYPE_BACK);
		}


		// SE�𗬂��Ă���Ƃ���
		se_playFlag[static_cast<int>(name)] = true;
	} /// void DoSound(ESOUNDNAME_SE name, VECTOR area, int volume)



	/// --------------------------------------------------------------------------------------------------
	void BGMEnd()
	{
		for (int i = 0; i != bgmArray; ++i)
		{
			if (bgm_name[i] == ESOUNDNAME_BGM::none) continue;
			SetBGMVolume(bgm_name[i], 0, 0);
		}
	}



	/// --------------------------------------------------------------------------------------------------
	void BGMTrans(ESOUNDNAME_BGM nextName, int volume)
	{
		// BGM������Ă��Ȃ�������
		if (!bgm_soundFlag) bgm_soundFlag = true;


		// �����BGM������Ă��Ȃ�������
		if (bgm_name[1] == ESOUNDNAME_BGM::none)
		{
			// 0�Ԗڂ̉��ʂ������āA�v��BGM1�Ԗڂŗ���
			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}


		// ���ɗ����Ă���BGM��������
		if (bgm_name[1] == nextName)
		{
			// ���N�G�X�g���ʂ��Đݒ肷��
			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}
		if (bgm_name[0] == nextName)
		{
			// ���N�G�X�g���ʂ��Đݒ肷��
			SetBGMVolume(bgm_name[1], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}


		// 0�Ԗڂ��1�Ԗڂ̕������N�G�X�g���ʑ傫��������
		if (bgm_requestVolume[0] < bgm_requestVolume[1])
		{
			// 0�Ԗڂ����Z�b�g����
			ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[0])]);
			StopSoundMem(bgm_sound[static_cast<int>(bgm_name[0])]);
			bgm_nowVolume[0] = 0;
			bgm_nextVolume[0] = 0;
			bgm_requestVolume[0] = 0;
			bgm_name[0] = ESOUNDNAME_BGM::none;


			// 1�Ԗڂ̉��ʂ������āA�v��BGM��0�Ԗڂŗ���
			SetBGMVolume(nextName, volume, volume);
			SetBGMVolume(bgm_name[1], 0, 0);
			return;
		}


		// 1�Ԗڂ��0�Ԗڂ̕������N�G�X�g���ʑ傫��������
		if (bgm_requestVolume[0] > bgm_requestVolume[1])
		{
			// 1�Ԗڂ����Z�b�g����
			ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[1])]);
			StopSoundMem(bgm_sound[static_cast<int>(bgm_name[1])]);
			bgm_nowVolume[1] = 0;
			bgm_nextVolume[1] = 0;
			bgm_requestVolume[1] = 0;
			bgm_name[1] = ESOUNDNAME_BGM::none;


			// 0�Ԗڂ̉��ʂ������āA�v��BGM��1�Ԗڂŗ���
			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}
	} /// void BGMTrans(ESOUNDNAME_BGM nextName, int volume)




	/// --------------------------------------------------------------------------------------------------
	void BGMProcess()
	{
		BGMFeed();		// �t�F�[�h���Ă�
		// ���ɂ��������邩������Ȃ��̂ňꉞ�ʏ����Ƃ���
	}


	/// --------------------------------------------------------------------------------------------------
	void BGMFeed()
	{
		// BGM������Ă��Ȃ������痬��Ă���Ƃ���
		if (!bgm_soundFlag) bgm_soundFlag = true;


		for (int i = 0; i != bgmArray; ++i)
		{
			// ���̉��ʂ�胊�N�G�X�g���ʂ̕�������������
			if (bgm_nowVolume[i] < bgm_nextVolume[i])
			{
				// ���[�U�[��BGM�ő剹�ʂ����݂��āA���ʂ��グ�Ă���
				ChangeVolumeSoundMem(static_cast<int>((bgm_nowVolume[i] + static_cast<int>((sin(-M_PI / 2 + M_PI / bgmFeedValue * bgm_feedCount[i]) + 1) / 2 * (bgm_nextVolume[i] - bgm_nowVolume[i]))) * bgm_volumeAdjustment * optionNowVolume)
					, bgm_sound[static_cast<int>(bgm_name[i])]);
			}
			// ���̉��ʂ�胊�N�G�X�g���ʂ�������������
			else
			{
				// ���[�U�[��BGM�ő剹�ʂ����݂��āA���ʂ������Ă���
				ChangeVolumeSoundMem(static_cast<int>((bgm_nowVolume[i] - static_cast<int>((sin(-M_PI / 2 + M_PI / bgmFeedValue * bgm_feedCount[i]) + 1) / 2 * (bgm_nowVolume[i] - bgm_nextVolume[i]))) * bgm_volumeAdjustment * optionNowVolume)
					, bgm_sound[static_cast<int>(bgm_name[i])]);
			}


			// �t�F�[�h�l�܂ŏグ�Ă���
			if (bgm_feedCount[i] <= bgmFeedValue)
			{
				bgm_feedCount[i]++;
			}
			// �t�F�[�h���������ꂽ��(�܂胊�N�G�X�g���ʂɒB����
			else
			{
				bgm_nowVolume[i] = bgm_nextVolume[i];
			}
		} /// for (int i = 0; i != bgmArray; ++i)
	} /// void BGMFeed()


	
	/// --------------------------------------------------------------------------------------------------
	void SetBGMVolume(ESOUNDNAME_BGM name, int volume, int maxVolume)
	{
		// BGM������Ă��Ȃ�������
		if (!bgm_soundFlag) bgm_soundFlag = true;


		for (int i = 0; i != bgmArray; ++i)
		{
			// �������Ă���BGM��������BGM��S�������Ă��Ȃ�������
			if (bgm_name[i] == ESOUNDNAME_BGM::none	|| bgm_name[i] == name)
			{
				// BGM��ݒ肷��
				bgm_name[i] = name;
				bgm_requestVolume[i] = volume;
				bgm_maxVolume[i] = maxVolume;


				// ���N�G�X�g���ʂɒB���Ă�����
				if (bgm_nextVolume[i] != bgm_requestVolume[i])
				{
					// ���ʂ��擾���ēn��
					bgm_nowVolume[i] = GetVolumeSoundMem2(bgm_sound[static_cast<int>(bgm_name[i])]);
					bgm_nextVolume[i] = bgm_requestVolume[i];
				}


				bgm_feedCount[i] = 0;		// ���ʃt�F�[�h���J�n������


				// ���̉��ʂ��~�܂��Ă��邩����Ȃ�0�ɋ߂�������
				if (bgm_nowVolume[i] <= 2
					|| !(CheckSoundMem(bgm_sound[static_cast<int>(bgm_name[i])])))
				{
					// �~�߂ďI��������
					StopSoundMem(bgm_sound[static_cast<int>(bgm_name[i])]);
					PlaySoundMem(bgm_sound[static_cast<int>(bgm_name[i])], DX_PLAYTYPE_LOOP);
					ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[i])]);
					bgm_nowVolume[i] = 0;
				}
				return;
			} /// if (bgm_name[i] == ESOUNDNAME_BGM::none	|| bgm_name[i] == name)
		} /// for (int i = 0; i != bgmArray; ++i)
	} /// void SetBGMVolume(ESOUNDNAME_BGM name, int volume, int maxVolume)



	/// --------------------------------------------------------------------------------------------------
	void Release()
	{
		// SE������
		for (int i = 0; i != seNum; ++i)
		{
			if (!se_loadFlag[i]) continue;
			DeleteSoundMem(se_sound[i]);
			se_sound[i] = -1;
		}


		// BGM������
		for (int i = 0; i != bgmNum; ++i)
		{
			if (!bgm_loadFlag[i]) continue;
			StopSoundMem(bgm_sound[i]);
			DeleteSoundMem(bgm_sound[i]);
			bgm_sound[i] = -1;
		}
	} /// void Release()



	/// --------------------------------------------------------------------------------------------------
	void SetCharaArea(VECTOR area)
	{
		charaArea = area;
	}



	/// --------------------------------------------------------------------------------------------------
	void SetLisnerArea(VECTOR area)
	{
		listenerArea = area;
	}



	/// --------------------------------------------------------------------------------------------------
	void SetLisnerViewArea(VECTOR area)
	{
		listenerViewArea = area;
	}



	/// --------------------------------------------------------------------------------------------------
	void Set3DRadius(float radius)
	{
		volume3DRadius = radius;
	}



	/// --------------------------------------------------------------------------------------------------
	void SetSEVolumeEntire(float volumeEntire)
	{
		se_volumeAdjustment = volumeEntire;
	}



	/// --------------------------------------------------------------------------------------------------
	float GetSEVolumeEntire()
	{
		return se_volumeAdjustment;
	}



	/// --------------------------------------------------------------------------------------------------
	void SetBGMVolumeEntire(float volumeEntire)
	{
		bgm_volumeAdjustment = volumeEntire;
	}



	/// --------------------------------------------------------------------------------------------------
	float GetBGMVolumeEntire()
	{
		return bgm_volumeAdjustment;
	}



	/// --------------------------------------------------------------------------------------------------
	void SetOptionMenuNow(bool nowTrue)
	{
		nowTrue ? optionNowVolume = 0.5f : optionNowVolume = 1.0f;
	}
} /// namespace SoundProcess
