#include "ActionSwitchToEditor.h"
#include "..\ApplicationManager.h"


ActionSwitchToEditor::ActionSwitchToEditor(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSwitchToEditor::~ActionSwitchToEditor(void)
{
}

void ActionSwitchToEditor::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Clear Status Bar
	pUI->ClearStatusBar();

	//clear menu
	pUI->ClearMenu();

	pUI->CreateEditorToolBar();



}

void ActionSwitchToEditor::Undo()
{}

void ActionSwitchToEditor::Redo()
{}