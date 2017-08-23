#include "MSGreciever.h"

MSGreciever::MSGreciever(ID Owner) : SentTo(Owner) {}

// void MSGreciever::getMSGS( std::shared_ptr<msg> message )
//{
//	que.push_back( message );
//}

void MSGreciever::getMSGS(std::unique_ptr<msg> &&message) {
  que.push_back(std::move(message));
}

MSGTYPE MSGreciever::peakatMSGS() {

  if (que.empty() == false) {

    if (que.back() == nullptr) {
      return MSGTYPE::Failed;
    }
    return que.back()->m_type;
  } else {
    return MSGTYPE::Failed;
  }
}

void MSGreciever::CheckForGarbage() {
  if (que.back() == nullptr) {
    que.clear();
  }
}

void MSGreciever::handleMSGS(void *passedvar) {
  for (auto &item : que) {
    if (SentTo.matchMyID(item->getTargetID())) {

      item->update(passedvar);

      que.pop_back();

    } else {
      que.pop_back();
    }
  }
}

bool MSGreciever::handleMSG(void *passedvar) {
  if (!que.empty()) {
    const auto &item = que.back();
    if (SentTo.matchMyID(item->getTargetID()) == true) {
      item->update(passedvar);
      que.pop_back();
    } else {
      que.pop_back();
    }
  }

  return que.empty();
}
