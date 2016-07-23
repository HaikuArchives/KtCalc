/*
	Calcolo_Kt_Window.cpp
	Mattia Tristo
	2003
*/

#ifndef _APPLICATION_H
#include <Application.h>
#endif

#ifndef CALCOLO_KT_APP_H
#include "Calcolo_Kt_App.h"
#endif

#ifndef CALCOLO_KT_WINDOW_H
#include "Calcolo_Kt_Window.h"
#endif

#ifndef CALCOLO_KT_VIEW_H
#include "Calcolo_Kt_View.h"
#endif

void set_palette_entry(long i,rgb_color c);

CalcoloKtWindow::CalcoloKtWindow(BRect frame)
    : BWindow(frame, LABEL_WINDOW_TITLE, B_TITLED_WINDOW, B_NOT_RESIZABLE)
{
    CalcoloKtView  *aView;
	
    frame.OffsetTo(B_ORIGIN);
    frame.top += MENU_BAR_HEIGHT + 1;
    aView = new CalcoloKtView(frame, "CalcoloKtView");
	aView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
    AddChild(aView);
    
    BMenu *menu;
    //BMenuItem *menuitem;
    BRect menuBarRect;
    
    menuBarRect.Set(0, 0, 10000, MENU_BAR_HEIGHT);
    fMenuBar = new BMenuBar(menuBarRect, "MenuBar");
    AddChild(fMenuBar);
    
    menu = new BMenu(LABEL_MENU_MODEL);
    fMenuBar->AddItem(menu);
        
    menu->AddItem(new BMenuItem(LABEL_MENU_MODEL_CIRCULAR_FORCE, new BMessage(MENU_MODEL_CF)));
    
    menu = new BMenu(LABEL_ABOUT);
    fMenuBar->AddItem(menu);
    
    menu->AddItem(new BMenuItem(LABEL_ABOUT, new BMessage(MENU_ABOUT)));
    
    Show();
}

void CalcoloKtWindow::MessageReceived(BMessage * msg)
{

   switch(msg->what)
   {
      case COMMAND_CALC: 
         {
         	CalcoloKtView *appView;
         	appView = (CalcoloKtView *)FindView("CalcoloKtView");
         	appView->Calculate();
         }
      break;
	  
	  case MENU_MODEL_CF:
	  	{
	  		BAlert *myAlert = new BAlert(LABEL_MENU_MODEL, ALERT_MODEL, ALERT_OK, NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
	  		//int32 button_index = 
	  		myAlert->Go();
		 }
	  break;
	  
	  case MENU_ABOUT:
	  	{
	  		BAlert *myAlert = new BAlert(LABEL_ABOUT, ABOUT_BOX_MESSAGE, ALERT_OK, NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT); 
	  		BTextView *myAlertTextView;
	  		myAlertTextView = myAlert->TextView();
	  		myAlertTextView->SetFontAndColor(be_fixed_font);
	  		myAlert->Go();
		 }
	  break;
	  
      default:
         BWindow::MessageReceived(msg);
      break;
   }
}

bool CalcoloKtWindow::QuitRequested()
{
    be_app->PostMessage(B_QUIT_REQUESTED);
    return(TRUE);
}
