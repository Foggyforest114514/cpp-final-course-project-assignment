#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"
#include <string>
class Button :public Object{
public:
	Button(int, int,int,int,std::string);
	void draw();
	int getWid(){ return width; }
	int getHei(){ return height; }
private:
	std::string text;
	int width;
	int height;
};
#endif