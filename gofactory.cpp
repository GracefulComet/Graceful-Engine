//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "gofactory.h"
#include "PlayerCtrl.h"

// TODO: Add other Object Types. types to do , Terrain, UI and Forground

GOfactory::GOfactory(){}

//void GOfactory::addGFX( Sprite graphic )
//{ 
//	Gfx.push_back( graphic ); 
//}

void GOfactory::addGFX( Sprite && graphic )
{
	Gfx.push_back( std::move( graphic ) );
}

void GOfactory::updateGFX( float deltaT )
{
	for( auto &sprite : Gfx )
	{
		sprite.update( deltaT );
	}
}

void GOfactory::drawGFX( SDL_Renderer * pRender )
{
	for( auto &sprite : Gfx )
	{
		sprite.draw( pRender );
	}
}

void GOfactory::updateCollision()
{
	m_Collider.detectAll();
}

//void GOfactory::addBehaviour( std::shared_ptr<Behaviour> Addee )
//{
//	m_Entities.push_back( Addee );
//}

void GOfactory::addBehaviour( std::unique_ptr<Behaviour>&& Addee )
{
	m_Entities.push_back( std::move( Addee ) );
}

void GOfactory::updateBehaviour()
{
	for( auto& pEntity : m_Entities )
	{
		pEntity->update();
	}
}

//todo add set position into the variables you want to set
void GOfactory::addPlayer( std::string filetoSprite, SDL_Event* evt, SDL_Renderer* render, Vec2DF pos )
{
	m_IDKeys++;
	addGFX( Sprite( filetoSprite, render, state::animated, m_IDKeys ) );
	Gfx.back().SetPos( pos.x, pos.y );
	

	for( unsigned int i = 0; i < Gfx.size(); i++ )
	{
		if( Gfx[ i ].getID() == m_IDKeys )
		{
			//addBehaviour( std::make_shared<PlayerCtrl>( Gfx[ i ].getListener(), evt, m_IDKeys ) );
			addBehaviour( std::make_unique<PlayerCtrl>( Gfx[ i ].getListener(), evt, m_IDKeys ) );

			SDL_Rect tempbox;
			tempbox.x = Gfx[ i ].getPosition()->x;
			tempbox.y = Gfx[ i ].getPosition()->y;
			tempbox.h = Gfx[ i ].getTiles()->getH();
			tempbox.w = Gfx[ i ].getTiles()->getW();

			m_Collider.addObjToTrack( CollisionData( Gfx[ i ].getID(), tempbox ) );
			m_Collider.addListener( Gfx[ i ].getListener() );
		
			for( unsigned int j = 0; j < m_Entities.size(); j++ )
			{
				if( m_Entities[ j ]->m_Mine.m_IDNumber == m_IDKeys )
				{
					m_Collider.addListener( m_Entities[ i ]->getlistener() );
				}
			}
		}
	}
}




