#include "ActionAddModule.h"
#include "../ApplicationManager.h"

ActionAddModule::ActionAddModule(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddModule::~ActionAddModule(void)
{
}

void ActionAddModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a Module: Click anywhere to add");

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

	//Set the graphics info

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Module* pR = new Module(pGInfo);

	pManager->AddComponent(pR);

	pR->Draw(pUI);

	pUI->PrintMsg("Enter R1");
	double R1 = stod(pUI->GetSrting());
	pUI->PrintMsg("Enter R2");
	double R2 = stod(pUI->GetSrting());
	pUI->PrintMsg("Enter R3");
	double R3 = stod(pUI->GetSrting());
	pUI->PrintMsg("Enter R4");
	double R4 = stod(pUI->GetSrting());

	pUI->ClearStatusBar();

	pR->Req = 1 / ((1 / (R1 + R2)) + (1 / (R3 + R4)));

	pUI->PrintMsg(to_string(pR->Req));
	pComp = pR;
}

void ActionAddModule::Undo()
{
	pManager->MinusList();
}

void ActionAddModule::Redo()
{
	pManager->AddComponent(pComp);
}