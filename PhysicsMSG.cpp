#include "PhysicsMSG.h"
#include <iostream>


PhysicsMSG::PhysicsMSG( Vec2DF velocity, float dt, ID target, ID Sender )
	:
	msg( target, Sender, MSGTYPE::Physics ),
	m_VecPayload( velocity ),
	m_DeltaTime( dt )
{}

void PhysicsMSG::update( void* Variables )
{
	if( ( Variables ) == nullptr )
	{
		std::cout << " Got Null" << std::endl;
	}
	else
	{
		auto &position = *reinterpret_cast< Vec2DF* >( Variables );
		position.x = m_VecPayload.Approach( m_VecPayload.x, ( ( Vec2DF* )Variables )->x, ( m_DeltaTime  * 0.15f ) );
		position.y = m_VecPayload.Approach( m_VecPayload.y, ( ( Vec2DF* )Variables )->y, ( m_DeltaTime * 0.15f ) );
		position += ( m_VecPayload *= 0.15f );
	}
}

