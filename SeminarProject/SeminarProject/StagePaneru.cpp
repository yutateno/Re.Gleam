#include "StagePaneru.hpp"



/// --------------------------------------------------------------------------------
StagePaneru::StagePaneru(const int draw, const VECTOR area) : BasicObject()
{
	// ���W��ݒ�
	this->area = area;

	
	// ���f���ǂݍ���
	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);

	
	// �T�C�Y�ύX
	MV1SetScale(this->modelHandle, VGet(50.0f, 50.0f, 50.0f));
	// ���W���X�V
	MV1SetPosition(this->modelHandle, area);
}



/// --------------------------------------------------------------------------------
StagePaneru::~StagePaneru()
{
	// ���f���J��
	MODEL_RELEASE(modelHandle);
}
