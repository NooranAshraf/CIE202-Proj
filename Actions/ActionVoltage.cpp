#include "ActionVoltage.h"
#include "..\ApplicationManager.h"

ActionVoltage::ActionVoltage(ApplicationManager* pApp) : Action(pApp)
{
}

ActionVoltage::~ActionVoltage(void)
{
}

void ActionVoltage::Execute()
{
	UI* pUI = pManager->GetUI();
	//Print Action Message
	pUI->PrintMsg("Calculating the Voltage");

	
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get a Pointer to the user Interfaces
	//pManager->CalculateVoltages();





	pUI->ClearStatusBar();

}

void ActionVoltage::Undo()
{}

void ActionVoltage::Redo()
{}

