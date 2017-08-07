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

Game::Game()
	:
	m_win( SDL_CreateWindow( "Graceful Engine :) ", SDL_WINDOWPOS_CENTERED,
							 SDL_WINDOWPOS_CENTERED, 800, 600,
							 SDL_WINDOW_SHOWN ) ),
	MainRender( SDL_CreateRenderer(
		m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ) )
{
	std::cout << "Game Creation started \n" << std::endl;

	//	TheTextureManager::Instance()->LoadWErrorChecking("Assets/JnRTiles.png","tiles", MainRender );
	//	TheTextureManager::Instance()->LoadWErrorChecking("Assets/ringsheetC.png", "Ring",MainRender);

	fact.addPlayer("Background.sp", &ev, MainRender, Vec2DF(100.0f, 100.0f));
	fact.addPlayer( "player.sp", &ev, MainRender, Vec2DF( 50.0f, 50.0f ) );
}

Game::~Game()
{
	SDL_DestroyRenderer( MainRender );
	SDL_DestroyWindow( m_win );
	SDL_Quit();
}

void Game::Setup() {}

void Game::GameLoop()
{
	while( isOpen == true )
	{
		while( SDL_PollEvent( &ev ) != 0 )
		{
			if( ev.type == SDL_QUIT )
			{
				isOpen = false;
			}
		}

		RL();
	}
}

void Game::composeFrame()
{
	m_currentFrame = int( ( SDL_GetTicks() / 100 ) % 60 );

	fact.updateBehaviour();
	fact.updateGFX( 60.0f );
	fact.updateCollision();
}

void Game::drawFrame()
{
	SDL_RenderClear( MainRender );

	fact.drawGFX( MainRender );

	SDL_RenderPresent( MainRender );
}

void Game::RL()
{
	composeFrame();
	drawFrame();
}

