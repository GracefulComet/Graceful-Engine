#pragma once
#include <string>
#include "Messages.h"

#include <SDL2/SDL.h>
enum class Move{Left, Right, Up , Down ,Idle };

class Behaviour {

	public:
	Behaviour();
	~Behaviour(){}
	
	virtual bool update();

	private:
	int id;

};

class PlayerCtrl : public Behaviour
{

 

	
	public:
	PlayerCtrl();
	~PlayerCtrl(){ }

	bool update(){

//		switch(){}
	
	switch ( Movement ){
	case Move::Left :
		 Velocity = Vector(-5.0f, 0.0f,0.0f) ;	
		myMessage = SpriteMSG(Velocity ,1 );	
		msger.sendMSG(this->myMessage);
		break;

	case Move::Right:
	 Velocity = Vector(-5.0f, 0.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,1 );	
		break;

	case Move::Up:
	 Velocity = Vector  (-5.0f, 0.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,1 );	
		break;
	case Move::Down:
	 Velocity = Vector  (-5.0f, 0.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,1 );	
		break;
	case Move::Idle :
	Velocity = Vector(0.0 , 0.0, 0.0);	
		break;
	default :
		Movement = Move::Idle;
		break;
	}

	}
	private:
	Move Movement;
 	MSGdispatcher msger;
	SpriteMSG myMessage;
 	Vector Velocity; 
};
