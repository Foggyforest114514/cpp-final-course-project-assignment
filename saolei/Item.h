#pragma once
#include <easyx.h>
#include "Object.h"

class Item:public Object{
public:
	Item(int,int);
	void draw();//画格子
	void setBoom(){ isBoom = true;}//设置格子为地雷
	bool boom(){ return isBoom; }//判断格子是否是地雷
	void BoomBack(){ isBoom = false; }
	void setNum(int n){ num = n;}//设置格子数字
	void setClick(){ isClick = true; }//设置格子已经被点击
	bool getClick(){ return isClick; }//获得格子点击状态
	void ClickBack(){ isClick = false; }//设置格子未被点击
	void setFlag(){ isFlag = true; }//设置格子被插上旗子
	bool getFlag(){ return isFlag; }//获得格子旗子状态
	void FlagBack(){ isFlag = false; }//设置格子为被插旗
	int getNum(){ return num; }//返回格子数字
	void setImage();
	//int getX(){ return x; }//获得格子坐标
	//int getY(){ return y; }
private:
	
	//int x;//横坐标
	//int y;//纵坐标
	int num;
	bool isBoom;//是否是雷
	bool isFlag;//是否已经插上旗子
	bool isClick;//是否已经被点击
	const COLORREF Co_click;//点击后颜色
	IMAGE img;
};