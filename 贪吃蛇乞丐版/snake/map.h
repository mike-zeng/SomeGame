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
	void show();//��ʾ��ͼ��ʳ��
	void map::menu();
	void change_score();
private:
	int score;
};
