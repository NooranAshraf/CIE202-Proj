
#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0;
	sourceVoltage = 0;
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass buzzer drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo); //update to draw the buzzer

}

void Buzzer::Operate()
{

}