#include<iostream>
using namespace std;
#include"creat.h"
#include"Graph.h"

int main() {
	cout << "������·����������";
	int i;
	cin >> i;
	Graph c;
	c.getc()->getGraph()->setsize(i);
	c.getc()->ArrayGraph_create();
	while (1) {

		cout << "1.��ʾ����";
		cout << "              ";
		cout << "2.���·���� ";
		cout << endl;
		cout << "3.ɾ��·����";
		cout << "            ";
		cout << "4.����·����֮�������";
		cout << endl;
		cout << "5.ɾ��·����֮�������";
		cout << "  ";
		cout << "6.��ѯ·������·�ɱ�";
		cout << endl;
		cout << "7.�˳�ϵͳ";
		cout << endl;
		cout << "��������Ҫ���еĲ�����";
		int sign;
		cin >> sign;
		if (0 < sign && sign < 7) {
			switch (sign) {
			case 1: {
				c.getc()->ArrayGraph_show();
				break;
			}
			case 2: {
				c.getc()->ArrayGraph_add();
				break;
			}
			case 3: {
				c.getc()->ArrayGraph_del_v();
				break;
			}
			case 4: {
				c.getc()->ArrayGraph_insert();
				break;
			}
			case 5: {
				c.getc()->ArrayGraph_del();
				break;
			}
			case 6: {
				cout << "������·�������ƣ�";
				int number;
				cin >> number;
				int a;
				a = c.getc()->getGraph()->search(number);
				c.dijkstra(a);
				break;
			}
			}

		}
		else if (sign == 7)
			break;
		else {
			cout << "���������������������룡" << endl;
		}
	}
	return 0;
}