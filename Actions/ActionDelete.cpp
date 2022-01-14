#include "ActionDelete.h"
#include "..\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("deleting the component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get the clicked component to delete
	Component* CompDeleted = pManager->GetComponentByCordinates(Cx, Cy);

	//Get the clicked connection to delete
	Connection* ConnDeleted = pManager->GetConnectionByCoordinates(Cx, Cy);

	
	if (CompDeleted != nullptr) {
		pManager->DeleteComp(Cx, Cy);
	}

	
	else if (ConnDeleted != nullptr) {
		pManager->DeleteConn(ConnDeleted);
	}

	else {

		pUI->PrintMsg("Nothing to delete");

		//Clear the status bar
		pUI->CreateStatusBar();
	}
	
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}
