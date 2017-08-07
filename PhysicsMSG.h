#pragma once

#include "Messages.h"
#include "vmath.h"

class PhysicsMSG : public msg
{
public:

	PhysicsMSG() = default;
	PhysicsMSG( Vec2DF velocity, float dt, ID target, ID Sender );
	
	void update( void* Variables )override;

public:
	Vec2DF m_VecPayload;
	float m_DeltaTime;
};
