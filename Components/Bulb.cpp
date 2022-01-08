#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, selected); //update to draw resistor

}

void Bulb::Edit(UI* pUI) {
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
void Bulb::SaveComponent(ofstream& file) {
	file << "BLB" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Bulb::LoadComponent(string labell, int valuee, int idd) {
	setLabel(labell);
	this->value = valuee;
	id = idd;

}
void Bulb::CopyComp() {
	CopiedValue = value;
	CopiedLabel = getLabel();
	string Type = "BLB";
}
void Bulb::PasteComp() {
	setLabel(CopiedLabel);
	setValue(CopiedValue);
}
void Bulb::Operate()
{

}