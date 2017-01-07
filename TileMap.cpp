#include "TileMap.h"

TileMap::TileMap(int ncol,int nrow,int Height,int width){
	
	int id =0;
	Frame temp;


	m_Height = Height;
	m_Width = width;
	m_Maping[ id ] = temp; 
	for(int y = 0; y <= nrow; y++){
		for(int x = 0; x <= ncol; x++){
	temp.x =x;
	temp.y =y;

	m_Maping [id ] = temp;
	
	
	id++;

		}	
	}

}
TileMap::TileMap(){}
TileMap::~TileMap(){}

void TileMap::setCurTile(int cFrame ){
m_curTile = cFrame;
}

int TileMap::getH(){
return m_Height;
}
int TileMap::getW(){
return m_Width;
}
int TileMap::getCurrCol(){
Frame temp;
temp = m_Maping[m_curTile];
return temp.x;
}
int TileMap::getCurrRow(){
Frame temp;
temp = m_Maping[m_curTile];
return temp.y;
}
