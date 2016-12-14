//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//
#include "GameObject.h"
#include <string>


GameObject::GameObject() {}
GameObject::~GameObject() {}

void GameObject::load(float PosX, float PosY, int width, int height, int Row, int Collumn, std::string textureID) {
	m_position = Vector(PosX, PosY, 0 );
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = Row;
	m_animOffset =0;
	m_currentCol = Collumn;
}

void GameObject::update(SDL_Event Ev,float DeltaTime,SDL_Renderer* pRenderer){}

void GameObject::draw(SDL_Renderer* pRenderer) {
	TheTextureManager::Instance()->drawFrame(
	    m_textureID, m_position.x, m_position.y, m_width, m_height,
	    m_currentRow, (m_currentCol + m_animOffset), pRenderer, SDL_FLIP_NONE);

}

void GameObject::animate(float DurPerFrame, int NumOfFrames, SDL_Renderer* pRenderer ){
	
	if(m_timer.cooldown(DurPerFrame) == true ){
	m_timer.reset();	
	m_animOffset++;

		if( m_animOffset >= NumOfFrames) 
		{
			m_animOffset = 0;
		}
	
	}
}
void GameObject::animatecycle(float DurPerFrame, int NumOfFrames, SDL_Renderer* pRenderer ){

	
	if(m_timer.cooldown(DurPerFrame) == true ){
	m_timer.reset();	


		if(reverse == false)
		{
			m_animOffset++;
		}

		if( m_animOffset >= NumOfFrames) 
		{
			reverse = true;	
			
		}
		if(reverse == true )
		{
		m_animOffset--;	
		}	
		if( m_animOffset <= 0)
		{
		reverse = false;
		}
	}
	
}
