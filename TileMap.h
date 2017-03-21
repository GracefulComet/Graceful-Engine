#include <map>

struct Frame {
  int x; // collum
  int y; // row
};

class TileMap {
public:
  TileMap(int ncol, int nrow, int Height, int width);
  TileMap();
  ~TileMap();

  void setCurTile(int cFrame);
  int getH();
  int getW();
  int getCurrCol();
  int getCurrRow();
  int getNCol();
  int getNRow();
  int getCurrTile();

protected:
  int m_NumCol; // number of collums
  int m_NumRow; // number Of Rows
  int m_CurCol; // Current Collum
  int m_CurRow; // current Row
  int m_Height; // hight of an individual tile
  int m_Width;  // width of an individual tile
  int m_curTile;
  std::map<int, Frame> m_Maping;
};
