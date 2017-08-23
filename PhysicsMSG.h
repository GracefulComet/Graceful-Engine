#pragma once

#include "Messages.h"
#include "vmath.h"

class PhysicsMSG : public msg {
public:
  PhysicsMSG() = default;
  //  ~PhysicsMSG()=default;
  PhysicsMSG(float x, float y, double dt, ID target, ID Sender);

  void update(void *Variables) override;

public:
  float m_x;
  float m_y;
  double m_rotation;
};
