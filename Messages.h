#pragma once
#include <string>
#include <vector>
#include "vmath.h"



class SpriteMSG  {

	public:

		SpriteMSG();
		~SpriteMSG();
		SpriteMSG(Vector payl, int target );
		void update(Vector* updatedValue);
		int getTargetID();
	private:
	
	Vector m_payload;
	int m_targetid;

};

class MSGreciever{

	public:
	MSGreciever();
	MSGreciever(int ID);
	~MSGreciever();
	void handleMSG(Vector* p_vec );

	void getMSGS(SpriteMSG* message );
	private:

	std::vector <SpriteMSG*> que;
	int id;

};

class MSGdispatcher {

	public:
	MSGdispatcher();
        MSGdispatcher( MSGreciever * FirstTarget );
	~MSGdispatcher();
//	void sendMSG(msg Message);
	void registerMSGER (MSGreciever* listener );
	void sendMSG(SpriteMSG* Message);
	private:


	std::vector<MSGreciever*> m_Listeners;
};


