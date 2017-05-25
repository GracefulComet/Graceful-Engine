#pragma once
#include <string>
#include <vector>
#include "vmath.h"
#include <SDL2/SDL.h>

enum class MSGTYPE {Physics , Animation };

class msg{
public:
    msg(){}
    virtual~msg(){}
//    msg(int target){m_targetid = target;}
    virtual void update(void * Variables)=0;
    int getTargetID();
    int m_targetid;
    MSGTYPE m_type;

};

class PhysicsMSG : public msg {
	public:
	
	PhysicsMSG();
	~PhysicsMSG();	
    PhysicsMSG( Vector velocity , float dt, int ID   );
	void update (void* Variables);
	Vector m_VecPayload;

	float m_DeltaTime;
	

};

class SpriteMSG :public msg {

	public:

		SpriteMSG();
		~SpriteMSG();
		SpriteMSG(Vector payl, int target );
        void update(void* Variables);

        Vector m_payload;


};

class MSGreciever{

	public:
	MSGreciever();
	MSGreciever(int ID);
	~MSGreciever();
    void handleMSG(void *passedvar);

    void getMSGS(msg* message );
	private:

    std::vector <msg*> que;
    int id;

};

class MSGdispatcher {

	public:
	MSGdispatcher();
        MSGdispatcher( MSGreciever * FirstTarget );
	~MSGdispatcher();
//	void sendMSG(msg Message);
	void registerMSGER (MSGreciever* listener );
    void sendMSG(msg* Message);
	private:


	std::vector<MSGreciever*> m_Listeners;
};


