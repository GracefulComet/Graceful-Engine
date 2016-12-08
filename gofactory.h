#pragma once
#include "GameObject.h"

class GOfactory {
       public:
	GOfactory();

	void loadlist(std::string id);

	void updateGO(int key, SDL_Event Event, float deltaT,SDL_Renderer* pRenderer);
	void updateAllGO(SDL_Event Event, float deltaT,SDL_Renderer* pRenderer );

	void drawGO(int key, SDL_Renderer* pRenderer);
	void drawAllGO(SDL_Renderer* pRender);
	void addGO(std::string Textureid, float initX, float initY, int Row, int Collumn);

	void addCollectable(std::string Textureid, float initX, float initY);

       private:
	std::map<int, GameObject> GOList;



	int P_Num_Keys;
};
