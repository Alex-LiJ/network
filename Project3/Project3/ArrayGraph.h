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
	sever vertexArr[200];        //顶点元素数组
	int arcArr[200][200];   //边矩阵二维数组
	void setsize(int i);
	int getsize();
	int search(int a);
	int fsearch(int a);
private:
	int MAXsize;
};
