#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddGround.h"
#include"Actions\ActionAddSwitch.h"
#include "Actions\ActionSelect.h"
#include "Actions/ActionEdit.h"
#include "Actions/ActionSwitchToDSN.h"
#include "Actions/ActionSave.h"
#include "Actions/ActionLoad.h"
#include "Actions/ActionAddModule.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_BULB:
			pAct = new ActionAddBulb(this);
			break;
		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddFuse(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGround(this);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		case DSN_MODE:
			pAct = new ActionSwitchToDSN(this);
			break;
		case SAVE:
			pAct = new ActionSave(this);
			break;
		case LOAD:
			pAct = new ActionLoad(this);
			break;

		case EDIT :
			pAct = new ActionEdit(this);
			break;
		case MODULE :
			pAct = new ActionAddModule(this);
		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			break;
	

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

//to check which component is clicked on - Nour
Component* ApplicationManager::ReturnComp(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->available(x, y)) {
			return CompList[i];
		}
	}
	return nullptr;
}

void ApplicationManager::UnselectAll() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Unselect();
	}
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i]->Unselect();
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::Save(fstream& file) {                 // save function
	file << std::to_string(CompCount) + "\n";

	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SaveComponent(file);
	}
	file << std::to_string(ConnCount) + "\n";
	for (int i = 0; i < ConnCount; i++) {
		ConnList[i]->SaveConnection(file);

	}
}
////////////////////////////////////////////////////////

void ApplicationManager::Load(fstream& file) {
	string text;

	getline(file, text); // reads each ch till the end of the line
	int Counter = stoi(text);

	for (int i = 0; i < Counter; i++) {

		getline(file, text, ' ');  //reads till the space
		string type = text;

		// get type from text
		GraphicsInfo* pGInfo = new GraphicsInfo(2);

		if (type == "RES") {
			Resistor* pR = new Resistor(pGInfo);
			AddComponent(pR);
			pR->LoadComponent(file, pUI);
		}
		else if (type == "BLB") {
			battery* pB = new battery(pGInfo);
			AddComponent(pB);
			pB->LoadComponent(file, pUI);
		}
		else if (type == "BAT") {
			Bulb* pB = new Bulb(pGInfo);
			AddComponent(pB);
			pB->LoadComponent(file, pUI);
		}
		else if (type == "GND") {
			Ground* pG = new Ground(pGInfo);
			AddComponent(pG);
			pG->LoadComponent(file, pUI);
		}
		else if (type == "SWT") {
			Switch* pS = new Switch(pGInfo);
			AddComponent(pS);
			pS->LoadComponent(file, pUI);
		}
	}
	getline(file, text);
	Counter = 0;
	getline(file, text);
	Counter = stoi(text);
	for (int i = 0; i < Counter; i++) {
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		getline(file, text, ' ');
		Component* C1 = ReturnCompbyID(stoi(text));

		getline(file, text);
		Component* C2 = ReturnCompbyID(stoi(text));
		Connection* pc = new Connection(pGInfo, C1, C2);
		ConnList[i]->LoadConnection(pUI);

	}

}
Component* ApplicationManager::ReturnCompbyID(int id) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->getID() == id) {
			return CompList[i];
		}
	}
	return nullptr;
}
//ALAA
Connection* ApplicationManager::GetConnectionByCoordinates(int x, int y) {
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i]->IsInConn(x, y, pUI) == true) {
			return ConnList[i];
		}
		else
			return nullptr;

	}
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->available(x, y) == true) {
			return CompList[i];
		}
		else
			return nullptr;

	}
}

//int ApplicationManager::getCompCount() {
//	return CompCount;
//}
//
//int ApplicationManager::getConnCount() {
//	return ConnCount;
//}
//
//Component** ApplicationManager::getComplist() {
//	return this->CompList;
//}
//
//Connection** ApplicationManager::getConnList() {
//	return this->ConnList;
//}
///////////////ALAA
void ApplicationManager::AddConnection(Connection* pConn) {
	ConnList[ConnCount++] = pConn;
}

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];
		
	}
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			delete ConnList[i];
		}
	}
	delete pUI;
}
