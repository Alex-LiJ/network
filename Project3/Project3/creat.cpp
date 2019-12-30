
#include<fstream>
#include "creat.h"
using namespace std;


void creat::ArrayGraph_add()//添加顶点
{
	int n = m.getsize();
	m.setsize(n + 1);
	sever a;
	a.number = (n + 1);
	cout << "请输入服务器名：";
	cin >> a.name;
	cout << endl;
	cout << "请输入服务器ip:";
	cin >> a.ip;
	m.vertexArr[m.getsize() - 1] = a;

	for (int i = 0; i < m.getsize(); ++i)
	{
		if (i != m.getsize() - 1) {
			cout << "若服务器" << a.name << "有和服务器" << m.vertexArr[i].name << "之间相连接，则输入连接=线路的权值，否则输入0" << endl;
			cin >> m.arcArr[m.getsize() - 1][i];
			if (m.arcArr[m.getsize() - 1][i] == 0)
				m.arcArr[m.getsize() - 1][i] = maxWeight;
			m.arcArr[i][m.getsize() - 1] = m.arcArr[m.getsize() - 1][i];
		}
	}
	ofstream file;
	ofstream nodefile;
	file.open("edge.txt");
	nodefile.open("node.txt");
	for (int i = 0; i < m.getsize(); i++) {           //写入顶点数据

		nodefile << m.vertexArr[i].number << " " << m.vertexArr[i].name << " " << m.vertexArr[i].ip << endl;

	}
	for (int i = 0; i < m.getsize(); i++) {            //写入边数据
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	nodefile.close();
	file.close();
}

void creat::ArrayGraph_del_v() {   //删除顶点
	cout << "你想删除哪个路由器？" << endl;
	int a;
	cin >> a;
	cout << endl;
	int n = m.search(a) - 1;
	int i, j;
	if (n < 0 || n >= m.getsize()) {
		cout << "输入错误，链路内没有您要删除的路由器" << endl;
		exit(0);
	}
	else {
		for (int h = 0; h < m.getsize(); h++) {
			if (a == m.vertexArr[h].name) {
				for (i = n; i < m.getsize(); i++) {
					for (j = 0; j < m.getsize(); j++) {
						m.arcArr[j][i] = m.arcArr[j][i + 1];
					}
				}

				for (i = n; i < m.getsize(); i++) {
					for (j = 0; j < m.getsize(); j++) {
						m.arcArr[i][j] = m.arcArr[i + 1][j];
					}
				}
				for (i = 0; i < m.getsize(); i++) {
					m.arcArr[m.getsize()][i] = 0;
				}
				for (i = 0; i < m.getsize(); i++) {
					m.arcArr[i][m.getsize()] = 0;
				}
				for (i = n; i < m.getsize(); i++) {
					m.vertexArr[i] = m.vertexArr[i + 1];
					m.vertexArr[i].number = m.vertexArr[i].number - 1;
				}
				sever origin;
				origin.number = 0;
				for (int i = 0; i < 20; i++)
					origin.name = 0;
				for (int i = 0; i < 20; i++)
					origin.ip = "aaa";
				m.vertexArr[m.getsize()] = origin;
				m.setsize(m.getsize() - 1);
				cout << "删除成功" << endl;
			}
		}
	}
	ofstream file;
	ofstream nodefile;
	file.open("edge.txt");
	nodefile.open("node.txt");
	for (int i = 0; i < m.getsize(); i++) {           //写入顶点数据

		nodefile << m.vertexArr[i].number << " " << m.vertexArr[i].name << " " << m.vertexArr[i].ip << endl;

	}
	for (int i = 0; i < m.getsize(); i++) {            //写入边数据
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	nodefile.close();
	file.close();
}

void creat::ArrayGraph_del()        //删边
{
	int a, b;
	cout << "请输入路由器1的编号：";
	cin >> a;
	a = m.search(a);
	cout << endl;
	cout << "请输入路由器2的编号：";
	cin >> b;
	b = m.search(b);
	cout << endl;
	for (int i = 0; i < m.getsize(); i++) {
		m.arcArr[a - 1][b - 1] = 0;
		m.arcArr[b - 1][a - 1] = m.arcArr[a - 1][b - 1];
	}
	ofstream file;
	file.open("g:\\edge.txt");
	for (int i = 0; i < m.getsize(); i++) {            //写入边数据
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	file.close();
}

void creat::ArrayGraph_insert() //插入边
{
	int a, b;
	cout << "请输入路由器1的编号：";
	cin >> a;
	a = m.search(a);
	cout << endl;
	cout << "请输入路由器2的编号：";
	cin >> b;
	b = m.search(b);
	cout << endl;
	cout << "请输入二者之间线路的距离：";
	int c = 0;
	cin >> c;
	cout << endl;
	m.arcArr[a - 1][b - 1] = c;
	m.arcArr[b - 1][a - 1] = m.arcArr[a - 1][b - 1];
	ofstream file;
	file.open("edge.txt");
	file << a << b << c;
	file.close();

}

ArrayGraph* creat::getGraph()
{
	return &m;
}

void creat::ArrayGraph_create()
{
	ifstream file;
	ifstream nodefile;
	file.open("edge.txt");
	nodefile.open("node.txt");
	int na;
	string p;
	int num;
	while (!nodefile.eof())
	{
		nodefile >> num >> na >> p;
		sever a;
		a.number = num;
		a.name = na;
		a.ip = p;
		m.vertexArr[num - 1] = a;

	}
	int k;
	int l;
	int v;
	while (!file.eof()) {

		file >> l >> k >> v;
		//cout << "若服务器" << j + 1 << "和服务器" << i + 1 << "之间相连接，输入连接线路的权值，否则输入0" << endl;
		if (k != l) {
			m.arcArr[l - 1][k - 1] = v;
			m.arcArr[k - 1][l - 1] = m.arcArr[l - 1][k - 1];
		}
	}

	for (int j = 0; j < m.getsize(); ++j)   //填充边关系
		for (int i = 0; i < m.getsize(); i++)
		{
			if (m.arcArr[j][i] == 0)
				m.arcArr[j][i] = maxWeight;

		}
	file.close();
	nodefile.close();
}

void creat::ArrayGraph_show()
{
	cout << "路由器编号分别为：";
	for (int i = 0; i < m.getsize(); ++i)
	{

		cout << m.vertexArr[i].number << "  ";
	}
	cout << endl;
	cout << "路由器名称分别为：";
	for (int i = 0; i < m.getsize(); ++i)
	{

		cout << m.vertexArr[i].name << "  ";
	}
	cout << endl;
	cout << "弧矩阵如下" << endl;
	cout << "num";
	for (int i = 0; i < m.getsize(); ++i)
		cout << m.vertexArr[i].name << "  ";
	cout << endl;

	for (int j = 0; j < m.getsize(); ++j)
	{
		cout << m.vertexArr[j].name << "  ";
		for (int i = 0; i < m.getsize(); ++i)
		{
			cout << m.arcArr[i][j] << "  ";

		}
		cout << endl;
	}
	cout << endl;
}
