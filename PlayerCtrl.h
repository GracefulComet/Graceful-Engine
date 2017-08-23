#pragma once
#include <iostream>
#include "PhysData.h"
#include "Behaviour.h"
#include "vmath.h"

enum class Move { Left, Right, Up, Down, Idle };

class PlayerCtrl : public Behaviour {
public:
  PlayerCtrl() = default;
  PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt,
             int idnum /*, ID physix */);

  PlayerCtrl *getPtr();
  void update() override;

private:
  Move Movement;
  Move LastMovement;
  Vec2DF Velocity;
  SDL_Event *event;
  TimerF m_time;
  Physdata test;
};
