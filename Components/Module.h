#pragma once
#include "Component.h"

class Module :public Component
{

	
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Operate();
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Edit(UI*);
	virtual void SaveComponent(fstream& file);
	virtual void LoadComponent(fstream& file, UI* pUI);
    double Req;
};