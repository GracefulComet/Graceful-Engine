#include "TileMap.h"

TileMap::TileMap(int ncol, int nrow, int Height, int width) {

  int id = 0;
  Frame temp;

  m_Height = Height;
  m_Width = width;
  m_NumRow = nrow;
  m_NumCol = ncol;

  for (int y = 0; y <= nrow; y++) {
    for (int x = 0; x <= ncol; x++) {
      temp.x = x;
      temp.y = y;

      m_Maping[id] = temp;

      id++;
    }
  }
  m_CurCol = 0;
  m_CurRow = 0;
}

void TileMap::setCurTile(int cFrame) { m_curTile = cFrame; }

int TileMap::getCurrTile() { return m_curTile; }

int TileMap::getH() { return m_Height; }

int TileMap::getW() { return m_Width; }

int TileMap::getCurrCol() {
  Frame temp;
  temp = m_Maping[m_curTile];
  return temp.x;
}

int TileMap::getCurrRow() {
  Frame temp;
  temp = m_Maping[m_curTile];
  return temp.y;
}

int TileMap::getNCol() {
  int temp = 0;
  temp = m_NumCol;
  return temp;
}

int TileMap::getNRow() {
  int temp = 0;
  temp = m_NumRow;
  return temp;
}

void TileMap::setNumAnimFrames(int numofFrames) {
  m_numframestoAnimate = numofFrames;
}

int TileMap::getNumAnimFrames() { return m_numframestoAnimate; }

void TileMap::setState(state DesiredState) { State = DesiredState; }

void TileMap::setFlip(bool isFlipped){
m_IsFlipped = isFlipped;
}
bool TileMap::getFlip(){return m_IsFlipped;}
state TileMap::getState() { return State; }
