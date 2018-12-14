#include "StagePaneru.hpp"


StagePaneru::StagePaneru(const int draw, const VECTOR area) : BasicObject()
{
	this->area = area;


	this->modelHandle = 0;
	this->modelHandle = MV1DuplicateModel(draw);


	MV1SetScale(this->modelHandle, VGet(50.0f, 50.0f, 50.0f));


	MV1SetPosition(this->modelHandle, area);
}

StagePaneru::~StagePaneru()
{
	MODEL_RELEASE(modelHandle);
}

void StagePaneru::Draw()
{
	BasicObject::Draw();
}
