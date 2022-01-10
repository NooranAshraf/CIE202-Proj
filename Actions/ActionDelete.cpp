#include "ActionDelete.h"
#include "..\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{
}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("deleting the component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get the clicked component to delete
	Component* CompDeleted = pManager->GetComponentByCordinates(Cx, Cy);

	//Get the clicked connection to delete
	Connection* ConnDeleted = pManager->GetConnectionByCoordinates(Cx, Cy);

	
	if (CompDeleted != nullptr) {
		pManager->DeleteComp(Cx, Cy);
	}

	
	else if (ConnDeleted != nullptr) {
		pManager->DeleteConn(ConnDeleted);
	}

	else {

		pUI->PrintMsg("Nothing to delete");

		//Clear the status bar
		pUI->CreateStatusBar();
	}
	


	//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	//int compWidth = pUI->getCompWidth();
	//int compHeight = pUI->getCompHeight();

	//Check the clicked point is in th design area
	/*while (((Cy - compHeight / 2) <= pUI->getToolBarHeight()) || ((Cy + compHeight / 2) >= (pUI->getWinHeight() - pUI->getStatBarHeight()))) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};

	while ((((Cx - compWidth / 2) <= 0)) || ((Cx + compWidth / 2) >= pUI->getWinWidth())) {
		pUI->PrintMsg("Click in another place in the design area");
		pUI->GetPointClicked(Cx, Cy);
	};*/

	//Clear Status Bar
	//pUI->ClearStatusBar();

	//Set the Graphics info

	//pGInfo->PointsList[0].x = Cx - compWidth / 2;
	//pGInfo->PointsList[0].y = Cy - compHeight / 2;
	//pGInfo->PointsList[1].x = Cx + compWidth / 2;
	//pGInfo->PointsList[1].y = Cy + compHeight / 2;

	//Resistor* pR = new Resistor(pGInfo);
	//pManager->AddComponent(pR);
}

void ActionDelete::Undo()
{
	pManager->AddComponent(pComp);
}

void ActionDelete::Redo()
{
	pManager->MinusList();
}
