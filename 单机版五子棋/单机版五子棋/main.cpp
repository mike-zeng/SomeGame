#include<iostream>
#include"piece.h"
#include"map.h"
using namespace std;
int main() {

flag:Map *m=new Map;//打印地图
	Piece *p=new Piece;//创建棋子
	int ret;
	while (true) {
		while (true) {
			if (p->getcoord() == 0) {
				break;
			}
		}//不断获取鼠标点击
		p->show();//下了一棋
		ret=p->judge();//判断是否结束
		if (ret != -1) {
			break;//游戏结束
		}
	}
	//显示胜负情况
	m->showRes(ret);
	//选择再来一局或者直接退出
	ret=m->chose();
	delete m;
	delete p;
	if (ret == 1) {
		goto flag;
	}
	else {
		return 0;
	}
}
