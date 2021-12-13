#pragma once
#include "Action.h"





class ActionSwitchToDSN : public Action
{
private:
	////Parameters for rectangular area to be occupied by the comp
	//int Cx, Cy;	//Center point of the comp

public:
    ActionSwitchToDSN(ApplicationManager* pApp);
	virtual ~ActionSwitchToDSN(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
