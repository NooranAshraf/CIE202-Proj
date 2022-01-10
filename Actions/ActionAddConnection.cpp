#include "ActionAddConnection.h"
#include"../ApplicationManager.h"


ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddConnection::~ActionAddConnection(void)
{
}

void ActionAddConnection::Execute() {
	int Cx2, Cy2;
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Connection

	//Print Action Message
	pUI->PrintMsg("Click on the first component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get pointer to the first component 
	Component* Cmpnt1 =pManager->ReturnComp(Cx, Cy);
	
	int x1 = Cmpnt1->getCompCenterX(pUI), y1 = Cmpnt1->getCompCenterY(pUI);
	
	if (Cx < x1) {

		pGInfo->PointsList[0].x = x1 - pUI->getCompWidth()/2;
		pGInfo->PointsList[0].y = y1;

	}
	else {

		pGInfo->PointsList[0].x = x1+ pUI->getCompWidth()/2;
		pGInfo->PointsList[0].y = y1;
	}


	// Print Action Message
	pUI->PrintMsg("Click on the Second component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx2, Cy2);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get pointer to the second component
	Component* Cmpnt2 = pManager->ReturnComp(Cx2, Cy2);

	
	int x2 = Cmpnt2->getCompCenterX(pUI), y2 = Cmpnt2->getCompCenterY(pUI);
	
	if (Cx < x2) {
		pGInfo->PointsList[1].x = x2 - pUI->getCompWidth()/2;
		pGInfo->PointsList[1].y = y2;
	}
	else {
		pGInfo->PointsList[1].x = x2 + pUI->getCompWidth()/2;
		pGInfo->PointsList[1].y = y2;
	}
	
	Connection* pR = new Connection(pGInfo,Cmpnt1,Cmpnt2);
	pManager->AddConnection(pR);
	pCon = pR;
}

void ActionAddConnection::Undo()
{
	pManager->MinusConn();
}

void ActionAddConnection::Redo()
{
	pManager->AddConnection(pCon);
}
