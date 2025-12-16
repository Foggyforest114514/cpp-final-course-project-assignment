#pragma once
#include <easyx.h>
#include <vector>
#include "Item.h"
#include "Button.h"
#include "TextBox.h"
class GameFrame
{
public:
	GameFrame();
	void gamelaunch();//游戏启动
	void init();//初始化界面
	void draw();//画界面
	void run();//游戏运行
	void Gameover();//游戏结束
	void isEnd();//判断游戏结束
private:
	void onLMsg();//处理左键点击格子信息
	void onRMsg();//处理右键点击格子信息
	bool onEndBtnMsg();//处理左键点击结束信息
	bool onReBtnMsg();//处理左键点击重新开始信息
	void getNum();//计算每个格子数字
	void clearzero(int row,int col);//格子为0时，清楚周围的0格子
	std::vector<std::vector<Item>> items;//存储方格
	bool Alive;//判断是否触雷
	bool End;//判断游戏是否结束
	ExMessage msg;//存储信息

	Button btn1;//游戏结束按钮
	Button btn2;//重新开始按钮
	TextBox textbox;//文本框
};