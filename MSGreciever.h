#pragma once

#include "Messages.h"

class MSGreciever
{

public:
	MSGreciever() = default;
	MSGreciever( ID identity );

	bool handleMSG( void *passedvar );
	void handleMSGS( void *passedvar );
	//void getMSGS( std::shared_ptr<msg> message );
	void getMSGS( std::unique_ptr<msg> &&message );
	MSGTYPE peakatMSGS( );
	void CheckForGarbage();

public:
	//std::vector<std::shared_ptr<msg>> que;
	std::vector<std::unique_ptr<msg>> que;
	ID SentTo;
};
