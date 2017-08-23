//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "Timer.h"

bool TimerF::cooldown(float duration) {

  m_prevTime = m_currTime;
  m_currTime = SDL_GetTicks();
  m_deltaTime += (m_currTime - m_prevTime);

  if (m_deltaTime >= duration) {
    m_ready = true;
    return m_ready;
  } else {
    m_ready = false;
    return m_ready;
  }
  if (m_deltaTime < 0) {
    m_deltaTime = 0;
  }

  return m_ready;
}

void TimerF::reset() {
  m_deltaTime = 0;
  m_ready = false;
}
float TimerF::getDelta() { return m_deltaTime; }
