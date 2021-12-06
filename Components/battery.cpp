#include "battery.h"
#include "../UI/UI.h"


battery::battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void battery::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo); //update to draw battery

}

void battery::Operate()
{

}
