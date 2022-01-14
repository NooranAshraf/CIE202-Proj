#pragma once
#include "Action.h"

//Class responsible for Delete action
class ActionMultipleDelete: public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp

public:
	ActionMultipleDelete(ApplicationManager* pApp);
	virtual ~ActionMultipleDelete(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
