#include "SoundProcess.hpp"

namespace SoundProcess
{
	/// IDのやつがロードしたかどうか
	bool loadFlag[33];
	/// 再生しているかどうか
	bool playFlag[33];
	/// ロードしたサウンド
	int soundLoad[33];
	/// ロードしたサウンドのタイプ
	ESOUNDTYPE soundType[33];

	/// プレイヤーの座標
	VECTOR charaArea;
	/// リスナーの座標
	VECTOR lisnerArea;


	/// 初期化
	void Init()
	{
		ZeroMemory(loadFlag, sizeof(loadFlag));
		ZeroMemory(playFlag, sizeof(playFlag));
		for (int i = 0; i != 33; ++i)
		{
			soundLoad[i] = -1;
		}
		for (int i = 0; i != 33; ++i)
		{
			soundType[i] = ESOUNDTYPE::none;
		}
		charaArea = VGet(0, 0, 0);
		lisnerArea = VGet(0, 0, 0);
	}


	/// 読み込み
	void Load(int loadFile, ESOUNDNAME name, ESOUNDTYPE type)
	{
		soundLoad[static_cast<int>(name)] = loadFile;
		loadFlag[static_cast<int>(name)] = true;
		soundType[static_cast<int>(name)] = type;
		if (type == ESOUNDTYPE::sound3DSourceChara)
		{
			Set3DPositionSoundMem(charaArea, soundLoad[static_cast<int>(name)]);
			Set3DRadiusSoundMem(VSize(VSub(charaArea, lisnerArea)), soundLoad[static_cast<int>(name)]);
		}
	}


	/// 読み込み
	void Load(int loadFile, ESOUNDNAME name, ESOUNDTYPE type, VECTOR partnerArea)
	{
		soundLoad[static_cast<int>(name)] = loadFile;
		loadFlag[static_cast<int>(name)] = true;
		soundType[static_cast<int>(name)] = type;
		if (type == ESOUNDTYPE::sound3DSourcePartner)
		{
			Set3DPositionSoundMem(partnerArea, soundLoad[static_cast<int>(name)]);
			Set3DRadiusSoundMem(VSize(VSub(partnerArea, lisnerArea)), soundLoad[static_cast<int>(name)]);
		}
	}


	/// プロセス
	void Process()
	{
		/// 再生個数
		int count = 0;

		// 再生しているかどうか判断
		for (int i = 0; i != 33; ++i)
		{
			// 音が流れていなかったら
			if (!CheckSoundMem(soundLoad[i]))
			{
				playFlag[i] = false;
				continue;
			}

			// 3D音源だったら
			if (soundType[i] == ESOUNDTYPE::sound3DSourceChara)
			{
				Set3DPositionSoundMem(charaArea, soundLoad[i]);
				continue;
			}

			// 再生していたら
			if (playFlag[i])
			{
				count++;		// 再生個数を加算
			}
		}

		// 一個以下なら特に何もしない
		//if (count <= 1)return;

		// 最小がボリューム0にならないように
		count--;

		/// 下げる値を減らしながら再生音量調整
		for (int i = 32; i >= 0; --i)
		{
			// 再生していなかったら
			if (!playFlag[i]) continue;


			// 音量を下げる
			ChangeVolumeSoundMem(255 - (6 * count), soundLoad[i]);
			if (count > 0) count--;
		}
	}

	void StageOneSound(int touchNum)
	{
		if (touchNum > 4)return;
		ChangeVolumeSoundMem(touchNum * 60, soundLoad[static_cast<int>(ESOUNDNAME::titleMusicBox)]);
	}

	void StageOneBallCatch()
	{
		int rand = GetRand(1);
		if (rand == 0)
		{
			PlaySoundMem(soundLoad[static_cast<int>(ESOUNDNAME::ballPawnHigh)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(125, soundLoad[static_cast<int>(ESOUNDNAME::ballPawnHigh)]);
		}
		else
		{
			PlaySoundMem(soundLoad[static_cast<int>(ESOUNDNAME::ballPawn)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(125, soundLoad[static_cast<int>(ESOUNDNAME::ballPawn)]);
		}
	}


	/// 再生させる
	void DoSound(ESOUNDNAME name)
	{
		if (static_cast<int>(name) >= 22)
		{
			if (playFlag[static_cast<int>(name)]) return;
			PlaySoundMem(soundLoad[static_cast<int>(name)], DX_PLAYTYPE_LOOP);
			ChangeVolumeSoundMem(0, soundLoad[static_cast<int>(name)]);
		}
		else
		{
			if (playFlag[static_cast<int>(name)]) return;
			PlaySoundMem(soundLoad[static_cast<int>(name)], DX_PLAYTYPE_BACK);
			ChangeVolumeSoundMem(0, soundLoad[static_cast<int>(name)]);
		}
		playFlag[static_cast<int>(name)] = true;
	}


	/// 音を入れていく
	void VolumeIn(ESOUNDNAME name, int volume)
	{
		static int upCount = 0;
		ChangeVolumeSoundMem(static_cast<int>((sin(-M_PI / 2 + M_PI / 120 * upCount) + 1) / 2 * volume), soundLoad[static_cast<int>(name)]);
		if (upCount <= 120)
		{
			upCount++;
		}
	}


	/// 音を消す
	void VolumeReset(ESOUNDNAME name, int volume)
	{
		static int downCount = 0;
		/*for (int i = 22; i != 33; ++i)
		{
			if (!playFlag[i]) continue;
			for (double j = GetVolumeSoundMem(soundLoad[i]) >= 255 ? 255 : GetVolumeSoundMem(soundLoad[i]); j > 0; j-=0.01f)
			{
				ChangeVolumeSoundMem(static_cast<int>(j), soundLoad[i]);
			}
			playFlag[i] = false;
		}*//*
		if (volume <= 0) return;
		if (++delay < 10)
		{
			VolumeReset(delay, name, volume);
		}
		else
		{*/
			ChangeVolumeSoundMem(static_cast<int>(volume - (sin(-M_PI / 2 + M_PI / 120 * downCount) + 1) / 2 * volume), soundLoad[static_cast<int>(name)]);
			if (downCount <= 120)
			{
				downCount++;
			}
			//VolumeReset(delay, name, volume);
		//}
	}

	/// 解放
	void Release()
	{
		for (int i = 0; i != 33; ++i)
		{
			VolumeReset(static_cast<ESOUNDNAME>(i));
			StopSoundMem(soundLoad[i]);
			SOUND_RELEASE(soundLoad[i]);
		}
	}


	/// キャラクターのエリア
	void SetCharaArea(VECTOR area)
	{
		charaArea = area;
	}


	/// リスナーのエリア
	void SetLisnerArea(VECTOR area)
	{
		lisnerArea = area;
	}
	void Test()
	{
		//printfDx("loadF: %d\tfile: %d\tPlayF: %d\n", loadFlag[static_cast<int>(ESOUNDNAME::titleMusicBox)], soundLoad[static_cast<int>(ESOUNDNAME::titleMusicBox)], playFlag[static_cast<int>(ESOUNDNAME::titleMusicBox)]);
	}
}
