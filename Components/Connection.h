#pragma once
#include "..\UI\UI.h"



class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo* pGfxInfo;	//The parameters required to draw a connection
	string m_label;        //Label of connection
	bool selected;
public:
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	virtual void Draw(UI*);	//for connection to Draw itself

	Component* getOtherComponent(Component* Cmpnt); // Get component connected to the other end of the connection
	bool IsInConn(int x, int y, UI* pUI);    //Check if the x and y is in the connection or not
	void setLabel(string label);        //sets the Label
	string getLabel();                  //returns the label
	Component* getCmpnt1();         //returns pointer to first Component
	Component* getCmpnt2();         //returns pointer to second Component
	void selectConn();
	void Unselect();
	void SaveConnection(ofstream& file);
	void LoadConnection(UI* pUI);
	~Connection();
};
