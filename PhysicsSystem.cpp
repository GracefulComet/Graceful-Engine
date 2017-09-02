#include "PhysicsSystem.h"
#include <iostream>

PhysicsSystem::PhysicsSystem() {
  const b2Vec2 Gravity(0.0f, 50.0f);
  TheWorld = new b2World(Gravity);
  m_myID = ID(0,OBJTYPE::CollisionSystem);
  m_Behaviour_Listener = MSGreciever(m_myID);
}

PhysicsSystem::~PhysicsSystem() { delete TheWorld;
while(userdata.empty() == !true){ 
userdata.pop_back();

  }
}

void PhysicsSystem::addTestObj(Vec2DF Pos, ID identity) {

    b2BodyDef bodydef;
     bodydef.type = b2_dynamicBody;
     bodydef.position.Set(Pos.x, Pos.y);
     userdata.push_back(new ID(identity));
     bodydef.userData = userdata.back();
     b2Body *body = TheWorld->CreateBody(&bodydef);
     b2PolygonShape dynamicBox;
     dynamicBox.SetAsBox(15.0f, 15.0f);
     b2FixtureDef fixturedef;
     fixturedef.shape = &dynamicBox;
     fixturedef.density = 0.9f;
     fixturedef.friction = 0.3f;
     body->CreateFixture(&fixturedef);


}
void PhysicsSystem::addTestGround(Vec2DF Pos, ID identity) {
  b2BodyDef GroundBodyDef;
  GroundBodyDef.type = b2_staticBody;
  userdata.push_back(new ID(identity));
  GroundBodyDef.userData = userdata.back();
  GroundBodyDef.position.Set(Pos.x, Pos.y);
  b2Body *GroundBody = TheWorld->CreateBody(&GroundBodyDef);
  b2PolygonShape GroundBox;
  GroundBox.SetAsBox(15.0f, 15.0f);
  GroundBody->CreateFixture(&GroundBox, 0.0f);
}

void PhysicsSystem::addLinkToSprite(MSGreciever *targetToSendMSGS,
                                    ID targetIDentifier) {
  m_Sprite_sender.registerMSGER(targetToSendMSGS);

}
void PhysicsSystem::addLinkToBehaviour(MSGreciever *targetToSendMSGS,
                                       ID targetIDentifier) {
  m_Behaviour_sender.registerMSGER(targetToSendMSGS);
  BehaviourIDs.push_back(targetIDentifier);
}

void PhysicsSystem::RespondToEntitys(){ 
auto *b = TheWorld->GetBodyList();
while(b != NULL){
    auto *target = reinterpret_cast<ID *>(b->GetUserData());




    switch(m_Behaviour_Listener.peakatMSGS()){

        case MSGTYPE::Failed :
            b = b->GetNext();
        break;

        case MSGTYPE::Player :
        if(target->m_IDNumber == m_Behaviour_Listener.que.back()->m_SenderID.m_IDNumber){
        m_Behaviour_Listener.handleMSG(b);
        b = b->GetNext();}
        else{b = b->GetNext();

            std::cout << target->m_IDNumber << " vs " << m_Behaviour_Listener.que.back()->m_TargetID.m_IDNumber << std::endl;
        }



        break;


        default :

        b = b->GetNext();
        break;

}

}

}



void PhysicsSystem::sendUpdatedPhysdata() {
  auto *b = TheWorld->GetBodyList();

  while (b != NULL) {

    ID* target = reinterpret_cast<ID* >(b->GetUserData());

    m_Sprite_sender.sendMSG(std::make_unique<PhysicsMSG>(
        b->GetPosition().x, b->GetPosition().y, b->GetAngle(), target[0],
        ID(0, OBJTYPE::CollisionSystem)));
    b = b->GetNext();
  }
}

ID PhysicsSystem::getID(){return m_myID;}

void PhysicsSystem::update() {

  TheWorld->Step(1.0f / 60.0f, 6, 2);
  this->RespondToEntitys();
  this->sendUpdatedPhysdata();
}

MSGreciever* PhysicsSystem::getListener(){return &m_Behaviour_Listener; }

bool PhysicsSystem::handleMSGS(void* Variable){
switch(m_Behaviour_Listener.peakatMSGS()){

	case MSGTYPE::Failed :
        std::cout << "there was a problem recieveing the message" << std::endl;
		return false;
	break;

    case MSGTYPE::Player :
	if(m_Behaviour_Listener.handleMSG(Variable) == false){
	return false;}else{return true;}
	break;


	default :
	return true;
	break;
}
}

