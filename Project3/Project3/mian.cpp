#include<iostream>
using namespace std;
#include"creat.h"
#include"Graph.h"

int main() {
	cout << "请输入路由器总数：";
	int i;
	cin >> i;
	Graph c;
	c.getc()->getGraph()->setsize(i);
	c.getc()->ArrayGraph_create();
	while (1) {

		cout << "1.显示矩阵";
		cout << "              ";
		cout << "2.添加路由器 ";
		cout << endl;
		cout << "3.删除路由器";
		cout << "            ";
		cout << "4.增加路由器之间的链接";
		cout << endl;
		cout << "5.删除路由器之间的链接";
		cout << "  ";
		cout << "6.查询路由器的路由表：";
		cout << endl;
		cout << "7.退出系统";
		cout << endl;
		cout << "请输入想要进行的操作：";
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
				cout << "请输入路由器名称：";
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
			cout << "输入错误操作，请重新输入！" << endl;
		}
	}
	return 0;
}