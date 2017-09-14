#pragma once
#include <iostream>
#include "PhysData.h"
#include "Behaviour.h"
#include "vmath.h"
#include "PlayerData.h"
#include "pCollisionMSG.h"

enum class Move { Left, Right, ViewUp ,Crouch, Idle };
enum class p_Action{ no_action, Jump, Spin, Dash };
class PlayerCtrl : public Behaviour {
public:
  PlayerCtrl() = default;
  PlayerCtrl(MSGreciever *firstListener, SDL_Event *Evnt,
             int idnum , ID physix );

  PlayerCtrl *getPtr();
  void addListener( MSGreciever* addee) override;
  void update() override;
  void handleMSGS();

private:
  Move Movement;
  Move LastMovement;
  p_Action Action;
  p_Action LastAction;
  int SameAction;
  int SameMovement;
  SDL_Event *event;
  TimerF m_time;
  Physdata test;
  ID PhysMSGID;
  bool FaceingLeft;
  pCollidedata m_collideR;
};


