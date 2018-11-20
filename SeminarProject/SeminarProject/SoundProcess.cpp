#include "SoundProcess.hpp"


namespace SoundProcess
{
	/// ID�̂�����[�h�������ǂ���
	bool loadFlag[33];
	/// �Đ����Ă��邩�ǂ���
	bool playFlag[33];
	/// ���[�h�����T�E���h
	int soundLoad[33];


	void Init()
	{
		ZeroMemory(loadFlag, sizeof(loadFlag));
		ZeroMemory(playFlag, sizeof(playFlag));
		for (int i = 0; i != 33; ++i)
		{
			soundLoad[i] = -1;
		}
	}

	void Load(int loadFile, ESOUNDNAME name)
	{
		soundLoad[static_cast<int>(name)] = loadFile;
		loadFlag[static_cast<int>(name)] = true;
	}

	void Process()
	{
		int count = 0;
		/// �Đ����Ă��邩�ǂ������f
		for (int i = 0; i != 33; ++i)
		{
			if (playFlag[i])
			{
				count++;
				continue;
			}
			if (!CheckSoundMem(soundLoad[i]))
			{
				playFlag[i] = false;
			}
		}

		/// ��ȉ��Ȃ���ɉ������Ȃ�
		if (count <= 1) return;

		/// �ŏ����{�����[��0�ɂȂ�Ȃ��悤��
		count--;
		/// ���̉�����l
		int volumeGain = static_cast<int>(255 / count);

		/// ������l�����炵�Ȃ���Đ����ʒ���
		for (int i = 32; i >= 0; --i)
		{
			if (!playFlag[i]) continue;
			ChangeVolumeSoundMem(255 - (volumeGain * count), soundLoad[i]);
			if (count > 0) count--;
		}
	}

	void DoSound(ESOUNDNAME name)
	{
		if (static_cast<int>(name) >= 22)
		{
			if (playFlag[static_cast<int>(name)]) return;
			PlaySoundMem(soundLoad[static_cast<int>(name)], DX_PLAYTYPE_LOOP);
		}
		else
		{
			if (playFlag[static_cast<int>(name)]) return;
			PlaySoundMem(soundLoad[static_cast<int>(name)], DX_PLAYTYPE_BACK);
		}
		playFlag[static_cast<int>(name)] = true;

		Process();
	}

	void Release()
	{
		for (int i = 0; i != 33; ++i)
		{
			if (!loadFlag[i]) continue;
			if (i >= 22)
			{
				StopSoundMem(soundLoad[i]);
			}
			SOUND_RELEASE(soundLoad[i]);
		}
	}
}
