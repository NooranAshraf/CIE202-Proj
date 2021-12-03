#pragma once
#include "Action.h"
#include "..\Components\battery.h"


class ActionAddBattery :public Action {    //Class responsible for adding a new resistor action
private:
//Parameters for rectangular area to be occupied by the comp
		int Cx, Cy;	//Center point of the comp
		int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
		ActionAddBattery(ApplicationManager* pApp);
		virtual ~ActionAddBattery(void);

		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();
};

