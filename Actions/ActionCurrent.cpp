#include "ActionCurrent.h"
#include "..\ApplicationManager.h"

ActionCurrent::ActionCurrent(ApplicationManager* pApp) : Action(pApp)
{
}

ActionCurrent::~ActionCurrent(void)
{
}

void ActionCurrent::Execute()
{
	UI* pUI = pManager->GetUI();
	//Print Action Message
	pUI->PrintMsg("Calculating the current");

	
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get a Pointer to the user Interfaces

	pManager->CalculateCurrent();


	

	
	pUI->ClearStatusBar();

}

void ActionCurrent::Undo()
{}

void ActionCurrent::Redo()
{}

