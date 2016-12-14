//
//Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
//Please Add your name befor you commit   :)
//Contributers::
//
//
//
//
#include<SDL2/SDL.h>

class TimerF
{
	public:
	
	TimerF(){
	m_ready = false;
	m_prevTime = 0.0f;
	m_currTime = 0.0f;
	m_deltaTime =0.0f;	
       	}	
	bool cooldown(float duration);
	void reset();	


	private:

	bool m_ready;
	float m_prevTime; 
  	float m_currTime;
	float m_deltaTime;

};
