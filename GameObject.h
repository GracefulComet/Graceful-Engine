#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "TexL.h"
#include"vmath.h"
#include "TileMap.h"



class GameObject
{
public:

	GameObject();
	~GameObject();
    void load(float PosX, float PosY, int width, int height,  int Row, int Collumn,
	std::string textureID);
	void draw(SDL_Renderer* pRenderer);
    void update(SDL_Event Ev,float DeltaTime,SDL_Renderer* pRenderer);
	void animate(float DurPerFrame, int NumOfFrames ,SDL_Renderer* pRenderer); 	
	

protected:

	int m_currentCol;
	int m_currentRow;
	Vector m_position;
	std::string m_textureID; 
	int m_animOffset;
	int m_width;
	int m_height;
	int m_currentFrame;
	float m_currTime;
	float m_prevTime;
	float m_deltaTime;
	TileMap m_tiles;

private:

};


