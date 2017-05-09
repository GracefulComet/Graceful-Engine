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
((Vector*)Variables)->operator +=(m_payload);
//updatedValue->operator +=(m_payload)  ;
//m_payload.Approach(updatedValue->x ,updatedValue->y, updatedValue->z);
}
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
