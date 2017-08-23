#pragma once
#include "vmath.h"

class Physdata {
public:
  Physdata() = default;
  ~Physdata() = default;
  Physdata(float x, float y, double angle)
      : m_Position(x, y), m_RotationAngle(angle) {}
  Vec2DF m_Position;
  double m_RotationAngle;
};
