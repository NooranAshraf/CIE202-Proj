#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBulb.h"
#include "Actions\ActionAddBattery.h"
#include "Actions\ActionAddFuse.h"
#include "Actions\ActionAddBuzzer.h"
#include "Actions\ActionAddGround.h"
#include "Actions\ActionAddSwitch.h"
#include "Actions\ActionSelect.h"
#include "Actions\ActionEdit.h"
#include "Actions\ActionSwitchToDSN.h"
#include "Actions\ActionSwitchToSim.h"
#include "Actions\ActionSave.h"
#include "Actions\ActionLoad.h"
#include "Actions\ActionLabel.h"
#include "Actions/ActionAddConnection.h"
#include "Actions/ActionDelete.h"
#include "Actions/ActionPaste.h"
#include "Actions/ActionCopy.h"
#include "Actions/ActionCut.h"
#include "Actions/ActionSwitchToEditor.h"
#include "Actions/ActionAddModule.h"
#include "Actions/ActionUndo.h"






ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;
	

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxConnCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

void ApplicationManager::AddConnection(Connection* pConn) 
{
	ConnList[ConnCount++] = pConn;
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
		//case LABEL:
			//pAct = new ActionLabel(this);
			//break;
		case EDIT :
			pAct = new ActionEdit(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionAddConnection(this);
			break;
		case SIM_MODE:
			pAct = new ActionSwitchToSim(this);
			break;
        case MODULE :
			pAct = new ActionAddModule(this);
                        break;
		case DELET:
			pAct = new ActionDelete(this);
			break;
		case COPY:
			pAct = new ActionCopy(this);
			break;
		case CUT:
			pAct = new ActionCut(this);
			break;
		case PASTE:
			pAct = new ActionPaste(this);
			break;
		case EDITOR_MODE:
			pAct = new ActionSwitchToEditor(this);
			break;
		case UNDO :
			pAct = new ActionUndo(this);
			break;

			

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct&& ActType !=UNDO)
	{
		pAct->Execute();
		stackUndo.push(pAct);
		
		/*delete pAct;
		pAct = nullptr;*/
	}
	if (ActType == UNDO) {
		pAct->Execute();
		delete pAct;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::Undo()
{
	Action* pUndo = stackUndo.top();
	stackUndo.pop();
	pUndo->Undo();
	stackRedo.push(pUndo);
	
}

void ApplicationManager::UpdateInterface()
{
	pUI->ClearDrawingArea();
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
///////////////////////////////////////////////////////////////////
bool ApplicationManager::DeleteComp(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->available(x, y) == TRUE) {
				Connection** Conn1 = CompList[i]->getTerm1_Conn();
				Connection** Conn2 = CompList[i]->getTerm2_Conn();
				for (int j = 0; j < CompList[i]->getterm1conn(); i++) {
					DeleteConn(Conn1[j]);
				}
				for (int j = 0; j < CompList[i]->getterm2conn(); i++) {
					DeleteConn(Conn2[j]);
				}
				delete CompList[i];
				for (int j = i; j < CompCount-1; j++)
				CompList[j] = CompList[j + 1];
				CompCount--;
				return true;
				
		}
	}
	return false;
}

bool ApplicationManager::DeleteConn(Connection* pConn) {
	for (int i = 0; i < ConnCount; i++) {
		if (pConn == ConnList[i] && pConn != nullptr) {
			Component* Comp1 = ConnList[i]->getCmpnt1();
			Component* Comp2 = ConnList[i]->getCmpnt2();
			Comp1->DeleteConn(ConnList[i]);
			Comp2->DeleteConn(ConnList[i]);
			delete ConnList[i];
			for (int j = i; j < ConnCount - 1; j++)
				ConnList[j] = ConnList[j + 1];
			ConnCount--;
			return true;

		}
	}
	return false;
}

void ApplicationManager::Copy(Component* Cp) {
	CompCopied = Cp;
}
void ApplicationManager::Cut(Component* Cp, int x, int y) {
	CompCut = Cp;
	DeleteComp(x, y);
	//pUI->ClearDrawingArea();
}
	
Component* ApplicationManager::getCompCopied()const {
	return CompCopied;
}
Component* ApplicationManager::getCompCut()const {
	return CompCut;
}

void ApplicationManager::Paste(Component* Pp, GraphicsInfo* pGInfo) {
	if (CompCopied) {
		Pp = CompCopied;
	}
	else if (CompCut) {
		Pp = CompCut;
	}
	if (dynamic_cast<Resistor*>(Pp)) {
		Resistor* pR = new Resistor(pGInfo);
		AddComponent(pR);
	}
	if (dynamic_cast<battery*>(Pp)) {
		battery* pB = new battery(pGInfo);
		AddComponent(pB);
		pB->PasteComp();
	}
	if (dynamic_cast<Buzzer*>(Pp)) {
		Buzzer* pB = new Buzzer(pGInfo);
		AddComponent(pB);
	}
	if (dynamic_cast<Fuse*>(Pp)) {
		Fuse* pR = new Fuse(pGInfo);
		AddComponent(pR);
	}
	if (dynamic_cast<Ground*>(Pp)) {
		Ground* pR = new Ground(pGInfo);
		AddComponent(pR);
	}
	if (dynamic_cast<Switch*>(Pp)) {
		Switch* pR = new Switch(pGInfo);
		AddComponent(pR);
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::Save(ofstream& file) {                 // save function
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

void ApplicationManager::Load(ifstream& file) {
	string text;
	//getline(file, text); // reads each ch till the end of the line
	int Counter;
	file >> Counter;
	for (int i = 0; i < Counter; i++) {

		//getline(file, text, ' ');  //reads till the space
		string type;
		int id;
		string label;
		double value;
		double x, y;
		file >> type >> id >> label >> value >> x >> y;
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		pGInfo->PointsList[0].x = x;
		pGInfo->PointsList[0].y = y;
		pGInfo->PointsList[1].x = x + pUI->getCompWidth();
		pGInfo->PointsList[1].y = y + pUI->getCompHeight();
		if (type == "RES") {
			Resistor* pR = new Resistor(pGInfo);
			AddComponent(pR);
			pR->LoadComponent(label, value, id);
		}
		else if (type == "BLB") {
			battery* pB = new battery(pGInfo);
			AddComponent(pB);
			pB->LoadComponent(label, value, id);
		}
		else if (type == "BAT") {
			Bulb* pB = new Bulb(pGInfo);
			AddComponent(pB);
			pB->LoadComponent(label, value, id);
		}
		else if (type == "GND") {
			Ground* pG = new Ground(pGInfo);
			AddComponent(pG);
			pG->LoadComponent(label, value, id);
		}
		else if (type == "SWT") {
			Switch* pS = new Switch(pGInfo);
			AddComponent(pS);
			pS->LoadComponent(label, value, id);
		}
		else if (type == "FUSE") {
			Fuse* pS = new Fuse(pGInfo);
			AddComponent(pS);
			pS->LoadComponent(label, value, id);
		}
	}
	//getline(file, text);
	int CounterConn;
	file >> CounterConn;
	int id = 0;
	int C1, C2;

	for (int i = 0; i < CounterConn; i++) {
		file >> C1 >> C2;
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		Component* Comp1 = ReturnCompbyID(C1);
		Component* Comp2 = ReturnCompbyID(C2);
		Connection* pc = new Connection(pGInfo, Comp1, Comp2);
		pc->LoadConnection(pUI);
		AddConnection(pc);
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

void ApplicationManager::MinusList() {
	CompList[CompCount] = nullptr;
	CompCount--;
}

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++) {
		if(CompList[CompCount])
			delete CompList[i];
		
	}
	for (int i = 0; i < ConnCount; i++) {
		if (ConnList[i] != nullptr) {
			delete ConnList[i];
		}
	}
	delete pUI;
}
