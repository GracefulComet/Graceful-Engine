#include "Collision.h"


CollisionData::CollisionData(){}
CollisionData::~CollisionData(){}
CollisionData::CollisionData(int id, SDL_Rect Rectangle){
    m_id = id;
    m_box = Rectangle;
}
SDL_Rect* CollisionData::getRect(){
    return &m_box;
}
int CollisionData::getID(){
    return m_id;
}


ID CollisionSystem::getID() { return m_MyID; }
CollisionSystem::CollisionSystem(){
	m_MyID = ID( 0 , OBJTYPE::CollisionSystem);
}
CollisionSystem::~CollisionSystem(){}
CollisionSystem:: CollisionSystem(MSGreciever* firstregister , CollisionData firstobj , int idnumber){
	m_MyID = ID(idnumber, OBJTYPE::CollisionSystem);
	m_sender.registerMSGER(firstregister);
	m_data.push_back(firstobj);

}
void CollisionSystem::updatePositions()
{
}
 void CollisionSystem::addObjToTrack(CollisionData addee){
	 m_data.push_back(addee);
 }
 void CollisionSystem::addListener(MSGreciever* listener ){
	 m_sender.registerMSGER(listener);
 }
 void CollisionSystem::detectCollides(SDL_Rect* box1 , SDL_Rect* box2){
 
	 if (SDL_HasIntersection(box1, box2) == SDL_TRUE) {
		 std::cout << "collided" << std::endl;
	 }


 }
 void CollisionSystem::detectAll(){
	 for (unsigned int i = 0; i < m_data.size(); i++) {
		 for (unsigned int j = 0; j < m_data.size(); j++) {
			 if (i != j) {
				 detectCollides(m_data[i].getRect(), m_data[j].getRect());
				 //m_sender.sendMSG();
			 }
			 else {}

		 }

	 }

 }
