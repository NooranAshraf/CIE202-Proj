#include "battery.h"
#include "../UI/UI.h"

battery::battery(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void battery::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, selected); //update to draw battery

}

void battery::Edit(UI* pUI) {
	pUI->PrintMsg("Enter L to edit the label or V to edit the voltage");
	string EditX; 
	EditX = pUI->GetSrting();
	if (EditX == "V" || EditX == "v") {
		pUI->PrintMsg("Enter a new value for the voltage");
		voltage = stod(pUI->GetSrting());
	}
	else if (EditX == "L" || EditX == "l") {
		pUI->PrintMsg("Enter a new Label");
		setLabel(pUI->GetSrting());
	}
	else {
		pUI->PrintMsg("Not valid");
	}
	value = voltage;
}
void battery::SaveComponent(fstream& file) {
	file << "BAT" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void battery::LoadComponent(fstream& file, UI* pUI) {
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

void battery::Operate()
{

}
