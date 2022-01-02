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
void Module::SaveComponent(fstream& file) {
	//IDK how if should be saved or if it should be - will contact yasmeen -
}
void Module::LoadComponent(fstream& file, UI* pUI) {
	//same here
}

void Module::Operate()
{

}