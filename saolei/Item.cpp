#include "Item.h"

Item::Item(int mx, int my) :Object(mx,my), isBoom(false), isClick(false), isFlag(false), Co_click(LIGHTBLUE), num(0),img(50,50){}
void Item::draw()
{
	setImage();
	settextcolor(BLACK);
	settextstyle(50, 0,TEXT("Î¢ÈíÑÅºÚ"));
	setbkmode(TRANSPARENT);
	if (!isClick){
		putimage(x, y, &img);
	}
	else if (isFlag){
		putimage(x, y, &img);
	}
	else if (isBoom){
		putimage(x, y, &img);
	}
	else {
		setfillcolor(Co_click);
		fillrectangle(x, y, x + 50, y + 50);
		if (num != 0)
			outtextxy(x + 15, y , num + '0');
	}
	
	
}
void Item::setImage()
{
	
	if (isFlag)
	{
		loadimage(&img, "../img/ÆìÖÄ.jpg",48,48);
	}
	else if (isBoom&&isClick)
	{
		loadimage(&img, "../img/µØÀ×.jpg",48,48);
	}
	else if (!isClick)
	{
		loadimage(&img, "../img/ÆÕÍ¨¸ñ×Ó.jpg", 48, 48);
	}
}
