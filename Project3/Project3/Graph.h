#pragma once
#include<iostream>
#include"creat.h"
#include"Data.h"

using namespace std;

#define infinity 1000

class Graph {
public:
	Graph();
	//Graph(ArrayGraph m); //���캯��
	void dijkstra(int v0);
	int getnum();
	creat* getc();
protected:
	int numEdges; //�ߵ���Ŀ
	creat c;
};
