#pragma once

#include "Behaviour.h"
#include "vmath.h"
#include "AnimationMSG.h"

enum class TerrType { Floor, CollapsableFloor };

class TerrainCtrl : public Behaviour {
public:
  TerrainCtrl() = default;
  TerrainCtrl(MSGreciever *firstListener, int idNum, TerrType type);
  TerrainCtrl *getPtr();
  void update() override;

private:
  TerrType m_type;
};
