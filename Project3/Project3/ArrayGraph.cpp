#include"ArrayGraph.h"
#include "creat.h"

ArrayGraph::ArrayGraph()
{
	sever origin;
	origin.number = 0;
	origin.name = 0;
	origin.ip = "aaa";
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			arcArr[j][i] = maxWeight;
	for (int j = 0; j < 200; j++)
		vertexArr[j] = origin;
	setsize(200);
}

//��ʼ��Ϊһ����Ȧͼ ��Ҳ���ǻ������У����Խ���Ԫ�ض���0   
ArrayGraph::ArrayGraph(int x)
{
	sever origin;
	origin.number = 0;
	origin.name = 0;
	origin.ip = "aaa";
	for (int i = 0; i < x; i++)
		for (int j = 0; j < 200; j++)
			arcArr[i][j] = maxWeight;
	for (int j = 0; j < x; j++)
		vertexArr[j] = origin;
	setsize(x);
}

void ArrayGraph::setsize(int i)
{
	MAXsize = i;
}

int ArrayGraph::getsize()
{
	return MAXsize;
}

int ArrayGraph::search(int a)         //���ݷ��������������
{
	for (int i = 0; i < getsize(); i++) {
		if (a == vertexArr[i].name) {
			return vertexArr[i].number;
		}
	}
	return 0;
}

int ArrayGraph::fsearch(int a)
{
	for (int i = 0; i < getsize(); i++) {
		if (a == vertexArr[i].number) {
			return vertexArr[i].name;
		}
	}
	return 0;
}
