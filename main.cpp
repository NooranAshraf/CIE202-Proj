
#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"
#include "Components/Component.h"

int Component::st_id = 0;

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	

	}while(ActType != EXIT);
		
	return 0;
}

