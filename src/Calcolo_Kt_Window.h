/*
	Calcolo_Kt_Window.h
	Mattia Tristo
	2003
*/

#ifndef CALCOLO_KT_WINDOW_H
#define CALCOLO_KT_WINDOW_H
#endif

#ifndef _WINDOW_H
#include <Window.h>
#endif

#ifndef _MENUBAR_H
#include <MenuBar.h>
#endif

#ifndef _MENU_H
#include <Menu.h>
#endif

#ifndef _MENUITEM_H
#include <MenuItem.h>
#endif

#ifndef _ALERT_H
#include <Alert.h>
#endif

#ifndef _TEXTVIEW_H
#include <TextView.h>
#endif

#define MENU_BAR_HEIGHT   18.0
#define MENU_MODEL_CF     'mmcf'
#define MENU_ABOUT		  'mnab'

class CalcoloKtWindow : public BWindow {

public:
              CalcoloKtWindow(BRect frame);
virtual void  MessageReceived(BMessage * msg);
virtual	bool  QuitRequested();

private:

	BMenuBar	*fMenuBar;
};
