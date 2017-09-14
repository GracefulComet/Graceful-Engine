#pragma once
#include <Box2D/Box2D.h>
#include "MSGreciever.h"
#include "MSGdispatcher.h"
#include <vector>
#include "vmath.h"
#include "PhysicsMSG.h"
#include "pCollisionMSG.h"

class MContactListener;

class PhysicsSystem {
public:
  PhysicsSystem();
  ~PhysicsSystem();

  void addTestObj(Vec2DF Pos, ID identity);
  void addTestGround(Vec2DF Pos, ID  identity);
  void addLinkToSprite(MSGreciever *targetToSendMSGS, ID targetIDentifier);
  void addLinkToBehaviour(MSGreciever *targetToSendMSGS, ID targetIDentifier);
  ID getID();
  MSGreciever* getListener();
  void sendUpdatedPhysdata();
  void sendCollisionData();
  void getBehaviourMSGS();
  void RespondToEntitys();
  bool handleMSGS( void* Variable );

  void update();

//private:
  MSGdispatcher m_Sprite_sender;
  MSGdispatcher m_Behaviour_sender;
  MSGreciever m_Behaviour_Listener;
  std::vector<ID> BehaviourIDs;
  std::vector<void *> userdata;
  ID m_myID;
  b2World *TheWorld;
  MContactListener* m_WListener;
};

class MContactListener : public b2ContactListener{
	public:
   MContactListener(PhysicsSystem* systemptr);
   ~MContactListener();
   void BeginContact(b2Contact* contact)override;  
   void EndContact(b2Contact* contact)override;


   PhysicsSystem* p_sys;
};
