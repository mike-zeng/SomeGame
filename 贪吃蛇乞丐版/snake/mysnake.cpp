#include"Snake.h"
//初始化蛇，标记蛇的起始位置和长度
Snake::Snake() {
	live = true;
	direct.first = 0;
	direct.second = 1;
	length = 1;
	head.first = 6;
	head.second = 5;
	body.push_back(head);
	creat_food();
}

//打印蛇的身体
void Snake::show() {
	HANDLE hout;
	COORD coord;

	coord.X = 0;
	coord.Y = 0;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition(hout, coord);

	system("color 2");
	std::pair<int, int> pos(0, 0);
	for (int y =1; y<= 25; y++) {
		for (int x = 1; x <= 35; x++) {

		
			
			if(x==1 || x == 35 || y == 1 || y == 25) {
				coord.X += 1;
				if (x == 35) {
					coord.X = 0;
					coord.Y += 1;
				}
				SetConsoleCursorPosition(hout, coord);
				continue;
			}//遇到边界只移动光标，不进行打印，只打印蛇
			else if (x == food.first&&y == food.second) {
				std::cout << "*";
				continue;
			}//遇到食物，进行打印
			
			pos.first = x;
			pos.second = y;
			if (std::find(body.begin(), body.end(), pos) != body.end()) {
				std::cout << "*";
			}//找到蛇的位置
			else {
				std::cout << ' ';
			}
		}
	}//每次显示后，进行一个单位的移动
	move();
}
int Snake::getlength() {
	return length;
}
//移动蛇的位置
void Snake::move() {
	set_direct();
	int cur;
	if (body[body.size() - 1].first + direct.first == food.first&&
		body[body.size() - 1].second + direct.second == food.second) {
		head.first = body[body.size() - 1].first + direct.first;
		head.second = body[body.size() - 1].second + direct.second;
		body.push_back(head);
		length++;
		creat_food();
	}//可以吃到食物,将食物作为自己的头重新走


	for (cur = 0; cur != (body.size()-1) ; cur++) {
		body[cur].first = body[cur + 1].first;
		body[cur].second = body[cur + 1].second;
	}

	body[cur].first += direct.first;
	body[cur].second += direct.second;//得到新的头
	head = body[cur];
	std::vector<std::pair<int,int>>::iterator it = std::find(body.begin(), body.end(), head);
	if (it!=body.end()&&++it!=body.end()) {
		live = false;
	}//撞到自己了
	
	if (head.first == 1 || head.first == 35 || head.second == 1 || head.second == 25) {
		live = false;
	}//撞到墙上了
	

}


//随机产生范围内的食物
void Snake::creat_food() {
	do {
		srand((int)time(NULL));
		food.first=abs(rand()) % 33+2;
		srand((int)time(NULL));
		food.second=abs(rand()) % 23+2;
	} while (std::find(body.begin(), body.end(), food) != body.end());//食物不在蛇上则继续
	//食物不能出现在蛇的位置和便捷上
	//std::cout << food.first <<" "<< food.second<<std::endl;
}

//设置方向
void Snake::set_direct() {
	//设计另一个进程用来计算时间，如果到达时间，则结束函数

	char ch = '0';//默认值
	if (_kbhit()) {
		ch = _getch();
		switch (ch) {
		case 'w':
			direct.first = 0;
			direct.second = -1;
			break;
		case 's':
			direct.first = 0;
			direct.second = 1;
			break;
		case 'a':
			direct.first = -1;
			direct.second = 0;
			break;
		case 'd':
			direct.first = 1;
			direct.second = 0;
			break;
		}
	}
}