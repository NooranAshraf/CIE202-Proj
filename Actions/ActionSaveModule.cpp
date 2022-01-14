#include "ActionSaveModul.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"

ActionSaveModule::ActionSaveModule(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSaveModule::~ActionSaveModule(void)
{
}

void ActionSaveModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Enter the module's name");
	// 
	//pUI->Get file name from the user;
	string filenameM = pUI->GetSrting();
	//Clear Status Bar
	pUI->ClearStatusBar();


	fileM.open(filenameM);
	//pManager->SaveModule(fileM);//I do realize fileM is a string but this is how save is done here i don't have time to fix it

	fileM.close();

	

}

void ActionSaveModule::Undo()
{}

void ActionSaveModule::Redo()
{}