#pragma once
#include "Component.h"

class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the Buzzer
	virtual void Edit(UI*);
	virtual void CopyComp();
	
	virtual void PasteComp();
	virtual void SaveComponent(ofstream& file);
	virtual void LoadComponent(string labell, int valuee, int idd);
};