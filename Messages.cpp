#pragma once
#include "Messages.h"

SpriteMSG::SpriteMSG(){}
SpriteMSG::~SpriteMSG(){}
SpriteMSG::SpriteMSG(Vector payl, int target){
m_payload = payl;
m_targetid = target;
}
int SpriteMSG::getTargetID(){return m_targetid;}
void SpriteMSG::update(Vector* updatedValue){

updatedValue->x += m_payload.x;
updatedValue->y += m_payload.y;
updatedValue->z += 0;
}

MSGdispatcher::MSGdispatcher(){}
MSGdispatcher::MSGdispatcher( MSGreciever * FirstTarget ){

	registerMSGER(FirstTarget);

}
MSGdispatcher::~MSGdispatcher(){}

MSGreciever::MSGreciever(){}
MSGreciever::~MSGreciever(){}

void MSGdispatcher::sendMSG(SpriteMSG Message){

	for (unsigned int i = 0; i < m_Listeners.size() ; i++){
	m_Listeners[i]->getMSGS(Message);

	}

}

void MSGdispatcher::registerMSGER(MSGreciever* listener ){

m_Listeners.push_back(listener);
}

void MSGreciever::getMSGS(SpriteMSG message) {


	que.push_back(message);

}

void MSGreciever::handleMSG(Vector* p_vec ){

	for (unsigned int i =0; i < que.size(); i++){
	if( id == que[i].getTargetID())	{
		que[i].update(p_vec);
		}

	}
	for(unsigned int j =0; j < que.size(); j ++){
	

	}

}
