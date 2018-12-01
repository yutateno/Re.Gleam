#pragma once
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>

namespace SoundProcess
{
	/// �Q�[���ɂ���ĕς�镔��-------------------------------------------------------

	// �T�E���h�̖��OID_SE��D��x����
	enum class ESOUNDNAME_SE
	{
		saveOn, saveMiss, pianoAttack3, pianoAttack2, pianoAttack1, pianoAttack
		, jump, pianoAttackMiss, landing, landing2, footFloor, foot
		, ballPickUp, strikeBomb, ballPawnHigh, ballPawn, lightOneFoot, lightFoot
		, crayonDie, titleBurnLow, titleBurnLowMagni, titleBurn
	};

	// �T�E���h�̖��OID_BGM
	enum class ESOUNDNAME_BGM
	{
		titleMusicBox, normalBGM, battleBGM, lightBGM, noise3, noise2
		, noise, noise_2, noise_1, ending, boss, none
	};
	/// --------------------------------------------------------------------------------

	// �T�E���h�^�C�v
	enum class ESOUNDTYPE
	{
		soundMem, soundStreem, sound3DSourceChara, sound3DSourcePartner, none
	};


	// ������
	void Init();

	// ���[�h
	void Load(int loadFile, ESOUNDNAME_SE name, ESOUNDTYPE type, VECTOR partnerArea = VGet(0, 0, 0));
	void Load(int loadFile, ESOUNDNAME_BGM name);

	// �v���Z�X
	void Process();

	// SE�̍Đ�
	void DoSound(ESOUNDNAME_SE name, int volume = 255);

	// BGM�̏I���
	void BGMEnd();

	// BGM�؂�ւ�
	void BGMTrans(ESOUNDNAME_BGM nextName, int volume = 255);

	// BGM���ʐݒ�
	void SetBGMVolume(ESOUNDNAME_BGM name, int volume, int maxVolume = 255);

	// ���
	void Release();

	// �v���C���[�̍��W��ݒ�
	void SetCharaArea(VECTOR area);

	// ���X�i�[�̍��W��ݒ�
	void SetLisnerArea(VECTOR area);

	// SE�̃��[�U�[���ʒ�����ݒ�
	void SetSEVolumeEntire(float volumeEntire);

	// BGM�̃��[�U�[���ʒ�����ݒ�
	void SetBGMVolumeEntire(float volumeEntire);
}
