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

#include "gofactory.h"

enum class GameState { MENU, PLAY, PAUSE, EXIT };

class Game
{
public:
	Game();
	~Game();

	void Setup();
	void GameLoop();
	void composeFrame();
	void drawFrame();

	void RL();

	void update();

private:
	SDL_Window *m_win;
	SDL_Renderer *MainRender;
	bool isOpen = true;
	int m_WHeight;
	int m_WWidth;
	SDL_Event ev;
	SDL_Texture *backBuffer;
	float Ctime = 0.f;
	float Ptime = 0.f;
	float deltatime = 0.f;
	int m_currentFrame;
	GOfactory fact;
	GameState m_GameState = GameState::PLAY;
	int m_lastframe = 0;
};
