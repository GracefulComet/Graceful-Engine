#pragma once
#include <string>
#include "Messages.h"
#include <iostream>
#include <SDL2/SDL.h>
enum class Move{Left, Right, Up , Down ,Idle };

class Behaviour {

	public:
	Behaviour(){}
	virtual	~Behaviour(){}
	
	virtual void update()=0;


	int id;

};

class PlayerCtrl : public Behaviour
{

 

	
	public:
	PlayerCtrl();

    PlayerCtrl(MSGreciever * firstListener, int ID ){
	id = ID;	
	msger = MSGdispatcher(firstListener);
    }

   PlayerCtrl( PlayerCtrl &mycopy ){

       this->id = mycopy.id;
       this->msger = mycopy.msger;
    }
   PlayerCtrl* getPtr(){
   return this;

   }

	~PlayerCtrl(){ }

	void update(){
	
    if(SDL_PollEvent(&event)){
	if(event.type == SDL_KEYDOWN ){	
	switch(event.key.keysym.sym){

		case SDLK_LEFT:
			Movement = Move::Left;
			break;
		case SDLK_RIGHT:
			Movement = Move::Right;
			break;

		case SDLK_UP:
			Movement = Move::Up;
			break;
		case SDLK_DOWN:
			Movement = Move::Down;
			break;



		default:
		       	Movement = Move::Idle;
			break;

		}
	}
	}
	switch ( Movement ){
		{case Move::Left :
		 Velocity = Vector(-5.0f, 0.0f,0.0f) ;	
		myMessage = SpriteMSG(Velocity ,id );
		msger.sendMSG(new SpriteMSG(myMessage));


		break;}

		{case Move::Right:
	 Velocity = Vector(5.0f, 0.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,id );	
		msger.sendMSG(new SpriteMSG(myMessage));

			
			break;}

		{	case Move::Up:
	 Velocity = Vector  (0.0f, 5.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,id );	
		msger.sendMSG(new SpriteMSG(myMessage));

				break;}
		{case Move::Down:
	 Velocity = Vector  (0.0f,-5.0f,0.0f) ;	
		myMessage =  SpriteMSG(Velocity ,id);	
		msger.sendMSG(new SpriteMSG(myMessage));

	
		break;}
		{	case Move::Idle :
	Velocity = Vector(0.0 , 0.0, 0.0);	
	myMessage = SpriteMSG(Velocity, id);
		msger.sendMSG(new SpriteMSG(myMessage));

			break;}
	default :
		Movement = Move::Idle;
		break;
	}
if(event.type = SDL_KEYUP){
        Movement == Move::Idle;
        }
}
	private:
	Move Movement;
 	MSGdispatcher msger;
	SpriteMSG myMessage;
 	Vector Velocity; 
	SDL_Event event;

};
