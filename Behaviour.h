#pragma once

#include "ID.h"
#include "MSGdispatcher.h"
#include "Timer.h"

class Behaviour {

public:
  Behaviour() = default;
  virtual ~Behaviour() = default;

  virtual void update() = 0;
  virtual void addListener(MSGreciever* addee);
  MSGreciever *getlistener();

public:
  ID m_Mine;
  ID m_Target;
  MSGdispatcher m_mailman;
  MSGreciever m_mailbox;
};
