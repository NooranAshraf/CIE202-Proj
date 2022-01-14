#include "ActionMove.h"
#include"../ApplicationManager.h"

ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{
}

ActionMove::~ActionMove(void)
{
}

void ActionMove::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	pComp = pManager->GetComponentByCordinates(Cx, Cy);



	buttonstate state = pUI->getState(LEFT_BUTTON, Cx, Cy);


	if (pComp != nullptr) {

		pUI->FindClick(Cx, Cy);
		//Not really sure what to do next i don't really understand the mouse files

		pManager->UpdateInterface();

	}

}

void ActionMove::Undo()
{
	
}

void ActionMove::Redo()
{
	
}

