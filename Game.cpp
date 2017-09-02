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

Game::Game()
    : m_win(SDL_CreateWindow("Graceful Engine :) ", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, 800, 600,
                             SDL_WINDOW_SHOWN)),
      MainRender(SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED |
                                                   SDL_RENDERER_PRESENTVSYNC)) {
  std::cout << "Game Creation started \n" << std::endl;

  //	TheTextureManager::Instance()->LoadWErrorChecking("Assets/JnRTiles.png","tiles",
  // MainRender );
  //	TheTextureManager::Instance()->LoadWErrorChecking("Assets/ringsheetC.png",
  //"Ring",MainRender);

  fact.addTerrain("Background.sp", MainRender, Vec2DF(0.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(32.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(64.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(96.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(128.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(160.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(192.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(224.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(256.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(288.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(320.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(352.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(384.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(416.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(448.0f, 500.0f));

  fact.addTerrain("Background.sp", MainRender, Vec2DF(480.0f, 500.0f));

  fact.addPlayer("player.sp", &ev, MainRender, Vec2DF(0.0f, 50.0f));

}

Game::~Game() {
  SDL_DestroyRenderer(MainRender);
  SDL_DestroyWindow(m_win);
  SDL_Quit();
}

void Game::Setup() {}

void Game::GameLoop() {
  while (isOpen == true) {
    while (SDL_PollEvent(&ev) != 0) {
      if (ev.type == SDL_QUIT) {
        isOpen = false;
      }
    }

    RL();
  }
}

void Game::composeFrame() {
  m_currentFrame = int((SDL_GetTicks() / 100) % 60);
  //  std::cout << "frame Count :  " << m_currentFrame << std::endl;
  fact.updateCollision();
  fact.updateBehaviour();
  fact.updateGFX(60.0f);
}

void Game::drawFrame() {
  SDL_RenderClear(MainRender);

  fact.drawGFX(MainRender);

  SDL_RenderPresent(MainRender);
}

void Game::RL() {
  composeFrame();
  drawFrame();
}
