#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	//CreateSimulationToolBar();
	CreateStatusBar();		//Create Status bar

}


int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//getters for the dimesions of the window. -Nour

int UI::getWinWidth() const {
	return width;
}

int UI::getWinHeight() const {
	return height;
}

int UI::getToolBarHeight() const {
	return ToolBarHeight;
}

int UI::getStatBarHeight() const {
	return StatusBarHeight;
}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_BULB: return ADD_BULB;
			case ITM_BATTERY: return ADD_BATTERY;
			case ITM_BUZZER:  return ADD_BUZZER;
			case ITM_FUSE: return ADD_FUSE;
			case ITM_SWITCH:  return ADD_SWITCH;
			case ITM_GROUND: return ADD_GROUND;
			case ITM_CONNECTION:  return ADD_CONNECTION;
			case ITM_MODULE: return MODULE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SIM: return SIM_MODE;
			case ITM_EDITOR: return EDITOR_MODE;
          

            case ITM_EXIT:	return EXIT;

			
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else if (AppMode== SIMULATION)//Application is in Simulation mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_CIRC_SIM: return START_SIM;
			case ITM_VOLTAGE:return VOLTAGE;
			case ITM_AMMETER:return CURRENT;
			case ITM_SWITCH_TO_DSN:return DSN_MODE;
			
             

			



				//A click on empty place in desgin toolbar
			}
		}
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}
	else if (AppMode == EDITOR) {
		if (y >= 0 && y < ToolBarHeight) {

			int ClickedItemOrder = (x / ToolItemWidth);

			switch (ClickedItemOrder) 
			{
			case ITM_LABEL: return ADD_Label;
			case ITM_EDIT: return EDIT;
			case ITM_DELETE:return DELET;
			case ITM_MULTIPLE_DELETE:return MultDel;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_TO_DSN:return DSN_MODE;


			}
		} return EDITOR_MODE;
	}

}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_BUZZER] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_BATTERY] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_FUSE] = "images\\Menu\\Menu_Fuse.jpg";
	MenuItemImages[ITM_GROUND] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\connection.jpg";
	MenuItemImages[ITM_MODULE] = "images\\Menu\\Module_Menu.jpg";

	MenuItemImages[ITM_EDITOR] = "images\\Menu\\Edit.jpg";
	MenuItemImages[ITM_SIM] = "images\\Menu\\SwitchToSim.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Redo.jpg";
	

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}

void UI::CreateEditorToolBar() {

	AppMode = EDITOR;

	string MenuItemImages[ITM_EDITOR_CNT];
	MenuItemImages[ITM_LABEL] = "images\\Menu\\Label.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Edit.jpg";
	MenuItemImages[ITM_MULTIPLE_DELETE] = "images\\Menu\\MultiDelete.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\load.jpg";
	MenuItemImages[ITM_TO_DSN] = "images\\Menu\\SwitchToDSN.jpg";
	

	for (int i = 0; i < ITM_EDITOR_CNT; i++) {

		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_CIRC_SIM] = "images\\Menu\\Start_SIM.jpg";
	MenuItemImages[ITM_VOLTAGE] = "images\\Menu\\Voltmeter_SIM.jpg";
	MenuItemImages[ITM_AMMETER] = "images\\Menu\\Ammeter_SIM.jpg";
	MenuItemImages[ITM_SWITCH_TO_DSN] = "images\\Menu\\SwitchToDSN.jpg";
	
	for (int i = 0; i < ITM_SIM_CNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

}

//clears the menu - NOUR

void UI::ClearMenu()const {

		pWind->SetPen(RED, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(0, 0, width, ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

//TODO: Add similar functions to draw all other components
void UI::DrawBulb(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string BulbImage;
	if (selected)
		BulbImage = "Images\\Comp\\Bulb_HI.jpg"; //use image of highlighted bulb
	else
		BulbImage = "Images\\Comp\\Bulb.jpg";	//use image of the normal bulb

													//Draw bulb at Gfx_Info (2nd corner)
	pWind->DrawImage(BulbImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
};

void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BatteryImage;
	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted battery
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	//use image of the normal battery

	//Draw battery at Gfx_Info (1st corner)
	pWind->DrawImage(BatteryImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawFuse(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string FuseImage;
	if (selected)
		FuseImage = "Images\\Comp\\Fuse_Hi.jpg"; //use image of highlighted fuse
	else
		FuseImage = "Images\\Comp\\Fuse.jpg";	//use image of the normal fuse

	//Draw Fuse at Gfx_Info (1st corner)
	pWind->DrawImage(FuseImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BuzzerImage;
	if (selected)
		BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";
	else
		BuzzerImage = "Images\\Comp\\Buzzer.jpg";


	pWind->DrawImage(BuzzerImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string SwitchImage;
	if (selected)
		SwitchImage = "Images\\Comp\\Switch_HI.jpg";
	else
		SwitchImage = "Images\\Comp\\Switch.jpg";


	pWind->DrawImage(SwitchImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Ground_HI.jpg";
	else
		GroundImage = "Images\\Comp\\Ground.jpg";


	pWind->DrawImage(GroundImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}


void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	if(selected)
		pWind->SetPen(RED);
	else
	pWind->SetPen(BLACK);


	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}

void UI::DrawModule(const GraphicsInfo& r_GfxInfo, bool selected) const
{

	string ModuleImage;
	if (selected)
		ModuleImage = "Images\\Comp\\Module_HI.jpg";
	else
		ModuleImage = "Images\\Comp\\Module.jpg";


	pWind->DrawImage(ModuleImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::FindClick(int& x, int& y) {
	pWind->GetMouseCoord(x, y);

}

buttonstate UI::getState(button one, int& x, int& y) {

	return pWind->GetButtonState(one, x, y);
};


UI::~UI()
{
	delete pWind;
}