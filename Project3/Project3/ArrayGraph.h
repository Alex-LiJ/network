#pragma once
#include<iostream>
using namespace std;
#include"Data.h"
#define maxWeight 1000

class ArrayGraph
{
public:
	ArrayGraph();
	ArrayGraph(int x);
	sever vertexArr[200];        //����Ԫ������
	int arcArr[200][200];   //�߾����ά����
	void setsize(int i);
	int getsize();
	int search(int a);
	int fsearch(int a);
private:
	int MAXsize;
};
