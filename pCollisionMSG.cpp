#include "pCollisionMSG.h"

pCollisionMSG::pCollisionMSG(CollData collision , ID target, ID sender):msg(target,sender,MSGTYPE::Collision), data(collision) {}
void pCollisionMSG::update(void * Variables){

	auto* Collision = reinterpret_cast<pCollidedata*>(Variables);
	
          if(data == CollData::Grounded){
	  Collision->numOfContacts++;
	  }else if(data == CollData::AirBorne){Collision->numOfContacts--; }
}
