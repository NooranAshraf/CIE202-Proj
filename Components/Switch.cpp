#include "Switch.h"

Switch::Switch(GraphicsInfo *r_GfxInfo) :Component(r_GfxInfo)
{
	
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass switch drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, selected); //update to draw switch

}

void Switch::Operate()
{

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
}

//bool Switch::Switched(int i) {
//	if (i == 0) 
//	{
//		return true;
//	}
//	else if (i == 1)
//	{
//		return false;
//	}
//}
