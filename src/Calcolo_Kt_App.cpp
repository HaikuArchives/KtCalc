/*
	Calcolo_Kt_App.h
	Mattia Tristo
	2003
*/

#ifndef CALCOLO_KT_APP_H
#include "Calcolo_Kt_App.h"
#endif

#ifndef CALCOLO_KT_WINDOW_H
#include "Calcolo_Kt_Window.h"
#endif

#ifndef CALCOLO_KT_VIEW_H
#include "Calcolo_Kt_View.h"
#endif

int main(int32 argc, char**argv)
{	
    CalcoloKtApplication *KtApp;

    KtApp = new CalcoloKtApplication();
    KtApp->Run();
	
    delete(KtApp);
    return(0);
}

CalcoloKtApplication::CalcoloKtApplication()
		  		  : BApplication("application/x-vnd.triber-calcolo_kt")
{
    //CalcoloKtWindow    *aWindow;
    BRect           	aRect;

    aRect.Set(20, 20, 400, 390);
    aWindow = new CalcoloKtWindow(aRect);	
}

/*
void CalcoloKtApplication::MessageReceived(BMessage * msg)
{

	switch (msg->what)
	{
		case MENU_LANG_ITA:
		{
			
    	}
    	break;
    		
    	default:
    		BApplication::MessageReceived(msg);
    	break;
    }
}
*/
