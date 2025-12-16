#include "Button.h"
#include <easyx.h>
#include <cstring>
using namespace std;

Button::Button(int mx, int my, int wid, int hei,string s) :Object(mx, my), width(wid), height(hei), text(s){}

void Button::draw()
{
	setlinecolor(BLACK);
	setfillcolor(RGB(146, 138, 148));
	fillrectangle(x, y, x + width, y + height);
	settextstyle(30, 0, TEXT("ËÎÌו"));
	setbkmode(TRANSPARENT);
	char t[100];
	strcpy(t, text.c_str());
	int hs = (width - textwidth(t)) / 2;
	int vs = (height - textheight(t)) / 2;
	outtextxy(x + hs, y + vs, t);

}