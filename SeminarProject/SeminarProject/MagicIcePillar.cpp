#include "MagicIcePillar.hpp"



/// ------------------------------------------------------------------------------------------
MagicIcePillar::MagicIcePillar()
{
	nowTime = 0;
	playEffect = false;
	area = VGet(0, 0, 0);

	effectAppear = LoadEffekseerEffect("media\\��I�[��\\appear.efk");
	playingEfAppear = -1;

	effectAttack = LoadEffekseerEffect("media\\��I�[��\\ice2.efk");
	playingEfAttack = -1;
}



/// ------------------------------------------------------------------------------------------
MagicIcePillar::~MagicIcePillar()
{
	// �G�t�F�N�g�J��
	StopEffekseer3DEffect(playingEfAttack);
	DeleteEffekseerEffect(effectAttack);
	StopEffekseer3DEffect(playingEfAppear);
	DeleteEffekseerEffect(effectAppear);
}



/// ------------------------------------------------------------------------------------------
void MagicIcePillar::Process()
{
	if (playEffect)
	{
		nowTime++;
		if (nowTime < aliveTime)
		{
			if (IsEffekseer3DEffectPlaying(playingEfAppear) != 0)
			{
				// �o���G�t�F�N�g���Đ�
				playingEfAppear = PlayEffekseer3DEffect(effectAppear);
				SetScalePlayingEffekseer3DEffect(playingEfAppear, 25, 25, 25);
				SetPosPlayingEffekseer3DEffect(playingEfAppear, area.x, area.y, area.z);
			}
		}
		else if (nowTime < aliveTime * 2)
		{
			if (IsEffekseer3DEffectPlaying(playingEfAttack) != 0)
			{
				// �U���G�t�F�N�g���Đ�
				playingEfAttack = PlayEffekseer3DEffect(effectAttack);
				SetScalePlayingEffekseer3DEffect(playingEfAttack, 25, 25, 25);
				SetPosPlayingEffekseer3DEffect(playingEfAttack, area.x, area.y, area.z);
			}
		}
		else playEffect = false;
	}
} /// void MagicIcePillar::Process()



/// ------------------------------------------------------------------------------------------
void MagicIcePillar::Active(VECTOR area)
{
	this->area = area;
	nowTime = 0;
	playEffect = true;
}
