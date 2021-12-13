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
	 value = -1;
}
void Ground::SaveComponent(fstream& file) {
	file << "GND" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Ground::LoadComponent(fstream& file, UI* pUI) {
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

void Ground::Operate()
{

}