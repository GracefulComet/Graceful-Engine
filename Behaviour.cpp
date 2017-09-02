#include "Behaviour.h"

MSGreciever *Behaviour::getlistener() { return &m_mailbox; }
void Behaviour::addListener(MSGreciever* addee){m_mailman.registerMSGER(addee); }
