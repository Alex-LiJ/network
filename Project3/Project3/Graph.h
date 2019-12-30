#pragma once
#include<iostream>
#include"creat.h"
#include"Data.h"

using namespace std;

#define infinity 1000

class Graph {
public:
	Graph();
	//Graph(ArrayGraph m); //构造函数
	void dijkstra(int v0);
	int getnum();
	creat* getc();
protected:
	int numEdges; //边的数目
	creat c;
};
