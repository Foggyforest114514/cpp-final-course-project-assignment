#include "TextBox.h"
#include <easyx.h>
#include <cstring>
using namespace std;

TextBox::TextBox(int mx, int my, int wid, int hei) :Object(mx, my), width(wid), height(hei), text(""){}

void TextBox::draw()
{
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(x, y, x + width, y + height);
	char t[100];
	strcpy(t, text.c_str());
	settextstyle(28, 0, TEXT("ËÎÌו"));
	outtextxy(x + 3, y + 3, t);
}