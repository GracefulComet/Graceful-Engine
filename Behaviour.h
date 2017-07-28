#pragma once
#include <string>
#include "Messages.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Timer.h"

enum class Move{Left, Right, Up , Down ,Idle };

class Behaviour {

	public:
	Behaviour(){}
	virtual	~Behaviour(){}
	
	virtual void update()=0;

    ID m_Mine;
    ID m_Target;

};

class PlayerCtrl : public Behaviour
{

 

	
	public:
	PlayerCtrl();

    PlayerCtrl(MSGreciever * firstListener,SDL_Event* Evnt,int idnum  ){
        m_Mine = ID(idnum, OBJTYPE::GameOBJ);
        m_Target = ID(idnum, OBJTYPE::Sprite);
    msger = MSGdispatcher();
    msger.registerMSGER(firstListener);
    event =  Evnt;

    Movement = Move::Idle;
    }

   PlayerCtrl( PlayerCtrl &mycopy ){

       this->m_Mine = mycopy.m_Mine;
       this->m_Target = mycopy.m_Target;
       this->msger = mycopy.msger;
       this->event = mycopy.event;
    }
   PlayerCtrl* getPtr(){
   return this;

   }

	~PlayerCtrl(){ }

    void update(){



	LastMovement = Movement;

    if(m_time.cooldown(60.0f) == true ){
	m_time.reset();	
	}


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
		

		}

    }else{
        if(event->type == SDL_KEYUP){
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
               
                }
            }
    }

	switch ( Movement ){
		{case Move::Left :

       Velocity += Vec2DF(-0.25f, 0.0f) ;
        msger.sendMSG(new PhysicsMSG(Velocity,m_time.getDelta(),m_Target,m_Mine ));
        msger.sendMSG(new AnimationMSG( 15, 3, state::animated , m_Target,m_Mine ));

		break;}

		{case Move::Right:
 	   	
        Velocity += Vec2DF(0.25f, 0.0f) ;
        msger.sendMSG(new PhysicsMSG(Velocity,m_time.getDelta(),m_Target,m_Mine ));
        msger.sendMSG(new AnimationMSG( 27, 3, state::animated ,m_Target,m_Mine  ));
			
			break;}

		{	case Move::Up:

        Velocity  += Vec2DF  (0.0f,- 0.25f) ;
        msger.sendMSG(new PhysicsMSG(Velocity,m_time.getDelta(),m_Target,m_Mine ));
        msger.sendMSG( new AnimationMSG( 39, 3, state::animated , m_Target,m_Mine  ));

            break;}
		{case Move::Down:

        Velocity += Vec2DF  (0.0f,0.25f) ;
        msger.sendMSG(new PhysicsMSG(Velocity,m_time.getDelta(),m_Target,m_Mine ));
        msger.sendMSG(new AnimationMSG( 3, 3, state::animated , m_Target,m_Mine ));
	
		break;}
		{	case Move::Idle :

    Velocity = Vec2DF(0.0 , 0.0);
    msger.sendMSG(new PhysicsMSG(Velocity,m_time.getDelta(),m_Target,m_Mine ));

            break;}
	default :
		Movement = Move::Idle;
	
	}
	
	



}
	private:
	Move Movement;
	Move LastMovement;
 	MSGdispatcher msger;

    Vec2DF Velocity;
    SDL_Event* event;
	TimerF m_time;

	
};
