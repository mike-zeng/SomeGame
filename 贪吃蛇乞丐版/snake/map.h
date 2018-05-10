#pragma once
#include<iostream>
#include"Snake.h"
#include<Windows.h>
#include<ctime>
#include<cstdlib>
#include <iomanip>
class map {
public:
	map();
	void show();//显示地图和食物
	void map::menu();
	void change_score();
private:
	int score;
};
