#include "ActionPaste.h"
#include "..\ApplicationManager.h"

ActionPaste::ActionPaste(ApplicationManager* pApp) :Action(pApp)
{
}

ActionPaste::~ActionPaste(void)
{
}

void ActionPaste::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Pasteing the component");

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

	Component* pasteCopy = pManager->getCompCopied();
	Component* pasteCut = pManager->getCompCut();

	pManager->Paste(pasteCopy, pGInfo);
	pManager->Paste(pasteCut, pGInfo);
}

void ActionPaste::Undo()
{
	pManager->MinusList();
}

void ActionPaste::Redo()
{
	pManager->AddComponent(pComp);
}
