#pragma once
#include "Action.h"

//This class is meant to create a menu for editing tools because there was no place in the design menu

class ActionSwitchToEditor : public Action
{
private:
	////Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp

public:
	ActionSwitchToEditor(ApplicationManager* pApp);
	virtual ~ActionSwitchToEditor(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};