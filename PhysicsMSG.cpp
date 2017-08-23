#include "PhysicsMSG.h"
#include "PhysData.h"
#include <iostream>

PhysicsMSG::PhysicsMSG(float x, float y, double angle, ID target, ID Sender)
    : msg(target, Sender, MSGTYPE::Physics), m_x(x), m_y(y), m_rotation(angle) {
}

void PhysicsMSG::update(void *Variables) {
  if ((Variables) == nullptr) {
    std::cout << " Got Null" << std::endl;
  } else {
    auto &LocationData = *reinterpret_cast<Physdata *>(Variables);

    LocationData.m_RotationAngle = m_rotation;
    LocationData.m_Position.x = m_x;
    LocationData.m_Position.y = m_y;
  }
}
