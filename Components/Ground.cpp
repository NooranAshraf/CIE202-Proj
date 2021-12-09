#include "Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, selected); //update to draw resistor

}

void Ground::Edit(UI* pUI) {
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
}

void Ground::Operate()
{

}