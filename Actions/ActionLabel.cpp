#include "ActionLabel.h"
#include "../ApplicationManager.h"
#include "../UI/UI.h"


ActionLabel::ActionLabel(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLabel::~ActionLabel(void)
{
}

void ActionLabel::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();


	//Print Action Message
	pUI->PrintMsg(" Click on a Component or Connection to label it");

	//Get Center point of the area where the Comp should be labelled
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Get the clicked component  
	Component* SelectedComponent = pManager->GetComponentByCordinates(Cx, Cy);

	//Get the clicked Connection
	Connection* SelectedConnection = pManager->GetConnectionByCoordinates(Cx, Cy);

	//Check if the pointer to the component is nullptr or not
	if (SelectedComponent != nullptr) {

		pComp = SelectedComponent;

		//Print Message to label the component
		pUI->PrintMsg("Enter the label of the Component");

		//Get the label of the component
		 newlabel = pUI->GetSrting();

		OldLabel = SelectedComponent->getLabel();

		//set the label of the component
		SelectedComponent->setLabel(newlabel);
	}

	//Check if the pointer to the connection is nullptr or not
	else if (SelectedConnection != nullptr) {
		pCon = SelectedConnection;
		//Print Message to label the connection
		pUI->PrintMsg("Enter the label of the Connection:");

		//Get the label of the connection
		newlabel = pUI->GetSrting();
		OldLabel = SelectedConnection->getLabel();
		//set the label of the connection
		SelectedConnection->setLabel(newlabel);
	}

	//Print message that no connection or component is selected
	else pUI->PrintMsg("No Component or Connection is selected to be labeled");

	//Clear the Status Bar
	pUI->ClearStatusBar();


}




void ActionLabel::Undo()
{
	if (pComp != nullptr) {

		pComp->setLabel(OldLabel);
	}
	else if (pCon != nullptr) {
		pCon->setLabel(OldLabel);
	}
}

void ActionLabel::Redo()
{
	if (pComp != nullptr) {

		pComp->setLabel(newlabel);
	}
	else if (pCon != nullptr) {
		pCon->setLabel(newlabel);
	}
}