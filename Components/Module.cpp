#include "Module.h"

Module::Module(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{

}

void Module::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawModule(*m_pGfxInfo, selected); //update to draw resistor

}

void Module::Edit(UI* pUI) {
	pUI->PrintMsg("Enter L to edit the label");
	string EditX;
	EditX = pUI->GetSrting();
	if (EditX == "L" || EditX == "l") {
		pUI->PrintMsg("Enter a new Label");
		setLabel(pUI->GetSrting());
	}
	else {
		pUI->PrintMsg("Not valid");
	}
	value = -1;
}
void Module::SaveComponent(ofstream& file) {
	file << "RES" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Module::LoadComponent(string labell, int valuee, int idd){
	//same here
}
void Module::CopyComp() {
	CopiedValue = value;
	CopiedLabel = getLabel();
	string Type = "MODULE";
}

void Module::PasteComp() {
	setLabel(CopiedLabel);
	setValue(CopiedValue);
}

void Module::Operate()
{

}