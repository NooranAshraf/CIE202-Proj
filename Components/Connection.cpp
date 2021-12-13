#include "Connection.h"
#include "Component.h"

Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
}
void Connection::Draw(UI* pUI)
{    //Pass the connection drawing info to it 
	pUI->DrawConnection(*pGfxInfo);        //update to draw connection
}

Component* Connection::getOtherComponent(Component* Cmpnt)
{
	Comp2= Cmpnt;
	return Comp2;
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

Component* Connection::getComp1() {
		return Comp1;
	}


Component* Connection::getComp2(){
	
		return Comp2;
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
void Connection::SaveConnection(fstream& file) {
	file << Comp1->getID() << " " << Comp2->getID() << "\n";

}
void Connection::LoadConnection(UI* pUI) {
	int x1 = Comp1->getCoordinates().x;
	int x2 = Comp2->getCoordinates().x;
	int y1 = Comp1->getCoordinates().y;
	int y2 = Comp2->getCoordinates().y;
	if (x2 > x1) {
		pGfxInfo->PointsList[1].x = x2;
		pGfxInfo->PointsList[1].y = y2 - pUI->getCompHeight() / 2;
		pGfxInfo->PointsList[0].x = x1 + pUI->getCompWidth();
		pGfxInfo->PointsList[0].y = y1;
	}
}