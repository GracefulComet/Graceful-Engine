#include "TileMap.h"

TileMap::TileMap(int ncol,int nrow,int Height,int width){
	
	int id =0;
	Frame temp;
	for(int y = 1; y <= ncol; y++){
		for(int x = 1; x <= nrow; x++){
	id++;
	temp.x =x;
	temp.y =y;

	m_Maping [id ] = temp;
	
	
		}	
	}

}
TileMap::TileMap(){}
TileMap::~TileMap(){}

void TileMap::setCurTile(int cFrame ){}

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
