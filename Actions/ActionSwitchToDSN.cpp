#include "ActionSwitchToDSN.h"
#include "..\ApplicationManager.h"




ActionSwitchToDSN::ActionSwitchToDSN(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchToDSN::~ActionSwitchToDSN(void)
{
}

void ActionSwitchToDSN::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Clear Status Bar
	pUI->ClearStatusBar();

	//clear menu
	pUI->ClearMenu();
	
	pUI->CreateDesignToolBar();
 


}

void ActionSwitchToDSN::Undo()
{}

void ActionSwitchToDSN::Redo()
{}