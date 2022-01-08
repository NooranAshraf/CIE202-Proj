#pragma once
#include "Action.h"

//Class responsible for label components action
class ActionLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
public:
	ActionLabel(ApplicationManager* pApp);
	virtual ~ActionLabel(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
