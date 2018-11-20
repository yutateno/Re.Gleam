#include "SoundProcess.hpp"


namespace SoundProcess
{
	/// IDのやつがロードしたかどうか
	bool loadFlag[33];
	/// 再生しているかどうか
	bool playFlag[33];
	/// ロードしたサウンド
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
		/// 再生しているかどうか判断
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

		/// 一個以下なら特に何もしない
		if (count <= 1) return;

		/// 最小がボリューム0にならないように
		count--;
		/// 音の下げる値
		int volumeGain = static_cast<int>(255 / count);

		/// 下げる値を減らしながら再生音量調整
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
