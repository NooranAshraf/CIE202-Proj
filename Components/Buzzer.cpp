
#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass buzzer drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, selected); //update to draw the buzzer

}

void Buzzer::Edit(UI* pUI) {
	pUI->PrintMsg("Enter L to edit the label or R to edit the resistance");
	string EditX;
	EditX = pUI->GetSrting();
	if (EditX == "R" || EditX == "r") {
		pUI->PrintMsg("Enter a new value for the resistance");
		resistance = stod(pUI->GetSrting());
	}
	else if (EditX == "L" || EditX == "l") {
		pUI->PrintMsg("Enter a new Label");
		setLabel(pUI->GetSrting());
	}
	else {
		pUI->PrintMsg("Not valid");
	}
}

void Buzzer::Operate()
{

}