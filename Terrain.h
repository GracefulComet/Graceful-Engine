#pragma once
#include "Behaviour.h"
class Terrain : public Behaviour
{

public:
	Terrain() = default;
	
	void update()override;

};
