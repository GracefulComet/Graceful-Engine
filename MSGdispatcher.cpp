#include "MSGdispatcher.h"

MSGdispatcher::MSGdispatcher(MSGreciever *FirstTarget) {
  registerMSGER(FirstTarget);
}

void MSGdispatcher::registerMSGER(MSGreciever *listener) {
  m_Listeners.push_back(listener);
}

// void MSGdispatcher::sendMSG( std::shared_ptr<msg> Message )
//{
//	for( auto &listener : m_Listeners )
//	{
//		listener->getMSGS( Message );
//	}
//}

void MSGdispatcher::sendMSG(std::unique_ptr<msg> &&Message) {
  for (auto &listener : m_Listeners) {

    if (Message.get() != nullptr) {
      if (Message->getTargetID().matchMyID(listener->SentTo)) {
        listener->getMSGS(std::move(Message));
      }
    } // else{}
  }
}
