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
	void move();//Ĭ�ϲ����з���任
	void creat_food();
	int getlength();
	void set_direct();
private:
	int length;
	int flag;//1,2,3,4���������� �ϣ��£�����
	std::vector<std::pair<int, int>> body;
	std::pair<int, int> direct;
	std::pair<int, int> head,food;//����ͷ��
public:
	bool live;
};
