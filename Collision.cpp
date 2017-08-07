#include "Collision.h"

// CollisionData class
CollisionData::CollisionData( int id, SDL_Rect Rectangle )
	:
	m_id( id ),
	m_box( Rectangle )
{}

SDL_Rect* CollisionData::getRect()
{
	return &m_box;
}

int CollisionData::getID()
{
	return m_id;
}

// CollisionSystem class
CollisionSystem::CollisionSystem()
	:
	m_MyID( 0, OBJTYPE::CollisionSystem )
{}

CollisionSystem::CollisionSystem( MSGreciever* firstregister, CollisionData firstobj, int idnumber )
	:
	m_MyID( idnumber, OBJTYPE::CollisionSystem )
{
	m_sender.registerMSGER( firstregister );
	addObjToTrack( firstobj );
}

void CollisionSystem::updatePositions()
{
}

void CollisionSystem::addObjToTrack( CollisionData addee )
{
	m_data.push_back( addee );
}

void CollisionSystem::addListener( MSGreciever* listener )
{
	m_sender.registerMSGER( listener );
}

void CollisionSystem::detectCollides( SDL_Rect* box1, SDL_Rect* box2 )
{
	if( SDL_HasIntersection( box1, box2 ) == SDL_TRUE )
	{
		std::cout << "collided" << std::endl;
	}
}

void CollisionSystem::detectAll()
{
	for( unsigned int i = 0; i < m_data.size(); i++ )
	{
		for( unsigned int j = i + 1; j < m_data.size(); j++ )
		{
			detectCollides( m_data[ i ].getRect(), m_data[ j ].getRect() );
		}
	}
}

ID CollisionSystem::getID() 
{ 
	return m_MyID; 
}

