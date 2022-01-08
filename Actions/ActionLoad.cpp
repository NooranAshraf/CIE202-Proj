#include "ActionLoad.h"
#include "../ApplicationManager.h"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}

void ActionLoad::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("loading the file: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);
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

	file.open(filename.c_str());
	while (!file) {
		pUI->PrintMsg("file open failed");
		string filename = pUI->GetSrting();
		file.open(filename.c_str());
	}
	pManager->Load(file);
	file.close();
}


void ActionLoad::Undo()
{}

void ActionLoad::Redo()
{}