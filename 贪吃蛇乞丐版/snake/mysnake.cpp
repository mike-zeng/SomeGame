#include"Snake.h"
//��ʼ���ߣ�����ߵ���ʼλ�úͳ���
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

//��ӡ�ߵ�����
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
			}//�����߽�ֻ�ƶ���꣬�����д�ӡ��ֻ��ӡ��
			else if (x == food.first&&y == food.second) {
				std::cout << "*";
				continue;
			}//����ʳ����д�ӡ
			
			pos.first = x;
			pos.second = y;
			if (std::find(body.begin(), body.end(), pos) != body.end()) {
				std::cout << "*";
			}//�ҵ��ߵ�λ��
			else {
				std::cout << ' ';
			}
		}
	}//ÿ����ʾ�󣬽���һ����λ���ƶ�
	move();
}
int Snake::getlength() {
	return length;
}
//�ƶ��ߵ�λ��
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
	}//���ԳԵ�ʳ��,��ʳ����Ϊ�Լ���ͷ������


	for (cur = 0; cur != (body.size()-1) ; cur++) {
		body[cur].first = body[cur + 1].first;
		body[cur].second = body[cur + 1].second;
	}

	body[cur].first += direct.first;
	body[cur].second += direct.second;//�õ��µ�ͷ
	head = body[cur];
	std::vector<std::pair<int,int>>::iterator it = std::find(body.begin(), body.end(), head);
	if (it!=body.end()&&++it!=body.end()) {
		live = false;
	}//ײ���Լ���
	
	if (head.first == 1 || head.first == 35 || head.second == 1 || head.second == 25) {
		live = false;
	}//ײ��ǽ����
	

}


//���������Χ�ڵ�ʳ��
void Snake::creat_food() {
	do {
		srand((int)time(NULL));
		food.first=abs(rand()) % 33+2;
		srand((int)time(NULL));
		food.second=abs(rand()) % 23+2;
	} while (std::find(body.begin(), body.end(), food) != body.end());//ʳ�ﲻ�����������
	//ʳ�ﲻ�ܳ������ߵ�λ�úͱ����
	//std::cout << food.first <<" "<< food.second<<std::endl;
}

//���÷���
void Snake::set_direct() {
	//�����һ��������������ʱ�䣬�������ʱ�䣬���������

	char ch = '0';//Ĭ��ֵ
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