#pragma once
#include "Action.h"
#include <fstream>
#include <string>
using namespace std;

class ActionSave : public Action
{
protected:
	fstream file;
	//Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp
	//int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionSave(ApplicationManager* pApp);
	virtual ~ActionSave(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
