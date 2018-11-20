#pragma once
#include "Basic.hpp"

namespace SoundProcess
{
	/// サウンドの名前ID
	enum class ESOUNDNAME
	{
		saveOn, saveMiss, pianoAttack, pianoAttack1, pianoAttack2, pianoAttack3
		, jump, pianoAttackMiss, landing, landing2, footFloor, foot
		, ballPickUp, strikeBomb, ballPawnHigh, ballPawn, lightOneFoot, lightFoot
		, crayonDie, titleBurnLow, titleBurnLowMagni, titleBurn, titleMusicBox, normalBGM
		, battleBGM, lightBGM, noise3, noise2, noise, noise_2
		, noise_1, ending, boss
	};


	/// 初期化
	void Init();

	/// ロード
	void Load(int loadFile, ESOUNDNAME name);
	
	/// 再生する
	void DoSound(ESOUNDNAME name);

	/// 解放する
	void Release();
}