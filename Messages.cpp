#include "Messages.h"

SpriteMSG::SpriteMSG(){}
SpriteMSG::~SpriteMSG(){}
SpriteMSG::SpriteMSG(Vector payl, int target){
m_payload = payl;
m_targetid = target;
}
int msg::getTargetID(){return m_targetid;}
void SpriteMSG::update(void* Variables){
if((Variables) == nullptr){

}else{



((Vector*)Variables)->x = m_payload.Approach(m_payload.x , ((Vector*)Variables)->x , (0.00006f * 60.0f ));
((Vector*)Variables)->y = m_payload.Approach(m_payload.y , ((Vector*)Variables)->y , (0.00006f * 60.0f ));
((Vector*)Variables)->operator +=(m_payload *= (0.00006f * 60.0f ) );
}
}


PhysicsMSG::PhysicsMSG(){

}

PhysicsMSG::~PhysicsMSG(){

}

PhysicsMSG::PhysicsMSG(Vector velocity, float dt,int ID ){

	m_VecPayload = velocity;
	m_type = MSGTYPE::Physics;
    m_targetid = ID;
	m_DeltaTime = dt;	

}

void PhysicsMSG::update( void* Variables ){


    ((Vector* )Variables )->x = m_VecPayload.Approach(m_VecPayload.x,((Vector*)Variables)->x, ( m_DeltaTime  * 0.15f) );
    ((Vector* )Variables )->y = m_VecPayload.Approach(m_VecPayload.y,((Vector*)Variables)->y, ( m_DeltaTime ) * 0.15f);
  ((Vector*)Variables)->operator+= (m_VecPayload *= 0.15f );
}

MSGdispatcher::MSGdispatcher(){}
MSGdispatcher::MSGdispatcher( MSGreciever * FirstTarget ){

	registerMSGER(FirstTarget);

}
MSGdispatcher::~MSGdispatcher(){}

MSGreciever::MSGreciever(){}
MSGreciever::MSGreciever(int ID){id = ID; }
MSGreciever::~MSGreciever(){}

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

void MSGreciever::handleMSG(void * passedvar){

	for (unsigned int i =0; i < que.size(); i++){
	if( id == que[i]->getTargetID())	{
        que[i]->update(passedvar);
		}
	}
    if ( que.empty() == false){
    que.pop_back();
    }
}
