#include "Behaviour.h"

MSGreciever * Behaviour::getlistener()
{
	return &m_mailbox;
}


