#include "Connection.h"
#include "Component.h"

Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
}
void Connection::Draw(UI* pUI)
{    //Pass the connection drawing info to it 
	pUI->DrawConnection(*pGfxInfo);        //update to draw connection
}

Component* Connection::getOtherComponent(Component* Cmpnt)
{
	Cmpnt2 = Cmpnt;
	return Cmpnt2;
}

bool Connection::IsInConn(int x, int y, UI* pUI) {
	int x1, y1, x2, y2;
	x1 = pGfxInfo->PointsList[0].x;
	y1 = pGfxInfo->PointsList[0].y;
	x2 = pGfxInfo->PointsList[1].x;
	y2 = pGfxInfo->PointsList[1].y;
	if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2)) {
		return true;
	}
	else {
		return false;
	}
}

void Connection::setLabel(string label) {
	m_label = label;
}

string Connection::getLabel() {
	return m_label;
}

Component* Connection::getCmpnt1() {
	return Cmpnt1;
}


Component* Connection::getCmpnt2() {

	return Cmpnt2;
}
void Connection::selectConn() {
	if (selected) {
		selected = false;
	}
	else {
		selected = true;
	}
}
void Connection::Unselect() {
	selected = false;
}
void Connection::SaveConnection(ofstream& file) {
	file << Cmpnt1->getID() << " " << Cmpnt2->getID() << "\n";

}
void Connection::LoadConnection(UI* pUI) {
	int x1 = Cmpnt1->getCoordinates().x;
	int x2 = Cmpnt2->getCoordinates().x;
	int y1 = Cmpnt1->getCoordinates().y;
	int y2 = Cmpnt2->getCoordinates().y;
	if (x2 > x1) {
		pGfxInfo->PointsList[1].x = x2;
		pGfxInfo->PointsList[1].y = y2 - pUI->getCompHeight() / 2;
		pGfxInfo->PointsList[0].x = x1 + pUI->getCompWidth();
		pGfxInfo->PointsList[0].y = y1;
	}
}
Connection::~Connection() {
	delete pGfxInfo;
}
