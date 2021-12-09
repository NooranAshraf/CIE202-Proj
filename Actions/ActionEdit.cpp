#include "ActionEdit.h"
#include "..\ApplicationManager.h"

ActionEdit::ActionEdit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionEdit::~ActionEdit(void)
{
}

void ActionEdit::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Editing a component/connection");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	Component* pSelect = pManager->ReturnComp(Cx, Cy);
	if (pSelect != nullptr) {
		pSelect->Edit(pUI);
	}
	pUI->ClearStatusBar();

}

void ActionEdit::Undo()
{}

void ActionEdit::Redo()
{}

