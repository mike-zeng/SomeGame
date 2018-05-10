#pragma once
#include<iostream>
#include<Windows.h>
#include<ctime>
#include"conio.h"
#include<cstdlib>
#include<vector>
class Snake {
public:
	Snake();
	void show();
	void move();//默认不进行方向变换
	void creat_food();
	int getlength();
	void set_direct();
private:
	int length;
	int flag;//1,2,3,4，，，方向 上，下，左，右
	std::vector<std::pair<int, int>> body;
	std::pair<int, int> direct;
	std::pair<int, int> head,food;//定义头部
public:
	bool live;
};
