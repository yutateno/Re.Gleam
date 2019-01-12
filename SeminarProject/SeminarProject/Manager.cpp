#include "Manager.hpp"


// �V�[���ύX
void Manager::SceneChange()
{
	// ���̃V�[��
	switch (BASICPARAM::e_nowScene)
	{
	// ���[�u1�̃��[�h
	case ESceneNumber::FIRSTLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u1
	case ESceneNumber::FIRSTMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove1(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	// ���[�u2�̃��[�h
	case ESceneNumber::SECONDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u2
	case ESceneNumber::SECONDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove2(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	// ���[�u3�̃��[�h
	case ESceneNumber::THIRDLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u3
	case ESceneNumber::THIRDMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove3(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	// ���[�u4�̃��[�h
	case ESceneNumber::FOURTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u4
	case ESceneNumber::FOURTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove4(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	// ���[�u5�̃��[�h
	case ESceneNumber::FIFTHLOAD:
		p_loadThread = new LoadThread();
		POINTER_RELEASE(p_baseMove);
		break;


	// ���[�u5
	case ESceneNumber::FIFTHMOVE:
		BASICPARAM::startFeedNow = true;
		feedCount = 255;
		p_baseMove = new MainMove5(p_loadThread->GetFile());
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		POINTER_RELEASE(p_loadThread);
		break;


	default:
		break;
	} /// switch (BASICPARAM::e_nowScene)
} /// void Manager::SceneChange()


// ���[�u1�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove1Load()
{
	// ���f���f�[�^
	move1str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";
	move1str[1] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move1str[2] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.myn";				// 4
	move1str[3] = "media\\������\\media\\��\\sword.myn";								// 1

	// �T�E���h�f�[�^
	move1str[4] = "media\\������\\media\\sound\\�^�C�g���i�I���S�[���j.wyn";
	move1str[5] = "media\\������\\media\\sound\\�ʂ��|�[���i���������ق��j.wyn";
	move1str[6] = "media\\������\\media\\sound\\�ʂ��|�[��.wyn";

	// �L�����N�^�[�̃e�N�X�`���f�[�^
	move1str[7] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_hair.pyn";
	move1str[8] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_ex.pyn";
	move1str[9] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_wear.pyn";
	move1str[10] = "media\\������\\media\\CLPH\\motion\\CLPH_motionALL.fbm\\whiteblack\\CLPH_face.pyn";

	// ���̃e�N�X�`���f�[�^
	move1str[11] = "media\\������\\media\\��\\whiteblack\\sword_Tex.pyn";

	// �R���g���[���[����
	move1str[12] = "media\\������\\media\\move1\\hida.pyn";
	move1str[13] = "media\\������\\media\\move1\\mighi.pyn";


	// ���f���f�[�^
	load1[0] = ELOADFILE::mv1model;
	load1[1] = ELOADFILE::mv1model;
	load1[2] = ELOADFILE::mv1model;
	load1[3] = ELOADFILE::mv1model;

	// �T�E���h�f�[�^
	load1[4] = ELOADFILE::soundStream;
	load1[5] = ELOADFILE::soundmem;
	load1[6] = ELOADFILE::soundmem;

	// �L�����N�^�[�̃e�N�X�`���f�[�^
	load1[7] = ELOADFILE::graph;
	load1[8] = ELOADFILE::graph;
	load1[9] = ELOADFILE::graph;
	load1[10] = ELOADFILE::graph;

	// ���̃e�N�X�`���f�[�^
	load1[11] = ELOADFILE::graph;

	// �R���g���[���[����
	load1[12] = ELOADFILE::graph;
	load1[13] = ELOADFILE::graph;
} /// void Manager::InitMove1Load()


// ���[�u2�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove2Load()
{
	// ���f���f�[�^
	move2str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move2str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move2str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move2str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
	move2str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move2str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
	move2str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
	move2str[7] = "media\\������\\media\\�u���b�N\\cubeblock.myn";					// 1
	move2str[8] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

	// �L�����̃e�N�X�`���f�[�^
	move2str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move2str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move2str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move2str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move2str[13] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// �K�i�̃e�N�X�`���f�[�^
	move2str[14] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// �X���̃e�N�X�`���f�[�^
	move2str[15] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
	move2str[16] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

	// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
	move2str[17] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

	// �u���b�N�̃e�N�X�`��
	move2str[18] = "media\\������\\media\\�u���b�N\\whiteblack\\tex.pyn";

	// �T�E���h�f�[�^
	move2str[19] = "media\\������\\media\\sound\\���܏E����.wyn";

	// ���Z�@�B�f�[�^
	move2str[20] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

	// ���Z�@�B�e�N�X�`��
	move2str[21] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move2str[22] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

	// �����@�B�̕⏕����
	move2str[23] = "media\\������\\media\\Terminal\\push.pyn";

	// �K�i�Ƃ��̂��Ƃ̏��f�[�^
	move2str[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

	// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
	move2str[25] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
	move2str[26] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

	// �K�i�Ə��̂����蔻��f�[�^
	move2str[27] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

	// 2D�֘A
	move2str[28] = "media\\������\\media\\2D�f��\\change\\whiteblack\\block_2D.pyn";
	move2str[29] = "media\\������\\media\\2D�f��\\change\\whiteblack\\CLPH_up.pyn";
	move2str[30] = "media\\������\\media\\2D�f��\\change\\whiteblack\\gaiyou_2D.pyn";
	move2str[31] = "media\\������\\media\\2D�f��\\change\\whiteblack\\kaidan_2d.pyn";
	move2str[32] = "media\\������\\media\\2D�f��\\change\\whiteblack\\Terminal_2D.pyn";
	move2str[33] = "media\\������\\media\\2D�f��\\change\\whiteblack\\kaidan_yuka2D.pyn";

	// �L�����N�^�[�����3DSE
	move2str[34] = "media\\������\\media\\sound\\�W�����v.wyn";
	move2str[35] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
	move2str[36] = "media\\������\\media\\sound\\����.wyn";
	move2str[37] = "media\\������\\media\\sound\\���n.wyn";
	move2str[38] = "media\\������\\media\\sound\\���n�Q.wyn";

	// �L�����N�^�[�̍U���̉�
	move2str[39] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
	move2str[40] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
	move2str[41] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

	// �h���b�v�A�C�e����SE�̓��ޖ�
	move2str[42] = "media\\������\\media\\sound\\���܏E����2.wyn";

	// ���̃X�e�[�W�ł�BGM�𗬂�
	move2str[43] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

	// ����̐���
	move2str[44] = "media\\������\\media\\move2\\attackTrans.pyn";
	move2str[45] = "media\\������\\media\\move2\\jumpTrans.pyn";
	move2str[46] = "media\\������\\media\\move2\\fastSpeedTrans.pyn";
	move2str[47] = "media\\������\\media\\move2\\optionTrans.pyn";


	load2[0] = ELOADFILE::mv1model;
	load2[1] = ELOADFILE::mv1model;
	load2[2] = ELOADFILE::mv1model;
	load2[3] = ELOADFILE::mv1model;
	load2[4] = ELOADFILE::mv1model;
	load2[5] = ELOADFILE::mv1model;
	load2[6] = ELOADFILE::mv1model;
	load2[7] = ELOADFILE::mv1model;
	load2[8] = ELOADFILE::mv1model;

	load2[9] = ELOADFILE::graph;
	load2[10] = ELOADFILE::graph;
	load2[11] = ELOADFILE::graph;
	load2[12] = ELOADFILE::graph;
	load2[13] = ELOADFILE::graph;
	load2[14] = ELOADFILE::graph;
	load2[15] = ELOADFILE::graph;
	load2[16] = ELOADFILE::graph;
	load2[17] = ELOADFILE::graph;
	load2[18] = ELOADFILE::graph;

	load2[19] = ELOADFILE::sound3DSource;

	load2[20] = ELOADFILE::mv1model;

	load2[21] = ELOADFILE::graph;
	load2[22] = ELOADFILE::graph;
	load2[23] = ELOADFILE::graph;

	load2[24] = ELOADFILE::mv1model;

	load2[25] = ELOADFILE::graph;
	load2[26] = ELOADFILE::graph;

	load2[27] = ELOADFILE::mv1model;

	load2[28] = ELOADFILE::graph;
	load2[29] = ELOADFILE::graph;
	load2[30] = ELOADFILE::graph;
	load2[31] = ELOADFILE::graph;
	load2[32] = ELOADFILE::graph;
	load2[33] = ELOADFILE::graph;

	load2[34] = ELOADFILE::sound3DSource;
	load2[35] = ELOADFILE::sound3DSource;
	load2[36] = ELOADFILE::sound3DSource;
	load2[37] = ELOADFILE::sound3DSource;
	load2[38] = ELOADFILE::sound3DSource;

	load2[39] = ELOADFILE::sound3DSource;
	load2[40] = ELOADFILE::sound3DSource;
	load2[41] = ELOADFILE::sound3DSource;

	load2[42] = ELOADFILE::sound3DSource;

	load2[43] = ELOADFILE::soundStream;

	load2[44] = ELOADFILE::graph;
	load2[45] = ELOADFILE::graph;
	load2[46] = ELOADFILE::graph;
	load2[47] = ELOADFILE::graph;
} /// void Manager::InitMove2Load()


// ���[�u3�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove3Load()
{
	// ���f���f�[�^
	move3str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move3str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move3str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move3str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
	move3str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move3str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
	move3str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
	move3str[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

	// �L�����̃e�N�X�`���f�[�^
	move3str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move3str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move3str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move3str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move3str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// �K�i�̃e�N�X�`���f�[�^
	move3str[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// �X���̃e�N�X�`���f�[�^
	move3str[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
	move3str[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

	// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
	move3str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

	// �T�E���h�f�[�^
	move3str[17] = "media\\������\\media\\sound\\���܏E����.wyn";

	// ���Z�@�B�f�[�^
	move3str[18] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

	// ���Z�@�B�e�N�X�`��
	move3str[19] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move3str[20] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

	// �����@�B�̕⏕����
	move3str[21] = "media\\������\\media\\Terminal\\push.pyn";

	// �K�i�Ƃ��̂��Ƃ̏��f�[�^
	move3str[22] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

	// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
	move3str[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
	move3str[24] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

	// �K�i�Ə��̂����蔻��f�[�^
	move3str[25] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

	// �L�����N�^�[�����3DSE
	move3str[26] = "media\\������\\media\\sound\\�W�����v.wyn";
	move3str[27] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
	move3str[28] = "media\\������\\media\\sound\\����.wyn";
	move3str[29] = "media\\������\\media\\sound\\���n.wyn";
	move3str[30] = "media\\������\\media\\sound\\���n�Q.wyn";

	// �L�����N�^�[�̍U���̉�
	move3str[31] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
	move3str[32] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
	move3str[33] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

	// �h���b�v�A�C�e����SE�̓��ޖ�
	move3str[34] = "media\\������\\media\\sound\\���܏E����2.wyn";

	// BGM
	move3str[35] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

	// �G�̃X���C���̃f�[�^
	move3str[36] = "media\\������\\media\\move3\\�C���N�X���C��\\ink_slime_motionALL.myn";
	move3str[37] = "media\\������\\media\\move3\\�C���N�X���C��\\ink_slime_motionALL.fbm\\normal\\Slime_tex.pyn";

	// �G�̃N�������q���[�}���̃f�[�^
	move3str[38] = "media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.myn";
	move3str[39] = "media\\������\\media\\move3\\�l�^�N������\\kureyon_,motionALL.fbm\\normal\\kre.pyn";

	// �h���b�v�A�C�e���̃f�[�^
	move3str[40] = "media\\������\\media\\move3\\�C���N�I��\\ink.myn";
	move3str[41] = "media\\������\\media\\move3\\�C���N�I��\\correction\\normal\\ink.pyn";

	// �_���[�W���o�摜
	move3str[42] = "media\\������\\media\\damage\\damage1\\whiteblack.pyn";
	move3str[43] = "media\\������\\media\\damage\\damage2\\whiteblack.pyn";
	move3str[44] = "media\\������\\media\\damage\\damage3\\whiteblack.pyn";
	move3str[45] = "media\\������\\media\\damage\\Blood\\bl1\\whiteblack.pyn";
	move3str[46] = "media\\������\\media\\damage\\Blood\\bl2\\whiteblack.pyn";
	move3str[47] = "media\\������\\media\\damage\\Blood\\bl3\\whiteblack.pyn";
	move3str[48] = "media\\������\\media\\damage\\Blood\\bl4\\whiteblack.pyn";
	move3str[49] = "media\\������\\media\\damage\\Blood\\bl5\\whiteblack.pyn";
	move3str[50] = "media\\������\\media\\damage\\Blood\\bl6\\whiteblack.pyn";
	move3str[51] = "media\\������\\media\\damage\\Blood\\bl7\\whiteblack.pyn";
	move3str[52] = "media\\������\\media\\damage\\Blood\\bl8\\whiteblack.pyn";
	move3str[53] = "media\\������\\media\\damage\\Blood\\bl9\\whiteblack.pyn";
	move3str[54] = "media\\������\\media\\damage\\Blood\\bl10\\whiteblack.pyn";

	// �G�̍U����
	move3str[55] = "media\\������\\media\\sound\\���鉹�i�����j.wyn";

	// �N�������̎��ʉ�
	move3str[56] = "media\\������\\media\\sound\\�N�������̎�(2).wyn";

	// �U��BGM
	move3str[57] = "media\\������\\media\\sound\\�퓬BGM.wyn";

	load3[0] = ELOADFILE::mv1model;
	load3[1] = ELOADFILE::mv1model;
	load3[2] = ELOADFILE::mv1model;
	load3[3] = ELOADFILE::mv1model;
	load3[4] = ELOADFILE::mv1model;
	load3[5] = ELOADFILE::mv1model;
	load3[6] = ELOADFILE::mv1model;
	load3[7] = ELOADFILE::mv1model;

	load3[8] = ELOADFILE::graph;
	load3[9] = ELOADFILE::graph;
	load3[10] = ELOADFILE::graph;
	load3[11] = ELOADFILE::graph;
	load3[12] = ELOADFILE::graph;

	load3[13] = ELOADFILE::graph;

	load3[14] = ELOADFILE::graph;
	load3[15] = ELOADFILE::graph;

	load3[16] = ELOADFILE::graph;

	load3[17] = ELOADFILE::sound3DSource;

	load3[18] = ELOADFILE::mv1model;

	load3[19] = ELOADFILE::graph;
	load3[20] = ELOADFILE::graph;

	load3[21] = ELOADFILE::graph;

	load3[22] = ELOADFILE::mv1model;

	load3[23] = ELOADFILE::graph;
	load3[24] = ELOADFILE::graph;

	load3[25] = ELOADFILE::mv1model;

	load3[26] = ELOADFILE::sound3DSource;
	load3[27] = ELOADFILE::sound3DSource;
	load3[28] = ELOADFILE::sound3DSource;
	load3[29] = ELOADFILE::sound3DSource;
	load3[30] = ELOADFILE::sound3DSource;

	load3[31] = ELOADFILE::sound3DSource;
	load3[32] = ELOADFILE::sound3DSource;
	load3[33] = ELOADFILE::sound3DSource;

	load3[34] = ELOADFILE::sound3DSource;

	load3[35] = ELOADFILE::soundStream;

	load3[36] = ELOADFILE::mv1model;
	load3[37] = ELOADFILE::graph;

	load3[38] = ELOADFILE::mv1model;
	load3[39] = ELOADFILE::graph;

	load3[40] = ELOADFILE::mv1model;
	load3[41] = ELOADFILE::graph;

	load3[42] = ELOADFILE::graph;
	load3[43] = ELOADFILE::graph;
	load3[44] = ELOADFILE::graph;
	load3[45] = ELOADFILE::graph;
	load3[46] = ELOADFILE::graph;
	load3[47] = ELOADFILE::graph;
	load3[48] = ELOADFILE::graph;
	load3[49] = ELOADFILE::graph;
	load3[50] = ELOADFILE::graph;
	load3[51] = ELOADFILE::graph;
	load3[52] = ELOADFILE::graph;
	load3[53] = ELOADFILE::graph;
	load3[54] = ELOADFILE::graph;

	load3[55] = ELOADFILE::sound3DSource;
	load3[56] = ELOADFILE::sound3DSource;

	load3[57] = ELOADFILE::soundStream;
} /// void Manager::InitMove3Load()


// ���[�u4�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove4Load()
{
	// ���f���f�[�^
	move4str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move4str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move4str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move4str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
	move4str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move4str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
	move4str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
	move4str[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

	// �L�����̃e�N�X�`���f�[�^
	move4str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move4str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move4str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move4str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move4str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// �K�i�̃e�N�X�`���f�[�^
	move4str[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// �X���̃e�N�X�`���f�[�^
	move4str[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
	move4str[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

	// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
	move4str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

	// ���Z�@�B�f�[�^
	move4str[17] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

	// ���Z�@�B�e�N�X�`��
	move4str[18] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move4str[19] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

	// �����@�B�̕⏕����
	move4str[20] = "media\\������\\media\\Terminal\\push.pyn";

	// �K�i�Ƃ��̂��Ƃ̏��f�[�^
	move4str[21] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

	// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
	move4str[22] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
	move4str[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

	// �K�i�Ə��̂����蔻��f�[�^
	move4str[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

	// �L�����N�^�[�����3DSE
	move4str[25] = "media\\������\\media\\sound\\�W�����v.wyn";
	move4str[26] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
	move4str[27] = "media\\������\\media\\sound\\����.wyn";
	move4str[28] = "media\\������\\media\\sound\\���n.wyn";
	move4str[29] = "media\\������\\media\\sound\\���n�Q.wyn";

	// �L�����N�^�[�̍U���̉�
	move4str[30] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
	move4str[31] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
	move4str[32] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

	// BGM
	move4str[33] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

	// �l�̃f�[�^
	move4str[34] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.myn";
	move4str[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\whiteblack\\human_col.pyn";

	// �G�̃f�[�^
	move4str[36] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.myn";
	move4str[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";

	load4[0] = ELOADFILE::mv1model;
	load4[1] = ELOADFILE::mv1model;
	load4[2] = ELOADFILE::mv1model;
	load4[3] = ELOADFILE::mv1model;
	load4[4] = ELOADFILE::mv1model;
	load4[5] = ELOADFILE::mv1model;
	load4[6] = ELOADFILE::mv1model;
	load4[7] = ELOADFILE::mv1model;

	load4[8] = ELOADFILE::graph;
	load4[9] = ELOADFILE::graph;
	load4[10] = ELOADFILE::graph;
	load4[11] = ELOADFILE::graph;
	load4[12] = ELOADFILE::graph;

	load4[13] = ELOADFILE::graph;

	load4[14] = ELOADFILE::graph;
	load4[15] = ELOADFILE::graph;

	load4[16] = ELOADFILE::graph;

	load4[17] = ELOADFILE::mv1model;

	load4[18] = ELOADFILE::graph;
	load4[19] = ELOADFILE::graph;

	load4[20] = ELOADFILE::graph;

	load4[21] = ELOADFILE::mv1model;

	load4[22] = ELOADFILE::graph;
	load4[23] = ELOADFILE::graph;

	load4[24] = ELOADFILE::mv1model;

	load4[25] = ELOADFILE::sound3DSource;
	load4[26] = ELOADFILE::sound3DSource;
	load4[27] = ELOADFILE::sound3DSource;
	load4[28] = ELOADFILE::sound3DSource;
	load4[29] = ELOADFILE::sound3DSource;

	load4[30] = ELOADFILE::sound3DSource;
	load4[31] = ELOADFILE::sound3DSource;
	load4[32] = ELOADFILE::sound3DSource;

	load4[33] = ELOADFILE::soundStream;

	load4[34] = ELOADFILE::mv1model;
	load4[35] = ELOADFILE::graph;

	load4[36] = ELOADFILE::mv1model;
	load4[37] = ELOADFILE::graph;
} /// void Manager::InitMove4Load()


// ���[�u5�̓ǂݍ��ݑf�ނ̏�����
void Manager::InitMove5Load()
{
	// ���f���f�[�^
	move5str[0] = "media\\������\\media\\�X�e�[�W���f��\\move1_hantei.myn";
	move5str[1] = "media\\������\\media\\swordCLPH\\clph_sword_all.myn";			// 5
	move5str[2] = "media\\������\\media\\paneru\\paneru.myn";
	move5str[3] = "media\\������\\media\\kaidan\\kaidan.myn";						// 1
	move5str[4] = "media\\������\\media\\kaidan\\kaidan_hantei.myn";
	move5str[5] = "media\\������\\media\\�X��\\Gaitou.myn";							// 2
	move5str[6] = "media\\������\\media\\�X�J�C�{�b�N�X\\SkyDome.myn";				// 1
	move5str[7] = "media\\������\\media\\�X�e�[�W���f��\\move1_graphic.myn";

	// �L�����̃e�N�X�`���f�[�^
	move5str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\sword_Tex.pyn";
	move5str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_hair.pyn";
	move5str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_wear.pyn";
	move5str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_face.pyn";
	move5str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\whiteblack\\CLPH_ex.pyn";

	// �K�i�̃e�N�X�`���f�[�^
	move5str[13] = "media\\������\\media\\kaidan\\whiteblack\\kaidan.pyn";

	// �X���̃e�N�X�`���f�[�^
	move5str[14] = "media\\������\\media\\�X��\\whiteblack\\body_col.pyn";
	move5str[15] = "media\\������\\media\\�X��\\whiteblack\\lamp_COLandems.pyn";

	// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
	move5str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\whiteblack\\BlueSky.byn";

	// ���Z�@�B�f�[�^
	move5str[17] = "media\\������\\media\\Terminal\\terminal.myn";					// 2

	// ���Z�@�B�e�N�X�`��
	move5str[18] = "media\\������\\media\\Terminal\\whiteblack\\Terminal.pyn";
	move5str[19] = "media\\������\\media\\Terminal\\whiteblack\\T_display.pyn";

	// �����@�B�̕⏕����
	move5str[20] = "media\\������\\media\\Terminal\\push.pyn";

	// �K�i�Ƃ��̂��Ƃ̏��f�[�^
	move5str[21] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1.myn";			// 2

	// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
	move5str[22] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\kaidan.pyn";
	move5str[23] = "media\\������\\media\\�K�i�Ə�����\\whiteblack\\yuka.pyn";

	// �K�i�Ə��̂����蔻��f�[�^
	move5str[24] = "media\\������\\media\\�K�i�Ə�����\\kaidan_yuka1_hantei.myn";

	// �L�����N�^�[�����3DSE
	move5str[25] = "media\\������\\media\\sound\\�W�����v.wyn";
	move5str[26] = "media\\������\\media\\sound\\�����i�L�����ۂ��́j.wyn";
	move5str[27] = "media\\������\\media\\sound\\����.wyn";
	move5str[28] = "media\\������\\media\\sound\\���n.wyn";
	move5str[29] = "media\\������\\media\\sound\\���n�Q.wyn";

	// �L�����N�^�[�̍U���̉�
	move5str[30] = "media\\������\\media\\sound\\�s�A�m�R���{�ꔭ��.wyn";
	move5str[31] = "media\\������\\media\\sound\\�s�A�m�R���{�񔭖�.wyn";
	move5str[32] = "media\\������\\media\\sound\\�s�A�m�R���{�O����.wyn";

	// BGM
	move5str[33] = "media\\������\\media\\sound\\�ʏ�bgm.wyn";

	load5[0] = ELOADFILE::mv1model;
	load5[1] = ELOADFILE::mv1model;
	load5[2] = ELOADFILE::mv1model;
	load5[3] = ELOADFILE::mv1model;
	load5[4] = ELOADFILE::mv1model;
	load5[5] = ELOADFILE::mv1model;
	load5[6] = ELOADFILE::mv1model;
	load5[7] = ELOADFILE::mv1model;

	load5[8] = ELOADFILE::graph;
	load5[9] = ELOADFILE::graph;
	load5[10] = ELOADFILE::graph;
	load5[11] = ELOADFILE::graph;
	load5[12] = ELOADFILE::graph;

	load5[13] = ELOADFILE::graph;

	load5[14] = ELOADFILE::graph;
	load5[15] = ELOADFILE::graph;

	load5[16] = ELOADFILE::graph;

	load5[17] = ELOADFILE::mv1model;

	load5[18] = ELOADFILE::graph;
	load5[19] = ELOADFILE::graph;

	load5[20] = ELOADFILE::graph;

	load5[21] = ELOADFILE::mv1model;

	load5[22] = ELOADFILE::graph;
	load5[23] = ELOADFILE::graph;

	load5[24] = ELOADFILE::mv1model;

	load5[25] = ELOADFILE::sound3DSource;
	load5[26] = ELOADFILE::sound3DSource;
	load5[27] = ELOADFILE::sound3DSource;
	load5[28] = ELOADFILE::sound3DSource;
	load5[29] = ELOADFILE::sound3DSource;

	load5[30] = ELOADFILE::sound3DSource;
	load5[31] = ELOADFILE::sound3DSource;
	load5[32] = ELOADFILE::sound3DSource;

	load5[33] = ELOADFILE::soundStream;
} /// void Manager::InitMove5Load()


// ���[�u3�̍s������Ń��[�u4�̓ǂݍ��ޑf�ނ��X�V
void Manager::Move4TextureReload()
{
	switch (BASICPARAM::e_TextureColor)
	{
	case ETextureColor::NORMAL:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			move4str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\sword_Tex.pyn";
			move4str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_hair.pyn";
			move4str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_wear.pyn";
			move4str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_face.pyn";
			move4str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\normal\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			move4str[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			move4str[14] = "media\\������\\media\\�X��\\normal\\body_col.pyn";
			move4str[15] = "media\\������\\media\\�X��\\normal\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			move4str[22] = "media\\������\\media\\�K�i�Ə�����\\normal\\kaidan.pyn";
			move4str[23] = "media\\������\\media\\�K�i�Ə�����\\normal\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			move4str[13] = "media\\������\\media\\kaidan\\normal\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			move4str[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\normal\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			move4str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\normal\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			move4str[18] = "media\\������\\media\\Terminal\\normal\\Terminal.pyn";
			move4str[19] = "media\\������\\media\\Terminal\\normal\\T_display.pyn";
		}
		break;
		

	case ETextureColor::P_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			move4str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\sword_Tex.pyn";
			move4str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_hair.pyn";
			move4str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_wear.pyn";
			move4str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_face.pyn";
			move4str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\P\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			move4str[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			move4str[14] = "media\\������\\media\\�X��\\P\\body_col.pyn";
			move4str[15] = "media\\������\\media\\�X��\\P\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			move4str[22] = "media\\������\\media\\�K�i�Ə�����\\P\\kaidan.pyn";
			move4str[23] = "media\\������\\media\\�K�i�Ə�����\\P\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			move4str[13] = "media\\������\\media\\kaidan\\P\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			move4str[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\P\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			move4str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\P\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			move4str[18] = "media\\������\\media\\Terminal\\P\\Terminal.pyn";
			move4str[19] = "media\\������\\media\\Terminal\\P\\T_display.pyn";
		}
		break;


	case ETextureColor::D_CORRECTION:
		if (!BASICPARAM::charaTextureWhiteBlack)
		{
			// �L�����̃e�N�X�`���f�[�^
			move4str[8] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\sword_Tex.pyn";
			move4str[9] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_hair.pyn";
			move4str[10] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_wear.pyn";
			move4str[11] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_face.pyn";
			move4str[12] = "media\\������\\media\\swordCLPH\\clph_sword_all.fbm\\D\\CLPH_ex.pyn";
		}
		if (!BASICPARAM::enemyTextureWhiteBlack)
		{
			move4str[37] = "media\\������\\media\\move4\\�l�i�G�j\\ene_human_motionALL.fbm\\whiteblack\\whiteblack.pyn";
		}
		if (!BASICPARAM::lightStreetTextureWhiteBlack)
		{
			// �X���̃e�N�X�`���f�[�^
			move4str[14] = "media\\������\\media\\�X��\\D\\body_col.pyn";
			move4str[15] = "media\\������\\media\\�X��\\D\\lamp_COLandems.pyn";
		}
		if (!BASICPARAM::stairsRoadTextureWhiteBlack)
		{
			// �K�i�Ƃ��̂��Ƃ̏��̃e�N�X�`���f�[�^
			move4str[22] = "media\\������\\media\\�K�i�Ə�����\\D\\kaidan.pyn";
			move4str[23] = "media\\������\\media\\�K�i�Ə�����\\D\\yuka.pyn";
		}
		if (!BASICPARAM::stairsTextureWhiteBlack)
		{
			// �K�i�̃e�N�X�`���f�[�^
			move4str[13] = "media\\������\\media\\kaidan\\D\\kaidan.pyn";
		}
		if (!BASICPARAM::anothreTextureWhiteBlack)
		{
			// �l�̃f�[�^
			move4str[35] = "media\\������\\media\\move4\\��ʐl�Q���̂P\\human1_motionALL.fbm\\D\\human_col.pyn";

			// �X�J�C�{�b�N�X�̃e�N�X�`���f�[�^
			move4str[16] = "media\\������\\media\\�X�J�C�{�b�N�X\\D\\BlueSky.byn";

			// ���Z�@�B�e�N�X�`��
			move4str[18] = "media\\������\\media\\Terminal\\D\\Terminal.pyn";
			move4str[19] = "media\\������\\media\\Terminal\\D\\T_display.pyn";
		}
		break;


	default:
		break;
	}
} /// void Manager::Move4TextureReload()


void Manager::OptionProcess()
{
	///�펞-------------------------------------------------------------------------------------------------------
	// BGM���ʒ����R�}���h��I�����Ă�����
	if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
	{
		// �E�ɃX�e�B�b�N��|���Ă�����
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// BGM�̐ݒ艹�ʂ��グ��
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() < 1.00f ? SoundProcess::GetBGMVolumeEntire() + 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
		// ���ɃX�e�B�b�N��|���Ă�����
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// BGM�̐ݒ艹�ʂ�������
			SoundProcess::SetBGMVolumeEntire(SoundProcess::GetBGMVolumeEntire() > 0.00f ? SoundProcess::GetBGMVolumeEntire() - 0.01f : SoundProcess::GetBGMVolumeEntire());
		}
	}
	// SE���ʒ����R�}���h��I�����Ă�����
	else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
	{
		// 61�J�E���g�̂��т�SE��炷
		if (++seDoWaitTimer > 60)
		{
			seDoWaitTimer = 0;
			SoundProcess::DoSound(SoundProcess::ESOUNDNAME_SE::ballPawnHigh);
		}


		// �E�ɃX�e�B�b�N��|���Ă�����
		if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) > 0)
		{
			// SE�̐ݒ艹�ʂ��グ��
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() < 1.00f ? SoundProcess::GetSEVolumeEntire() + 0.01f : SoundProcess::GetSEVolumeEntire());
		}
		// ���ɃX�e�B�b�N��|���Ă�����
		else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_X) < 0)
		{
			// SE�̐ݒ艹�ʂ�������
			SoundProcess::SetSEVolumeEntire(SoundProcess::GetSEVolumeEntire() > 0.00f ? SoundProcess::GetSEVolumeEntire() - 0.01f : SoundProcess::GetSEVolumeEntire());
		}
	}
	///�펞-------------------------------------------------------------------------------------------------------


	///����-------------------------------------------------------------------------------------------------------
	// ����{�^�����������Ƃ��̓���
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	{
		// BGM�ɃJ�[�\�����������Ƃ�
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			// BGM�ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::BGMSelect;
			optionSelectMin = 8;
			optionSelectMax = 8;
		}
		// SE�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// SE�ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::SESelect;
			optionSelectMin = 9;
			optionSelectMax = 9;
		}
		// �e�N�X�`���F�̒ʏ�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			// �ʏ�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::NORMAL;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �e�N�X�`���F��P�^�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			// P�^�␳�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::P_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �e�N�X�`���F��D�^�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// D�^�␳�F�ɕς���
			BASICPARAM::e_TextureColor = ETextureColor::D_CORRECTION;
			if (BASICPARAM::e_TextureColor != BASICPARAM::e_preTextureColor)
			{
				BASICPARAM::e_preTextureColor = BASICPARAM::e_TextureColor;
				p_baseMove->ThsTextureReload();		// �e�N�X�`���؂�ւ�
			}
		}
		// �F�o�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorSelect
			&& BASICPARAM::e_nowScene >= ESceneNumber::THIRDMOVE)
		{
			// �ʏ�F�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::ColorNormal;
			optionSelectMin = 5;
			optionSelectMax = 7;
		}
		// �T�E���h�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			// BGM�ɃJ�[�\�����ڂ�
			SoundProcess::SetOptionMenuNow(false);				// �T�E���h�̉��ʂ��I�v�V�����p�����߂�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		// BGM�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGM�̐ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		// SE�I���ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SE�̐ݒ艹�ʂɈڂ�
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		// �J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			// ���ߖ@�J�����Ɉڂ�
			optionSelectButtonNum = EOptionSelectButton::CameraPerspective;
			optionSelectMin = 10;
			optionSelectMax = 13;
		}
		// ���ߖ@�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			// �J���������ߖ@�J�����ɐݒ肷��
			BASICPARAM::nowCameraOrtho = false;
		}
		// ���ˉe�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			// �J�����𐳎ˉe�J�����ɐݒ肷��
			BASICPARAM::nowCameraOrtho = true;
		}
		// ����]�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			// ����]�̃X�e�B�b�N�������t�ɂ���
			BASICPARAM::cameraHorizonReturn = !BASICPARAM::cameraHorizonReturn;
		}
		// �c��]�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// �c��]�̃X�e�B�b�N�������t�ɂ���
			BASICPARAM::cameraVerticalReturn = !BASICPARAM::cameraVerticalReturn;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_A) == 1)
	///����------------------------------------------------------------------------------------------------------


	///�߂�-------------------------------------------------------------------------------------------------------
	// �߂�{�^�����������Ƃ��̓���
	if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	{
		// BGM�ɃJ�[�\�����������Ƃ�
		if (optionSelectButtonNum == EOptionSelectButton::BGM
			|| optionSelectButtonNum == EOptionSelectButton::SE)
		{
			// �T�E���h�ɃJ�[�\�����ڂ�
			SoundProcess::SetOptionMenuNow(true);					// �T�E���h�̉��ʂ��I�v�V�����p����ɖ߂�
			optionSelectButtonNum = EOptionSelectButton::Sound;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		// �ʏ�F�ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::ColorNormal
			|| optionSelectButtonNum == EOptionSelectButton::ColorP
			|| optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			// �F�o�I���ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::ColorSelect;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
		// BGM���ʒ����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			// BGM�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::BGM;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		// SE���ʒ����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			// SE�ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::SE;
			optionSelectMin = 3;
			optionSelectMax = 4;
		}
		// ���ߖ@�J�����ɃJ�[�\�����������Ƃ�
		else if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective
			|| optionSelectButtonNum == EOptionSelectButton::CameraOrtho
			|| optionSelectButtonNum == EOptionSelectButton::CameraHReturn
			|| optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			// �J�����ɃJ�[�\�����ڂ�
			optionSelectButtonNum = EOptionSelectButton::Camera;
			optionSelectMin = 0;
			optionSelectMax = 2;
		}
	} /// if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_B) == 1)
	///�߂�------------------------------------------------------------------------------------------------------


	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
	// ���X�e�B�b�N����ɓ|������
	if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) > 0)
	{
		if(optionControllLeftStickY[0] < 2) optionControllLeftStickY[0]++;
	}
	// ���X�e�B�b�N�����ɓ|������
	else if (DLLXinput::GetPadThumbData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::STICK_LEFT_Y) < 0)
	{
		if (optionControllLeftStickY[1] < 2) optionControllLeftStickY[1]++;
	}
	// ���X�e�B�b�N����ɘM���ĂȂ�������
	else
	{
		optionControllLeftStickY[0] = 0;
		optionControllLeftStickY[1] = 0;
	}


	// ��ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[0] == 1)
	{
		// �J�[�\������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp > optionSelectMin ? --temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect) optionPageNowNumber = 0;
	}
	// ���ɃX�e�B�b�N��|�����Ƃ�
	if (optionControllLeftStickY[1] == 1)
	{
		// �J�[�\�������Ɉړ�����
		int temp = static_cast<int>(optionSelectButtonNum);
		optionSelectButtonNum = static_cast<EOptionSelectButton>(temp < optionSelectMax ? ++temp : temp);
		if (optionSelectButtonNum == EOptionSelectButton::Camera) optionPageNowNumber = 1;
	}
	/// �X�e�B�b�N�̈�񉟂��|���ōX�V����悤����-----------------------------------------------------------------
} /// void Manager::OptionProcess()


// �I�v�V������ʂ̕`��
void Manager::OptionDraw()
{
	// �w�i
	DrawGraph(0, 0, gaussianScreen, false);


	//�@���f���\��
	p_baseMove->OptionActorModel();


	// �I�v�V��������߂�����摜
	DrawGraph(1600, 800, optionDrawMedia[static_cast<int>(EOptionDraw::optionEnd)], true);


	// ���ڂ̃I�v�V�����̂Ƃ�
	if (optionPageNowNumber == 0)
	{
		/// �T�E���h�֌W�I�v�V����---------------------------------------------------------------
		// UI:Sound
		DrawGraph(95, 95, optionDrawMedia[static_cast<int>(EOptionDraw::Sound)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::Sound)
		{
			DrawBox(95 + 5, 95 + 5, 95 + 211 - 5, 95 + 86 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 95 + 4, 95 + 211 - 4, 95 + 86 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 95 + 3, 95 + 211 - 3, 95 + 86 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGM
		DrawGraph(381, 114, optionDrawMedia[static_cast<int>(EOptionDraw::BGM)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::BGM)
		{
			DrawBox(381 + 5, 114 + 5, 381 + 87 - 5, 114 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(381 + 4, 114 + 4, 381 + 87 - 4, 114 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(381 + 3, 114 + 3, 381 + 87 - 3, 114 + 58 - 3, GetColor(50, 50, 200), false);
		}


		// UI:BGM�o�[
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(200, 200, 200), true);
		DrawBox(546, 100, 546 + 548, 100 + 81, GetColor(0, 0, 0), false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::BGMSelect)
		{
			DrawBox(546 + 5, 100 + 5, 546 + 548 - 5, 100 + 81 - 5, GetColor(50, 50, 200), false);
			DrawBox(546 + 4, 100 + 4, 546 + 548 - 4, 100 + 81 - 4, GetColor(50, 50, 200), false);
			DrawBox(546 + 3, 100 + 3, 546 + 548 - 3, 100 + 81 - 3, GetColor(50, 50, 200), false);
		}
		DrawBox(546 - 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 547)
			, 100 - 10, 546 + 5 + static_cast<int>(SoundProcess::GetBGMVolumeEntire() * 548)
			, 100 + 81 + 10, GetColor(255, 255, 255), true);


		// UI:SE
		DrawGraph(385, 266, optionDrawMedia[static_cast<int>(EOptionDraw::SE)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::SE)
		{
			DrawBox(385 + 5, 266 + 5, 385 + 86 - 5, 266 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 266 + 4, 385 + 86 - 4, 266 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 266 + 3, 385 + 86 - 3, 266 + 58 - 3, GetColor(50, 50, 200), false);
		}

		// UI:SE�o�[
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(200, 200, 200), true);
		DrawBox(548, 255, 548 + 547, 255 + 78, GetColor(0, 0, 0), false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::SESelect)
		{
			DrawBox(548 + 5, 255 + 5, 548 + 547 - 5, 255 + 78 - 5, GetColor(50, 50, 200), false);
			DrawBox(548 + 4, 255 + 4, 548 + 547 - 4, 255 + 78 - 4, GetColor(50, 50, 200), false);
			DrawBox(548 + 3, 255 + 3, 548 + 547 - 3, 255 + 78 - 3, GetColor(50, 50, 200), false);
		}
		DrawBox(548 - 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 - 10, 548 + 5 + static_cast<int>(SoundProcess::GetSEVolumeEntire() * 547)
			, 255 + 78 + 10, GetColor(255, 255, 255), true);
		/// �T�E���h�֌W�I�v�V����---------------------------------------------------------------


		/// �F�o�Ɋւ���I�v�V����-----------------------------------------------------------------------
		// �F�o�␳�ł��郀�[�u����Ȃ�������
		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);


		// UI:�F�o����
		DrawGraph(96, 413, optionDrawMedia[static_cast<int>(EOptionDraw::Color)], false);


		// UI:�ʏ�F
		DrawGraph(385, 427, optionDrawMedia[static_cast<int>(EOptionDraw::ColorNormal)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorNormal)
		{
			DrawBox(385 + 5, 427 + 5, 385 + 83 - 5, 427 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 427 + 4, 385 + 83 - 4, 427 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 427 + 3, 385 + 83 - 3, 427 + 58 - 3, GetColor(50, 50, 200), false);
		}

		// UI:P�^
		DrawGraph(386, 550, optionDrawMedia[static_cast<int>(EOptionDraw::ColorP)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorP)
		{
			DrawBox(386 + 5, 550 + 5, 386 + 83 - 5, 550 + 59 - 5, GetColor(50, 50, 200), false);
			DrawBox(386 + 4, 550 + 4, 386 + 83 - 4, 550 + 59 - 4, GetColor(50, 50, 200), false);
			DrawBox(386 + 3, 550 + 3, 386 + 83 - 3, 550 + 59 - 3, GetColor(50, 50, 200), false);
		}

		// UI:D�^
		DrawGraph(385, 682, optionDrawMedia[static_cast<int>(EOptionDraw::ColorD)], false);
		// �J�[�\�����������Ă�����
		if (optionSelectButtonNum == EOptionSelectButton::ColorD)
		{
			DrawBox(385 + 5, 682 + 5, 385 + 83 - 5, 682 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 682 + 4, 385 + 83 - 4, 682 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 682 + 3, 385 + 83 - 3, 682 + 58 - 3, GetColor(50, 50, 200), false);
		}


		if (BASICPARAM::e_nowScene < ESceneNumber::THIRDMOVE) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


		// �F�o�␳�ɃJ�[�\�����������Ă�����(�u�����h���瓦��������
		if (optionSelectButtonNum == EOptionSelectButton::ColorSelect)
		{
			DrawBox(96 + 5, 413 + 5, 96 + 112 - 5, 413 + 76 - 5, GetColor(50, 50, 200), false);
			DrawBox(96 + 4, 413 + 4, 96 + 112 - 4, 413 + 76 - 4, GetColor(50, 50, 200), false);
			DrawBox(96 + 3, 413 + 3, 96 + 112 - 3, 413 + 76 - 3, GetColor(50, 50, 200), false);
		}
		/// �F�o�Ɋւ���I�v�V����-----------------------------------------------------------------------


		// ���̃y�[�W
		DrawGraph(96, 815, optionDrawMedia[static_cast<int>(EOptionDraw::nextPage)], false);
	} /// if (optionPageNowNumber == 0)
	// ��y�[�W�ڂ̎�
	else if (optionPageNowNumber == 1)
	{
		// �O�̃y�[�W��
		DrawGraph(96, 95, optionDrawMedia[static_cast<int>(EOptionDraw::prevPage)], false);


		/// �J�����̊ւ���I�v�V����------------------------------------------------
		// �J����
		DrawGraph(95, 247, optionDrawMedia[static_cast<int>(EOptionDraw::Camera)], false);
		if (optionSelectButtonNum == EOptionSelectButton::Camera)
		{
			DrawBox(95 + 5, 247 + 5, 95 + 109 - 5, 247 + 68 - 5, GetColor(50, 50, 200), false);
			DrawBox(95 + 4, 247 + 4, 95 + 109 - 4, 247 + 68 - 4, GetColor(50, 50, 200), false);
			DrawBox(95 + 3, 247 + 3, 95 + 109 - 3, 247 + 68 - 3, GetColor(50, 50, 200), false);
		}

		// ���ߖ@
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 267, optionDrawMedia[static_cast<int>(EOptionDraw::Perspective)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraPerspective)
		{
			DrawBox(385 + 5, 267 + 5, 385 + 83 - 5, 267 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 267 + 4, 385 + 83 - 4, 267 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 267 + 3, 385 + 83 - 3, 267 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// ���ˉe
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 400, optionDrawMedia[static_cast<int>(EOptionDraw::Ortho)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraOrtho)
		{
			DrawBox(385 + 5, 400 + 5, 385 + 83 - 5, 400 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 400 + 4, 385 + 83 - 4, 400 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 400 + 3, 385 + 83 - 3, 400 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::nowCameraOrtho) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// �����]
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 513, optionDrawMedia[static_cast<int>(EOptionDraw::HorizonReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraHReturn)
		{
			DrawBox(385 + 5, 513 + 5, 385 + 83 - 5, 513 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 513 + 4, 385 + 83 - 4, 513 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 513 + 3, 385 + 83 - 3, 513 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraHorizonReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		// �c���]
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);
		DrawGraph(385, 646, optionDrawMedia[static_cast<int>(EOptionDraw::VerticalReturn)], false);
		if (optionSelectButtonNum == EOptionSelectButton::CameraVReturn)
		{
			DrawBox(385 + 5, 646 + 5, 385 + 83 - 5, 646 + 58 - 5, GetColor(50, 50, 200), false);
			DrawBox(385 + 4, 646 + 4, 385 + 83 - 4, 646 + 58 - 4, GetColor(50, 50, 200), false);
			DrawBox(385 + 3, 646 + 3, 385 + 83 - 3, 646 + 58 - 3, GetColor(50, 50, 200), false);
		}
		if (!BASICPARAM::cameraVerticalReturn) SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	} /// else if (optionPageNowNumber == 1)
} /// void Manager::OptionDraw()


// �R���X�g���N�^
Manager::Manager()
{
	// ������
	BASICPARAM::e_preScene = ESceneNumber::THIRDLOAD;
	BASICPARAM::e_nowScene = ESceneNumber::THIRDLOAD;
	BASICPARAM::e_preTextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::e_TextureColor = ETextureColor::WHITEBLACK;
	BASICPARAM::nowCameraOrtho = false;
	BASICPARAM::cameraHorizonReturn = false;
	BASICPARAM::cameraVerticalReturn = false;
	BASICPARAM::charaTextureWhiteBlack = true;
	BASICPARAM::enemyTextureWhiteBlack = true;
	BASICPARAM::lightStreetTextureWhiteBlack = true;
	BASICPARAM::stairsRoadTextureWhiteBlack = true;
	BASICPARAM::stairsTextureWhiteBlack = true;
	BASICPARAM::anothreTextureWhiteBlack = true;


	// �V�[���P�̑f�ރt�@�C��
	InitMove1Load();


	// �V�[���Q�̑f�ރt�@�C��
	InitMove2Load();


	// ���[�u3�̃��[�h�f��
	InitMove3Load();


	// ���[�u4�̃��[�h�f��
	InitMove4Load();


	// ���[�u5�̃��[�h�f��
	InitMove5Load();


	// �������̏�����
	p_baseMove = nullptr;
	p_loadThread = nullptr;


	// �ŏ��̃��[�h�𐶐�
	p_loadThread = new LoadThread();
	preLoadScene = false;


	// ��ʂɊւ���
	gaussianScreen = MakeScreen(1920, 1080);


	// �I�v�V�����Ɋւ���
	optionMenuNow = false;
	optionControllLeftStickY[0] = 0;
	optionControllLeftStickY[1] = 0;
	optionPageNowNumber = 0;
	optionSelectMin = 0;
	optionSelectMax = 2;
	seDoWaitTimer = 0;
	for (int i = 0; i != optionDrawNum; ++i)
	{
		optionDrawMedia[i] = -1;
	}
	LoadFile::MyLoad("media\\������\\media\\option\\BGM.pyn", optionDrawMedia[0], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\camera.pyn", optionDrawMedia[1], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\D�^.pyn", optionDrawMedia[2], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\P�^.pyn", optionDrawMedia[3], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\SE.pyn", optionDrawMedia[4], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\Sound.pyn", optionDrawMedia[5], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\���ߖ@.pyn", optionDrawMedia[6], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�F�o����.pyn", optionDrawMedia[7], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\���ˉe.pyn", optionDrawMedia[8], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�ʏ�F.pyn", optionDrawMedia[9], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�����].pyn", optionDrawMedia[10], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\�c���].pyn", optionDrawMedia[11], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\nextPage.pyn", optionDrawMedia[12], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\prevPage.pyn", optionDrawMedia[13], ELOADFILE::graph);
	LoadFile::MyLoad("media\\������\\media\\option\\optionEnd.pyn", optionDrawMedia[14], ELOADFILE::graph);


	// �t�F�[�h�����Ɋւ���
	feedCount = 0;
	BASICPARAM::endFeedNow = false;
	BASICPARAM::startFeedNow = false;
	feedDraw = GetColor(0, 0, 0);


	// �A���`�G�C���A�V���O�Ɋւ���
	SetCreateDrawValidGraphMultiSample(4, 4);			// 4x4�̃A���`�G�C���A�V���O���[�h�ɂ���
	antiAliasScreen = MakeScreen(1920, 1080, false);	// �A���`�G�C���A�V���O�p�̉�ʂ��쐬
	SetCreateDrawValidGraphMultiSample(0, 0);			// ���ɖ߂�
} /// Manager::Manager()


// �f�X�g���N�^
Manager::~Manager()
{
	for (int i = 0; i != optionDrawNum; ++i)
	{
		GRAPHIC_RELEASE(optionDrawMedia[i]);
	}
	GRAPHIC_RELEASE(gaussianScreen);
	GRAPHIC_RELEASE(antiAliasScreen);


	POINTER_RELEASE(p_baseMove);
	POINTER_RELEASE(p_loadThread);
}


// �X�V
void Manager::Update()
{
	// ���̃V�[���ƒ��O�̃V�[��������
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)		
	{
		// �ŏ��̃��[�u�̃��[�h��������
		if (BASICPARAM::e_preScene == ESceneNumber::FIRSTLOAD)		
		{
			p_loadThread->Process(max1, move1str, load1);		// ���[�h������


			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max1)		
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h�������Ƃ���
				BASICPARAM::e_nowScene = ESceneNumber::FIRSTMOVE;	// ���̃V�[�����w�肷��
			}
		}
		// ��Ԗڂ̃��[�u�̃��[�h��������
		else if (BASICPARAM::e_preScene == ESceneNumber::SECONDLOAD)
		{
			p_loadThread->Process(max2, move2str, load2);		// ���[�h������


			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max2)		
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h��������
				BASICPARAM::e_nowScene = ESceneNumber::SECONDMOVE;	// ���̃V�[�����w�肷��
			}
		}
		// �O�Ԗڂ̃��[�u�̃��[�h��������
		else if (BASICPARAM::e_preScene == ESceneNumber::THIRDLOAD)
		{
			p_loadThread->Process(max3, move3str, load3);		// ���[�h������


			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max3)
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h��������
				BASICPARAM::e_nowScene = ESceneNumber::THIRDMOVE;	// ���̃V�[�����w�肷��
			}
		}
		// �l�Ԗڂ̃��[�u�̃��[�h��������
		else if (BASICPARAM::e_preScene == ESceneNumber::FOURTHLOAD)
		{
			p_loadThread->Process(max4, move4str, load4);		// ���[�h������


			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max4)
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h��������
				BASICPARAM::e_nowScene = ESceneNumber::FOURTHMOVE;	// ���̃V�[�����w�肷��
			}
		}
		// �ܔԖڂ̃��[�u�̃��[�h��������
		else if (BASICPARAM::e_preScene == ESceneNumber::FIFTHLOAD)
		{
			p_loadThread->Process(max5, move5str, load5);		// ���[�h������


			// ���[�h���I��������
			if (p_loadThread->GetNum() >= max5)
			{
				BASICPARAM::endFeedNow = true;						// �I���t�F�[�h�̃t���b�O�𗧂Ă�
				preLoadScene = true;								// ���O�����[�h��������
				BASICPARAM::e_nowScene = ESceneNumber::FIFTHMOVE;	// ���̃V�[�����w�肷��
			}
		}
		// ���[�h�ł͂Ȃ��Q�[����������
		else
		{
			preLoadScene = false;		// ���O�����[�h�ł͂Ȃ��Ƃ���


			// �I�v�V�������j���[�łȂ��Ƃ�
			if (!optionMenuNow)
			{
				// �J�n�t�F�[�h���I�����Ă�����
				if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
				{
					// �A���`�G�C���A�X��ʂɑ΂��ĕ`�揈�����s��
					SetDrawScreen(antiAliasScreen);
					ClearDrawScreen();


					// �Q�[���Ɋւ���
					p_baseMove->CameraProcess();
					p_baseMove->Draw();


					// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
					DrawEffekseer3D();
					// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
					DrawEffekseer2D();


					BASICPARAM::e_nowScene = p_baseMove->GetScene();


					// �A���`�G�C���A�X��ʂɕ`�悵�����̂𗠉�ʂɏ�������
					SetDrawScreen(DX_SCREEN_BACK);
					DrawGraph(0, 0, antiAliasScreen, false);


					// �Q�[���Ɋւ���
					p_baseMove->CameraProcess();				// SetDrawScreen���s���ƃJ�����̐ݒ肪�Ȃ��Ȃ�̂ōĐݒ���s��
					p_baseMove->Process();


					// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
					UpdateEffekseer3D();
					// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
					UpdateEffekseer2D();


					// �I�v�V������ʂɈڍs����R�}���h�������ꂽ��A�܂��̓E�B���h�E�Y����A�N�e�B�u�ɂȂ�����
					if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1
						|| !GetWindowActiveFlag())
					{
						// ���݂̉�ʂ��L���v�`������
						GetDrawScreenGraph(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, gaussianScreen);	


						GraphFilter(gaussianScreen, DX_GRAPH_FILTER_GAUSS, 8, 1400);	// ���݂̉�ʂɃK�E�X�t�B���^�����Ăڂ���	


						p_baseMove->OptionActorModelBefore();							// �I�v�V�����p�̃��f���\���̏���
						


						optionMenuNow = true;											// �I�v�V�������j���[�Ɉڍs����t���b�O�𗧂Ă�


						optionSelectButtonNum = EOptionSelectButton::Sound;				// �I�v�V�������j���[�̃{�^���ʒu��������


						optionPageNowNumber = 0;										// �I�v�V�����̃y�[�W��1�y�[�W�ڂɂ���


						SoundProcess::SetOptionMenuNow(true);							// �T�E���h���ʂ��I�v�V�������j���[�p�ɉ�����悤����

					}
#ifdef _DEBUG
					MyDebug::DebugProcess();
#endif // _DEBUG
					ScreenFlip();
				} /// if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/)
				// �J�n�t�F�[�h�������Ă�����
				else
				{
					feedCount -= 5;						// �t�F�[�h�J�E���g��������			


					// ��ʂɊւ����A
					ClearDrawScreen();
					SetDrawScreen(DX_SCREEN_BACK);


					// �Q�[���Ɋւ����A
					p_baseMove->CameraProcess();
					p_baseMove->Draw();


					// �t�F�[�h�C������
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
					DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


					// �t�F�[�h�J�E���g��������܂�������J�n�t�F�[�h�t���b�O������
					if (feedCount <= 0)
					{
						feedCount = 0;
						BASICPARAM::startFeedNow = false;
					}


					ScreenFlip();
				} /// else(!if (!BASICPARAM::startFeedNow/* && !BASICPARAM::endFeedNow*/))
			} /// if (!optionMenuNow)
			// �I�v�V�������j���[�̂Ƃ�
			else
			{
				// ��ʂɊւ����A
				ClearDrawScreen();


				// �I�v�V�����Ɋւ���
				OptionDraw();
				OptionProcess();


				// �I�v�V������ʂ���߂�
				if (DLLXinput::GetPadButtonData(DLLXinput::GetPlayerPadNumber(), DLLXinput::XINPUT_PAD::BUTTON_START) == 1)
				{
					p_baseMove->OptionActorModelAfter();
					p_baseMove->CameraProcess();			// �J�����؂�ւ�
					SoundProcess::SetOptionMenuNow(false);		// �T�E���h���ʂ��I�v�V�����p����߂�
					optionMenuNow = false;
				}


				ScreenFlip();
			} /// else(!if (!optionMenuNow))
		} /// else
	} /// if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)	
	// �V�[�����ڍs����悤�Ɏw�肳�ꂽ��
	else
	{
		// ���݂̃V�[���̏I���t�F�[�h���I�������
		if (!BASICPARAM::endFeedNow)
		{
			if (BASICPARAM::e_preScene == ESceneNumber::THIRDMOVE)
			{
				Move4TextureReload();
			}


			// �V�[����ς���
			SceneChange();


			// ���O�̃V�[���ƍ��̃V�[���𓯂��ɂ���
			BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
		} /// if (!BASICPARAM::endFeedNow)
		// ���݂̃V�[���̏I���t�F�[�h�̂Ƃ�
		else
		{
			// �I���V�[�������[�h�ł͂Ȃ��Ƃ�
			if (!preLoadScene)
			{				
				// �t�F�[�h�����Z����
				feedCount += 5;


				// ��ʂɊւ����A
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();


				// �Q�[���̕`��Ɋւ���̂������c���ăQ�[���Ɋւ������
				p_baseMove->CameraProcess();
				p_baseMove->Draw();


				// �t�F�[�h�A�E�g����
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


				ScreenFlip();


				// �t�F�[�h�J�E���g�����ɒB������t���b�O������
				if (feedCount >= 255)
				{
					// �G�t�F�N�g���I������
					DrawEffekseer2D_End();
					DrawEffekseer3D_End();


					// �T�E���h���������
					SoundProcess::Release();


					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			} /// if (!preLoadScene)
			// �I���V�[�������[�h�̂Ƃ�
			else
			{
				// �T�E���h���������
				SoundProcess::Release();


				// �t�F�[�h�����Z����
				feedCount += 15;


				// ��ʂɊւ����A
				SetDrawScreen(DX_SCREEN_BACK);
				ClearDrawScreen();


				// �Q�[���̕`��Ɋւ���̂������c���ăQ�[���Ɋւ������
				p_loadThread->Draw();


				// �t�F�[�h�A�E�g����
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, feedCount);
				DrawBox(0, 0, BASICPARAM::winWidth, BASICPARAM::winHeight, feedDraw, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);


				ScreenFlip();


				// �t�F�[�h�J�E���g�����ɒB������t���b�O������
				if (feedCount >= 255)
				{
					feedCount = 0;
					BASICPARAM::endFeedNow = false;
				}
			} /// else(!if (!preLoadScene))
		} /// else(!if (!BASICPARAM::endFeedNow))
	} /// else(!if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene))
} /// void Manager::Update()