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

    PlayerCtrl(MSGreciever * firstListener,SDL_Event* Evnt,int ID ){
	id = ID;	
	msger = MSGdispatcher(firstListener);
    event =  Evnt;
    }

   PlayerCtrl( PlayerCtrl &mycopy ){

       this->id = mycopy.id;
       this->msger = mycopy.msger;
       this->event = mycopy.event;
    }
   PlayerCtrl* getPtr(){
   return this;

   }

	~PlayerCtrl(){ }

	void update(){

    SDL_PollEvent(event);
    if(event->type == SDL_KEYDOWN ){
    switch(event->key.keysym.sym){

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

    }else{
        if(event->type = SDL_KEYUP){
            switch(event->key.keysym.sym){

            case SDLK_LEFT:
                Movement = Move::Idle;
                break;
            case SDLK_RIGHT:
                Movement = Move::Idle;
                break;

            case SDLK_UP:
                Movement = Move::Idle;
                break;
            case SDLK_DOWN:
                Movement = Move::Idle;
                break;

            default:
                    Movement = Move::Idle;
                break;
                }
            }
    }

	switch ( Movement ){
		{case Move::Left :
         Velocity = Vector(-0.8f, 0.0f,0.0f) ;
        myMessage = new SpriteMSG(Velocity ,id );
        msger.sendMSG(myMessage);


		break;}

		{case Move::Right:
     Velocity = Vector(0.8f, 0.0f,0.0f) ;
        myMessage = new SpriteMSG(Velocity ,id );
        msger.sendMSG(myMessage);

			
			break;}

		{	case Move::Up:
     Velocity = Vector  (0.0f,- 0.8f,0.0f) ;
        myMessage = new SpriteMSG(Velocity ,id );
        msger.sendMSG(myMessage);

				break;}
		{case Move::Down:
     Velocity = Vector  (0.0f,0.8f,0.0f) ;
        myMessage = new  SpriteMSG(Velocity ,id);
        msger.sendMSG(myMessage);

	
		break;}
		{	case Move::Idle :
	Velocity = Vector(0.0 , 0.0, 0.0);	
    myMessage = new SpriteMSG(Velocity, id);
        msger.sendMSG(myMessage);

			break;}
	default :
		Movement = Move::Idle;
		break;
	}

}
	private:
	Move Movement;
 	MSGdispatcher msger;
    msg* myMessage;
 	Vector Velocity; 
    SDL_Event* event;

};
