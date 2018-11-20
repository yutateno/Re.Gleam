#pragma once
#include "Basic.hpp"

namespace SoundProcess
{
	/// �T�E���h�̖��OID
	enum class ESOUNDNAME
	{
		saveOn, saveMiss, pianoAttack, pianoAttack1, pianoAttack2, pianoAttack3
		, jump, pianoAttackMiss, landing, landing2, footFloor, foot
		, ballPickUp, strikeBomb, ballPawnHigh, ballPawn, lightOneFoot, lightFoot
		, crayonDie, titleBurnLow, titleBurnLowMagni, titleBurn, titleMusicBox, normalBGM
		, battleBGM, lightBGM, noise3, noise2, noise, noise_2
		, noise_1, ending, boss
	};


	/// ������
	void Init();

	/// ���[�h
	void Load(int loadFile, ESOUNDNAME name);
	
	/// �Đ�����
	void DoSound(ESOUNDNAME name);

	/// �������
	void Release();
}