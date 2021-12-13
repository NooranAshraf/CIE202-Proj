#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.H"
#include "..\UI\UI.h"
#include "Connection.h"
#include <fstream>


//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	string m_Label;
protected:
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2

	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;
	bool selected;
	double voltage;
	double resistance;
    
	int id; // theses two lines are for the id of the components to save in the file
	double value;
	string Type;


	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component

public:
	static int st_id;
	Component(GraphicsInfo *r_GfxInfo);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	void setLabel(string label);
	string getLabel() const;
	double getResistance() const;
	double getVoltage() const;
	int getID() const; //for the save file
	Point getCoordinates() const; //for the save file
	double getValue() const;

	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	virtual void Edit(UI*) = 0;   //To edit label and voltage -N
	
	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	void Select();
	bool available(int x, int y); //returns true if the point clicked contains this component-N
	void Unselect();
	virtual void SaveComponent(fstream& file) = 0;
	virtual void LoadComponent(fstream& file, UI* pUI) = 0;

	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
