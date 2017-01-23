#include "Sprite.h"

enum class TerrainState{wall, floor, DoorClosed, DoorOpen };

class Terrain{
	public:
	Terrain();
	~Terrain();


	private:
	TerrainState m_state;
	Sprite m_tiles;
}
