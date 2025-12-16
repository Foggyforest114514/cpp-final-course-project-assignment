#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Object.h"
#include <string>
class TextBox :public Object{
public:
	TextBox(int, int, int, int);
	void draw();
	void setText(std::string s){ text = s; }
private:
	int width;
	int height;
	std::string text;
};

#endif