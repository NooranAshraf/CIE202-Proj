#include "ActionCut.h"
#include "..\ApplicationManager.h"

ActionCut::ActionCut(ApplicationManager* pApp) :Action(pApp)
{
}

ActionCut::~ActionCut(void)
{
	delete ComptoCut;
}

void ActionCut::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("Cutting the component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	

	ComptoCut = pManager->ReturnComp(Cx, Cy);
	

	if (ComptoCut != nullptr) {
		pManager->Cut(ComptoCut);
		ComptoCut->CopyComp();
		//pManager->DeleteComp(Cx, Cy);
		
		pUI->ClearStatusBar();
	}
	else {

		pUI->PrintMsg("Nothing to cut");

		//Clear the status bar
		pUI->CreateStatusBar();
	}

	
}

void ActionCut::Undo()
{}

void ActionCut::Redo()
{}
