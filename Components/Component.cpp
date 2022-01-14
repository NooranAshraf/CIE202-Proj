#include "Component.h"

Component::Component(GraphicsInfo* r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	id = Component::st_id++;

}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	selected = false;
	id = Component::st_id++;

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
void Component::setValue(double copiedvalue) { // for paste feature
	value = copiedvalue;
}

void Component::setCurrent(double Current) { // for the fuse
	this->Current = Current;
}
double Component::getCurrent()const { // for the fuse
	return Current;
}
bool Component::getSwitch()const { // for the switch
	return switched;
}
void Component::setSwitch(bool switched) { // for the switch
	this->switched = switched;
}


void Component::setLabel(string label) {
	m_Label = label;
}

string Component::getLabel() const {
	return m_Label;
}

//Get the X component center
int Component::getCompCenterX(UI* pUI) {
	return m_pGfxInfo->PointsList[0].x + pUI->getCompWidth() / 2;
}

//Get the Y component center
int Component::getCompCenterY(UI* pUI) {
	return m_pGfxInfo->PointsList[0].y + pUI->getCompHeight() / 2;
}

double Component::getResistance() const {
	return resistance;
}
double Component::getVoltage() const {
	return voltage;
}

// Alaa 

 //Set the term1 voltage
void Component::setTerm1Volt(double v) {
	term1_volt = v;
}

//Set the term2 voltage
void Component::setTerm2Volt(double v) {
	term2_volt = v;
}

//Set the Resistance
void Component::setResistance(double R) {
	resistance = R;
}

//Set the SourceVoltage
void Component::setVoltage(double V) {
	voltage = V;

}


//Get the term1 voltage
double Component::getTerm1Volt() {
	return term1_volt;
}

//Get the term2 voltage
double Component::getTerm2Volt() {
	return term2_volt;
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
//Get pointer to the term1 connection
Connection** Component::getTerm1_Conn() {
	return term1_connections;
}

//Get pointer to the term2 connection
Connection** Component::getTerm2_Conn() {
	return term2_connections;
}

//Delete the connection of a componnet
void Component::DeleteConn(Connection* ConnToDelete) {
	for (int i = 0; i < term1_conn_count; i++) {
		if (term1_connections[i] == ConnToDelete) {
			term1_connections[i] = nullptr;
		}
	}
	for (int i = 0; i < term2_conn_count; i++) {
		if (term2_connections[i] == ConnToDelete) {
			term2_connections[i] = nullptr;
		}
	}
}

int Component::getterm1conn()const {
	return term1_conn_count;
}
int Component::getterm2conn()const {
	return term2_conn_count;
}


Component::~Component()
{
	delete m_pGfxInfo;
}

