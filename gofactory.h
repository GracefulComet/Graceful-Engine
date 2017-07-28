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
#include <vector>
#include "Messages.h"
#include "Behaviour.h"
#include "Collision.h"

class GOfactory {
public:
  GOfactory();
  ~GOfactory();
  void addBehaviour( Behaviour* Addee );
  void updateBehaviour();
  void addGFX( Sprite graphic  );
  void updateGFX( float deltaT );
  void drawGFX(SDL_Renderer * pRender);
  void updateCollision();
  void addPlayer(std::string filetoSprite,SDL_Event* evt, SDL_Renderer* render, Vec2DF pos);
private:
 std::vector<Sprite> Gfx;
 CollisionSystem m_Collider;
  std::vector<Behaviour*> m_Entities;
  int m_IDKeys;
};
