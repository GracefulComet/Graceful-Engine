#include "TerrainCtrl.h"

TerrainCtrl::TerrainCtrl(MSGreciever *firstListener, int idNum, TerrType type) {
  m_Mine = ID(idNum, OBJTYPE::GameOBJ);
  m_Target = ID(idNum, OBJTYPE::Sprite);
  m_mailman = MSGdispatcher(firstListener);
  m_type = type;
}
TerrainCtrl *TerrainCtrl::getPtr() { return this; }
void TerrainCtrl::update() {
  m_mailman.sendMSG(
      std::make_unique<AnimationMSG>(0, 0, state::idle, m_Target, m_Mine));
}
