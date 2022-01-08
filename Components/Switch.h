#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo *r_GfxInfo);
	virtual void Draw(UI*);	//Draws the switch
	virtual void Operate();
	virtual void Edit(UI*);
	virtual void CopyComp();
	
	virtual void PasteComp();
	virtual void SaveComponent(ofstream& file);
	virtual void LoadComponent(string labell, int valuee, int idd);
};
