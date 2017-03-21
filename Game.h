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
#include <SDL2/SDL.h>
#include <iostream>

#include "Inputh.h"
#include "gofactory.h"

enum class GameState { MENU, PLAY, PAUSE, EXIT };

class Game {
public:
  void Setup();
  void GameLoop();
  void composeFrame();
  void drawFrame();

  void RL();

  void update();

  Game();
  ~Game();

private:
  SDL_Window *m_win;
  SDL_Renderer *MainRender;
  bool isOpen;
  int m_WHeight;
  int m_WWidth;
  SDL_Event ev;
  SDL_Texture *backBuffer;
  float Ctime;
  float Ptime;
  float deltatime;
  int m_currentFrame;
  GOfactory fact;
  GameState m_GameState;
  int m_lastframe;
  Sprite Test;
};
