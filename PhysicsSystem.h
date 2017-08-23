#pragma once
#include <Box2D/Box2D.h>
#include "MSGreciever.h"
#include "MSGdispatcher.h"
#include <vector>
#include "vmath.h"
#include "PhysicsMSG.h"

class PhysicsSystem {
public:
  PhysicsSystem();
  ~PhysicsSystem();

  void addTestObj(Vec2DF Pos, ID identity);
  void addTestGround(Vec2DF Pos, ID identity);
  void addLinkToSprite(MSGreciever *targetToSendMSGS, ID targetIDentifier);
  void addLinkToBehaviour(MSGreciever *targetToSendMSGS, ID targetIDentifier);
  void sendUpdatedPhysdata();
  void sendCollisionData();
  // needs to create physics world objs
  // needs to send uppdated obj positions(converted from meters to pixels
  // do we need to handle rotations? if so how.
  void update();

private:
  MSGdispatcher m_Sprite_sender;
  MSGdispatcher m_Behaviour_sender;
  //	std::vector <ID> SpriteIDs;
  std::vector<ID> BehaviourIDs;
  std::vector<void *> userdata;
  // std::vector<b2Bodies >Bodies;
  b2World *TheWorld;
};
