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
	Component* Comp1 =pManager->ReturnComp(Cx, Cy);
	//int x1 = Comp1->getCompCenterX(pUI), y1 = Comp1->getCompCenterY(pUI); ------ uncomment before submitting----
	
	if (Cx < x1) {

		pGInfo->PointsList[0].x = x1 - pUI->getCompWidth();
		pGInfo->PointsList[0].y = y1;

	}
	else {

		pGInfo->PointsList[0].x = pUI->getCompWidth();
		pGInfo->PointsList[0].y = y1;
	}



	// Print Action Message
	pUI->PrintMsg("Click on the Second component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx2, Cy2);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get pointer to the second component
	Component* Comp2 = pManager->ReturnComp(Cx, Cy);
	//int x2 = Comp2->getCompCenterX(pUI), y2 = Comp2->getCompCenterY(pUI);
	
	if (Cx < x2) {
		pGInfo->PointsList[1].x = x2 - pUI->getCompWidth();
		pGInfo->PointsList[1].y = y2;
	}
	else {
		pGInfo->PointsList[1].x = pUI->getCompWidth();
		pGInfo->PointsList[1].y = y2;
	};

	Connection* pR = new Connection(pGInfo,Comp1,Comp2);
	 
	/*pManager->AddConnection(pR);
	if (Cx > x1) {
		Comp1->addTerm1Connection(pR);
	}
	else Comp1->addTerm2Connection(pR);

	if (Cx2 > x2) {
		Comp2->addTerm1Connection(pR);
	}
	else Comp2->addTerm2Connection(pR);*/
	///////////////////////////////////////////////////////////////// ALAA ///////// uncomment before submitting if working
}

void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}
