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
	TheInputHandler::Instance()->update(ev);

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
	test.animatecycle( 100.0f , 5 );
	fact.updateAllGO(ev, deltatime );
}

void Game::drawFrame() {
	SDL_RenderClear(MainRender);
	fact.drawAllGO(MainRender);
	test.draw(MainRender);
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
	    m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	backBuffer =
	    SDL_CreateTexture(MainRender, SDL_PIXELFORMAT_ABGR8888,
			      SDL_TEXTUREACCESS_TARGET, m_WHeight, m_WWidth);

	m_lastframe = 0;


	TheInputHandler::Instance()->InitialiseJoysticks();


	m_GameState = GameState::PLAY;

	if (TheTextureManager::Instance()->load("Assets/char1.png", "players0",
						MainRender) == true) {
		std::cout << "loaded char1.png" << std::endl;
	} else {
		std::cout << "Failed to load char1.png" << std::endl;
	}
	if (TheTextureManager::Instance()->load("Assets/SpinningCoin.png",
						"Coin", MainRender) == true) {
		std::cout << "loaded SpinningCoin.png" << std::endl;
	} else {
		std::cout << "Failed to load SpinningCoin.png" << std::endl;
	}
		if (TheTextureManager::Instance()->load("Assets/ringsheetC.png", "Ring",
						MainRender) == true){
			std::cout << "loaded ringsheet.png" << std::endl;}
		else {	std::cout << "loaded SpinningCoin.png" << std::endl;}

	fact.addGO("players0",  50, 50,5,5 );

	test.load (200,200 ,248 ,248, 1 , 1 ,"Ring");






}

void Game::RL() {
	Ptime = Ctime;
	Ctime = SDL_GetTicks();
	deltatime = Ctime - Ptime;
	if (deltatime > 0.15) {
		deltatime = 0.15;
	}
	composeFrame();
	drawFrame();
}

Game::~Game() {
	TheInputHandler::Instance()->clean();
	SDL_DestroyRenderer(MainRender);
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}
