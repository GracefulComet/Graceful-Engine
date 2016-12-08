#include "gofactory.h"

// TODO: Add other Object Types. types to do , Terrain, UI and Forground




GOfactory::GOfactory()
{
	P_Num_Keys = 0;
}



void GOfactory::loadlist(std::string id)
{

}

void GOfactory::updateGO(int key , SDL_Event Event, float deltaT,SDL_Renderer* pRenderer)
{
	// Goes through a specific player  and updates their internal state by speficifying the specific player key
	GOList[key].update(Event,deltaT , pRenderer);
}

void GOfactory::updateAllGO(SDL_Event Event, float deltaT, SDL_Renderer* pRenderer)
{
	// loops through each GameObject and and updates its internal state till all GameObjects are updated
		for (int i = 1; i <= P_Num_Keys; i++)
		{
			updateGO(i, Event, deltaT,pRenderer);
		}
}

void GOfactory::drawGO(int key, SDL_Renderer* pRenderer)
{
	// Draws the a single Player by its key
	GOList[key].draw(pRenderer);
}

void GOfactory::drawAllGO(SDL_Renderer * pRender)
{
	// loops through each player and draws it at its position untill each player is drawn
	for (int i = 1; i <= P_Num_Keys; i++)
	{
		drawGO(i, pRender);
	}
}

void GOfactory::addGO(std::string Textureid, float initX, float initY , int Row, int Column )
{
	P_Num_Keys++;
	int key = P_Num_Keys;

	GameObject temp;
	temp.load(initX, initY, 32, 32 , Row ,Column, Textureid );
	GOList[key] = temp;
	
}
