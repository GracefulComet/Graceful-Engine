#include "ID.h"

ID::ID(int idnumber, OBJTYPE type) : m_IDNumber(idnumber), m_IDType(type) {}

ID::ID(int idnumber, OBJTYPE type, GOTYPE gameObjType) : m_IDNumber(idnumber), m_IDType(type),m_GOdata(gameObjType) {}

bool ID::ptrIDMatch(ID *target) {
  return this->m_IDNumber == target->m_IDNumber &&
         this->m_IDType == target->m_IDType;
}

bool ID::matchMyID(ID target) {
  return m_IDNumber == target.m_IDNumber && m_IDType == target.m_IDType;
}

bool ID::checkIDmatch(ID target, ID comparison) {
  return checkIDmatch(&target, &comparison);
}

bool ID::checkIDmatch(ID *target, ID *comparison) {
  return target->matchMyID(*comparison);
}
