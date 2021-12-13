#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	id = st_id++;

}

void Component::Select() {
	if (selected) {
		selected = false;
	}
	else {
		selected = true;
	}
}
bool Component::available(int x, int y) {
	if (x >= m_pGfxInfo->PointsList[0].x && x <= m_pGfxInfo->PointsList[1].x && y >= m_pGfxInfo->PointsList[0].y && y <= m_pGfxInfo->PointsList[1].y) {
		return true;
	}
	else return false;
}

void Component::setLabel(string label) {
	m_Label = label;
}

string Component::getLabel() const {
	return m_Label;
}

double Component::getResistance() const {
	return resistance;
}
double Component::getVoltage() const {
	return voltage;
}
int Component::getID() const {
	return id;
} //for the save file
Point Component::getCoordinates() const {
	return m_pGfxInfo->PointsList[0];
} //for the save file
double Component::getValue() const {
	return value;
}

void Component::Unselect() {
	selected = false;
}


Component::~Component()
{ 
	delete m_pGfxInfo;
}

