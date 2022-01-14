#include "ActionMultipleDelete.h"
#include "../ApplicationManager.h"


ActionMultipleDelete::ActionMultipleDelete(ApplicationManager* pApp) :Action(pApp)
{


}

ActionMultipleDelete::~ActionMultipleDelete(void)
{
}

void ActionMultipleDelete::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Message to tell the user to enter the number of componets to be deleted
	pUI->PrintMsg("Enter Number of Items To Be Deleted: ");

	//Get tghe number of components to be deleted
	string userinput = pUI->GetSrting();

	//Convert the choice from string to integer
	int Choice = stoi(userinput);

	//Clear the Status Bar
	pUI->ClearStatusBar();

	//Perform the Loop to do the multiple delete
	for (int i = 0; i < Choice; i++) {

		//Print Action Message
		pUI->PrintMsg("Click on the component or connection to delete it");

		//Get Center point of the area where the Comp or connection should be deleted
		pUI->GetPointClicked(Cx, Cy);

		//Clear Status Bar
		pUI->ClearStatusBar();

		//Get the clicked component to delete
		Component* CompToDelete = pManager->GetComponentByCordinates(Cx, Cy);

		//Get the clicked connection to delete
		Connection* ConnToDelete = pManager->GetConnectionByCoordinates(Cx, Cy);

		//Check if the pointer to the component is nullptr or not
		if (CompToDelete != nullptr) {

			//Delete the selected Component
			pManager->DeleteComp(Cx, Cy);
		}

		//Check if the pointer to the connection is nullptr or not
		else if (ConnToDelete != nullptr) {

			//Delete the selected Connection
			pManager->DeleteConn(ConnToDelete);
		}

		else {

			//Print Message that no componenet or connection is selected
			pUI->PrintMsg("No Component or Connection is selected to delete");

			//Clear the Status Bar
			pUI->CreateStatusBar();
		}
	}
}

void ActionMultipleDelete::Undo()
{}

void ActionMultipleDelete::Redo()
{}