#include "Messages.h"


ID::ID(){}

ID::~ID(){}

bool ID::matchMyID(ID target) {
    if (this->m_IDNumber == target.m_IDNumber) {
        if (this->m_IDType == target.m_IDType) {
            return true;

        }
    }
    else { return false; }

}
ID* ID::getIDref() { return this; }
ID ID::getID(){return *this;}

bool ID::checkIDmatch(ID target, ID comparison) {

    if (target.m_IDNumber == comparison.m_IDNumber) {
        if (target.m_IDType == comparison.m_IDType) {

            return true;
        }
    }
    else { return false; }
}

bool ID::checkIDmatch(ID* target, ID* comparison) {

    if (target->m_IDNumber == comparison->m_IDNumber) {
        if (target->m_IDType == comparison->m_IDType) {

            return true;
        }
    }
}


PhysicsMSG::PhysicsMSG(){

}


PhysicsMSG::~PhysicsMSG(){

}

PhysicsMSG::PhysicsMSG(Vec2DF velocity, float dt, ID target, ID Sender ){

	m_VecPayload = velocity;
	m_type = MSGTYPE::Physics;
    m_TargetID = target;
	m_SenderID = Sender;
	m_DeltaTime = dt;	

}

PhysicsMSG::PhysicsMSG(PhysicsMSG & Copy)
{
    this->m_VecPayload = Copy.m_VecPayload;
    this->m_type = Copy.m_type;
    this->m_TargetID = Copy.m_TargetID;
    this->m_SenderID = Copy.m_SenderID;
    this->m_DeltaTime = Copy.m_DeltaTime;
}

void PhysicsMSG::update( void* Variables ){
    if((Variables) == nullptr){
    std::cout << " Got Null" <<std::endl;
    }else{

    ((Vec2DF* )Variables )->x = m_VecPayload.Approach(m_VecPayload.x,((Vec2DF*)Variables)->x, ( m_DeltaTime  * 0.15f) );
    ((Vec2DF* )Variables )->y = m_VecPayload.Approach(m_VecPayload.y,((Vec2DF*)Variables)->y, ( m_DeltaTime ) * 0.15f);
  ((Vec2DF*)Variables)->operator+= (m_VecPayload *= 0.15f );
    }
}


AnimationMSG::AnimationMSG(int curTile, int AnimateFrames , state desiredState, ID target, ID Sender ){
    m_type = MSGTYPE::Animation;
    m_curFrameSet = curTile;
    m_AnimationFramesSet = AnimateFrames;
    m_TargetID = target;
	m_SenderID = Sender;
    m_state = desiredState;
}
//    AnimationMSG::AnimationMSG(AnimationMSG& Copy){
//
//      this->m_type = Copy.m_type;
//      this->m_curFrameSet = Copy.m_curFrameSet;
//      this->m_AnimationFramesSet = Copy.m_AnimationFramesSet;
//      this->m_TargetID = Copy.m_TargetID;
//      this->m_SenderID = Copy.m_SenderID;
//      this->m_state = Copy.m_state;
//    }


void  AnimationMSG::update(void* Variables){
    if((Variables) == nullptr){
    std::cout << " Got Null" <<std::endl;
    }else{

    ((TileMap*)Variables)->setCurTile(m_curFrameSet);
    ((TileMap*)Variables)->setNumAnimFrames(m_AnimationFramesSet);
    ((TileMap*)Variables)->setState(m_state);

    }

}


MSGdispatcher::MSGdispatcher(){
        std::cout << "MsgDispatcher default c'stor"<<std::endl;

}
MSGdispatcher::MSGdispatcher( MSGreciever * FirstTarget )
//    :
{

    std::cout << "MsgDispatcher custom c'stor"<<std::endl;
	registerMSGER(FirstTarget);

}
MSGdispatcher::~MSGdispatcher(){
    std::cout << "MsgDispatcher destroyed"<<std::endl;
    if (m_Listeners.empty() == false){
    m_Listeners.clear();
    }
}

MSGdispatcher::MSGdispatcher(const MSGdispatcher& copy){
    std::cout << "MsgDispatcher copied"<<std::endl;

    this->m_Listeners.reserve((copy.m_Listeners.size()));
    for(unsigned int i =0; i < copy.m_Listeners.size(); i ++){
        if(copy.m_Listeners[i] !=  nullptr ){
    this->m_Listeners.push_back(copy.m_Listeners[i]);
        }
    }
}

MSGreciever::MSGreciever():SentTo{ID(0,OBJTYPE::Failed)}
{}
MSGreciever::MSGreciever(ID Owner ): SentTo{Owner}
{


}
MSGreciever::~MSGreciever(){

    if(que.empty() == false){
    for(unsigned int i=0;i < que.size();i ++ ){
        delete que[i];
    }
    que.clear();
    }
    que.clear();
}
//MSGreciever::MSGreciever (const MSGreciever& Copy ){

//    this->SentTo = Copy.SentTo;
//    if(Copy.que.empty() == false){
//        this->que.reserve(Copy.que.size());
//        for(unsigned int i = 0; i < Copy.que.size();i++){


//        }

//    }

//}

//MSGreciever& operator=( const MSGreciever& Copy ){return *this;}

void MSGdispatcher::sendMSG(msg* Message){

    for (unsigned int i = 0; i < m_Listeners.size() ; i++){
    m_Listeners[i]->getMSGS(Message);

	}

}

void MSGdispatcher::registerMSGER(MSGreciever* listener ){

m_Listeners.push_back(listener);
}

void MSGreciever::getMSGS(msg* message) {


    que.push_back(message);

}

MSGTYPE MSGreciever::peakatMSGS(){

if(que.empty() == false){
   return que.back()->m_type;
          }
}

void MSGreciever::CheckForGarbage()
{
    if (que.back() == nullptr) {
        que.clear();
	}
}



bool MSGreciever::handleMSG(void * passedvar){
	CheckForGarbage();
    if(que.empty() == false){
        if(SentTo.matchMyID( que.back()->m_TargetID.getID()) == true){
           que.back()->update(passedvar);
           delete que.back();
            que.pop_back();
        }

    }
return que.empty();
}
