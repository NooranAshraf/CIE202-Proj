#include "ActionSelect.h"
#include "..\ApplicationManager.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSelect::~ActionSelect(void)
{
}

void ActionSelect::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Selecting a component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	Component* pSelect = pManager->ReturnComp(Cx,Cy);
	if (pSelect != nullptr) {
		pSelect->Select();
	}


}

void ActionSelect::Undo()
{}

void ActionSelect::Redo()
{}

