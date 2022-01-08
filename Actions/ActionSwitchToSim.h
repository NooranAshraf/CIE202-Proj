#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

//Class responsible for Simulation Mode
class ActionSwitchToSim : public Action
{
private: 
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp

public:
	ActionSwitchToSim(ApplicationManager* pApp);
	virtual ~ActionSwitchToSim(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
