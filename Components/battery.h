#pragma once
#include "Component.h"

class battery :public Component
{
public:
	battery(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the battery
	virtual void Edit(UI*);
};

