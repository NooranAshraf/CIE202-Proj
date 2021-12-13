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
void Component::Unselect() {
	selected = false;
}


Component::~Component()
{ 
	delete m_pGfxInfo;
}

