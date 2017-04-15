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

 // void loadlist(std::string id);

 // void updateGO(int key, SDL_Event Event, float deltaT);
 // void updateAllGO(SDL_Event Event, float deltaT);

 // void drawGO(int key, SDL_Renderer *pRenderer);
 // void drawAllGO(SDL_Renderer *pRender);
 // void addGO(std::string Textureid, int NumCol, int NumRow, int Width,
 //            int Height, float PosX, float PosY);

  void addBehaviour(); 
  void addGFX( Sprite graphic  );
  void updateGFX( float deltaT );
  void drawGFX(SDL_Renderer * pRender);
 
 // void addCollectable(std::string Textureid, float initX, float initY);
 // void Anim(float duration, int key, int NumFrames, SDL_Renderer *pRender);
 // void AddGrid(int NumCol, int NumRows, std::string textureID, int width,
 //              int height, int GridX, int GridY);

private:
//  std::map<int, Sprite> GOList;
  std::vector<Sprite> Gfx;
  
//  int P_Num_Keys;
};
