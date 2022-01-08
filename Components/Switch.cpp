#include "Switch.h"

Switch::Switch(GraphicsInfo *r_GfxInfo) :Component(r_GfxInfo)
{
	
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass switch drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, selected); //update to draw switch

}

void Switch::Edit(UI* pUI) {
	pUI->PrintMsg("Enter L to edit the label or r to edit the resistance");
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
void Switch::SaveComponent(ofstream& file) {
	file << "SWT" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Switch::LoadComponent(string labell, int valuee, int idd) {
	setLabel(labell);
	this->value = valuee;
	id = idd;
}
void Switch::CopyComp() {
	CopiedValue = value;
	CopiedLabel = getLabel();
	string Type = "SWT";
}
void Switch::PasteComp() {
	setLabel(CopiedLabel);
	setValue(CopiedValue);
}

void Switch::Operate()
{

}


