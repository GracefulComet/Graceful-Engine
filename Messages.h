#pragma once

#include "ID.h"
#include <memory>
#include <vector>

class msg
{
public:
	msg() = default;
	virtual~msg() = default;
	msg( ID target, ID sender, MSGTYPE Type );

	virtual void update( void * Variables ) = 0;

	ID getTargetID();
	ID getSenderID();

public:
	ID m_TargetID;
	ID m_SenderID;
	MSGTYPE m_type;
};



//repurpose this for getting position to collision system;
/*class SpriteMSG :public msg
{
public:
	SpriteMSG();
	~SpriteMSG();
	SpriteMSG( Vec2DF payl, int target );
	void update( void* Variables );

public:
	Vec2DF m_payload;
};*/




