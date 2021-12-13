#pragma once
#include "Component.h"

class Fuse :public Component
{
	public:
		Fuse(GraphicsInfo* r_GfxInfo);
		virtual void Operate();	//Calculates the volt on both terminals
		virtual void Draw(UI*);	//Draws the fuse
		virtual void Edit(UI*);
		virtual void SaveComponent(fstream& file);
		virtual void LoadComponent(fstream& file, UI* pUI);
};

