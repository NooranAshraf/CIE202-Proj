#include "ActionAddFuse.h"
#include "..\ApplicationManager.h"

ActionAddFuse::ActionAddFuse(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddFuse::~ActionAddFuse(void)
{
}

void ActionAddFuse::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new fuse: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

        //Check the clicked point is in th design area
	while (((Cy - compHeight / 2) <= pUI->getToolBarHeight()) || ((Cy + compHeight / 2) >= (pUI->getWinHeight() - pUI->getStatBarHeight()))) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};

	while ((((Cx - compWidth / 2) <= 0)) || ((Cx + compWidth / 2) >= pUI->getWinWidth())) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Set the graphcis info

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Fuse* pR = new Fuse(pGInfo);
	pManager->AddComponent(pR);
	pComp = pR;
}

void ActionAddFuse::Undo()
{
	pManager->MinusList();
}

void ActionAddFuse::Redo()
{
	pManager->AddComponent(pComp);
}