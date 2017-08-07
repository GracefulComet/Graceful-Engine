//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#pragma once
#include "Sprite.h"
#include "Behaviour.h"
#include "Collision.h"
#include <vector>

class GOfactory
{
public:
	GOfactory();

	//void addBehaviour( std::shared_ptr<Behaviour> Addee );
	void addBehaviour( std::unique_ptr<Behaviour> &&Addee );
	void updateBehaviour();
	//void addGFX( Sprite graphic );
	void addGFX( Sprite &&graphic );
	void updateGFX( float deltaT );
	void drawGFX( SDL_Renderer * pRender );
	void updateCollision();
	void addPlayer( std::string filetoSprite, SDL_Event* evt, SDL_Renderer* render, Vec2DF pos );

private:
	std::vector<Sprite> Gfx;
	CollisionSystem m_Collider;
	//std::vector<std::shared_ptr<Behaviour> > m_Entities;
	std::vector<std::unique_ptr<Behaviour>> m_Entities;
	int m_IDKeys = 0;
};
