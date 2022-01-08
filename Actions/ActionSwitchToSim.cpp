#include "Action.h"
#include "ActionSwitchToSim.h"




ActionSwitchToSim::ActionSwitchToSim(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchToSim::~ActionSwitchToSim(void)
{
}

void ActionSwitchToSim::Execute() {

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	
    //Clear Status Bar
	pUI->ClearStatusBar();

	//clear menu
	pUI->ClearMenu();

	pUI->CreateSimulationToolBar();
}

void ActionSwitchToSim::Undo()
{}

void ActionSwitchToSim::Redo()
{}
