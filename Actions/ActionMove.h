#pragma once

#include "Action.h"


class ActionMove: public Action
{
private:
	Component* pComp;
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionMove(ApplicationManager* pApp);
	virtual ~ActionMove(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};
