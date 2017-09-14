#include "PlayerData.h"


PlayerMSG::PlayerMSG(PlayerAction action, ID target, ID sender )
	:msg(target,sender,MSGTYPE::Player) {
	m_action = action;	
	}

void PlayerMSG::update(void* Variables){

auto &mybod = *reinterpret_cast<b2Body*>(Variables); 

switch( m_action){

	case PlayerAction::Idle:
	break;

	case PlayerAction::WalkLeft :
    mybod.ApplyLinearImpulse( b2Vec2(-500,0), mybod.GetWorldCenter(), true);
   mybod.ApplyForce( b2Vec2(-500000,0), mybod.GetWorldCenter(), true); 

	break;

	case PlayerAction::WalkRight:
    mybod.ApplyLinearImpulse( b2Vec2(500 ,0), mybod.GetWorldCenter(), true);
    mybod.ApplyForce( b2Vec2(500000, 0), mybod.GetWorldCenter(), true);
	break;


	
	case PlayerAction::Jump:
  mybod.ApplyLinearImpulse( b2Vec2(0,-50000), mybod.GetWorldCenter(), true);
  mybod.ApplyLinearImpulse( b2Vec2(0,-50000), mybod.GetWorldCenter(), true);
  mybod.ApplyLinearImpulse( b2Vec2(0,-50000), mybod.GetWorldCenter(), true);
    break;

	case PlayerAction::Crouch:
	break;

	case PlayerAction::SlowToStop:
	break;

	default :
	break;
	}	

}
