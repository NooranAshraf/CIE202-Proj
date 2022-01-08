#include "ActionSave.h"
#include "../ApplicationManager.h"
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}

ActionSave::~ActionSave(void)
{
}

void ActionSave::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Saving the file: Enter the name");

	//Get Center point of the area where the Comp should be drawn
	// 
	//pUI->Get file name from the user;
	string filename = pUI->GetSrting();
	//Clear Status Bar
	pUI->ClearStatusBar();


	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

												 //Calculate the rectangle Corners
	//int compWidth = pUI->getCompWidth();
	//int compHeight = pUI->getCompHeight();

	//pGInfo->PointsList[0].x = Cx - compWidth / 2;
	//pGInfo->PointsList[0].y = Cy - compHeight / 2;
	//pGInfo->PointsList[1].x = Cx + compWidth / 2;
	//pGInfo->PointsList[1].y = Cy + compHeight / 2;

	//Bulb* pR = new Bulb(pGInfo);
	//pManager->AddComponent(pR);

	file.open(filename);
	/*pManager->Save(file);*/

	file.close();
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{}