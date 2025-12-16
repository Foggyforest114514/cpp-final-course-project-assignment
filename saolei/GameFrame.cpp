
#include "stdafx.h"
#include "GameFrame.h"
#include <random>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;
void GameFrame::init()
{
	initgraph(400, 600,2);
	setbkcolor(RGB(224,212,227));
	cleardevice();
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			items[j][i].ClickBack();
			items[j][i].FlagBack();
			items[j][i].BoomBack();
		}
	}
	/*随机生成十个地雷*/
	default_random_engine a;
	a.seed(time(0));
	uniform_int_distribution<int> b(0, 7);
	uniform_int_distribution<int> c(0, 5);
	int count = 0;
	while (count < 10)
	{
		int row = b(a);
		int col = c(a);
		if (!items[row][col].boom())
		{
			items[row][col].setBoom();
			count++;
		}
	}
	
	/*for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (items[j][i].boom())
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}*///测试代码
	getNum();
	/*cout << endl;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << items[j][i].getNum()<<" ";
		}
		cout << endl;
	}*/
	textbox.setText("游戏中。。。");
	draw();

}
GameFrame::GameFrame() :Alive(true), End(false), btn1(Button(230, 460, 120, 60, "游戏结束")), btn2(Button(50, 460, 120, 60, "重新开始")), textbox(TextBox(50,530,300,30))
{
	for (int j = 0; j < 8; j++)
	{
		vector<Item> tmp;
		for (int i = 0; i < 6; i++)
		{
			tmp.push_back(Item(i*50+50, j*50+50));
		}
		items.push_back(tmp);
	}//初始化所有方格
	GameFrame::init();
}
void GameFrame::draw()
{
	/*画格子*/
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			items[j][i].draw();
		}
	}
	btn1.draw();
	btn2.draw();
	textbox.draw();
}
void GameFrame::run()
{
	End = false;
	Alive = true;
	bool tmp1 = false;
	bool tmp2 = false;
	while (!End)
	{
		isEnd();
		BeginBatchDraw();
		cleardevice();
		draw();
		EndBatchDraw();//双缓冲
		while (peekmessage(&msg, 1))//(peekmessage(&msg, EM_MOUSE))
		{
			onLMsg();
			onRMsg();
			tmp1 = onEndBtnMsg();
			tmp2 = onReBtnMsg();
		}
		
		Sleep(50);
	}
	if (tmp1||tmp2)
		return;
	Gameover();

	
	//getchar();
}

void GameFrame::getNum()
{
	int tmp;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			tmp = 0;
			if (i>0 && items[j][i - 1].boom())
				tmp++;
			if (i < 5 && items[j][i + 1].boom())
				tmp++;
			if (j>0 && items[j - 1][i].boom())
				tmp++;
			if (j < 7 && items[j + 1][i].boom())
				tmp++;
			if (i>0 && j > 0 && items[j - 1][i - 1].boom())
				tmp++;
			if (i > 0 && j < 7 && items[j + 1][i - 1].boom())
				tmp++;
			if (i<5 && j>0 && items[j - 1][i + 1].boom())
				tmp++;
			if (i < 5 && j < 7 && items[j + 1][i + 1].boom())
				tmp++;
			items[j][i].setNum(tmp);
		} 
	}
}
void GameFrame::onLMsg()
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 6; i++)
			{
				if (msg.x > items[j][i].getX() && msg.x<items[j][i].getX() + 50 && msg.y > items[j][i].getY() && msg.y < items[j][i].getY() + 50)
				{
					if (!items[j][i].getClick())
						items[j][i].setClick();
					if (items[j][i].boom()&&!items[j][i].getFlag())
						Alive = false;
					clearzero(j, i);
				}
			}
		}
	}

}
void GameFrame::onRMsg()
{
	if (msg.message == WM_RBUTTONDOWN)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 6; i++)
			{
				if (msg.x > items[j][i].getX() && msg.x<items[j][i].getX() + 50 && msg.y > items[j][i].getY() && msg.y < items[j][i].getY() + 50)
				{
					if (!items[j][i].getClick()&&!items[j][i].getFlag())
					{
						items[j][i].setClick();
						items[j][i].setFlag();
					}
					else if (items[j][i].getFlag())
					{
						items[j][i].ClickBack();
						items[j][i].FlagBack();
					}
				}
			}
		}
	}
}
void GameFrame::clearzero(int row,int col)
{
	items[row][col].setClick();
	if (items[row][col].getNum() != 0 || items[row][col].boom())
		return;
	if (row > 0){
		
		if (items[row - 1][col].getNum() == 0 && !items[row - 1][col].getClick())
			clearzero(row - 1, col);
		items[row - 1][col].setClick();
	}
	if (col > 0){
		
		if (items[row][col - 1].getNum() == 0 && !items[row][col - 1].getClick())
			clearzero(row, col-1);
		items[row][col-1].setClick();
	}
	if (row < 7){
		
		if (items[row + 1][col].getNum() == 0 && !items[row + 1][col].getClick())
			clearzero(row + 1, col);
		items[row +1][col].setClick();
	}
	if (col <5){
		
		if (items[row][col + 1].getNum() == 0 && !items[row][col + 1].getClick())
			clearzero(row, col+1);
		items[row][col+1].setClick();
	}
	if (row>0&&col>0){

		if (items[row - 1][col - 1].getNum() == 0 && !items[row - 1][col - 1].getClick())
			clearzero(row - 1, col - 1);
		items[row - 1][col - 1].setClick();
	}
	if (row<7&&col<5){

		if (items[row+1][col + 1].getNum() == 0 && !items[row+1][col + 1].getClick())
			clearzero(row+1, col + 1);
		items[row+1][col + 1].setClick();
	}
	if (row>0&&col <5){

		if (items[row-1][col + 1].getNum() == 0 && !items[row-1][col + 1].getClick())
			clearzero(row-1, col + 1);
		items[row-1][col + 1].setClick();
	}
	if (row<7&&col>0){

		if (items[row+1][col - 1].getNum() == 0 && !items[row+1][col - 1].getClick())
			clearzero(row+1, col - 1);
		items[row+1][col - 1].setClick();
	}
}
void GameFrame::isEnd()
{
	if (!Alive)
	{
		End = true;
		return;
	}
	int count = 0;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (items[j][i].getClick()&&!items[j][i].boom())
				count++;
		}
	}
	if (count == 38)
		End = true;
}
void GameFrame::Gameover()
{
	if (!Alive)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 6; i++)
			{
				if (items[j][i].boom())
					items[j][i].setClick();
			}
		}
		textbox.setText("你失败了！");
		draw();
	}
	else {
		textbox.setText("游戏结束，你获胜了！");
		draw();
	}
}
bool GameFrame::onEndBtnMsg()
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		if (msg.x > btn1.getX() && msg.x<btn1.getX() + btn1.getWid() && msg.y>btn1.getY() && msg.y < btn1.getY() + btn1.getHei())
		{
			End = true;
			exit(0);
			//closegraph();
			return true;
		}
	}
	return false;
}
bool GameFrame::onReBtnMsg()
{
	if (msg.message == WM_LBUTTONDOWN)
	{
		if (msg.x > btn2.getX() && msg.x<btn2.getX() + btn2.getWid() && msg.y>btn2.getY() && msg.y < btn2.getY() + btn2.getHei())
		{
			End = true;
			init();
			run();
			return true;
		}
	}
	return false;

}
void GameFrame::gamelaunch()
{
	run();
	while (true)
	{
		bool close = false;
		bool restart = false;
		while (peekmessage(&msg,1))//(peekmessage(&msg, EM_MOUSE))
		{
			close = onEndBtnMsg();
			restart = onReBtnMsg();
		}
		if (close)
			break;
	}
}