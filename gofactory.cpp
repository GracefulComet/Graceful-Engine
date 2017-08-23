//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "gofactory.h"
#include "PlayerCtrl.h"
#include "TerrainCtrl.h"
// TODO: Add other Object Types. types to do , Terrain, UI and Forground

GOfactory::GOfactory() {}

void GOfactory::addGFX(Sprite &&graphic) { Gfx.push_back(std::move(graphic)); }

void GOfactory::updateGFX(float deltaT) {
  for (auto &sprite : Gfx) {

    sprite.update(deltaT);
  }
}

void GOfactory::drawGFX(SDL_Renderer *pRender) {
  for (auto &sprite : Gfx) {
    sprite.draw(pRender);
  }
}

void GOfactory::updateCollision() { PS.update(); }

// void GOfactory::addBehaviour( std::shared_ptr<Behaviour> Addee )
//{
//	m_Entities.push_back( Addee );
//}

void GOfactory::addBehaviour(std::unique_ptr<Behaviour> &&Addee) {
  m_Entities.push_back(std::move(Addee));
}

void GOfactory::updateBehaviour() {
  for (auto &pEntity : m_Entities) {
    pEntity->update();
  }
}

// todo add set position into the variables you want to set
void GOfactory::addPlayer(std::string filetoSprite, SDL_Event *evt,
                          SDL_Renderer *render, Vec2DF pos) {
  m_IDKeys++;
  addGFX(Sprite(filetoSprite, render, state::animated, m_IDKeys));
  Gfx.back().SetPos(pos.x, pos.y);

  for (unsigned int i = 0; i < Gfx.size(); i++) {
    if (ID(m_IDKeys, OBJTYPE::Sprite).matchMyID(Gfx[i].getID())) {
      // addBehaviour( std::make_shared<PlayerCtrl>( Gfx[ i ].getListener(),
      // evt, m_IDKeys ) );
      addBehaviour(std::make_unique<PlayerCtrl>(Gfx.back().getListener(), evt,
                                                m_IDKeys));
      PS.addLinkToSprite(Gfx.back().getListener(), Gfx.back().getID());
      PS.addTestObj(pos, Gfx.back().getID());
    }
  }
}
void GOfactory::addTerrain(std::string filetoSprite, SDL_Renderer *render,
                           Vec2DF pos) {
  m_IDKeys++;
  addGFX(Sprite(filetoSprite, render, state::idle, m_IDKeys));
  Gfx.back().SetPos(pos.x, pos.y);
  addBehaviour(std::make_unique<TerrainCtrl>(Gfx.back().getListener(), m_IDKeys,
                                             TerrType::Floor));
  PS.addLinkToSprite(Gfx.back().getListener(), Gfx.back().getID());
  PS.addTestGround(pos, Gfx.back().getID());
}
