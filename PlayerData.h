#include "Messages.h"
#include <Box2D/Box2D.h>

enum class PlayerAction {Idle, WalkLeft, WalkRight, Jump , Crouch , SlowToStop };


class PlayerMSG : public msg{
	public :
//PlayerMSG()=default;
PlayerMSG(PlayerAction action , ID target, ID sender );
~PlayerMSG()=default;

 void update(void* Variables)override;
 PlayerAction m_action;



};
