#include"map.h"
//��ͼ��ܱ��
map::map() {
	score = 0;
}
//����ʳ��

//��ʾ��ͼ
void map::show() {
	for (int y = 1; y <=25; y++) {//y
		for (int x=1; x <=35; x++) {//x

			if (x == 35) {
				std::cout <<'*'<< std::endl;
			}
			else if (y==1||x==1||y==25) {
				std::cout << '*';
			}//�߽�
			else{
				std::cout << ' ';
			}
		}
	}
}
//��ʾ����
void map::menu() {
	HANDLE hout;
	COORD coord;
	coord.X = 50;
	coord.Y = 5;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	std::cout << "��Ϸ����" << std::endl;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "1.ͨ��w,a,s,d�����ߵ��ƶ�����" << std::endl;;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "2.�߲���ײ������ͱ߽�"<<std::endl;
		coord.Y += 1;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "3.ͨ���ƶ��ߵ�����ʳ������ǵ÷�����ͬʱ������䳤" << std::endl;
		coord.Y += 6;
		coord.X += 5;
		SetConsoleCursorPosition(hout, coord);
		std::cout << "�÷�:0" << std::endl;
	
}
void map::change_score() {
	score++;
	HANDLE hout;
	COORD coord;
	coord.X = 55;
	coord.Y = 14;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	std::cout << "�÷�:";
	std::cout << std::setw(4) << score << std::endl;


}