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
	vector<pair<int, int>> book;//��¼������Ϣ
	int x, y;
	int flag;//��ɫ0Ϊ�ڣ�1Ϊ��
};

Piece::Piece(){
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 15; j++) {
			res[i][j] = -1;
		}
	}
	flag = 0;
}

//�����û������ȡ�������ĵ�
int Piece::getcoord() {
	FlushMouseMsgBuffer();
	const int w = 40;
	int t_x=0, t_y=0;
	MOUSEMSG m;
	while(true){
		m=GetMouseMsg();//��ȡ�����
		if (m.mkLButton == true) {
			break;
		}
	}
	int temp_x = m.x;
	int temp_y = m.y;
	//�����ȡ���ǵ���ĵ꣬������Ϊ�������ĵ㣬��Ҫ���м��㡣
	//���ӵ����ĵ�һ����ֱ�ߵĽ�����С�
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
	//�жϸ�λ���Ƿ��Ѿ���������
	if (find(book.begin(), book.end(), pair<int, int>(x, y)) != book.end()) {
		return -1;
	}//�Ѿ�����
	return 0;
}
//����������ʾ����,����ͨ�����������
void Piece::show() {
	res[x / 40][y / 40] = flag;//��Ǻڰ�����
	if (flag== 0) {
		setfillcolor(BLACK);//����
		flag = 1;
	}
	else {
		setfillcolor(WHITE);//����
		flag = 0;
	}
	fillcircle(this->x, this->y, 20);

	FlushMouseMsgBuffer();
	book.push_back(pair<int, int>(x, y));
	
}

//�ж�ʤ��

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
			continue;//������
		}
		if (res[i][j] == res[temp_x][temp_y]) {
			sum++;
		}
	}//���
	if (sum == 5) {
		//������óɹ���Ķ���

		return res[i][j];//Ӯ��
	}
	else {
		return -1;
	}
}