#pragma once
#include <vector>
#include "SDL2/SDL.h"
enum class MSG_Type{ Input , Player };
enum class MSGER_Type{ Players , Collision , Input};

class msg
{

public:
	msg( )
	{
       	}
	
	~msg ()
	{ 
	}

protected :

	//float Time;
	char* sender;
	char* sent_to;
	
	


	 	
};

class IO_msg : msg
{
enum class Dpad{ NOBUTTON, Lp, Rp , Up ,Dp ,Lr ,Rr ,Ur ,Dr };

public:

void update();

private:

};


class msg_disp 

{

public :



protected :

//vector	<msg> Queue;


};
























