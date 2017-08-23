#include "Messages.h"

msg::msg(ID target, ID sender, MSGTYPE Type)
    : m_TargetID(target), m_SenderID(sender), m_type(Type) {}

ID msg::getTargetID() { return m_TargetID; }

ID msg::getSenderID() { return m_SenderID; }
