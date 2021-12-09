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
		case EDIT :
			pAct = new ActionEdit(this);
			break;
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

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
//PLEASE WORK - 