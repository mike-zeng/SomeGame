#include<iostream>
#include"piece.h"
#include"map.h"
using namespace std;
int main() {

flag:Map *m=new Map;//��ӡ��ͼ
	Piece *p=new Piece;//��������
	int ret;
	while (true) {
		while (true) {
			if (p->getcoord() == 0) {
				break;
			}
		}//���ϻ�ȡ�����
		p->show();//����һ��
		ret=p->judge();//�ж��Ƿ����
		if (ret != -1) {
			break;//��Ϸ����
		}
	}
	//��ʾʤ�����
	m->showRes(ret);
	//ѡ������һ�ֻ���ֱ���˳�
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
