#pragma once
#include "Messages.h"

enum class CollData { AirBorne, Grounded, GRing,Enemy };

struct pCollidedata{
  int numOfContacts;
  int numOfRings;
  bool CanJump;
  bool Grounded;
  CollData LastState;  
};
class pCollisionMSG : public msg{
	public:
pCollisionMSG( CollData collision ,ID target, ID sender);
~pCollisionMSG()=default;
void update(void* Variables)override;
CollData data;

};
