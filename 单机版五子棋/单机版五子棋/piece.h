#pragma once
#include<graphics.h>
#include<vector>
#include<algorithm>
using namespace std;
class Piece {
public:
	Piece();
	void show();
	int getcoord();
	int judge();
	int sub_judge(int i, int j, int flag);
private:
	int res[16][16];
	vector<pair<int, int>> book;//记录棋盘信息
	int x, y;
	int flag;//颜色0为黑，1为白
};

Piece::Piece(){
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 15; j++) {
			res[i][j] = -1;
		}
	}
	flag = 0;
}

//根据用户点击获取棋子中心点
int Piece::getcoord() {
	FlushMouseMsgBuffer();
	const int w = 40;
	int t_x=0, t_y=0;
	MOUSEMSG m;
	while(true){
		m=GetMouseMsg();//获取鼠标信
		if (m.mkLButton == true) {
			break;
		}
	}
	int temp_x = m.x;
	int temp_y = m.y;
	//这里获取的是点击的店，不能作为棋子中心点，需要进行计算。
	//棋子的中心点一定是直线的交叉点中。
	int i,sum=0;
	for ( i = 1; i <=15;i++) {
		if (abs(i*w - temp_x) <= 15) {
			t_x = i*w;
			sum++;
		}
	}
	for (int i = 1; i <= 15; i++) {
		if (abs(i*w - temp_y) <= 15) {
			t_y = i*w;
			sum++;
		}
	}
	if (sum == 2) {
		x = t_x;
		y = t_y;
	}
	else {
		return -1;
	}
	//判断该位置是否已经有棋子了
	if (find(book.begin(), book.end(), pair<int, int>(x, y)) != book.end()) {
		return -1;
	}//已经存在
	return 0;
}
//给定坐标显示棋子,坐标通过鼠标点击计算
void Piece::show() {
	res[x / 40][y / 40] = flag;//标记黑白棋子
	if (flag== 0) {
		setfillcolor(BLACK);//黑子
		flag = 1;
	}
	else {
		setfillcolor(WHITE);//白子
		flag = 0;
	}
	fillcircle(this->x, this->y, 20);

	FlushMouseMsgBuffer();
	book.push_back(pair<int, int>(x, y));
	
}

//判断胜负

int Piece::judge() {
	
	for (int i = 1; i <= 15; i++) {
		for (int j = 0; j <= 15; j++) {
			for (int m = 1; m <= 6; m++) {
				int ret=sub_judge(i,j,m);
				if (ret != -1) {
					return ret;
				}
			}
		}
	}
	return -1;
}



int Piece::sub_judge(int i, int j, int f) {
	int temp_x, temp_y, sum = 1;
	for (int m = 1; m <= 4; m++) {
		switch (f) {
			case 1:
				temp_x = i + m;
				temp_y = j;
				break;
			case 2:
				temp_x = i-m;
				temp_y = j;
				break;
			case 3:
				temp_x = i;
				temp_y = j+m;
				break;
			case 4:
				temp_x = i;
				temp_y = j-m;
				break;
			case 5:
				temp_x = i + m;
				temp_y = j + m;
				break;
			case 6:
				temp_x = i + m;
				temp_y = j - m;
				break;
		}
		
		if (temp_x < 1 || temp_y < 1 || temp_x>15 || temp_y>15) {
			continue;//出界了
		}
		if (res[i][j] == res[temp_x][temp_y]) {
			sum++;
		}
	}//左横
	if (sum == 5) {
		//如何设置成功后的动作

		return res[i][j];//赢了
	}
	else {
		return -1;
	}
}