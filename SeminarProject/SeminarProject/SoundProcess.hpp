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

	/// �T�E���h�^�C�v
	enum class ESOUNDTYPE
	{
		soundMem, soundStreem, sound3DSourceChara, sound3DSourcePartner, none
	};


	/// ������
	void Init();

	/// ���[�h
	void Load(int loadFile, ESOUNDNAME name, ESOUNDTYPE type);

	/// 3D�T�E���h�̃��[�h
	void Load(int loadFile, ESOUNDNAME name, ESOUNDTYPE type, VECTOR partnerArea);
	
	/// �Đ�����
	void DoSound(ESOUNDNAME name);

	/// �������Ă���
	void VolumeIn(ESOUNDNAME name, int volume = 255);

	/// ��������
	void VolumeReset(ESOUNDNAME name, int volume = 255);

	/// �������
	void Release();

	/// �v���Z�X
	void Process();

	/// �X�e�[�W1����T�E���h
	void StageOneSound(int touchNum);
	void StageOneBallCatch();

	/// �v���C���[�̍��W��ݒ�
	void SetCharaArea(VECTOR area);

	/// ���X�i�[�̍��W��ݒ�
	void SetLisnerArea(VECTOR area);



	void Test();
}