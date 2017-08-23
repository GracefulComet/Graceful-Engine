#include "PlayerCtrl.h"
#include "AnimationMSG.h"
#include "PhysicsMSG.h"

PlayerCtrl::PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt, int idnum)
    : Movement(Move::Idle), event(Evnt), test() {
  m_Mine = ID(idnum, OBJTYPE::GameOBJ);
  m_Target = ID(idnum, OBJTYPE::Sprite);
  m_mailman = MSGdispatcher(firstListener);
}

PlayerCtrl *PlayerCtrl::getPtr() { return this; }

void PlayerCtrl::update() {
  LastMovement = Movement;

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
    case SDLK_UP:
      Movement = Move::Up;
      break;
    case SDLK_DOWN:
      Movement = Move::Down;
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
      case SDLK_RIGHT:
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
    Velocity += Vec2DF(-0.25f, 0.0f);
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(15, 3, state::animated,
                                                     m_Target, m_Mine));
    //    m_mailman.sendMSG(std::make_unique<PhysicsMSG>(Velocity,
    //    0.0f,m_Target, m_Mine));
    break;
  case Move::Right:
    Velocity += Vec2DF(0.25f, 0.0f);
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(27, 3, state::animated,
                                                     m_Target, m_Mine));
    //    m_mailman.sendMSG(std::make_unique<PhysicsMSG>(Velocity,0.0f
    //    ,m_Target, m_Mine));
    break;
  case Move::Up:
    Velocity += Vec2DF(0.0f, -0.25f);
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(39, 3, state::animated,
                                                     m_Target, m_Mine));
    //    m_mailman.sendMSG(std::make_unique<PhysicsMSG>(Velocity,0.0 ,m_Target,
    //    m_Mine));
    break;
  case Move::Down:
    Velocity += Vec2DF(0.0f, 0.25f);
    m_mailman.sendMSG(std::make_unique<AnimationMSG>(3, 3, state::animated,
                                                     m_Target, m_Mine));
    //    m_mailman.sendMSG(std::make_unique<PhysicsMSG>(Velocity,0.0,m_Target,
    //    m_Mine));
    break;
  case Move::Idle:
    Velocity += Vec2DF(0.0, 0.0);
    // test.m_RotationAngle += 5.0f;
    // m_mailman.sendMSG(std::make_unique<PhysicsMSG>(0.0f,
    // 0.0f,test.m_RotationAngle,m_Target, m_Mine));
    break;
  default:
    Movement = Move::Idle;
  }
}
