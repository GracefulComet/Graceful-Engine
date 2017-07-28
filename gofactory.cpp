//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "gofactory.h"

// TODO: Add other Object Types. types to do , Terrain, UI and Forground

GOfactory::GOfactory() {m_IDKeys = 0;
}

GOfactory::~GOfactory(){
    for(unsigned int i; i < m_Entities.size();i ++){
        delete m_Entities[i];
    }
    m_Entities.clear();
}

void GOfactory::addGFX(Sprite graphic){ Gfx.push_back(graphic);  }

void GOfactory::updateGFX(float deltaT){ 
	
	for (unsigned int i =0; i < Gfx.size();i++ ){
    Gfx[i].update(deltaT );
	}


}

void GOfactory::drawGFX(SDL_Renderer * pRender){

	
	for ( unsigned int  i =0; i < Gfx.size(); i++ )
	{Gfx[i].draw(pRender);}

}

void GOfactory::updateCollision()
{
	m_Collider.detectAll();
}

void GOfactory::addBehaviour(Behaviour* Addee){
m_Entities.push_back(Addee);
}
void GOfactory::updateBehaviour(){ 
	if (m_Entities.empty() == true ){
	}
	else{
    for (unsigned int i =0; i < m_Entities.size(); i++){
    m_Entities[i]->update();
		}
	}
}
//
//todo add set position into the variables you want to set
void GOfactory::addPlayer(std::string filetoSprite, SDL_Event* evt, SDL_Renderer* render, Vec2DF pos){
m_IDKeys++;
Sprite temp(filetoSprite, render, state::animated,m_IDKeys );
temp.SetPos(pos.x,pos.y);
addGFX (temp);


for ( unsigned int i=0; i < Gfx.size();i++  ) {
	if (Gfx[i].getID() == m_IDKeys) {

        addBehaviour(new PlayerCtrl(Gfx[i].getListener(), evt, m_IDKeys));
		SDL_Rect tempbox;
		tempbox.x = Gfx[i].getPosition()->x;
		tempbox.y = Gfx[i].getPosition()->y;
		tempbox.h = Gfx[i].getTiles()->getH();
		tempbox.w = Gfx[i].getTiles()->getW();

//		m_Collider.addObjToTrack(CollisionData(Gfx[i].getID(), tempbox));
//		m_Collider.addListener(Gfx[i].getListener());
//	for (unsigned int j = 0; j < m_Entities.size(); j++) {
//		if (m_Entities[j]->m_Mine.m_IDNumber = m_IDKeys) {
//			m_Collider.addListener(m_Entities[i]->getlistener());
//		}
//	}


	}
    
}



}




