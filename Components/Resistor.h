#pragma once
#include "Component.h"
#include <fstream>

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo *r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Edit(UI*);
	virtual void CopyComp();

	virtual void PasteComp();
	virtual void SaveComponent(ofstream& file);
	virtual void LoadComponent(string labell, int valuee, int idd);
};
