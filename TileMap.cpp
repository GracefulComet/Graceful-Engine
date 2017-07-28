#include "TileMap.h"

TileMap::TileMap(int ncol, int nrow, int Height, int width) {

  int id = 0;
  Frame temp;

  m_Height = Height;
  m_Width = width;
  m_NumRow = nrow;
  m_NumCol = ncol;
  m_Maping[id] = temp;
  for (int y = 0; y <= nrow; y++) {
    for (int x = 0; x <= ncol; x++) {
      temp.x = x;
      temp.y = y;

      m_Maping[id] = temp;

      id++;
    }
  }
  m_CurCol = 0;
  m_CurRow = 0 ;
}
TileMap::TileMap() {}
TileMap::~TileMap() {}

void TileMap::setCurTile(int cFrame) { m_curTile = cFrame; }

int TileMap::getCurrTile() { return m_curTile; }

int TileMap::getH() { return m_Height; }
int TileMap::getW() { return m_Width; }
int TileMap::getCurrCol() {

  return m_Maping[m_curTile].x;
}
int TileMap::getCurrRow() {

  return m_Maping[m_curTile].y;
}
int TileMap::getNCol() {

  return m_NumCol;
}
int TileMap::getNRow() {

  return m_NumRow;
}
void TileMap::setNumAnimFrames(int numofFrames){
    m_numframestoAnimate = numofFrames;
}
int TileMap::getNumAnimFrames(){

    return m_numframestoAnimate;
}
void TileMap::setState(state DesiredState){
    State = DesiredState;
}
state TileMap::getState(){
    return State;
}
