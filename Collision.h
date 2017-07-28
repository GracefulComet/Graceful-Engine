#pragma once
#include "Messages.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class CollisionData{
public:

    CollisionData();
    ~CollisionData();
    CollisionData(int id, SDL_Rect Rectangle);
    SDL_Rect* getRect();
    int getID();


private:
    SDL_Rect m_box;
    int m_id;
};


class CollisionSystem{

public:

    CollisionSystem();
    ~CollisionSystem();
     CollisionSystem(MSGreciever* firstregister, CollisionData firstobj , int idnumber);
     void updatePositions();
     void addObjToTrack( CollisionData addee);
     void addListener(MSGreciever* listener );
     void detectCollides(SDL_Rect* box1 , SDL_Rect* box2);
     void detectAll();
	 ID getID();


private:
	ID m_MyID;
    std::vector <CollisionData > m_data;
    MSGdispatcher m_sender;

};
