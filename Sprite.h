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
#include "PhysData.h"
#include "MSGreciever.h"
#include "TileMap.h"
#include "Timer.h"
#include "vmath.h"
#include <string>

class Sprite // small graphics object
    {
public:
  Sprite() = default;
  Sprite(int width, int height, int nCol, int nRow, std::string textureID);
  Sprite(std::string FileName, SDL_Renderer *Render);
  Sprite(std::string FileName, SDL_Renderer *Render, state stat, int id);

  void LoadFromFile(std::string FileName, SDL_Renderer *Render);
  void SaveToFile(std::string FileName, std::string TextureFilename,
                  std::string textureID);
  void draw(SDL_Renderer *pRenderer);
  void update(float DeltaTime);
  void animate(float DurPerFrame, int NumOfFrames, bool Cycle);
  void setCurTile(int CurT);
  void Nanimate(float DurPerFrame, int NumOfFrames, bool Cycle);
  void SetPos(float x, float y);
  //  Vec2DF *getPosition();
  TileMap *getTiles();
  //  Vec2DF *getVec();
  void HandleMSG();
  MSGreciever *getListener();
  ID getID();
  ID *getIDptr();
  Physdata *getRot_Pos();

protected:
  TileMap m_tiles;
  bool reverse;
  std::unique_ptr<MSGreciever> m_messenger;
  std::string m_textureID;
  int m_animOffset;
  TimerF m_timer;
  ID m_ID;
  Physdata m_locationData;
};
