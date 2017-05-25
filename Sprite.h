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
#include "TexL.h"
#include "TileMap.h"
#include "Timer.h"
#include "vmath.h"
#include <SDL2/SDL.h>
#include <string>
#include "Messages.h"

	enum class state {idle,animated, cycle };
class Sprite // small graphics object
{
public:
  Sprite(int width, int height, int nCol, int nRow, std::string textureID);
  Sprite( std::string FileName, SDL_Renderer *Render);

  Sprite( std::string FileName, SDL_Renderer *Render, state stat, int id );


  Sprite();
  ~Sprite();

  void LoadFromFile(std::string FileName, SDL_Renderer *Render);
  void SaveToFile(std::string FileName, std::string TextureFilename,
                  std::string textureID);
  void draw(SDL_Renderer *pRenderer);
  void update(float DeltaTime , int NumOfFrames);
  void animate(float DurPerFrame, int NumOfFrames, bool Cycle);
  void setCurTile(int CurT);
  void Nanimate(float DurPerFrame, int NumOfFrames, bool Cycle);
  void SetPos(float x, float y);
  TileMap m_tiles;
  Vector* getVec();
  void HandleMSG( ); 
  MSGreciever* getListener();
  int getID();


protected:
  bool reverse;
  Vector m_position;
  Vector m_movespeed;
  MSGreciever m_messenger;
  std::string m_textureID;
  int m_animOffset;
  TimerF m_timer;
  state State;
  int m_ID;
private:
};
