#pragma once
#include "Component.h"

class Module :public Component
{

	
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Edit(UI*);

	virtual void PasteComp();
	virtual void CopyComp();
	virtual void SaveComponent(ofstream& file);
	virtual void LoadComponent(string labell, int valuee, int idd);
    double Req;

	
};