#include"map.h"
//地图框架标记
map::map() {
	score = 0;
}
//产生食物

//显示地图
void map::show() {
	for (int y = 1; y <=25; y++) {//y
		for (int x=1; x <=35; x++) {//x

			if (x == 35) {
				std::cout <<'*'<< std::endl;
			}
			else if (y==1||x==1||y==25) {
				std::cout << '*';
			}//边界
			else{
				std::cout << ' ';
			}
		}
	}
}
//显示规则
void map::menu() {
	HANDLE hout;
	COORD coord;
	coord.X = 50;
	coord.Y = 5;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	std::cout << "游戏规则" << std::endl;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "1.通过w,a,s,d控制蛇的移动方向" << std::endl;;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "2.蛇不能撞到蛇身和边界"<<std::endl;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "3.通过移动蛇的来吃食物可以是得分增加同时蛇身将会变长" << std::endl;
		coord.Y += 6;
		coord.X += 5;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "得分:0" << std::endl;
	
}
void map::change_score() {
	score++;
	HANDLE hout;
	COORD coord;
	coord.X = 55;
	coord.Y = 14;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	std::cout << "得分:";
	std::cout << std::setw(4) << score << std::endl;


}