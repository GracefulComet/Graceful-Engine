//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "Game.h"

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  Game Maingame;
  Maingame.Setup();
  Maingame.GameLoop();

  return 0;
}
