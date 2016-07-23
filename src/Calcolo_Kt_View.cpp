/*
	Calcolo_Kt_View.cpp
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

CalcoloKtView::CalcoloKtView(BRect rect, char *name)
    : BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
}


void CalcoloKtView::AttachedToWindow() 
{
    BBox *aBox;
    BRect aBoxRect;
	aBoxRect.Set(10, 10, 370, 340);
    
    aBox = new BBox(aBoxRect /*BRect(10, 10, 340, 312)*/, "Box_Calcolo_Kt",B_FOLLOW_NONE);
    aBox->SetLabel(LABEL_BOX_TITLE);
    AddChild(aBox);
    
    BRect txt1Rect;
	txt1Rect.Set(10, 20, 180, 30);
	
	txt1 = new BTextControl(txt1Rect, "txt1", "r/d :", "0.10", NULL, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	txt1->SetDivider(30);
	txt1->SetTarget(this);
	aBox->AddChild(txt1);
	
	/*
	app_info  theInfo;
	entry_ref theRef;
	
	be_roster->GetRunningAppInfo(be_app->Team(), &theInfo);
	theRef = theInfo.ref;
	
	BEntry theEntry(&theRef);
	BPath path;
	char name[B_FILE_NAME_LENGTH];
	
	theEntry.GetName(name);
	theEntry.GetPath(&path);
	
	txt1->SetText(name);
	*/
	
	BRect txt2Rect;
	txt2Rect.Set(10, 40, 180, 50);
	
	txt2 = new BTextControl(txt2Rect, "txt2", "D/d :", "1.2", NULL, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	txt2->SetDivider(30);
	txt2->SetTarget(this);
	aBox->AddChild(txt2);
	
	//txt2->SetText(path.Path());
	
	BRect lbl1Rect;
	lbl1Rect.Set(10, 70, 80, 80);
	
	lbl1 = new BStringView(lbl1Rect, "lbl1", "Kt : 0.00"); //, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_WILL_DRAW|B_NAVIGABLE);
	aBox->AddChild(lbl1);
	
	BRect buttonRect;
	buttonRect.Set(90, 60, 180, 80);

	BButton * button = new BButton(buttonRect, NULL, LABEL_BUTTON_CAPTION, new BMessage(COMMAND_CALC), B_FOLLOW_ALL_SIDES, B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE);
	button->SetTarget(this);
	aBox->AddChild(button);
	
	BRect drawRect;
	drawRect.Set(20, 100, 330, 310);
	
	BView *drawView;
	drawView = new BView(drawRect, "drawView", B_FOLLOW_ALL_SIDES, 0);
	drawView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	drawView->SetLowColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	aBox->AddChild(drawView);
	

	BRect iconRect;
	iconRect.Set(210, 20, 340, 80);
	
	BView *iconView;
	iconView = new BView(iconRect, "iconView", B_FOLLOW_ALL_SIDES, 0);
	iconView->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	iconView->SetLowColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	aBox->AddChild(iconView);

}


void CalcoloKtView::Draw(BRect)
{
	
	BView *iconView;
    iconView = (BView *)FindView("iconView");
         	
	iconView->SetHighColor(0, 0, 0);	
	
	BPoint	p1, p2;
	
	// Dimensioni della BView iconView 130 x 60 pixels
	
	float x_origin;
	float y_origin;
	float l_tot;
	float h_tot;
	
	// .:: Dimensioni principali dell'icona ::.
	
	x_origin = 25;
	y_origin = 5;
	l_tot = 90;
	h_tot = 52;
	
	// .:: Sezione Sx ::.
	
	p1.x = x_origin;
	p1.y = y_origin;
	p2.x = x_origin + l_tot * 5 / 9;
	p2.y = y_origin;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);

	p1.x = x_origin;
	p1.y = y_origin + h_tot;
	p2.x = x_origin + l_tot * 5 / 9;
	p2.y = y_origin + h_tot;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);

	p1.x = x_origin + l_tot * 5 / 9;
	p1.y = y_origin;
	p2.x = x_origin + l_tot * 5 / 9;
	p2.y = y_origin + h_tot;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	// .:: Quota Sx ::.
	
	p1.x = x_origin + (l_tot * 5 / 9)/2;
	p1.y = y_origin;
	p2.x = x_origin + (l_tot * 5 / 9)/2;
	p2.y = y_origin + h_tot;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	// .:: Freccie quota Sx ::.
	
	float largfreccie;
	BPoint p3;
	
	largfreccie = h_tot * 3 / 52;
	
	p1.x = x_origin + (l_tot * 5 / 9)/2;
	p1.y = y_origin;
	p2.x = p1.x - largfreccie / 2;
	p2.y = p1.y + largfreccie * 2;
	p3.x = p1.x + largfreccie / 2;
	p3.y = p1.y + largfreccie * 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	p1.x = x_origin + (l_tot * 5 / 9)/2;
	p1.y = y_origin + h_tot;
	p2.x = p1.x - largfreccie / 2;
	p2.y = p1.y - largfreccie * 2;
	p3.x = p1.x + largfreccie / 2;
	p3.y = p1.y - largfreccie * 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	// .:: Testo quota Sx ::.
	
	BPoint dimtext;
	BFont font(be_plain_font); 
	
	float fontsize;
	
	fontsize = h_tot * 7 / 52;
	
	font.SetSize(fontsize);
	iconView->SetFont(&font);

	dimtext.x = x_origin + (l_tot * 5 / 9)/2 + l_tot * 5 / 90;
	dimtext.y = y_origin + h_tot / 2 + fontsize / 2;
	
	iconView->MovePenTo(dimtext);
   	iconView->DrawString("D");
	
	// .:: Sezione Dx ::.
	
	float arcradius;
	
	arcradius = l_tot * 7 / 90;
	
	p1.x = x_origin + l_tot * 5 / 9 + arcradius;
	p1.y = y_origin + h_tot / 4;
	p2.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45;
	p2.y = y_origin + h_tot / 4;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	p1.x = x_origin + l_tot * 5 / 9 + arcradius;
	p1.y = y_origin + h_tot *3 / 4;
	p2.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45;
	p2.y = y_origin + h_tot *3 / 4;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	// .:: Quota Dx ::.
	
	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 7 / 45;
	p1.y = y_origin + h_tot / 4;
	p2.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 7 / 45;
	p2.y = y_origin + h_tot *3 / 4;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	// .:: Freccie quota Sx ::.
	
	largfreccie = h_tot * 3 / 52;
	
	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 7 / 45;
	p1.y = y_origin + h_tot / 4;
	p2.x = p1.x - largfreccie / 2;
	p2.y = p1.y + largfreccie * 2;
	p3.x = p1.x + largfreccie / 2;
	p3.y = p1.y + largfreccie * 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 7 / 45;
	p1.y = y_origin + h_tot *3 / 4;
	p2.x = p1.x - largfreccie / 2;
	p2.y = p1.y - largfreccie * 2;
	p3.x = p1.x + largfreccie / 2;
	p3.y = p1.y - largfreccie * 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	// .:: Testo quota Dx ::.
	
	dimtext.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 7 / 45 + l_tot * 5 / 90;
	dimtext.y = y_origin + h_tot / 2 + fontsize / 2;
	
	iconView->MovePenTo(dimtext);
   	iconView->DrawString("d");
   	
   	
   	// .:: Simbolo di continuazione a Sx ::.
   	
   	float xbezorig;
   	float ybezorig;
   	float xunit;
   	float yunit;
   	BPoint controlpoints[4];

   	xbezorig = x_origin;
	ybezorig = y_origin;
	   	
   	xunit = l_tot * 2 / 45;
   	yunit = h_tot / 20;
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 1 * yunit; 	
   	controlpoints[2].x = xbezorig + 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 2 * yunit;
   	controlpoints[3].x = xbezorig + 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 3 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 3 * yunit;
   	controlpoints[1].x = xbezorig + 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 4 * yunit;
   	controlpoints[2].x = xbezorig + 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 5 * yunit;
   	controlpoints[3].x = xbezorig + 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 6 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 6 * yunit;
   	controlpoints[1].x = xbezorig + 1 * xunit;
   	controlpoints[1].y = ybezorig + 7 * yunit;
   	controlpoints[2].x = xbezorig + 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 8 * yunit;
   	controlpoints[3].x = xbezorig + 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 9 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1 * xunit;
   	controlpoints[0].y = ybezorig + 7 * yunit;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 8 * yunit;
   	controlpoints[2].x = xbezorig + 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 9 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 10 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig + 10 * yunit;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 11 * yunit; 	
   	controlpoints[2].x = xbezorig - 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 12 * yunit;
   	controlpoints[3].x = xbezorig - 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 13 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 13 * yunit;
   	controlpoints[1].x = xbezorig - 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 14 * yunit;
   	controlpoints[2].x = xbezorig - 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 15 * yunit;
   	controlpoints[3].x = xbezorig - 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 16 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 16 * yunit;
   	controlpoints[1].x = xbezorig - 1 * xunit;
   	controlpoints[1].y = ybezorig + 17 * yunit;
   	controlpoints[2].x = xbezorig - 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 18 * yunit;
   	controlpoints[3].x = xbezorig - 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 19 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1 * xunit;
   	controlpoints[0].y = ybezorig + 17 * yunit;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 18 * yunit;
   	controlpoints[2].x = xbezorig - 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 19 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 20 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 1 * yunit; 	
   	controlpoints[2].x = xbezorig - 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 2 * yunit;
   	controlpoints[3].x = xbezorig - 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 3 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 3 * yunit;
   	controlpoints[1].x = xbezorig - 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 4 * yunit;
   	controlpoints[2].x = xbezorig - 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 5 * yunit;
   	controlpoints[3].x = xbezorig - 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 6 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 6 * yunit;
   	controlpoints[1].x = xbezorig - 1 * xunit;
   	controlpoints[1].y = ybezorig + 7 * yunit;
   	controlpoints[2].x = xbezorig - 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 8 * yunit;
   	controlpoints[3].x = xbezorig - 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 9 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1 * xunit;
   	controlpoints[0].y = ybezorig + 7 * yunit;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 8 * yunit;
   	controlpoints[2].x = xbezorig - 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 9 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 10 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	
   	// .:: Simbolo di continuazione a Dx ::.

   	xbezorig = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45;
	ybezorig = y_origin + h_tot / 4;
	   	
   	xunit = l_tot * 2 / 90;
   	yunit = h_tot / 40;
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 1 * yunit; 	
   	controlpoints[2].x = xbezorig + 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 2 * yunit;
   	controlpoints[3].x = xbezorig + 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 3 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 3 * yunit;
   	controlpoints[1].x = xbezorig + 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 4 * yunit;
   	controlpoints[2].x = xbezorig + 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 5 * yunit;
   	controlpoints[3].x = xbezorig + 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 6 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 6 * yunit;
   	controlpoints[1].x = xbezorig + 1 * xunit;
   	controlpoints[1].y = ybezorig + 7 * yunit;
   	controlpoints[2].x = xbezorig + 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 8 * yunit;
   	controlpoints[3].x = xbezorig + 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 9 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1 * xunit;
   	controlpoints[0].y = ybezorig + 7 * yunit;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 8 * yunit;
   	controlpoints[2].x = xbezorig + 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 9 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 10 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig + 10 * yunit;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 11 * yunit; 	
   	controlpoints[2].x = xbezorig - 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 12 * yunit;
   	controlpoints[3].x = xbezorig - 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 13 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 13 * yunit;
   	controlpoints[1].x = xbezorig - 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 14 * yunit;
   	controlpoints[2].x = xbezorig - 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 15 * yunit;
   	controlpoints[3].x = xbezorig - 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 16 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 16 * yunit;
   	controlpoints[1].x = xbezorig - 1 * xunit;
   	controlpoints[1].y = ybezorig + 17 * yunit;
   	controlpoints[2].x = xbezorig - 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 18 * yunit;
   	controlpoints[3].x = xbezorig - 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 19 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig - 1 * xunit;
   	controlpoints[0].y = ybezorig + 17 * yunit;
   	controlpoints[1].x = xbezorig - 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 18 * yunit;
   	controlpoints[2].x = xbezorig - 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 19 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 20 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig + 10 * yunit;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 11 * yunit; 	
   	controlpoints[2].x = xbezorig + 1.2 * xunit;
   	controlpoints[2].y = ybezorig + 12 * yunit;
   	controlpoints[3].x = xbezorig + 1.5 * xunit;
   	controlpoints[3].y = ybezorig + 13 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.5 * xunit;
   	controlpoints[0].y = ybezorig + 13 * yunit;
   	controlpoints[1].x = xbezorig + 1.7 * xunit;
   	controlpoints[1].y = ybezorig + 14 * yunit;
   	controlpoints[2].x = xbezorig + 1.5 * xunit;
   	controlpoints[2].y = ybezorig + 15 * yunit;
   	controlpoints[3].x = xbezorig + 1.1 * xunit;
   	controlpoints[3].y = ybezorig + 16 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1.1 * xunit;
   	controlpoints[0].y = ybezorig + 16 * yunit;
   	controlpoints[1].x = xbezorig + 1 * xunit;
   	controlpoints[1].y = ybezorig + 17 * yunit;
   	controlpoints[2].x = xbezorig + 0.8 * xunit;
   	controlpoints[2].y = ybezorig + 18 * yunit;
   	controlpoints[3].x = xbezorig + 0.3 * xunit;
   	controlpoints[3].y = ybezorig + 19 * yunit;
   	   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	controlpoints[0].x = xbezorig + 1 * xunit;
   	controlpoints[0].y = ybezorig + 17 * yunit;
   	controlpoints[1].x = xbezorig + 0.8 * xunit;
   	controlpoints[1].y = ybezorig + 18 * yunit;
   	controlpoints[2].x = xbezorig + 0.3 * xunit;
   	controlpoints[2].y = ybezorig + 19 * yunit;
   	controlpoints[3].x = xbezorig;
   	controlpoints[3].y = ybezorig + 20 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	// .:: Archi di raccordo ::.

	xunit = arcradius / 3;
   	yunit = arcradius / 3;
   	
    xbezorig = x_origin + l_tot * 5 / 9;
	ybezorig = y_origin + h_tot / 4 - arcradius;
   	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig;
   	controlpoints[1].x = xbezorig + 0.5 * xunit;
   	controlpoints[1].y = ybezorig + 1 * yunit; 	
   	controlpoints[2].x = xbezorig + 1 * xunit;
   	controlpoints[2].y = ybezorig + 2 * yunit;
   	controlpoints[3].x = xbezorig + 3 * xunit;
   	controlpoints[3].y = ybezorig + 3 * yunit;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	xbezorig = x_origin + l_tot * 5 / 9;
	ybezorig = y_origin + h_tot *3 / 4;
	
   	controlpoints[0].x = xbezorig;
   	controlpoints[0].y = ybezorig + 3 * yunit;
   	controlpoints[1].x = xbezorig + 0.5 * xunit;
   	controlpoints[1].y = ybezorig + 2 * yunit; 	
   	controlpoints[2].x = xbezorig + 1 * xunit;
   	controlpoints[2].y = ybezorig + 1 * yunit;
   	controlpoints[3].x = xbezorig + 3 * xunit;
   	controlpoints[3].y = ybezorig;
   	
   	iconView->StrokeBezier(controlpoints, B_SOLID_HIGH);
   	
   	// .:: Quota raggio raccordo ::.
	
	xbezorig = x_origin + l_tot * 5 / 9;
	ybezorig = y_origin + h_tot / 4 - arcradius;
   	
   	float pigreco;
   	
   	pigreco = atan(1) * 4;
   	   	
	p1.x = xbezorig + 1.2 * xunit;
	p1.y = ybezorig + 1.8 * yunit;
	p2.x = p1.x + 2 * arcradius * cos(pigreco / 4);
	p2.y = p1.y - 2 * arcradius * sin(pigreco / 4);
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	
	// .:: Freccia quota raggio di raccordo ::.
	
	p2.x = p1.x + (-1 * largfreccie / 2 * cos(pigreco / 4) + largfreccie * 2 * sin(pigreco / 4));
	p2.y = p1.y + (-1 * largfreccie / 2 * sin(pigreco / 4) - largfreccie * 2 * cos(pigreco / 4));
	p3.x = p1.x + (largfreccie / 2 * cos(pigreco / 4) + largfreccie * 2 * sin(pigreco / 4));
	p3.y = p1.y + (largfreccie / 2 * sin(pigreco / 4) - largfreccie * 2 * cos(pigreco / 4));
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
   	
   	// .:: Testo quota raggio di raccordo ::.
   	
   	p2.x = p1.x + 2 * arcradius * cos(pigreco / 4);
   	p2.y = p1.y - arcradius / 2 * sin(pigreco / 4);
	
	iconView->MovePenTo(p2);
   	iconView->DrawString("r");
   	
   	// .:: Quota forza Sx ::.
   	
   	p1.x = x_origin - 3 * xunit;
	p1.y = y_origin + h_tot / 2;
	p2.x = x_origin - 8 * xunit;
	p2.y = y_origin + h_tot / 2;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
   	
   	p1.x = x_origin - 8 * xunit;
	p1.y = y_origin + h_tot / 2;
   	p2.x = p1.x + largfreccie * 2;
	p2.y = p1.y - largfreccie / 2;
	p3.x = p1.x + largfreccie * 2;
	p3.y = p1.y + largfreccie / 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	p1.x = x_origin - 11 / 2 * xunit;
	p1.y = y_origin + h_tot / 2 - yunit;
	
	iconView->MovePenTo(p1);
   	iconView->DrawString("P");
   	
   	// .:: Quota forza Dx ::.
   	
   	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45 + 3 * xunit;
	p1.y = y_origin + h_tot / 2;
	p2.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45 + 8 * xunit;
	p2.y = y_origin + h_tot / 2;
	
	iconView->StrokeLine(p1, p2, B_SOLID_HIGH);
   	
   	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45 + 8 * xunit;
	p1.y = y_origin + h_tot / 2;
   	p2.x = p1.x - largfreccie * 2;
	p2.y = p1.y - largfreccie / 2;
	p3.x = p1.x - largfreccie * 2;
	p3.y = p1.y + largfreccie / 2;
	
	iconView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
   	
   	p1.x = x_origin + l_tot * 5 / 9 + arcradius + l_tot * 14 / 45 + 11 / 2 * xunit;
	p1.y = y_origin + h_tot / 2 - yunit;
	
	iconView->MovePenTo(p1);
   	iconView->DrawString("P");
   	
   	// .:: Grafico ::.
   	
   	// Dimensioni della BView drawView 310 x 210 pixels
   	
	BView *drawView;
    drawView = (BView *)FindView("drawView");
         	
	drawView->SetHighColor(0, 0, 0);	
	
	p1.x = 30;
	p1.y = 0;
	p2.x = 30;
	p2.y = 200;
	
	drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
   	p2.x = p1.x - largfreccie / 2;
	p2.y = p1.y + largfreccie * 2;
	p3.x = p1.x + largfreccie / 2;
	p3.y = p1.y + largfreccie * 2;
	
	drawView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	p1.x = 30;
	p1.y = 200;
	p2.x = 310;
	p2.y = 200;
	
	drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	p1.x = 310;
	p1.y = 200;
	p2.x = p1.x - largfreccie * 2;
	p2.y = p1.y - largfreccie / 2;
	p3.x = p1.x - largfreccie * 2;
	p3.y = p1.y + largfreccie / 2;
	
	drawView->FillTriangle(p1, p2, p3, B_SOLID_HIGH);
	
	for (int i = 280; i > 0; i = i - 50)
	{
		p1.x = i;
		p1.y = 198;
		p2.x = i;
		p2.y = 202;
	
		drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
		
		p1.y = 210;
		
		float flxLabel;
		BString strxLabel;
		
		flxLabel = (i - 10) / 50 * 0.05;
    	strxLabel << (float)flxLabel;
    
		drawView->MovePenTo(p1);
   		drawView->DrawString(strxLabel.String());
		
	}
	
	for (int i = 200; i > 0; i = i - 25)
	{
		p1.x = 28;
		p1.y = i;
		p2.x = 32;
		p2.y = i;
	
		drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
		
		p1.x = 0;
		
		float flyLabel;
		BString stryLabel;
		
		flyLabel = (200 - i) / 25 * 0.5;
    	stryLabel << (float)flyLabel;
    
		drawView->MovePenTo(p1);
   		drawView->DrawString(stryLabel.String());
   		
	}
	
	p1.x = 10;
	p1.y = 10;
	
	drawView->MovePenTo(p1);
   	drawView->DrawString("Kt");
   	
   	p1.x = 157;
	p1.y = 210;
	
	drawView->MovePenTo(p1);
   	drawView->DrawString("r/d");

}

void CalcoloKtView::Calculate()
{

	BString txt1text;
	BString txt2text;
	BString kt_text;
	
	long double Kt;
	long double x;	// r/d
	long double D_d;	// D/d
	long double a;
	long double b;
	long double c;
    long double a1;
    long double b1;
    long double c1;
    
	txt1text << txt1->Text();
	txt2text << txt2->Text();
	
    x = atof(txt1text.String());
    D_d = atof(txt2text.String());
    
    if (!((x > 0) && (x <= 0.3)))
    {
    	BAlert *myAlert = new BAlert(ALERT_RD_TITLE, ALERT_RD_MESSAGE, ALERT_OK, NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
	  	myAlert->Go();
    	return;
    }
    
    if (!((D_d >= 1.01) && (D_d <= 3)))
    {
    	BAlert *myAlert = new BAlert(ALERT_DD_TITLE, ALERT_DD_MESSAGE, ALERT_OK, NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_WARNING_ALERT);
	  	myAlert->Go();
    	return;
    }
    
    
    if (D_d <= 1.05)
    {
    	a1 =	0.590823256;
    	b1 =	0.000625284;
    	
    	a = a1 + b1 / log(D_d);
    	
	}
	
	else
	{
		a1 =	0.806683239;
		b1 =	-0.010667756;
		c1 =	0.342511804;
		
		a = a1 + b1 * (D_d / log(D_d)) + c1 * (log(D_d) / D_d);
	}
	
    
    a1 =	-0.287595623;
    b1 =	-0.021137436;
    c1 =	0.001099864;
    
    b = a1 + b1 * D_d + c1 / log(D_d);
    
    
    if (D_d <= 1.05)
    {
    	a1 =	-1.585648431;
    	b1 =	0.003195393;
    	
    	c = a1 + b1 * (D_d / log(D_d));
    	
	}
	
	else
	{
		a1 =	37.11501602;
		b1 =	14.59448006;
		c1 =	-51.84367334;
		
		c = D_d / (a1 + b1 * D_d + c1 * sqrt(D_d));
				
	}
    
    
    Kt = a * pow(x, b) * pow((1-x), c);
       
    kt_text << "Kt : ";
    kt_text << (float)Kt;
    
    lbl1->SetText(kt_text.String());
 	
 	/*
 	kt_text.SetTo("");
 	kt_text << "D_d : ";
 	kt_text << (float)D_d;
 	kt_text << "a : ";
 	kt_text << (float)a;
 	kt_text << "; b : ";
 	kt_text << (float)b;
 	kt_text << "; c : ";
 	kt_text << (float)c;
 	
 	txt2->SetText(kt_text.String());
 	*/
 	
 	BView *drawView;
    drawView = (BView *)FindView("drawView");
         	
	drawView->SetHighColor(0, 200, 50);
	
	/*
	.:: Asse x (30, 200) - (310, 200) ::.
	.:: Asse y (30,   0) - ( 30, 200)::.
	*/
	
	BPoint p1, p2;
	
	p1.x = (310 - 30) * x / 0.28 + 30;
	p1.y = 200 - 200 * Kt / 4;
	p2.x = (310 - 30) * x / 0.28 + 30;
	p2.y = 200;
	
	drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	p1.x = (310 - 30) * x / 0.28 + 30;
	p1.y = 200 - 200 * Kt / 4;
	p2.x = 30;
	p2.y = 200 - 200 * Kt / 4;
	
	drawView->StrokeLine(p1, p2, B_SOLID_HIGH);
	
	drawView->SetHighColor(0, 0, 0);
	
	float xres;
	
	xres = 0.28 / (310 - 30 + 1);
	
	x = 1 * xres;
	p1.x = 1 + 30;
	p1.y = 200 - 200 * ( a * pow(x, b) * pow((1-x), c)) / 4;
	
	drawView->MovePenTo(p1);
	
	for (int i = 2; i <= 280; i++)
	{
		x = i * xres;
		p1.x = i + 30;
		p1.y = 200 - 200 * ( a * pow(x, b) * pow((1-x), c)) / 4;
		
		drawView->StrokeLine(p1, B_SOLID_HIGH);
	}
		
}
