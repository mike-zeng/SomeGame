#pragma once
#include<graphics.h>

class Map {
public:
	Map();
	void Print(int x,int y,int wedth);
	void showRes(int ret);
	int chose();
private:
};



Map::Map() {
	initgraph(640, 640);
	setbkcolor(BROWN);
	cleardevice();
	Print(40,40,40);
	//�滭����
}
void Map::Print(int x, int y, int width) {
	for (int i = 0; i < 15; i++) {
		line(x, y + i * width, x + 560, y + i * width);
		line(x + i * width, y, x + i * width, y + 560);
	}//���̻���
	setfillcolor(BLACK);

	for (int i = 1; i <= 3; i++) {
		fillcircle(x+3*width,y+width*(4*i-1), 5);
		fillcircle(x +7*width, y + width*(4 * i - 1), 5);
		fillcircle(x + 11 * width, y + width*(4 * i - 1), 5);
	}//����
}


//չʾ���
void Map::showRes(int ret) {
	setbkcolor(BROWN);
	cleardevice();
	if (ret == 0) {
		settextcolor(BLACK);
		settextstyle(80, 80, _T("����"));
		outtextxy(80, 100, _T("�ڷ�ʤ"));
	}//��ʤ
	else {
		settextcolor(WHITE);
		settextstyle(80, 80, _T("����"));
		outtextxy(80, 100, _T("�׷�ʤ"));
	}
}

int Map::chose() {
	FlushMouseMsgBuffer();
	int t_x, t_y;
	MOUSEMSG m;

	settextcolor(BLACK);
	settextstyle(40, 40, _T("����"));
	outtextxy(160, 380, _T("����һ��"));

	settextcolor(BLACK);
	settextstyle(40, 40, _T("����"));
	outtextxy(160, 450, _T("�˳���Ϸ"));

	while (true) {
		m= GetMouseMsg();//��ȡ�����
		if (m.mkLButton == true) {
			t_x = m.x;
			t_y = m.y;

			if (t_x >= 160 && t_x <= 320 && t_y >= 380 && t_y <= 420) {
				return 1;
			}
			else if (t_x >= 160 && t_x <= 320 && t_y >= 450 && t_y <= 490) {
				return 2;
			}
		}//�ɹ����
	}
}
