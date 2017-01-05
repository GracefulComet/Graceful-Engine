//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//
#include "Sprite.h"
#include <string>


Sprite::Sprite(int width, int height, int nCol, int nRow, std::string textureID ) {
 m_tiles = TileMap(nCol,nRow ,height,width);
 m_textureID  = textureID;

}
Sprite::Sprite(){}
Sprite::~Sprite() {}

void Sprite::load(float PosX, float PosY, int width, int height, int Row, int Collumn, std::string textureID) {
	m_position = Vector(PosX, PosY, 0 );
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = Row;
	m_animOffset =0;
	m_currentCol = Collumn;
	reverse = false;
}

void Sprite::update(SDL_Event Ev,float DeltaTime){}

void Sprite::draw(SDL_Renderer* pRenderer) {
	TheTextureManager::Instance()->drawFrame(
	    m_textureID, m_position.x, m_position.y, this->m_tiles.getW() ,this->m_tiles.getH(),
	    m_currentRow, (m_currentCol + m_animOffset), pRenderer, SDL_FLIP_NONE);

}

void Sprite::animate(float DurPerFrame, int NumOfFrames , bool Cycle ){
	

	if(m_timer.cooldown(DurPerFrame) == true ){
	m_timer.reset();		
		if (Cycle == true){
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
		}else if(Cycle == false){
			m_animOffset++;
			if(m_animOffset >= NumOfFrames){
			m_animOffset = 0;
			}
		}
	}
}


void Sprite::Nanimate(float DurPerFrame, int NumOfFrames, bool Cycle ){

	if(m_timer.cooldown(DurPerFrame) == true ){
	m_timer.reset();		
		if (Cycle == true){
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
		}else if(Cycle == false){
			m_animOffset++;
			if(m_animOffset >= NumOfFrames){
			m_animOffset = 0;
			}
		}
	}

}
