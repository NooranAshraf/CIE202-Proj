#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components/Component.h"
#include "Components/Connection.h"
#include <stack>

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components
	enum { MaxConnCount = 200 };

private:
	int CompCount, ConnCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers)
	UI* pUI; //pointer to the UI
	stack<Action* > stackUndo;
	stack<Action*> stackRedo;

protected:
	Component* CompCopied;
	Component* CompCut;
	

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	int getCompCount() {};

	int getConnCount() {};



	Component** getComplist() {}

	Connection** getConnList() {}
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddConnection(Connection* pConn);
	void Save(ofstream& file);  //save function 
	void Load(ifstream& file);  //Load function


	void UnselectAll();

	
	bool DeleteComp(int x, int y);
	bool DeleteConn(Connection* pConn);
	void Copy(Component* Cp);
	void Paste(Component* Pp, GraphicsInfo* pGInfo);
	void Cut(Component* Cp, int x, int y);
	void Undo();
	void MinusList();
	void Redo();

	Component* getCompCopied()const;
	Component* getCompCut()const;

	Component* GetComponentByCordinates(int x, int y);
	Connection* GetConnectionByCoordinates(int x, int y);

	Component* ReturnComp(int x, int y);
	Component* ReturnCompbyID(int id);

	//destructor
	~ApplicationManager();
};

#endif