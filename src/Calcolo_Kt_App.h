/*
	Calcolo_Kt_App.h
	Mattia Tristo
	2003
*/

#ifndef CALCOLO_KT_APP_H
#define CALCOLO_KT_APP_H

#ifndef _APPLICATION_H
#include <Application.h>
#endif

#ifndef _ROSTER_H
#include <Roster.h>
#endif

#ifndef _PATH_H
#include <Path.h>
#endif

#ifndef _LOCALE_H
#include <Locale.h>
#endif

//#include <sys/param.h> // for MAX() macro
//#include <inttypes.h>
//#define _T(str) be_locale.GetString(str)
//typedef char            Char; 

#ifndef CALCOLO_KT_WINDOW_H
#include "Calcolo_Kt_Window.h"
#endif

const uint32 MENU_LANG = 'mnlg';

class CalcoloKtApplication : public BApplication {

public:
             CalcoloKtApplication();
//virtual void MessageReceived(BMessage * msg);

private:
			  CalcoloKtWindow    *aWindow;
	
};

#endif

#define		LABEL_WINDOW_TITLE					_T("Kt Calc")
#define		LABEL_BOX_TITLE						_T("Calculation of concentration's factor Kt")
#define		LABEL_BUTTON_CAPTION				_T("Calculate!")
#define		LABEL_ABOUT							_T("About")
#define		LABEL_MENU_MODEL					_T("Model")
#define		LABEL_MENU_MODEL_CIRCULAR_FORCE		_T("Circular Sect. - Force")
#define		ALERT_MODEL							_T("Till now only the circular section model with force is supported.\nFeel free to contribute implementing other models.")
#define		ALERT_OK							_T("Ok")
#define		ABOUT_BOX_MESSAGE					_T("  Calculation of concentration's\n        factor of stress Kt\n\n           written  by\n          Mattia Tristo\n\n         to contact me :\n     mattia_tristo@libero.it\n\n      Padova - Italy - 2003\n\n")
#define		ALERT_RD_TITLE						_T("r/d out of range")
#define		ALERT_RD_MESSAGE					_T("The value of r/d entered is out of validity range\n( 0 < r/d <= 0.30)")
#define		ALERT_DD_TITLE						_T("D/d out of range")
#define		ALERT_DD_MESSAGE					_T("The value of D/d entered is out of validity range\n( 1.01 <= D/d <= 3)")
