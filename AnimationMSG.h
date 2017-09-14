#pragma once

#include "Messages.h"
#include "TileMap.h"

class AnimationMSG : public msg {
public:
  AnimationMSG() = default;
  AnimationMSG(int curTile, int AnimateFrames,bool flip , state desiredState, ID target,
               ID Sender);

  void update(void *Variables) override;

public:
  bool Flip;
  int m_curFrameSet;
  int m_AnimationFramesSet;
  state m_state;
};
