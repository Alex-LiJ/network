
#include<fstream>
#include "creat.h"
using namespace std;


void creat::ArrayGraph_add()//��Ӷ���
{
	int n = m.getsize();
	m.setsize(n + 1);
	sever a;
	a.number = (n + 1);
	cout << "���������������";
	cin >> a.name;
	cout << endl;
	cout << "�����������ip:";
	cin >> a.ip;
	m.vertexArr[m.getsize() - 1] = a;

	for (int i = 0; i < m.getsize(); ++i)
	{
		if (i != m.getsize() - 1) {
			cout << "��������" << a.name << "�кͷ�����" << m.vertexArr[i].name << "֮�������ӣ�����������=��·��Ȩֵ����������0" << endl;
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
	for (int i = 0; i < m.getsize(); i++) {           //д�붥������

		nodefile << m.vertexArr[i].number << " " << m.vertexArr[i].name << " " << m.vertexArr[i].ip << endl;

	}
	for (int i = 0; i < m.getsize(); i++) {            //д�������
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	nodefile.close();
	file.close();
}

void creat::ArrayGraph_del_v() {   //ɾ������
	cout << "����ɾ���ĸ�·������" << endl;
	int a;
	cin >> a;
	cout << endl;
	int n = m.search(a) - 1;
	int i, j;
	if (n < 0 || n >= m.getsize()) {
		cout << "���������·��û����Ҫɾ����·����" << endl;
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
				cout << "ɾ���ɹ�" << endl;
			}
		}
	}
	ofstream file;
	ofstream nodefile;
	file.open("edge.txt");
	nodefile.open("node.txt");
	for (int i = 0; i < m.getsize(); i++) {           //д�붥������

		nodefile << m.vertexArr[i].number << " " << m.vertexArr[i].name << " " << m.vertexArr[i].ip << endl;

	}
	for (int i = 0; i < m.getsize(); i++) {            //д�������
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	nodefile.close();
	file.close();
}

void creat::ArrayGraph_del()        //ɾ��
{
	int a, b;
	cout << "������·����1�ı�ţ�";
	cin >> a;
	a = m.search(a);
	cout << endl;
	cout << "������·����2�ı�ţ�";
	cin >> b;
	b = m.search(b);
	cout << endl;
	for (int i = 0; i < m.getsize(); i++) {
		m.arcArr[a - 1][b - 1] = 0;
		m.arcArr[b - 1][a - 1] = m.arcArr[a - 1][b - 1];
	}
	ofstream file;
	file.open("g:\\edge.txt");
	for (int i = 0; i < m.getsize(); i++) {            //д�������
		for (int j = i; j < m.getsize(); j++) {
			file << i + 1 << " " << j + 1 << " " << m.arcArr[i][j] << endl;
		}
	}
	file.close();
}

void creat::ArrayGraph_insert() //�����
{
	int a, b;
	cout << "������·����1�ı�ţ�";
	cin >> a;
	a = m.search(a);
	cout << endl;
	cout << "������·����2�ı�ţ�";
	cin >> b;
	b = m.search(b);
	cout << endl;
	cout << "���������֮����·�ľ��룺";
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
		//cout << "��������" << j + 1 << "�ͷ�����" << i + 1 << "֮�������ӣ�����������·��Ȩֵ����������0" << endl;
		if (k != l) {
			m.arcArr[l - 1][k - 1] = v;
			m.arcArr[k - 1][l - 1] = m.arcArr[l - 1][k - 1];
		}
	}

	for (int j = 0; j < m.getsize(); ++j)   //���߹�ϵ
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
	cout << "·������ŷֱ�Ϊ��";
	for (int i = 0; i < m.getsize(); ++i)
	{

		cout << m.vertexArr[i].number << "  ";
	}
	cout << endl;
	cout << "·�������Ʒֱ�Ϊ��";
	for (int i = 0; i < m.getsize(); ++i)
	{

		cout << m.vertexArr[i].name << "  ";
	}
	cout << endl;
	cout << "����������" << endl;
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
