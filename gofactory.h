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
#include "Behaviour.h"
#include "PhysicsSystem.h"
#include "Sprite.h"
#include <vector>

class GOfactory {
public:
  GOfactory();

  // void addBehaviour( std::shared_ptr<Behaviour> Addee );
  void addBehaviour(std::unique_ptr<Behaviour> &&Addee);
  void updateBehaviour();
  // void addGFX( Sprite graphic );
  void addGFX(Sprite &&graphic);
  void updateGFX(float deltaT);
  void drawGFX(SDL_Renderer *pRender);
  void updateCollision();
  void
  addPlayer(std::string filetoSprite, SDL_Event *evt, SDL_Renderer *render,
            Vec2DF pos); // eventually add read and saving to a PhysicsFile.
  void addTerrain(std::string filetoSprite, SDL_Renderer *render, Vec2DF pos);

private:
  std::vector<Sprite> Gfx;
  PhysicsSystem PS;
  // std::vector<std::shared_ptr<Behaviour> > m_Entities;
  std::vector<std::unique_ptr<Behaviour>> m_Entities;
  int m_IDKeys = 0;
};
