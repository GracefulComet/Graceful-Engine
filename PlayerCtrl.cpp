#include "PlayerCtrl.h"
#include "AnimationMSG.h"
#include "PhysicsMSG.h"

PlayerCtrl::PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt, int idnum,ID physix)
    : Movement(Move::Idle), event(Evnt), test() {
  m_Mine = ID(idnum, OBJTYPE::GameOBJ);
  m_Target = ID(idnum, OBJTYPE::Sprite);
  m_mailman = MSGdispatcher(firstListener);
  PhysMSGID = physix; 
}

PlayerCtrl *PlayerCtrl::getPtr() { return this; }

void PlayerCtrl::addListener(MSGreciever* addee){
    m_mailman.registerMSGER(addee);
    if(PhysMSGID.matchMyID(addee->SentTo)){
    std::cout << "Message Registrations does match" <<std::endl;
    }else{

    std::cout << PhysMSGID.m_IDNumber << " /n";
    }
                                                   }



void PlayerCtrl::update() {

  if (m_time.cooldown(60.0f) == true) {
    m_time.reset();
  }

  if (event->type == SDL_KEYDOWN) {
    switch (event->key.keysym.sym) {
    case SDLK_LEFT:
      Movement = Move::Left;
      break;
    case SDLK_RIGHT:
      Movement = Move::Right;
      break;
    case SDLK_SPACE:
      Movement = Move::Jump;
      break;
    case SDLK_DOWN:
      Movement = Move::Crouch;
      break;
    default:
      Movement = Move::Idle;
    }
  } else {
    if (event->type == SDL_KEYUP) {
      switch (event->key.keysym.sym) {
      case SDLK_LEFT:
        Movement = Move::Idle;
        break;
      case SDLK_SPACE:
        Movement = Move::Idle;
        break;
      case SDLK_UP:
        Movement = Move::Idle;
        break;
      case SDLK_DOWN:
        Movement = Move::Idle;
        break;
      default:
        Movement = Move::Idle;
      }
    }
  }

  switch (Movement) {
  case Move::Left:

    m_mailman.sendMSG(std::make_unique<AnimationMSG>(15, 3, state::animated,
                                                     m_Target, m_Mine));
    m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkLeft,PhysMSGID,m_Mine ));


    break;
  case Move::Right:
 
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(27, 3, state::animated,
                                                     m_Target, m_Mine));
   m_mailman.sendMSG(std::make_unique<PlayerMSG>( PlayerAction::WalkRight,PhysMSGID,m_Mine ));
   
    break;
  case Move::Jump:
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(39, 3, state::animated,
                                                     m_Target, m_Mine));  
    break;
  case Move::Crouch:
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(3, 3, state::animated,
                                                     m_Target, m_Mine));
    break;
  case Move::Idle:

    break;
  default:
    Movement = Move::Idle;
  }
}
