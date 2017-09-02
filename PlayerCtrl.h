#pragma once
#include <iostream>
#include "PhysData.h"
#include "Behaviour.h"
#include "vmath.h"
#include "PlayerData.h"

enum class Move { Left, Right, Jump ,Crouch, Idle };

class PlayerCtrl : public Behaviour {
public:
  PlayerCtrl() = default;
  PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt,
             int idnum , ID physix );

  PlayerCtrl *getPtr();
  void addListener( MSGreciever* addee) override;
  void update() override;


private:
  Move Movement;
  SDL_Event *event;
  TimerF m_time;
  Physdata test;
  ID PhysMSGID;
};
