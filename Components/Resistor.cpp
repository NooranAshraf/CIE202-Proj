#include "Resistor.h"
#include <string.h>

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, selected); //update to draw resistor

}

void Resistor::Edit(UI* pUI) {
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
void Resistor::SaveComponent(ofstream& file) {

	file << "RES" << " " << to_string(id) << " " << getLabel() + " " << to_string(resistance) << " " << to_string(m_pGfxInfo->PointsList[0].x) << " " << to_string(m_pGfxInfo->PointsList[0].y) << "\n";
}
void Resistor::LoadComponent(string labell, int valuee, int idd) {
	setLabel(labell);
	this->value = valuee;
	id = idd;

	/*string text;
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
	m_pGfxInfo->PointsList[1].y = m_pGfxInfo->PointsList[0].x + pUI->getCompHeight();*/
}
void Resistor::CopyComp() {
	CopiedValue = value;
	CopiedLabel = getLabel();
	string Type = "RES";
}

void Resistor::PasteComp() {
	setLabel(CopiedLabel);
	setValue(CopiedValue);
}
void Resistor::Operate()
{

}