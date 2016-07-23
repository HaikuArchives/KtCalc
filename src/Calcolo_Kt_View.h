/*
	Calcolo_Kt_View.h
	Mattia Tristo
	2003
*/

#ifndef CALCOLO_KT_VIEW_H
#define CALCOLO_KT_VIEW_H

#ifndef _VIEW_H
#include <View.h>
#endif

#ifndef _TEXTCONTROL_H
#include <TextControl.h>
#endif

#ifndef _STRINGVIEW_H
#include <StringView.h>
#endif

#ifndef _BUTTON_H
#include <Button.h>
#endif

#ifndef _BOX_H
#include <Box.h>
#endif

#ifndef _STRING_H
#include <String.h>
#endif

#ifndef _CSTDLIB_H
#include <cstdlib>
#endif

#ifndef _CMATH_H
#include <cmath>
#endif

const uint32 COMMAND_CALC = 'Calc';

class CalcoloKtView : public BView {

public:
              CalcoloKtView(BRect frame, char *name); 
virtual	void  AttachedToWindow();
virtual	void  Draw(BRect updateRect);
virtual	void  Calculate();

private :

	BTextControl 	*txt1;
	BTextControl 	*txt2;
	BStringView     *lbl1;

};

#endif 
