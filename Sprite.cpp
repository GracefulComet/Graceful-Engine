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
#include<iostream>
#include<fstream>
#include<stdlib.h>
Sprite::Sprite(int width, int height, int nCol, int nRow, std::string textureID ) {
 m_tiles = TileMap(nCol,nRow ,height,width);
 m_textureID  = textureID;
 m_tiles.setCurTile( 0 );
 m_animOffset = 0;
}
Sprite::Sprite(){}
Sprite::~Sprite() {}



void Sprite::LoadFromFile(std::string FileName ,SDL_Renderer* Render ){
	std::string line;
	std::string tempTexName;
	std::string tempTexID;
	int tempW;
	int tempH;
	int tempNcol;
	int tempNrow;
	

	std::ifstream ifs(FileName);
	if (ifs.is_open() ){
		int counter = 0;
		while(std::getline(ifs,line)){
			counter++;
		
			if(counter >=7 ){
			counter =1;	
			}
			if(counter ==1){
			tempTexName = line;	
			}
			if(counter ==2){
			tempTexID = line;		
			}	
			if(counter ==3){

			tempW = atoi(line.c_str());	

			}
			if(counter ==4){
	
			tempH = atoi(line.c_str());	
			}
			if(counter ==5){
		
			tempNcol = atoi(line.c_str());	
			}		
			if(counter ==6){
			
			tempNrow = atoi(line.c_str());	
			}
	
// wrap texture loading in an if statement that checks if the file is already open
		}
//	TheTextureManager::Instance()->LoadWErrorChecking(tempTexName,tempTexID ,Render );

		m_textureID = tempTexID;
	     	m_tiles = TileMap(tempNcol,tempNrow ,tempH,tempW);

			 m_tiles.setCurTile( 0 );
			 m_animOffset = 0;
			 ifs.close();			  }

		
	else{std::cout << "file " << FileName << " not found "<< std::endl;  }

}

void Sprite::SaveToFile( std::string FileName ,std::string TextureFilename,std::string textureID ){
	
	
		
	std::ofstream ofs( FileName ,std::ios::trunc);
	ofs<< TextureFilename  << std::endl << textureID << std::endl << m_tiles.getW() << std::endl
	<<m_tiles.getH()<<std::endl << m_tiles.getNCol()<< std::endl << m_tiles.getNRow() <<std::endl;
	ofs.close();

}


void Sprite::update(SDL_Event Ev,float DeltaTime){}

void Sprite::draw(SDL_Renderer* pRenderer) {
	TheTextureManager::Instance()->drawFrame(
	    m_textureID, m_position.x, m_position.y, this->m_tiles.getW() ,this->m_tiles.getH(),
	    this->m_tiles.getCurrRow() , (this->m_tiles.getCurrCol() + m_animOffset), pRenderer, SDL_FLIP_NONE);

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


void Sprite::SetPos( float x , float y ){
m_position.x = x;
m_position.y = y;
m_position.z =0;
}
