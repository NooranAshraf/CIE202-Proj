#include "ActionAddGround.h"
#include "../ApplicationManager.h"

ActionAddGround::ActionAddGround(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddGround::~ActionAddGround(void)
{
}

void ActionAddGround::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Bulb: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

												 //Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();


	//Check the clicked point is in th design area
	while (((Cy - compHeight / 2) <= 50) || ((Cy + compHeight / 2) >= 600)) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};

	while (((Cy - compWidth / 2) <= 200) || ((Cy + compWidth / 2) >= 1000)) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Set the graphics info

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Ground* pR = new Ground(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddGround::Undo()
{}

void ActionAddGround::Redo()
{}

