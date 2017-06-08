#include "Collision.h"


CollisionData::CollisionData(){}
CollisionData::~CollisionData(){}
CollisionData::CollisionData(int id, SDL_Rect Rectangle){
    m_id = id;
    m_box = Rectangle;
}
SDL_Rect CollisionData::getRect(){
    return m_box;
}
int CollisionData::getID(){
    return m_id;
}



CollisionSystem::CollisionSystem(){}
CollisionSystem::~CollisionSystem(){}
CollisionSystem:: CollisionSystem(MSGreciever firstregister){}
 void CollisionSystem::addObjToTrack(){}
 void CollisionSystem::addListener(){}
 void CollisionSystem::detectCollides(){}
 void CollisionSystem::detectAll(){}
