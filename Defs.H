#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_RESISTOR,		//Add a resistor
	ADD_SWITCH,			//Add Switch
	ADD_BULB,			//Add LAMP
	ADD_BATTERY,        //ADD BATTERY
	ADD_FUSE,            //ADD FUSE
	ADD_BUZZER,
	ADD_GROUND,
	ADD_CONNECTION,		//Add Wire Connection
	EDIT,

	START_SIM,
	VOLTAGE,
	CURRENT,

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection

	MOVE,		//Move a Component, a Connection
	MODULE,
	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file
	MultDel,
	DELET,
	COPY,
	CUT,
	PASTE,
	SAVE_MODULE,

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled
	CALC_CURR,

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	EDITOR_MODE,

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	EDITOR,
};

//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20




#endif