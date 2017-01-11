//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//
#pragma once
#include "Sprite.h"
#include <vector>
class GOfactory {
       public:
	GOfactory();

	void loadlist(std::string id);

	void updateGO(int key, SDL_Event Event, float deltaT);
	void updateAllGO(SDL_Event Event, float deltaT);

	void drawGO(int key, SDL_Renderer* pRenderer);
	void drawAllGO(SDL_Renderer* pRender);
	void addGO(std::string Textureid, int NumCol, int NumRow , int Width, int Height ,float PosX,float PosY );

	void addCollectable(std::string Textureid, float initX, float initY);
	
	

       private:
	std::map<int, Sprite> GOList;


	int P_Num_Keys;
};
