#ifndef _ACTION_H
#define _ACTION_H

class ApplicationManager; //forward class declaration
class Component;
class Connection;

//Base class for all possible actions (abstract class)
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	Component* pComp;
	Connection* pCon;

public:
	Action(ApplicationManager *pApp) { pManager = pApp;
	pComp = nullptr;
	pCon = nullptr;
	}	//constructor
	

	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo()=0;

	//To redo this action (code depends on action type)
	virtual void Redo()=0;


};

#endif