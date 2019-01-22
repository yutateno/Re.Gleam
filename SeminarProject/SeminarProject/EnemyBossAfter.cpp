#include "EnemyBossAfter.hpp"



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::MotionProcess()
{
	// �U���̎��ɂȂ�����
	if (attackMotionNow)
	{
		// ���U�肩�����U����������
		if (e_attackPattern == EAttackPattern::hand)
		{
			// �A�j���[�V������ݒ肷��
			animSpeed = 0.05f;
			Player_PlayAnim(MOTION::attack);
			attackFrame += animSpeed;


			// ���[�V�������I��������
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attack) - 4)
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
		// �X�̒����g���U����������
		else if (e_attackPattern == EAttackPattern::icePillar)
		{
			// �A�j���[�V������ݒ肷��
			animSpeed = 0.4f;
			Player_PlayAnim(MOTION::attackMagic);
			attackFrame += animSpeed;


			// ���[�V�������I��������
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attackMagic))
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
		// �����g���U����������
		else if (e_attackPattern == EAttackPattern::magicBlock)
		{
			// �A�j���[�V������ݒ肷��
			animSpeed = 0.1f;
			Player_PlayAnim(MOTION::attackMagic2);
			attackFrame += animSpeed;


			// ���[�V�������I��������
			if (attackFrame > MV1GetAnimTotalTime(modelHandle, MOTION::attackMagic2))
			{
				attackMotionNow = false;
				attackFrame = 0.0f;
			}
		}
	} /// if (attackMotionNow)
	// �U�����Ȃ��Ƃ�
	else
	{
		// �A�j���[�V������ݒ肷��
		animSpeed = 0.2f;
		Player_PlayAnim(MOTION::idleDevile);
	}
} /// void EnemyBossAfter::MotionProcess()



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::MoveProcess()
{

}



/// ----------------------------------------------------------------------------------------
EnemyBossAfter::EnemyBossAfter(const int modelHandle, const int modelTex0
	, const int modeltex1, const int modelTex2) : BasicCreature(false)
{
	// 3D���f���̓ǂݍ���
	this->modelHandle = -1;
	this->modelHandle = MV1DuplicateModel(modelHandle);

	
	// �e�N�X�`���̓K��
	textureHandle0 = -1;
	textureHandle1 = -1;
	textureHandle2 = -1;
	textureHandle0 = modelTex0;
	textureHandle1 = modeltex1;
	textureHandle2 = modelTex2;
	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 0, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 1, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendMode(this->modelHandle, 2, DX_BLENDMODE_ALPHA);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 0, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 1, blendCount);
	MV1SetMaterialDrawBlendParam(this->modelHandle, 2, blendCount);
	MV1SetMaterialEmiColor(this->modelHandle, 0, GetColorF(1.0f, 1.0f, 1.0f, 1.0f));
	MV1SetMaterialEmiColor(this->modelHandle, 1, GetColorF(0.3f, 0.3f, 0.3f, 1.0f));
	MV1SetMaterialEmiColor(this->modelHandle, 2, GetColorF(0.3f, 0.3f, 0.3f, 1.0f));


	// 3D���f���̃A�j���[�V�������A�^�b�`����
	attachNum = MOTION::idleDevile;
	attachMotion = MV1AttachAnim(this->modelHandle, attachNum, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(this->modelHandle, attachMotion);


	// ������
	modelHeight = 4100.0f;
	modelWidth = 600.0f;
	walkSpeed = 0.0f;
	animSpeed = 0.5f;
	jumpUpNow = false;
	area = VGet(4500.0f, 200.0f, 0.0f);
	angle = DX_PI_F / 2.0f;
	MV1SetScale(this->modelHandle, VGet(25, 25, 25));


	// �U��
	moveCount = 0;
	attackFrame = 0.0f;
	attackDamageNow = false;
	attackStartNow = false;
	e_attackPattern = EAttackPattern::hand;
	e_preAttackPattern = EAttackPattern::hand;


	// ���f���̍��W���X�V
	MV1SetRotationXYZ(this->modelHandle, VGet(0.0f, angle, 0.0f));
	MV1SetPosition(this->modelHandle, this->area);


	// �R���W�������̃Z�b�g�A�b�v
	MV1SetupCollInfo(this->modelHandle, -1);
} /// EnemyBossAfter::EnemyBossAfter(const int modelHandle, const int modelTex0



/// ----------------------------------------------------------------------------------------
EnemyBossAfter::~EnemyBossAfter()
{
	// �e�N�X�`���J��
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);


	// ���f���J��
	MODEL_RELEASE(modelHandle);
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::Draw()
{
#ifdef _DEBUG
	if (MyDebug::enemyThreeSlimeDrawFlag)
	{
		DrawCapsule3D(area, VAdd(area, VGet(0.0f, modelHeight, 0.0f)), modelWidth, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), false);
	}
#endif // _DEBUG
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::DrawWhile()
{
	MV1DrawModel(modelHandle);
}



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::Process()
{
	attackStartNow = false;		// �U�������n�߂ĂȂ��Ƃ���


	// �_���[�W���󂯂���
	if (damageHit) damageHit = false;


	// 300�t���[���ɓ��B������
	if (moveCount++ > moveDoCount)
	{
		// �O��Ƃ͈Ⴄ�U����������
		while (e_preAttackPattern == e_attackPattern)
		{
			std::mt19937 mt(rnd());
			std::uniform_int_distribution<> attackPatternRnd(0, 2);        // ����
			e_attackPattern = static_cast<EAttackPattern>(attackPatternRnd(mt));
		}


		// �U�������s������
		e_preAttackPattern = e_attackPattern;
		attackStartNow = true;
		moveCount = 0;
		attackMotionNow = true;
	}


	// ���[�V�����̎���
	Player_AnimProcess();

	
	// ���[�V�����̃v���Z�X
	MotionProcess();
} /// void EnemyBossAfter::Process()



/// ----------------------------------------------------------------------------------------
void EnemyBossAfter::TextureReload()
{
	GRAPHIC_RELEASE(textureHandle0);
	GRAPHIC_RELEASE(textureHandle1);
	GRAPHIC_RELEASE(textureHandle2);


	switch (BASICPARAM::e_TextureColor)
	{
		// �ʏ�F�ɂ���
	case ETextureColor::NORMAL:
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\wing\\normal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\body\\normal.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\head\\normal.pyn", textureHandle2, ELOADFILE::graph);
		break;
		// D�^�␳�ɂ���
	case ETextureColor::D_CORRECTION:
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\wing\\D.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\body\\D.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\head\\D.pyn", textureHandle2, ELOADFILE::graph);
		break;
		// P�^�␳�ɂ���
	case ETextureColor::P_CORRECTION:
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\wing\\P.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\body\\P.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\head\\P.pyn", textureHandle2, ELOADFILE::graph);
		break;
	default:
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\wing\\normal.pyn", textureHandle0, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\body\\normal.pyn", textureHandle1, ELOADFILE::graph);
		LoadFile::MyLoad("media\\���X�{�X�Q��\\���[�V����\\motion_Boss1.fbm\\head\\normal.pyn", textureHandle2, ELOADFILE::graph);
		break;
	}


	MV1SetTextureGraphHandle(this->modelHandle, 0, textureHandle0, true);
	MV1SetTextureGraphHandle(this->modelHandle, 1, textureHandle1, false);
	MV1SetTextureGraphHandle(this->modelHandle, 2, textureHandle2, false);
} /// void EnemyBossAfter::TextureReload()
