//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//
#include "gofactory.h"

// TODO: Add other Object Types. types to do , Terrain, UI and Forground




GOfactory::GOfactory()
{
	P_Num_Keys = 0;
}



void GOfactory::loadlist(std::string id)
{

}

void GOfactory::updateGO(int key , SDL_Event Event, float deltaT)
{
// Goes through a specific player  and updates their internal state by speficifying the specific player key
	GOList[key].update(Event,deltaT );
}

void GOfactory::updateAllGO(SDL_Event Event, float deltaT)
{
// loops through each GameObject and and updates its internal state till all GameObjects are updated
		for (int i = 1; i <= P_Num_Keys; i++)
		{
			updateGO(i, Event, deltaT);
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

void GOfactory::addGO(std::string Textureid, int NumCol, int NumRow , int Width, int Height,float PosX,float PosY )
{
	P_Num_Keys++;
	int key = P_Num_Keys;

	Sprite temp;
	temp = Sprite(Width,Height,NumCol,NumRow, Textureid);
	temp.SetPos(PosX,PosY);
	GOList[key] =  temp;
	
}
void GOfactory::Anim(float duration, int key,int NumFrames,SDL_Renderer* pRender){

GOList[key].Nanimate(duration ,NumFrames, pRender);

}
void GOfactory::AddGrid(int NumCol,int NumRows, std::string textureID,int width,int height,int GridX,int GridY ){

	for(int y =0; y <= GridY;y++){
		for(int x =0; x <= GridX; x++){
	
		addGO(textureID,NumCol,NumRows,width,height,width * y,height* x);

		}
	}


}


