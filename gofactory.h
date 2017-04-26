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

class GOfactory {
public:
  GOfactory();

  void addBehaviour( Behaviour* Addee );
  void updateBehaviour();
  void addGFX( Sprite graphic  );
  void updateGFX( float deltaT );
  void drawGFX(SDL_Renderer * pRender);
  void addPlayer(std::string filetoSprite, SDL_Renderer* render); 
private:
 std::vector<Sprite> Gfx;
  std::vector<Behaviour*> m_Entities; 
  int m_IDKeys;
};
