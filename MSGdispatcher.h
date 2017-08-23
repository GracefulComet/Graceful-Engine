#pragma once

#include "MSGreciever.h"
#include "Messages.h"

class MSGdispatcher {

public:
  MSGdispatcher() = default;
  MSGdispatcher(MSGreciever *FirstTarget);

  void registerMSGER(MSGreciever *listener);
  // void sendMSG( std::shared_ptr<msg> Message );
  void sendMSG(std::unique_ptr<msg> &&Message);

public:
  std::vector<MSGreciever *> m_Listeners;
};
