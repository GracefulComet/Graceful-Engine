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
    mybod.ApplyForce( b2Vec2(-50000,-100), mybod.GetWorldCenter(), false);

	break;

	case PlayerAction::WalkRight:
    mybod.ApplyLinearImpulse( b2Vec2(5000,-100), mybod.GetWorldCenter(), false);
	break;
	
	case PlayerAction::Jump:
    break;

	case PlayerAction::Crouch:
	break;

	case PlayerAction::SlowToStop:
	break;

	default :
	break;
	}	

}
