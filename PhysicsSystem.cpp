#include "PhysicsSystem.h"
#include <iostream>

PhysicsSystem::PhysicsSystem() {
  const b2Vec2 Gravity(0.0f, 50.0f);
  TheWorld = new b2World(Gravity);
}

PhysicsSystem::~PhysicsSystem() { delete TheWorld; }

void PhysicsSystem::addTestObj(Vec2DF Pos, ID identity) {

  b2BodyDef bodydef;
  bodydef.type = b2_dynamicBody;
  bodydef.position.Set(Pos.x, Pos.y);
  userdata.push_back(new ID(identity));
  bodydef.userData = userdata.back();
  b2Body *body = TheWorld->CreateBody(&bodydef);
  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(16.0f, 16.0f);
  b2FixtureDef fixturedef;
  fixturedef.shape = &dynamicBox;
  fixturedef.density = 20.0f;
  fixturedef.friction = 0.3f;
  body->CreateFixture(&fixturedef);
  //   userdata.push_back(new ID(identity));
  // body->SetUserData( userdata.back());
}
void PhysicsSystem::addTestGround(Vec2DF Pos, ID identity) {
  b2BodyDef GroundBodyDef;
  GroundBodyDef.type = b2_staticBody;
  userdata.push_back(new ID(identity));
  GroundBodyDef.userData = userdata.back();
  GroundBodyDef.position.Set(Pos.x, Pos.y);
  b2Body *GroundBody = TheWorld->CreateBody(&GroundBodyDef);
  b2PolygonShape GroundBox;
  GroundBox.SetAsBox(16.0f, 16.0f);
  GroundBody->CreateFixture(&GroundBox, 0.0f);
}

void PhysicsSystem::addLinkToSprite(MSGreciever *targetToSendMSGS,
                                    ID targetIDentifier) {
  m_Sprite_sender.registerMSGER(targetToSendMSGS);
  // SpriteIDs.push_back(targetIDentifier);
}
void PhysicsSystem::addLinkToBehaviour(MSGreciever *targetToSendMSGS,
                                       ID targetIDentifier) {
  m_Behaviour_sender.registerMSGER(targetToSendMSGS);
  BehaviourIDs.push_back(targetIDentifier);
}
void PhysicsSystem::sendUpdatedPhysdata() {
  auto *b = TheWorld->GetBodyList();

  while (b != NULL) {

    auto *target = reinterpret_cast<ID *>(b->GetUserData());

    m_Sprite_sender.sendMSG(std::make_unique<PhysicsMSG>(
        b->GetPosition().x, b->GetPosition().y, b->GetAngle(), *target,
        ID(0, OBJTYPE::CollisionSystem)));
    b = b->GetNext();
  }
}

void PhysicsSystem::update() {

  TheWorld->Step(1.0f / 60.0f, 6, 2);
  this->sendUpdatedPhysdata();
}