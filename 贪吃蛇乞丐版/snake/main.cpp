#include<iostream>
#include"conio.h"
#include"map.h"
#include"Snake.h"
using namespace std;
int main() {
	map mymap;
	Snake s;
	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false; //���ؿ���̨���
	
	SetConsoleCursorInfo(handle, &CursorInfo);

	mymap.show();
	mymap.menu();
	while (s.live) {
		int old_len = s.getlength();
		s.show();
		if (old_len != s.getlength()) {
			mymap.change_score();
		}//���Լӷ���

		Sleep(100);
	}
	if (!s.live) {
		system("color 3");
		std::cout << "game over" << std::endl;
	}
	system("pause");
	return 0;
}