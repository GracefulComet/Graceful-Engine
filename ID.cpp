#include "ID.h"

ID::ID( int idnumber, OBJTYPE type )
	:
	m_IDNumber( idnumber ),
	m_IDType( type )
{}

bool ID::matchMyID( ID target )
{
	return
		m_IDNumber == target.m_IDNumber &&
		m_IDType == target.m_IDType;
}

bool ID::checkIDmatch( ID target, ID comparison )
{
	return checkIDmatch( &target, &comparison );
}

bool ID::checkIDmatch( ID * target, ID * comparison )
{
	return target->matchMyID( *comparison );
}