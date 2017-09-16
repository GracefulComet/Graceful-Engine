#include "PlayerCtrl.h"
#include "AnimationMSG.h"
#include "PhysicsMSG.h"

PlayerCtrl::PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt, int idnum,ID physix)
    : Movement(Move::Idle), event(Evnt), test() {
  m_Mine = ID(idnum, OBJTYPE::GameOBJ,GOTYPE::Player);
  m_Target = ID(idnum, OBJTYPE::Sprite);
  m_mailman = MSGdispatcher(firstListener);
  m_mailbox = MSGreciever(m_Mine);
  PhysMSGID = physix; 
  FaceingLeft = false;
  LastMovement = Move::Idle;
  SameMovement = 0;
  m_collideR.numOfContacts = 0;
  m_collideR.numOfRings = 0;
  m_collideR.CanJump = false;
  m_collideR.Grounded = false;
  m_collideR.LastState = CollData::AirBorne;
  Action = p_Action::no_action;
  LastAction = p_Action::no_action;
}

PlayerCtrl *PlayerCtrl::getPtr() { return this; }

void PlayerCtrl::addListener(MSGreciever* addee){
    m_mailman.registerMSGER(addee);
}

void PlayerCtrl::handleMSGS(){
switch(m_mailbox.peakatMSGS()){

  case MSGTYPE::Collision :
if(m_mailbox.handleMSG(&m_collideR) == false){this->handleMSGS();}

  break;


  default :
break;
}



}

void PlayerCtrl::update() {

  if (m_time.cooldown(1/60.0f) == true) {
    m_time.reset();
  }

  this->handleMSGS();
  if(m_collideR.numOfContacts == 0){
    m_collideR.CanJump = false;
    m_collideR.Grounded = false;
  }else if(m_collideR.numOfContacts > 0 ){
    m_collideR.CanJump = true;
    m_collideR.Grounded = true;
  }

  const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

  if( currentKeyStates[ SDL_SCANCODE_DOWN ] ) { Movement = Move::Crouch;} 
  else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ) { Movement = Move::Left;} 
  else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ) { Movement = Move::Right;} 
    else { Movement = Move::Idle;}
  if(currentKeyStates[ SDL_SCANCODE_SPACE]) {
    if(m_collideR.CanJump == true){Action = p_Action::Jump;} 
  }// else {}

  if(event->type == SDL_KEYUP){
    if(event->key.keysym.sym == SDLK_SPACE){
    Action = p_Action::no_action; 
    }

  }








 switch (Movement) {
  case Move::Left:

    if(LastMovement ==  Movement){
   SameMovement++; 
    }else{LastMovement = Movement;
    SameMovement = 0;
    }
    if(m_collideR.Grounded == true){ 
    FaceingLeft = true;

    if(SameMovement < 150){
   m_mailman.sendMSG(std::make_unique<AnimationMSG>(27, 8, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));
   m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkLeft,PhysMSGID,m_Mine ));
    }
    else if(SameMovement > 150){
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(35, 4, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));
   m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkLeft,PhysMSGID,m_Mine ));
    
    }
  }
    break;
  case Move::Right:
   FaceingLeft = false;  

    if(LastMovement ==  Movement){
   SameMovement++; 
    }else{LastMovement = Movement;
    SameMovement = 0;
    }
if(m_collideR.Grounded == true){ 
    if(SameMovement < 150){
   m_mailman.sendMSG(std::make_unique<AnimationMSG>(27, 8, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));
   m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkRight,PhysMSGID,m_Mine ));
    }
    else if(SameMovement > 150){
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(35, 4, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));
   m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkRight,PhysMSGID,m_Mine ));
    } 
    }
    break;
  case Move::Crouch:
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(0, 0, FaceingLeft,state::animated,
                                                      m_Target, m_Mine));

    break;
  case Move::Idle:

    if(LastMovement ==  Movement){
   SameMovement++; 
    }else{LastMovement = Movement;
    SameMovement = 0;
    }
    
   if(m_collideR.Grounded == true){ 
    if(SameMovement < 150 ){     m_mailman.sendMSG(std::make_unique<AnimationMSG>(0, 0,FaceingLeft, state::animated,
                                                     m_Target, m_Mine));
    }else if(SameMovement > 150 && SameMovement < 190){
        m_mailman.sendMSG(std::make_unique<AnimationMSG>(5, 1,FaceingLeft, state::cycle,
                                                     m_Target, m_Mine));
    }else if(SameMovement > 190 && SameMovement < 205){
        m_mailman.sendMSG(std::make_unique<AnimationMSG>(6, 1,FaceingLeft, state::cycle,
                                                     m_Target, m_Mine));
    }
    
    else if(SameMovement > 210){
         m_mailman.sendMSG(std::make_unique<AnimationMSG>(7, 2,FaceingLeft, state::cycle,
                                                     m_Target, m_Mine));
    }
  }else{SameMovement = 0;}
    //else if(SameMovement > 170){
    // m_mailman.sendMSG(std::make_unique<AnimationMSG>(9, 3,FaceingLeft, state::animated,
     //                                                m_Target, m_Mine));
    
    //}
 	break;

  default:
    Movement = Move::Idle;
  }

  switch(Action){
case p_Action::no_action :
break;  

case p_Action::Jump :
 if(LastAction ==  Action){
    SameAction++; 
    }else{LastAction = Action;
    SameAction = 0;
    }
if(m_collideR.CanJump){SameAction = 0;}
    if(SameAction < 15){
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(39, 5, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));  
 m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::Jump,PhysMSGID,m_Mine ));
    }else{ m_mailman.sendMSG(std::make_unique<AnimationMSG>(39, 5, FaceingLeft,state::animated,
                                                     m_Target, m_Mine));  
    }
break;

default :
break;  

}

}
