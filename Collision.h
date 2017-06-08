#pragma once
#include "Messages.h"
#include <SDL2/SDL.h>
#include <vector>

class CollisionData{
public:

    CollisionData();
    ~CollisionData();
    CollisionData(int id, SDL_Rect Rectangle);
    SDL_Rect getRect();
    int getID();


private:
    SDL_Rect m_box;
    int m_id;
};


class CollisionSystem{

public:

    CollisionSystem();
    ~CollisionSystem();
     CollisionSystem(MSGreciever firstregister);
     void addObjToTrack();
     void addListener();
     void detectCollides();
     void detectAll();


private:

    std::vector <CollisionData > m_data;
    std::vector <MSGreciever* > m_listeners;
    MSGdispatcher m_sender;

};
