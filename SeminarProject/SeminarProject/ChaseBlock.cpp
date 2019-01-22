#include "ChaseBlock.hpp"



/// --------------------------------------------------------------------------------------------------
ChaseBlock::ChaseBlock()
{
	// ‰Šú‰»
	area = VGet(4500.0f - (48.415f * 25.0f), 200.0f + (198.550f * 25.0f), -65.554f * 25.0f);
	chaseArea = VGet(0, 0, 0);
	speed = VGet(0, 0, 0);
	disappearFrame = 0;
	activeNow = false;
}



/// --------------------------------------------------------------------------------------------------
ChaseBlock::~ChaseBlock()
{
}



/// --------------------------------------------------------------------------------------------------
void ChaseBlock::Process()
{
	if (activeNow)
	{
		area = VAdd(area, speed);

		
		if (disappearFrame++ > 200)
		{
			activeNow = false;
		}
	}
} /// void ChaseBlock::Process()

void ChaseBlock::Draw()
{
	if (activeNow)
	{
		SetUseZBuffer3D(TRUE);
		SetWriteZBuffer3D(TRUE);
		DrawSphere3D(VAdd(area, VGet(0.0f, 300.0f, 0.0f)), 300, 16, GetColor(50, 50, 50), GetColor(0, 0, 0), TRUE);
		SetWriteZBuffer3D(FALSE);
		SetUseZBuffer3D(FALSE);
	}
}



/// --------------------------------------------------------------------------------------------------
void ChaseBlock::Active(VECTOR chaseArea)
{
	area = VGet(4500.0f - (48.415f * 25.0f), 200.0f + (198.550f * 25.0f), -65.554f * 25.0f);
	activeNow = true;
	this->chaseArea = chaseArea;
	disappearFrame = 0;
	speed.x = std::fabsf((area.x - chaseArea.x) / 150);
	speed.y = std::fabsf((area.y - chaseArea.y) / 150);
	speed.z = std::fabsf((area.z - chaseArea.z) / 150);
	// ƒvƒŒƒCƒ„[‚É‹ß‚Ã‚­
	if (chaseArea.x < area.x - (speed.x * 2))
	{
		speed.x = -speed.x;
	}
	if (chaseArea.y < area.y - (speed.y * 2))
	{
		speed.y = -speed.y;
	}
	if (chaseArea.z < area.z - (speed.z * 2))
	{
		speed.z = -speed.z;
	}
} /// void ChaseBlock::Active(VECTOR chaseArea)
