#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo *r_GfxInfo);
	virtual void Draw(UI*);	//Draws the switch
	virtual void Operate();
	virtual void Edit(UI*);
};
