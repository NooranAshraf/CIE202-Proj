
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
	value = resistance;
}
void Buzzer::SaveComponent(ofstream& file) {
	file << "BUZ" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Buzzer::LoadComponent(string labell, int valuee, int idd) {
	setLabel(labell);
	this->value = valuee;
	id = idd;
}
void Buzzer::CopyComp() {
	CopiedValue = value;
	CopiedLabel = getLabel();
	string Type = "BUZ";
}

void Buzzer::PasteComp() {
	setLabel(CopiedLabel);
	setValue(CopiedValue);
}
void Buzzer::Operate()
{

}