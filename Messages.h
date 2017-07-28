#pragma once
#include <string>
#include <vector>
#include "vmath.h"
#include <SDL2/SDL.h>
#include<iostream>
#include"TileMap.h"
enum class MSGTYPE {Failed ,Physics , Animation , Collision };
enum class OBJTYPE {Failed, Sprite, CollisionSystem, GameOBJ };

class ID {
public:
    ID();
    ~ID();
    ID(int idnumber, OBJTYPE type): m_IDNumber{idnumber}, m_IDType{type}
    {
	}


    ID* getIDref();
    ID getID();
    bool matchMyID(ID target);

    bool checkIDmatch(ID target, ID comparison);
    bool checkIDmatch(ID* target, ID* comparison);
	
	int m_IDNumber;
	OBJTYPE m_IDType;
};

class msg{
public:
    msg(){}
    virtual~msg(){}
//    msg(int target){m_targetid = target;}
    virtual void update(void * Variables)=0;
	ID m_TargetID;
	ID m_SenderID;
    MSGTYPE m_type;

};

class PhysicsMSG : public msg {
	public:
	
	PhysicsMSG();
    ~PhysicsMSG();
    PhysicsMSG( Vec2DF velocity , float dt,  ID target, ID Sender  );
    PhysicsMSG(PhysicsMSG& Copy);
    void update (void* Variables);
    Vec2DF m_VecPayload;

	float m_DeltaTime;
	

};

class AnimationMSG : public msg{

public:

    AnimationMSG(){}
    ~AnimationMSG(){}
    AnimationMSG(int curTile, int AnimateFrames, state desiredState , ID target, ID Sender );
    AnimationMSG(AnimationMSG& Copy);
    void update(void* Variables);
    int m_curFrameSet;
    int m_AnimationFramesSet;
    state m_state;


};


//class SpriteMSG :public msg {
    //repurpose this for getting position to collision system;
//	public:

//		SpriteMSG();
//		~SpriteMSG();
//		SpriteMSG(Vec2DF payl, int target );
//        void update(void* Variables);

//        Vec2DF m_payload;


//};

class MSGreciever{

	public:
	MSGreciever();
	MSGreciever(ID identity);
    MSGreciever(const MSGreciever& Copy);
    MSGreciever& operator=(const MSGreciever Copy );
	~MSGreciever();
    bool handleMSG(void *passedvar);

    void getMSGS(msg* message );
    MSGTYPE peakatMSGS();
	void CheckForGarbage();

	private:

    std::vector <msg*> que;
    ID SentTo;

};

class MSGdispatcher {

	public:
	MSGdispatcher();
    MSGdispatcher( MSGreciever * FirstTarget );
    MSGdispatcher(const MSGdispatcher& copy);
	~MSGdispatcher();
//	void sendMSG(msg Message);
    void registerMSGER (MSGreciever* listener );
    void sendMSG(msg* Message);
    private:
    std::vector<MSGreciever*> m_Listeners;
};


class CollisionMSG : msg {
public:
	CollisionMSG() {}
	~CollisionMSG() {}
	// what else does a collision message want to get across
	//
	CollisionMSG( int id) {
		m_TargetID = ID( id , OBJTYPE::CollisionSystem);
		m_type = MSGTYPE::Collision;
	}
    void update(void* Variables) {
	
	}
private:
	ID m_CollidedObject; // takes an id


};
