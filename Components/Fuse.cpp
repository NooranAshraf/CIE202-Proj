#include "Fuse.h"
#include "../UI/UI.h"
Fuse::Fuse(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, selected); //update to draw battery

}

void Fuse::Edit(UI* pUI) {
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
void Fuse::SaveComponent(fstream& file) {
	file << "FUSE" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Fuse::LoadComponent(fstream& file, UI* pUI) {
	string text;
	getline(file, text, ' ');
	id = stoi(text);
	getline(file, text, ' ');
	setLabel(text);
	getline(file, text, ' ');
	resistance = stod(text);
	getline(file, text, ' ');
	m_pGfxInfo->PointsList[0].x = stoi(text);
	getline(file, text);
	m_pGfxInfo->PointsList[0].y = stoi(text);
	m_pGfxInfo->PointsList[1].x = m_pGfxInfo->PointsList[0].x + pUI->getCompWidth();
	m_pGfxInfo->PointsList[1].y = m_pGfxInfo->PointsList[0].x + pUI->getCompHeight();
}
void Fuse::Operate()
{

}
