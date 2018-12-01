#include "SoundProcess.hpp"

namespace SoundProcess
{
	/// �Q�[���ɂ���ĕς�镔��------------------
	const int seNum = 22;
	const int bgmNum = 11;
	const int bgmArray = 2;
	const int bgmFeedValue = 90;
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

	// �����ʒu
	VECTOR partnerArea;

	// ���X�i�[�ʒu
	VECTOR listenerArea;


	/// �����֐�---------------------------

	// BGM�v���Z�X
	void BGMProcess();

	// BGM�t�F�[�h
	void BGMFeed();



	void Init()
	{
		for (int i = 0; i != seNum; ++i)
		{
			se_sound[i] = -1;
		}
		ZeroMemory(se_loadFlag, sizeof(se_loadFlag));
		ZeroMemory(se_playFlag, sizeof(se_playFlag));
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
	}


	void Load(int loadFile, ESOUNDNAME_SE name, ESOUNDTYPE type, VECTOR partnerArea)
	{
		se_sound[static_cast<int>(name)] = loadFile;
		se_loadFlag[static_cast<int>(name)] = true;
		if (type == ESOUNDTYPE::sound3DSourceChara)
		{
			Set3DPositionSoundMem(charaArea, se_sound[static_cast<int>(name)]);
			Set3DRadiusSoundMem(VSize(VSub(charaArea, listenerArea)), se_sound[static_cast<int>(name)]);
		}
		else if (type == ESOUNDTYPE::sound3DSourcePartner)
		{
			Set3DPositionSoundMem(partnerArea, se_sound[static_cast<int>(name)]);
			Set3DRadiusSoundMem(VSize(VSub(partnerArea, listenerArea)), se_sound[static_cast<int>(name)]);
		}
	}


	void Load(int loadFile, ESOUNDNAME_BGM name)
	{
		bgm_sound[static_cast<int>(name)] = loadFile;
		bgm_loadFlag[static_cast<int>(name)] = true;
	}


	void Process()
	{
		/// �Đ���
		int count = 0;

		// �Đ����Ă��邩�ǂ������f
		for (int i = 0; i != seNum; ++i)
		{
			// ��������Ă��Ȃ�������
			if (!CheckSoundMem(se_sound[i]))
			{
				se_playFlag[i] = false;
				continue;
			}

			// �Đ����Ă�����
			if (se_playFlag[i])
			{
				count++;		// �Đ��������Z
			}
		}

		if (bgm_soundFlag)
		{
			if (bgm_requestVolume[0] < bgm_requestVolume[1]
				&& bgm_requestVolume[1] != bgm_maxVolume[1] - (10 * count))
			{
				SetBGMVolume(bgm_name[1], bgm_maxVolume[1] - (10 * count), bgm_maxVolume[1]);
			}
			if (bgm_requestVolume[0] > bgm_requestVolume[1]
				&& bgm_requestVolume[0] != bgm_maxVolume[0] - (10 * count))
			{
				SetBGMVolume(bgm_name[0], bgm_maxVolume[0] - (10 * count), bgm_maxVolume[0]);
			}
			count--;
		}


		/// ������l�����炵�Ȃ���Đ����ʒ���
		for (int i = seNum - 1; i >= 0; --i)
		{
			// �Đ����Ă��Ȃ�������
			if (!se_playFlag[i]) continue;

			// ���ʂ�������
			ChangeVolumeSoundMem(static_cast<int>(((255 - (10 * count))) * se_volumeAdjustment), se_sound[i]);
			if (count > 0)
			{
				count--;
			}
			else
			{
				break;
			}
		}

		BGMProcess();
	}


	void DoSound(ESOUNDNAME_SE name, int volume)
	{
		if (!se_playFlag[static_cast<int>(name)])
		{
			PlaySoundMem(se_sound[static_cast<int>(name)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(0, se_sound[static_cast<int>(name)]);
		}

		se_playFlag[static_cast<int>(name)] = true;
	}


	void BGMEnd()
	{
		for (int i = 0; i != bgmArray; ++i)
		{
			if (bgm_name[i] == ESOUNDNAME_BGM::none) continue;
			SetBGMVolume(bgm_name[i], 0, 0);
		}
	}


	void BGMTrans(ESOUNDNAME_BGM nextName, int volume)
	{
		if (!bgm_soundFlag) bgm_soundFlag = true;

		if (bgm_name[1] == ESOUNDNAME_BGM::none)
		{
			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}

		if (bgm_name[1] == nextName)
		{
			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}

		if (bgm_name[0] == nextName)
		{
			SetBGMVolume(bgm_name[1], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}

		if (bgm_requestVolume[0] < bgm_requestVolume[1])
		{
			ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[0])]);
			StopSoundMem(bgm_sound[static_cast<int>(bgm_name[0])]);
			bgm_nowVolume[0] = 0;
			bgm_nextVolume[0] = 0;
			bgm_requestVolume[0] = 0;
			bgm_name[0] = ESOUNDNAME_BGM::none;

			SetBGMVolume(nextName, volume, volume);
			SetBGMVolume(bgm_name[1], 0, 0);
			return;
		}

		if (bgm_requestVolume[0] > bgm_requestVolume[1])
		{
			ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[1])]);
			StopSoundMem(bgm_sound[static_cast<int>(bgm_name[1])]);
			bgm_nowVolume[1] = 0;
			bgm_nextVolume[1] = 0;
			bgm_requestVolume[1] = 0;
			bgm_name[1] = ESOUNDNAME_BGM::none;

			SetBGMVolume(bgm_name[0], 0, 0);
			SetBGMVolume(nextName, volume, volume);
			return;
		}
	}


	void BGMProcess()
	{
		BGMFeed();
		printfDx("%d\n", GetVolumeSoundMem2(bgm_sound[static_cast<int>(bgm_name[0])]));
	}


	void BGMFeed()
	{
		if (!bgm_soundFlag) bgm_soundFlag = true;

		for (int i = 0; i != bgmArray; ++i)
		{
			if (bgm_nowVolume[i] < bgm_nextVolume[i])
			{
				ChangeVolumeSoundMem(static_cast<int>((bgm_nowVolume[i] + static_cast<int>((sin(-M_PI / 2 + M_PI / bgmFeedValue * bgm_feedCount[i]) + 1) / 2 * (bgm_nextVolume[i] - bgm_nowVolume[i]))) * bgm_volumeAdjustment)
					, bgm_sound[static_cast<int>(bgm_name[i])]);
			}
			else
			{
				ChangeVolumeSoundMem(static_cast<int>((bgm_nowVolume[i] - static_cast<int>((sin(-M_PI / 2 + M_PI / bgmFeedValue * bgm_feedCount[i]) + 1) / 2 * (bgm_nowVolume[i] - bgm_nextVolume[i]))) * bgm_volumeAdjustment)
					, bgm_sound[static_cast<int>(bgm_name[i])]);
			}
			if (bgm_feedCount[i] <= bgmFeedValue)
			{
				bgm_feedCount[i]++;
			}
			else
			{
				bgm_nowVolume[i] = bgm_nextVolume[i];
			}
		}
	}


	void SetBGMVolume(ESOUNDNAME_BGM name, int volume, int maxVolume)
	{
		if (!bgm_soundFlag) bgm_soundFlag = true;

		for (int i = 0; i != bgmArray; ++i)
		{
			if (bgm_name[i] == ESOUNDNAME_BGM::none
				|| bgm_name[i] == name)
			{
				bgm_name[i] = name;
				bgm_requestVolume[i] = volume;
				bgm_maxVolume[i] = maxVolume;
				if (bgm_nextVolume[i] != bgm_requestVolume[i])
				{
					bgm_nowVolume[i] = GetVolumeSoundMem2(bgm_sound[static_cast<int>(bgm_name[i])]);
					bgm_nextVolume[i] = bgm_requestVolume[i];
				}
				bgm_feedCount[i] = 0;
				if (bgm_nowVolume[i] <= 2
					|| !(CheckSoundMem(bgm_sound[static_cast<int>(bgm_name[i])])))
				{
					StopSoundMem(bgm_sound[static_cast<int>(bgm_name[i])]);
					PlaySoundMem(bgm_sound[static_cast<int>(bgm_name[i])], DX_PLAYTYPE_LOOP);
					ChangeVolumeSoundMem(0, bgm_sound[static_cast<int>(bgm_name[i])]);
					bgm_nowVolume[i] = 0;
				}
				return;
			}
		}
	}


	void Release()
	{
		for (int i = 0; i != seNum; ++i)
		{
			if (!se_loadFlag[i]) continue;
			DeleteSoundMem(se_sound[i]);
			se_sound[i] = -1;
		}
		for (int i = 0; i != bgmNum; ++i)
		{
			if (!bgm_loadFlag[i]) continue;
			StopSoundMem(bgm_sound[i]);
			DeleteSoundMem(bgm_sound[i]);
			bgm_sound[i] = -1;
		}
	}


	void SetCharaArea(VECTOR area)
	{
		charaArea = area;
	}


	void SetLisnerArea(VECTOR area)
	{
		listenerArea = area;
	}


	void SetSEVolumeEntire(float volumeEntire)
	{
		se_volumeAdjustment = volumeEntire;
	}


	void SetBGMVolumeEntire(float volumeEntire)
	{
		bgm_volumeAdjustment = volumeEntire;
	}
}
