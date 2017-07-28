//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//

#include "Game.h"

void Game::Setup() {}

void Game::GameLoop() {
	while (isOpen == true) {


		if (SDL_PollEvent(&ev) == 0) {
			RL();
		}
		while (SDL_PollEvent(&ev) != 0) {

			RL();
			if (ev.type == SDL_QUIT) {
				isOpen = false;
			}
		}
	}
}

void Game::composeFrame() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 60);
    SDL_PollEvent(&ev);
	fact.updateBehaviour();	
	fact.updateGFX(60.0f  );
//	fact.updateCollision();

}

void Game::drawFrame() {
	SDL_RenderClear(MainRender);

	fact.drawGFX(MainRender);

	SDL_RenderPresent(MainRender);
}

Game::Game() {
	Ctime = 0.0f;
	Ptime = 0.0f;
	deltatime = 0.0f;
	isOpen = true;
	std::cout << "Game Creation started \n" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	m_win = SDL_CreateWindow("Graceful Engine :) ", SDL_WINDOWPOS_CENTERED,
				 SDL_WINDOWPOS_CENTERED, 800, 600,
				 SDL_WINDOW_SHOWN);
	MainRender = SDL_CreateRenderer(
	    m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );


	m_lastframe = 0;


	TheInputHandler::Instance()->InitialiseJoysticks();


	m_GameState = GameState::PLAY;
//	TheTextureManager::Instance()->LoadWErrorChecking("Assets/JnRTiles.png","tiles", MainRender );
//	TheTextureManager::Instance()->LoadWErrorChecking("Assets/ringsheetC.png", "Ring",MainRender);




    fact.addPlayer("Background.sp", &ev, MainRender, Vec2DF(100.0f, 100.0f));
    fact.addPlayer("player.sp",&ev, MainRender,Vec2DF(50.0f,50.0f));



}

void Game::RL() {
	composeFrame();
	drawFrame();
}

Game::~Game() {

	TheInputHandler::Instance()->clean();
	SDL_DestroyRenderer(MainRender);
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}
