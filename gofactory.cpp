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

void GOfactory::addGFX(Sprite graphic){ Gfx.push_back(graphic);  }

void GOfactory::updateGFX(float deltaT){ 
	
	for (unsigned int i =0; i < Gfx.size();i++ ){
	Gfx[i].update(deltaT , 7 );
	}


}

void GOfactory::drawGFX(SDL_Renderer * pRender){

	
	for ( unsigned int  i =0; i < Gfx.size(); i++ )
	{Gfx[i].draw(pRender);}

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

void GOfactory::addPlayer(std::string filetoSprite, SDL_Renderer* render ){
m_IDKeys++;
Sprite temp(filetoSprite, render, state::animated,m_IDKeys );
addGFX (temp);
for ( unsigned int i=0; i < Gfx.size();i++  ) {
if (Gfx[i].getID() == m_IDKeys ){

addBehaviour(new PlayerCtrl(Gfx[i].getListener(),m_IDKeys ));
Gfx[i].SetPos(0.0f , 0.0f);

    }
}



}




